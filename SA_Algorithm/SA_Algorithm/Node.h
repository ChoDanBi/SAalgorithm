#pragma once
#include "header.h"

class Node
{
protected:
	vector<pair<Vector2, int>> Relay;
	pair<int, int> Fitness; //Repeater count, Hop

	int Send;
	int Detect;

	int Num;
	vector<int> Binary;	//¡Øreverse order

public:	//Init
	void Init();
	void Init(vector<pair<Vector2, int>> _relay);


public:	//Set
	void SetNum(int _num);
	void SetNum(int _num, int _size);

	void SetBinary(vector<int> _binary);
	void SetBinary(vector<int> _binary, int _size);

public: //Get
	int GetNum() { return Num; }
	int* pGetNum() { return &Num; }

	vector<int> GetBinary() { return Binary; };
	vector<int>* pGetBinary() { return &Binary; };

	int GetFit() { return Fitness.first; }
	int* pGetFit() { return &Fitness.first; }

public:	//ect
	void Show();

public:	//init

	Node(){ Init(); }
	Node(vector<pair<Vector2, int>> _relay) { Init(_relay); }

	//Node() : Num(0), Fitness(), Binary(NULL) {};

	Node(int _num) { SetNum(_num); }
	Node(int _num, int _size) { SetNum(_num, _size); }

	Node(vector<int> _binary) { SetBinary(_binary); }
	Node(vector<int> _binary, int _size) { SetBinary(_binary, _size); }

private: //function
	int func(int x) { return (80 + (38 * x) - (x * x)); }
};

