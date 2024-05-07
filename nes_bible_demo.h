// PLAYER + GLOBAL
#define ACCEL 30
#define LADDER_ACCEL 20
#define DECEL 50
#define HITSTUN_DECEL 65
#define MAX_SPEED 0x160
#define MAX_LADDER_SPEED 0x100
#define JUMP_VEL -0x510
#define MAX_PLAYER_HEALTH 28
#define GRAVITY 0x3c
#define MAX_PROJECTILES 3
#define PROJECTILE_COOLDOWN_FRAMES 10
#define PROJECTILE_SPEED 3
#define PROJECTILE_SPEED_WITH_SCROLL 5

//Collision + Extra
#define COL_DOWN 0x80
#define COL_ALL 0x40
#define COL_LADDER 0x01
#define COL_LADDER_TOP 0x02
#define TURN_OFF 0xff

//SCROLL
#define MAX_RIGHT 0x9000
#define MAX_LEFT 0x4000

// needed for sprites
#define B4 0
#define B3 0
#define OAM_PRIO 0

#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
unsigned char debug;
unsigned char pad1;
unsigned char pad1_new;
unsigned char short_jump_count;
unsigned char map_loaded;
unsigned char collision;
unsigned char player_in_air;
unsigned char player_is_running;
unsigned char player_on_ladder;
unsigned char player_on_ladder_pose;
unsigned char player_in_hitstun;
unsigned char player_running;
unsigned char collision_L;
unsigned char collision_R;
unsigned char collision_U;
unsigned char collision_D;
unsigned char coordinates;
unsigned char nametable_to_load;
unsigned char temp1;
unsigned char temp2;
unsigned char temp3;
unsigned char temp4;
unsigned char multi_jump;
unsigned int temp5;
unsigned int temp6;
unsigned int tempint;
unsigned int tempint2;
unsigned int temp_playerlocation;
unsigned char level;
unsigned char offset;
unsigned char level_up;
unsigned char level_down;
unsigned char eject_L;				 // from the left
unsigned char eject_R;				 // remember these from the collision sub routine
unsigned char eject_D;				 // from below
unsigned char eject_U;				 // from up
unsigned char direction = 1;	 // facing left or right?
unsigned char hit_direction;	 // hit direction
unsigned char direction_y = 1; // going up or down
unsigned char sprite_frame_counter;
unsigned char frame_counter;
unsigned char frame_counter2;
#define LEFT 0
#define RIGHT 1
#define DOWN 4
#define UP 3

int address;
unsigned char x; // room loader code
unsigned char y;
unsigned char nt;
unsigned char index;
unsigned char index2;
unsigned char room_to_load = 0;
unsigned char current_room = 0;
unsigned char map;
unsigned int scroll_x;
unsigned int scroll_y;
unsigned char scroll_count;
unsigned int pseudo_scroll_x;

unsigned char song;
#define MAX_SONGS 1
enum
{
	SONG_GAME,
	// SONG_PAUSE
};
enum {
	SFX_SHOOT,
	SFX_ENEMY_HITS,
	SFX_SHOT_HITS,
	SFX_LIFE_UP,
	SFX_PLAYER_DIES,
	SFX_JUMP,
	SFX_START_LEVEL,
	SFX_VICTORY
};

unsigned char game_mode;
enum
{
	MODE_TITLE,
	MODE_GAME,
	MODE_PAUSE,
	MODE_DEATH,
	MODE_SWITCH,
	MODE_END,
	MODE_GAME_OVER,
	MODE_RESET,
	BOSS_ENTRY
};

const unsigned char *pointer;
unsigned char l_scroll_frames;
unsigned char r_scroll_frames;
unsigned int old_x;
unsigned int old_y;
unsigned char bright;
unsigned char bright_count;
unsigned char temp;
unsigned char temp_x;
unsigned char temp_y;
unsigned char temp_room;
unsigned char player_shooting;
unsigned char death;
unsigned char death_flag;
unsigned char invul_frames;
unsigned char projectile_cooldown;
unsigned char projectile_count;
unsigned char projectile_index;
unsigned char projectiles_list[] = {TURN_OFF, TURN_OFF, TURN_OFF, TURN_OFF};
unsigned char projectiles_x[] = {0, 0, 0, 0};
unsigned char projectiles_y[] = {0, 0, 0, 0};

