#include "SimulatedAnnealing.h"
#include "NodeFactory.h"

#define cNode NM->GetCurNode()

SimulatedAnnealing* SimulatedAnnealing::Instance = nullptr;

void SimulatedAnnealing::Init(const double& _accept, const double& _temp, const double& _diff)
{
	AcceptanceProbabilty = _accept;
	Temperature = _temp;
	Difference = _diff;
	vector<int> v(10, 0);
	for (int i = 0; i < 10; ++i)
		Board.push_back(v);
}

void SimulatedAnnealing::Init(const double& _accept, const double& _temp, const double& _diff, const int& _range, const int& _send, const int& _detect)
{
	AcceptanceProbabilty = _accept;
	Temperature = _temp;
	Difference = _diff;
	NM->Init(_range, _send, _detect);
}

void SimulatedAnnealing::Init(const double& _accept, const double& _temp, const double& _diff, const int& _range, const int& _send, const int& _detect, const int& _num)
{
	AcceptanceProbabilty = _accept;
	Temperature = _temp;
	Difference = _diff;
	NM->Init(_range, _send, _detect, _num);
}

void SimulatedAnnealing::Start()
{
	ReadFile();
	Simulating();
	Finish();
}

void SimulatedAnnealing::Simulating()
{
	Node* node;
	int dis, size = cNode->GetBinary().size();
	double per;

	for (int i = 0; i < size;) {

		node = NF::CreateNearNode(cNode, i, NM->GetSize());
		dis = GetDistance(cNode->pGetFit(), node->pGetFit());
		per = GetPercent(dis);

		//Good Fit or Bad Fit: Percent is lower than Accept
		if (ChkAbletoChange(node, dis, per, &i, &size))
			continue;

		//nothing - go next
		DEL(node); ++i;
	}
}

bool SimulatedAnnealing::ChkAbletoChange(Node* _node, const int& _dis, const int& _per, int* _i, int* _size)
{
	if ((_dis > 0) || (_per < AcceptanceProbabilty)) {
		if (_per < AcceptanceProbabilty) Temperature /= Difference;
		NM->SetCurNode(_node);
		*_size = cNode->GetBinary().size(); *_i = 0;
		return true;
	}return false;
}

void SimulatedAnnealing::WriteFile(int _cnt)
{
	ofstream ofs("SensLoc.txt", ios_base::out);
	for (int i = 0; i < _cnt; ++i) {
		int x = GetRand(99);
		int y = GetRand(99);
		ofs << x << " " << y << endl;
	}
	ofs.close();
}

void SimulatedAnnealing::ReadFile()
{
	ifstream ifs("SensLoc.txt", ios_base::in);
	string ch;
	while (!ifs.eof())
	{
		ifs >> ch; int x = stoi(ch);
		ifs >> ch; int y = stoi(ch);
		Board[y][x] = -1;
	}
	ifs.close();
}

