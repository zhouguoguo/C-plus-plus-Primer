#include <iostream>
using namespace std;

class TreeNode {
public:
	TreeNode(string str = string()) :
		value(str), count(new int(1)), left(nullptr), right(nullptr){}
	TreeNode(const TreeNode& t) :
		value(t.value), count(t.count), left(t.left), right(t.right)
		{++(*count);}
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

TreeNode& TreeNode::operator=(const TreeNode& tn)
{
	++(*tn.count);
	if (--*count == 0) {
		delete count;
		delete left;
		delete right;
	}
	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;
	return *this;
}

TreeNode::~TreeNode()
{
	if (--*count == 0)
	{
		delete count;
		delete left;
		delete right;
	}
}

class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree& bst) : root(new TreeNode(*(bst.root))) {}
	BinStrTree& operator=(const BinStrTree& bst)
	{
		TreeNode* tr = new TreeNode(*(bst.root));
		delete root;
		root = tr;
		return *this;
	}
	~BinStrTree() {delete root;}
private:
	TreeNode * root;
};

int main()
{
	BinStrTree bst, bst1;
	BinStrTree bst2(bst);
	bst1 = bst2;

}
