#pragma once
#include "header.h"
#include "SensorManager.h"

#define LINKLIST map<Point, vector<Point*>, Point_cmp>
#define GRAPH map<Point,vector<Point>, Point_cmp>

typedef int Repeater;
typedef int Hop;

class Node
{
private:
	pair<Repeater, Hop> Fitness;

private:
	LINKLIST LinkList;
	GRAPH Graph;

public:
	Node();

private:
	//중계기 범위 안 센서들 감지
	void SerachNearSensor(Point _point, int _detect, vector<Point*>* _ispoint);
	void LinkRepeter();
	void CmpDisSensor();
	vector<int> FindRange(Point _point, int _detect);


public:	//Set
	int GetRepeater() { return Fitness.first; }
	int GetHop() { return Fitness.second; }
	LINKLIST* GetLinkList() { return &LinkList; }
	GRAPH* GetGraph() { return &Graph; }

public: //Ect
	void ShowSensor();
	void ShowRepeater();

private:
	void Release() { LinkList.clear();}

public:
	~Node() { Release(); }
};

