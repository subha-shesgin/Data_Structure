
#include <iostream>
#include <list>
using namespace std;

int main() {
    // *****************************************************
  
    // LinkedList = Nodes are in 2 parts (data + address)
    //              Nodes are in non-consecutive memory locations
    //              Elements are linked using pointers

    // Advantages:
    // 1. Dynamic Data Structure (allocates needed memory while running)
    // 2. Insertion and Deletion of Nodes is easy. O(1)
    // 3. No/Low memory waste
  
    // Disadvantages:
    // 1. Greater memory usage (additional pointer)
    // 2. No random access of elements (no index [i])
    // 3. Accessing/searching elements is more time consuming. O(n)
  
    // Uses:
    // 1. Implement Stacks/Queues
    // 2. GPS navigation
    // 3. Music playlist

    // *****************************************************
  
    list<string> linkedList;
  
    // LinkedList as a Queue
    linkedList.push_back("A");
    linkedList.push_back("B");
    linkedList.push_back("C");
    linkedList.push_back("D");
    linkedList.push_back("F");
  
    // Uncomment to remove an element from the front (similar to poll in Java)
    // linkedList.pop_front();
  
    // Uncomment to add an element at a specific position (similar to add in Java)
    // auto it = linkedList.begin();
    // advance(it, 4); // Move to 5th element (index 4)
    // linkedList.insert(it, "E");

    // Uncomment to remove a specific element
    // linkedList.remove("E");

    // Access elements from front and back (similar to peekFirst and peekLast in Java)
    // cout << linkedList.front() << endl;
    // cout << linkedList.back() << endl;
  
    // Uncomment to add elements at the front and back
    // linkedList.push_front("0");
    // linkedList.push_back("G");

    // Uncomment to remove first and last elements
    // string first = linkedList.front();
    // string last = linkedList.back();
    // linkedList.pop_front();
    // linkedList.pop_back();

    // Printing the list
    for (auto item : linkedList) {
        cout << item << " ";
    }
    cout << endl;
  
    return 0;
}
