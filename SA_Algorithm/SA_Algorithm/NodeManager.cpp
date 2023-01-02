#include "NodeManager.h"
#include "NodeFactory.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(double _t, int _x)
{
	T = _t;
	SetcurNode(NodeFactory::CreateNode(_x));
	cout << "�ʱ���: "; curNode->show(); cout << endl;
}

void NodeManager::Init(double _t, int _min, int _max)
{
	T = _t;
	SetcurNode(
		NodeFactory::CreateNode(
			NodeFactory::GetRand(_min, _max)));
	cout << "�ʱ���: "; curNode->show(); cout << endl;
}


void NodeManager::SetcurNode(Node* _node)
{
	if (curNode != nullptr)
		delete curNode;
	curNode = _node;
}

void NodeManager::CmpNodes()
{
	vector<int> b = curNode->GetBinary();
	for (int i = 0; i < b.size(); ++i) {
		Node* node = MakeCmpNode(b, i);


	}
}

Node* NodeManager::MakeCmpNode(Node* node,const int &ind)
{
	return MakeCmpNode(node->GetBinary(),ind);
}

Node* NodeManager::MakeCmpNode(vector<int> _binary,const int &ind)
{
	return nullptr;
}

