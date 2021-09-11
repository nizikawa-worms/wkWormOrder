
#ifndef WKWORMORDER_CTASKTEAM_H
#define WKWORMORDER_CTASKTEAM_H


#include "CTask.h"
#include "../BitmapImage.h"
#include "../BitmapTextbox.h"

typedef unsigned char BYTE;

struct TeamBarStruct {
	DWORD vtable_dword0;
	DWORD team_number_dword4;
	DWORD team_alliance_dword8;
	DWORD gameglobal_dwordC;
	DWORD textbox_dword10;
	BitmapImage * energy_bar_bitmap_dword14;
	DWORD width_dword18;
	DWORD highlight_dword1C;
	DWORD dword20;
};


class CTaskTeam : public CTask {
public:
	enum OwnerState {OwnerOff, OwnerOn};

	int unknown30; // 0x30
	int unknown34; // 0x34
	int team_number_dword38; // 0x38
	int unknown3C; // 0x3C
	int owner_byte40; // 0x40
	int unknown41; // 0x41
	int unknown42; // 0x42
	int unknown43; // 0x43
	int unknown44; // 0x44
	int unknown48; // 0x48
	int unknown4C; // 0x4C
	int unknown50; // 0x50
	int unknown54; // 0x54
	int unknown58; // 0x58
	int unknown5C; // 0x5C
	int lastLaunchedWeapon_dword60; // 0x60
	int unknown64; // 0x64
	int unknown68; // 0x68
	int unknown6C; // 0x6C
	int unknown70; // 0x70
	int unknown74; // 0x74
	int unknown78; // 0x78
	int unknown7C; // 0x7C
	int unknown80; // 0x80
	int unknown84; // 0x84
	int unknown88; // 0x88
	int unknown8C; // 0x8C
	int unknown90; // 0x90
	int unknown94; // 0x94
	int unknown98; // 0x98
	int unknown9C; // 0x9C
	int unknownA0; // 0xA0
	int unknownA4; // 0xA4
	int unknownA8; // 0xA8
	int unknownAC; // 0xAC
	int unknownB0; // 0xB0
	int unknownB4; // 0xB4
	int unknownB8; // 0xB8
	int unknownBC; // 0xBC
	int unknownC0; // 0xC0
	int unknownC4; // 0xC4
	int unknownC8; // 0xC8
	int unknownCC; // 0xCC
	int unknownD0; // 0xD0
	int unknownD4; // 0xD4
	int unknownD8; // 0xD8
	int unknownDC; // 0xDC
	int unknownE0; // 0xE0
	int unknownE4; // 0xE4
	int unknownE8; // 0xE8
	int unknownEC; // 0xEC
	int unknownF0; // 0xF0
	int unknownF4; // 0xF4
	int unknownF8; // 0xF8
	int unknownFC; // 0xFC
	int unknown100; // 0x100
	int unknown104; // 0x104
	int unknown108; // 0x108
	int unknown10C; // 0x10C
	int unknown110; // 0x110
	int unknown114; // 0x114
	int unknown118; // 0x118
	int unknown11C; // 0x11C
	int unknown120; // 0x120
	int unknown124; // 0x124
	int unknown128; // 0x128
	int unknown12C; // 0x12C
	int unknown130; // 0x130
	int unknown134; // 0x134
	int unknown138; // 0x138
	int unknown13C; // 0x13C
	int unknown140; // 0x140
	int unknown144; // 0x144
	int unknown148; // 0x148
	int unknown14C; // 0x14C
	int unknown150; // 0x150
	int unknown154; // 0x154
	int unknown158; // 0x158
	int unknown15C; // 0x15C
	int unknown160; // 0x160
	int unknown164; // 0x164
	int unknown168; // 0x168
	int unknown16C; // 0x16C
	int unknown170; // 0x170
	int unknown174; // 0x174
	int unknown178; // 0x178
	int unknown17C; // 0x17C
	int unknown180; // 0x180
	int unknown184; // 0x184
	int unknown188; // 0x188
	int unknown18C; // 0x18C
	int unknown190; // 0x190
	int unknown194; // 0x194
	int unknown198; // 0x198
	int unknown19C; // 0x19C
	int unknown1A0; // 0x1A0
	int unknown1A4; // 0x1A4
	int unknown1A8; // 0x1A8
	int unknown1AC; // 0x1AC
	int unknown1B0; // 0x1B0
	int unknown1B4; // 0x1B4
	int unknown1B8; // 0x1B8
	int unknown1BC; // 0x1BC
	int unknown1C0; // 0x1C0
	int unknown1C4; // 0x1C4
	int unknown1C8; // 0x1C8
	int unknown1CC; // 0x1CC
	int unknown1D0; // 0x1D0
	int unknown1D4; // 0x1D4
	int unknown1D8; // 0x1D8
	int unknown1DC; // 0x1DC
	int unknown1E0; // 0x1E0
	int unknown1E4; // 0x1E4
	int unknown1E8; // 0x1E8
	int unknown1EC; // 0x1EC
	int unknown1F0; // 0x1F0
	int unknown1F4; // 0x1F4
	int unknown1F8; // 0x1F8
	int unknown1FC; // 0x1FC
	int unknown200; // 0x200
	int unknown204; // 0x204
	int unknown208; // 0x208
	int unknown20C; // 0x20C
	int unknown210; // 0x210
	int unknown214; // 0x214
	int unknown218; // 0x218
	int unknown21C; // 0x21C
	int unknown220; // 0x220
	int unknown224; // 0x224
	int unknown228; // 0x228
	int unknown22C; // 0x22C
	int unknown230; // 0x230
	int unknown234; // 0x234
	int unknown238; // 0x238
	int unknown23C; // 0x23C
	int unknown240; // 0x240
	int unknown244; // 0x244
	int unknown248; // 0x248
	int unknown24C; // 0x24C
	int unknown250; // 0x250
	int unknown254; // 0x254
	int unknown258; // 0x258
	int unknown25C; // 0x25C
	int unknown260; // 0x260
	int unknown264; // 0x264
	int unknown268; // 0x268
	int unknown26C; // 0x26C
	int unknown270; // 0x270
	int unknown274; // 0x274
	int unknown278; // 0x278
	int unknown27C; // 0x27C
	int unknown280; // 0x280
	int unknown284; // 0x284
	int unknown288; // 0x288
	int unknown28C; // 0x28C
	int unknown290; // 0x290
	int unknown294; // 0x294
	int unknown298; // 0x298
	int unknown29C; // 0x29C
	int unknown2A0; // 0x2A0
	int unknown2A4; // 0x2A4
	int unknown2A8; // 0x2A8
	int unknown2AC; // 0x2AC
	int unknown2B0; // 0x2B0
	int unknown2B4; // 0x2B4
	int unknown2B8; // 0x2B8
	int unknown2BC; // 0x2BC
	int unknown2C0; // 0x2C0
	int unknown2C4; // 0x2C4
	int unknown2C8; // 0x2C8
	int unknown2CC; // 0x2CC
	int unknown2D0; // 0x2D0
	int unknown2D4; // 0x2D4
	int unknown2D8; // 0x2D8
	int unknown2DC; // 0x2DC
	int unknown2E0; // 0x2E0
	int unknown2E4; // 0x2E4
	int unknown2E8; // 0x2E8
	int unknown2EC; // 0x2EC
	int unknown2F0; // 0x2F0
	int unknown2F4; // 0x2F4
	int unknown2F8; // 0x2F8
	int unknown2FC; // 0x2FC
	int unknown300; // 0x300
	int unknown304; // 0x304
	int unknown308; // 0x308
	int unknown30C; // 0x30C
	int unknown310; // 0x310
	int unknown314; // 0x314
	int unknown318; // 0x318
	int unknown31C; // 0x31C
	int unknown320; // 0x320
	int unknown324; // 0x324
	int unknown328; // 0x328
	int unknown32C; // 0x32C
	int unknown330; // 0x330
	int unknown334; // 0x334
	int unknown338; // 0x338
	int unknown33C; // 0x33C
	int unknown340; // 0x340
	int unknown344; // 0x344
	int unknown348; // 0x348
	int unknown34C; // 0x34C
	int unknown350; // 0x350
	int unknown354; // 0x354
	int unknown358; // 0x358
	int unknown35C; // 0x35C
	int unknown360; // 0x360
	int unknown364; // 0x364
	int unknown368; // 0x368
	int unknown36C; // 0x36C
	int unknown370; // 0x370
	int unknown374; // 0x374
	int unknown378; // 0x378
	int unknown37C; // 0x37C
	int unknown380; // 0x380
	int unknown384; // 0x384
	int unknown388; // 0x388
	int unknown38C; // 0x38C
	int unknown390; // 0x390
	int unknown394; // 0x394
	int unknown398; // 0x398
	int unknown39C; // 0x39C
	int unknown3A0; // 0x3A0
	int unknown3A4; // 0x3A4
	int unknown3A8; // 0x3A8
	int unknown3AC; // 0x3AC
	int unknown3B0; // 0x3B0
	int unknown3B4; // 0x3B4
	int unknown3B8; // 0x3B8
	int unknown3BC; // 0x3BC
	int unknown3C0; // 0x3C0
	int unknown3C4; // 0x3C4
	int unknown3C8; // 0x3C8
	int unknown3CC; // 0x3CC
	int unknown3D0; // 0x3D0
	int unknown3D4; // 0x3D4
	int unknown3D8; // 0x3D8
	int unknown3DC; // 0x3DC
	int unknown3E0; // 0x3E0
	int unknown3E4; // 0x3E4
	int unknown3E8; // 0x3E8
	int unknown3EC; // 0x3EC
	int unknown3F0; // 0x3F0
	int unknown3F4; // 0x3F4
	int unknown3F8; // 0x3F8
	int unknown3FC; // 0x3FC
	int unknown400; // 0x400
	int unknown404; // 0x404
	int unknown408; // 0x408
	int unknown40C; // 0x40C
	int unknown410; // 0x410
	int unknown414; // 0x414
	int unknown418; // 0x418
	int unknown41C; // 0x41C
	int unknown420; // 0x420
	int unknown424; // 0x424
	int unknown428; // 0x428
	int unknown42C; // 0x42C
	int unknown430; // 0x430
	int unknown434; // 0x434
	int unknown438; // 0x438
	int unknown43C; // 0x43C
	int unknown440; // 0x440
	int unknown444; // 0x444
	int unknown448; // 0x448
	int unknown44C; // 0x44C
	int unknown450; // 0x450
	int unknown454; // 0x454
	int unknown458; // 0x458
	int unknown45C; // 0x45C


private:
	static inline OwnerState ownerState = OwnerOff;
	static BitmapImage* __stdcall hookSetNameTextbox(TeamBarStruct * This, BitmapTextbox * box, char *text, int text_color, int color1, int color2, int * width, int * height, int opacity);
	static void hookDrawTeamBar_patch1();
public:
	static void install();
	static OwnerState getOwnerState();
	static void setOwnerState(OwnerState ownerState);
};

#endif //WKWORMORDER_CTASKTEAM_H
