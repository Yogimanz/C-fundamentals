#include "pch.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::AddNode(int value)
{
	struct node* newNode = new node();
	//newNode will be the last element inside the list so it should point to null
	newNode->next = NULL;
	newNode->data = value;
	//check if head exists and if so go to the end of the list then add a node
	if (head != NULL)
	{
		struct node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	else
		// head doesnt exist so new elements becomes the first node and head points to it
	{
		head = newNode;
	}
}

void LinkedList::AddNodeAT(int value, int index)
{
}

void LinkedList::AddElementAtFront(int value)
{
	//New node we are adding is going to replace/ be added to the start of the list 
	struct node* newNode = new node();
	newNode->data = value;
	newNode->next = head->next;
	head = newNode;
}


void LinkedList::DeleteElement(int value)
{
}

void LinkedList::DeleteElementAt(int index)
{
}

void LinkedList::ReverseList()
{
}

void LinkedList::PrintList()
{
	// go through the list and print the current element
	struct node* current = head;
	while (current->next != NULL)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}


LinkedList::~LinkedList()
{

}
