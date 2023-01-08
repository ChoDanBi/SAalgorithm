#include "NodeFactory.h"
#include <random>

Node* NodeFactory::CreateNearNode(Node* _node)
{
	vector<int> binary = _node->GetBinary();
	int ind = GetRand((binary.size() - 1));
	binary[ind] = binary[ind] == 1 ? 0 : 1;
	return CreateNode(binary);
}

Node* NodeFactory::CreateNearNode(Node* _node, const int& ind)
{
	vector<int> binary = _node->GetBinary();
	binary[ind] = binary[ind] == 1 ? 0 : 1;
	return CreateNode(binary);
}

Node* NodeFactory::CreateNearNode(vector<int> _binary)
{
	int ind = GetRand((_binary.size() - 1));
	_binary[ind] = _binary[ind] == 1 ? 0 : 1;
	return CreateNode(_binary);
}

Node* NodeFactory::CreateNearNode(vector<int> _binary, const int& ind)
{
	_binary[ind] = _binary[ind] == 1 ? 0 : 1;
	return CreateNode(_binary);
}

Node* NodeFactory::CreateRandomNode(int _max)
{
	int num = GetRand(_max);
	return CreateNode(num);
}

void NodeFactory::SafeDelet(Node* _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}

int NodeFactory::GetRand(int _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

int NodeFactory::GetRand(int _min, int _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}


