#include "person.h"

std::ostream& operator<<(std::ostream& stream, const person& p)
{
    stream << p.getInfo();
    return stream;
}