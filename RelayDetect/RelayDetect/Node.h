#pragma once
#include "header.h"
#include "SensorManager.h"

#define LINKLIST map<Point, set<Point*>>

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
	//중계기 범위 안 센서들 감지
	void SerachNearSensor(Point* _point, int* _detect, set<Point*>* _ispoint);

public:	//Set
	int GetRepeater() { return Fitness.first; }
	int GetHop() { return Fitness.second; }
	LINKLIST GetLinkList() { return LinkList; }

public: //Ect
	void Show() { cout << "Make Complete\n"; }

private:
	void Release() { LinkList.clear();}

public:
	~Node() { Release(); }
};

