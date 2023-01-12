#include <iostream>
#include <exception>

class FieldExceptions :public std::exception{
   const char* message;
public:
    FieldExceptions(const char*  exception) :message(exception){}

    const char*  what ()const noexcept override{
        return message;
    }

};