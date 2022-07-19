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
    if (!IsAudioDeviceReady())
        InitAudioDevice();
    _music = LoadMusicStream("assets/music/menu.mp3");
    _music.looping = true;
    _soundVolume = 5;
    _musicVolume = 5;
    _isSoundActive = true;
    _isMusicActive = true;
    PlayMusicStream(_music);
    _hoverSound = LoadSound("assets/music/hoverSound.mp3");
    _clickSound = LoadSound("assets/music/clickSound.mp3");
    SetMusicVolume(_music, _musicVolume);
    SetSoundVolume(_hoverSound, _soundVolume);
    SetSoundVolume(_clickSound, _soundVolume);
    _oldMusicTime = 0.0f;
}

Music bomberman::settings::RaylibMusic::getMusicStream()
{
    return _music;
}

Sound bomberman::settings::RaylibMusic::getClickSound()
{
    return _clickSound;
}

Sound bomberman::settings::RaylibMusic::getHoverSound()
{
    return _hoverSound;
}

bool bomberman::settings::RaylibMusic::isSoundActive()
{
    return _isSoundActive;
}

bool bomberman::settings::RaylibMusic::isMusicActive()
{
    return _isMusicActive;
}

void bomberman::settings::RaylibMusic::changeMusic(std::string musicPath)
{
    if (IsMusicStreamPlaying(_music)) {
        _oldMusicTime = GetMusicTimePlayed(_music);
        StopMusicStream(_music);
        UnloadMusicStream(_music);
    }
    _music = LoadMusicStream(musicPath.c_str());
    PlayMusicStream(_music);
    SetMusicVolume(_music, _musicVolume);
}

void bomberman::settings::RaylibMusic::rechangeMusic(std::string musicPath)
{
    if (IsMusicStreamPlaying(_music)) {
        StopMusicStream(_music);
        UnloadMusicStream(_music);
    }
    _music = LoadMusicStream(musicPath.c_str());
    SeekMusicStream(_music, _oldMusicTime);
    PlayMusicStream(_music);
    _oldMusicTime = 0.0f;
}

void bomberman::settings::RaylibMusic::toggleSound(bool isActive)
{
    _isSoundActive = isActive;
}

void bomberman::settings::RaylibMusic::toggleMusic(bool isActive)
{
    // isActive ? PlayMusicStream(_music) : StopMusicStream(_music);
    _isMusicActive = isActive;
}

int bomberman::settings::RaylibMusic::getMusicVolume()
{
    return _musicVolume;
}

int bomberman::settings::RaylibMusic::getSoundVolume()
{
    return _soundVolume;
}

void bomberman::settings::RaylibMusic::increaseSound()
{
    _soundVolume = _soundVolume + 1 > 10 ? 10 : _soundVolume + 1;
    SetSoundVolume(_hoverSound, _soundVolume);
    SetSoundVolume(_clickSound, _soundVolume);
}

void bomberman::settings::RaylibMusic::decreaseSound()
{
    _soundVolume = _soundVolume - 1 < 0 ? 0 : _soundVolume - 1;
    SetSoundVolume(_hoverSound, _soundVolume);
    SetSoundVolume(_clickSound, _soundVolume);
}

void bomberman::settings::RaylibMusic::increaseMusic()
{
    _musicVolume = _musicVolume + 1 > 10 ? 10 : _musicVolume + 1;
    SetMusicVolume(_music, _musicVolume);
}

void bomberman::settings::RaylibMusic::decreaseMusic()
{
    _musicVolume = _musicVolume - 1 < 0 ? 0 : _musicVolume - 1;
    SetMusicVolume(_music, _musicVolume);
}

void bomberman::settings::RaylibMusic::update()
{
    UpdateMusicStream(_music);
}
