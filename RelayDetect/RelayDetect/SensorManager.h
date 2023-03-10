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
	int Size;
	int Detect;
	int Send;

	Point* Base[2];
	vector<vector<int>> Board;
	vector<Point*> Sensor;

public:
	void Init(int _size, int _detect, int _send);

private:
	void SetSensor();
	void SetBoard();
	void Release();

public:
	int GetSize() { return Size; }
	int GetDetect() { return Detect; }
	int GetSend() { return Send; }
	Point* GetFirstBase() { return Base[0]; }
	Point* GetSecondBase() { return Base[1]; }
	vector<vector<int>>* GetBoard() { return &Board; }
	vector<Point*>* GetSensor() { return &Sensor; }

public:
	void ShowBoard();
	void ShowSensor();

private:
	SensorManager(): Base(), Detect(), Size(), Send() {}
public:
	~SensorManager() { Release(); }
};

