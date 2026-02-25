#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
    List myList;

    myList.headPush(10);
    myList.headPush(20);
    myList.tailPush(30);
    myList.tailPush(40);

    cout << "List: ";
    myList.printList();   

    cout << "Pop head: " << myList.headPop() << endl;
    cout << "Pop tail: " << myList.tailPop() << endl;

    cout << "After pops: ";
    myList.printList();

    myList.deleteNode(10);
    cout << "After deleting 10: ";
    myList.printList();

    cout << "Is 30 in list? " << (myList.isInList(30) ? "Yes" : "No") << endl;
    cout << "Is 45 in list? " << (myList.isInList(45) ? "Yes" : "No") << endl;

    return 0;
}
