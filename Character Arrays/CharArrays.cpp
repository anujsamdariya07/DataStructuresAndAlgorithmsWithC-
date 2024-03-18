#include<iostream>

using namespace std;

int main()
{
    char ch[10]; // Character array with 10 elements.

    int x = 'a'; // The ASCII value of a will be stored in x.

    // Input 2 ways:
    // 1st
    // for(int i = 0 ; i < 10 ; i++)
    // {
    //     cin >> ch[i];
    // }
    // 2nd
    // cin >> ch;

    char ch2[10] = "Anuj";
    // Here in ch2, the 5th charater will be the null character denoted by '\0', whose integer value will be 0, i.e., (int)'\0' = 0, it denotes string termination.

    // cin >> ch; --> Terminates on 'Enter(\n)', 'Tab(\t)', and 'Space( )'
    // cin.getline(ch, Number of characters you want as input) --> Terminates only on 'Enter(\n)', #include<string> required.
}