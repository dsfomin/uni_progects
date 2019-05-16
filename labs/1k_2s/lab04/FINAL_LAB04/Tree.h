#ifndef TREE_H
#define TREE_H

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

#endif
