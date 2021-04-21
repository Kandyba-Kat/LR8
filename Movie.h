#pragma once
#include <fstream>
#include "Type.h";
#include "Cartoon.h"
#include "Fiction.h"
#include "Documentary.h"

using namespace std;

namespace myLab {
	struct Movie
	{
		type mKey;
		char mName[50];
		char mCountry[50];
		union { // используем включение
			Cartoon c;
			Fiction f;
			Documentary d;
		};
	};

	Movie* In(ifstream& ifst);
	void Out(Movie& mv, ofstream& ofst);
	int VowelsCount(Movie& mv);
	bool Compare(Movie* first, Movie* second);
}