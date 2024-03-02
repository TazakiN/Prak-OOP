#ifndef SubstractEXPRESSION_HPP
#define SubstractEXPRESSION_HPP

#include "Expression.hpp"

class SubstractExpression : public BinaryExpression
{
public:
    SubstractExpression(Expression *x, Expression *y);
    int solve();
};

#endif