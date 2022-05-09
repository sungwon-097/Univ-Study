#include <iostream>
using namespace std;

class PFArrayI
{
public:
    PFArrayI( );
    //Initializes with a capacity of 50.

    PFArrayI(int capacityValue);

    PFArrayI(const PFArrayI& pfaObject);

    void addElement(int element);
    //Precondition: The array is not full.
    //Postcondition: The element has been added.

    bool full( ) const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.

    int getCapacity( ) const { return capacity; }

    int getNumberUsed( ) const { return used; }

    void emptyArray( ){ used = 0; }
    //Empties the array.

    int& operator[](int index);
    //Read and change access to elements 0 through numberUsed - 1.

    PFArrayI& operator =(const PFArrayI& rightSide);

    ~PFArrayI( );

private:
    int *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.

};

int main(){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayI temp(cap);

    cout << "Enter up to "<< cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    int next;
    cin >> next;

    while((next >= 0) && (!temp.full( ))){
        temp.addElement(next);
        cin >> next;
    }
    cout<< "You entered the following "<< temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout<< temp[index] << " ";
    cout<< endl;
}

PFArrayI::PFArrayI( ) :capacity(50), used(0){
    a = new int[capacity];
}

PFArrayI::PFArrayI(int size) :capacity(size), used(0){
    a = new int[capacity];
}

PFArrayI::PFArrayI(const PFArrayI& pfaObject) 
  :capacity(pfaObject.getCapacity( )), used(pfaObject.getNumberUsed( )){
    a = new int[capacity];
    for (int i =0; i < used; i++)
        a[i] = pfaObject.a[i];
}

void PFArrayI::addElement(int element){
    if (used >= capacity){
        cout << "Attempt to exceed capacity in PFArrayI.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

int& PFArrayI::operator[](int index){
    if (index >= used){
        cout << "Illegal index in PFArrayI.\n";
        exit(0);
    }

    return a[index];
}

PFArrayI& PFArrayI::operator =(const PFArrayI& rightSide){
    if (capacity != rightSide.capacity){
        delete [] a;
        a = new int[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];

    return *this;
}

PFArrayI::~PFArrayI( ){
    delete [] a;
}