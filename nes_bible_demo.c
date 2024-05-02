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

void main(void)
{
	// test

	reset();

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
				pal_fade_to(4, 0); // fade to black
				ppu_off();
				// load game mode
				game_mode = MODE_GAME;
				// song = SONG_GAME;
				// music_play(song); //no music yet
				ppu_on_all();
				pal_bright(4); // back to normal brightness
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

			if (pad1_new & PAD_START)
			{
				game_mode = MODE_PAUSE;
				// song = SONG_PAUSE;
				// music_play(song);
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

			// player goes up to next level
			if (high_byte(BoxGuy1.y) < 0x08 && level_up && player_on_ladder)
			{
				BoxGuy1.y = 0xD000;			 // put the user above the bottom of the screen.
				pal_fade_to(4, 0);			 // fade to black
				game_mode = MODE_SWITCH; // this handles loading the level
				init_mode_switch();
				scroll_x = 0;
				ppu_off();
				++level;
				level_up = 0;
				room_to_load = 0;
				nametable_to_load = 0;
			}

			// player goes down to next level
			if (high_byte(BoxGuy1.y) > 0xd0 && high_byte(BoxGuy1.y) < 0xd9 && level_up) // todo: might need less than 0xd0
			{
				BoxGuy1.y = 0x1800;			 // put the user near the top of screen
				pal_fade_to(4, 0);			 // fade to black
				game_mode = MODE_SWITCH; // this handles loading the level
				ppu_off();
				scroll_x = 0;
				++level;
				level_up = 0;
				room_to_load = 0;
				nametable_to_load = 0;
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
			// draw_sprites();

			if (pad1_new & PAD_START)
			{

				reset();
				game_mode = MODE_GAME;
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
				// song = SONG_GAME;
				// music_play(song);
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
	}
}

void reset(void)
{
	ppu_wait_nmi();
	ppu_off();		 // screen off
	pal_bright(4); // back to normal brightness
	scroll_x = 0;
	scroll_y = 0;
	map_loaded = 0;
	player_in_air = 0;
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
	level = 0;				// debug, change starting level
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
			if (entity_type[index2] == ENTITY_PIT_WIDE_64)
			{
				oam_meta_spr(temp_x, temp_y, animate_bread_data);
			}
			else if (entity_type[index2] == ENTITY_LEVEL_UP)
			{
				oam_meta_spr(temp_x, temp_y, animate_bun_data);
			}
			else
			{
				oam_meta_spr(temp_x, temp_y, animate_fruit_data);
			}
		}
	}

	if (debug)
	{
		// SCROLL_X SPRITES
		// oam_spr(20, 010, 0x58, 1); // 0xfe = X
		temp1 = (scroll_x) >> 8;
		oam_spr(28, 10, temp1 + 0x30, 2);
		temp1 = (scroll_x & 0xff) >> 4;
		oam_spr(36, 10, temp1 + 0x30, 2);
		temp1 = (scroll_x & 0x0f);
		oam_spr(44, 10, temp1 + 0x30, 2);

		// CURRENT ROOM # SPRITE

		tempint = scroll_x + high_byte(BoxGuy1.x);
		temp1 = (tempint >> 8);

		// temp1 = (scroll_x) >> 8; // high byte of scroll_x
		// oam_spr(58, 010, 0x52, 1); // 0xfd = R
		oam_spr(90, 10, temp1 + 0x30, 1);
		temp1 = room_to_load;
		oam_spr(100, 10, temp1 + 0x30, 3);

		// PLAYER X LOCATION SPRITES
		// oam_spr(66, 10, 0x58, 2); // 0xfe = X
		temp1 = (BoxGuy1.x >> 8 & 0xff) >> 4;
		oam_spr(66, 10, temp1 + 0x30, 2);
		temp1 = (BoxGuy1.x >> 8 & 0x0f);
		oam_spr(74, 10, temp1 + 0x30, 2);

		oam_spr(120, 10, nametable_to_load + 0x30, 3);

		// // PLAYER Y LOCATION SPRITES
		// oam_spr(50, 20, 0xff, 2); // 0xff = Y
		// oam_spr(58, 20, temp_cmap1 + 0x30, 2);
		// oam_spr(80, 20, temp_cmap2 + 0x30, 2);
	}
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

	if (pad1 & PAD_LEFT && !player_in_hitstun)
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
	else if (pad1 & PAD_RIGHT && !player_in_hitstun)
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
		// TODO: not hardcode the last level here
		if (bg_coll_ladder_top_under_player() && level != 6)
		{
			BoxGuy1.x = (BoxGuy1.x + 0x700) & ~0xF00; // tried to square the player to the ladder
			player_on_ladder = 1;
			player_on_ladder_pose = 0;
			player_in_air = 0;
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

	if (BoxGuy1.vel_y > 0) // he's falling
	{
		// player_in_air = 1;
		if (bg_coll_D()) // if he's collising below
		{								 // check collision below
			player_in_air = 0;
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

	if (pad1_new & PAD_UP)
	{
		direction_y = UP;
		if (bg_coll_ladder())
		{
			// needs to snap player to grid, to nearest 16 pixels
			BoxGuy1.x = (BoxGuy1.x + 0x700) & ~0xF00;
			player_on_ladder_pose = 0;
			player_on_ladder = 1;
			player_in_air = 0;
			BoxGuy1.vel_y = 0;
			BoxGuy1.vel_x = 0;
		}
	}

	if (pad1_new & PAD_A)
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
			// sfx_play(SFX_JUMP, 0);
			short_jump_count = 1;
			player_in_air = 1;
		}
	}
	if (pad1_new & PAD_B && projectile_cooldown == 0) // shooting
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
				if (enemy_health[index] == 0 || enemy_health[index] > 240) // check for overflow with 240
				{
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
		if (enemy_x[index] > Generic2.x)
		{
			Generic.x -= 1; // test going left
			bg_collision_fast();
			if (collision_L)
				return;
			if (collision_D) // needs ground under it
			{

				if (enemy_actual_x[index] == 0)
				{
					--enemy_room[index];
				}
				--enemy_actual_x[index];
				enemy_dir[index] = LEFT;
			}
		}
		else if (enemy_x[index] < Generic2.x)
		{

			Generic.x += 1; // test going right

			bg_collision_fast();
			if (collision_R)
				return;
			if (collision_D)
			{
				++enemy_actual_x[index];
				if (enemy_actual_x[index] == 0)
				{
					++enemy_room[index];
				}
				
				enemy_dir[index] = RIGHT;
			}
		}
	}
}

void enemy_owl_behavior(void)
{
	// no collision for owl, he just swoops down and out.
	// mode 0 is idle, mode 1 is attacking

	if(enemy_x[index] > Generic2.x // enemy right of player
		&& enemy_x[index] - Generic2.x < 50) // and close
	{
		enemy_mode[index] = 1;
	}
	if(enemy_x[index] < Generic2.x // enemy left of player
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
		if (enemy_frames[index] < 10)
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
		else if (enemy_frames[index] < 20)
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
		else if (enemy_frames[index] < 30)
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
		else if (enemy_frames[index] < 40)
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
		else if (enemy_frames[index] < 50)
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
		else if (enemy_frames[index] < 60)
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
	if (enemy_frames[index] % 2 == 0 && enemy_mode[index] == 1) // he moves every 3 frames after activated
	{
		if (enemy_x[index] > Generic2.x) // enemy is right of player
		{
			if (enemy_actual_x[index] == 0)
			{
				--enemy_room[index]; //I think there's a bug here
			}
			--enemy_actual_x[index];
			++enemy_y[index];
			enemy_dir[index] = LEFT;
		}
		else if (enemy_x[index] < Generic2.x) // enemy is left of player
		{

			++enemy_actual_x[index];
			if (enemy_actual_x[index] == 0)
			{
				++enemy_room[index];  //I think there's a bug here
			}
			
			++enemy_y[index];
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

		++index2;
	}

	for (++index; index < MAX_ENEMY; ++index)
	{
		enemy_y[index] = TURN_OFF;
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
					// ppu_off();
					death_flag = 30; // 30 frames the player can die in
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

	Generic2.width = ENEMY_WIDTH;
	Generic2.height = ENEMY_HEIGHT;

	for (index = 0; index < MAX_ENEMY; ++index)
	{
		if (enemy_active[index])
		{
			Generic2.x = enemy_x[index];
			Generic2.y = enemy_y[index];
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
						player_in_hitstun = ENEMY_OWL_PLAYER_HITSTUN;
						invul_frames = ENEMY_OWL_PLAYER_INVUL;
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
	// clear nametables
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			// index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, 0); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}
	scroll_x = 0;
	set_scroll_x(0);
	oam_clear();

	game_mode = MODE_DEATH;
	multi_vram_buffer_horz("GAME OVER", 10, NTADR_A(11, 6));

	multi_vram_buffer_horz("PRESS START", 12, NTADR_A(10, 14));

	ppu_on_all();
	pal_fade_to(0, 4); // fade to black
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