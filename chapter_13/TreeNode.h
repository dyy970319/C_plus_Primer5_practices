#include <iostream>
#include <string>

using namespace std;

class TreeNode{
	public:
		TreeNode(string s,int i,TreeNode *l,TreeNode *r)
			:value(s),count(i),left(l),right(r){}
		TreeNode(const TreeNode&tn)
			:value(tn.value),count(tn.count){
			auto newL = *tn.left;
			*left = newL;
			auto newR = *tn.right;
			*right = newR;
		}
		TreeNode& operator=(const TreeNode&tn)
		{
			value = tn.value;
			count = tn.count;
			auto newL = *tn.left;
			*left = newL;
			auto newR = *tn.right;
			*right = newR;
			return *this;
		}
		~TreeNode(){
			delete left,right;
		}
	private:
		string value;
		int count;
		TreeNode *left;
		TreeNode *right;
};