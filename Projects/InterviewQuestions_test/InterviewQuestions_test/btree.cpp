#include "stdafx.h"
#include "btree.h"


btree::btree()
{
	myRoot = 1;
	root = nullptr;
	myroot = myRoot;
}


btree::~btree()
{
}

void btree::insert(int key)
{
	if (root != nullptr)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

node * btree::search(int key)
{
	return search(key, root);
}

node* btree::search(int key, node* leaf)
{
	if (leaf != nullptr)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return nullptr;
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::destroy_tree(node* leaf)
{
	if (leaf != nullptr)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node * leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != nullptr)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = nullptr;    //Sets the left child of the child node to nullptr
			leaf->left->right = nullptr;   //Sets the right child of the child node to nullptr
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != nullptr)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = nullptr;  //Sets the left child of the child node to nullptr
			leaf->right->right = nullptr; //Sets the right child of the child node to nullptr
		}
	}
}
