#include "rbtree.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define parent(x) ((x)->parent)
#define grandParent(x) ((x)->parent->parent)

/*
 * �Ժ�����Ľ��(x)��������ת
 *
 *
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(����)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 *
 *
 */
void rotate_left(RBTree* tree, TreeNode* x) {
	TreeNode* y = x->right;
	// ����x���Һ���Ϊy
	x->right = y->left;

	// �� ��y�����ӡ� ��Ϊ ��x���Һ��ӡ���
	// ���y�����ӷǿգ��� ��x�� ��Ϊ ��y�����ӵĸ��ס�
	if (y->left != NULL) {
		y->left->parent = x;
	}

	// // �� ��x�ĸ��ס� ��Ϊ ��y�ĸ��ס�
	y->parent = x->parent;

	if (x->parent == NULL) {
		tree->root = y; //  ��� ��x�ĸ��ס� �ǿսڵ㣬��y��Ϊ���ڵ�
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
 * �Ժ�����Ľ��(y)��������ת
 *
 * ����ʾ��ͼ(�Խ��y��������)��
 *            py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(����)-->            /  \
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
			// case 1: �������Ǻ�ɫ
			if (uncle != NULL && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				grandParent->color = RED;
				node = grandParent;
				continue;
			}
			// case 2: �������Ǻ�ɫ, �ҵ�ǰ������Һ���
			if (node == parent->right) {
				node = parent;
				rotate_left(tree, node);
			}
			// case 3: ��ǰ��������ӣ����������Ǻ�ɫ
			grandParent(node)->color = RED;
			parent(node)->color = BLACK;
			rotate_right(tree, grandParent(node));
		}
		else {
			TreeNode* uncle = grandParent->left;
			// case 1: �������Ǻ�ɫ
			if (uncle != NULL && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				grandParent->color = RED;
				node = grandParent;
				continue;
			}
			//  case 2: ��ǰ��������ӣ��������Ǻ�ɫ��
			if (node == parent->left) {
				node = parent;
				rotate_right(tree, node);
			}
			// case 3: ��ǰ������Һ��ӣ��������Ǻ�ɫ
			grandParent(node)->color = RED;
			parent(node)->color = BLACK;
			rotate_left(tree, grandParent(node));
		}
	}
	// ���������Ϊ��ɫ
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
	// �ҵ��˲����λ��, �����½��
	TreeNode* node = (TreeNode*)calloc(1, sizeof(TreeNode));
	if (node == NULL) {
		printf("Error: malloc failed in RBTree_insert.\n");
		exit(1);
	}
	node->key = key;
	// node->color = RED;
	// ������
	node->parent = prev;
	if (prev == NULL)
		tree->root = node;
	else if (key < prev->key)
		prev->left = node;
	else
		prev->right = node;
	// �����޶�Ϊһ�ź����
	rbtree_insert_fixup(tree, node);
}

void inOrder(TreeNode* root) {
	// �߽�����
	if (root == NULL) return;
	// ����������
	inOrder(root->left);
	// ���������
	printf("%c ", root->key);
	// ����������
	inOrder(root->right);
}


void RBTree_inOrder(RBTree* tree) {
	// ί���������ʵ��
	inOrder(tree->root);
}

void RBTree_levelOrder(RBTree* tree) {
	if (tree->root == NULL) return;
	Queue* q = Queue_create();
	// ������������
	enqueue(q, tree->root);
	while (!isEmpty(q)) {
		// ������
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
	// ���������
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
	// ����������
	root->left = build(preOrder + 1, inOrder, idx);
	// ����������
	root->right = build(preOrder + idx + 1, inOrder + idx + 1, len - idx - 1);
	return root;
}

RBTree* RBTree_build(char* preOrder, char* inOrder, int len) {
	RBTree* tree = (RBTree*)calloc(1, sizeof(RBTree));
	// �������н�㣬���Ѵ�����ĸ���㸳ֵ�� tree->root;
	tree->root = build(preOrder, inOrder, len);
	return tree;
}
