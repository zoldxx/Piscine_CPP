#pragma once
#include "Data.hpp"

class Serializer
{
    public:
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);

    private:
    Serializer();
    ~Serializer();
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const & src);
};
