#include <iostream>

using namespace std;

class HotDogStand // define class
{
public:
    HotDogStand(string Name);
    void justSold(int sold);
    string getName();
    int getNumSold();
    static int getTotalNumSold();

private:
    static int totalNumSold;
    int salesVolume;
    int sold;
    string storeName;
};

int main(){
    
    HotDogStand h1("SSU-1"), h2("SSU-2"), h3("CAU-1");
    h1.justSold(20);
    h2.justSold(50);
    h3.justSold(1);

    cout << h1.getName() << " has sold " << h1.getNumSold() << " hotdogs." << "\n";
    cout << h2.getName() << " has sold " << h2.getNumSold() << " hotdogs." << "\n";
    cout << h3.getName() << " has sold " << h3.getNumSold() << " hotdogs." << "\n";

    cout << "Total sales are : " << HotDogStand::getTotalNumSold() << "\n";
}

HotDogStand::HotDogStand(string name){ // init class
    storeName = name;
    salesVolume = 0;
    sold = 0;
}

int HotDogStand::getNumSold(){ // get Total sales volume(in object)
    return salesVolume;
}

int HotDogStand::totalNumSold = 0; // init static variable

int HotDogStand::getTotalNumSold(){ // return Total sales volume(All objects)
    return totalNumSold;
}

void HotDogStand::justSold(int sold){ // add sold volume(in object and All objects)
    salesVolume += sold;
    totalNumSold += sold;
}

string HotDogStand::getName(){ // define name
    return storeName;
}