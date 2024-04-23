// Backtracking is simply recursion, the only difference being that we need to do some additional actions while returning from the recursive call.

#include<iostream>
#include<string>

using namespace std;

void printPermutations1(string str, int index)
{
    // Base condition
    if(index >= str.length()) 
    {
        cout << str << " ";
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        // Recursive Call
        swap(str[index], str[j]);
        printPermutations1(str, index+1);
    }
    
}

// Here, we will be passing the string as reference, so any change in string will result in actual chnaging of the string rather than creating a copy string unlike the above method. To minimize this we use backtracking, ie, go a step back by again swapping the string elements.
void printPermutations2(string &str, int index)
{
    // Base condition
    if(index >= str.length()) 
    {
        cout << str << " ";
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        // Recursive Call
        printPermutations2(str, index+1);
        // Backtracking step
        swap(str[index], str[j]);
    }
    
}

int main()
{
    string str = "abc";
    // cout << str;
    int index = 0;
    printPermutations1(str, index);
    cout << endl << endl;
    index = 0;
    printPermutations2(str, index);
}