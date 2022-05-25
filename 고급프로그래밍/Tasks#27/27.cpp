#include <iostream>
#include <map>
#include <string>

using namespace std;

void inputInfo(map<string, string> container)
{
START:

    string id, name;
    map<string, string>::iterator iter;

    while (true)
    {
        cout << "Enter the ID number : ";
        cin >> id;
        if (id == "0")
            break;
        cout << "Enter the student name : ";
        cin >> name;
        container.insert(make_pair(id, name));
    }
    cout << "(interrupt)\nEnter the searching ID number : ";
    cin >> id;

    for (iter = container.begin(); iter != container.end(); iter++)
    {
        if (iter->first == id)
        {
            cout << "The student name is " << iter->second << "\n";
            return;
        }
    }
    char flag;
    cout << "\nInvalid ID, do you want to restart?(y/n) : ";
    cin >> flag;
    if (flag == 'y')
        goto START;

    return;
}

int main()
{
    map<string, string> students;
    inputInfo(students);
}