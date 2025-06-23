#include <iostream>
#include <string>

using namespace std;


void recursion(string &s, char x, char y, int n)
{
   
    if (n < 0)
        return;
    if (s[n] == x)
    {
        s[n] = y;
    }
    recursion(s, x, y, n - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char X, Y;
    cout << "Enter X,Y: ";
    cin >> X >> Y;

    int n = str.length() -1;
   
    recursion(str, X, Y, n);

   
    cout <<"after: " << str << endl;

    return 0;
}
