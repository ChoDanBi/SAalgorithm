#pragma once
#include "header.h"
#include "Node.h"

class Factory {
public:
	static Point CreatePoint()
	{
		int Range = SMINS->GetSize() - 1;
		int y = GetRand(Range);
		int x = GetRand(Range);
		return Point(y, x);
	}

	static Point CreatePoint(int _y, int _x)
	{
		return Point(_y, _x);
	}

public:




};