#include <fstream>
#include <iostream>

using namespace std;
fstream fin("LinkedList.txt");
#define cin fin

struct ListNode
{
	int value;
	ListNode *next;

	ListNode() :value(0), next(nullptr) {}
	ListNode(const int &v) : value(v), next(nullptr) {}
};

void constructList(ListNode *&head, const int const *intArray, const unsigned int &size)
{
	if (size <= 0 || intArray == nullptr)
		return;

	head = new ListNode(intArray[0]);
	ListNode *preNode = head;
	unsigned int index = 1;
	while (index<size)
	{
		ListNode *nextNode = new ListNode(intArray[index]);
		preNode->next = nextNode;
		preNode = preNode->next;
		++index;
	}	
}

void printList(const ListNode const *head)
{
	while (head != nullptr)
	{
		cout << head->value << ' ';
		head = head->next;
	}
	cout << endl;
}

void appendTail(ListNode *&head, const int &value)
{
	if (head == nullptr)
	{
		head = new ListNode(value);
		return;
	}

	ListNode *end = head;
	while (end->next != nullptr)
		end = end->next;

	end->next = new ListNode(value);
}

void deleteNode(ListNode *&head, const int &value)
{	
	if (&head == nullptr || head == nullptr)
		return;

	ListNode *pNode = head, *tobeDelete=nullptr;

	if (pNode->value == value)
	{
		head = pNode->next;
		tobeDelete = pNode;
	}
	else
	{
		while (pNode->next != nullptr&&pNode->next->value != value)
			pNode = pNode->next;

		if (pNode->next != nullptr && pNode->next->value == value)
		{
			pNode->next = pNode->next->next;
			tobeDelete = pNode->next;
		}
	}

	if (tobeDelete != nullptr)
	{
		delete tobeDelete;
		tobeDelete = nullptr;
	}		
}

int main()
{
	int N;
	cin >> N;

	while (N--)
	{
		int listLength;
		cin >> listLength;
		int *intArray = new int[listLength];
		int i = 0;
		while (i<listLength)
		{
			int newValue;
			cin >> newValue;
			intArray[i] = newValue;
			++i;
		}
		ListNode *head=nullptr;
		constructList(head, intArray, listLength);
		deleteNode(head, 1);
		printList(head);

		delete[] intArray;
		intArray = nullptr;
	}
}