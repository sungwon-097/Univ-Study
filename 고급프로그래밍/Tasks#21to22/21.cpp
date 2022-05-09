#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

    // class declare
class Employee
    {
    public:
        Employee( );
        Employee(const string& theName, const string& theSsn);
        string getName( ) const;
        string getSsn( ) const;
        double getNetPay( ) const;
        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);
        void printCheck( ) const;
    private:
        string name;
        string ssn;
        double netPay;
    };

class HourlyEmployee : public Employee
    {
    public:
        HourlyEmployee( );
        HourlyEmployee(const string&  theName, const string&  theSsn,
                           double theWageRate, double theHours);
        void setRate(double newWageRate);
        double getRate( ) const;
        void setHours(double hoursWorked);
        double getHours( ) const;
        void printCheck( ) ;
    private:
        double wageRate;
        double hours;
    };

class UnivHourlyEmployee : public HourlyEmployee
    {
    public:
        UnivHourlyEmployee( );
        UnivHourlyEmployee(const string&  theName, const string&  theSsn, 
                                string univ, double wageRate, double hoursWorked);
        void setUniv(const string& theUniv);
        void printInfo();
        string getUniv() const;
    private:
        string univName;
    }; 

    // main function
int main(){
    UnivHourlyEmployee john("JohnDoe", "123456", "SSU", 10, 40);
    john.printInfo();
}
    //class define
Employee::Employee( ) : name("No name yet"), ssn("No number yet"), netPay(0)
{
    setName("No name yet");
    setSsn("No number yet");
    setNetPay(0);
}

Employee::Employee(const string& theName, const string& theNumber)
    : name(theName), ssn(theNumber), netPay(0)
{
    setName(theName);
    setSsn(theNumber);
    setNetPay(0);
}

string Employee::getName( ) const
{
    return name;
}

string Employee::getSsn( ) const
{
    return ssn;
}

double Employee::getNetPay( ) const
{
    return netPay;
}

void Employee::setName(const string& newName)
{
    name = newName;
}

void Employee::setSsn(const string& newSsn)
{
    ssn = newSsn;
}

void Employee::setNetPay (double newNetPay)
{
    netPay = newNetPay;
}

void Employee::printCheck( ) const
{
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
            << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
            << "Check with the author of the program about this bug.\n";
    exit(1);
}

HourlyEmployee::HourlyEmployee( ) : Employee( ), wageRate(0), hours(0)
{
    setRate(0);
    setHours(0);
}

HourlyEmployee::HourlyEmployee(const string&  theName, const string&  theNumber,
                                double theWageRate, double theHours)
    : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours)
{
    setName(theName);
    setSsn(theNumber);
    setRate(theWageRate);
    setHours(theHours);
}

void HourlyEmployee::setRate(double newWageRate)
{
    wageRate = newWageRate;
}

double HourlyEmployee::getRate( ) const
{
    return wageRate;
}

void HourlyEmployee::setHours(double hoursWorked)
{
    hours = hoursWorked;
}

double HourlyEmployee::getHours( ) const
{
    return hours;
}

void HourlyEmployee::printCheck( )
{
    setNetPay(hours * wageRate);

    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << getName( ) << endl;
    cout << "The sum of " << getNetPay( ) << " Dollars\n";
    cout << "________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSsn( ) << endl;
    cout << "Hourly Employee. \nHours worked: " << hours
            << " Rate: " << wageRate << " Pay: " << getNetPay( ) << endl;
    cout << "_________________________________________________\n";
}

UnivHourlyEmployee::UnivHourlyEmployee( ){
    setUniv("univ");
}

UnivHourlyEmployee::UnivHourlyEmployee(const string&  theName, const string&  theSsn, string univ, double wageRate, double hoursWorked){
    setName(theName);
    setSsn(theSsn);
    setUniv(univ);
    setNetPay(wageRate*hoursWorked);
    setRate(wageRate);
    setHours(hoursWorked);
    
}
void UnivHourlyEmployee::setUniv(const string& univ)
{
    univName = univ;
}
string UnivHourlyEmployee::getUniv() const{
    return univName;
}

void UnivHourlyEmployee::printInfo(){
    cout << "Employee name: " << getName() << ", Affliation: " << getUniv();
    printCheck();
}