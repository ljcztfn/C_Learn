// 接口
#include <stdbool.h>

#define RED false
#define BLACK true

typedef char T;

typedef struct TreeNode_s {
	bool color;
	T key;
	struct TreeNode_s* left;
	struct TreeNode_s* right;
	struct TreeNode_s* parent;
}TreeNode;

typedef struct {
	TreeNode* root;
} RBTree;

RBTree* RBTree_create();
void RBTree_insert(RBTree* tree, T key);
// 遍历
void RBTree_preOrder(RBTree* tree);
void RBTree_inOrder(RBTree* tree);
void RBTree_postOrder(RBTree* tree);
void RBTree_levelOrder(RBTree* tree);
// 建树
RBTree* RBTree_build(char* preOrder, char* inOrder);