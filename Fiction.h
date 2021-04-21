#pragma once
#include <fstream>
#include "Type.h"

using namespace std;

namespace myLab {
	struct Fiction
	{
		char mDirector[50]; // Имя режиссера
	};

	void InFiction(Fiction& f, ifstream& ifst);
	void Out(Fiction& f, ofstream& ofst);
}