
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(nullptr), right(nullptr) {
//}
//};

bool Error_occur = false;

#include <queue>
using namespace std;

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
	TreeNode *level1stFind(TreeNode *toFind, queue<TreeNode*> &treeQueue);
	bool compare2Trees(TreeNode *Tree1, TreeNode *Tree2);
};

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	queue<TreeNode*> treeQueue;
	treeQueue.push(pRoot1);

	while (true) {
		TreeNode* node = level1stFind(pRoot2, treeQueue);
		if (node == nullptr)
			return false;

		if (compare2Trees(node, pRoot2))
			return true;
	}
}

TreeNode* Solution::level1stFind(TreeNode *toFind, queue<TreeNode*> &treeQueue) {
	if (toFind == nullptr) {
		Error_occur = true;
		return nullptr;
	}

	while (!treeQueue.empty()) {
		TreeNode *node = treeQueue.front();
		treeQueue.pop();

		if (node->left != nullptr)
			treeQueue.push(node->left);
		if (node->right != nullptr)
			treeQueue.push(node->right);

		if (node->val == toFind->val)
			return node;
	}
	return nullptr;
}

bool Solution::compare2Trees(TreeNode *Tree1, TreeNode *Tree2) {
	// whether Tree2 is the subtree of Tree1
	if (Tree2 == nullptr)
		return false;// 空树不是任意一个树的子结构

	if (Tree1 == nullptr&&Tree2 != nullptr)
		return false;

	// inorder iterate        
	if (Tree1->val != Tree2->val)
		return false;

	if (Tree2->left != nullptr)
		if (!compare2Trees(Tree1->left, Tree2->left))
			return false;

	if (Tree2->right != nullptr)
		if (!compare2Trees(Tree1->right, Tree2->right))
			return false;

	// both left and right subTree equals, Tree2 is the subTree of Tree1
	return true;
}