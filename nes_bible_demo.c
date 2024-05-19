/*	Unnamed NES BIBLE Game

	An attempt at making the best Bible game for the NES
	By BrianAndAlanGames

	Based off work by NESDoug
 */

/*
TODO List:
	[] sign posts / text in game?

	[] enemy dying animation
	[] enemy hit animation?
	[] level transition doesn't work?
	[] fix enemy collision (down)
	[] cleanup reset code
	[] add lives / deaths / game over
*/

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "Sprites.h" // holds our metasprite data
#include "nes_bible_demo.h"
#include "enemy_stats.h"
#include "collision.c"
#include "player_sprites.c"
// #include "BG/Stage1/title.h"
// #include "BG/Stage1/gameover.h"

void main(void)
{
	// test

	reset();

	load_title();

	while (1)
	{
		while (game_mode == MODE_TITLE)
		{
			// unused for title screen
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);
			if (pad1_new & PAD_START)
			{
				sfx_play(SFX_START_LEVEL, 0);
				pal_bright(3);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(2);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(1);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(0);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				ppu_off();
				for (temp = 0; temp < 20; ++temp)
				{
					ppu_wait_nmi();
				}
				// load game mode
				game_mode = MODE_GAME;
				load_room();

				ppu_on_all();
				pal_bright(1);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(2);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(3);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}
				pal_bright(4);
				for (temp = 0; temp < 10; ++temp)
				{
					ppu_wait_nmi();
				}

				song = SONG_GAME;
				music_play(song);
				set_music_speed(11);
			}
		}
		while (game_mode == MODE_GAME)
		{
			// gray_line();
			++frame_counter;
			// infinite loop
			ppu_wait_nmi(); // wait till beginning of the frame

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);
			pad1_state = pad_state(0);

			if (pad1_new & PAD_START)
			{
				game_mode = MODE_PAUSE;
				// song = SONG_PAUSE;
				// music_play(song);
				music_stop();
				// color_emphasis(0x01);
				ppu_mask(0b00011001); // grayscale mode

				break; // out of the game loop
			}

			movement();
			check_spr_objects();
			check_entity_objects();
			projectile_movement();

			sprite_collisions();
			entity_collisions();

			set_scroll_x(scroll_x);
			set_scroll_y(scroll_y);

			handle_scrolling();

			draw_sprites();

			if (BoxGuy1.health == 0 || BoxGuy1.health > MAX_PLAYER_HEALTH) // if it wraps
			{
				death = 1;
			}

			if (death)
			{
				init_death();
			}

			// check for player offscreen level flags

			// player goes up to next level //must be on ladder
			if (high_byte(BoxGuy1.y) < 0x08 && level_up && player_on_ladder)
			{
				BoxGuy1.y = 0xD000; // put the user above the bottom of the screen.
				level_up_routine();
			}

			// player goes down to next level, ladder not necessary
			if (high_byte(BoxGuy1.y) > 0xd0 && high_byte(BoxGuy1.y) < 0xf4 && level_up) // todo: might need less than 0xd0
			{
				BoxGuy1.y = 0x1800; // put the user near the top of screen
				level_up_routine();
			}

			// player goes up to previous level
			if (high_byte(BoxGuy1.y) < 0x08 && level_down && player_on_ladder)
			{
				BoxGuy1.y = 0xD000; // put the user above the bottom of the screen.
				level_down_routine();

				// set max scroll and all that jazz.
			}

			// player goes down to previous level
			if (high_byte(BoxGuy1.y) > 0xd0 && level_down)
			{
				BoxGuy1.y = 0x1800; // put the user near the top of screen

				level_down_routine();
			}

			// player is crossing screen border and set to die.
			if (high_byte(BoxGuy1.y) > 0xe8 && death_flag)
			{
				++death;
			}
		}
		while (game_mode == MODE_DEATH)
		{
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);

			temp_x = 120;
			temp_y = 195;
			if (frame_counter < 250)
			{
				oam_clear();
				++frame_counter;
				if (frame_counter < 40)
				{
					oam_meta_spr(temp_x, temp_y, animate_playerstandright_data);
				}
				else if (frame_counter < 50)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright1_data);
				}
				else if (frame_counter < 60)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright2_data);
				}
				else if (frame_counter < 70)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright3_data);
				}
				else if (frame_counter < 80)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright4_data);
				}
				else if (frame_counter < 90)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright5_data);
				}
				else if (frame_counter < 100)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright6_data);
				}
				else if (frame_counter < 110)
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright7_data);
				}
				else
				{
					oam_meta_spr(temp_x, temp_y, animate_deathright8_data);
				}
			}

			if (pad1_new & PAD_START)
			{

				reset();

				load_title();
				game_mode = MODE_TITLE;
			}
		}

		while (game_mode == MODE_PAUSE)
		{
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);

			// draw_sprites();

			if (pad1_new & PAD_START)
			{
				game_mode = MODE_GAME;
				song = SONG_GAME;
				music_play(song);
				// color_emphasis(COL_EMP_NORMAL);
				ppu_mask(0b00011000); // grayscale mode
			}
		}
		while (game_mode == MODE_SWITCH)
		{
			ppu_wait_nmi();
			++bright_count;
			if (bright_count >= 0x10)
			{ // fade out
				bright_count = 0;
				--bright;
				if (bright != 0xff)
					pal_bright(bright); // fade out
			}
			set_scroll_x(scroll_x);

			if (bright == 0xff)
			{ // now switch rooms
				ppu_off();
				oam_clear();
				if (level < 20)
				{
					load_room();
					game_mode = MODE_GAME;
					ppu_on_all();
					pal_bright(4); // back to normal brighness
				}
			}
		}
		while (game_mode == MODE_END)
		{
			ppu_wait_nmi();

			pad1 = pad_poll(0); // read the first controller
			pad1_new = get_pad_new(0);

			// draw_sprites();

			if (pad1_new & PAD_START)
			{
				reset();
				game_mode = MODE_TITLE;
			}
		}
	}
}

#include "BG/Stage1/titletiled.c"
void load_title(void)
{
	ppu_off();

	pal_bg(palette_bg);
	set_data_pointer(titletiled_0);
	set_mt_pointer(metatile);
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}
	ppu_on_all();
	game_mode = MODE_TITLE;
	multi_vram_buffer_horz("CORGS DEMO", 10, NTADR_A(14, 6));

	multi_vram_buffer_horz("BRIAN & ALAN GAMES", 18, NTADR_A(12, 8));
}

#include "BG/Stage1/gameovertiled.c"
const unsigned char palette_gameover[16] = {0x0f, 0x0f, 0x00, 0x10, 0x0f, 0x0f, 0x30, 0x08, 0x0f, 0x0f, 0x17, 0x06, 0x0f, 0x0f, 0x19, 0x29};
void load_gameover(void)
{
	clear_vram_buffer();

	pal_bg(palette_gameover);
	set_data_pointer(gameovertiled_0);
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	};
	multi_vram_buffer_horz("GAME OVER", 10, NTADR_A(11, 12));

	multi_vram_buffer_horz("PRESS START", 12, NTADR_A(10, 14));
}

#include "BG/Stage1/victory.h"
const unsigned char palette_victory[16] = {
		0x21, 0x0f, 0x00, 0x10,
		0x21, 0x21, 0x30, 0x21,
		0x21, 0x30, 0x21, 0x30,
		0x21, 0x0f, 0x0f, 0x29};
