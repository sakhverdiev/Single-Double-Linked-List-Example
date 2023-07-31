#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;

	Node() :data(), next(), prev() {}
	Node(const T& _data) :data(_data), next(), prev() {}
};


template<class T>
class DoubleLinkedList
{
	Node<T>* head;   // en birinci element
	Node<T>* tail;  // en sonuncu element
public:

	DoubleLinkedList() :head(), tail() {}

	// push_front
	void push_front(T data)
	{
		push_front(new Node<T>(data));
	}
	void push_front(Node<T>* node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}
		node->next = head;
		head->prev = node;
		head = node;
	}

	// push_back
	void push_back(T data)
	{
		push_back(new Node<T>(data));
	}
	void push_back(Node<T>* node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}

		node->prev = tail;
		tail->next = node;

		tail = node;
	}

	// insert_before // Arasdirin ve analiz edin
	void insert_before(Node<T>* node, T data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = node;

		if (node != head)
		{
			node->prev->next = newNode;
		}

		temp->prev = newNode;
		newNode->next = temp;
	}
	// insert_after  node->next
	void insert_after(Node<T>* node, T data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = node;

		if (node != tail)
		{
			node->next->prev = newNode;
			newNode->next = node->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
	}

	// pop_front
	void pop_front()
	{
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}

		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
	// pop_back
	void pop_back()
	{
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}


		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;

	}
	// search
	Node<T>* search(T data)
	{
		Node<T>* temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == data)
			{
				return temp;
			}
			temp = temp->next;
		}

		if(temp->data == data)
		{
			return temp;
		}

		return NULL;
	}

	// displayFront
	void displayFront()
	{
		Node<T>* temp = head;
		cout << "[";
		while (temp->next != NULL)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << "]" << endl;
	}
	// displayBack
	void displayBack()
	{
		Node<T>* temp = tail;
		cout << "[";
		while (temp->prev != NULL)
		{
			cout << temp->data << ", ";
			temp = temp->prev;
		}
		cout << temp->data << "]" << endl;
	}
};


int main(){
	string name_1 = "Vusal";
	string name_2 = "Hesen";
	string name_3 = "Huseyn";
	string name_4 = "Nezrin";
	string name_5 = "Rovshen";
	string name_6 = "Ramazan";

	DoubleLinkedList<string> list;
	list.push_back(name_1);
	list.push_back(name_2);
	list.push_back(name_3);
	list.push_front(name_4);
	list.push_front(name_5);
	list.push_front(name_6);

	list.displayFront();
	list.displayBack();

}