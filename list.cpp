#include <iostream>
#include "list.h"
using namespace std;

List::~List() {
    for (Node* p; !isEmpty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

int List::isEmpty() {
    return head == nullptr;
}

void List::headPush(int el) {
    Node* newNode = new Node(el);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void List::tailPush(int el) {
    Node* newNode = new Node(el);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int List::headPop() {
    if (isEmpty()) {
        cout << "List is empty!" << endl;
        return -1;
    }
    int val = head->info;  
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) tail = nullptr;
    return val;
}

int List::tailPop() {
    if (isEmpty()) {
        cout << "List is empty!" << endl;
        return -1;
    }
    int val = tail->info;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    return val;
}

void List::deleteNode(int val) {
    if (isEmpty()) return;

    if (head->info == val) {
        headPop();
        return;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->info != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr) {
        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
    }
}

bool List::isInList(int val) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->info == val) return true;
        temp = temp->next;
    }
    return false;
}

void List::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->info << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
