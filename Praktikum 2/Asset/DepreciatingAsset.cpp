#include "DepreciatingAsset.hpp"
#include "BaseAsset.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double DepreciatingAsset::getValue(int years)
{
    return x->getValue(years) * pow(1 - this->rate, years);
}