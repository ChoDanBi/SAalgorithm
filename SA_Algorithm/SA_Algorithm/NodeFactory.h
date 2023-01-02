#pragma once
#include "NodeManager.h"

class NodeFactory
{
public:
	//���� �� ��������
	static int GetRand(int _max);
	static int GetRand(int _min, int _max);

	//�Ϲ� ������Ʈ �����
	static Node* CreateNode(int _num);
	static Node* CreateNode(vector<int> _binary);
};

