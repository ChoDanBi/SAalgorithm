#include "Node.h"
#include "Factory.h"

Node::Node()
{
	int dy[2] = { -1, 1 };
	int dx[2] = { -1, 1 };

	vector<Point*> isPoint;

	while (isPoint.size() != (*SENSOR).size())
	{
		Point point = FT::CreatePoint();

		//중계기와 센서 위치가 겹치거나, 이미 있는 중계기의 좌표일 때 continue
		if ((*BOARD)[point.y][point.x] > 0
			|| LinkList.find((point)) != LinkList.end()) continue;

		SerachNearSensor(point, SMINS->GetDetect(), &isPoint);
	}
	//CmpDisSensor();
	LinkRepeter();
}

void Node::SerachNearSensor(Point _point, int _detect, vector<Point*>* _ispoint)
{
	//vector<int> v = FindRange(_point, _detect);

	//int Top = v[0], Bottom = v[1], Left = v[2], Right = v[3];
	int Top = _point.y - _detect, Bottom = _point.y + _detect,
		Left = _point.x - _detect, Right = _point.x + _detect;

	//범위 안에 있는 센서
	double Detect = (double)_detect;
	double dis;
	vector<Point*> s;

	for (vector<Point*>::iterator i = (*SENSOR).begin(); i != (*SENSOR).end(); ++i)
	{
		if (!(Top <= (*i)->y && (*i)->y <= Bottom && Left <= (*i)->x && (*i)->x <= Right)) continue;

		dis = sqrt((pow(((*i)->y - _point.y), 2) + pow(((*i)->x - _point.x), 2)));

		//거리가 되는지 확인
		if (dis > Detect) continue;

		//이미 다른 중계기에 연결되어 있다면
		if (find((*_ispoint).begin(), (*_ispoint).end(), *i) != (*_ispoint).end()) continue;

		//연결하기
		s.push_back(*i);
		_ispoint->push_back(*i);
	}
	if (!s.empty()) LinkList.insert(make_pair(_point, s));
}

void Node::LinkRepeter()
{
	//어케해야할까유...
	vector<Point> v;
	Graph.insert(make_pair((*FBASE), v));
	Graph.insert(make_pair((*SBASE), v));

	vector<Point> point;
	for (LINKLIST::iterator i = LinkList.begin(); i != LinkList.end(); ++i)
		point.push_back((*i).first);

	double send = (double)SMINS->GetSend();
	double dis;

	for (vector<Point>::iterator i = point.begin(); i != point.end(); ++i)
	{
		if (((*FBASE).y - send) <= (*i).y && (*i).y <= ((*FBASE).y + send)
			&& ((*FBASE).x - send) <= (*i).x && (*i).x <= ((*FBASE).x + send))
		{
			//거리 구하기
			dis = sqrt((pow(((*FBASE).y - (*i).y), 2) + pow(((*FBASE).x - (*i).x), 2)));
			if (dis > send) continue;
			Graph[*FBASE].push_back((*i));
		}
		else if (((*SBASE).y - send) <= (*i).y && (*i).y <= ((*SBASE).y + send)
			&& ((*SBASE).x - send) <= (*i).x && (*i).x <= ((*SBASE).x + send))
		{
			//거리 구하기
			dis = sqrt((pow(((*SBASE).y - (*i).y), 2) + pow(((*SBASE).x - (*i).x), 2)));
			if (dis > send) continue;
			Graph[*FBASE].push_back((*i));
		}
		else continue;

		Graph.insert(make_pair((*i), v));
		point.erase(i);
		if (i != point.begin()) --i;
	}

	/*
		절리당다리당당
		쏘피곤 나중에 그거 해야하는디 아직 1시간이나 남았네
	*/

}

vector<int> Node::FindRange(Point _point, int _detect)
{
	//left top / right buttom
	int y[2] = { (_point.y - _detect),(_point.y + _detect) };

	//y 기준으로 범위 좁히기
	int Top = 0;
	for (; Top < (int)(*SENSOR).size(); ++Top)
	{
		if ((*SENSOR)[Top]->y <= y[0]) break;
	}

	int Bottom = (int)(*SENSOR).size() - 1;
	for (; Bottom > -1; --Bottom)
	{
		if ((*SENSOR)[Bottom]->y <= y[1]) break;
	}

	int Left = (_point.x - _detect);
	int Right = (_point.x + _detect);

	vector<int> v = { Top,Bottom,Left,Right };
	return v;
}

void Node::ShowRepeater()
{
	for (GRAPH::iterator i = Graph.begin(); i != Graph.end(); ++i)
	{
		if ((*i).second.empty()) continue;

		cout << "베이스(x, y): " << (*i).first.x << ", " << (*i).first.y <<
			" 연결된 중계기: ";
		for (vector<Point>::iterator it = (*i).second.begin(); it != (*i).second.end(); ++it)
		{
			cout << "(" << (*it).x << ", " << (*it).y << ") ";
		}
		cout << endl;
	}
}

void Node::ShowSensor()
{
	vector<int> v(SMINS->GetSize(),0);
	vector<vector<int>> Board;
	for (int i = 0; i < SMINS->GetSize(); ++i) Board.push_back(v);

	int n = 1;
	for (LINKLIST::iterator i = LinkList.begin(); i != LinkList.end(); ++i)
	{
		Board[(*i).first.y][(*i).first.x] = -1 * n;
		cout << n << "번 중계기(x, y): (" << (*i).first.y << ", " << (*i).first.x
			<< ") 연결 센서(x, y): ";
		for (int j = 0; j < (int)(*i).second.size(); ++j)
		{
			cout << "(" << (*i).second[j]->x << ", " << (*i).second[j]->y << ") ";
			Board[(*i).second[j]->y][(*i).second[j]->x] = n;
		}
		cout << endl;
		n++;
	}

	for (int i = 0; i < SMINS->GetSize(); ++i)
	{
		for (int j = 0; j < SMINS->GetSize(); ++j)
		{
			if (Board[i][j] == 0) cout << " * ";
			else if (Board[i][j] < 0) cout << "S" << (-1 * Board[i][j]) << " ";
			else cout << " " << Board[i][j] << " ";
		}
		cout << endl;
	}
}



