#include "Paper.hpp"
int main() {
    Paper *a = new Paper('A');
    Paper *b = new Paper('B');
    Paper *c = new Paper('C');
    Paper *d = new Paper(*c);

    a->fold();
    b->fold();
    d->fold();
    d->glue();
    delete a;
    d->setName('X');
    c->fold();
    c->glue();
    c->~Paper();
    delete d;
    b->~Paper();
    return 0;
}