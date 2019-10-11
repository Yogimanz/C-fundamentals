#pragma once
class LinkedList
{
private:
	struct node {
		int data;
		struct node* next;
	};
	struct node* head;
public:
	LinkedList();
	void AddNode(int value);
	void AddNodeAT(int value, int index);
	void AddElementAtFront(int value);
	void DeleteElement(int value);
	void DeleteElementAt(int index);
	void ReverseList();
	void PrintList();

	~LinkedList();
};

