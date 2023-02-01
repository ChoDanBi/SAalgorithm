#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <random>
#include "Define.h"

using namespace std;

typedef struct Vector2
{
	int y;
	int x;
	Vector2() : y(0), x(0) {};
	Vector2(int _y, int _x) : y(_y), x(_x) {};
} Point;



static bool cmp(const Point* v1, const Point* v2)
{
	if (v1->y == v2->y)
		return v1->x < v2->x;
	return v1->y < v2->y;
}


static int _Y;
static bool FindY(const Point* _point) { return _Y <= _point->y; }


template <typename T>
inline void SafeDelet(T _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}


inline int GetRand(int _max)
{
	random_device rd; mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}

inline int GetRand(int _min, int _max)
{
	random_device rd; mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}