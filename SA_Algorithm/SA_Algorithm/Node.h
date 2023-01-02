#pragma once
#include "header.h"

class Node
{
private:
	int Num = 0;	//�ĺ���: x
	int Fit = 0;		//������: f(x)
	vector<int> Binary;	//������

public:
	//���ڷ� �ʱ�ȭ
	void SetNum(int _num);
	int GetNum() { return Num; }

	//�������� �ʱ�ȭ
	void SetBinary(vector<int> _Binary);
	vector<int> GetBinary() { return Binary; };

	int GetFit() { return Fit; }

	void show();

private:
	//�Լ�
	int f(int x) { return (80 + (38 * x) - (x * x)); }
};

