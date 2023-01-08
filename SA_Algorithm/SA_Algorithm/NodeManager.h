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
	int Size;
	Node* currentNode;

public:	//Init
	void Init(const int& _range);
	void Init(const int& _range, const int& _num);

public:	//Get&Set
	void SetRange(int _range) { Range = _range; }
	int GetRange() { return Range; }

	void SetSize() { Size = 1; while (Range > pow(2, Size)) ++Size; }
	int GetSize() { return Size; }

public:	//Node
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
	NodeManager() : Range(1), Size(1), currentNode(nullptr) {};
public:
	~NodeManager() {};
};

