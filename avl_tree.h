#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

template <typename T> class AVLTree : public Tree<T>
{
public:
	struct node
	{
		T Data;
		int height;
		node* left;
		node* right;
	};

	node* root;

	AVLTree(Strategy<T>* compare);
	~AVLTree();

	int bsheight(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	node* rotateright(node* p);
	node* rotateleft(node* q);
	node* balance(node* p);
	node* insert(node* p, T data);
	void insert_(T data);
	node* findmin(node* p);
	node* removemin(node* p);
	node* remove(node* p, T k);
	void remove_(T k);
	void inorder(node* p);
	void inorder_();
	node* findnode(node* p, T data);
	void findnode_(T data);
	void change(node* p, int k);
	node* create_node(T k);
};

template<typename T> AVLTree<T>::AVLTree(Strategy<T>* compare) : Tree<T>::Tree(compare)
{
	root = nullptr;
}

template<typename T> AVLTree<T>::~AVLTree()
{

}

template<typename T> int AVLTree<T>::bsheight(node* p)
{
	int t;
	if (!p)
		return 0;
	else
	{
		t = p->height;
		return t;
	}
}

template<typename T> int AVLTree<T>::bfactor(node* p)
{
	return bsheight(p->right) - bsheight(p->left);
}

template<typename T> void AVLTree<T>::fixheight(node* p)
{
	int hl = bsheight(p->left);
	int hr = bsheight(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::rotateright(node* p)
{
	node* q = p->left;
	if (root == p) root = q;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::rotateleft(node* q)
{
	node* p = q->right;
	if (root == q) root = p;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::balance(node* p)
{
	fixheight(p);
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	return p; // балансировка не нужна
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::create_node(T k)
{
	node* new_node = new node;
	new_node->Data = k; new_node->left = new_node->right = 0; new_node->height = 1;
	return new_node;
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::insert(node* p, T data)
{
	if (!root)
	{
		root = create_node(data);
		return root;
	}
	if (!p) return create_node(data);
	if (this->comparator->compare(data, p->Data) < 0)
		p->left = insert(p->left, data);
	else if(this->comparator->compare(data, p->Data) > 0)
		p->right = insert(p->right, data);
	else
		return p;
	return balance(p);
}

template<typename T> void AVLTree<T>::insert_(T data)
{
	insert(root, data);
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::findmin(node* p)
{
	return p->left ? findmin(p->left) : p;
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::removemin(node* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

template<typename T> void AVLTree<T>::remove_(T k)
{
	remove(root, k);
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::remove(node* p, T data)
{
	if (!p) return 0;
	if (this->comparator->compare(data, p->Data) < 0)
		p->left = remove(p->left, data);
	else if (this->comparator->compare(data, p->Data) > 0)
		p->right = remove(p->right, data);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		if (root == p) root = nullptr;
		p = nullptr;
		if (!r) return q;
		node* min = findmin(r);
		if (!root) root = min;
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

template<typename T> void AVLTree<T>::inorder_()
{
	inorder(root);
}

template<typename T> void AVLTree<T>::inorder(node* p)
{
	if (!p)
		return;
	inorder(p->left);
	cout << *(p->Data) << endl;
	inorder(p->right);
}

template<typename T>typename AVLTree<T>::node* AVLTree<T>::findnode(node* p, T data)
{
	if (!p)
	{
		cout << "Element not found!" << endl;
		return NULL;
	}
	else if (this->comparator->compare(data, p->Data) < 0)
	{
		return findnode(p->left, data);
	}
	else if (this->comparator->compare(data, p->Data) > 0)
	{
		return findnode(p->right, data);
	}
	else
	{
		return p;
	}
}

template<typename T> void AVLTree<T>::findnode_(T data)
{
	if (findnode(root, data)) cout << *(findnode(root, data)->Data) << endl;
}

template<typename T> void AVLTree<T>::change(node* p, int k)
{
	if (p)
		p->key = k;
}