#pragma once
#include <fstream>
#include "Type.h"

using namespace std;

namespace myLab {
	struct Documentary
	{
		unsigned short int mYear; // ��� ��������
	};

	void InDocumentary(Documentary& d, ifstream& ifst);
	void Out(Documentary& d, ofstream& ofst);
}