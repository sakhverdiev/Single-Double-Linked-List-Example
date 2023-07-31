#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
    string data;
    Node* next;

    Node() : data(), next() {}
    Node(const string& _data) : data(_data), next() {}
};

class SingleLinkedList
{
    Node* head;

public:
    SingleLinkedList() : head() {}

    void AddBegin(Node*& item);
    void AddEnd(const string& item);
    void DeleteBegin();
    void DeleteEnd();
    void DeleteByValue(const string& item);
    Node* SearchValue(const string& item);
    void Display();
};

void SingleLinkedList::AddBegin(Node*& item)
{
    Node* newNode = new Node(item->data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void SingleLinkedList::AddEnd(const string& item)
{
    Node* newNode = new Node(item);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void SingleLinkedList::DeleteBegin()
{
    if (head == nullptr) {
        assert(!"List is Empty");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void SingleLinkedList::DeleteEnd()
{
    if (head == nullptr) {
        assert(!"List is Empty");
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    delete temp;
    prev->next = nullptr;
}

void SingleLinkedList::DeleteByValue(const string& item)
{
    if (head == nullptr) {
        assert(!"List is Empty");
    }

    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == item) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item not found in the list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

Node* SingleLinkedList::SearchValue(const string& item)
{
    if (head == nullptr) {
        assert(!"List is Empty");
    }

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == item) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

void SingleLinkedList::Display()
{
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "[";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << ", ";
        }
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main() {
	Node* a = new Node("Vusal");
	Node* b = new Node("Ilkin");
	Node* c = new Node("Cavid");
	Node* d = new Node("Hesen");
	Node* e = new Node("Huseyn");

	string name_1 = "Ramazan";
	string name_2 = "Rafiyev";

	SingleLinkedList list;
	list.AddBegin(a);
	list.AddBegin(b);
	list.AddBegin(c);
	list.AddBegin(d);
	list.AddBegin(e);
	list.AddEnd(name_1);
	list.AddEnd(name_2);
	
	list.Display();
}