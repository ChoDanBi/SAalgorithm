#include "NodeManager.h"
#include "NodeFactory.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(const int& _range)
{
	Range = _range;
	currentNode = NF::CreateNode(NF::GetRand(_range));
	cout << "Start - "; ShowCurNode();
}

void NodeManager::Init(const int& _range, const int& _num)
{
	Range = _range;
	currentNode = NF::CreateNode(_num);
	cout << "Start - "; ShowCurNode();
}

void NodeManager::SetCurNode(Node* _node)
{
	Release();
	currentNode = _node;
	_node = nullptr;
}

void NodeManager::ShowCurNode() { currentNode->Show(); }

void NodeManager::Release()
{
	if (currentNode == nullptr) return;
	DEL(currentNode);
}