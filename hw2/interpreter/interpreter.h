#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>

class Interpreter {
public:
    Interpreter(std::istream& in);
    ~Interpreter();

    void write(std::ostream& out);

private:
    void parse(std::istream& in);
};

#endif
