#ifndef COMMAND_HPP
#define COMMAND_HPP

class Command {
public:
    virtual std::string format() const = 0;
};

#endif
