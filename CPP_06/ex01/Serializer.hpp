#pragma once
#include <iostream>
#include <cstdint>

typedef struct Data
{
    std::string message;
    int         grade;
}              Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(std::string s);
        Serializer(const Serializer &);
        Serializer& operator=(const Serializer &);
        ~Serializer();
};