void load_victory(void)
{
	ppu_off(); // screen off

	pal_bg(palette_victory);
	vram_adr(NAMETABLE_A);
	// this sets a start position on the BG, top left of screen
	// vram_adr() and vram_unrle() need to be done with the screen OFF

	vram_unrle(victory);
	ppu_on_all();
	music_stop();
	sfx_play(SFX_VICTORY, 0);

	game_mode = MODE_END;
}

void reset(void)
{
	oam_clear();
	ppu_wait_nmi();
	ppu_off();		 // screen off
	pal_bright(4); // back to normal brightness
	scroll_x = 0;
	scroll_y = 0;
	map_loaded = 0;
	player_in_air = 0;
	falling_down = 0;
	player_on_ladder = 0;
	player_running = 0;
	short_jump_count = 0;
	multi_jump = 0;
	projectile_cooldown = 0;
	projectile_count = 0;
	projectile_index = 0;
	player_shooting = 0;
	direction = 1;
	direction_y = 0; // down default?
	frame_counter = 0;
	sprite_frame_counter = 0;
	r_scroll_frames = 0;
	l_scroll_frames = 0;
	collision = 0;
	death = 0;
	BoxGuy1.x = 0x4000;
	BoxGuy1.y = 0x8400;
	BoxGuy1.health = MAX_PLAYER_HEALTH;
	invul_frames = 0;
	game_mode = MODE_GAME;
	level = 6;				// debug, change starting level
	room_to_load = 0; // debug, hacky, change starting room
	debug = 0;
	player_in_hitstun = 0;
	invul_frames = 0;
	nametable_to_load = 0;

	// clear all projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		projectiles_list[temp1] = TURN_OFF;
	}

	// clear all enemies and entities
	for (temp1 = 0; temp1 < MAX_ENTITY; ++temp1)
	{
		entity_y[temp1] = TURN_OFF;
	}
	for (temp1 = 0; temp1 < MAX_ENEMY; ++temp1)
	{
		enemy_y[temp1] = TURN_OFF;
	}

	ppu_mask(0); // grayscale mode
	// load the palettes
	pal_bg(palette_bg);
	pal_spr(palette_sp);

	// use the second set of tiles for sprites
	// both bg and sprites are set to 0 by default
	bank_spr(0);
	bank_bg(1);

	set_vram_buffer(); // do at least once, sets a pointer to a buffer

	load_room();

	set_scroll_y(0xff); // shift the bg down 1 pixel

	ppu_on_all(); // turn on screen
}

void projectile_movement(void)
{
	for (temp1 = 0; temp1 < 3; ++temp1)
	{
		if (projectiles_list[temp1] != TURN_OFF)
		{
			if (projectiles_x[temp1] > 250)
			{
				projectiles_list[temp1] = TURN_OFF;
			}
			else
			{

				// This code adjusts for when the screen is scrolling too.
				if (projectiles_list[temp1] == RIGHT)
				{

					if ((BoxGuy1.x <= MAX_LEFT) && (pad1 & PAD_LEFT))
					{
						projectiles_x[temp1] += PROJECTILE_SPEED_WITH_SCROLL;
					}
					else
					{
						projectiles_x[temp1] += PROJECTILE_SPEED;
					}
				}
				else if (projectiles_list[temp1] == LEFT)
				{
					if ((BoxGuy1.x >= MAX_RIGHT) && (pad1 & PAD_RIGHT))
					{
						projectiles_x[temp1] -= PROJECTILE_SPEED_WITH_SCROLL;
					}
					else
					{
						projectiles_x[temp1] -= PROJECTILE_SPEED;
					}
				}
			}
		}
	}
}

void handle_scrolling(void)
{
	// how to do scrolling:
	// if the hero is facing right, put an attribute column in front of the current nametable window
	// (4 frames = 1 column of 4 metatiles = 1 attribute column)
	// if the hero is facing left, put an attribute column in behind the current nametable window

	// figure out if we're drawing to the right or left
	if (!r_scroll_frames && !l_scroll_frames)
	{
		if (BoxGuy1.vel_x > 0)
		{
			r_scroll_frames = 4;
		}
		else
		{
			l_scroll_frames = 4;
		}
	}

	if (r_scroll_frames)
	{
		draw_screen_R();
		--r_scroll_frames;
	}
	else if (l_scroll_frames)
	{
		draw_screen_L();
		--l_scroll_frames;
	}
}

