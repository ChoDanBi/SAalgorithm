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

	int Send;
	int Detect;

	vector<vector<int>> Board;
	map<int, Vector2> Sensor;
	Vector2 Base[2];

	Node* currentNode;

public:	//Init
	void Init(const int& _range, const int& _send, const int& _detect);
	void Init(const int& _range, const int& _send, const int& _detect, const int& _num);

public:	//Get&Set
	void SetRange(int _range) { Range = _range; }
	int GetRange() { return Range; }

	void SetSize() { Size = 1; int p = 2; while (Range > p) { ++Size; p *= 2; } }
	int GetSize() { return Size; }

	void SetSend(int _send) { Send = _send; }
	int GetSend() { return Send; }

	void SetDetect(int _detect) { Detect = _detect; }
	int GetDetect() { return Detect; }

	vector<vector<int>>* GetBoard() { return &Board; }
	void SetBorad();

	map<int, Vector2>* GetSensor() { return &Sensor; }

	Vector2* GetBase0() { return &Base[0]; }
	Vector2* GetBase1() { return &Base[1]; }

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
	void ShowBoard();

public:	//Release
	void DelCurNode() { SafeDelet(currentNode); }
	void Release();

private:
	NodeManager() : Range(0), Size(0), Send(0), Detect(0), currentNode(nullptr) {};
public:
	~NodeManager() { Release(); }
};

