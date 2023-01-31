#pragma once

#define SMINS SensorManager::GetInstance()
#define SENSOR SensorManager::GetInstance()->GetSensor()

typedef struct Vector2
{
	int y;
	int x;
	Vector2(int _y, int _x) : y(_y), x(_x) {};
} Point;

static bool cmp(const Point* v1, const Point* v2)
{
	if (v1->y == v2->y)
		return v1->x < v2->x;
	return v1->y < v2->y;
}

template <typename T>
inline void SafeDelet(T _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}