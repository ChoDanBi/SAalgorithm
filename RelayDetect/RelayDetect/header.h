#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <random>
#include "Define.h"

using namespace std;

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