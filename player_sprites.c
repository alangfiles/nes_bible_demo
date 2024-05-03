#define PLAYER_RUN_1_FRAMES 12
#define PLAYER_RUN_2_FRAMES 24
#define PLAYER_RUN_3_FRAMES 36
#define PLAYER_RUN_4_FRAMES 48

#define PLAYER_LADDER_1_FRAMES 15
#define PLAYER_LADDER_2_FRAMES 30

void draw_boss_health_meter()
{
  // draw health meter
  switch (enemy_health[index])
  {
  case 28:
    tempint2 = animate_meter28_data;
    break;
  case 27:
    tempint2 = animate_meter27_data;
    break;
  case 26:
    tempint2 = animate_meter26_data;
    break;
  case 25:
    tempint2 = animate_meter25_data;
    break;
  case 24:
    tempint2 = animate_meter24_data;
    break;
  case 23:
    tempint2 = animate_meter23_data;
    break;
  case 22:
    tempint2 = animate_meter22_data;
    break;
  case 21:
    tempint2 = animate_meter21_data;
    break;
  case 20:
    tempint2 = animate_meter20_data;
    break;
  case 19:
    tempint2 = animate_meter19_data;
    break;
  case 18:
    tempint2 = animate_meter18_data;
    break;
  case 17:
    tempint2 = animate_meter17_data;
    break;
  case 16:
    tempint2 = animate_meter16_data;
    break;
  case 15:
    tempint2 = animate_meter15_data;
    break;
  case 14:
    tempint2 = animate_meter14_data;
    break;
  case 13:
    tempint2 = animate_meter13_data;
    break;
  case 12:
    tempint2 = animate_meter12_data;
    break;
  case 11:
    tempint2 = animate_meter11_data;
    break;
  case 10:
    tempint2 = animate_meter10_data;
    break;
  case 9:
    tempint2 = animate_meter9_data;
    break;
  case 8:
    tempint2 = animate_meter8_data;
    break;
  case 7:
    tempint2 = animate_meter7_data;
    break;
  case 6:
    tempint2 = animate_meter6_data;
    break;
  case 5:
    tempint2 = animate_meter5_data;
    break;
  case 4:
    tempint2 = animate_meter4_data;
    break;
  case 3:
    tempint2 = animate_meter3_data;
    break;
  case 2:
    tempint2 = animate_meter2_data;
    break;
  case 1:
    tempint2 = animate_meter1_data;
    break;
  default:
    tempint2 = animate_meter0_data;
    break;
  }

  oam_meta_spr(0x48, 0x16, tempint2);
}

void draw_player_health_meter()
{
  // draw health meter
  switch (BoxGuy1.health)
  {
  case 28:
    tempint2 = animate_meter28_data;
    break;
  case 27:
    tempint2 = animate_meter27_data;
    break;
  case 26:
    tempint2 = animate_meter26_data;
    break;
  case 25:
    tempint2 = animate_meter25_data;
    break;
  case 24:
    tempint2 = animate_meter24_data;
    break;
  case 23:
    tempint2 = animate_meter23_data;
    break;
  case 22:
    tempint2 = animate_meter22_data;
    break;
  case 21:
    tempint2 = animate_meter21_data;
    break;
  case 20:
    tempint2 = animate_meter20_data;
    break;
  case 19:
    tempint2 = animate_meter19_data;
    break;
  case 18:
    tempint2 = animate_meter18_data;
    break;
  case 17:
    tempint2 = animate_meter17_data;
    break;
  case 16:
    tempint2 = animate_meter16_data;
    break;
  case 15:
    tempint2 = animate_meter15_data;
    break;
  case 14:
    tempint2 = animate_meter14_data;
    break;
  case 13:
    tempint2 = animate_meter13_data;
    break;
  case 12:
    tempint2 = animate_meter12_data;
    break;
  case 11:
    tempint2 = animate_meter11_data;
    break;
  case 10:
    tempint2 = animate_meter10_data;
    break;
  case 9:
    tempint2 = animate_meter9_data;
    break;
  case 8:
    tempint2 = animate_meter8_data;
    break;
  case 7:
    tempint2 = animate_meter7_data;
    break;
  case 6:
    tempint2 = animate_meter6_data;
    break;
  case 5:
    tempint2 = animate_meter5_data;
    break;
  case 4:
    tempint2 = animate_meter4_data;
    break;
  case 3:
    tempint2 = animate_meter3_data;
    break;
  case 2:
    tempint2 = animate_meter2_data;
    break;
  case 1:
    tempint2 = animate_meter1_data;
    break;
  default:
    tempint2 = animate_meter0_data;
    break;
  }

  oam_meta_spr(0x16, 0x16, tempint2);
}

