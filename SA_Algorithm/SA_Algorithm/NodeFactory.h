#pragma once
#include "NodeManager.h"

class NodeFactory
{
public:
	//랜덤 값 가져오기
	static int GetRand(int _max);
	static int GetRand(int _min, int _max);

	//일반 오브젝트 만들기
	static Node* CreateNode(int _num);
	static Node* CreateNode(vector<int> _binary);
};

