#include<iostream>

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

int main()
{
    char ch[10] = "Anuj";
    cout << "Character array before swapping:" << ch << endl;
    reverseCharArray(ch);
    cout << "Character array after swapping:" << ch << endl;
}