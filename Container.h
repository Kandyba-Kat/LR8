#pragma once
#include "Movie.h"

struct Container
{
    enum { max_len = 100 }; // ������������ �����
    int len;                // ������� �����
    Movie* cont[max_len];
};
