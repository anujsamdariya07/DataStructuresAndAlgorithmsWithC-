#include<iostream>
#include<cstring>

using namespace std;

int getLength(char ch[])
{
    int result = 0;

    int i = 0;
    while(ch[i] != '\0')
    {
        result++;
        i++;
    }
    
    return result;
}

int main()
{
    char ch[10] = "Anu";
    int result = getLength(ch);
    cout << "Length = " << result << endl;
    cout << "Length = " << strlen(ch) << endl;
}