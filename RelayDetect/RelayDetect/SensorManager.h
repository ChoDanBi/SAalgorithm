#pragma once
#include "header.h"

class SensorManager
{
private:
	static SensorManager* Instance;
public:
	static SensorManager* GetInstance() {
		if (Instance == nullptr) Instance = new SensorManager;
		return Instance;
	}

private:
	int Range;
	int Detect;
	int Send;

	vector<vector<int>> Board;
	vector<Vec2*> Sensor;

public:
	void Init(int _range, int _detect, int _send);

private:
	void SetSensor();
	void SetBoard();
	void Release();

public:
	int* GetRange() { return &Range; }
	int* GetDetect() { return &Detect; }
	int* GetSend() { return &Send; }
	vector<vector<int>>* GetBoard() { return &Board; }
	vector<Vec2*>* GetSensor() { return &Sensor; }

public:
	void ShowBoard();

private:
	SensorManager() { }
public:
	~SensorManager() { Release(); }
};

