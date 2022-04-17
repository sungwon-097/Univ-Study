#include <iostream>

using namespace std;

class DayOfYear{
    public:
        void output();
        void adjustDay(int day);
        int month;
        int day;
};

void DayOfYear::output()
{
    switch(month){
        case 1: cout << "January "; break;
        case 2: cout << "February "; break;
        case 3: cout << "March "; break;
        case 4: cout << "April "; break;
        case 5: cout << "May "; break;
        case 6: cout << "June "; break;
        case 7: cout << "July "; break;
        case 8: cout << "August "; break;
        case 9: cout << "September "; break;
        case 10: cout << "October "; break;
        case 11: cout << "November "; break;
        case 12: cout << "Decamber "; break;
        default: cout << "Error "; break;
    }
    cout << day;
}

void DayOfYear::adjustDay(int date)
{
    day += date; // 조정할 날짜를 더함
    if(day < 1) month -= 1; // day가 1 미만으로 유효하지 않을 때 전 달로 계산

    if(month > 12) month -= 12; // month를 유효한 값으로 맞춰줌 (0 < month <= 12)
    else if(month < 1) month += 12;

    int monthDay = 0; // 그 달의 날짜를 담을 변수
    switch(month){ // monthDay를 계산
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            monthDay = 31; break;
        case 4:case 6:case 9:case 11:
            monthDay = 30; break;
        case 2:
            monthDay = 28; break;
        default:;
    }

    if(day > 0){
        if(day > monthDay){ // day가 양수이며 monthDay보다 큰 경우
            day -= monthDay; month += 1; //달 넘어감
            adjustDay(0);
        }
        else return; // day가 양수이며 monthDay 범위인 경우(유효한 날짜)
    }
    else{ // day 가 0또는 음수일 경우 
        day += monthDay; // 전 달의 monthDay를 더함
        adjustDay(0);
    }
}
int main(){
    DayOfYear d1;
    d1.month = 8;
    d1.day = 20;

    d1.adjustDay(20);
    cout << "Adjusted date is : ";
    d1.output(); cout << endl;
}