#include "NodeManager.h"
#include "NodeFactory.h"
#include "SensorFile.h"

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(const int& _range, const int& _send, const int& _detect)
{
	Range = _range;
	SetSize();

	Send = _send;
	Detect = _detect;

	currentNode = NF::CreateNode(GetRand(_range), Size);
	cout << "Start - "; ShowCurNode();

	for (int i = 0; i < _range; ++i) {
		vector<int> v(_range, 0);
		Board.push_back(v);
	}
	SetBorad();
	ShowBoard();
}

void NodeManager::Init(const int& _range, const int& _send, const int& _detect, const int& _num)
{
	Range = _range;
	SetSize();

	Send = _send;
	Detect = _detect;

	currentNode = NF::CreateNode(_num, Size);
	cout << "Start - "; ShowCurNode();

	for (int i = 0; i < _range; ++i) {
		vector<int> v(_range, 0);
		Board.push_back(v);
	}
	SetBorad();
	ShowBoard();
}

void NodeManager::SetBorad()
{
	vector<Vector2> v = SF::GetSensor();

	for (int i = 0; i < v.size(); ++i) {
		Board[v[i].y][v[i].x] = 1;
		Sensor.insert(make_pair((v[i].y * Range + v[i].x) ,v[i]));
	}

	//Base
	Base[0] = Vector2(0, (Range / 2));
	Base[1] = Vector2((Range - 1), (Range / 2 - 1));

	Board[Base[0].y][Base[0].x] = 2;
	Board[Base[1].y][Base[1].x] = 2;
}

void NodeManager::SetCurNode(Node* _node)
{
	DelCurNode();
	currentNode = _node;
	_node = nullptr;
}

void NodeManager::ShowCurNode() { currentNode->Show(); }
void NodeManager::ShowBoard()
{
	for (int i = 0; i < Board.size(); ++i) {
		for (int j = 0; j < Board[i].size(); ++j) {
			cout << Board[i][j] << " ";
		} cout << endl;
	}
}

void NodeManager::Release()
{
	DEL(currentNode);
	DEL(Instance);
}
