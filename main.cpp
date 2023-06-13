#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
/*
����� ������ ��� ������ � ��������� �������.
����� ������ ���� ������������ ����� ������:
���� long ��� ������ � ���� unsigned char -
��� ������.
������� ����� (�������) ��� ������ �� �����
������ ���� �������� �� ����� ����� �������.
����������� ��������, ���������, ������� ����,
������� ����� �� ������� �����, ��������� �� 
������� ����� � �������� ���������.
*/

#include <cassert>
#include "Money.h"
#include "TestMoney.h"


void TestMoney()
{
	TestSumming();			// ������������ ���������� operator+
	TestSubtraction();		// ������������ ���������� operator-
	TestMultiplying();		// ������������ ���������� operator* ��� ��������� �� ������ ������ Money
	TestMultiplying2();		// ������������ ���������� operator* ��� ��������� �� double
	TestDivision();			// ������������ ���������� operator/ ��� ������� �� double
	TestDivision2();		// ������������ ���������� operator/ ��� ������� �� ������ ������ Money
	TestOperatorLess();		// ������������ ���������� operator<
	TestOperatorMore();		// ������������ ���������� operator>
	TestOperatorEqual();	// ������������ ���������� operator==
}



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	
	TestMoney();

	// ������������ ���������� ���������� <<, >>
	Money m;
	std::cin >> m; // ���� - �����,�������
	std::cout << m;

	return 0;
}
