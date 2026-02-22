#include <iostream>
#include "list.h"


List::~List() {
	for(Node *p; !isEmpty(); ){
		p=head->next;
		delete head;
		head=p;
	}
}