#include "NodeFactory.h"
#include <random>

Node* NodeFactory::CreateNearNode(Node* _node, const int& _ind)
{
	vector<int> binary = _node->GetBinary();
	binary[_ind] = binary[_ind] == 1 ? 0 : 1;
	return CreateNode(binary);
}

Node* NodeFactory::CreateNearNode(Node* _node, const int& _ind, const int& _size)
{
	vector<int> binary = _node->GetBinary();
	binary[_ind] = binary[_ind] == 1 ? 0 : 1;
	return CreateNode(binary, _size);
}

Node* NodeFactory::CreateNearNode(vector<int> _binary, const int& _ind)
{
	_binary[_ind] = _binary[_ind] == 1 ? 0 : 1;
	return CreateNode(_binary);
}

Node* NodeFactory::CreateNearNode(vector<int> _binary, const int& _ind, const int& _size)
{
	_binary[_ind] = _binary[_ind] == 1 ? 0 : 1;
	return CreateNode(_binary, _size);
}

Node* NodeFactory::CreateRandomNode(const int& _max)
{
	int num = GetRand(_max);
	return CreateNode(num);
}

Node* NodeFactory::CreateRandomNode(const int& _max, const int& _size)
{
	int num = GetRand(_max);
	return CreateNode(num, _size);
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


