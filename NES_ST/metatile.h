// const unsigned char palette_bg[16] = {
// 		0x21, 0x0f, 0x2d, 0x10,
// 		0x21, 0x30, 0x29, 0x06,
// 		0x21, 0x0f, 0x17, 0x06,
// 		0x21, 0x0f, 0x19, 0x29};

const unsigned char palette_bg[16] = {
		0x21, 0x0f, 0x00, 0x10,
		0x21, 0x30, 0x29, 0x06,
		0x21, 0x0f, 0x16, 0x06,
		0x21, 0x0f, 0x19, 0x29};

const unsigned char metatile[] = {
		123, 124, 139, 140, 0,
		125, 126, 141, 142, 0,
		155, 156, 171, 172, 0,
		157, 158, 173, 174, 0,
		190, 175, 123, 124, 0,
		190, 190, 139, 140, 0,
		190, 191, 141, 142, 0,
		190, 190, 173, 174, 0,
		190, 185, 155, 156, 0,
		190, 190, 157, 158, 0,
		190, 187, 171, 172, 0,
		190, 175, 173, 174, 0,
		190, 189, 123, 124, 0,
		190, 189, 125, 126, 0,
		186, 191, 155, 156, 0,
		186, 184, 157, 158, 0,
		123, 174, 124, 123, 0,
		139, 140, 155, 156, 0,
		141, 142, 157, 158, 0,
		123, 124, 139, 1, 0,
		173, 142, 174, 1, 0,
		173, 1, 1, 1, 0,
		125, 126, 1, 1, 0,
		157, 158, 1, 1, 0,
		171, 172, 1, 1, 0,
		1, 123, 1, 1, 0,
		123, 173, 1, 174, 0,
		123, 124, 1, 123, 0,
		122, 124, 139, 140, 0,
		0, 0, 0, 122, 0,
		123, 106, 124, 123, 0,
		0, 0, 106, 0, 0,
		117, 118, 133, 134, 2,
		101, 102, 133, 134, 2,
		117, 118, 149, 150, 2,
		116, 118, 132, 134, 2,
		117, 119, 133, 135, 2,
		100, 102, 132, 134, 2,
		101, 103, 133, 135, 2,
		116, 118, 148, 150, 2,
		117, 119, 149, 151, 2,
		187, 205, 203, 203, 2,
		205, 188, 221, 220, 2,
		204, 205, 220, 203, 2,
		205, 175, 220, 203, 2,
		204, 207, 203, 223, 2,
		206, 205, 222, 220, 2,
		206, 205, 222, 203, 2,
		101, 102, 149, 150, 2,
		100, 102, 148, 150, 2,
		101, 103, 149, 151, 2,
		235, 235, 251, 252, 3,
		235, 234, 252, 251, 3,
		250, 235, 252, 252, 3,
		235, 236, 251, 252, 3,
		152, 153, 168, 169, 3,
		154, 152, 170, 168, 3,
		1, 1, 154, 152, 3,
		123, 139, 173, 155, 0,
		142, 123, 156, 174, 0,
		139, 124, 155, 173, 0,
		10, 11, 10, 11, 2,
		10, 11, 10, 11, 2,
		202, 202, 218, 218, 0,
		56, 54, 54, 54, 2,
		55, 54, 54, 54, 2,
		55, 57, 54, 55, 2,
		50, 48, 50, 48, 2,
		49, 48, 49, 48, 2,
		49, 49, 49, 49, 2,
		50, 48, 52, 49, 2,
		48, 51, 48, 53, 2,
		1, 1, 31, 2, 2,
		48, 51, 48, 51, 2,
		2, 13, 14, 2, 3,
		1, 1, 2, 2, 3,
		31, 2, 2, 47, 3,
		27, 12, 2, 1, 3,
		5, 1, 4, 1, 2,
		15, 63, 1, 2, 3,
		0, 0, 0, 0, 0,
		1, 1, 1, 1, 0,
		1, 1, 42, 1, 3,
		26, 1, 1, 42, 3,
		1, 1, 1, 26, 3,
		242, 242, 1, 1, 2,
		1, 243, 1, 1, 2,
		212, 1, 1, 1, 2,
		0, 0, 128, 129, 3,
		0, 0, 130, 130, 3,
		1, 42, 2, 2, 3,
		26, 1, 2, 2, 3,
		3, 170, 3, 232, 3,
		168, 169, 104, 252, 3,
		138, 3, 248, 3, 3,
		3, 3, 233, 3, 3,
		8, 25, 9, 24, 2,
		8, 25, 8, 24, 2,
		177, 178, 8, 24, 2,
		212, 176, 243, 192, 2,
		8, 25, 193, 194, 2,
		179, 243, 195, 212, 2,
		0, 0, 0, 240, 2,
		241, 0, 0, 0, 2,
		20, 4, 21, 4, 2,
		21, 4, 21, 5, 2,
		229, 230, 20, 4, 2,
		212, 228, 243, 244, 2,
		20, 4, 245, 246, 2,
		231, 243, 247, 212, 2,
		0, 226, 0, 0, 2,
		227, 0, 0, 0, 2,
		6, 23, 6, 23, 2,
		7, 22, 7, 23, 2,
		6, 23, 7, 23, 2,
		224, 225, 6, 22, 2,
		212, 208, 242, 242, 2,
		209, 243, 242, 242, 2,
		0, 0, 0, 210, 2,
		0, 0, 211, 0, 2,
		3, 3, 170, 170, 3,
		4, 227, 4, 0, 2,
		169, 169, 120, 105, 3,
		0, 0, 137, 0, 3,
		138, 0, 138, 0, 3,
		138, 0, 121, 0, 3,
		3, 3, 3, 249, 3,
		249, 233, 170, 170, 3,
		144, 144, 0, 0, 2,
		145, 146, 0, 0, 2,
		1, 1, 146, 146, 2,
		146, 144, 0, 0, 2,
		1, 1, 146, 144, 2,
		104, 168, 1, 105, 3,
		104, 105, 238, 237, 3,
		104, 104, 239, 238, 3,
		105, 104, 238, 237, 3,
		104, 239, 239, 255, 3,
		105, 237, 238, 238, 3,
		169, 104, 104, 1, 3,
		170, 168, 104, 105, 3,
		170, 168, 104, 104, 3,
		169, 138, 170, 138, 3,
		168, 138, 170, 138, 3,
		168, 169, 169, 170, 3,
		170, 169, 168, 168, 3,
		169, 170, 170, 169, 3,
		168, 168, 169, 168, 3,
		169, 169, 170, 169, 3,
		0, 122, 136, 170, 3,
		0, 136, 136, 170, 3,
		106, 0, 170, 106, 3,
		137, 0, 168, 137, 3,
		169, 106, 170, 170, 3,
		1, 255, 255, 0, 3,
		255, 1, 0, 254, 3,
		239, 239, 254, 253, 3,
		237, 238, 254, 255, 3,
		253, 254, 0, 0, 3,
		169, 121, 255, 0, 3,
		5, 3, 5, 3, 3,
		63, 3, 5, 3, 3,
		5, 3, 47, 3, 3,
		1, 31, 31, 2, 3,
		15, 2, 1, 15, 3,
		2, 47, 17, 17, 3,
		3, 3, 17, 17, 3,
		3, 97, 96, 3, 3,
		3, 98, 3, 3, 3,
		3, 3, 97, 3, 3,
		96, 3, 3, 3, 3,
		3, 3, 114, 3, 3,
		0, 0, 0, 113, 3,
		0, 0, 0, 112, 3,
		162, 215, 162, 215, 2,
		255, 253, 0, 0, 3,
		3, 3, 3, 3, 3,
		64, 64, 2, 2, 1,
		0, 0, 0, 5, 2,
		63, 3, 2, 63, 3,
		1, 1, 13, 1, 3,
		3, 14, 3, 3, 3,
		99, 131, 115, 147, 2,
		14, 2, 3, 14, 1,
		63, 3, 2, 63, 1,
		3, 3, 3, 3, 2,
		3, 98, 96, 3, 2,
		97, 3, 3, 3, 2,
		3, 3, 96, 3, 2,
		3, 3, 3, 114, 1,
		97, 3, 3, 98, 1,
		3, 96, 3, 3, 1,
		181, 182, 197, 198, 2,
		1, 180, 1, 196, 2,
		183, 1, 199, 1, 2,
		1, 1, 165, 166, 2,
		213, 214, 1, 1, 2,
		0, 0, 107, 107, 0,
		160, 161, 160, 161, 1,
		16, 16, 1, 1, 0,
		1, 159, 1, 1, 0,
		200, 201, 216, 217, 2,
		1, 1, 217, 1, 2,
		1, 200, 1, 1, 2,
		1, 201, 1, 217, 2,
		216, 1, 1, 1, 2,
		216, 1, 1, 201, 2,
		1, 216, 201, 1, 2,
		0, 94, 108, 3, 0,
		0, 0, 107, 108, 0,
		107, 94, 3, 109, 0,
		107, 94, 109, 93, 0,
		109, 3, 3, 109, 0,
		109, 109, 3, 3, 0,
		109, 3, 3, 3, 0,
		109, 64, 109, 64, 0,
		64, 110, 111, 64, 0,
		109, 20, 3, 111, 0,
		64, 110, 64, 64, 0,
		110, 110, 64, 110, 0,
		0, 0, 30, 30, 1,
		0, 0, 0, 28, 1,
		0, 0, 29, 0, 1,
		109, 109, 163, 167, 0,
		93, 91, 64, 159, 0,
		92, 128, 159, 1, 0,
		0, 0, 91, 92, 0,
		95, 0, 159, 95, 0,
		91, 92, 159, 1, 0,
		107, 108, 1, 163, 0,
		109, 3, 164, 3, 0,
		163, 167, 159, 159, 0,
		3, 109, 167, 3, 0,
		159, 159, 159, 159, 0,
		1, 1, 159, 159, 0,
		159, 1, 159, 159, 0,
		110, 159, 110, 143, 0,
		143, 127, 110, 110, 0,
		159, 159, 143, 127, 0,
		127, 159, 110, 143, 0};

const unsigned char metatile_colision_map[] = {
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_LADDER, COL_LADDER_TOP, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};