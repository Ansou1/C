/*
** sound.c for  in /home/daguen_s/rendu/T2Rush1/etape_2
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Sun Mar  9 18:43:44 2014 daguen_s
** Last update Sun Mar  9 19:15:29 2014 daguen_s
*/

#include "rush.h"

void                    stop()
{
  Mix_HaltMusic();
  Mix_HaltChannel(-1);
  Mix_FreeMusic(music);
  Mix_FreeChunk(sound);
  Mix_CloseAudio();
}

void                    son()
{
  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
  music = Mix_LoadMUS("./img/badboys.wav");
  Mix_PlayMusic(music, -1);
}