void load_room(void)
{
	offset = level_offsets[level];
	offset += room_to_load;
	set_data_pointer(stage1_levels_list[offset]);
	set_mt_pointer(metatile);
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(nametable_to_load, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}

	ppu_off();
	// a little bit in the next room
	set_data_pointer(stage1_levels_list[offset + 1]);
	for (y = 0;; y += 0x20)
	{
		x = 0;
		temp1 = (nametable_to_load + 1) % 2;
		address = get_ppu_addr(temp1, x, y);
		index = (y & 0xf0);
		buffer_4_mt(address, index); // ppu_address, index to the data
		flush_vram_update2();
		if (y == 0xe0)
			break;
	}
	// a little bit in the previous room
	set_data_pointer(stage1_levels_list[offset - 1]);
	for (y = 0;; y += 0x20)
	{
		x = 240;
		temp1 = (nametable_to_load + 1) % 2;
		address = get_ppu_addr(temp1, x, y);
		index = y + (x >> 4);
		// index = (y & 0xd8); //ALAN <-- fix
		buffer_4_mt(address, index); // ppu_address, index to the data
		flush_vram_update2();
		if (y == 0xe0)
			break;
	}

	// copy the room to the collision map
	// the second one should auto-load with the scrolling code
	// we also copy the previous map into the other collision nametable
	// so that we can go backwards through the levels.
	map = room_to_load & 1; // even or odd?
	if (!map)
	{
		memcpy(c_map, stage1_levels_list[offset], 240);
		memcpy(c_map2, stage1_levels_list[offset - 1], 240);
	}
	else
	{
		memcpy(c_map2, stage1_levels_list[offset], 240);
		memcpy(c_map, stage1_levels_list[offset - 1], 240);
	}

	// init the max_room and max_scroll
	max_rooms = level_max_rooms[level] - 1;
	max_scroll = (max_rooms * 0x100) - 1; // 11 rooms makes 0x0AFF as the max

	sprite_obj_init();
	entity_obj_init();
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();

	draw_player_sprites();

	// draw projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		if (projectiles_list[temp1] != TURN_OFF)
		{
			temp6 = projectiles_y[temp1]; //+ sine_wave[frame_counter % 10];
			oam_meta_spr(projectiles_x[temp1], temp6, animate_orb0_data);
		}
	}

	// draw enemy sprites
	offset = get_frame_count() & 3;
	offset = offset << 4; // * 16, the size of the shuffle array
	for (index = 0; index < MAX_ENEMY; ++index)
	{
		index2 = shuffle_array[offset];
		++offset;
		temp_y = enemy_y[index2];
		if (enemy_health[index2] == 0)
			continue;
		if (temp_y == TURN_OFF)
			continue;
		if (!enemy_active[index2])
			continue;
		temp_x = enemy_x[index2];
		if (temp_x == 0)
			temp_x = 1; // problems with x = 0
		if (temp_x > 0xf0)
			continue;
		if (temp_y < 0xf0)
		{
			oam_meta_spr(temp_x, temp_y, enemy_anim[index2]);
			// draw bear life bar
			if (enemy_type[index2] == ENEMY_BEAR)
			{
				temp = enemy_health[index2];
				draw_health_meter();
				oam_meta_spr(0x28, 0x16, tempint2);
			}
		}
	}

	offset = get_frame_count() & 3;
	offset = offset << 4; // * 16, the size of the shuffle array

	// debug, eventually remove this TODO
	for (index = 0; index < MAX_ENTITY; ++index)
	{
		index2 = shuffle_array[offset];
		++offset;
		temp_y = entity_y[index2];
		if (temp_y == TURN_OFF)
			continue;
		if (!entity_active[index2])
			continue;
		temp_x = entity_x[index2];
		if (temp_x == 0)
			temp_x = 1; // problems with x = 0
		if (temp_x > 0xf0)
			continue;
		if (temp_y < 0xf0)
		{
			++entity_frames[index2];
			if (entity_type[index2] == ENTITY_STARBURST)
			{
				if (entity_frames[index2] < 20)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst1_data);
				}
				else if (entity_frames[index2] < 40)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst2_data);
				}
				else if (entity_frames[index2] < 60)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst3_data);
				}
				else if (entity_frames[index2] < 80)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst2_data);
				}
				else
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst1_data);
					entity_frames[index2] = 0;
				}
			}
			if (entity_type[index2] == ENTITY_WINE)
			{
				oam_meta_spr(temp_x, temp_y, animate_wine_data);
			}
			if (entity_type[index2] == ENTITY_BREAD)
			{
				if (entity_frames[index2] < 20)
					oam_meta_spr(temp_x, temp_y, animate_bread_data);
				else if (entity_frames[index2] < 40)
					oam_meta_spr(temp_x, temp_y, animate_bread2_data);
				else
				{
					oam_meta_spr(temp_x, temp_y, animate_bread_data);
					entity_frames[index2] = 0;
				}
			}
			if (entity_type[index2] == ENTITY_FRUIT)
			{
				if (entity_frames[index2] < 20)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst1_data);
				}
				else if (entity_frames[index2] < 40)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst2_data);
				}
				else if (entity_frames[index2] < 60)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst3_data);
				}
				else if (entity_frames[index2] < 80)
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst2_data);
				}
				else
				{
					oam_meta_spr(temp_x, temp_y, animate_starburst1_data);
					entity_frames[index2] = 0;
				}
			}
			if (entity_type[index2] == ENTITY_BUN)
			{
				if (entity_frames[index2] < 20)
					oam_meta_spr(temp_x, temp_y, animate_bun_data);
				else if (entity_frames[index2] < 40)
					oam_meta_spr(temp_x, temp_y, animate_bun2_data);
				else
				{
					oam_meta_spr(temp_x, temp_y, animate_bun_data);
					entity_frames[index2] = 0;
				}
			}
		}
	}

	// if (debug)
	// {
	// 	// SCROLL_X SPRITES
	// 	// oam_spr(20, 010, 0x58, 1); // 0xfe = X
	// 	temp1 = (scroll_x) >> 8;
	// 	oam_spr(28, 10, temp1 + 0x30, 2);
	// 	temp1 = (scroll_x & 0xff) >> 4;
	// 	oam_spr(36, 10, temp1 + 0x30, 2);
	// 	temp1 = (scroll_x & 0x0f);
	// 	oam_spr(44, 10, temp1 + 0x30, 2);

	// 	// CURRENT ROOM # SPRITE

	// 	tempint = scroll_x + high_byte(BoxGuy1.x);
	// 	temp1 = (tempint >> 8);

	// 	// temp1 = (scroll_x) >> 8; // high byte of scroll_x
	// 	// oam_spr(58, 010, 0x52, 1); // 0xfd = R
	// 	oam_spr(90, 10, temp1 + 0x30, 1);
	// 	temp1 = room_to_load;
	// 	oam_spr(100, 10, temp1 + 0x30, 3);

	// 	// PLAYER X LOCATION SPRITES
	// 	// oam_spr(66, 10, 0x58, 2); // 0xfe = X
	// 	temp1 = (BoxGuy1.x >> 8 & 0xff) >> 4;
	// 	oam_spr(66, 10, temp1 + 0x30, 2);
	// 	temp1 = (BoxGuy1.x >> 8 & 0x0f);
	// 	oam_spr(74, 10, temp1 + 0x30, 2);

	// 	oam_spr(120, 10, nametable_to_load + 0x30, 3);

	// 	// // PLAYER Y LOCATION SPRITES
	// 	// oam_spr(50, 20, 0xff, 2); // 0xff = Y
	// 	// oam_spr(58, 20, temp_cmap1 + 0x30, 2);
	// 	// oam_spr(80, 20, temp_cmap2 + 0x30, 2);
	// }
}

