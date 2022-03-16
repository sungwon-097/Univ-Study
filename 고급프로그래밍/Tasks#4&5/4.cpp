#include <iostream>

using namespace std;

int main(void){

    int score[3] = {0,}; // store 3 scores
    double avg = 0.0;
    string grade = "";

    cout << "Put the discrete math score : ";
    cin >> score[0];
    cout << "Put the Programming Language score : ";
    cin >> score[1];
    cout << "Put the Data Structure score : ";
    cin >> score[2];

    avg = (score[0] + score[1] + score[2]) / 3.0;

    if(avg > 95)         grade = "A+";
    else if(avg > 90)    grade = "A0";
    else if(avg > 85)    grade = "B+";
    else if(avg > 80)    grade = "B0";
    else if(avg > 75)    grade = "C+";
    else if(avg > 70)    grade = "C0";
    else                 grade = "F";

    cout<<fixed;
    cout.precision(2);
    cout << "The average score is " << avg << " and the grade is " << grade << endl;

    return 0;
}