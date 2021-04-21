#include <fstream>
#include <string>
#include "Movie.h"

namespace myLab {
	// Сигнатуры требуемых внешних функций
	void InCartoon(Cartoon& c, ifstream& ifst);
	void InFiction(Fiction& f, ifstream& ifst);
	void InDocumentary(Documentary& d, ifstream& ifst);

	Movie* In(ifstream& ifst)
	{
		Movie* mv;
		string line; //Временное решение на случай переполнения
		int key;
		ifst >> key;

		if (ifst.fail())
		{
			ifst.clear();
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			return 0;
		}
		else
		{
			switch (key)
			{
			case 1:
				mv = new Movie;
				mv->mKey = type::CARTOON;

				getline(ifst, line);
				getline(ifst, line);
				line.resize(49);

				strcpy_s(mv->mName, 50, line.c_str());
				InCartoon(mv->c, ifst);

				line.clear();
				ifst >> line;
				line.resize(49);
				strcpy_s(mv->mCountry, 50, line.c_str());
				line.clear();
				return mv;
			case 2:
				mv = new Movie;
				mv->mKey = type::FICTION;

				getline(ifst, line);
				getline(ifst, line);
				line.resize(49);
				strcpy_s(mv->mName, 50, line.c_str());
				InFiction(mv->f, ifst);

				line.clear();
				ifst >> line;
				line.resize(49);
				strcpy_s(mv->mCountry, 50, line.c_str());
				line.clear();
				return mv;
			case 3:
				mv = new Movie;
				mv->mKey = type::DOCUMENTARY;
				getline(ifst, line);
				getline(ifst, line);
				line.resize(49);
				strcpy_s(mv->mName, 50, line.c_str());
				InDocumentary(mv->d, ifst);

				line.clear();
				ifst >> line;
				line.resize(49);
				strcpy_s(mv->mCountry, 50, line.c_str());
				line.clear();
				return mv;
			default:
				char junk[50]; //для мусора
				ifst.getline(junk, 50);
				ifst.getline(junk, 50);
				ifst.getline(junk, 50);
				return 0;
			}
			line.clear();
		}
	}
}