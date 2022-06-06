#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string love = "love", hate = "hate", text, str;

    fstream f;
    f.open("5.txt");

    while (f >> text)
    {
        if (text == hate)
            text = love;
        str += text;
        str += " ";
    }
    f.close();
    cout << str;
    return 0;
}