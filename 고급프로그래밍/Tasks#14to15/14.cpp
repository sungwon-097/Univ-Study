#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    DayOfYear(int monthValue, int datValue);
    DayOfYear(string monthValue, int datValue);

    DayOfYear(int monthValue);
    DayOfYear(string monthValue);

    void input( );
    void output( );
    void set(int newMonth, int newDay);
    //Precondition: newMonth and newDay form a possible date.

    void set(int newMonth);
    //Precondition: 1 <= newMonth <= 12
    //Postcondition: The date is set to the first day of the given month.
 
    int getMonthNumber( ); //Returns 1 for January, 2 for February, etc.
    int getDay( );

private:
    int month;
    int day;
    void testDate();
};

int main(){
    string sMonth; 
    int day;
    
    cout<< "Put an abbreviation of a month(3chars) and a day(number): ";
    cin >> sMonth >> day;
    DayOfYear date1(sMonth), date2(sMonth, day);
    date1.output();
    date2.output();
}

DayOfYear::DayOfYear(int monthValue, int dayValue)
{
    set(monthValue, dayValue);
    testDate();
}

DayOfYear::DayOfYear(string monthValue, int dayValue)
{
    int month;
    if(monthValue == "Jan") month = 1;
    else if(monthValue == "Feb") month = 2;
     else if(monthValue == "Mar") month = 3;
      else if(monthValue == "Apr") month = 4;
       else if(monthValue == "May") month = 5;
        else if(monthValue == "Jun") month = 6;
         else if(monthValue == "Jul") month = 7;
          else if(monthValue == "Aug") month = 8;
           else if(monthValue == "Sep") month = 9;
            else if(monthValue == "Oct") month = 10;
             else if(monthValue == "Nov") month = 11;
              else if(monthValue == "Dec") month = 12;
    set(month, dayValue);
    testDate();
}

DayOfYear::DayOfYear(int monthValue)
{
    int dayValue = 1;
    set(monthValue, dayValue);
    testDate();
}

DayOfYear::DayOfYear(string monthValue)
{
    int month, dayValue = 1;
    if(monthValue == "Jan") month = 1;
    else if(monthValue == "Feb") month = 2;
     else if(monthValue == "Mar") month = 3;
      else if(monthValue == "Apr") month = 4;
       else if(monthValue == "May") month = 5;
        else if(monthValue == "Jun") month = 6;
         else if(monthValue == "Jul") month = 7;
          else if(monthValue == "Aug") month = 8;
           else if(monthValue == "Sep") month = 9;
            else if(monthValue == "Oct") month = 10;
             else if(monthValue == "Nov") month = 11;
              else if(monthValue == "Dec") month = 12;
    set(month, dayValue);
    testDate();
}

//Uses iostream and cstdlib:
void DayOfYear::set(int newMonth, int newDay)
{
    if ((newMonth >= 1) && (newMonth <= 12))
        month = newMonth;
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    if ((newDay >= 1) && (newDay <= 31))
        day = newDay;
    else
    {
        cout << "Illegal day value! Program aborted.\n";
        exit(1);
    }
}

//Uses iostream and cstdlib:
void DayOfYear::set(int newMonth)
{
    if ((newMonth >= 1) && (newMonth <= 12))
        month = newMonth;
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    day = 1;
}


int DayOfYear::getMonthNumber( )
{
    return month;
}

int DayOfYear::getDay( )
{
    return day;
}

//Uses iostream and cstdlib:
void DayOfYear::input( )
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
    {
        cout << "Illegal date! Program aborted.\n";
        exit(1);
    }
}

void DayOfYear::output( )
{
    switch (month)
    {
        case 1:
            cout << "January "; break;
        case 2:
            cout << "February "; break;
        case 3:
            cout << "March "; break;
        case 4:
            cout << "April "; break;
        case 5:
            cout << "May "; break;
        case 6:
            cout << "June "; break;
        case 7:
            cout << "July "; break;
        case 8:
            cout << "August "; break;
        case 9:
            cout << "September "; break;
        case 10:
            cout << "October "; break;
        case 11:
            cout << "November "; break;
        case 12:
            cout << "December "; break;
        default:
            cout << "Error in DayOfYear::output. Contact software vendor.";
    }

    cout << day << "\n";
}
void DayOfYear::testDate()
{
    if((month < 1) || (month > 12))
    {
        cout << "illegal month value!\n";
        exit(1);
    }
    if((day < 1)||(day > 31))
    {
        cout << "illegal day value!\n";
        exit(1);
    }
}