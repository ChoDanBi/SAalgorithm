#pragma once
#include "Node.h"

class NodeFactory
{
public:	//Create Node
	static Node* CreateNode(const int& _num) { return new Node(_num); }
	static Node* CreateNode(const int& _num, const int& _size) { return new Node(_num, _size); }

	static Node* CreateNode(const vector<int> &_binary) { return new Node(_binary); }
	static Node* CreateNode(const vector<int> &_binary, const int& _size) { return new Node(_binary, _size); }

public:	//Create Near Node
	static Node* CreateNearNode(Node* _node, const int& _ind);
	static Node* CreateNearNode(Node* _node, const int& _ind, const int& _size);

	static Node* CreateNearNode(vector<int> _binary, const int& _ind);
	static Node* CreateNearNode(vector<int> _binary, const int& _ind, const int& _size);

public:	//Create Random Node
	static Node* CreateRandomNode(const int& _max);
	static Node* CreateRandomNode(const int& _max, const int& _size);
};

