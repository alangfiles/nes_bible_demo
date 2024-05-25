
#include "level0.c"
#include "level1.c"
#include "level2.c"
#include "level3.c"
#include "level4.c"
#include "level5.c"
#include "level6.c"
#include "level7.c"

const unsigned char *const stage1_levels_list[] = {
    level0_0, level0_1, level0_2, level0_3, level0_4, level0_5, level0_6, level0_7,
    level1_0,
    level2_0, level2_1, level2_2, level2_3,
    level3_0,
    level4_0, level4_1, level4_2, level4_3, level4_4,
    level5_0,
    level6_0, level6_1,
    level7_0};

const unsigned char level_max_rooms[] = {
    8, 1, 4, 1, 5, 1, 2, 1};

const unsigned char level_offsets[] = {
    0, 8, 9, 13, 14, 19, 20, 22};

const unsigned char starting_x_place[] = {
    30, 60, 40, 200, 60, 180, 40, 180
};
const unsigned char starting_y_place[] = {
    160, 180, 180, 100, 80, 190, 190, 180
};

enum
{
    ENEMY_SNAIL,
    ENEMY_OWL,
    ENEMY_BEAR,
};

enum
{
    ENTITY_LEVEL_UP,
    ENTITY_PIT,
    ENTITY_PIT_WIDE_64,
    ENTITY_LEVEL_DOWN,
    ENTITY_LEVEL_DOWN_WIDE_256,
    ENTITY_LEVEL_UP_WIDE_256,
    ENTITY_SPIKE_WIDE_64,
    ENTITY_WINE,
    ENTITY_BREAD,
    ENTITY_BUN,
    ENTITY_FRUIT,
    ENTITY_ROCK,
    ENTITY_STARBURST
};

// NOTE MAX_ENEMY = 10

// NOTE, after testing, we can only handle 4 enemies on the same screen

#define LEVEL_BOTTOM 230
#define LEVEL_TOP 0

