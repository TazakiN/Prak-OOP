#ifndef NEGATIVEEXPRESSION_HPP
#define NEGATIVEEXPRESSION_HPP

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression
{
public:
    NegativeExpression(Expression *x);
    int solve();
};

#endif