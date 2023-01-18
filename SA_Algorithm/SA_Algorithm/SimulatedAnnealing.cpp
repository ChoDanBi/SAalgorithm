#include "SimulatedAnnealing.h"
#include "NodeFactory.h"

SimulatedAnnealing* SimulatedAnnealing::Instance = nullptr;

void SimulatedAnnealing::Init(const double& _accept, const double& _temp, const double& _diff, const int& _range, const int& _send, const int& _detect)
{
	AcceptanceProbabilty = _accept;
	Temperature = _temp;
	Difference = _diff;
	NM->Init(_range, _send, _detect);
	//NM->Init((_range*_range -1), _send, _detect);
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
