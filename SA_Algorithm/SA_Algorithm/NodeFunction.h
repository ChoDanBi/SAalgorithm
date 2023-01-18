#pragma once
#include "Node.h"

class NodeFunction
{
private:
	vector<pair<Vector2, int>>* Relay;
	
public:	//Init
	void Init();
	void Init(vector<pair<Vector2, int>>* _relay);

	void SetRelay(vector<pair<Vector2, int>> _relay) { Relay = &_relay; }

public:	//link
	bool Linked(Vector2 _vec, int _num);

public:
	NodeFunction() { Init(); }
	NodeFunction(vector<pair<Vector2, int>> _relay) { Init(&_relay); }
private:
	void Release() { Relay = nullptr;}
public:
	~NodeFunction() { Release(); }
};

