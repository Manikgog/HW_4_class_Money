#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
/*
Класс Деньги для работы с денежными суммами.
Число должно быть представлено двумя полями:
типа long для рублей и типа unsigned char -
для копеек.
Дробная часть (копейки) при выводе на экран
должна быть отделена от целой части запятой.
Реализовать сложение, вычитание, деление сумм,
деление суммы на дробное число, умножение на 
дробное число и операции сравнения.
*/

#include <cassert>
#include "Money.h"
#include "TestMoney.h"


void TestMoney()
{
	TestSumming();			// тестирование перегрузки operator+
	TestSubtraction();		// тестирование перегрузки operator-
	TestMultiplying();		// тестирование перегрузки operator* при умножении на объект класса Money
	TestMultiplying2();		// тестирование перегрузки operator* при умножении на double
	TestDivision();			// тестирование перегрузки operator/ при делении на double
	TestDivision2();		// тестирование перегрузки operator/ при делении на объект класса Money
	TestOperatorLess();		// тестирование перегрузки operator<
	TestOperatorMore();		// тестирование перегрузки operator>
	TestOperatorEqual();	// тестирование перегрузки operator==
}



int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	
	TestMoney();

	// Тестирование перегрузки операторов <<, >>
	Money m;
	std::cin >> m; // ввод - рубли,копейки
	std::cout << m;

	return 0;
}
