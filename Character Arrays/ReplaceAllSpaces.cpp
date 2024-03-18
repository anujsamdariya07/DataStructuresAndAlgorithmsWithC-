#include<iostream>
#include<cstring>

using namespace std;

void replaceAllSpace(char ch[])
{
    int i = 0, size = strlen(ch);
    while(i < size)
    {
        if(ch[i] == ' ')
        {
            ch[i] = '@';
        }
        i++;
    }
}

int main()
{
    char ch[100] = "My Name is Anuj";
    cout << "Character Array before replacing: " << ch << endl;
    replaceAllSpace(ch);
    cout << "Character Array after replacing: " << ch << endl;
}