#include <iostream>
#include "PremiumUser.h"
using namespace std;

PremiumUser::PremiumUser(char *nameInput) : User(nameInput)
{
    this->num_of_music_downloaded = 0;
    this->active = true;
}

PremiumUser::PremiumUser(const PremiumUser &otherUser) : User(otherUser.name)
{
    this->num_of_favourite_music = otherUser.getNumOfFavouriteMusic();
    this->music_list = new char *[1000];
    for (int i = 0; i < this->num_of_favourite_music; i++)
    {
        this->music_list[i] = new char[strlen(otherUser.music_list[i])];
        strcpy(this->music_list[i], otherUser.music_list[i]);
    }
    this->num_of_music_downloaded = otherUser.num_of_music_downloaded;
    this->active = otherUser.active;
}

PremiumUser::~PremiumUser()
{
}

void PremiumUser::downloadMusic(char *musicTitle)
{
    if (this->active)
    {
        this->num_of_music_downloaded++;
        cout << "Music Downloaded: " << musicTitle << endl;
    }
    else
    {
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser::inactivatePremium()
{
    this->active = false;
}

void PremiumUser::activatePremium()
{
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const
{
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const
{
    return this->active;
}