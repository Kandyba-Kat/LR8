#include <fstream>
#include "Fiction.h"

namespace myLab {
	void Out(Fiction& f, ofstream& ofst)
	{
		ofst << ", Director's name = " << f.mDirector;
	}
}