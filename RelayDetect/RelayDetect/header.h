#pragma once

#include <iostream>
#include <vector>
#include <map>
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
	Vector2(int _y, int _x) : y(_y), x(_x) {}

	bool operator == (const Vector2& p) const { return tie(y, x) == tie(p.y, p.x); }
} Point;

typedef struct Vector2_cmp
{
	bool operator()(const Vector2& p1, const Vector2& p2) const
	{
		if (p1.y == p2.y) return p1.x < p2.x;
		return p1.y < p2.y;
	}
}Point_cmp;

static bool cmp(const Point* v1, const Point* v2)
{
	if (v1->y == v2->y)
		return v1->x < v2->x;
	return v1->y < v2->y;
}


static int _Y;
static bool FindY(const Point* _point) { return _Y <= _point->y; }


template <typename T>
inline void SafeDelet(T* _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}


static int GetRand(int _min, int _max)
{
	random_device rd; mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}

static int GetRand(int _max)
{
	return GetRand(0, _max);
}