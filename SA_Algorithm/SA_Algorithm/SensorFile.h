#pragma once
#include "header.h"
#include <fstream>

using namespace std;

typedef class SensorFile {
public:	//File
	static void WriteFile(int _cnt, int _range)
	{
		ofstream ofs("Sensor.txt", ios_base::out);

		int x, y;
		for (int i = 0; i < _cnt; ++i) {
			x = GetRand(_range - 1);
			y = GetRand(_range - 1);

			ofs << x << " " << y << endl;
		}
		ofs.close();
	}

	static void ReadSensor()
	{
		ifstream ifs("Sensor.txt", ios_base::in);
		string ch;
		while (!ifs.eof())
		{
			ifs >> ch; cout << "(" << ch << ", ";
			ifs >> ch; cout << ch << ")\n";
		}
		ifs.close();
	}

public:	//Get
	static vector<Vec2> GetSensor() {
		ifstream ifs("Sensor.txt", ios_base::in);
		
		vector<Vec2> vec;
		int y, x; string ch;

		while (!ifs.eof())
		{
			ifs >> ch;
			x = stoi(ch);
			ifs >> ch;
			y = stoi(ch);
			vec.push_back(Vec2(y, x));
		}
		ifs.close();

		return vec;
	}

}SFile;