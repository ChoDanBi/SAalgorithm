#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>
#include "Define.h"

using namespace std;

typedef struct Vector2
{
	int x, y;
	Vector2(int _y, int _x) : y(_y), x(_x) {};
} Vec2;

template <typename T>
inline void SafeDelet(T *_node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}

inline int GetRand(int _max)
{ 
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

inline int GetRand(int _min, int _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}