// y, room, x, type,
// y = TURN_OFF end of list
const unsigned char level_0_enemies[] = {
	192, 0, 224, ENEMY_SNAIL,
    48, 1, 144,  ENEMY_OWL,
	176, 1, 224, ENEMY_SNAIL,
	128, 3, 0, ENEMY_SNAIL,
	48, 3, 144, ENEMY_OWL,
	128, 5, 160,  ENEMY_SNAIL,
	144, 6, 128,  ENEMY_SNAIL,
	0, 7, 112, ENEMY_OWL,
	64, 7, 144,  ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_1_enemies[] = {
	96, 0, 128,  ENEMY_SNAIL,
	16, 0, 192,  ENEMY_OWL,
    TURN_OFF};
const unsigned char level_2_enemies[] = {
	144, 0, 128, ENEMY_SNAIL,
	160, 1, 64,  ENEMY_SNAIL,
	96, 2, 96, ENEMY_SNAIL,
	144, 2, 224,  ENEMY_SNAIL,
	192, 3, 160, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_3_enemies[] = {
    48, 0, 48,  ENEMY_OWL,
    128, 0, 176, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_4_enemies[] = {
    0, 0, 160,  ENEMY_OWL,
    128, 0, 224, ENEMY_SNAIL,
    48, 0, 224,  ENEMY_OWL,
    192, 1, 176, ENEMY_SNAIL,
    96, 4, 192, ENEMY_SNAIL,
	32, 4, 208, ENEMY_OWL,
    TURN_OFF};
const unsigned char level_5_enemies[] = {
	144, 0, 80, ENEMY_SNAIL,
	112, 0, 192, ENEMY_SNAIL,
	80, 0, 32, ENEMY_SNAIL,
	16,0,32, ENEMY_OWL,
    TURN_OFF};
const unsigned char level_6_enemies[] = {
	16, 0, 96, ENEMY_OWL,
    190, 0, 200, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_7_enemies[] = {
    193, 0, 40, ENEMY_BEAR,
    TURN_OFF};



const unsigned char *const Enemy_list[] = {
    level_0_enemies, level_1_enemies, level_2_enemies,
    level_3_enemies, level_4_enemies, level_5_enemies,
    level_6_enemies, level_7_enemies};

const unsigned char level_0_entities[] = {
    //160, 0, 16, ENTITY_PLAYER_STARAT, 
	LEVEL_BOTTOM, 2, 0, ENTITY_PIT_WIDE_64, // pit begins here; is 80 pixels wide
    LEVEL_BOTTOM, 2, 64, ENTITY_PIT_WIDE_64,
    LEVEL_BOTTOM, 4, 0, ENTITY_PIT_WIDE_64, // pit begins here; is 80 pixels wide
    LEVEL_BOTTOM, 4, 64, ENTITY_PIT_WIDE_64,
    LEVEL_BOTTOM, 5, 96, ENTITY_PIT_WIDE_64,  // pit begins here; is 48 pixels wide
    LEVEL_BOTTOM, 5, 176, ENTITY_PIT_WIDE_64, // pit begins here; is 32 pixels wide
    LEVEL_BOTTOM, 6, 160, ENTITY_PIT_WIDE_64, // pit begins here; is 64 pixels wide
    LEVEL_TOP, 7, 160, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_1_entities[] = {
    LEVEL_BOTTOM, 0, 0xA0, ENTITY_LEVEL_DOWN,
    LEVEL_TOP, 0, 48, ENTITY_LEVEL_UP,
    72, 0, 204, ENTITY_BUN,
    TURN_OFF};
const unsigned char level_2_entities[] = {
    LEVEL_BOTTOM, 0, 48, ENTITY_LEVEL_DOWN,
    LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
	LEVEL_BOTTOM, 1, 0, ENTITY_SPIKE_WIDE_64, // beginning of first spike pit
	LEVEL_BOTTOM, 1, 64, ENTITY_SPIKE_WIDE_64,
    LEVEL_BOTTOM, 1, 128, ENTITY_SPIKE_WIDE_64, 
	LEVEL_BOTTOM, 1, 192, ENTITY_SPIKE_WIDE_64, 
	LEVEL_BOTTOM, 2, 0, ENTITY_SPIKE_WIDE_64, 
	200, 2, 32, ENTITY_BREAD,
    LEVEL_BOTTOM, 2, 144, ENTITY_SPIKE_WIDE_64, // begin of second spike pit
    LEVEL_BOTTOM, 2, 208, ENTITY_SPIKE_WIDE_64,
    LEVEL_BOTTOM, 3, 16, ENTITY_SPIKE_WIDE_64,
    LEVEL_BOTTOM, 3, 176, ENTITY_LEVEL_UP,
    LEVEL_BOTTOM, 3, 192, ENTITY_LEVEL_UP,
    LEVEL_BOTTOM, 3, 218, ENTITY_LEVEL_UP,
    LEVEL_BOTTOM, 3, 234, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_3_entities[] = {
    LEVEL_TOP, 0, 176, ENTITY_LEVEL_DOWN,
    LEVEL_BOTTOM, 0, 48, ENTITY_LEVEL_UP,
    LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_UP_WIDE_256,
    TURN_OFF};
const unsigned char level_4_entities[] = {
    LEVEL_TOP, 0, 48, ENTITY_LEVEL_DOWN,
    LEVEL_TOP, 4, 192, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_5_entities[] = {
    LEVEL_BOTTOM, 0, 192, ENTITY_LEVEL_DOWN,
    LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 48, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_6_entities[] = {
	LEVEL_BOTTOM, 0, 48, ENTITY_LEVEL_DOWN,
    190, 1, 200, ENTITY_STARBURST,
    TURN_OFF};  

const unsigned char *const entity_list[] = {
    level_0_entities, level_1_entities, level_2_entities,
    level_3_entities, level_4_entities, level_5_entities,
    level_6_entities};
