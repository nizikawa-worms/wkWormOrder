
#ifndef WKWORMORDER_BITMAPIMAGE_H
#define WKWORMORDER_BITMAPIMAGE_H

typedef unsigned long DWORD;
class BitmapImage {
public:
	virtual int _fastcall vt0(BitmapImage * This, int EDX, int a2, int a3, int a4, int a5, int a6) = 0;
	virtual int _fastcall vt4(BitmapImage * This, int EDX, int a2, int a3, int a4, int a5) = 0;
	virtual int _fastcall vt8(BitmapImage * This, int EDX, int a2, int a3, int a4, int a5) = 0;
	virtual int _fastcall vtC(BitmapImage * This, int EDX, int a2) = 0;
	virtual int _fastcall vt10(BitmapImage * This, int EDX, int a2, int a3) = 0;
	virtual int _fastcall vt14(BitmapImage * This, int EDX, int a2, int a3, int a4) = 0; //20
	virtual int _fastcall vt18(BitmapImage * This, int EDX, int a2, int a3) = 0; //24
	virtual int _fastcall vt1C(BitmapImage * This, int EDX, int a2, int a3, int a4) = 0; //28
	virtual int _fastcall vt20(BitmapImage * This, int EDX) = 0; //32
	virtual int _fastcall vt24(BitmapImage * This, int EDX, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) = 0; //36
	virtual int _fastcall vt28(BitmapImage * This, int EDX, int a2, int a3, int a4, int a5, int a6) = 0; //40

//		int vtable_dword0; // 0x0
	int unknown4; // 0x4
	int data_dword8; // 0x8
	int bitdepth_dwordC; // 0xC
	int rowsize_dword10; // 0x10
	int max_width_dword14; // 0x14
	int max_height_dword18; // 0x18
	int unknown1C; // 0x1C
	int unknown20; // 0x20
	int current_width_dword24; // 0x24
	int current_height_dword28; // 0x28
	// values below are probably unused / wrong size of structure
	int unknown2C; // 0x2C
	int unknown30; // 0x30
	int unknown34; // 0x34
	int unknown38; // 0x38
	int unknown3C; // 0x3C
	int unknown40; // 0x40
	int unknown44; // 0x44
	int unknown48; // 0x48
	static constexpr int vtNum = 11;
};



#endif //WKWORMORDER_BITMAPIMAGE_H