void movement(void)
{

	if (death_flag > 0)
	{
		// this is so we don't have a weird situation
		// where the player triggers the death flag
		// but doesn't cross the border til later
		--death_flag;
	}

	if (invul_frames > 0)
	{
		--invul_frames;
	}
	if (player_in_hitstun)
	{
		--player_in_hitstun;
	}

	if (player_in_hitstun > 0)
	{
		if (hit_direction == RIGHT)
		{
			BoxGuy1.vel_x += HITSTUN_DECEL;
			if (BoxGuy1.vel_x >= MAX_SPEED)
				BoxGuy1.vel_x = MAX_SPEED;
		}
		else
		{
			BoxGuy1.vel_x -= HITSTUN_DECEL;
			if (BoxGuy1.vel_x < -MAX_SPEED)
				BoxGuy1.vel_x = -MAX_SPEED;
		}
	}

	// handle x

	old_x = BoxGuy1.x;

	if (pad1 & PAD_LEFT && !player_in_hitstun  && !player_is_sliding)
	{
		direction = LEFT;
		player_is_running = 1;

		if (!player_on_ladder)
		{
			if (BoxGuy1.vel_x >= DECEL)
			{
				BoxGuy1.vel_x -= DECEL;
			}
			else if (BoxGuy1.vel_x > 0)
			{
				BoxGuy1.vel_x = 0;
			}
			else
			{
				BoxGuy1.vel_x -= ACCEL;
				if (BoxGuy1.vel_x < -MAX_SPEED)
					BoxGuy1.vel_x = -MAX_SPEED;
			}
		}
	}
	else if (pad1 & PAD_RIGHT && !player_in_hitstun && !player_is_sliding)
	{

		direction = RIGHT;
		player_is_running = 1;

		if (!player_on_ladder)
		{

			if (BoxGuy1.vel_x <= DECEL)
			{
				BoxGuy1.vel_x += DECEL;
			}
			else if (BoxGuy1.vel_x < 0)
			{
				BoxGuy1.vel_x = 0;
			}
			else
			{
				BoxGuy1.vel_x += ACCEL;
				if (BoxGuy1.vel_x >= MAX_SPEED)
					BoxGuy1.vel_x = MAX_SPEED;
			}
		}
	}
	else
	{ // nothing pressed
		player_is_running = 0;
		if (BoxGuy1.vel_x >= ACCEL)
			BoxGuy1.vel_x -= ACCEL;
		else if (BoxGuy1.vel_x < -ACCEL)
			BoxGuy1.vel_x += ACCEL;
		else
			BoxGuy1.vel_x = 0;
	}

	if(player_is_sliding > 0){
		--player_is_sliding;

		if(direction == LEFT){
				BoxGuy1.vel_x = -MAX_SLIDE_SPEED;
		} else {
			BoxGuy1.vel_x = MAX_SLIDE_SPEED;
		}
	}

	BoxGuy1.x += BoxGuy1.vel_x;

	if (BoxGuy1.x > 0xf000)
	{ // too far, don't wrap around

		if (old_x >= 0x8000)
		{
			BoxGuy1.x = 0xf000; // max right
		}
		else
		{
			BoxGuy1.x = 0x0000; // max left
		}

		BoxGuy1.vel_x = 0;
	}

#pragma region Collision
	Generic.x = high_byte(BoxGuy1.x); // this is much faster than passing a pointer to BoxGuy1
	Generic.y = high_byte(BoxGuy1.y);
	Generic.width = HERO_WIDTH;
	Generic.height = HERO_HEIGHT;

	if (BoxGuy1.vel_x < 0)
	{
		if (bg_coll_L())
		{ // check collision left
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_L;
			BoxGuy1.vel_x = 0;
			if (BoxGuy1.x > 0xf000)
			{
				// no wrap around
				BoxGuy1.x = 0xf000;
			}
		}
	}
	else if (BoxGuy1.vel_x > 0)
	{
		if (bg_coll_R())
		{ // check collision right
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_R;
			BoxGuy1.vel_x = 0;
			if (BoxGuy1.x > 0xf000)
			{
				// no wrap around
				BoxGuy1.x = 0x0000;
			}
		}
	}

	// skip collision if vel = 0

	// handle y

	// gravity

	// BoxGuy1.vel_y is signed

	if (player_on_ladder && (bg_coll_ladder() || bg_coll_ladder_top_under_player()))
	{
		if (pad1 & PAD_DOWN)
		{
			direction_y = DOWN;
			++player_on_ladder_pose;
			BoxGuy1.vel_y += LADDER_ACCEL;
			if (BoxGuy1.vel_y > MAX_LADDER_SPEED)
			{
				BoxGuy1.vel_y = MAX_LADDER_SPEED;
			}
			player_on_ladder_top = 0;
		}
		else if (pad1 & PAD_UP)
		{
			direction_y = UP;
			++player_on_ladder_pose;
			BoxGuy1.vel_y -= LADDER_ACCEL;
			if (BoxGuy1.vel_y < -MAX_LADDER_SPEED)
			{
				BoxGuy1.vel_y = -MAX_LADDER_SPEED;
			}
			// if you're on the top of ladder, zip to the top top;
			if (bg_coll_ladder_top_under_player())
			{
				++player_on_ladder_top;

				if (player_on_ladder_top > 10)
				{
					// if he's going fast, just bump him 2px up
					if (BoxGuy1.vel_y = -MAX_LADDER_SPEED)
					{
						BoxGuy1.y -= 0x200;
					}
					else
					{ // otherwise, bump him up 8px
						BoxGuy1.y -= 0x800;
					}

					player_on_ladder_top = 0;
					player_on_ladder = 0;
				}
			}
		}
		else
		{
			BoxGuy1.vel_y = 0;
		}
	}
	else
	{
		if (player_on_ladder && bg_coll_ladder_top_under_player())
		{
			// how does a player get off ladders. before they just moved fast enough
			player_on_ladder = 0;
		}
		if (BoxGuy1.vel_y < 0x300)
		{
			BoxGuy1.vel_y += GRAVITY;
		}
		else
		{
			BoxGuy1.vel_y = 0x300; // consistent
		}
	}

	if (pad1 & PAD_DOWN)
	{
		direction_y = DOWN;
		if (bg_coll_ladder_top_under_player())
		{
			BoxGuy1.x = (BoxGuy1.x + 0x700) & ~0xF00; // tried to square the player to the ladder
			player_on_ladder = 1;
			player_on_ladder_pose = 0;
			player_in_air = 0;
			falling_down = 0;
			BoxGuy1.vel_y = 0;
			BoxGuy1.vel_x = 0;
			BoxGuy1.y += 0x100;
		}
	}

	BoxGuy1.y += BoxGuy1.vel_y; // add gravity to y; (make him go up or down)
	if (BoxGuy1.y > 0xf000)			// limit how high he can go
	{
		BoxGuy1.y = 0x0000;
	}

	Generic.x = high_byte(BoxGuy1.x);
	Generic.y = high_byte(BoxGuy1.y);

	// if(!player_on_ladder && BoxGuy1.vel_y > 0){
	// 	player_in_air = 1;
	// }
	if (BoxGuy1.vel_y > 0) // he's falling
	{
		++falling_down;

		if (falling_down > 2 && !player_on_ladder)
		{ // been falling for 2 frames
			player_in_air = 1;
		}

		if (bg_coll_D()) // if he's collising below
		{								 // check collision below
			player_in_air = 0;
			falling_down = 0;
			multi_jump = 0;
			player_on_ladder = 0;

			high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_D;
			BoxGuy1.y &= 0xff00;
			if (BoxGuy1.vel_y > 0)
			{
				BoxGuy1.vel_y = 0;
			}
		}
	}
	else if (BoxGuy1.vel_y < 0)
	{
		if (bg_coll_U())
		{ // check collision above
			high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_U;
			BoxGuy1.vel_y = 0;
		}
	}

	// check collision down a little lower than hero
	Generic.y = high_byte(BoxGuy1.y); // the rest should be the same

	if (projectile_cooldown > 0)
	{
		--projectile_cooldown;
	}
	

	if (pad1_new & PAD_UP || pad1_state & PAD_UP) // on trigger or hold
	{
		direction_y = UP;
		if (!player_on_ladder && bg_coll_ladder())
		{
			// needs to snap player to grid, to nearest 16 pixels
			BoxGuy1.x = (BoxGuy1.x + 0x700) & ~0xF00;
			player_on_ladder_pose = 0;
			player_on_ladder = 1;
			player_in_air = 0;
			falling_down = 0;
			BoxGuy1.vel_y = 0;
			BoxGuy1.vel_x = 0;
		}
	}  

	if(pad1_state & PAD_DOWN && pad1_new & PAD_A){
		player_is_sliding = 25;
	} else if (pad1_new & PAD_A)
	{
		if (player_on_ladder)
		{
			player_on_ladder = 0;
			player_in_air = 1;
		}
		else if (bg_coll_D2() || multi_jump < 2)
		{
			++multi_jump;
			BoxGuy1.vel_y = JUMP_VEL; // JUMP
			sfx_play(SFX_JUMP, 0);
			short_jump_count = 1;
			player_in_air = 1;
		}
	}
	if (pad1_new & PAD_B && projectile_cooldown == 0 && !player_in_hitstun && !player_is_sliding) // shooting
	{

		// check if there's an empty shot spot
		for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
		{
			if (projectiles_list[temp1] == TURN_OFF)
			{
				temp2 = 1;
				break;
			}
		}
		if (temp2)
		{
			projectile_cooldown = PROJECTILE_COOLDOWN_FRAMES;
			player_shooting = 10;
			projectile_index = temp1;

			// if player is facing right:
			if (direction == RIGHT)
			{
				projectiles_list[projectile_index] = RIGHT;
			}
			else
			{
				projectiles_list[projectile_index] = LEFT;
			}

			projectiles_x[projectile_index] = high_byte(BoxGuy1.x) + 10;
			projectiles_y[projectile_index] = high_byte(BoxGuy1.y);
			sfx_play(SFX_SHOOT, 0);
		}
	}

#pragma endregion

	// allow shorter jumps
	if (short_jump_count)
	{
		++short_jump_count;
		if (short_jump_count > 30)
			short_jump_count = 0;
	}
	if ((short_jump_count) && ((pad1 & PAD_A) == 0) && (BoxGuy1.vel_y < -0x200))
	{
		BoxGuy1.vel_y = -0x200;
		short_jump_count = 0;
	}

	// scroll
	// when the player is in the middle of the screen, reset the map loaded
	temp5 = low_byte(scroll_x) + high_byte(BoxGuy1.x);
	if (temp5 > 0x98 && temp5 < 0xa4) // middle of the screen
	{
		map_loaded = 0;
	}

	temp5 = BoxGuy1.x; // store his x before we check the scrolling

	if (BoxGuy1.x < MAX_LEFT)
	{

		if (!map_loaded)
		{
			room_to_load = ((scroll_x >> 8) - 1); // high byte = room, one to the left
			new_cmap();
			map_loaded = 1; // only do once
		}

		temp1 = (MAX_LEFT - BoxGuy1.x) >> 8;
		if (temp1 > 3)
			temp1 = 3; // max scroll change

		tempint = scroll_x + high_byte(BoxGuy1.x);
		current_room = (tempint >> 8);

		if (max_rooms >= 1) // this is for the multi-room levels
		{
			if ((scroll_x - temp1) > max_scroll) // if subtracting the scroll makes it overflow
			{
				scroll_x = 0; // just go to zero (and move the guy)
			}
			else // otherwise scroll the window and offset the guy's movement
			{
				scroll_x -= temp1;																	 // scroll the window
				high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) + temp1; // add the offset to the guy
			}
		}
	}

	if (BoxGuy1.x > MAX_RIGHT)
	{
		if (!map_loaded) // gets reset whenever the player's in the middle of the level
		{
			room_to_load = ((scroll_x >> 8) + 1); // high byte = room, one to the left

			new_cmap();
			map_loaded = 1; // only do once
		}
		temp1 = (BoxGuy1.x - MAX_RIGHT) >> 8;
		if (temp1 > 3)
			temp1 = 3; // max scroll change

		if (max_rooms >= 1) // used for single room levels
		{
			scroll_x += temp1;																	 // scroll the window
			high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - temp1; // sub the offet from the guy
		}
	}

	if (scroll_x >= max_scroll)
	{
		scroll_x = max_scroll;						// stop scrolling right, end of level
		BoxGuy1.x = temp5;								// but allow the x position to go all the way right
		if (high_byte(BoxGuy1.x) >= 0xe0) // but limit how far right he can go
		{
			BoxGuy1.x = 0xe000;
		}
	}
}

