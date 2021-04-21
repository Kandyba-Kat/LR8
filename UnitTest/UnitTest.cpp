#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Container.h"
#include "../Container_Constr.cpp"
#include "../Container_In.cpp"
#include "../Container_Out.cpp"

#include "../Movie.h"
#include "../Movie_In.cpp"
#include "../Movie_Out.cpp"

#include "../Cartoon.h"
#include "../Cartoon_In.cpp"
#include "../Cartoon_Out.cpp"

#include "../Fiction.h"
#include "../Fiction_In.cpp"
#include "../Fiction_Out.cpp"

#include "../Documentary.h"
#include "../Documentary_In.cpp"
#include "../Documentary_Out.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Container_In_7) //�������� ������� In ��� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_7.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(7, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Container_In_0) //�������� ������� In ��� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //� ����� �����
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(0, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Movie_In_3) //�������� ������� In ��� Movie
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_3_with_incorrect_keys.txt");
			Container c;
			Init(c);
			In(c, ifst);
			int actual = c.len;
			Assert::AreEqual(2, actual);//OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_7) //�������� ������� Sort ��� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_7.txt"); //� ����� 7 �������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); // ��, ���������� ������ ��� ������
			Out(c, ofst);
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_7_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_0) //�������� ������� Sort ��� ������� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //� ����� �����
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c); //OK, ���������� �� ���������
			Out(c, ofst); //� �������� ����� "Container contents 0 elements."
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_1) //�������� ������� Sort ��� ���������� � ����� ���������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_1.txt"); //� ����� ���� �������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, ���������� �� ���������
			Out(c, ofst); //� �������� ����� "Container contents 1 elements."
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_1_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Sort_2) //�������� ������� Sort ��� ���������� � ����� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_2.txt"); //� ����� ��� ��������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Sort(c);  //OK, ���������� ����� ���� ��������� 
			Out(c, ofst); //� �������� ����� "Container contents 2 elements."

			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_2_SORTED.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutCartoon_0) //�������� ������� OutCartoon ��� ������� ����������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //� ����� �����
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //� �������� ����� "Only cartoons."
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_OutCartoon_without_cartoons) //�������� ������� OutCartoon ���������� ��� cartoons
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_5_without_cartoons.txt"); //� ����� 5 �������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			OutCartoon(c, ofst); //� �������� ����� "Only cartoons."
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_5_without_cartoons_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_InData_OverBuf) //�������� ������� InData �� ��������� � ������ ������������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_1_overbuf.txt"); //� ����� ���� cartoon � ���������� > 50 ��������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_1_overbuf_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_CountOfVowel_0) //�������� ������� VowelCount � ������ 0 �������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0_vowels.txt"); //� ��������� ��� �������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_0_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Movie_CountOfVowel_5) //�������� ������� VowelCount � ������ 5 �������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_5_vowels.txt"); //� ��������� 5 �������
			ofstream ofst("D:/TMP/TMP_proc/UnitTest/out.txt");
			Container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			//��� ��������� ���� ������
			string expected, actual;
			ifstream fin_act("D:/TMP/TMP_proc/UnitTest/out.txt");
			ifstream fin_exp("D:/TMP/TMP_proc/UnitTest/out_5_vowels_IDEAL.txt");
			getline(fin_act, actual, '\0');
			getline(fin_exp, expected, '\0');
			Assert::AreEqual(expected, actual); //OK
			Clear(c);
		}
		TEST_METHOD(Container_Clean_0) //�������� ������� ���������� ��� ���������� ���������
		{
			ifstream ifst("D:/TMP/TMP_proc/UnitTest/in_0.txt"); //� ����� �����
			Container c;
			Init(c);
			In(c, ifst);
			Clear(c);//OK, ���� �� ���������
			Assert::AreEqual(c.len, 0); //OK
		}
	};
}
