#include <iostream>
#include <string>

using namespace std;

int convertToASCII(string letter)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        char x = letter.at(i);
        sum += int(x);
    }
    return sum;
}
