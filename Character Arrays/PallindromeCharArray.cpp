#include<iostream>
#include<cstring>

using namespace std;

void reverseCharArray(char ch[])
{
    int size = 0;
    int i = 0;
    while(ch[i] != '\0')
    {
        i++, size++;
    }

    int left = 0, right = size - 1;
    while(left < right)
    {
        swap(ch[left], ch[right]);
        left++, right--;
    }
}

bool isPallindrome1(char ch[])
{
    char *ch2 = new char[strlen(ch)];
    for(int i = 0 ; i < strlen(ch) ; i++)
    {
        ch2[i] = ch[i];
    }
    reverseCharArray(ch2);
    return (strcmp(ch, ch2) == 0);
}

bool isPallindrome2(char ch[])
{
    bool result;
    int left = 0, right = strlen(ch) - 1;
    while(left < right)
    {
        if(ch[left] == ch[right])
        {
            result = true;
        } else 
        {
            result = false;
            break;
        }
        left++, right--;
    }
    return result;
}

int main()
{
    char ch[100] = "NamaN";
    // 1st Approach
    if(isPallindrome1(ch) == true)
    {
        cout << "The given character array is a pallindrome." << endl;
    } else
    {
        cout << "The given character array is not a pallindrome." << endl;
    }
    
    // 2nd Approach
    if(isPallindrome2(ch) == true)
    {
        cout << "The given character array is a pallindrome." << endl;
    } else
    {
        cout << "The given character array is not a pallindrome." << endl;
    }
}