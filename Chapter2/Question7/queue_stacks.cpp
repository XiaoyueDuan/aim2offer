#include <stack>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;
#define cin fin
fstream fin("input.txt");

template <typename T>
class CQueue
{
public:
	CQueue() {}
	~CQueue() {}

	void appendTail(const T&node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> 
void CQueue<T>::appendTail(const T &node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	while (!stack1.empty())
	{
		T &topNodeOfStack1 = stack1.top();
		stack2.push(topNodeOfStack1);
		stack1.pop();
	}

	try 
	{
		if (stack2.size() == 0)
			throw exception("queue is empty");
		T returnNode = stack2.top();
		stack2.pop();
		return returnNode;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	int nLines = 0;
	cin >> nLines;
	while (nLines-->0)
	{
		CQueue<int> queue;
		queue.deleteHead();
		int num;
		cin >> num;
		while (num-->0)
		{
			int n;
			cin >> n;
			queue.appendTail(n);
		}
		queue.deleteHead();
	}
	return 0;
}
