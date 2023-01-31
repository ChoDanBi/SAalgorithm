#pragma once

#define SMINS SensorManager::GetInstance()

typedef struct Vector2
{
	int x, y;
	Vector2(int _y, int _x) : y(_y), x(_x) {};
} Vec2;

template <typename T>
inline void SafeDelet(T _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}