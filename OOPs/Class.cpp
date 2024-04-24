#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
    int height;

public:
    // bool isRegistered;
    double id;
    double age;
    string name;
    int nos;

    void study()
    {
        cout << "Studying" << endl;
    }
    void sleep()
    {
        cout << "Sleeping" << endl;
    }
    void bunk()
    {
        cout << "Bunking" << endl;
    }
};

int main()
{
    // If we remove all the member variables of a class then the compiler will auto-assign 1 byte to it.
    // While calculating size of smaller variables, to reduce the processing time, an additional padding is added.
    // Here, int have size of 4, so for bool which has a size of 1, we will get it's size as 4 as well. But if we calculate it's size alone, then we will recieve as 1.
    cout << sizeof(Student) << endl;
    Student s1;
    Student s2;

    // s1.height = 10;--> error
    s1.name = "Anuj";
    s1.age = 20;
    s1.nos = 430;
    s1.id = 21;

    s2.name = "Luffy";
    s2.age = 19;
    s2.nos = 0;
    s2.id = 56;
}