void draw_player_sprites()
{

  draw_player_health_meter();

  // player stuff get the player x,y
  temp_x = BoxGuy1.x >> 8;
  temp_y = BoxGuy1.y >> 8;

  // don't let it be 0
  if (temp_x == 0)
    temp_x = 1;
  if (temp_y == 0)
    temp_y = 1;

  // sprite_frame_counter
  ++sprite_frame_counter;

#define FLASH_DURATION 8
#define TOTAL_DURATION 16 // 4 frames on + 4 frames off

  if (invul_frames > 0)
  {
    if (frame_counter % TOTAL_DURATION < FLASH_DURATION)
    {
      return;
    }
  }

  // countdown player shot
  if (player_shooting > 0)
  {
    --player_shooting;
  }

  if (player_in_hitstun)
  {
    if (direction == LEFT)
    {
      tempint = animate_recoilleft_data;
    }
    else
    {
      tempint = animate_recoilright_data;
    }
    oam_meta_spr(temp_x, temp_y, tempint);
    return;
  }
  else if (player_in_air)
  {
    if (direction == LEFT)
    {
      if (player_shooting)
      {
        tempint = animate_playerjumpleftshoot_data;
      }
      else
      {
        tempint = animate_playerjumpleft_data;
      }
    }
    else
    {
      if (player_shooting)
      {
        tempint = animate_playerjumprightshoot_data;
      }
      else
      {
        tempint = animate_playerjumpright_data;
      }
    }
    oam_meta_spr(temp_x, temp_y, tempint);
    return;
  }
  else if (player_on_ladder)
  {
    if (player_shooting)
    {
      if (direction == LEFT)
      {
        tempint = animate_playerclimbshootleft_data;
        player_on_ladder_pose = 0;
      }
      else
      {
        tempint = animate_playerclimbshootright_data;
        player_on_ladder_pose = PLAYER_LADDER_1_FRAMES;
      }
      oam_meta_spr(temp_x, temp_y, tempint);
      return;
    }

    if (player_on_ladder_pose < PLAYER_LADDER_1_FRAMES)
    {
      oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
    }
    else if (player_on_ladder_pose < PLAYER_LADDER_2_FRAMES)
    {
      oam_meta_spr(temp_x, temp_y, animate_playerclimb2_data);
    }
    else
    {
      oam_meta_spr(temp_x, temp_y, animate_playerclimb1_data);
      player_on_ladder_pose = 0;
    }

    return;
  }
  else if (player_is_running) // running
  {

    if (sprite_frame_counter < PLAYER_RUN_1_FRAMES)
    {
      if (direction == LEFT)
      {
        if (player_shooting)
        {
          tempint = animate_playerrunshoot2left_data;
        }
        else
        {
          tempint = animate_playerrun2left_data;
        }
      }
      else
      {

        if (player_shooting)
        {
          tempint = animate_playerrunshoot2right_data;
        }
        else
        {
          tempint = animate_playerrun2right_data;
        }
      }
    }
    else if (sprite_frame_counter < PLAYER_RUN_2_FRAMES)
    {
      if (direction == LEFT)
      {
        if (player_shooting)
        {
          tempint = animate_playerrunshoot3left_data;
        }
        else
        {
          tempint = animate_playerrun3left_data;
        }
      }
      else
      {

        if (player_shooting)
        {
          tempint = animate_playerrunshoot3right_data;
        }
        else
        {
          tempint = animate_playerrun3right_data;
        }
      }
    }
    else if (sprite_frame_counter < PLAYER_RUN_3_FRAMES)
    {
      if (direction == LEFT)
      {
        if (player_shooting)
        {
          tempint = animate_playerrunshoot2left_data;
        }
        else
        {
          tempint = animate_playerrun2left_data;
        }
      }
      else
      {

        if (player_shooting)
        {
          tempint = animate_playerrunshoot2right_data;
        }
        else
        {
          tempint = animate_playerrun2right_data;
        }
      }
    }
    else if (sprite_frame_counter < PLAYER_RUN_4_FRAMES)
    {
      if (direction == LEFT)
      {
        if (player_shooting)
        {
          tempint = animate_playerrunshoot1left_data;
        }
        else
        {
          tempint = animate_playerrun1left_data;
        }
      }
      else
      {

        if (player_shooting)
        {
          tempint = animate_playerrunshoot1right_data;
        }
        else
        {
          tempint = animate_playerrun1right_data;
        }
      }
    }
    else
    {
      sprite_frame_counter = 0;
      if (direction == LEFT)
      {
        if (player_shooting)
        {
          tempint = animate_playerrunshoot1left_data;
        }
        else
        {
          tempint = animate_playerrun1left_data;
        }
      }
      else
      {

        if (player_shooting)
        {
          tempint = animate_playerrunshoot1right_data;
        }
        else
        {
          tempint = animate_playerrun1right_data;
        }
      }
    }

    oam_meta_spr(temp_x, temp_y, tempint);
    return;
  }

  else //  player is standing
  {
    if (player_shooting)
    {
      if (direction == LEFT)
      {
        tempint = animate_playerstandshootleft_data;
      }
      else
      {
        tempint = animate_playerstandshootright_data;
      }
    }
    else
    {
      if (direction == LEFT)
      {
        tempint = animate_playerstandleft_data;
      }
      else
      {
        tempint = animate_playerstandright_data;
      }
    }
    oam_meta_spr(temp_x, temp_y, tempint);
    return;
  }
}