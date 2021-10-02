#include "CTaskTeam.h"
#include "../Hooks.h"
#include "../Config.h"
#include "../BitmapTextbox.h"
#include "../Utils.h"
#include "../W2App.h"
#include "../Debugf.h"
#include <fmt/format.h>

BitmapImage* __stdcall CTaskTeam::hookSetNameTextbox(TeamBarStruct * This, BitmapTextbox * box, char *text, int text_color, int color1, int color2, int * width, int * height, int opacity) {
	if(ownerState == OwnerOn) {
		DWORD ddmain = *(DWORD *) (This->gameglobal_dwordC + 0x24);
		DWORD teamdata = ddmain + 0x450 + (This->team_number_dword4 - 1) * 0xBB8;
		char ownerId = *(char *) teamdata;
		std::string owner;
		if (ownerId >= 0) {
			owner = (char *) (ddmain + 4 + 0x50 * ownerId);
		}
		DWORD totalhp = 0;
		DWORD addr = This->gameglobal_dwordC + 0x4188 + 1308 * This->team_number_dword4;
		for(int i=0; i < 8; i++) {
			totalhp += *(WORD*)addr;
			addr += 156;
		}
		int wins = *(unsigned char*)(teamdata+5);
		std::string buff;
		try {
			buff = fmt::format(Config::getTeamNameFormat(), fmt::arg("name", text), fmt::arg("owner", owner), fmt::arg("hp", totalhp), fmt::arg("wins", wins));
		} catch(std::exception & e) {
			buff = fmt::format("Format error: {}", e.what());
		}
		return BitmapTextbox::origTextboxSetText(box, (char *) buff.c_str(), text_color, color1, color2, width, height, opacity);
	}
	return BitmapTextbox::origTextboxSetText(box, text, text_color, color1, color2, width, height, opacity);
}


void CTaskTeam::getMyTeams(std::vector<std::pair<std::string, std::vector<std::string>>> & teams) {
	auto ddmain = W2App::getAddrDDMain();
	if(!ddmain) return;
	char mymachine = *(char *) (ddmain + 0xD9DC);
	char numteams = *(char*)(ddmain + 0x44c);
	for(int i=0; i < numteams; i++) {
		DWORD teamdata = ddmain + 0x450 + i * 0xBB8;
		char ownerId = *(char *) teamdata;
		if (ownerId == mymachine) {
			char *name = (char *) (teamdata + 6);
			std::vector<std::string> worms;
			for (int j = 0; j < 8; j++) {
				char *worm = (char *) (teamdata + 0xA77 + j * 40);
				worms.emplace_back(worm);
			}
			teams.emplace_back(name, worms);
		}
	}
}

DWORD addrDrawTeamBar_patch1_ret;
void __declspec(naked) CTaskTeam::hookDrawTeamBar_patch1() {
	_asm {
			push 0x10000
			lea esi,dword ptr ss:[esp+0x1C]
			push esi
			lea esi,dword ptr ss:[esp+0x24]
			push esi
			mov esi,dword ptr ds:[ecx+0x7324]
			mov ecx,dword ptr ds:[ecx+0x7328]
			push esi
			push ecx
			push edx
			mov edx,dword ptr ds:[edi+0x10]
			lea eax,dword ptr ss:[ebp+0x4114]
			push eax
			push edx

			push edi // teambarstruct
			call hookSetNameTextbox
			jmp addrDrawTeamBar_patch1_ret
	}
}

void CTaskTeam::install() {
	ownerState = (OwnerState) Config::isTeamNameShowOwnerEnabled();
	DWORD addrDrawTeamBar = _ScanPattern("DrawTeamBar", "\x83\xEC\x14\x53\x55\x56\x57\x8B\xF9\x8B\x47\x20\x8B\x77\x04\x8B\x4F\x0C\x99\x2B\xC2\xD1\xF8\xC1\xE0\x10\x01\x44\x24\x2C\x8B\xC6\x69\xC0\x00\x00\x00\x00", "??????xxxxxxxxxxxxxxxxxxxxxxxxxxxx????");
	DWORD addrDrawTeamBar_patch1 = addrDrawTeamBar + 0x9C;
	addrDrawTeamBar_patch1_ret = addrDrawTeamBar + 0xCA;
	_HookAsm(addrDrawTeamBar_patch1, (DWORD) &hookDrawTeamBar_patch1);
}

CTaskTeam::OwnerState CTaskTeam::getOwnerState() {
	return ownerState;
}

void CTaskTeam::setOwnerState(CTaskTeam::OwnerState ownerState) {
	CTaskTeam::ownerState = ownerState;
}
