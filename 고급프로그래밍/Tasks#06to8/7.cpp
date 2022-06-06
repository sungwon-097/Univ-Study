#include <iostream>
#include <algorithm>
#include <vector>

#define ARRAY_ROW 4
#define ARRAY_COULMN 4

using namespace std;

int main(){

    int a[ARRAY_ROW][ARRAY_COULMN] = { 10, 20, 30, 40, 5, 4, 3, 99, 55, 100, 42, 100, 0, 105, 2, 11};
    int len = ARRAY_COULMN * ARRAY_ROW;
    vector<int> copyArr;
    
    for(int i=0 ; i < len ; i++){
        copyArr.push_back(*(*a+i));
    }

    sort(copyArr.begin(), copyArr.end(), greater<int>());

    cout << "The largest number is " << copyArr[0] << endl;
    cout << "The second-largest number is " << copyArr[1];
    
    return 0;
}