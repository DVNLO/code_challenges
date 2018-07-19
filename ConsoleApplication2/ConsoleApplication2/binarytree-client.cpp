
// Here is the file binarytree-client.cpp
#include "stdafx.h"
#include <iostream>
#include "binarytree.h"
using namespace cs_ll;
using namespace std;

int main() {
    binarytree list;
    
    int num;
    bool found;
    
    cout << "enter number to insert (negative to quit): ";
    cin >> num;
    while (num >= 0){
        list.insert(num);
        cout << "enter number to insert (negative to quit): ";
        cin >> num;
    }
    
    list.print();
    cout << endl;
    
    binarytree::size_type numItems;
    numItems = list.size();
    cout << "There are " << numItems << " items." << endl;
    
    
    
    cout << "enter a number to find (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        int result = list.find(num, found);
        if (!found) {
            cout << "not found" << endl;
        } else {
            cout << "found.  The data is " << result << endl;
        }
        cout << "enter a number to find (negative to quit): ";
        cin >> num;
    }
    
    
    cout << "enter a number to delete (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        list.del(num, found);
        if (found) {
            cout << "the list is now ";
            list.print();
            cout << endl;
        } else {
            cout << num << " is not in the list." << endl;
        }
        cout << "enter a number to delete (negative to quit): ";
        cin >> num;
    }
    
    
    binarytree list2(list);
    
    cout << "Now list 2 should be a copy of list.  Here it is: ";
    list2.print();
    cout << endl;
    
    
    list2.del(3, found);
    
    
    cout << "After deleting a 3 from list2, list2 is now: ";
    list2.print();
    cout << endl << "list should be unchanged.  Here it is: ";
    list.print();
    cout << endl;
    
    list = list2;
    
    cout << "Now list has been assigned list2 so it should match list2.  Here it is: ";
    list.print();
    cout << endl;
    
    list.del(4, found);
    
    cout << "After deleting a 4 from list, list is now: ";
    list.print();
    cout << endl << "list2 should be unchanged.  Here it is: ";
    list2.print();
    cout << endl;
    
}
