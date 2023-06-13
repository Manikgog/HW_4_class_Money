#include "TestMoney.h"

void TestSumming()
{
	Money m1(2, 60);
	Money m2(3, 45);
	Money m3;
	m3 = m1 + m2;
	assert(m3.GetRuble() == 6);
	assert(m3.GetPenny() == 5);
}

void TestSubtraction()
{
	Money m1(4, 60);
	Money m2(3, 45);
	Money m3;
	m3 = m1 - m2;
	assert(m3.GetRuble() == 1);
	assert(m3.GetPenny() == 15);
}

void TestMultiplying()
{
	Money m1(2, 60);
	Money m2(3, 45);
	Money m3;
	m3 = m1 * m2;
	assert(m3.GetRuble() == 8);
	assert(m3.GetPenny() == 97);
}

void TestMultiplying2()
{
	Money m1(2, 60);
	double m2 = 3.45;
	Money m3;
	m3 = m1 * m2;
	assert(m3.GetRuble() == 8);
	assert(m3.GetPenny() == 97);
}

void TestDivision()
{
	Money m1(2, 60);
	double m2 = 3.45;
	Money m3;
	m3 = m1 / m2;
	assert(m3.GetRuble() == 0);
	assert(m3.GetPenny() == 75);
}

void TestDivision2()
{
	Money m1(2, 60);
	Money m2(3, 45);
	Money m3;
	m3 = m1 / m2;
	assert(m3.GetRuble() == 0);
	assert(m3.GetPenny() == 75);
}

void TestOperatorLess()
{
	Money m1(2, 60);
	Money m2(3, 45);
	assert(m1 < m2 == true);
}

void TestOperatorMore()
{
	Money m1(2, 60);
	Money m2(3, 45);
	assert(m2 > m1 == true);
}

void TestOperatorEqual()
{
	Money m1(2, 60);
	Money m2(2, 60);
	assert((m2 == m1) == true);
}