void draw_screen_L(void)
{
	// scrolling to the left, draw metatiles as we go
	pseudo_scroll_x = scroll_x - 0x20; // Modify the scroll offset for left scroll

	temp1 = pseudo_scroll_x >> 8;
	// if (temp1 > 0)
	// {
	// 	temp1 = temp1 - 1;
	// }

	offset = level_offsets[level];
	offset += temp1; // in place of room?!?

	set_data_pointer(stage1_levels_list[offset]);
	nt = temp1 & 1;
	x = pseudo_scroll_x & 0xff;

	switch (scroll_count)
	{
	case 0:
		address = get_ppu_addr(nt, x, 0);
		index = 0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x20);
		index = 0x20 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 1:
		address = get_ppu_addr(nt, x, 0x40);
		index = 0x40 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x60);
		index = 0x60 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 2:
		address = get_ppu_addr(nt, x, 0x80);
		index = 0x80 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xa0);
		index = 0xa0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	default:
		address = get_ppu_addr(nt, x, 0xc0);
		index = 0xc0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xe0);
		index = 0xe0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
	}

	--scroll_count;		 // Reverse the increment to scroll in the opposite direction
	scroll_count &= 3; // mask off top bits, keep it 0-3
}

void draw_screen_R(void)
{
	// scrolling to the right, draw metatiles as we go
	pseudo_scroll_x = scroll_x + 0x120;

	temp1 = pseudo_scroll_x >> 8;

	offset = level_offsets[level];
	offset += temp1; // in place of room?!?

	set_data_pointer(stage1_levels_list[offset]);
	nt = temp1 & 1;
	x = pseudo_scroll_x & 0xff;

	switch (scroll_count)
	{
	case 0:
		address = get_ppu_addr(nt, x, 0);
		index = 0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x20);
		index = 0x20 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 1:
		address = get_ppu_addr(nt, x, 0x40);
		index = 0x40 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0x60);
		index = 0x60 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	case 2:
		address = get_ppu_addr(nt, x, 0x80);
		index = 0x80 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xa0);
		index = 0xa0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
		break;

	default:
		address = get_ppu_addr(nt, x, 0xc0);
		index = 0xc0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data

		address = get_ppu_addr(nt, x, 0xe0);
		index = 0xe0 + (x >> 4);
		buffer_4_mt(address, index); // ppu_address, index to the data
	}

	++scroll_count;
	scroll_count &= 3; // mask off top bits, keep it 0-3
}

// copy a new collision map to one of the 2 c_map arrays
void new_cmap(void)
{

	offset = level_offsets[level];
	offset += room_to_load;

	map = room_to_load & 1; // even or odd?
	if (!map)
	{
		memcpy(c_map, stage1_levels_list[offset], 240);
	}
	else
	{
		memcpy(c_map2, stage1_levels_list[offset], 240);
	}
}

char get_position(void)
{
	// is it in range ? return 1 if yes

	temp5 -= scroll_x;
	temp_x = temp5 & 0xff;
	if (high_byte(temp5))
		return 0;
	return 1;
}

void check_entity_objects(void)
{

	Generic2.x = high_byte(BoxGuy1.x);
	// mark each object "active" if they are, and get the screen x

	for (index = 0; index < MAX_ENTITY; ++index)
	{
		entity_active[index] = 0; // default to zero
		if (entity_y[index] != TURN_OFF)
		{
			high_byte(temp5) = entity_room[index];
			low_byte(temp5) = entity_actual_x[index];
			temp1 = entity_active[index] = get_position();
			if (temp1 == 0)
				continue;
			entity_x[index] = temp_x; // screen x coords

			entity_moves();
		}
	}
}

void entity_moves(void)
{
	// some entities drop til they're coliding with the ground.
	if (entity_type[index] == ENTITY_BUN || entity_type[index] == ENTITY_STARBURST || entity_type[index] == ENTITY_FRUIT)
	{
		// check for collision
		Generic.x = entity_x[index];
		Generic.y = entity_y[index] - 6; // mid point
		Generic.width = 16;
		Generic.height = 1;

		bg_collision_fast();
		if (!collision_D)
		{
			++entity_y[index];
			if (entity_y[index] != TURN_OFF && !entity_type[index] == ENTITY_STARBURST || !entity_type[index] == ENTITY_FRUIT)
			{ // fruit moves slowly
				++entity_y[index];
			}
		}
	}
}

