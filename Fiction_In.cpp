#include <fstream>
#include <string>
#include "Fiction.h"

namespace myLab {
	void InFiction(Fiction& f, ifstream& ifst)
	{
		string line;
		getline(ifst, line);
		line.resize(49);
		strcpy_s(f.mDirector, 50, line.c_str());
		line.clear();
	}
}