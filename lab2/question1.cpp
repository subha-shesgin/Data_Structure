#include <iostream>
#include <stack>
using namespace std;


void remove(stack<int> &s, int item)
{
    stack<int> temp;
    
    
    while (!s.empty())
    {
        if (s.top() != item)
        {
            temp.push(s.top());
        }
        s.pop();
    }

   
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{
    int n = 5;
    stack<int> s;

    cout << "Enter s";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        s.push(num);
    }

    int item;
    cout << "Enter item ";
    cin >> item;

    
    stack<int> tempStack = s; 
    cout << "\nBefore removing: ";
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    
    remove(s, item);

    
    cout << "After removing: ";
    if (s.empty())
    {
        cout << "Stack is empty";
    }
    else
    {
       
        while (!s.empty())
        {
           
           tempStack.push(s.top());

           s.pop();
        }
        while(!tempStack.empty()){
            cout<<tempStack.top()<<" ";
            tempStack.pop();
        }
    }
    cout << endl;

    return 0;
}
