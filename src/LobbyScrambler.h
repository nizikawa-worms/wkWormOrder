

#ifndef WKWORMORDER_LOBBYSCRAMBLER_H
#define WKWORMORDER_LOBBYSCRAMBLER_H

typedef unsigned long       DWORD;
class LobbyScrambler {
private:
	static inline DWORD addrFrontendTeams;
	static int scrambleTeamNames(int teamNumber, DWORD This, DWORD a2, DWORD a3, int(__fastcall * callback)(DWORD This, DWORD EDX, DWORD a2, DWORD a3));
	static int listNumberToTeamNumber(DWORD Base, int listNumber);
	static int __fastcall hookHostClickTeam(DWORD This, DWORD EDX, DWORD a2, DWORD a3);
	static int __fastcall hookClientClickTeam(DWORD This, DWORD EDX, DWORD a2, DWORD a3);

public:
	static void install();
};


#endif //WKWORMORDER_LOBBYSCRAMBLER_H
