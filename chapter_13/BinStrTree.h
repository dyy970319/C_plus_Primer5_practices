#include "TreeNode.h"

class BinStrTree{
	public:
		BinStrTree(TreeNode *t):root(t){}
		BinStrTree(const BinStrTree& tn){
			auto temp_root = *tn.root;
			*root = temp_root;
		}
		BinStrTree operator=(const BinStrTree& tn)
		{
			auto temp_root = *tn.root;
			*root = temp_root;
			return *this;
		}
		~BinStrTree(){
			delete root;
		}
	private:
		TreeNode *root;
};