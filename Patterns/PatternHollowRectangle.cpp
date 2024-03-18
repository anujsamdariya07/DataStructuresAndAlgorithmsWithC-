#include <iostream>

using namespace std;

int main()
{
    int length, breadth;

    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    for(int row = 0 ; row < breadth ; row++)
    {
        for(int column = 0 ; column < length ; column++)
        {   
            if(row == 0 || row == breadth - 1)
            {
                cout << "* ";
            } else
            {
                if(column == 0 || column == length -1)
                {
                    cout << "* ";
                } else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}