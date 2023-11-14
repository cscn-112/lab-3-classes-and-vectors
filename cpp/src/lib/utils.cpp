#include <string>
#include <fstream>

#include "utils.h"

float greater_than(float x, float y)
{
    return x > y ? x : y;
}

float less_than(float x, float y)
{
    return x < y ? x : y;
}

std::string read_line(std::fstream &File)
{
    std::string buf = "";

    std::getline(File, buf);

    return buf;
}
