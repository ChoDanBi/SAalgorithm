#pragma once
#include "header.h"

class Node
{
private:
	int Num;
	int Fit;
	vector<int> Binary;

public:	//Set
	void SetNum(int _num);
	void SetBinary(vector<int> _Binary);

public: //Get
	int GetNum() { return Num; }
	int* pGetNum() { return &Num; }
	vector<int> GetBinary() { return Binary; };
	vector<int>* pGetBinary() { return &Binary; };
	int GetFit() { return Fit; }
	int* pGetFit() { return &Fit; }

public:	//ect
	void Show();

public:	//init
	Node() {};
	Node(int _num) { SetNum(_num); }
	Node(vector<int> _binary) { SetBinary(_binary); }

private: //function
	int f(int x) { return (80 + (38 * x) - (x * x)); }
};

