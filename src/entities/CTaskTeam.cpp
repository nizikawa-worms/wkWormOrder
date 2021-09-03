#include "CTaskTeam.h"
#include "../Hooks.h"
#include "../Config.h"
#include "../BitmapTextbox.h"
#include "../Utils.h"



BitmapImage* __stdcall hookSetNameTextbox(TeamBarStruct * This, BitmapTextbox * box, char *text, int text_color, int color1, int color2, int * width, int * height, int opacity) {
	DWORD ddmain = *(DWORD*)(This->gameglobal_dwordC + 0x24);
	DWORD teamdata = ddmain + 0x450 + (This->team_number_dword4-1)*0xBB8;
	BYTE ownerId = *(BYTE*)teamdata;
	if(ownerId >= 0) {
		char *ownerName = (char *) (ddmain + 4 + 0x50 * ownerId);
		if(strlen(ownerName)) {
			std::string buff = Config::getTeamNameFormat();
			Utils::replaceString(buff, "{name}", text);
			Utils::replaceString(buff, "{owner}", ownerName);
			return BitmapTextbox::origTextboxSetText(box, (char *) buff.c_str(), text_color, color1, color2, width, height, opacity);
		}
	}
	return BitmapTextbox::origTextboxSetText(box, text, text_color, color1, color2, width, height, opacity);
}

DWORD addrDrawTeamBar_patch1_ret;
void __declspec(naked) hookDrawTeamBar_patch1() {
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
	if(Config::isTeamNameShowOwnerEnabled()) {
		DWORD addrDrawTeamBar = _ScanPattern("DrawTeamBar", "\x83\xEC\x14\x53\x55\x56\x57\x8B\xF9\x8B\x47\x20\x8B\x77\x04\x8B\x4F\x0C\x99\x2B\xC2\xD1\xF8\xC1\xE0\x10\x01\x44\x24\x2C\x8B\xC6\x69\xC0\x00\x00\x00\x00", "??????xxxxxxxxxxxxxxxxxxxxxxxxxxxx????");
		DWORD addrDrawTeamBar_patch1 = addrDrawTeamBar + 0x9C;
		addrDrawTeamBar_patch1_ret = addrDrawTeamBar + 0xCA;
		_HookAsm(addrDrawTeamBar_patch1, (DWORD) &hookDrawTeamBar_patch1);
	}
}