void check_spr_objects(void)
{
	Generic2.x = high_byte(BoxGuy1.x);
	// mark each object "active" if they are, and get the screen x

	for (index = 0; index < MAX_ENEMY; ++index)
	{
		enemy_active[index] = 0; // default to zero
		if (enemy_y[index] != TURN_OFF)
		{
			high_byte(temp5) = enemy_room[index];
			low_byte(temp5) = enemy_actual_x[index];
			temp1 = enemy_active[index] = get_position();
			if (temp1 == 0 || enemy_health[index] == 0)
				continue;
			enemy_x[index] = temp_x; // screen x coords

			enemy_moves(); // if active, do it's moves now
		}
	}
}

void entity_obj_init(void)
{
	pointer = entity_list[level];

	for (index = 0; index < MAX_ENTITY; ++index)
	{
		entity_y[index] = TURN_OFF; // turn off all objects
	}

	for (index = 0, index2 = 0; index < MAX_ENTITY; ++index)
	{

		entity_x[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		entity_y[index] = temp1;

		if (temp1 == TURN_OFF)
			break;

		++index2;

		entity_active[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		entity_room[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		entity_actual_x[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		entity_type[index] = temp1;

		++index2;
	}
}

void enemy_moves(void)
{
	enemy_frames[index] += 1;

	// check enemy collision with projectiles
	for (temp1 = 0; temp1 < MAX_PROJECTILES; ++temp1)
	{
		if (projectiles_list[temp1] != TURN_OFF)
		{
			if (
					(enemy_x[index] > projectiles_x[temp1] - 5 && enemy_x[index] < projectiles_x[temp1] + 5) &&
					(enemy_y[index] > projectiles_y[temp1] - 30 && enemy_y[index] < projectiles_y[temp1] + 30))
			{
				projectiles_list[temp1] = TURN_OFF;
				--enemy_health[index];
				sfx_play(SFX_SHOT_HITS, 0);
				if (enemy_health[index] == 0 || enemy_health[index] > 240) // check for overflow with 240
				{
					if (enemy_type[index] == ENEMY_BEAR)
					{
						// place an item there.
						entity_y[0] = 80;
						entity_x[0] = 120;
						entity_room[0] = enemy_room[index];
						entity_active[0] = 1;
						entity_type[0] = ENTITY_FRUIT;
						entity_actual_x[0] = 128;
					}
					// randomly decide to place something
					else if (frame_counter % 2 == 0)
					{
						// find an empty entity slot
						for (index2 = 0; index2 <= MAX_ENTITY; ++index2)
						{
							if (entity_y[index2] == TURN_OFF)
							{
								break;
							}
						}
						// place an item there.
						entity_y[index2] = enemy_y[index];
						entity_x[index2] = enemy_x[index];
						entity_room[index2] = enemy_room[index];
						entity_active[index2] = 1;
						entity_type[index2] = ENTITY_BUN;
						entity_actual_x[index2] = enemy_actual_x[index];
					}

					// delete the enemy
					enemy_y[index] = TURN_OFF;
					enemy_active[index] = 0;
				}
			}
		}
	}

	if (enemy_type[index] == ENEMY_SNAIL)
	{
		enemy_snail_behavior();
	}
	if (enemy_type[index] == ENEMY_OWL)
	{
		enemy_owl_behavior();
	}
	if (enemy_type[index] == ENEMY_BEAR)
	{
		enemy_bear_behavior();
	}
}

enum
{
	BEAR_WALK,
	BEAR_PREP_RUN,
	BEAR_RUN,
	BEAR_PREP_ATTACK,
	BEAR_ATTACK
};

void enemy_bear_behavior(void)
{
	Generic.x = enemy_x[index];
	Generic.y = enemy_y[index] + 6; // mid point
	Generic.width = ENEMY_BEAR_WIDTH;
	Generic.height = ENEMY_BEAR_HEIGHT;

	// determine bear mode

	// if he's in walk mode he can change
	// otherwise he completes his mode.
	if (enemy_mode[index] == BEAR_WALK)
	{
		// if the player is far away, the bear will run

		// his mode can change when he's walking.
		// if (enemy_frames[index] == 200)
		// {
		// 	// after 200 frames, the bear will rain down rocks
		// 	enemy_mode[index] = BEAR_PREP_RUN;
		// 	enemy_frames[index] = 0;
		// }

		// if player is far away, bear will run
		if ((enemy_actual_x[index] >= Generic2.x && ((enemy_actual_x[index] - Generic2.x) > 120)) ||
				(enemy_actual_x[index] < Generic2.x && ((Generic2.x - enemy_actual_x[index]) > 120)))
		{
			enemy_mode[index] = BEAR_PREP_RUN;
		}
	}

	if (enemy_mode[index] == BEAR_PREP_RUN)
	{
		if (enemy_frames[index] > 50)
		{
			enemy_mode[index] = BEAR_RUN;
			enemy_frames[index] = 0;
		}
	}

	if (enemy_mode[index] == BEAR_RUN)
	{
		if (enemy_frames[index] > 100)
		{
			enemy_mode[index] = BEAR_WALK;
			enemy_frames[index] = 0;
		}
	}

	switch (enemy_mode[index])
	{
		case BEAR_WALK:
		#pragma region bear_walk
		if (enemy_frames[index] < 10)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk1eft_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalkright_data;
			}
		}
		else if (enemy_frames[index] < 20)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk2left_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalk2right_data;
			}
		}
		else if (enemy_frames[index] < 30)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk3left_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalk3right_data;
			}
		}
		else if (enemy_frames[index] < 40)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk2left_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalk2right_data;
			}
		}
		else
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk1eft_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalkright_data;
			}
			enemy_frames[index] = 0;
		}
		#pragma endregion
		break;
		case BEAR_PREP_RUN:
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_beararms_data;
			}
			else
			{
				enemy_anim[index] = animate_beararmsright_data;
			}
		break;
		case BEAR_RUN:
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_bearwalk1eft_data;
			}
			else
			{
				enemy_anim[index] = animate_bearwalkright_data;
			}
		break;
		default: 
		break;
	}


	//actual movement
	switch(enemy_mode[index]){
		case BEAR_WALK:
			if (enemy_frames[index] % 3 == 0)
			{

				// note, Generic2 is the hero's x position
				if (enemy_x[index] > Generic2.x)
				{
					Generic.x -= 1; // test going left
				}
				else if (enemy_x[index] < Generic2.x)
				{
					Generic.x += 1; // test going right
				}
			}
		break;
		case BEAR_PREP_RUN:
			//bear stands still
			break;
		case BEAR_RUN:
			// note, Generic2 is the hero's x position
			if (enemy_x[index] > Generic2.x)
			{
				Generic.x -= 1; // test going left
			}
			else if (enemy_x[index] < Generic2.x)
			{
				Generic.x += 1; // test going right
			}
		default: 
		break;
	}
}

