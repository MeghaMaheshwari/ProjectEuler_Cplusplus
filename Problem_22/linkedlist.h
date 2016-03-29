#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Node
{
	string Data;
	Node* next;
};

class LinkedList
{
  private:
	  Node* head;
  public:
	  LinkedList();
	  void InsertData(string);
      int CalculateValue();
	  void PrintData();
};

int GetCount(string);

int Getcompare(string, string);

Node* GetNewNode(string);