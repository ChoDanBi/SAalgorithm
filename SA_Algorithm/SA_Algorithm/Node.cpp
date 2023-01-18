#include "Node.h"
#include "NodeFunction.h"

#define FUNC NodeFunction

void Node::Init()
{
	FUNC* f = new FUNC;
	f->SetRelay(Relay);





	delete f; f = nullptr;
}

void Node::Init(vector<pair<Vector2, int>> _relay)
{
	Relay = _relay;
	FUNC* f = new FUNC(_relay);





	delete f; f = nullptr;
}

void Node::SetNum(int _num)
{
	Num = _num;
	Fitness.first = func(Num);
	do { Binary.push_back(_num % 2); _num /= 2; }
	while (_num != 0);
}

void Node::SetNum(int _num, int _size)
{
	Num = _num;
	Fitness.first = func(Num);
	for (int i = 0; i < _size; ++i)
	{ Binary.push_back(_num % 2); _num /= 2; }
}

void Node::SetBinary(vector<int> _binary)
{
	Num = 0;
	int size = _binary.size();
	for (int i = 0; i < size; ++i)
		Num += _binary[i] * (int)pow(2, i);
	Fitness.first = func(Num);
	Binary = _binary;
}

void Node::SetBinary(vector<int> _binary, int _size)
{
	Num = 0;
	for (int i = 0; i < _binary.size(); ++i)
		Num += (_binary[i] * (int)pow(2, i));
	Fitness.first = func(Num);
	for (int i = 0; i < _size; ++i)
		Binary.push_back(_binary.size() > i ? _binary[i] : 0);
}

void Node::Show()
{
	cout << "Num: " << Num
		<< ", Fit: " << Fitness.first
		<< ", Binary: ";
	for (int i = (Binary.size() - 1); i >= 0; --i)
		cout << Binary[i];

	cout << "\n";
}