unsigned char sine_wave[] = {5, 8, 10, 10, 8, 5, 2, 0, 0, 2};
// for shuffling 16 enemies
const unsigned char shuffle_array[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
		0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15,
		15, 13, 11, 9, 7, 5, 3, 1, 14, 12, 10, 8, 6, 4, 2, 0};
unsigned char offset;

#pragma bss-name(push, "BSS")

unsigned char c_map[240];
unsigned char c_map2[240]; // not used in this example

struct Base
{
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

struct Base Generic;
struct Base Generic2;

struct Hero
{
	unsigned int x; // low byte is sub-pixel
	unsigned int y;
	signed int vel_x; // speed, signed, low byte is sub-pixel
	signed int vel_y;
	unsigned char health;
};

struct Hero BoxGuy1 = {0x4000, 0x8400}; // starting position
// the width and height should be 1 less than the dimensions (14x14)
// note, I'm using the top left as the 0,0 on x,y

#define HERO_WIDTH 14
#define HERO_HEIGHT 14

// #define MAX_ROOMS (11-1)
// #define MAX_SCROLL (MAX_ROOMS * 0x100)-1
#define MIN_SCROLL 0x0000

unsigned char max_rooms;
unsigned int max_scroll;
// data is exactly 240 bytes, 16 * 15
// doubles as the collision map data

const unsigned char palette_sp[] = {
		0x21, 0x17, 0x24, 0x36,
		0x21, 0x06, 0x28, 0x37,
		0x21, 0x0f, 0x11, 0x30,
		0x21, 0x17, 0x3d, 0x38};

#define MAX_ENEMY 16
unsigned char enemy_x[MAX_ENEMY];
unsigned char enemy_y[MAX_ENEMY];
unsigned char enemy_active[MAX_ENEMY];
unsigned char enemy_mode[MAX_ENEMY];
unsigned char enemy_health[MAX_ENEMY];
unsigned char enemy_room[MAX_ENEMY];
unsigned char enemy_actual_x[MAX_ENEMY];
unsigned char enemy_type[MAX_ENEMY];
unsigned char enemy_dir[MAX_ENEMY];
const unsigned char *enemy_anim[MAX_ENEMY];
unsigned char enemy_frames[MAX_ENEMY];

#define MAX_ENTITY 16
unsigned char entity_x[MAX_ENTITY];
unsigned char entity_y[MAX_ENTITY];
unsigned char entity_active[MAX_ENTITY];
unsigned char entity_room[MAX_ENTITY];
unsigned char entity_actual_x[MAX_ENTITY];
unsigned char entity_type[MAX_ENTITY];
const unsigned char *entity_anim[MAX_ENTITY];
unsigned char entity_frames[MAX_ENTITY];

#define ENEMY_WIDTH 13
#define ENEMY_HEIGHT 13

// 5 bytes per metatile definition, tile TL, TR, BL, BR, palette 0-3
// T means top, B means bottom, L left,R right
// 51 maximum # of metatiles = 255 bytes
#include "BG/Stage1/metatile.h"

#include "BG/Stage1/Stage1.c"
// data is exactly 240 bytes, 16 * 15
// doubles as the collision map data

// PROTOTYPES
void load_room(void);
void draw_sprites(void);
void movement(void);
char bg_collision_sub(void);
void draw_screen_R(void);
void draw_screen_L(void);
void new_cmap(void);
void handle_scrolling(void);
void projectile_movement(void);
void check_spr_objects(void);
void check_entity_objects(void);
void sprite_collisions(void);
void entity_collisions(void);
void load_title(void);
void load_victory(void);

void enemy_moves(void);
void entity_moves(void);
void reset(void);
void sprite_obj_init(void);
void entity_obj_init(void);
void init_death(void);
void init_mode_switch(void);
void level_down_routine(void);
void enemy_snail_behavior(void);
void enemy_owl_behavior(void);
void enemy_bear_behavior(void);

char bg_coll_L(void);
char bg_coll_R(void);
char bg_coll_U(void);
char bg_coll_D(void);
char bg_coll_D2(void);
char get_position(void);