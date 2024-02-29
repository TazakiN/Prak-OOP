#include "SpacingGuildShip.hpp"

using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip()
    : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1)
{
    this->passengerCount - 0;
    this->operatingGuildNavigator = 3;
    this->spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock)
    : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1)
{
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &other) : maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), serialNum(producedShips + 1)
{
    this->passengerCount = other.passengerCount;
    this->operatingGuildNavigator = other.guildNavigatorCount;
    this->spiceStock = other.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip()
{
}

int SpacingGuildShip::getShipSerialNum() const
{
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
    return passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
    if (operatingGuildNavigator)
    {
        totalGuildTravel += distance / (E * E * operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers)
{
    if (passengerCount + addedPassengers > maxPassengerCap)
    {
        passengerCount = maxPassengerCap;
    }
    else
    {
        passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
    if (passengerCount - droppedPassengers < 0)
    {
        passengerCount = 0;
    }
    else
    {
        passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n)
{
    if (spiceStock >= n * GUILD_NAVIGATOR_SPICE_DOSE)
    {
        operatingGuildNavigator += n;
        spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
    }
    else
    {
        operatingGuildNavigator += spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock = 0;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
    spiceStock += addedSpice;
}