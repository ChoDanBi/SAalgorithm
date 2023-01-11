#pragma once
#include "header.h"
#include "NodeFactory.h"
#include <fstream>

class FileManager
{
public:
	static void ReadFile(string _FileName) {
		ofstream ofs;
		ofs.open(_FileName);
		ofs << "50 0\n50 100" << endl;
		ofs.close();
	}

	static void WriteSensLoc(int _cnt) {
		ofstream ofs("SensLoc.txt", ios_base::out);

		for (int i = 0; i < _cnt; ++i) {
			int x = NF::GetRand(100);
			int y = NF::GetRand(100);
			ofs << x << " " << y << endl;
		}

		ofs.close();
	}

	static void ReadSensLoc() {
		ifstream ifs("SensLoc.txt", ios_base::in);
		char ch[64];
		while (!ifs.eof())
		{
			ifs >> ch;
			cout << ch << endl;
		}
		ifs.close();
	}
};

