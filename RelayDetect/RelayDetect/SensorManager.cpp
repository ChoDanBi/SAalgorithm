#include "SensorManager.h"

SensorManager* SensorManager::Instance = NULL;

void SensorManager::Init(int _range, int _detect, int _send)
{
	Range = _range;
	Detect = _detect;
	Send = _send;

	SetSensor();
	SetBoard();
}

void SensorManager::SetSensor()
{
	Sensor.push_back(new Vec2(6, 7));
	Sensor.push_back(new Vec2(4, 13));
	Sensor.push_back(new Vec2(0, 5));
	Sensor.push_back(new Vec2(2, 13));
	Sensor.push_back(new Vec2(11, 8));
	Sensor.push_back(new Vec2(10, 9));
	Sensor.push_back(new Vec2(13, 5));
	Sensor.push_back(new Vec2(12, 12));
}

void SensorManager::SetBoard()
{
	for (int i = 0; i < Range; ++i) {
		vector<int> v(Range, 0);
		Board.push_back(v);
	}

	for (int i = 0; i < Sensor.size(); ++i)
		Board[Sensor[i]->y][Sensor[i]->x] = 1;
}

void SensorManager::ShowBoard()
{
	if (Board.empty()) return;

	for (int i = 0; i < Board.size(); ++i) {
		for (int j = 0; j < Board[0].size(); ++j) {
			if (Board[i][j] == 1) cout << "1";
			else cout << "*";
		}cout << endl;
	}
}

void SensorManager::Release()
{
	while (!Sensor.empty())
	{
		SafeDelet(Sensor.back());
		Sensor.pop_back();
	}

	SafeDelet(Instance);
}
