#include <iostream>

class FieldExceptions {
    std::string message;
public:
    FieldExceptions(std::string exception) :message(exception){}

    std::string what ()const noexcept{
        return message;
    }

};