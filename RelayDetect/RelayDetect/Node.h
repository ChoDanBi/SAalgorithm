#pragma once
#include "header.h"

#define LINKLIST vector<pair<Point, set<Point*>>>

typedef int Repeater;
typedef int Hop;

class Node
{
private:
	pair<Repeater, Hop> Fitness;

private:
	LINKLIST LinkList;

public:
	Node();

private:
	void SerachSensor(Point* _point, int* _detect);
	Point MakeRepeater();
	

public:	//Set
	int GetRepeater() { return Fitness.first; }
	int GetHop() { return Fitness.second; }
	LINKLIST GetLinkList() { return LinkList; }

public: //Ect
	void Show();

private:
	void Release();

public:
	~Node() { Release(); }
};

