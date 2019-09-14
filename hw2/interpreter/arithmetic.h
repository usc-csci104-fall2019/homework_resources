#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

#include <string>
#include

class NumericExpression {
public:
    virtual ~NumericExpression() {}
    virtual std::string format() const = 0;
};

class AdditionExpression : public NumericExpression {
public:
    AdditionExpression(NumericExpression* left, NumericExpression* right);
    ~AdditionExpression();

    virtual std::string format() const;

private:
    NumericExpression* left;
    NumericExpression* right;
};

#endif
