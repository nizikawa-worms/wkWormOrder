
#include "BitmapTextbox.h"
#include "Hooks.h"
//#include "WaLibc.h"
#include "W2App.h"

//
//BitmapTextbox *(__fastcall *addrConstructTextbox)(DWORD DdDisplay, int EDX, BitmapTextbox *box, int maxlength, int font);
//BitmapTextbox::BitmapTextbox(int maxlength, int font) {
//	DWORD addrDdDisplay = W2App::getAddrDdDisplay();
//	if(!addrDdDisplay) throw std::runtime_error("DD Display is null");
//	memset((void*)this, 0, sizeof(BitmapTextbox));
//	addrConstructTextbox(addrDdDisplay, 0, this, maxlength, font);
//}
//
//
//BitmapImage * BitmapTextbox::setText(char *text, int *width, int *height, int text_color, int color1, int color2, int opacity) {
//	return origTextboxSetText(this, text, text_color, color1, color2, width, height, opacity);
//}
//
//void *BitmapTextbox::operator new(size_t size) {
//	return WaLibc::waMalloc(size);
//}
//
//void BitmapTextbox::operator delete(void *p) {
//	WaLibc::waFree(p);
//}


void BitmapTextbox::install() {
//	addrConstructTextbox = (BitmapTextbox *(__fastcall *)(DWORD,int,BitmapTextbox *,int,int))
//			_ScanPattern("ConstructTextbox", "\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x51\x8B\x44\x24\x1C\x53\x8B\x5C\x24\x1C\x55\x8B\x6C\x24\x1C\x56\x57\x8B\xF1\x89\x45\x08", "???????xx????xxxx????xxxxxxxxxxxxxxxxxxxxxx");
	origTextboxSetText = (BitmapImage *(__stdcall *)(BitmapTextbox *,char *,int,int,int,int *,int *,int))
			_ScanPattern("TextboxSetText", "\x6A\xFF\x68\x00\x00\x00\x00\x64\xA1\x00\x00\x00\x00\x50\x8B\x44\x24\x18\x64\x89\x25\x00\x00\x00\x00\x83\xEC\x10\x53\x8B\x5C\x24\x24\x3B\x83\x00\x00\x00\x00\x55", "???????xx????xxxxxxxx????xxxxxxxxxx????x");
}
