#include "Restaurant.hpp"

Restaurant::Restaurant()
{
}

Restaurant::~Restaurant() {}

void Restaurant::Push(int val)
{
    this->order.push(val);
}

void Restaurant::Pop(int val)
{
    if (this->order.size() < val)
    {
        cout << "Proses tidak valid" << endl;
    }
    else
    {
        for (int i = 0; i < val; i++)
        {
            this->order.pop();
        }
    }
}

void Restaurant::AddMenu(int k, int val)
{
    if (k == 0 || this->order.size() == 0)
        return;
    int temp = this->order.top();
    this->Pop(1);
    AddMenu(k - 1, val);
    temp += val;
    this->Push(val);
}

void Restaurant::Reorder(int k)
{
}

ostream &operator<<(ostream &os, Restaurant res)
{
    os << "(";
    if (res.order.size() != 0)
    {
        for (int i = 0; i < res.order.size() - 1; i++)
        {
            os << res.order.top() << ", ";
            res.order.pop();
        }
        os << res.order.top();
    }
    os << ")";
}