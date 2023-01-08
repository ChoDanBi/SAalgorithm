#pragma once
#include "Node.h"

class NodeFactory
{
public:	//Create Node
	static Node* CreateNode(int _num) { return new Node(_num); }
	static Node* CreateNode(vector<int> _binary) { return new Node(_binary); }

public:	//Create Near Node
	static Node* CreateNearNode(Node* _node);
	static Node* CreateNearNode(Node* _node, const int& ind);

	static Node* CreateNearNode(vector<int> _binary);
	static Node* CreateNearNode(vector<int> _binary, const int& ind);

public:	//Create Random Node
	static Node* CreateRandomNode(int _max);

public:	//Release Node
	static void SafeDelet(Node* _node);

public:	//Get Random Num
	static int GetRand(int _max);
	static int GetRand(int _min, int _max);
};

