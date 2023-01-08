#pragma once
#include "header.h"
#include "Node.h"

class Node;
class NodeManager
{
private:
	static NodeManager* Instance;

public:
	static NodeManager* GetInstance() {
		if (Instance == NULL)
			Instance = new NodeManager();
		return Instance;
	}

private:
	int Range;
	Node* currentNode;

public:	//Init
	void Init(const int& _range);
	void Init(const int& _range, const int& _num);

public:	//Range - Get&Set
	void SetRange(int _range) { Range = _range; }
	int GetRange() { return Range; }

public:	//Node - Get&Set
	void SetCurNode(Node* _node);
	Node* GetCurNode() { return currentNode; }

	int GetCurNum() { return currentNode->GetNum(); }
	int* pGetCurNum() { return currentNode->pGetNum(); }

	int GetCurFit() { return currentNode->GetFit(); }
	int* pGetCurFit() { return currentNode->pGetFit(); }

	vector<int> GetCurBinary() { return currentNode->GetBinary(); }
	vector<int>* pGetCurBinary() { return currentNode->pGetBinary(); }

public:	//Ect
	void ShowCurNode();

public:	//Release
	void Release();


private:
	NodeManager() : Range(1), currentNode(nullptr) {};
public:
	~NodeManager() {};
};

