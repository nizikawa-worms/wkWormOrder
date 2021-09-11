#include "CTaskWorm.h"
#include "../Hooks.h"
#include "../BitmapTextbox.h"
#include "CTaskTeam.h"
#include "../W2App.h"
#include "../Utils.h"
#include "../Config.h"


BitmapImage* __stdcall CTaskWorm::hookSetNameTextbox(CTaskWorm * worm, BitmapTextbox * box, char *text, int text_color, int color1, int color2, int * width, int * height, int opacity) {
	if (CTaskTeam *team = (CTaskTeam *) worm->parent) {
		if (DWORD ddmain = *(DWORD *) (worm->gameglobal2c + 0x24)) {
			BYTE mymachine = *(BYTE *) (ddmain + 0xD9DC);
			DWORD ddgame = W2App::getAddrDdGame();
			if((ddgame && *(BYTE *) (ddgame + 0x490)) // replay
				|| (mymachine == team->owner_byte40) // my worms
				|| (orderState == OrderAll)) {
				std::string buff = Config::getWormNameFormat();
				Utils::replaceString(buff, "{name}", text);
				Utils::replaceString(buff, "{number}", std::to_string(worm->wormnumber_dword100));
				return BitmapTextbox::origTextboxSetText(box, (char *) buff.c_str(), text_color, color1, color2, width, height, opacity);
			}
		}
	}

	return BitmapTextbox::origTextboxSetText(box, text, text_color, color1, color2, width, height, opacity);
}


DWORD addrDrawWormTextboxes_patch1_ret;
void __declspec(naked) CTaskWorm::hookDrawWormTextboxes_patch1() {
	_asm {
			mov ecx,dword ptr ds:[ecx+0x7328]
			push 0x10000
			lea edx,dword ptr ss:[esp+0x14]
			push edx
			lea edx,dword ptr ss:[esp+0x1C]
			push edx
			mov edx,dword ptr ss:[esp+0x30]
			push edx
			mov edx,dword ptr ds:[esi+0x350]
			push ecx
			mov ecx,dword ptr ss:[esp+0x34]
			push ecx
			push eax
			push edx

			push esi // worm
			call hookSetNameTextbox
			jmp addrDrawWormTextboxes_patch1_ret
	}
}


void CTaskWorm::install() {
	DWORD addrDrawWormTextboxes = _ScanPattern("DrawWormTextboxes", "\x81\xEC\x00\x00\x00\x00\x8B\x86\x00\x00\x00\x00\x8B\x4E\x2C\x33\xD2\x89\x44\x24\x14\x8B\x41\x24\x89\x44\x24\x04\x39\x90\x00\x00\x00\x00\x53\x0F\x95\xC2\x55\x57\x83\xC2\x01", "??????xx????xxxxxxxxxxxxxxxxxx????xxxxxxxxx");
	DWORD addrDrawWormTextboxes_patch1 = addrDrawWormTextboxes + 0x2BB;
	addrDrawWormTextboxes_patch1_ret = addrDrawWormTextboxes + 0x2E8;
	_HookAsm(addrDrawWormTextboxes_patch1, (DWORD)&hookDrawWormTextboxes_patch1);
}

CTaskWorm::OrderState CTaskWorm::getOrderState() {
	return orderState;
}

void CTaskWorm::setOrderState(CTaskWorm::OrderState orderState) {
	CTaskWorm::orderState = orderState;
}
