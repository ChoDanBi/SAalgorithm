#pragma once
#include "header.h"

#define LINKLIST vector<pair<Vec2, set<Vec2*>>>

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
	Node(int _range);

private:

public:	//Set
	int GetRepeater() { return Fitness.first; }
	int GetHop() { return Fitness.second; }
	LINKLIST GetLinkList() { return LinkList; }

public: //Ect
	void Show();

public:
	~Node() {}
};

