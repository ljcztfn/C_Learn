#include "rbtree.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define parent(x) ((x)->parent)
#define grandParent(x) ((x)->parent->parent)

/*
 * 对红黑树的结点(x)进行左旋转
 *
 *
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
void rotate_left(RBTree* tree, TreeNode* x) {
	TreeNode* y = x->right;
	// 设置x的右孩子为y
	x->right = y->left;

	// 将 “y的左孩子” 设为 “x的右孩子”；
	// 如果y的左孩子非空，将 “x” 设为 “y的左孩子的父亲”
	if (y->left != NULL) {
		y->left->parent = x;
	}

	// // 将 “x的父亲” 设为 “y的父亲”
	y->parent = x->parent;

	if (x->parent == NULL) {
		tree->root = y; //  如果 “x的父亲” 是空节点，则将y设为根节点
	}
	else {
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}

	y->left = x;
	x->parent = y;

}

/*
 * 对红黑树的结点(y)进行右旋转
 *
 * 右旋示意图(对结点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 *
 */
void rotate_right(RBTree* tree, TreeNode* y) {
	TreeNode* x = y->left;

	y->left = x->right;
	if (x->right != NULL) {
		x->right->parent = y;
	}

	x->parent = y->parent;
	if (y->parent == NULL) {
		tree->root = x;
	}
	else {
		if (y->parent->left == y)
			y->parent->left = x;
		else
			y->parent->right = x;
	}

	x->right = y;
	y->parent = x;
}

void rbtree_insert_fixup(RBTree* tree, TreeNode* node) {
	TreeNode* parent = node->parent;

	while (parent != NULL && parent->color == RED) {
		TreeNode* grandParent = parent->parent;

		if (parent == grandParent->left) {
			TreeNode* uncle = grandParent->right;
			// case 1: 叔叔结点是红色
			if (uncle != NULL && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				grandParent->color = RED;
				node = grandParent;
				continue;
			}
			// case 2: 叔叔结点是黑色, 且当前结点是右孩子
			if (node == parent->right) {
				node = parent;
				rotate_left(tree, node);
			}
			// case 3: 当前结点是左孩子，且叔叔结点是黑色
			grandParent(node)->color = RED;
			parent(node)->color = BLACK;
			rotate_right(tree, grandParent(node));
		}
		else {
			TreeNode* uncle = grandParent->left;
			// case 1: 叔叔结点是红色
			if (uncle != NULL && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				grandParent->color = RED;
				node = grandParent;
				continue;
			}
			//  case 2: 当前结点是左孩子，叔叔结点是黑色的
			if (node == parent->left) {
				node = parent;
				rotate_right(tree, node);
			}
			// case 3: 当前结点是右孩子，叔叔结点是黑色
			grandParent(node)->color = RED;
			parent(node)->color = BLACK;
			rotate_left(tree, grandParent(node));
		}
	}
	// 将根结点设为黑色
	tree->root->color = BLACK;
}

RBTree* RBTree_create() {
	return (RBTree*)calloc(1, sizeof(RBTree));
}

void RBTree_insert(RBTree* tree, T key) {
	TreeNode* prev = NULL;
	TreeNode* curr = tree->root;
	while (curr != NULL) {
		prev = curr;
		int cmp = key - curr->key;
		if (cmp < 0)
			curr = curr->left;
		else if (cmp > 0)
			curr = curr->right;
		else
			return;
	}
	// 找到了插入的位置, 创建新结点
	TreeNode* node = (TreeNode*)calloc(1, sizeof(TreeNode));
	if (node == NULL) {
		printf("Error: malloc failed in RBTree_insert.\n");
		exit(1);
	}
	node->key = key;
	// node->color = RED;
	// 插入结点
	node->parent = prev;
	if (prev == NULL)
		tree->root = node;
	else if (key < prev->key)
		prev->left = node;
	else
		prev->right = node;
	// 重新修订为一颗红黑树
	rbtree_insert_fixup(tree, node);
}

void inOrder(TreeNode* root) {
	// 边界条件
	if (root == NULL) return;
	// 遍历左子树
	inOrder(root->left);
	// 遍历根结点
	printf("%c ", root->key);
	// 遍历右子树
	inOrder(root->right);
}


void RBTree_inOrder(RBTree* tree) {
	// 委托这个方法实现
	inOrder(tree->root);
}

void RBTree_levelOrder(RBTree* tree) {
	if (tree->root == NULL) return;
	Queue* q = Queue_create();
	// 将根结点入队列
	enqueue(q, tree->root);
	while (!isEmpty(q)) {
		// 出队列
		TreeNode* node = dequeue(q);
		printf("%c ", node->key);
		if (node->left != NULL) {
			enqueue(q, node->left);
		}
		if (node->right != NULL) {
			enqueue(q, node->right);
		}
	}
}

TreeNode* build(char* preOrder, char* inOrder, int len) {
	char ch = *preOrder;
	// 构建根结点
	TreeNode* root = (TreeNode*)calloc(1, sizeof(TreeNode));
	root->key = ch;
	int idx = 0;
	for (; idx < len; idx++) {
		if (inOrder[idx] == ch) {
			break;
		}
	}
	// ch[1..idx][idx+1, len-1]
	// [0..idx-1]idx[idx+1, len-1]
	// 构建左子树
	root->left = build(preOrder + 1, inOrder, idx);
	// 构建右子树
	root->right = build(preOrder + idx + 1, inOrder + idx + 1, len - idx - 1);
	return root;
}

RBTree* RBTree_build(char* preOrder, char* inOrder, int len) {
	RBTree* tree = (RBTree*)calloc(1, sizeof(RBTree));
	// 创建所有结点，并把创建后的根结点赋值给 tree->root;
	tree->root = build(preOrder, inOrder, len);
	return tree;
}