void enemy_snail_behavior(void)
{
	// for bg collisions
	Generic.x = enemy_x[index];
	Generic.y = enemy_y[index] + 6; // mid point
	Generic.width = ENEMY_SNAIL_WIDTH;
	Generic.height = ENEMY_SNAIL_HEIGHT;

	// set animation:
	if (enemy_frames[index] < 10)
	{
		if (enemy_dir[index] == LEFT)
		{
			enemy_anim[index] = animate_snail1left_data;
		}
		else
		{
			enemy_anim[index] = animate_snail1right_data;
		}
	}
	else if (enemy_frames[index] < 20)
	{
		if (enemy_dir[index] == LEFT)
		{
			enemy_anim[index] = animate_snail2left_data;
		}
		else
		{
			enemy_anim[index] = animate_snail2right_data;
		}
	}
	else if (enemy_frames[index] < 30)
	{
		if (enemy_dir[index] == LEFT)
		{
			enemy_anim[index] = animate_snail3left_data;
		}
		else
		{
			enemy_anim[index] = animate_snail3right_data;
		}
	}
	else
	{
		if (enemy_dir[index] == LEFT)
		{
			enemy_anim[index] = animate_snail3left_data;
		}
		else
		{
			enemy_anim[index] = animate_snail3right_data;
		}
		enemy_frames[index] = 0;
	}

	// actual movement
	if (enemy_frames[index] % 3 == 0)
	{

		// note, Generic2 is the hero's x position
		if (enemy_mode[index] == 0)
		{
			Generic.x -= 1; // test going left
			bg_collision_fast();
			if (collision_L)
			{
				enemy_mode[index] = 1;
				return;
			}
			if (collision_D) // needs ground under it
			{

				if (enemy_actual_x[index] == 0)
				{
					--enemy_room[index];
				}
				--enemy_actual_x[index];
				enemy_dir[index] = LEFT;
			}
			else
			{
				enemy_mode[index] = 1;
			}
		}
		else if (enemy_mode[index] == 1)
		{

			Generic.x += 1; // test going right

			bg_collision_fast();
			if (collision_R)
			{
				enemy_mode[index] = 0;
				return;
			}
			if (collision_D)
			{
				++enemy_actual_x[index];
				if (enemy_actual_x[index] == 0)
				{
					++enemy_room[index];
				}

				enemy_dir[index] = RIGHT;
			}
			else
			{
				enemy_mode[index] = 0;
			}
		}
	}
}

void enemy_owl_behavior(void)
{
	// no collision for owl, he just swoops down and out.
	// mode 0 is idle, mode 1 is attacking

	if (enemy_x[index] > Generic2.x					 // enemy right of player
			&& enemy_x[index] - Generic2.x < 50) // and close
	{
		enemy_mode[index] = 1;
	}
	if (enemy_x[index] < Generic2.x					 // enemy left of player
			&& Generic2.x - enemy_x[index] < 50) // and close
	{
		enemy_mode[index] = 1;
	}

	// animation
	if (enemy_mode[index] == 0)
	{
		if (enemy_dir[index] == LEFT)
		{
			enemy_anim[index] = animate_hootyowl5left_data;
		}
		else
		{
			enemy_anim[index] = animate_hootyowl5right_data;
		}
	}
	else
	{
		if (enemy_frames[index] < 4)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl1left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl1right_data;
			}
		}
		else if (enemy_frames[index] < 8)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl2left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl2right_data;
			}
		}
		else if (enemy_frames[index] < 12)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl3left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl3right_data;
			}
		}
		else if (enemy_frames[index] < 16)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl4left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl4right_data;
			}
		}
		else if (enemy_frames[index] < 20)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl3left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl3right_data;
			}
		}
		else if (enemy_frames[index] < 24)
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl2left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl2right_data;
			}
		}
		else
		{
			if (enemy_dir[index] == LEFT)
			{
				enemy_anim[index] = animate_hootyowl1left_data;
			}
			else
			{
				enemy_anim[index] = animate_hootyowl1right_data;
			}
			enemy_frames[index] = 0;
		}
	}

	// enemy movement
	if (enemy_mode[index] == 1) // he moves every 3 frames after activated
	{
		++enemy_y[index];
		if (enemy_x[index] > Generic2.x) // enemy is right of player
		{
			if (enemy_actual_x[index] == 0)
			{
				--enemy_room[index]; // I think there's a bug here
			}
			--enemy_actual_x[index];
			enemy_dir[index] = LEFT;
		}
		else if (enemy_x[index] < Generic2.x) // enemy is left of player
		{

			++enemy_actual_x[index];
			if (enemy_actual_x[index] == 0)
			{
				++enemy_room[index]; // I think there's a bug here
			}
			enemy_dir[index] = RIGHT;
		}

		// if you're at the same Y as the player, then fly upwards and away
	}
}

