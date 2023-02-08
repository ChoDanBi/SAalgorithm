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
	CmpDisSensor();

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

void Node::CmpDisSensor()
{
	for (LINKLIST::iterator i = LinkList.begin(); i != LinkList.end(); ++i)
	{




	}
}

vector<int> Node::FindYTwoPoint(Point _point, int _detect)
{
	//left top / right buttom
	int y[2] = { (_point.y - _detect),(_point.y + _detect) };

	//y �������� ���� ������
	int Top = 0;
	for (; Top < (int)SENSOR.size()-1; ++Top)
	{
		if (SENSOR[Top]->y <= y[0] && y[0] <= SENSOR[Top +1]->y) break;
	}

	int Bottom = (int)SENSOR.size() - 1;
	for (; Bottom > 1; --Bottom)
	{
		if (SENSOR[Bottom - 1]->y <= y[0] && y[0] <= SENSOR[Bottom]->y) break;
	}

	// = (int)(find_if(SENSOR.begin(), SENSOR.end(), FindY) - SENSOR.begin());
	// = (int)(find_if((SENSOR.begin() + Top), SENSOR.end(), FindY) - SENSOR.begin());
	//if (Bottom == (SENSOR.end() - SENSOR.begin()))
	//	Bottom = (int)SENSOR.size() - 1;

	int Left = (_point.x - _detect);
	int Right = (_point.x + _detect);

	vector<int> v = { Top,Bottom,Left,Right };

	return v;
}

void Node::Show()
{
	vector<int> v(SMINS->GetSize(),0);
	vector<vector<int>> Board;
	for (int i = 0; i < SMINS->GetSize(); ++i) Board.push_back(v);

	int n = 1;
	for (LINKLIST::iterator i = LinkList.begin(); i != LinkList.end(); ++i)
	{
		Board[(*i).first.y][(*i).first.x] = -1;

		for (int j = 0; j < (int)(*i).second.size(); ++j)
			Board[(*i).second[j]->y][(*i).second[j]->x] = n;

		n++;
	}

	for (int i = 0; i < SMINS->GetSize(); ++i)
	{
		for (int j = 0; j < SMINS->GetSize(); ++j)
		{
			if (Board[i][j] == 0) cout << " ";
			else if (Board[i][j] == -1) cout << "R";
			else cout << Board[i][j];
		}
		cout << endl;
	}
}



