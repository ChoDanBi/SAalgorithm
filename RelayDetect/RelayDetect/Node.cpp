#include "Node.h"
#include "Factory.h"

Node::Node()
{
	int dy[2] = { -1, 1 };
	int dx[2] = { -1, 1 };

	set<Point*> isPoint;
	while (isPoint.size() != SENSOR->size())
	{
		Point point = FT::CreatePoint();
		SerachNearSensor(&point, SMINS->GetDetect(), &isPoint);
	}
}

void Node::SerachNearSensor(Point* _point, int* _detect, set<Point*>* _ispoint)
{
	//중계기와 센서 위치가 겹치거나, 이미 있는 중계기의 좌표일 때 return
	if ((*BOARD)[_point->y][_point->x] == 1 
		|| LinkList.find((*_point)) != LinkList.end()) return;

	//left top / right buttom
	int y[2] = { (_point->y - *_detect),(_point->y + *_detect) };
	int x[2] = { (_point->x - *_detect),(_point->x + *_detect) };

	//y 기준으로 범위 좁히기
	_Y = y[0]; int Top = 
		(int)(find_if((*SENSOR).begin(), (*SENSOR).end(),
		FindY) - (*SENSOR).begin());

	_Y = y[1]; int Bottom =
		(int)(find_if(((*SENSOR).begin() + Top), (*SENSOR).end(),
		FindY) - (*SENSOR).begin());

	if (Bottom == ((*SENSOR).end() - (*SENSOR).begin()))
		Bottom = (int)(*SENSOR).size() - 1;
	

	//범위 안에 있는 센서
	double Detect = (double)(*_detect);
	double dis;

	int Y, X;

	set<Point*> s;

	for (; Top <= Bottom; ++Top)
	{
		X = (*SENSOR)[Top]->x;

		//중계기 범위 안에 센서가 있다면 거리 체크
		if (x[0] <= X && X <= x[1])
		{
			Y = (*SENSOR)[Top]->y;
			dis = sqrt((pow((Y - _point->y), 2)
				+ pow((X - _point->x), 2)));

			if (dis > Detect) continue;

			//이미 다른 중계기에 연결되어 있다면
			if ((*_ispoint).find((*SENSOR)[Top]) != (*_ispoint).end()) continue;

			//연결하기
			s.insert((*SENSOR)[Top]);
			_ispoint->insert((*SENSOR)[Top]);
		}
	}
	if (!s.empty()) LinkList.insert(make_pair(*_point, s));
}


