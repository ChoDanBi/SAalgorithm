#include "NodeManager.h"
#include "NodeFactory.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(const int& _range, const int& _send, const int& _detect)
{
	Range = _range;
	SetSize();

	Send = _send;
	Detect = _detect;

	currentNode = NF::CreateNode(GetRand(_range), Size);
	cout << "Start - "; ShowCurNode();
}

void NodeManager::Init(const int& _range, const int& _send, const int& _detect, const int& _num)
{
	Range = _range;
	SetSize();

	Send = _send;
	Detect = _detect;

	currentNode = NF::CreateNode(_num, Size);
	cout << "Start - "; ShowCurNode();
}

void NodeManager::SetCurNode(Node* _node)
{
	DelCurNode();
	currentNode = _node;
	_node = nullptr;
}

void NodeManager::ShowCurNode() { currentNode->Show(); }


void NodeManager::Release()
{
	DEL(currentNode);
	DEL(Instance);
}
