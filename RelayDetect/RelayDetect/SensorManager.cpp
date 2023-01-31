#include "SensorManager.h"

SensorManager* SensorManager::Instance = NULL;

void SensorManager::Init(int _range, int _detect, int _send)
{
	Range = _range;
	Detect = _detect;
	Send = _send;

	Base[0] = new Point(0, Range/2);
	Base[1] = new Point(Range - 1, (Range / 2 - 1));

	SetSensor();
	SetBoard();
}

void SensorManager::SetSensor()
{
	Sensor.push_back(new Point(6, 7));
	Sensor.push_back(new Point(4, 13));
	Sensor.push_back(new Point(0, 5));
	Sensor.push_back(new Point(2, 13));
	Sensor.push_back(new Point(11, 8));
	Sensor.push_back(new Point(10, 9));
	Sensor.push_back(new Point(13, 5));
	Sensor.push_back(new Point(12, 12));

	sort(Sensor.begin(), Sensor.end(), cmp);
	//ShowSensor();
}

void SensorManager::SetBoard()
{
	vector<int> v(Range, 0);
	for (int i = 0; i < Range; ++i) Board.push_back(v);

	for (int i = 0; i < (int)Sensor.size(); ++i)
		Board[Sensor[i]->y][Sensor[i]->x] = 1;
}

void SensorManager::ShowBoard()
{
	if (Board.empty()) return;
	for (int i = 0; i < (int)Board.size(); ++i)
	{
		for (int j = 0; j < (int)Board[0].size(); ++j)
		{
			if (Board[i][j] != 0) cout << "S";
			else cout << " ";
		}
		cout << endl;
	}
}

void SensorManager::ShowSensor()
{
	for (vector<Point*>::iterator i = Sensor.begin(); i != Sensor.end(); ++i)
		cout << "y: " << (*i)->y << ", x: " << (*i)->x << endl;
}

void SensorManager::Release()
{
	SafeDelet(Base[0]);
	SafeDelet(Base[1]);
	while (!Sensor.empty())
	{
		SafeDelet(Sensor.back());
		Sensor.pop_back();
	}
	SafeDelet(Instance);
}
