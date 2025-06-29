#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <iostream>
#include <limits>
#include "Global.h"

class Input
{
public:
    static float ReadFloatNumber(string msg = "Invalid Number, Enter again : ");
    static string ReadString();
    static int ReadNumberBetween(int from, int to);
    static int ReadNumber();
};

#endif  // INPUT_H