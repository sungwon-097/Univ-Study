#include <iostream>
#include <algorithm>
#include <vector>

void sort_three(int& a, int& b, int& c){

    std::vector<int> array;
    array.push_back(a);
    array.push_back(b);
    array.push_back(c);

    sort(array.begin(), array.end(), std::greater<int>());
    a = array[0];
    b = array[1];
    c = array[2];
}

int main(){
    int i1 = 100, i2 = 90, i3 = 500;
    sort_three(i1, i2, i3);
    std::cout << "Three number are: "
         << i1 << " , " << i2 << " , "<< i3 << "\n";
}