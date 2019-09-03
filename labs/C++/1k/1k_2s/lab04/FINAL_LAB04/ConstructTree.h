#ifndef CONSTRUCT_TREE_H
#define CONSTRUCT_TREE_H

#include "AFuntions.h"

class node // tree
{
public:
	string data;
	node *left = NULL, *right = NULL;
	node() {};
	node(string x)
	{
		data = x;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
		c == '*' || c == '/' ||
		c == '^')
		return true;
	return false;
}

void inorder(node *root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

node* newNode(char v)
{
	node *temp = new node;
	temp->left = temp->right = NULL;
	temp->data = v;
	return temp;
};

// Returns root of constructed tree for given 
// postfix expression 
node* constructTree(char postfix[])
{
	List<node *> st;
	node *t, *t1, *t2;

	// Traverse through every character of 
	// input expression 
	for (size_t i = 0; i < strlen(postfix); i++)
	{
		// If operand, simply push into stack 
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			st.push_back(t);
		}
		else // operator 
		{
			t = newNode(postfix[i]);

			// Pop two top nodes 
			t1 = st[st.GetSize()-1]; // Store top 
			st.pop_back();      // Remove top 
			t2 = st[st.GetSize() - 1]; // Store top 
			st.pop_back();

			//  make them children 
			t->right = t1;
			t->left = t2;

			// Add this subexpression to stack 
			st.push_back(t);
		}
	}

	//  only element will be root of expression 
	// tree 
	t = st[st.GetSize() - 1];
	st.pop_back();

	return t;
}

#endif