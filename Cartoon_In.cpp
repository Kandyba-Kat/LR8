#include <fstream>
#include <string>
#include "Cartoon.h"

namespace myLab {
	void InCartoon(Cartoon& c, ifstream& ifst)
	{
		short line;
		ifst >> line;

		//������� ����������� ��� ��������� ������ ��������� �������
		if (ifst.fail())
		{
			return;
		}
		else
		{
			if (line == 0)
			{
				c.mType = Cartoon::DRAWN;
			}
			else if (line == 1)
			{
				c.mType = Cartoon::RAGDOLL;
			}
			else if (line == 2)
			{
				c.mType = Cartoon::PLASTICINE;
			}
		}
	}
}
