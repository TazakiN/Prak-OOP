#include "AppreciatingAsset.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double AppreciatingAsset::getValue(int years)
{
    return x->getValue(years) * pow(this->rate + 1, years);
}