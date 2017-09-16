#include <iostream>
#include <fstream>

using namespace std;
fstream fin("Input.txt");
#define cin fin

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left, *right;

	BinaryTreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

int find(const int *array, const int &value, const int &size)
{
	if (size <= 0)
		return -1;	//fail
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == value)
			return i;
	}
	return -1;		//fail
}

bool binarayTreeConstruct(BinaryTreeNode *&head, const int *preOrderTree, const int &pStartPos, const int &pEndPos,
	const int *inOrderTree, const int &iStartPos, const int &iEndPos)
{
	if (pStartPos > pEndPos || iStartPos > iEndPos)
		return true;

	if (pEndPos < 0 || iEndPos < 0)
		return false;

	int headValue = preOrderTree[pStartPos];
	int posInBinaryTree = find(&inOrderTree[iStartPos], headValue, iEndPos-iStartPos+1);
	if (posInBinaryTree == -1)
		return false;

	head = new BinaryTreeNode(headValue);
	if (binarayTreeConstruct(head->left, preOrderTree, pStartPos + 1, pStartPos + posInBinaryTree,
		inOrderTree, iStartPos, iStartPos + posInBinaryTree - 1) &&
		binarayTreeConstruct(head->right, preOrderTree, pStartPos + posInBinaryTree + 1, pEndPos,
			inOrderTree, iStartPos + posInBinaryTree + 1, iEndPos))
		return true;
}

int main()
{
	int nGroup;
	cin >> nGroup;
	int n=0;
	while (nGroup--)
	{
		int nNodes;
		cin >> nNodes;
		int *preOrderTree = new int[nNodes];
		int *inOrderTree = new int[nNodes];

		int i = 0;
		while (i < nNodes)
		{
			cin >> preOrderTree[i];
			++i;
		}

		i = 0;
		while (i < nNodes)
		{
			cin >> inOrderTree[i];
			++i;
		}

		BinaryTreeNode *head = nullptr;
		++n;
		if (!binarayTreeConstruct(head, preOrderTree, 0, nNodes-1,
			inOrderTree, 0, nNodes-1))
			cout << "Input "<< n <<": Fail to construct binary tree" << endl;
	}
	return 0;
}