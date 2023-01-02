#pragma once
#include "header.h"

class Node
{
private:
	int Num = 0;	//후보해: x
	int Fit = 0;		//적랍도: f(x)
	vector<int> Binary;	//이진법

public:
	//숫자로 초기화
	void SetNum(int _num);
	int GetNum() { return Num; }

	//이진수로 초기화
	void SetBinary(vector<int> _Binary);
	vector<int> GetBinary() { return Binary; };

	int GetFit() { return Fit; }

	void show();

private:
	//함수
	int f(int x) { return (80 + (38 * x) - (x * x)); }
};

