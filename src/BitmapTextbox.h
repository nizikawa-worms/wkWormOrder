

#ifndef WKWORMORDER_BITMAPTEXTBOX_H
#define WKWORMORDER_BITMAPTEXTBOX_H


#include "BitmapImage.h"

typedef unsigned long DWORD;
class BitmapTextbox {
public:
	static const int defaultTextColor = 6;
	static const int defaultTextBackground = 21;
	static const int defaultTextFrame = 54;
	static const int defaultTextFont = 1;
	static const int defaultTextOpacity = 0x10000;
public:
	DWORD width_dword0;
	DWORD height_dword4;
	DWORD fontid_dword8;
	DWORD bitmap_dwordC;
	DWORD dword10;
	DWORD dword14;
	DWORD dword18;
	DWORD message_dword1C;
	DWORD dword20;
	DWORD dword24;
	DWORD dword28;
	DWORD dword2C;
	DWORD dword30;
	DWORD dword34;
	DWORD dword38;
	DWORD dword3C;
	DWORD dword40;
	DWORD dword44;
	DWORD dword48;
	DWORD dword4C;
	DWORD dword50;
	DWORD dword54;
	DWORD dword58;
	DWORD dword5C;
	DWORD dword60;
	DWORD dword64;
	DWORD dword68;
	DWORD dword6C;
	DWORD dword70;
	DWORD dword74;
	DWORD dword78;
	DWORD dword7C;
	DWORD dword80;
	DWORD dword84;
	DWORD dword88;
	DWORD dword8C;
	DWORD dword90;
	DWORD dword94;
	DWORD dword98;
	DWORD dword9C;
	DWORD dwordA0;
	DWORD dwordA4;
	DWORD dwordA8;
	DWORD dwordAC;
	DWORD dwordB0;
	DWORD dwordB4;
	DWORD dwordB8;
	DWORD dwordBC;
	DWORD dwordC0;
	DWORD dwordC4;
	DWORD dwordC8;
	DWORD dwordCC;
	DWORD dwordD0;
	DWORD dwordD4;
	DWORD dwordD8;
	DWORD dwordDC;
	DWORD dwordE0;
	DWORD dwordE4;
	DWORD dwordE8;
	DWORD dwordEC;
	DWORD dwordF0;
	DWORD dwordF4;
	DWORD dwordF8;
	DWORD dwordFC;
	DWORD dword100;
	DWORD dword104;
	DWORD dword108;
	DWORD dword10C;
	DWORD dword110;
	DWORD dword114;
	DWORD dword118;
	DWORD textcolor_dword11C;
	DWORD width_dword120;
	DWORD height_dword124;
	DWORD color1_dword128;
	DWORD color2_dword12C;
	DWORD opacity_dword130;
	DWORD dword134;
	DWORD dword138;
	DWORD dword13C;
	DWORD dword140;
	DWORD dword144;
	DWORD dword148;
	DWORD dword14C;
	DWORD dword150;
	DWORD dword154;

//	BitmapTextbox(int maxlength=256, int font=defaultTextFont);
//	void * operator new(size_t size);
//	void operator delete(void * p);
//	BitmapImage * setText(char *text, int *width, int *height, int text_color = defaultTextColor, int color1 = defaultTextBackground, int color2 = defaultTextFrame, int opacity = defaultTextOpacity);

	static inline BitmapImage * (__stdcall *origTextboxSetText)(BitmapTextbox * box, char *text, int text_color, int color1, int color2, int * width, int * height, int opacity);
	static void install();
};


#endif //WKWORMORDER_BITMAPTEXTBOX_H
