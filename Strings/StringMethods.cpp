#include<iostream>
#include<string>

using namespace std;

int main()
{
    string name;
    cout << "Enter name: ";
    getline(cin, name);

    // Length of the string
    cout << "Length of string: " << name.length() << endl;

    // Check whether string is empty
    cout << "String empty or not: " << name.empty() << endl;

    // Find a character at a particular index
    cout << "Char at 0th index: " << name.at(0) << endl;

    // Front character of a string
    cout << "Front character of name is: " << name.front() << endl;

    // Back character of a string
    cout << "Back character of name is: " << name.back() << endl;

    string str1 = "Anuj";
    string str2 = "Samdariya";
    cout << "Before appending: " << str1 << " " << str2 << endl;
    str1.append(str2);
    cout << "After appending: " << str1 << " " << str2 << endl;

    // For erasing a part of the string
    string str3 = "This is a car";
    cout << "Before erasing: " << str3 << endl;
    str3.erase(4, 3);
    cout << "After erasing: " << str3 << endl;

    // Insert a string at a certain index
    string str4 = "Monkey Luffy";
    string str5 = " D.";
    cout << "Before inserting: " << str4 << endl;
    str4.insert(6, str5);
    cout << "After inserting: " << str4 << endl;

    // To add and delete an element at the last of the string
    string str6 = "Love";
    cout << "Before push_back: " << str6 << endl;
    str6.push_back('r');
    cout << "After push_back: " << str6 << endl;
    cout << "Before pop_back: " << str6 << endl;
    str6.pop_back();
    cout << "After pop_back: " << str6 << endl;

    string str7 = "Monkey D. Luffy";
    string str8 = "D.";
    if(str7.find(str8) == string::npos)
    {
        cout << "Not found" << endl;
    } else 
    {
        cout << "Found" << endl;
    }
    if(str7.compare(str8) == 0)
    {
        cout << "Matching" << endl;
    } else
    {
        cout << "Not matching" << endl;
    }

    // To take out a particular part of a string
    string str9 = "This is a car of big daddies";
    cout << "From 6 to 9 index: " << str9.substr(6, 9) << endl;
}