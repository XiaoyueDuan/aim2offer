/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;

		TreeNode *tail = nullptr;
		ConvertNode(pRootOfTree, tail);

		// go to head
		while (tail->left != nullptr)
			tail = tail->left;

		return tail;
	}

	void ConvertNode(TreeNode *pRootofTree, TreeNode *&tail)
	{
		if (pRootofTree == nullptr)
			return;

		// left
		ConvertNode(pRootofTree->left, tail);
		pRootofTree->left = tail;
		if (tail != nullptr)
			tail->right = pRootofTree;

		//right
		tail = pRootofTree;
		ConvertNode(pRootofTree->right, tail);
	}
};