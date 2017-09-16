#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
fstream fin("ReversePrintLinkedList.txt");
#define cin fin

void ReversePrintLinkedList(ListNode *head)
{
	stack<ListNode *> listStack;
	ListNode *pNode = head;
	while (pNode != nullptr)
	{
		listStack.push(pNode);
		pNode = pNode->next;
	}

	while (!listStack.empty())
	{
		pNode = listStack.top();
		cout << pNode->value << " ";
		listStack.pop();
	}
	cout << endl;
}
