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
	//�߰��� ���� ��ġ�� ��ġ�ų�, �̹� �ִ� �߰���� ��ǥ�� �� return
	if ((*BOARD)[_point->y][_point->x] == 1 
		|| LinkList.find((*_point)) != LinkList.end()) return;

	//left top / right buttom
	int y[2] = { (_point->y - *_detect),(_point->y + *_detect) };
	int x[2] = { (_point->x - *_detect),(_point->x + *_detect) };

	//y �������� ���� ������
	_Y = y[0]; int Top = 
		(int)(find_if((*SENSOR).begin(), (*SENSOR).end(),
		FindY) - (*SENSOR).begin());

	_Y = y[1]; int Bottom =
		(int)(find_if(((*SENSOR).begin() + Top), (*SENSOR).end(),
		FindY) - (*SENSOR).begin());

	if (Bottom == ((*SENSOR).end() - (*SENSOR).begin()))
		Bottom = (int)(*SENSOR).size() - 1;
	

	//���� �ȿ� �ִ� ����
	double Detect = (double)(*_detect);
	double dis;

	int Y, X;

	set<Point*> s;

	for (; Top <= Bottom; ++Top)
	{
		X = (*SENSOR)[Top]->x;

		//�߰�� ���� �ȿ� ������ �ִٸ� �Ÿ� üũ
		if (x[0] <= X && X <= x[1])
		{
			Y = (*SENSOR)[Top]->y;
			dis = sqrt((pow((Y - _point->y), 2)
				+ pow((X - _point->x), 2)));

			if (dis > Detect) continue;

			//�̹� �ٸ� �߰�⿡ ����Ǿ� �ִٸ�
			if ((*_ispoint).find((*SENSOR)[Top]) != (*_ispoint).end()) continue;

			//�����ϱ�
			s.insert((*SENSOR)[Top]);
			_ispoint->insert((*SENSOR)[Top]);
		}
	}
	if (!s.empty()) LinkList.insert(make_pair(*_point, s));
}


