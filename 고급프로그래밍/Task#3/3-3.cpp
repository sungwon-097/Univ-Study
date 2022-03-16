#include <iostream>

using namespace std;

int main(void){

    double temp_Celsius, temp_Fahrenheit;
    cout << "Put the degree in Celsius : ";
    cin >> temp_Celsius;

    temp_Fahrenheit = 1.8 * temp_Celsius + 32.0;

    cout << "The degree in Fahrenheit is : " << temp_Fahrenheit << "\n";
    return 0;
}