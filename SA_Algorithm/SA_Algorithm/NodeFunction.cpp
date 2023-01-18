#include <cmath>
#include "NodeFunction.h"
#include "NodeManager.h"

void NodeFunction::Init()
{
	vector<int> num;
	for (map<int, Vector2>::iterator i = SENSOR->begin();
		i != SENSOR->end(); ++i)
		num.push_back((*i).first);

	int x, y;
	while (!num.empty())
	{
		x = GetRand(NM->GetRange() - 1);
		y = GetRand(NM->GetRange() - 1);

		for (vector<int>::iterator i = num.begin(); i != num.end();)
		{


		}
	}

}

bool NodeFunction::Linked(Vector2 _vec, int _num)
{
	Vector2 sensor = Vector2(_num % NM->GetRange(), _num / NM->GetRange());
	double dis;

	return false;
}

