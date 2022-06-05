/*
** EPITECH PROJECT, 2020
** Pikmins
** File description:
** Options.cpp
*/
#include "raylib.h"
#include "Options.hpp"

bomberman::settings::RaylibMusic::RaylibMusic()
{
    InitAudioDevice();
    _music = LoadMusicStream("assets/music/menu.mp3");
    _music.looping = true;
    PlayMusicStream(_music);
}

Music bomberman::settings::RaylibMusic::getMusicStream()
{
    return _music;
}

bool bomberman::settings::RaylibMusic::isSoundActive()
{
    return _isSoundActive;
}

void bomberman::settings::RaylibMusic::toggleSound()
{
    _isSoundActive = !_isSoundActive;
}

void bomberman::settings::RaylibMusic::toggleMusic()
{
    if (IsMusicStreamPlaying(_music))
        StopMusicStream(_music);
    else
        PlayMusicStream(_music);
}
