#include <iostream>

const double TRANSFER_TO_MILE = 1.60934 * 1000; // meter to miles

using namespace std;

int main(void){

    double distance_METER = 184.6;
    double distance_MILE = distance_METER / TRANSFER_TO_MILE;

    cout << "The distance is " << distance_MILE << " miles\n";
    return 0;
}