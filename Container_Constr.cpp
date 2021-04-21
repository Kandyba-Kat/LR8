#include "Container.h"

namespace myLab {
    void Init(Container& c)
    {
        c.len = 0;
    }

    // ������� ���������� �� ��������� (������������ ������)
    void Clear(Container& c)
    {
        for (int i = 0; i < c.len; i++) {
            delete c.cont[i];
        }
        c.len = 0;
    }
}