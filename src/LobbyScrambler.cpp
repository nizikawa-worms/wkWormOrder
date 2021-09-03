
#include "LobbyScrambler.h"
#include "Hooks.h"
#include "Debugf.h"
#include "Config.h"
#include <algorithm>
#include <random>


int LobbyScrambler::listNumberToTeamNumber(DWORD Base, int listNumber) {
	// hex-rays intensifies
	if (listNumber >= 0 && listNumber < *(DWORD *) (Base  + 276)) {
		DWORD teamNumber = 0;
		DWORD v6, v7;
		for (v6 = *(DWORD *) (Base + 268); listNumber; v6 = *(DWORD *) v6) --listNumber;
		if (v6) {
			v7 = *(DWORD *) (v6 + 8);
			teamNumber = *(int *) (v7 + 4);
			return teamNumber;
		}
	}
	return -1;
}

int (__fastcall *origHostClickTeam)(DWORD This, DWORD EDX, DWORD a2, DWORD a3);
int __fastcall LobbyScrambler::hookHostClickTeam(DWORD This, DWORD EDX, DWORD a2, DWORD a3) {
	int listNumber = *(int *) (a2 + 12);
	int teamNumber = listNumberToTeamNumber(This + 245016, listNumber);
	if(teamNumber >= 0) {
		return scrambleTeamNames(teamNumber, This, a2, a3, origHostClickTeam);;
	} else {
		return origHostClickTeam(This, 0, a2, a3);
	}
}

int (__fastcall *origClientClickTeam)(DWORD This, DWORD EDX, DWORD a2, DWORD a3);
int __fastcall LobbyScrambler::hookClientClickTeam(DWORD This, DWORD EDX, DWORD a2, DWORD a3) {
	int listNumber = *(int *) (a2 + 12);
	int teamNumber = listNumberToTeamNumber(This + 240256, listNumber);
	if(teamNumber >= 0) {
		return scrambleTeamNames(teamNumber, This, a2, a3, origClientClickTeam);
	} else {
		return origClientClickTeam(This, 0, a2, a3);
	}
}

int LobbyScrambler::scrambleTeamNames(int teamNumber, DWORD This, DWORD a2, DWORD a3, int(__fastcall * callback)(DWORD This, DWORD EDX, DWORD a2, DWORD a3)) {
	char *teamname = (char *) (addrFrontendTeams + 0xF10 * teamNumber);

	std::vector<std::string> wormnames, backup;
	for (int i = 1; i <= 8; i++) {
		wormnames.emplace_back(std::string(teamname + 0x11 * i, 0x11));
	}
	backup = wormnames;

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(wormnames.begin(), wormnames.end(), g);

	for (int i = 1; i <= 8; i++) {
		memcpy(teamname + 0x11 * i, wormnames[i - 1].data(), 0x11);
	}

	auto ret = callback(This, 0, a2, a3);

	for (int i = 1; i <= 8; i++) {
		memcpy(teamname + 0x11 * i, backup[i - 1].data(), 0x11);
	}

	return ret;
}


void LobbyScrambler::install() {
	if(Config::isScrambleWormOrderEnabled()) {
		DWORD addrHostClickTeam = _ScanPattern("HostClickTeam", "\x55\x8B\xEC\x83\xE4\xF8\x81\xEC\x00\x00\x00\x00\x8B\x45\x08\x53\x56\x8B\xF1\x8B\x4D\x0C\x57\xC7\x01\x00\x00\x00\x00\x8B\x40\x0C\x83\xCF\xFF\x3B\xC7", "??????xx????xxxxxxxxxxxxx????xxxxxxxx");
		DWORD addrClientClickTeam = _ScanPattern("ClientClickTeam", "\x55\x8B\xEC\x83\xE4\xF8\x81\xEC\x00\x00\x00\x00\x53\x56\x57\x8B\xF9\x6A\x00\x8D\xB7\x00\x00\x00\x00\x33\xC9\x89\x7C\x24\x14\xE8\x00\x00\x00\x00\x8B\x45\x0C", "??????xx????xxxxxxxxx????xxxxxxx????xxx");
		addrFrontendTeams = *(DWORD *) (addrHostClickTeam + 0xE8);

		_HookDefault(HostClickTeam);
		_HookDefault(ClientClickTeam);
	}
}