// cc65 is very slow if 2 arrays/pointers are on the same line, so I
// broke them into 2 separate lines with temp1 as a passing variable
void sprite_obj_init(void)
{

	pointer = Enemy_list[level];
	for (index = 0, index2 = 0; index < MAX_ENEMY; ++index)
	{

		enemy_x[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		enemy_y[index] = temp1;

		if (temp1 == TURN_OFF)
			break;

		++index2;

		enemy_active[index] = 0;

		temp1 = pointer[index2]; // get a byte of data
		enemy_room[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		enemy_actual_x[index] = temp1;

		++index2;

		temp1 = pointer[index2]; // get a byte of data
		enemy_type[index] = temp1;
		if (enemy_type[index] == ENEMY_SNAIL)
		{
			enemy_health[index] = ENEMY_SNAIL_HEALTH; // set enemy health here
		}
		if (enemy_type[index] == ENEMY_OWL)
		{
			enemy_health[index] = ENEMY_OWL_HEALTH; // set enemy health here
		}
		if (enemy_type[index] == ENEMY_BEAR)
		{
			enemy_health[index] = ENEMY_BEAR_HEALTH; // set enemy health here
		}

		++index2;
	}

	for (++index; index < MAX_ENEMY; ++index)
	{
		enemy_y[index] = TURN_OFF;
		enemy_mode[index] = 0;
	}
}

void entity_collisions(void)
{

	Generic.x = high_byte(BoxGuy1.x);
	Generic.y = high_byte(BoxGuy1.y);
	Generic.width = HERO_WIDTH;
	Generic.height = HERO_HEIGHT;

	for (index = 0; index < MAX_ENTITY; ++index)
	{
		if (entity_active[index])
		{
			switch (entity_type[index])
			{
			case ENTITY_PIT_WIDE_64:
				Generic2.width = 64;
				Generic2.height = 8;
				break;
			case ENTITY_SPIKE_WIDE_64:
				Generic2.width = 64;
				Generic2.height = 8;
				break;
			case ENTITY_LEVEL_DOWN_WIDE_256:
				Generic2.width = 255;
				Generic2.height = 8;
				break;
			case ENTITY_LEVEL_UP_WIDE_256:
				Generic2.width = 255;
				Generic2.height = 8;
				break;
			default:
				Generic2.width = 16;
				Generic2.height = 16;
				break;
			}

			Generic2.x = entity_x[index];
			Generic2.y = entity_y[index];
			// if (entity_type[index] == ENTITY_PIT_WIDE_64) // for full lenght check?
			// {
			// 	// don't bother running collision for pits, just check Y
			// 	if (Generic.y >= Generic2.y)
			// 	{
			// 		death_flag = 30; // 30 frames the player can die in
			// 	}
			// }
			// else if (entity_type[index] == ENTITY_LEVEL_UP_FULL)
			// {
			// 	if (Generic.y >= Generic2.y)
			// 	{
			// 		++level_up;
			// 	}
			// }
			// else if (entity_type[index] == ENTITY_LEVEL_DOWN_FULL)
			// {
			// 	if (Generic.y >= Generic2.y)
			// 	{
			// 		++level_down;
			// 	}
			// }
			// TODO: do I even need formal collision checking?
			if (check_collision(&Generic, &Generic2))
			{
				switch (entity_type[index])
				{
				case ENTITY_PIT_WIDE_64:
					death_flag = 30; // 30 frames the player can die in
					break;
				case ENTITY_LEVEL_UP_WIDE_256:
					++level_up;
					break;
				case ENTITY_LEVEL_DOWN_WIDE_256:
					++level_down;
					break;
				case ENTITY_LEVEL_UP:
					++level_up;
					break;
				case ENTITY_LEVEL_DOWN:
					++level_down;
					break;
				case ENTITY_SPIKE_WIDE_64:
					++death;
					break;
				case ENTITY_FRUIT:
					load_victory();
					break;
				case ENTITY_BUN:
					if (BoxGuy1.health < MAX_PLAYER_HEALTH)
					{
						BoxGuy1.health += 1;
						sfx_play(SFX_LIFE_UP, 0);
					}
					entity_active[index] = 0;
					entity_y[index] = TURN_OFF;
					break;
				case ENTITY_BREAD:
					BoxGuy1.health = MAX_PLAYER_HEALTH;
					sfx_play(SFX_LIFE_UP, 0);
					entity_active[index] = 0;
					entity_y[index] = TURN_OFF;
					break;
				case ENTITY_STARBURST:
					pal_fade_to(4, 0);			 // fade to black
					game_mode = MODE_SWITCH; // this handles loading the level
					ppu_off();
					scroll_x = 0;
					++level;
					level_up = 0;
					room_to_load = 0;
					nametable_to_load = 0;
					break;
				default:
					break;
				}
			}
		}
	}
}

void sprite_collisions(void)
{
	Generic.x = high_byte(BoxGuy1.x);
	Generic.y = high_byte(BoxGuy1.y);

	for (index = 0; index < MAX_ENEMY; ++index)
	{
		if (enemy_active[index])
		{
			switch (enemy_type[index])
			{
			case ENEMY_SNAIL:
				Generic2.width = ENEMY_SNAIL_WIDTH;
				Generic2.height = ENEMY_SNAIL_HEIGHT;
				Generic2.x = enemy_x[index] + 4;
				Generic2.y = enemy_y[index];
				break;
			case ENEMY_OWL:
				Generic2.width = ENEMY_OWL_WIDTH;
				Generic2.height = ENEMY_OWL_HEIGHT;
				Generic2.x = enemy_x[index];
				Generic2.y = enemy_y[index];
				break;
			case ENEMY_BEAR:
				Generic2.width = ENEMY_BEAR_WIDTH;
				Generic2.height = ENEMY_BEAR_HEIGHT;
				Generic2.x = enemy_x[index];
				Generic2.y = enemy_y[index];
				break;
			default:
				Generic2.width = ENEMY_WIDTH;
				Generic2.height = ENEMY_HEIGHT;
				Generic2.x = enemy_x[index];
				Generic2.y = enemy_y[index];
			}

			if (check_collision(&Generic, &Generic2))
			{

				switch (enemy_type[index])
				{
				case ENEMY_SNAIL:

					// check for player collision:
					if (invul_frames == 0)
					{
						hit_direction = enemy_dir[index];
						// enemy_health[index] -= 1;  // hit the enemy running into it?
						BoxGuy1.health -= ENEMY_SNAIL_DAMAGE; // check for overflow
						player_on_ladder = 0;									// hitting hits you off ladder
						sfx_play(SFX_ENEMY_HITS, 0);
						player_in_hitstun = ENEMY_SNAIL_PLAYER_HITSTUN;
						invul_frames = ENEMY_SNAIL_PLAYER_INVUL;
					}
					break;
				case ENEMY_OWL:

					// check for player collision:
					if (invul_frames == 0)
					{
						hit_direction = enemy_dir[index];
						// enemy_health[index] -= 1;  // hit the enemy running into it?
						BoxGuy1.health -= ENEMY_OWL_DAMAGE; // check for overflow
						player_on_ladder = 0;								// hitting hits you off ladder
						sfx_play(SFX_ENEMY_HITS, 0);
						player_in_hitstun = ENEMY_OWL_PLAYER_HITSTUN;
						invul_frames = ENEMY_OWL_PLAYER_INVUL;
					}
					break;
				case ENEMY_BEAR:
					if (invul_frames == 0)
					{
						hit_direction = enemy_dir[index];
						// enemy_health[index] -= 1;  // hit the enemy running into it?
						BoxGuy1.health -= ENEMY_BEAR_DAMAGE; // check for overflow
						player_on_ladder = 0;								 // hitting hits you off ladder
						sfx_play(SFX_ENEMY_HITS, 0);
						player_in_hitstun = ENEMY_BEAR_PLAYER_HITSTUN;
						invul_frames = ENEMY_BEAR_PLAYER_INVUL;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}
void init_death(void)
{
	pal_fade_to(4, 0); // fade to black
	ppu_off();
	load_gameover();

	frame_counter = 0;
	scroll_x = 0;
	set_scroll_x(0);
	oam_clear();

	game_mode = MODE_DEATH;
	// multi_vram_buffer_horz("GAME OVER", 10, NTADR_A(11, 6));

	// multi_vram_buffer_horz("PRESS START", 12, NTADR_A(10, 14));

	ppu_on_all();
	music_stop();
	sfx_play(SFX_PLAYER_DIES, 0);
	pal_fade_to(0, 4); // fade to black
}

void level_up_routine()
{
	pal_fade_to(4, 0); // fade to black
	ppu_off();
	game_mode = MODE_SWITCH; // this handles loading the level
	++level;
	level_up = 0;
	max_rooms = level_max_rooms[level] - 1;
	nametable_to_load = 0;
	scroll_x = 0;
	room_to_load = 0;

	if (max_rooms > 1)
	{
		max_scroll = (max_rooms * 0x100) - 1;
	}
	else
	{
		max_scroll = 0;
	}
}

void level_down_routine()
{
	pal_fade_to(4, 0); // fade to black
	ppu_off();
	game_mode = MODE_SWITCH; // this handles loading the level

	--level;
	level_down = 0;
	max_rooms = level_max_rooms[level] - 1;
	nametable_to_load = max_rooms % 2;
	if (max_rooms > 1)
	{
		max_scroll = (max_rooms * 0x100) - 1;
		scroll_x = max_scroll;
		room_to_load = max_rooms;
	}
	else
	{
		max_scroll = 0;
		scroll_x = 0;
		room_to_load = max_rooms;
	}
}

void init_mode_switch()
{
	// switch to vertical scroll,
	// load both name tables
	// the mode moves scrollY up
}