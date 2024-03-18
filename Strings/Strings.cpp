#include<iostream>
#include<string>

using namespace std;

int main()
{
    // Can change size dynamically during run time

    // Creation
    string name = "Anuj";

    // Input
    cout << "Enter your name: ";
    // cin >> name;
    getline(cin, name);

    // Output
    cout << name << endl;

    // Printing specific character
    cout << name[3] << endl;

    int index = 0;
    while(name[index] != '\0')
    {
        cout << "index: " << index << " Character: " << name[index] << endl;
        index++;
    }
}