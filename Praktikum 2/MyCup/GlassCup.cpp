#include "GlassCup.hpp"

using namespace std;

bool GlassCup::is_usable()
{
    return Glass::is_usable();
}

void GlassCup::fill(int volume, enum WaterType type)
{
    if (is_usable())
    {
        Cup::fill(volume, type);
    }
}

void GlassCup::drink(int volume)
{
    if (is_usable())
    {
        Cup::drink(volume);
    }
}

void GlassCup::drop(int height)
{
    if (is_usable())
    {
        int force;
        if (Cup::get_water_volume() == 0)
        {
            force = height;
        }
        else
        {
            force = height * Cup::get_water_volume();
        }
        Glass::apply_force(force);
    }
}