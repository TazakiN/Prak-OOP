#include "PlasticCup.hpp"

using namespace std;

bool PlasticCup::is_usable()
{
    return Plastic::is_usable() && current_microplastics < maximum_microplastics;
}

void PlasticCup::fill(int volume, enum WaterType type)
{
    Cup::fill(volume, type);
    Plastic::use();
    if (WaterType::HOT_WATER == type)
    {
        current_microplastics += Plastic::shred_microplastics(volume * 2, capacity);
    }
    else
    {
        current_microplastics += Plastic::shred_microplastics(volume, capacity);
    }
}

void PlasticCup::drink(int volume)
{
    Cup::drink(volume);
    Plastic::use();
    current_microplastics -= volume;
    if (current_microplastics < 0)
    {
        current_microplastics = 0;
    }
}

void PlasticCup::drop(int height)
{
    current_microplastics += Plastic::shred_microplastics(get_water_volume() * height, capacity);
    Cup::drop(height);
}