#pragma once
#include "header.h"
#include "Node.h"

#define E 2.718281

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
	double T;
	Node* curNode;		//���� ���

public:
	void Init(double  _t, int _x);
	void Init(double _t, int _min, int _max);

	//������Ʈ
	void SetcurNode(Node* _node);
	void ShowCurNode() { curNode->show(); }

	int GetcurNodeNum() { return curNode->GetNum(); }
	int GetcurNodeFit() { return curNode->GetFit(); }
	Node* GetcurNode() { return curNode; }

	//��� ���ϱ�
	void CmpNodes();
	//��� �����
	Node* MakeCmpNode(Node* node,const int &ind);
	Node* MakeCmpNode(vector<int> _binary,const int &ind);
	//�ۼ�Ʈ ���ϱ�
	double GetPercent(Node* node, int d) { return pow(E, -(d / T)); }

private:
	NodeManager() {};
public:
	~NodeManager() {};
};

