#include<iostream>
#include<cstring>

using namespace std;

void toUppercase(char ch[])
{
    for(int i = 0 ; i < strlen(ch) ; i++)
    {
        if(ch[i] > 'Z')
        {
            ch[i] = ch[i] - 'a' + 'A';
        }
    }
}

int main()
{
    char ch[100] = "Anuj";
    cout << "The character array before conversion: " << ch << endl;
    toUppercase(ch);
    cout << "The character array after conversion: " << ch << endl;
}