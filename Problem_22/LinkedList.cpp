#include <fstream>
#include "linkedlist.h"

/*
Linkedlist constructor
*/
LinkedList::LinkedList()
	:head(NULL)
{};

/*Input Param: Val -> Value to be added to the linkedlist
  Function : Adds a new node to the linkedlist in ascending order
  Return : None
*/
void LinkedList::InsertData(string val)
{
	Node* Previous = NULL;
	if(head == NULL)
	{
		head = GetNewNode(val);
	}
	else
	{
		Node* temp = head;
		bool NodeAdded = false;
		while(temp != NULL)
		{
		   	if(val.compare(temp->Data) <= 0)            
			{
				// create the new node only when we know that we are going to insert it to save memory leak
				Node* Newnode = GetNewNode(val);
				// This means the new node must be headnode
				if(NULL == Previous)
				{
					Newnode->next = temp;
					head = Newnode;
				}
				// the new node needs to be inserted in between two nodes.
				else
				{				
					Previous->next = Newnode;
					Newnode->next = temp;				
				}
				NodeAdded = true;
				break;
			}
			// we have reached the end of the list and the value is greater than any of the existing elements, so insert this new value at the end
			if(NULL == temp->next)
			{
				temp->next = GetNewNode(val);
				break;
			}			
			Previous = temp;
			temp = temp->next;
			
		}		
	}	
};

/*Input Param:None
Function : Calculates the value of the data in the linkedlist which is the total of the value of each word multiplied 
           by its position
Return : Returns the calculated sum.
*/
int LinkedList::CalculateValue()
{
	Node* temp = head;
	int Sum = 0;
	int Counter = 1;
	while(NULL != temp)
	{
		int SubTotal = GetCount(temp->Data);
		Sum = Sum + (SubTotal * Counter);
		temp = temp->next;
		++Counter;
	}
	return Sum;
};

/*
Input Param:None
Function : Prints the data in the linkedlist
Return : None
*/
void LinkedList::PrintData()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->Data << endl;
		temp = temp->next;
	}	
}

/*Input Param: Word 
  Function : Gets the Count of the word based on the position value of its letter in the english alphabet.
  Return : Returns the value of the word.
*/
int GetCount(string Word)
{
	int Sum = 0;
	static int ascii_to_integer = 64;
	for (string::iterator it = Word.begin() ; it < Word.end(); it++)
	{
		Sum = Sum + (*it - ascii_to_integer);
	}
	return Sum;
}

/* Input Param: Val
Function : Creates a new node.
Return : Returns a new node
*/
Node* GetNewNode(string val)
{
	Node *Newnode = new Node;
	Newnode->Data = val;
	Newnode->next = NULL;
	return Newnode;
}