#include "Node.h"
#include "NodeManager.h"

void Node::SetNum(int _num)
{
	Num = _num;
	Fit = f(Num);
	do {
		Binary.push_back(_num % 2);
		_num /= 2;
	} while (_num != 0);
}

void Node::SetBinary(vector<int> _Binary)
{
	Num = 0;
	int size = _Binary.size();
	for (int i = 0; i < size; ++i)
		Num += _Binary[i] * (int)pow(2, i);

	Fit = f(Num);
	Binary = _Binary;
}

void Node::show()
{
	cout << "후보해: " << Num
		<< " 적합도: " << Fit
		<< " 이진법: ";
	for (int i = (Binary.size() - 1); i >= 0; ++i) cout << Binary[i];
	cout << endl;
}

