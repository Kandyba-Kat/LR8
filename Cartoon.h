#pragma once
#include <fstream>
#include "Type.h"

using namespace std;

namespace myLab {
	struct Cartoon
	{
		enum creationType
		{
			DRAWN,
			RAGDOLL,
			PLASTICINE
		};
		creationType mType;
	};

	void InCartoon(Cartoon& c, ifstream& ifst);
	void Out(Cartoon& c, ofstream& ofst);

}