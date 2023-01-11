#include "Edge.h"

void Edge::SetNum(int _num, int _size, int _send, int _receive)
{
	Num = _num;
	for (int i = 0; i < _size; ++i)
	{ Binary.push_back(_num % 2); _num /= 2; }
	SendDis = _send;
	ReceiveDis = _receive;

	Fitness = func(Num);
}

void Edge::SetBinary(vector<int> _binary, int _size, int _send, int _receive)
{
	Num = 0;
	for (int i = 0; i < _binary.size(); ++i)
		Num += (_binary[i] * (int)pow(2, i));
	for (int i = 0; i < _size; ++i)
		Binary.push_back(_binary.size() > i ? _binary[i] : 0);
	SendDis = _send;
	ReceiveDis = _receive;
	Fitness = func(Num);
}

int Edge::func(int x)
{
    return 0;
}
