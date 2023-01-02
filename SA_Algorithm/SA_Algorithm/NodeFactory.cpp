#include "NodeFactory.h"
#include <random>

int NodeFactory::GetRand(int _max)
{
	//�õ尪�� ��� ���� rd ����
	random_device rd;
	//���� ���� ���� �ʱ�ȭ
	mt19937 gen(rd());
	//min~max������ ���� ����
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

int NodeFactory::GetRand(int _min, int _max)
{
	//�õ尪�� ��� ���� rd ����
	random_device rd;
	//���� ���� ���� �ʱ�ȭ
	mt19937 gen(rd());
	//min~max������ ���� ����
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

//������Ʈ �����
Node* NodeFactory::CreateNode(int _num)
{
	Node* node = new Node;
	node->SetNum(_num);
	return node;
}

Node* NodeFactory::CreateNode(vector<int> _binary)
{
	Node* node = new Node;
	node->SetBinary(_binary);
	return node;
}


