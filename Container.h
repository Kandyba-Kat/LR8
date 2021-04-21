#pragma once
#include "Movie.h"

using namespace std;

namespace myLab {
    struct Container
    {
        enum { max_len = 100 }; // максимальная длина
        int len;                // текущая длина
        Movie* cont[max_len];
    };

    void Init(Container& c);
    void Clear(Container& c);
    void In(Container& c, ifstream& ifst);
    void Out(Container& c, ofstream& ofst);
    void OutCartoon(Container& c, ofstream& ofst);
    void Sort(Container& c);
}
