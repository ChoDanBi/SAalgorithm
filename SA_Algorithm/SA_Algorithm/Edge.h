#pragma once
#include "Node.h"

class Edge : Node
{
private:
	int SendDis;	//Send Distance
	int ReceiveDis;	//Receive Distance;

public:	//Init
	void SetNum(int _num, int _size, int _send, int _receive);
	void SetBinary(vector<int> _binary, int _size, int _send, int _receive);

public:
	virtual int func(int x);



public:
	Edge(int _num, int _size, int _send, int _receive){
		SetNum(_num, _size, _send, _receive);}
	Edge(vector<int> _binary, int _size, int _send, int _receive) {
		SetBinary(_binary, _size, _send, _receive);}
};

