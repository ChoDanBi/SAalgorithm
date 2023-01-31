#pragma once
#include "header.h"

class NodeFunction
{
public:	//Init
	void Init(vector<Vec2*>* Relay, vector<int, int>* Matching);

public:	//functions
	bool Linked(Vector2 _vec, int _num);



private:
	void Release() { }

public:
	//�ʱ��� �����
	NodeFunction(vector<Vec2*>* Relay, vector<int, int>* Matching) { Init(Relay, Matching); }

	~NodeFunction() { Release(); }
};

