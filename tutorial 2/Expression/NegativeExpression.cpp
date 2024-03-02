#include "NegativeExpression.hpp"

NegativeExpression::NegativeExpression(Expression *x) : UnaryExpression(x)
{
}

int NegativeExpression::solve()
{
    return -this->x->solve();
}