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

		//중계기와 센서 위치가 겹치거나, 이미 있는 중계기의 좌표일 때 continue
		if ((*BOARD)[point.y][point.x] == 1
			|| LinkList.find((point)) != LinkList.end()) continue;


		SerachNearSensor(point, SMINS->GetDetect(), &isPoint);
	}
}

void Node::SerachNearSensor(Point _point, int _detect, vector<Point*>* _ispoint)
{
	vector<int> v = FindYTwoPoint(_point, _detect);

	int Top = v[0], Bottom = v[1], Left = v[2], Right = v[3];

	//범위 안에 있는 센서
	double Detect = (double)_detect;
	double dis;

	int X;

	vector<Point*> s;

	for (int i = Top; i <= Bottom; ++i)
	{
		X = SENSOR[i]->x;

		//중계기 범위 안에 센서가 있다면 거리 체크
		if (!(Left <= X && X <= Right)) continue;

		dis = sqrt((pow((SENSOR[i]->y - _point.y), 2)
			+ pow((X - _point.x), 2)));

		//거리가 되는지 확인
		if (dis > Detect) continue;

		//이미 다른 중계기에 연결되어 있다면
		//if ((*_ispoint).find(SENSOR[i]) != (*_ispoint).end()) continue;
		if (find((*_ispoint).begin(),(*_ispoint).end(),SENSOR[i]) != (*_ispoint).end()) continue;
		
		//연결하기
		s.push_back(SENSOR[i]);
		_ispoint->push_back(SENSOR[i]);
	}

	if (!s.empty()) LinkList.insert(make_pair(_point, s));
}


vector<int> Node::FindYTwoPoint(Point _point, int _detect)
{
	//left top / right buttom
	int y[2] = { (_point.y - _detect),(_point.y + _detect) };

	//y 기준으로 범위 좁히기
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



