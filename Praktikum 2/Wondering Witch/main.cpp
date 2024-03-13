#include "A.hpp"
#include "B.hpp"

int main() {
    B b;

    // Start editing here :D
    b.A::setMe(10);
    b.setMe(200);
    b.print();
    return 0;
}