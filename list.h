#ifndef LIST
#define LIST

class Node {
public:
	int info;
	Node* next;
	Node(int el, Node *ptr = 0) { info = el; next = ptr; }
};

class List {
public:
	List() { head = tail = 0; }
	~List();
	int isEmpty();
	void headPush(int); //Add element to front of list
	void tailPush(int); //Add element to tail of list
	int headPop(); //Remove and return element from front of list
	int tailPop(); //Remove and return element from tail of list
	void deleteNode(int); //Delete a particular value
	bool isInList(int); //Check if a particular value is in the list
	void printList();

private:
	Node *head, *tail;
};

#endif //LIST