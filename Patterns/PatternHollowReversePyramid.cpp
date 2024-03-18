# include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    for(int i = n ; i >= 0 ; i--)
    {
        for(int j = i ; j >= 0 ; j--)
        {
            if(i == n || i == 0 || j == i || j == 0)
            {
                cout << "* ";
            } else 
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    return 0;
}