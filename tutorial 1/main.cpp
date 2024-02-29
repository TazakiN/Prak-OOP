#include "A.hpp"

int main()
{
    A x('1');
    A y('2');
    A z(x);
    z = y;
    z.show();
    return 0;
}