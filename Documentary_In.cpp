#include <fstream>
#include "Documentary.h"

namespace myLab {
	void InDocumentary(Documentary& d, ifstream& ifst)
	{
		unsigned short int line;
		ifst >> line;

		//������� ����������� ��� ��������� ������ ��������� �������
		if (ifst.fail())
		{
			return;
		}
		else
		{
			d.mYear = line;
		}
	}
}
