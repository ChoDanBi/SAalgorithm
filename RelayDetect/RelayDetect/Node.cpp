#include "Node.h"
#include "SensorManager.h"

Node::Node()
{
	int dy[2] = { -1, 1 };
	int dx[2] = { -1, 1 };
	int* Detect = SMINS->GetDetect();

	Point point = MakeRepeater();
	SerachSensor(&point, Detect);
}

void Node::SerachSensor(Point* _point, int* _detect)
{
	//left top / right buttom
	int y[2] = { (_point->y - *_detect ),(_point->y + *_detect) };
	int x[2] = { (_point->x - *_detect),(_point->x + *_detect) };

	int mid = *SMINS->GetRange() / 2;
	int start = mid, end = mid;

	while (true) {
		//y[0] <= (*SENSOR)[mid]->y <= y[1] 조건 이진 탐색: start index

		//범위 안에 존재
		if (y[0] <= (*SENSOR)[mid]->y && (*SENSOR)[mid]->y <= y[1])
		{
			start = mid;
			mid--;
			if(mid <= 0)
			{

				break;
			}
			if ((*SENSOR)[mid]->y < y[0] && (*SENSOR)[start]->y >= y[0]) break;
			continue;
		}

		//탐색 값이 크다면
		if (y[0] > (*SENSOR)[mid]->y)
		{
			mid -= (mid / 2);
			continue;
		}

		if ((*SENSOR)[mid]->y > y[1])
		{
			mid += (mid / 2);
		}
	}
}

Point Node::MakeRepeater()
{
	int Range = *SMINS->GetRange();
	int y = GetRand(Range);
	int x = GetRand(Range);
	return Point(y, x);
}

void Node::Show()
{
	cout << "Make Complete\n";
}

void Node::Release()
{
	while (!LinkList.empty())
		LinkList.pop_back();
	
}
