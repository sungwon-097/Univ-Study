#include <iostream>

int iAdd(int num1, int num2){
    return num1 + num2;
}

int iSub(int num1, int num2){
    return num1 - num2;
}

int iMul(int num1, int num2){
    return num1 * num2;
}

double iDiv(int num1, int num2){
    return (double)num1 / (double)num2;
}

int main()
{
    int a = 20, b = 7;
    std::cout<< "Add:\t"<< iAdd(a,b) << std::endl;
    std::cout<< "Sub:\t"<< iSub(a,b) << std::endl;
    std::cout<< "Mul:\t"<< iMul(a,b) << std::endl;
    std::cout<< "Div:\t"<< iDiv(a,b) << std::endl;

    return 0;
}

