#define B4 0
#define B3 0
#define OAM_PRIO 0

const unsigned char animate_bread_data[] = {

		0, 0, 0x0d, 0,
		8, 0, 0x0e, 0,
		0, -8, 0x2b, 2,
		8, -8, 0x2b, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_bread2_data[] = {

		0, 0, 0x0d, 0,
		8, 0, 0x0e, 0,
		0, -8, 0x2b, 2 | OAM_FLIP_V,
		8, -8, 0x2b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bun_data[] = {

		0, 0, 0x1d, 0,
		0, -8, 0x2b, 2,
		0x80

};

const unsigned char animate_bun2_data[] = {

		0, 0, 0x1d, 0,
		0, -8, 0x2b, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_fruit_data[] = {

		0, 0, 0x1e, 0,
		0x80

};

const unsigned char animate_wine_data[] = {

		0, 0, 0x0f, 2,
		0, 8, 0x1f, 2,
		0, 1, 0x1c, 0,
		0x80

};

const unsigned char animate_implosion1_data[] = {

		0, 0, 0x2e, 2,
		8, 0, 0x2e, 2 | OAM_FLIP_H,
		0, 8, 0x2e, 2 | OAM_FLIP_V,
		8, 8, 0x2e, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_implosion2_data[] = {

		4, 4, 0x4e, 2,
		4, 4, 0x2f, 2,
		0x80

};

const unsigned char animate_implosion3_data[] = {

		4, 5, 0x4f, 2,
		0x80

};

const unsigned char animate_orb0_data[] = {

		0, 0, 0x0c, 0,
		0x80

};

const unsigned char animate_meter28_data[] = {

		0, 0, 0x50, 2,
		0, 8, 0x50, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter27_data[] = {

		0, 0, 0x51, 2,
		0, 8, 0x50, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter26_data[] = {

		0, 0, 0x52, 2,
		0, 8, 0x50, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter25_data[] = {

		0, 0, 0x53, 2,
		0, 8, 0x50, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter24_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x50, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter23_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x51, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter22_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x52, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter21_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x53, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter20_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x50, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter19_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x51, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter18_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x52, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter17_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x53, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter16_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x50, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter15_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x51, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter14_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x52, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter13_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x53, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter12_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x50, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter11_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x51, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter10_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x52, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter9_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x53, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter8_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x50, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter7_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x51, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter6_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x52, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter5_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x53, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter4_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x54, 2,
		0, 48, 0x50, 2,
		0x80

};

const unsigned char animate_meter3_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x54, 2,
		0, 48, 0x51, 2,
		0x80

};

const unsigned char animate_meter2_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x54, 2,
		0, 48, 0x52, 2,
		0x80

};

const unsigned char animate_meter1_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x54, 2,
		0, 48, 0x53, 2,
		0x80

};

const unsigned char animate_meter0_data[] = {

		0, 0, 0x54, 2,
		0, 8, 0x54, 2,
		0, 16, 0x54, 2,
		0, 24, 0x54, 2,

		0, 32, 0x54, 2,
		0, 40, 0x54, 2,
		0, 48, 0x54, 2,
		0x80

};

const unsigned char animate_laddertop_data[] = {

		0, 0, 0x57, 0,
		8, 0, 0x57, 0 | OAM_FLIP_H,
		0, 8, 0x26, 0,
		8, 8, 0x36, 0,

		0, -8, 0x55, 0,
		8, -8, 0x56, 0,
		0x80

};

const unsigned char animate_playerclimb1_data[] = {

		0, -8, 0x04, 0,
		8, -8, 0x03, 0,
		0, 0, 0x14, 0,
		8, 0, 0x13, 0,

		0, 8, 0x22, 0,
		8, 8, 0x25, 0,
		0x80

};

const unsigned char animate_playerclimb2_data[] = {

		0, -8, 0x02, 0,
		8, -8, 0x05, 0,
		0, 0, 0x12, 0,
		8, 0, 0x15, 0,

		0, 8, 0x24, 0,
		8, 8, 0x23, 0,
		0x80

};

const unsigned char animate_playerclimbshootleft_data[] = {

		0, -8, 0x06, 0,
		8, -8, 0x07, 0,
		0, 0, 0x16, 0,
		8, 0, 0x13, 0,

		0, 8, 0x22, 0,
		8, 8, 0x25, 0,
		1, -7, 0x0a, 2,
		-8, 0, 0x08, 0,
		0x80

};

const unsigned char animate_playerclimbshootright_data[] = {

		0, -8, 0x07, 0 | OAM_FLIP_H,
		8, -8, 0x06, 0 | OAM_FLIP_H,
		0, 0, 0x12, 0,
		8, 0, 0x16, 0 | OAM_FLIP_H,

		0, 8, 0x24, 0,
		8, 8, 0x23, 0,
		16, 0, 0x08, 0 | OAM_FLIP_H,
		7, -7, 0x0a, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_recoilleft_data[] = {

		0, -8, 0x29, 0,
		8, -8, 0x2a, 0,
		0, 0, 0x39, 0,
		8, 0, 0x3a, 0,

		0, 8, 0x49, 0,
		8, 8, 0x4a, 0,
		16, 0, 0x3b, 0,
		-8, 0, 0x3b, 0 | OAM_FLIP_H,

		4, -7, 0x0b, 2,
		0x80

};

const unsigned char animate_skeletonleft_data[] = {

		0, -8, 0x2c, 2,
		0, 8, 0x4c, 2,
		0, 0, 0x3c, 2,
		8, 0, 0x3d, 2,

		8, -8, 0x2d, 2,
		8, 8, 0x4d, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		0x80

};

const unsigned char animate_deathleft1_data[] = {

		0, -8, 0x2c, 2,
		0, 8, 0x4c, 2,
		0, 0, 0x3c, 2,
		8, 0, 0x3d, 2,

		8, -8, 0x2d, 2,
		8, 8, 0x4d, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		0x80

};

const unsigned char animate_deathleft2_data[] = {

		0, -8, 0x2c, 2,
		0, 8, 0x4c, 2,
		0, 0, 0x3c, 2,
		8, 0, 0x3d, 2,

		8, -8, 0x2d, 2,
		8, 8, 0x4d, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		0x80

};

const unsigned char animate_deathleft3_data[] = {

		0, -6, 0x2c, 2,
		0, 2, 0x3c, 2,
		8, 2, 0x3d, 2,
		8, -6, 0x2d, 2,

		16, 0, 0x4b, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		0, 8, 0x4c, 2,
		8, 8, 0x4d, 2,
		0x80

};

const unsigned char animate_deathleft4_data[] = {

		0, -4, 0x2c, 2,
		0, 4, 0x3c, 2,
		8, 4, 0x3d, 2,
		8, -4, 0x2d, 2,

		16, 2, 0x4b, 2 | OAM_FLIP_H,
		-8, 2, 0x4b, 2,
		0, 8, 0x4c, 2,
		8, 8, 0x4d, 2,
		0x80

};

const unsigned char animate_deathleft5_data[] = {

		0, -2, 0x2c, 2,
		0, 6, 0x3c, 2,
		8, 6, 0x3d, 2,
		8, -2, 0x2d, 2,

		16, 4, 0x4b, 2 | OAM_FLIP_H,
		-8, 4, 0x4b, 2,
		0, 8, 0x4c, 2,
		8, 8, 0x4d, 2,
		0x80

};

const unsigned char animate_deathleft6_data[] = {

		0, -2, 0x2c, 2,
		0, 6, 0x3c, 2,
		8, 6, 0x3d, 2,
		8, -2, 0x2d, 2,

		16, 6, 0x4b, 2 | OAM_FLIP_H,
		-8, 6, 0x4b, 2,
		0, 8, 0x4c, 2,
		8, 8, 0x4d, 2,
		0x80

};

const unsigned char animate_deathleft7_data[] = {

		0, -1, 0x2c, 2,
		0, 7, 0x5e, 2,
		8, 7, 0x5f, 2,
		8, -1, 0x2d, 2,

		15, 9, 0x4b, 2 | OAM_FLIP_H,
		-7, 9, 0x4b, 2,
		0x80

};

const unsigned char animate_deathleft8_data[] = {

		0, -1, 0x2c, 2,
		0, 7, 0x5e, 2,
		8, 7, 0x5f, 2,
		8, -1, 0x2d, 2,

		15, 11, 0x4b, 2 | OAM_FLIP_H,
		-7, 11, 0x4b, 2,
		0x80

};

const unsigned char animate_recoilright_data[] = {

		8, -8, 0x29, 0 | OAM_FLIP_H,
		0, -8, 0x2a, 0 | OAM_FLIP_H,
		8, 0, 0x39, 0 | OAM_FLIP_H,
		0, 0, 0x3a, 0 | OAM_FLIP_H,

		8, 8, 0x49, 0 | OAM_FLIP_H,
		0, 8, 0x4a, 0 | OAM_FLIP_H,
		-8, 0, 0x3b, 0 | OAM_FLIP_H,
		16, 0, 0x3b, 0,

		4, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_skeletonright_data[] = {

		8, -8, 0x2c, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		8, 0, 0x3c, 2 | OAM_FLIP_H,
		0, 0, 0x3d, 2 | OAM_FLIP_H,

		0, -8, 0x2d, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright1_data[] = {

		8, -8, 0x2c, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		8, 0, 0x3c, 2 | OAM_FLIP_H,
		0, 0, 0x3d, 2 | OAM_FLIP_H,

		0, -8, 0x2d, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright2_data[] = {

		8, -8, 0x2c, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		8, 0, 0x3c, 2 | OAM_FLIP_H,
		0, 0, 0x3d, 2 | OAM_FLIP_H,

		0, -8, 0x2d, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		-8, 0, 0x4b, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright3_data[] = {

		8, -6, 0x2c, 2 | OAM_FLIP_H,
		8, 2, 0x3c, 2 | OAM_FLIP_H,
		0, 2, 0x3d, 2 | OAM_FLIP_H,
		0, -6, 0x2d, 2 | OAM_FLIP_H,

		-8, 0, 0x4b, 2,
		16, 0, 0x4b, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright4_data[] = {

		8, -4, 0x2c, 2 | OAM_FLIP_H,
		8, 4, 0x3c, 2 | OAM_FLIP_H,
		0, 4, 0x3d, 2 | OAM_FLIP_H,
		0, -4, 0x2d, 2 | OAM_FLIP_H,

		-8, 2, 0x4b, 2,
		16, 2, 0x4b, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright5_data[] = {

		8, -2, 0x2c, 2 | OAM_FLIP_H,
		8, 6, 0x3c, 2 | OAM_FLIP_H,
		0, 6, 0x3d, 2 | OAM_FLIP_H,
		0, -2, 0x2d, 2 | OAM_FLIP_H,

		-8, 4, 0x4b, 2,
		16, 4, 0x4b, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright6_data[] = {

		8, -2, 0x2c, 2 | OAM_FLIP_H,
		8, 6, 0x3c, 2 | OAM_FLIP_H,
		0, 6, 0x3d, 2 | OAM_FLIP_H,
		0, -2, 0x2d, 2 | OAM_FLIP_H,

		-8, 6, 0x4b, 2,
		16, 6, 0x4b, 2 | OAM_FLIP_H,
		8, 8, 0x4c, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright7_data[] = {

		8, -1, 0x2c, 2 | OAM_FLIP_H,
		8, 7, 0x5e, 2 | OAM_FLIP_H,
		0, 7, 0x5f, 2 | OAM_FLIP_H,
		0, -1, 0x2d, 2 | OAM_FLIP_H,

		-7, 9, 0x4b, 2,
		15, 9, 0x4b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_deathright8_data[] = {

		8, -1, 0x2c, 2 | OAM_FLIP_H,
		8, 7, 0x5e, 2 | OAM_FLIP_H,
		0, 7, 0x5f, 2 | OAM_FLIP_H,
		0, -1, 0x2d, 2 | OAM_FLIP_H,

		-7, 11, 0x4b, 2,
		15, 11, 0x4b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerstandright_data[] = {

		8, -8, 0x00, 0 | B3 | OAM_FLIP_H | OAM_PRIO,
		0, -8, 0x01, 0 | OAM_FLIP_H,
		8, 0, 0x10, 0 | OAM_FLIP_H,
		0, 0, 0x11, 0 | OAM_FLIP_H,

		8, 8, 0x20, 0 | OAM_FLIP_H,
		0, 8, 0x21, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerstandleft_data[] = {

		0, -8, 0x00, 0 | B3 | OAM_PRIO,
		8, -8, 0x01, 0,
		0, 0, 0x10, 0,
		8, 0, 0x11, 0,

		0, 8, 0x20, 0,
		8, 8, 0x21, 0,
		4, -7, 0x0b, 2,
		0x80

};

const unsigned char animate_playerstandshootleft_data[] = {

		0, -8, 0x00, 0 | B3 | OAM_PRIO,
		8, -8, 0x01, 0,
		0, 0, 0x09, 0,
		8, 0, 0x11, 0,

		0, 8, 0x20, 0,
		8, 8, 0x21, 0,
		4, -7, 0x0b, 2,
		-8, 0, 0x08, 0,
		0x80

};

const unsigned char animate_playerstandshootright_data[] = {

		8, -8, 0x00, 0 | B3 | OAM_FLIP_H | OAM_PRIO,
		0, -8, 0x01, 0 | OAM_FLIP_H,
		8, 0, 0x09, 0 | OAM_FLIP_H,
		0, 0, 0x11, 0 | OAM_FLIP_H,

		8, 8, 0x20, 0 | OAM_FLIP_H,
		0, 8, 0x21, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x08, 0 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrun1left_data[] = {

		0, -8, 0x1a, 0,
		8, -8, 0x1b, 0,
		0, 0, 0x32, 0,
		8, 0, 0x33, 0,

		0, 8, 0x42, 0,
		8, 8, 0x43, 0,
		16, 8, 0x46, 0,
		4, -5, 0x0b, 2,
		0x80

};

const unsigned char animate_playerrun2left_data[] = {

		0, -8, 0x00, 0,
		8, -8, 0x01, 0,
		0, 0, 0x30, 0,
		8, 0, 0x31, 0,

		0, 8, 0x40, 0,
		8, 8, 0x41, 0,
		4, -7, 0x0b, 2,
		0x80

};

const unsigned char animate_playerrun3left_data[] = {

		0, -8, 0x1a, 0,
		8, -8, 0x1b, 0,
		0, 0, 0x34, 0,
		8, 0, 0x35, 0,

		0, 8, 0x44, 0,
		8, 8, 0x45, 0,
		16, 8, 0x46, 0,
		4, -5, 0x0b, 2,
		0x80

};

const unsigned char animate_playerrun1right_data[] = {

		8, -8, 0x1a, 0 | OAM_FLIP_H,
		0, -8, 0x1b, 0 | OAM_FLIP_H,
		8, 0, 0x32, 0 | OAM_FLIP_H,
		0, 0, 0x33, 0 | OAM_FLIP_H,

		8, 8, 0x42, 0 | OAM_FLIP_H,
		0, 8, 0x43, 0 | OAM_FLIP_H,
		-8, 8, 0x46, 0 | OAM_FLIP_H,
		4, -5, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrun2right_data[] = {

		8, -8, 0x00, 0 | OAM_FLIP_H,
		0, -8, 0x01, 0 | OAM_FLIP_H,
		8, 0, 0x30, 0 | OAM_FLIP_H,
		0, 0, 0x31, 0 | OAM_FLIP_H,

		8, 8, 0x40, 0 | OAM_FLIP_H,
		0, 8, 0x41, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrun3right_data[] = {

		8, -8, 0x1a, 0 | OAM_FLIP_H,
		0, -8, 0x1b, 0 | OAM_FLIP_H,
		8, 0, 0x34, 0 | OAM_FLIP_H,
		0, 0, 0x35, 0 | OAM_FLIP_H,

		8, 8, 0x44, 0 | OAM_FLIP_H,
		0, 8, 0x45, 0 | OAM_FLIP_H,
		-8, 8, 0x46, 0 | OAM_FLIP_H,
		4, -5, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrunshoot1left_data[] = {

		0, -8, 0x1a, 0,
		8, -8, 0x1b, 0,
		0, 0, 0x19, 0,
		8, 0, 0x33, 0,

		0, 8, 0x42, 0,
		8, 8, 0x43, 0,
		16, 8, 0x46, 0,
		4, -5, 0x0b, 2,

		-8, 0, 0x18, 0,
		0x80

};

const unsigned char animate_playerrunshoot2left_data[] = {

		0, -8, 0x00, 0,
		8, -8, 0x01, 0,
		0, 0, 0x09, 0,
		8, 0, 0x31, 0,

		0, 8, 0x40, 0,
		8, 8, 0x41, 0,
		4, -7, 0x0b, 2,
		-8, 0, 0x08, 0,
		0x80

};

const unsigned char animate_playerrunshoot3left_data[] = {

		0, -8, 0x1a, 0,
		8, -8, 0x1b, 0,
		0, 0, 0x19, 0,
		8, 0, 0x35, 0,

		0, 8, 0x44, 0,
		8, 8, 0x45, 0,
		16, 8, 0x46, 0,
		4, -5, 0x0b, 2,

		-8, 0, 0x18, 0,
		0x80

};

const unsigned char animate_playerrunshoot1right_data[] = {

		8, -8, 0x1a, 0 | OAM_FLIP_H,
		0, -8, 0x1b, 0 | OAM_FLIP_H,
		8, 0, 0x19, 0 | OAM_FLIP_H,
		0, 0, 0x33, 0 | OAM_FLIP_H,

		8, 8, 0x42, 0 | OAM_FLIP_H,
		0, 8, 0x43, 0 | OAM_FLIP_H,
		-8, 8, 0x46, 0 | OAM_FLIP_H,
		4, -5, 0x0b, 2 | OAM_FLIP_H,

		16, 0, 0x18, 0 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrunshoot2right_data[] = {

		8, -8, 0x00, 0 | OAM_FLIP_H,
		0, -8, 0x01, 0 | OAM_FLIP_H,
		8, 0, 0x09, 0 | OAM_FLIP_H,
		0, 0, 0x31, 0 | OAM_FLIP_H,

		8, 8, 0x40, 0 | OAM_FLIP_H,
		0, 8, 0x41, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x08, 0 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerrunshoot3right_data[] = {

		8, -8, 0x1a, 0 | OAM_FLIP_H,
		0, -8, 0x1b, 0 | OAM_FLIP_H,
		8, 0, 0x19, 0 | OAM_FLIP_H,
		0, 0, 0x35, 0 | OAM_FLIP_H,

		8, 8, 0x44, 0 | OAM_FLIP_H,
		0, 8, 0x45, 0 | OAM_FLIP_H,
		-8, 8, 0x46, 0 | OAM_FLIP_H,
		4, -5, 0x0b, 2 | OAM_FLIP_H,

		16, 0, 0x18, 0 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerjumpleft_data[] = {

		0, -8, 0x27, 0,
		8, -8, 0x28, 0,
		0, 0, 0x37, 0,
		8, 0, 0x38, 0,

		0, 8, 0x47, 0,
		8, 8, 0x48, 0,
		8, 16, 0x58, 0,
		4, -7, 0x0b, 2,
		0x80

};

const unsigned char animate_playerjumpleftshoot_data[] = {

		0, -8, 0x00, 0,
		8, -8, 0x28, 0,
		0, 0, 0x09, 0,
		8, 0, 0x38, 0,

		0, 8, 0x47, 0,
		8, 8, 0x48, 0,
		8, 16, 0x58, 0,
		4, -7, 0x0b, 2,

		-8, 0, 0x08, 0,
		0x80

};

const unsigned char animate_playerjumpright_data[] = {

		8, -8, 0x27, 0 | OAM_FLIP_H,
		0, -8, 0x28, 0 | OAM_FLIP_H,
		8, 0, 0x37, 0 | OAM_FLIP_H,
		0, 0, 0x38, 0 | OAM_FLIP_H,

		8, 8, 0x47, 0 | OAM_FLIP_H,
		0, 8, 0x48, 0 | OAM_FLIP_H,
		0, 16, 0x58, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_playerjumprightshoot_data[] = {

		8, -8, 0x00, 0 | OAM_FLIP_H,
		0, -8, 0x28, 0 | OAM_FLIP_H,
		8, 0, 0x09, 0 | OAM_FLIP_H,
		0, 0, 0x38, 0 | OAM_FLIP_H,

		8, 8, 0x47, 0 | OAM_FLIP_H,
		0, 8, 0x48, 0 | OAM_FLIP_H,
		0, 16, 0x58, 0 | OAM_FLIP_H,
		4, -7, 0x0b, 2 | OAM_FLIP_H,

		16, 0, 0x08, 0 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_hootyowl1left_data[] = {

		0, 0, 0xe7, 2,
		0, 8, 0xf7, 2,
		8, 0, 0xe8, 2,
		16, 0, 0xe9, 2,

		8, 8, 0xf8, 2,
		16, 8, 0xf9, 2,
		0x80

};

const unsigned char animate_hootyowl2left_data[] = {

		0, 0, 0xc7, 2,
		0, 8, 0xf7, 2,
		8, 0, 0xe8, 2,
		16, 0, 0xc9, 2,

		8, 8, 0xf8, 2,
		16, 8, 0xf9, 2,
		0x80

};

const unsigned char animate_hootyowl3left_data[] = {

		0, 0, 0xa7, 2,
		0, 8, 0xb7, 2,
		8, 0, 0xe8, 2,
		16, 0, 0xa9, 2,

		8, 8, 0xf8, 2,
		16, 8, 0xb9, 2,
		0x80

};

const unsigned char animate_hootyowl4left_data[] = {

		0, 0, 0x87, 2,
		8, 0, 0x88, 2,
		16, 0, 0x89, 2,
		8, 8, 0x98, 2,

		0, 8, 0x97, 2,
		16, 8, 0x99, 2,
		0x80

};

const unsigned char animate_hootyowl5left_data[] = {

		0, 8, 0x87, 2 | OAM_FLIP_V,
		8, 8, 0x88, 2 | OAM_FLIP_V,
		16, 8, 0x89, 2 | OAM_FLIP_V,
		8, 0, 0x98, 2 | OAM_FLIP_V,

		0, 0, 0x97, 2 | OAM_FLIP_V,
		16, 0, 0x99, 2 | OAM_FLIP_V,
		0x80

};

const unsigned char animate_hootyowl1right_data[] = {

		16, 0, 0xe7, 2 | OAM_FLIP_H,
		16, 8, 0xf7, 2 | OAM_FLIP_H,
		8, 0, 0xe8, 2 | OAM_FLIP_H,
		0, 0, 0xe9, 2 | OAM_FLIP_H,

		8, 8, 0xf8, 2 | OAM_FLIP_H,
		0, 8, 0xf9, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_hootyowl2right_data[] = {

		16, 0, 0xc7, 2 | OAM_FLIP_H,
		16, 8, 0xf7, 2 | OAM_FLIP_H,
		8, 0, 0xe8, 2 | OAM_FLIP_H,
		0, 0, 0xc9, 2 | OAM_FLIP_H,

		8, 8, 0xf8, 2 | OAM_FLIP_H,
		0, 8, 0xf9, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_hootyowl3right_data[] = {

		16, 0, 0xa7, 2 | OAM_FLIP_H,
		16, 8, 0xb7, 2 | OAM_FLIP_H,
		8, 0, 0xe8, 2 | OAM_FLIP_H,
		0, 0, 0xa9, 2 | OAM_FLIP_H,

		8, 8, 0xf8, 2 | OAM_FLIP_H,
		0, 8, 0xb9, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_hootyowl4right_data[] = {

		16, 0, 0x87, 2 | OAM_FLIP_H,
		8, 0, 0x88, 2 | OAM_FLIP_H,
		0, 0, 0x89, 2 | OAM_FLIP_H,
		8, 8, 0x98, 2 | OAM_FLIP_H,

		16, 8, 0x97, 2 | OAM_FLIP_H,
		0, 8, 0x99, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_hootyowl5right_data[] = {

		16, 8, 0x87, 2 | OAM_FLIP_H | OAM_FLIP_V,
		8, 8, 0x88, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0, 8, 0x89, 2 | OAM_FLIP_H | OAM_FLIP_V,
		8, 0, 0x98, 2 | OAM_FLIP_H | OAM_FLIP_V,

		16, 0, 0x97, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0, 0, 0x99, 2 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snail1left_data[] = {

		0, 0, 0xed, 3,
		0, 8, 0xfd, 3,
		8, 0, 0xee, 3,
		8, 8, 0xfe, 3,

		16, 0, 0xef, 3,
		16, 8, 0xff, 3,
		0x80

};

const unsigned char animate_snail2left_data[] = {

		0, 0, 0xcd, 3,
		0, 8, 0xdd, 3,
		8, 0, 0xee, 3,
		8, 8, 0xfe, 3,

		16, 0, 0xef, 3,
		16, 8, 0xdf, 3,
		0x80

};

const unsigned char animate_snail3left_data[] = {

		0, 0, 0xad, 3,
		0, 8, 0xbd, 3,
		8, 0, 0xee, 3,
		8, 8, 0xfe, 3,

		16, 0, 0xef, 3,
		16, 8, 0xbf, 3,
		0x80

};

const unsigned char animate_snail1right_data[] = {

		16, 0, 0xed, 3 | OAM_FLIP_H,
		16, 8, 0xfd, 3 | OAM_FLIP_H,
		8, 0, 0xee, 3 | OAM_FLIP_H,
		8, 8, 0xfe, 3 | OAM_FLIP_H,

		0, 0, 0xef, 3 | OAM_FLIP_H,
		0, 8, 0xff, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snail2right_data[] = {

		16, 0, 0xcd, 3 | OAM_FLIP_H,
		16, 8, 0xdd, 3 | OAM_FLIP_H,
		8, 0, 0xee, 3 | OAM_FLIP_H,
		8, 8, 0xfe, 3 | OAM_FLIP_H,

		0, 0, 0xef, 3 | OAM_FLIP_H,
		0, 8, 0xdf, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snail3right_data[] = {

		16, 0, 0xad, 3 | OAM_FLIP_H,
		16, 8, 0xbd, 3 | OAM_FLIP_H,
		8, 0, 0xee, 3 | OAM_FLIP_H,
		8, 8, 0xfe, 3 | OAM_FLIP_H,

		0, 0, 0xef, 3 | OAM_FLIP_H,
		0, 8, 0xbf, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake1left_data[] = {

		32, 8, 0xfa, 1 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snake2left_data[] = {

		32, 0, 0xfa, 1 | OAM_FLIP_H | OAM_FLIP_V,
		32, 8, 0xcc, 1,
		0x80

};

const unsigned char animate_snake3left_data[] = {

		32, 0, 0xeb, 1,
		32, 8, 0xcc, 1,
		24, 0, 0xcb, 1,
		0x80

};

const unsigned char animate_snake4left_data[] = {

		32, 0, 0xeb, 1,
		32, 8, 0xcc, 1,
		16, 0, 0xcb, 1,
		24, 0, 0xdc, 1 | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snake5left_data[] = {

		32, 0, 0xeb, 1,
		32, 8, 0xcc, 1,
		16, 0, 0xea, 1,
		24, 0, 0xdc, 1 | OAM_FLIP_V,

		16, 8, 0xfa, 1,
		0x80

};

const unsigned char animate_snake6left_data[] = {

		32, 0, 0xeb, 1,
		32, 8, 0xcc, 1,
		16, 0, 0xea, 1,
		24, 0, 0xdc, 1 | OAM_FLIP_V,

		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake7left_data[] = {

		32, 0, 0xeb, 1,
		32, 8, 0xec, 1 | OAM_FLIP_H | OAM_FLIP_V,
		16, 0, 0xea, 1,
		24, 0, 0xdc, 1 | OAM_FLIP_V,

		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake8left_data[] = {

		32, 0, 0xdb, 1 | OAM_FLIP_H,
		16, 0, 0xea, 1,
		24, 0, 0xdc, 1 | OAM_FLIP_V,
		16, 8, 0xcc, 1 | OAM_FLIP_H,

		0, 8, 0xfa, 1 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snake9left_data[] = {

		16, 0, 0xea, 1,
		24, 0, 0xdb, 1 | OAM_FLIP_H,
		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0, 8, 0xcc, 1 | OAM_FLIP_V,

		0, 0, 0xfa, 1 | OAM_FLIP_H | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snake10left_data[] = {

		16, 0, 0xec, 1,
		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,

		-8, 0, 0xcb, 1,
		0x80

};

const unsigned char animate_snake11left_data[] = {

		16, 0, 0xec, 1 | OAM_FLIP_H,
		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,

		-8, 0, 0xfb, 1,
		0x80

};

const unsigned char animate_snake12left_data[] = {

		16, 0, 0xec, 1,
		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,

		-8, 0, 0xfc, 1,
		0x80

};

const unsigned char animate_snake13left_data[] = {

		16, 0, 0xec, 1 | OAM_FLIP_H,
		16, 8, 0xcc, 1 | OAM_FLIP_H,
		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,

		-8, 0, 0xfb, 1,
		0x80

};

const unsigned char animate_snake14left_data[] = {

		16, 8, 0xec, 1,
		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,
		-16, 0, 0xcb, 1,

		-8, 0, 0xdc, 1 | OAM_FLIP_V,
		0x80

};

const unsigned char animate_snake15left_data[] = {

		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,
		-16, 0, 0xea, 1,
		-8, 0, 0xdc, 1 | OAM_FLIP_V,

		-16, 8, 0xfa, 1,
		0x80

};

const unsigned char animate_snake16left_data[] = {

		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,
		-16, 0, 0xea, 1,
		-8, 0, 0xdc, 1 | OAM_FLIP_V,

		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake17left_data[] = {

		0, 8, 0xcc, 1 | OAM_FLIP_V,
		0, 0, 0xeb, 1,
		-16, 0, 0xea, 1,
		-8, 0, 0xdc, 1 | OAM_FLIP_V,

		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake18left_data[] = {

		0, 8, 0xec, 1 | OAM_FLIP_H | OAM_FLIP_V,
		0, 0, 0xeb, 1,
		-16, 0, 0xea, 1,
		-8, 0, 0xdc, 1 | OAM_FLIP_V,

		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake19left_data[] = {

		0, 0, 0xdb, 1 | OAM_FLIP_H,
		-16, 0, 0xea, 1,
		-8, 0, 0xdc, 1 | OAM_FLIP_V,
		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake20left_data[] = {

		-8, 0, 0xdb, 1 | OAM_FLIP_H,
		-16, 0, 0xea, 1,
		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake21left_data[] = {

		-16, 0, 0xec, 1,
		-16, 8, 0xcc, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_snake22left_data[] = {

		-16, 8, 0xec, 1,
		0x80

};

const unsigned char animate_spidrer1_data[] = {

		0, 0, 0xba, 3,
		8, 0, 0xba, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_spider2_data[] = {

		0, 0, 0xca, 3,
		8, 0, 0xca, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_spider3_data[] = {

		0, 0, 0xda, 3,
		8, 0, 0xda, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_spiderweb_data[] = {

		0, 0, 0xbb, 2,
		0x80

};

const unsigned char animate_mousewalk1left_data[] = {

		0, 0, 0x78, 3,
		8, 0, 0x79, 3,
		8, -8, 0x69, 3,
		0x80

};

const unsigned char animate_mousewalk2left_data[] = {

		0, 0, 0x74, 3,
		8, 0, 0x75, 3,
		8, -8, 0x65, 3,
		0x80

};

const unsigned char animate_mousewalk3left_data[] = {

		0, 0, 0x76, 3,
		8, 0, 0x77, 3,
		8, -8, 0x67, 3,
		0x80

};

const unsigned char animate_mousewalk1right_data[] = {

		8, 0, 0x78, 3 | OAM_FLIP_H,
		0, 0, 0x79, 3 | OAM_FLIP_H,
		0, -8, 0x69, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_mousewalk2right_data[] = {

		8, 0, 0x74, 3 | OAM_FLIP_H,
		0, 0, 0x75, 3 | OAM_FLIP_H,
		0, -8, 0x65, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_mousewalk3right_data[] = {

		8, 0, 0x76, 3 | OAM_FLIP_H,
		0, 0, 0x77, 3 | OAM_FLIP_H,
		0, -8, 0x67, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_mousejumpleft_data[] = {

		0, 0, 0x66, 3,
		8, 0, 0x68, 3,
		8, -8, 0x69, 3,
		0x80

};

const unsigned char animate_mousejumpright_data[] = {

		8, 0, 0x66, 3 | OAM_FLIP_H,
		0, 0, 0x68, 3 | OAM_FLIP_H,
		0, -8, 0x69, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bearstandleft_data[] = {

		0, -16, 0xb4, 1,
		8, -16, 0xb5, 1,
		0, -8, 0xc4, 1,
		8, -8, 0xc5, 1,

		0, 0, 0xd4, 1,
		8, 0, 0xd5, 1,
		0, 8, 0xe4, 1,
		8, 8, 0xe5, 1,

		3, -14, 0x0b, 2,
		0x80

};

const unsigned char animate_bearstandright_data[] = {

		8, -16, 0xb4, 1 | OAM_FLIP_H,
		0, -16, 0xb5, 1 | OAM_FLIP_H,
		8, -8, 0xc4, 1 | OAM_FLIP_H,
		0, -8, 0xc5, 1 | OAM_FLIP_H,

		8, 0, 0xd4, 1 | OAM_FLIP_H,
		0, 0, 0xd5, 1 | OAM_FLIP_H,
		8, 8, 0xe4, 1 | OAM_FLIP_H,
		0, 8, 0xe5, 1 | OAM_FLIP_H,

		5, -14, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bearroarleft_data[] = {

		0, -16, 0x94, 1,
		8, -16, 0xb5, 1,
		0, -8, 0xa4, 1,
		8, -8, 0xc5, 1,

		0, 0, 0xd4, 1,
		8, 0, 0xd5, 1,
		0, 8, 0xe4, 1,
		8, 8, 0xe5, 1,

		3, -14, 0x0b, 2,
		-8, -12, 0xc3, 1,
		0x80

};

const unsigned char animate_bearroarright_data[] = {

		8, -16, 0x94, 1 | OAM_FLIP_H,
		0, -16, 0xb5, 1 | OAM_FLIP_H,
		8, -8, 0xa4, 1 | OAM_FLIP_H,
		0, -8, 0xc5, 1 | OAM_FLIP_H,

		8, 0, 0xd4, 1 | OAM_FLIP_H,
		0, 0, 0xd5, 1 | OAM_FLIP_H,
		8, 8, 0xe4, 1 | OAM_FLIP_H,
		0, 8, 0xe5, 1 | OAM_FLIP_H,

		5, -14, 0x0b, 2 | OAM_FLIP_H,
		16, -12, 0xc3, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_beararms_data[] = {

		0, -16, 0xa0, 1,
		8, -16, 0xa1, 1,
		0, -8, 0xb0, 1,
		8, -8, 0xb1, 1,

		0, 0, 0xc0, 1,
		8, 0, 0xc1, 1,
		0, 8, 0xe4, 1,
		8, 8, 0xe5, 1,

		3, -14, 0x0b, 2,
		16, -8, 0xb2, 1,
		16, -16, 0xa2, 1,
		0x80

};

const unsigned char animate_beararmsright_data[] = {

		8, -16, 0xa0, 1 | OAM_FLIP_H,
		0, -16, 0xa1, 1 | OAM_FLIP_H,
		8, -8, 0xb0, 1 | OAM_FLIP_H,
		0, -8, 0xb1, 1 | OAM_FLIP_H,

		8, 0, 0xc0, 1 | OAM_FLIP_H,
		0, 0, 0xc1, 1 | OAM_FLIP_H,
		8, 8, 0xe4, 1 | OAM_FLIP_H,
		0, 8, 0xe5, 1 | OAM_FLIP_H,

		5, -14, 0x0b, 2 | OAM_FLIP_H,
		-8, -8, 0xb2, 1 | OAM_FLIP_H,
		-8, -16, 0xa2, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bearwalk1eft_data[] = {

		0, -16, 0xd0, 1,
		8, -16, 0xd1, 1,
		0, -8, 0xe0, 1,
		8, -8, 0xe1, 1,

		0, 0, 0xf0, 1,
		8, 0, 0xf1, 1,
		8, 8, 0xf3, 1,
		0, 8, 0xf2, 1,

		16, 8, 0xd3, 1,
		3, -12, 0x0b, 2,
		0x80

};

const unsigned char animate_bearwalk2left_data[] = {

		0, -16, 0xb4, 1,
		8, -16, 0xb5, 1,
		0, -8, 0xc4, 1,
		8, -8, 0xc5, 1,

		0, 0, 0xd2, 1,
		8, 0, 0xd5, 1,
		0, 8, 0xf4, 1,
		8, 8, 0xf5, 1,

		3, -14, 0x0b, 2,
		0x80

};

const unsigned char animate_bearwalk3left_data[] = {

		0, -16, 0xd0, 1,
		8, -16, 0xd1, 1,
		0, -8, 0xe0, 1,
		8, -8, 0xe1, 1,

		0, 0, 0xe2, 1,
		8, 0, 0xe3, 1,
		0, 8, 0xf2, 1,
		8, 8, 0xf3, 1,

		3, -12, 0x0b, 2,
		16, 8, 0xd3, 1,
		0x80

};

const unsigned char animate_bearwalkright_data[] = {

		8, -16, 0xd0, 1 | OAM_FLIP_H,
		0, -16, 0xd1, 1 | OAM_FLIP_H,
		8, -8, 0xe0, 1 | OAM_FLIP_H,
		0, -8, 0xe1, 1 | OAM_FLIP_H,

		8, 0, 0xf0, 1 | OAM_FLIP_H,
		0, 0, 0xf1, 1 | OAM_FLIP_H,
		0, 8, 0xf3, 1 | OAM_FLIP_H,
		8, 8, 0xf2, 1 | OAM_FLIP_H,

		-8, 8, 0xd3, 1 | OAM_FLIP_H,
		5, -12, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bearwalk2right_data[] = {

		8, -16, 0xb4, 1 | OAM_FLIP_H,
		0, -16, 0xb5, 1 | OAM_FLIP_H,
		8, -8, 0xc4, 1 | OAM_FLIP_H,
		0, -8, 0xc5, 1 | OAM_FLIP_H,

		8, 0, 0xd2, 1 | OAM_FLIP_H,
		0, 0, 0xd5, 1 | OAM_FLIP_H,
		8, 8, 0xf4, 1 | OAM_FLIP_H,
		0, 8, 0xf5, 1 | OAM_FLIP_H,

		5, -14, 0x0b, 2 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bearwalk3right_data[] = {

		8, -16, 0xd0, 1 | OAM_FLIP_H,
		0, -16, 0xd1, 1 | OAM_FLIP_H,
		8, -8, 0xe0, 1 | OAM_FLIP_H,
		0, -8, 0xe1, 1 | OAM_FLIP_H,

		8, 0, 0xe2, 1 | OAM_FLIP_H,
		0, 0, 0xe3, 1 | OAM_FLIP_H,
		8, 8, 0xf2, 1 | OAM_FLIP_H,
		0, 8, 0xf3, 1 | OAM_FLIP_H,

		5, -12, 0x0b, 2 | OAM_FLIP_H,
		-8, 8, 0xd3, 1 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_bouldersmall_data[] = {

		0, 0, 0xc2, 1,
		0x80

};

const unsigned char animate_fisleft_data[] = {

		0, 1, 0xb3, 3,
		0x80

};

const unsigned char animate_fishright_data[] = {

		0, 1, 0xb3, 3 | OAM_FLIP_H,
		0x80

};

const unsigned char animate_stoneupplerleft_data[] = {

		0, 0, 0x60, 3,
		0x80

};

const unsigned char animate_stoneupperright_data[] = {

		0, 0, 0x61, 3,
		0x80

};

const unsigned char animate_stownlowerleft_data[] = {

		0, 0, 0x70, 3,
		0x80

};

const unsigned char animate_stonelowerright_data[] = {

		0, 0, 0x71, 3,
		0x80

};

const unsigned char animate_stonebig_data[] = {

		0, 8, 0x70, 3,
		8, 8, 0x71, 3,
		0, 0, 0x60, 3,
		8, 0, 0x61, 3,
		0x80

};

const unsigned char animate_stonesmall_data[] = {

		0, 0, 0xc2, 3,
		0x80

};

// const unsigned char animate_deerleft1_data[]={

// 	- 1,- 5,0x6f,2,
// 	  0,  0,0x7d,1,
// 	  0,- 8,0x6d,1,
// 	  8,- 8,0x6e,1,

// 	  8,  0,0x7e,1,
// 	  0,  8,0x8d,1,
// 	  8,  8,0x8e,1,
// 	 16,  0,0x7f,1,

// 	 16,  8,0x8f,1,
// 	  8, 16,0x9e,1,
// 	 16, 16,0x9f,1,
// 	  0, 16,0x9d,1,
// 	0x80

// };

// const unsigned char animate_deerleft2_data[]={

// 	- 1,- 4,0x6f,2,
// 	  0,  0,0x8b,1,
// 	  0,- 8,0x7b,1,
// 	  8,- 8,0x7c,1,

// 	  8,  0,0x8c,1,
// 	  0,  8,0xbe,1,
// 	  8,  8,0x8e,1,
// 	 16,  8,0x8f,1,

// 	  8, 16,0xae,1,
// 	 16, 16,0xaf,1,
// 	 16,  0,0x8a,1,
// 	0x80

// };

// const unsigned char animate_deerleft3_data[]={

// 	- 1,- 5,0x6f,2,
// 	  0,  0,0x7d,1,
// 	  0,- 8,0x6d,1,
// 	  8,- 8,0x6e,1,

// 	  8,  0,0x7e,1,
// 	  0,  8,0x9a,1,
// 	  8,  8,0x9b,1,
// 	 16,  0,0x7f,1,

// 	 16,  8,0x9c,1,
// 	  8, 16,0xab,1,
// 	 16, 16,0xac,1,
// 	  0, 16,0xaa,1,
// 	0x80

// };

// const unsigned char animate_deerleftjump_data[]={

// 	- 1,- 5,0x6f,2,
// 	  0,  0,0x7d,1,
// 	  0,- 8,0x6d,1,
// 	  8,- 8,0x6e,1,

// 	  8,  0,0x7e,1,
// 	  0,  8,0xbe,1,
// 	  8,  8,0x9b,1,
// 	 16,  0,0x7f,1,

// 	 16,  8,0x9c,1,
// 	  8, 16,0x6a,1,
// 	 16, 16,0x6b,1,
// 	 24, 16,0x6c,1,
// 	0x80

// };

// const unsigned char animate_deerright1_data[]={

// 	 17,- 5,0x6f,2|OAM_FLIP_H,
// 	 16,  0,0x7d,1|OAM_FLIP_H,
// 	 16,- 8,0x6d,1|OAM_FLIP_H,
// 	  8,- 8,0x6e,1|OAM_FLIP_H,

// 	  8,  0,0x7e,1|OAM_FLIP_H,
// 	 16,  8,0x8d,1|OAM_FLIP_H,
// 	  8,  8,0x8e,1|OAM_FLIP_H,
// 	  0,  0,0x7f,1|OAM_FLIP_H,

// 	  0,  8,0x8f,1|OAM_FLIP_H,
// 	  8, 16,0x9e,1|OAM_FLIP_H,
// 	  0, 16,0x9f,1|OAM_FLIP_H,
// 	 16, 16,0x9d,1|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_deerright2_data[]={

// 	 17,- 4,0x6f,2|OAM_FLIP_H,
// 	 16,  0,0x8b,1|OAM_FLIP_H,
// 	 16,- 8,0x7b,1|OAM_FLIP_H,
// 	  8,- 8,0x7c,1|OAM_FLIP_H,

// 	  8,  0,0x8c,1|OAM_FLIP_H,
// 	 16,  8,0xbe,1|OAM_FLIP_H,
// 	  8,  8,0x8e,1|OAM_FLIP_H,
// 	  0,  8,0x8f,1|OAM_FLIP_H,

// 	  8, 16,0xae,1|OAM_FLIP_H,
// 	  0, 16,0xaf,1|OAM_FLIP_H,
// 	  0,  0,0x8a,1|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_deerright3_data[]={

// 	 17,- 5,0x6f,2|OAM_FLIP_H,
// 	 16,  0,0x7d,1|OAM_FLIP_H,
// 	 16,- 8,0x6d,1|OAM_FLIP_H,
// 	  8,- 8,0x6e,1|OAM_FLIP_H,

// 	  8,  0,0x7e,1|OAM_FLIP_H,
// 	 16,  8,0x9a,1|OAM_FLIP_H,
// 	  8,  8,0x9b,1|OAM_FLIP_H,
// 	  0,  0,0x7f,1|OAM_FLIP_H,

// 	  0,  8,0x9c,1|OAM_FLIP_H,
// 	  8, 16,0xab,1|OAM_FLIP_H,
// 	  0, 16,0xac,1|OAM_FLIP_H,
// 	 16, 16,0xaa,1|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_deerrightjump_data[]={

// 	 17,- 5,0x6f,2|OAM_FLIP_H,
// 	 16,  0,0x7d,1|OAM_FLIP_H,
// 	 16,- 8,0x6d,1|OAM_FLIP_H,
// 	  8,- 8,0x6e,1|OAM_FLIP_H,

// 	  8,  0,0x7e,1|OAM_FLIP_H,
// 	 16,  8,0xbe,1|OAM_FLIP_H,
// 	  8,  8,0x9b,1|OAM_FLIP_H,
// 	  0,  0,0x7f,1|OAM_FLIP_H,

// 	  0,  8,0x9c,1|OAM_FLIP_H,
// 	  8, 16,0x6a,1|OAM_FLIP_H,
// 	  0, 16,0x6b,1|OAM_FLIP_H,
// 	- 8, 16,0x6c,1|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_squirrelleft1_data[]={

// 	- 1,  3,0xa5,2,
// 	  0,  0,0x80,3,
// 	  0, 16,0x83,3,
// 	  8,  0,0x81,3,

// 	- 3, 15,0xa3,1,
// 	- 3,  7,0x93,1,
// 	  0,  8,0x90,3,
// 	  8,  8,0x91,3,

// 	 16,  8,0x92,3,
// 	  8, 16,0x84,3,
// 	 16,  0,0x82,3,
// 	0x80

// };

// const unsigned char animate_squirrelleft2_data[]={

// 	- 1,  4,0xa5,2,
// 	  0,  1,0x80,3,
// 	  0, 16,0x85,3,
// 	  8,  0,0x62,3,

// 	- 3, 15,0xa3,1,
// 	- 3,  7,0x93,1,
// 	  8,  8,0x72,3,
// 	 16,  8,0x73,3,

// 	  8, 16,0x86,3,
// 	 16,  0,0x63,3,
// 	  0,  9,0x90,3,
// 	0x80

// };

// const unsigned char animate_squirrelleft3_data[]={

// 	- 1,  3,0xa5,2,
// 	  0,  0,0x80,3,
// 	  0, 16,0x95,3,
// 	  8,  0,0x81,3,

// 	- 3, 15,0xa3,1,
// 	- 3,  7,0x93,1,
// 	  0,  8,0x90,3,
// 	  8,  8,0x91,3,

// 	 16,  8,0x92,3,
// 	  8, 16,0x96,3,
// 	 16,  0,0x82,3,
// 	0x80

// };

// const unsigned char animate_acornleft_data[]={

// 	  0,  0,0x93,1,
// 	  0,  8,0xa3,1,
// 	0x80

// };

// const unsigned char animate_squirrelright1_data[]={

// 	  9,  3,0xa5,2|OAM_FLIP_H,
// 	  8,  0,0x80,3|OAM_FLIP_H,
// 	  8, 16,0x83,3|OAM_FLIP_H,
// 	  0,  0,0x81,3|OAM_FLIP_H,

// 	 11, 15,0xa3,1|OAM_FLIP_H,
// 	 11,  7,0x93,1|OAM_FLIP_H,
// 	  8,  8,0x90,3|OAM_FLIP_H,
// 	  0,  8,0x91,3|OAM_FLIP_H,

// 	- 8,  8,0x92,3|OAM_FLIP_H,
// 	  0, 16,0x84,3|OAM_FLIP_H,
// 	- 8,  0,0x82,3|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_squirrelright2_data[]={

// 	  9,  4,0xa5,2|OAM_FLIP_H,
// 	  8,  1,0x80,3|OAM_FLIP_H,
// 	  8, 16,0x85,3|OAM_FLIP_H,
// 	  0,  0,0x62,3|OAM_FLIP_H,

// 	 11, 15,0xa3,1|OAM_FLIP_H,
// 	 11,  7,0x93,1|OAM_FLIP_H,
// 	  0,  8,0x72,3|OAM_FLIP_H,
// 	- 8,  8,0x73,3|OAM_FLIP_H,

// 	  0, 16,0x86,3|OAM_FLIP_H,
// 	- 8,  0,0x63,3|OAM_FLIP_H,
// 	  8,  9,0x90,3|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_squirrelright3_data[]={

// 	  9,  3,0xa5,2|OAM_FLIP_H,
// 	  8,  0,0x80,3|OAM_FLIP_H,
// 	  8, 16,0x95,3|OAM_FLIP_H,
// 	  0,  0,0x81,3|OAM_FLIP_H,

// 	 11, 15,0xa3,1|OAM_FLIP_H,
// 	 11,  7,0x93,1|OAM_FLIP_H,
// 	  8,  8,0x90,3|OAM_FLIP_H,
// 	  0,  8,0x91,3|OAM_FLIP_H,

// 	- 8,  8,0x92,3|OAM_FLIP_H,
// 	  0, 16,0x96,3|OAM_FLIP_H,
// 	- 8,  0,0x82,3|OAM_FLIP_H,
// 	0x80

// };

// const unsigned char animate_acornright_data[]={

// 	  0,  0,0x93,1|OAM_FLIP_H,
// 	  0,  8,0xa3,1|OAM_FLIP_H,
// 	0x80

// };

const unsigned char animate_starburst1_data[] = {

		1, -8, 0x59, 1,
		8, -8, 0x59, 1 | OAM_FLIP_H,
		8, -1, 0x59, 1 | OAM_FLIP_H | OAM_FLIP_V,
		1, -1, 0x59, 1 | OAM_FLIP_V,
		0x80

};

const unsigned char animate_starburst2_data[] = {

		1, -8, 0x5a, 1,
		8, -8, 0x5a, 1 | OAM_FLIP_H,
		8, -1, 0x5a, 1 | OAM_FLIP_H | OAM_FLIP_V,
		1, -1, 0x5a, 1 | OAM_FLIP_V,
		0x80

};

const unsigned char animate_starburst3_data[] = {

		8, -8, 0x5b, 1 | OAM_FLIP_H,
		8, -1, 0x5b, 1 | OAM_FLIP_H | OAM_FLIP_V,
		1, -1, 0x5b, 1 | OAM_FLIP_V,
		1, -8, 0x5b, 1,
		0x80

};

const unsigned char animate_slideleft_data[] = {

		0, 5, 0xa6, 0,

		8, 5, 0xb6, 0,

		16, 4, 0xc6, 0,

		24, 5, 0xd6, 0,

		-8, 13, 0xe6, 0,

		0, 13, 0xf6, 0,

		8, 13, 0x3e, 0,

		16, 12, 0x4e, 0,

		24, 13, 0x4f, 0,

		1, 6, 0x0b, 2,

		0x80

};

const unsigned char animate_slideright_data[] = {

		8, 5, 0xa6, 0 | OAM_FLIP_H,

		0, 5, 0xb6, 0 | OAM_FLIP_H,

		-8, 4, 0xc6, 0 | OAM_FLIP_H,

		-16, 5, 0xd6, 0 | OAM_FLIP_H,

		16, 13, 0xe6, 0 | OAM_FLIP_H,

		8, 13, 0xf6, 0 | OAM_FLIP_H,

		0, 13, 0x3e, 0 | OAM_FLIP_H,

		-8, 12, 0x4e, 0 | OAM_FLIP_H,

		-16, 13, 0x4f, 0 | OAM_FLIP_H,

		7, 6, 0x0b, 2 | OAM_FLIP_H,

		0x80

};

const unsigned char animate_scroll_data[] = {

		0, -8, 0x5c, 1,

		8, -8, 0x5d, 1,

		0, 0, 0x5c, 1 | OAM_FLIP_V,

		8, 0, 0x5d, 1 | OAM_FLIP_V,

		0x80

};