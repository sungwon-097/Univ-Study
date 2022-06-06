#include <iostream>
#include <string>

using namespace std;

class Hotdog
{
public:
    Hotdog(string s) : name(s), soldNum(0) {}
    void getNumSold() { cout << name << " " << soldNum << "\n"; }
    void justsold(int sold)
    {
        soldNum += sold;
        total += sold;
    }
    static int getTotal() { return total; }
    // int getTotal() { return 2; };

private:
    string name;
    int soldNum;
    static int total;
};
int Hotdog::total = 0;

int main()
{
    Hotdog h1("s1");
    Hotdog h2("s2");
    Hotdog h3("s3");

    h1.justsold(10);
    h2.justsold(20);
    h3.justsold(30);

    h1.getNumSold();
    h2.getNumSold();
    h3.getNumSold();

    cout << Hotdog::getTotal();
}