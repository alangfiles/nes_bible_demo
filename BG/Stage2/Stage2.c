
#include "level0.c"
#include "level1.c"
#include "level2.c"
#include "level3.c"
#include "level4.c"
#include "level5.c"
#include "level6.c"
#include "level7.c"
#include "level8.c"
#include "level9.c"

const unsigned char *const stage2_levels_list[] = {
    level0_0, level0_1,
    level1_0,
    level2_0,
    level3_0, level3_1, level3_2, // 5
    level4_0,
    level5_0, level5_1, level5_2, level5_3,
    level6_0,
    level7_0, // 14
    level8_0, level8_1, level8_2, level8_3, level8_4,
    level9_0};

const unsigned char level_max_rooms[] = {
    2, 1, 1, 3, 1, 4, 1, 1, 5, 1};

const unsigned char level_offsets[] = {
    0, 2, 3, 4, 7, 8, 12, 13, 14, 19, 20};

enum
{
    ENEMY_SNAIL,
    ENEMY_OWL,
    ENEMY_SNAKE,
};

enum
{
    ENTITY_LEVEL_UP,
    ENTITY_PIT,
    ENTITY_PIT_WIDE_64,
    ENTITY_LEVEL_DOWN,
    ENTITY_SPIKE_WIDE_64
};

// NOTE MAX_ENEMY = 10

// NOTE, after testing, we can only handle 4 enemies on the same screen

// y, room, x, type,
// y = TURN_OFF end of list
const unsigned char level_0_enemies[] = {
    // 48, 1, 96,  ENEMY_OWL,
    // 16, 1, 192,  ENEMY_OWL,
    // 32, 3, 160,  ENEMY_OWL,
    192, 1, 160, ENEMY_SNAIL,
    128, 3, 16, ENEMY_SNAIL,
    128, 5, 80, ENEMY_SNAIL,
    64, 6, 32, ENEMY_SNAIL,
    64, 7, 144, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_1_enemies[] = {
    176, 0, 112, ENEMY_SNAIL,
    48, 0, 160, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_2_enemies[] = {
    160, 1, 96, ENEMY_SNAIL,
    96, 2, 128, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_3_enemies[] = {
    // 48, 0, 48,  ENEMY_OWL,
    128, 0, 176, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_4_enemies[] = {
    // 0, 0, 160,  ENEMY_OWL,
    128, 0, 224, ENEMY_SNAIL,
    // 48, 0, 224,  ENEMY_OWL,
    192, 1, 176, ENEMY_SNAIL,
    // 32, 2, LEVEL_BOTTOM,  ENEMY_OWL,
    // 96, 3, LEVEL_BOTTOM,  ENEMY_OWL,
    96, 4, 192, ENEMY_SNAIL,
    TURN_OFF};
const unsigned char level_5_enemies[] = {
    // 80, 0, 112,  ENEMY_OWL,

    TURN_OFF};
const unsigned char level_6_enemies[] = {
    TURN_OFF};

#define LEVEL_BOTTOM 230
#define LEVEL_TOP 0

const unsigned char *const Enemy_list[] = {
    level_0_enemies, level_1_enemies, level_2_enemies,
    level_3_enemies, level_4_enemies, level_5_enemies,
    level_6_enemies};

const unsigned char level_0_entities[] = {
    LEVEL_TOP, 1, 80, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_1_entities[] = {
    LEVEL_BOTTOM, 0, 80, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 80, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_2_entities[] = {
    LEVEL_BOTTOM, 0, 80, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 160, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_3_entities[] = {
    LEVEL_BOTTOM, 0, 160, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 2, 176, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_4_entities[] = {
    LEVEL_BOTTOM, 0, 176, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 128, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_5_entities[] = {
    LEVEL_BOTTOM, 0, 128, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 3, 176, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_6_entities[] = {
    LEVEL_BOTTOM, 0, 176, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 144, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_7_entities[] = {
    LEVEL_BOTTOM, 0, 128, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 0, 128, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_8_entities[] = {
    LEVEL_BOTTOM, 0, 128, ENTITY_LEVEL_DOWN,
    // LEVEL_BOTTOM, 0, 0, ENTITY_LEVEL_DOWN_WIDE_256,
    LEVEL_TOP, 4, 192, ENTITY_LEVEL_UP,
    TURN_OFF};
const unsigned char level_9_entities[] = {
    TURN_OFF};

const unsigned char *const entity_list[] = {
    level_0_entities, level_1_entities, level_2_entities,
    level_3_entities, level_4_entities, level_5_entities,
    level_6_entities};
