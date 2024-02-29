#include "Item.hpp"

using namespace std;

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : serialNum(totalItems + 1)
{
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
};

Item::Item(int stock, int price) : serialNum(totalItems + 1)
{
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item &other) : serialNum(totalItems + 1)
{
    this->stock = other.stock;
    this->price = other.price;
    this->sold = other.sold;
    totalItems++;
}

Item::~Item()
{
}

int Item::getSerialNum() const
{
    return serialNum;
}

int Item::getSold() const
{
    return this->sold;
}

int Item::getPrice() const
{
    return this->price;
}

void Item::addStock(int addedStock)
{
    this->stock += addedStock;
}

void Item::sell(int soldStock)
{
    if (stock < soldStock)
    {
        totalRevenue += stock * price;
        this->sold += stock;
        stock = 0;
    }
    else
    {
        totalRevenue += soldStock * price;
        this->sold += soldStock;
        stock -= soldStock;
    }
}

void Item::setPrice(int newPrice)
{
    this->price = newPrice;
}