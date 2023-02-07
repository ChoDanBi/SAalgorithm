#include "Node.h"
#include "Factory.h"

Node::Node()
{
	int dy[2] = { -1, 1 };
	int dx[2] = { -1, 1 };

	vector<Point*> isPoint;

	while (isPoint.size() != SENSOR.size())
	{
		Point point = FT::CreatePoint();

		//�߰��� ���� ��ġ�� ��ġ�ų�, �̹� �ִ� �߰���� ��ǥ�� �� continue
		if ((*BOARD)[point.y][point.x] == 1
			|| LinkList.find((point)) != LinkList.end()) continue;


		SerachNearSensor(point, SMINS->GetDetect(), &isPoint);
	}
}

void Node::SerachNearSensor(Point _point, int _detect, vector<Point*>* _ispoint)
{
	vector<int> v = FindYTwoPoint(_point, _detect);

	int Top = v[0], Bottom = v[1], Left = v[2], Right = v[3];

	//���� �ȿ� �ִ� ����
	double Detect = (double)_detect;
	double dis;

	int X;

	vector<Point*> s;

	for (int i = Top; i <= Bottom; ++i)
	{
		X = SENSOR[i]->x;

		//�߰�� ���� �ȿ� ������ �ִٸ� �Ÿ� üũ
		if (!(Left <= X && X <= Right)) continue;

		dis = sqrt((pow((SENSOR[i]->y - _point.y), 2)
			+ pow((X - _point.x), 2)));

		//�Ÿ��� �Ǵ��� Ȯ��
		if (dis > Detect) continue;

		//�̹� �ٸ� �߰�⿡ ����Ǿ� �ִٸ�
		//if ((*_ispoint).find(SENSOR[i]) != (*_ispoint).end()) continue;
		if (find((*_ispoint).begin(),(*_ispoint).end(),SENSOR[i]) != (*_ispoint).end()) continue;
		
		//�����ϱ�
		s.push_back(SENSOR[i]);
		_ispoint->push_back(SENSOR[i]);
	}

	if (!s.empty()) LinkList.insert(make_pair(_point, s));
}


vector<int> Node::FindYTwoPoint(Point _point, int _detect)
{
	//left top / right buttom
	int y[2] = { (_point.y - _detect),(_point.y + _detect) };

	//y �������� ���� ������
	_Y = y[0]; int Top =
		(int)(find_if(SENSOR.begin(), SENSOR.end(),
			FindY) - SENSOR.begin());

	_Y = y[1]; int Bottom =
		(int)(find_if((SENSOR.begin() + Top), SENSOR.end(),
			FindY) - SENSOR.begin());

	if (Bottom == (SENSOR.end() - SENSOR.begin()))
		Bottom = (int)SENSOR.size() - 1;

	int Left = (_point.x - _detect);
	int Right = (_point.x + _detect);

	vector<int> v = { Top,Bottom,Left,Right };

	return v;
}



