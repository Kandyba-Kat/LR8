#include <fstream>
#include "Container.h"

namespace myLab {
    Movie* In(ifstream& ifdt);

    // ���� ����������� ���������� �� ���������� ������
    void In(Container& c, ifstream& ifst)
    {
        while (!ifst.eof())
        {
            if ((c.cont[c.len] = In(ifst)) != 0)
            {
                c.len++;
            }
        }
    }
}