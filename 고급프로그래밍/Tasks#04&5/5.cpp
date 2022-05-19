#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){

    string text, str;
    fstream inputStream;

    inputStream.open("task5.txt");

    while(inputStream >> text){
        if(text != "hate")  str += text + " ";
        else                str += "love ";
    }
    inputStream.close();

    cout << str;
    return 0;
}