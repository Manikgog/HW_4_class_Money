#include "Money.h"

Money::Money() : _ruble(0), _penny(0) {}
Money::Money(long ruble, unsigned char penny)
	: _ruble(ruble), _penny(penny) {}
Money::Money(long ruble)
	: _ruble(ruble), _penny(0) {}
Money::Money(unsigned char penny)
	: _ruble(0), _penny(penny) {}
long Money::GetRuble()
{
	return _ruble;
}
unsigned char Money::GetPenny()
{
	return _penny;
}

Money Money::operator+(const Money& m)
{
	long r = _ruble + m._ruble;
	char p = _penny + m._penny;
	if (p >= 100)
	{
		r++;
		p -= 100;
	}
	return Money(r, p);;
}

Money Money::operator-(const Money& m)
{
	long r = _ruble - m._ruble;
	char p = _penny - m._penny;
	if (p < 0)
	{
		r--;
		p = 100 + p;
	}
	return Money(r, p);;
}

Money Money::operator+(double num)
{
	double tmp = _ruble + num;
	long r = tmp;
	unsigned char p = (tmp - r) * 100 + _penny;
	if (p >= 100)
	{
		r += p / 100;
		p %= 100;
	}
	return Money(r, p);
}

Money Money::operator-(double num)
{
	double tmp = _ruble + (double)_penny / 100;
	long r = tmp - num;
	char p = ((tmp - num) - r) * 100;
	return Money(r, (unsigned char)p);
}

Money Money::operator*(Money& m)
{
	double num = m._ruble + (double)m._penny / 100;
	double tmp = _ruble + (double)_penny / 100;
	long r = tmp * num;
	char p = ((tmp * num) - r) * 100;
	return Money(r, (unsigned char)p);
}

Money Money::operator*(double num)
{
	double tmp = _ruble + (double)_penny / 100;
	long r = tmp * num;
	char p = ((tmp * num) - r) * 100;
	return Money(r, (unsigned char)p);
}

Money Money::operator/(Money& m)
{
	double num = m._ruble + (double)m._penny / 100;
	double tmp = _ruble + (double)_penny / 100;
	long r = tmp / num;
	char p = ((tmp / num) - r) * 100;
	return Money(r, (unsigned char)p);
}

Money Money::operator/(double num)
{
	double tmp = _ruble + (double)_penny / 100;
	long r = tmp / num;
	char p = ((tmp / num) - r) * 100;
	return Money(r, (unsigned char)p);
}

bool Money::operator==(const Money& money)
{
	double _m = _ruble + (double)_penny / 100;
	double m = money._ruble + (double)_penny / 100;
	if ((_m - m) < 0.01)
		return true;
	else
		return false;
}

bool Money::operator<(const Money& money)
{
	double _m = _ruble + (double)_penny / 100;
	double m = money._ruble + (double)_penny / 100;
	if (_m < m)
		return true;
	else
		return false;
}

bool Money::operator>(const Money& money)
{
	double _m = _ruble + (double)_penny / 100;
	double m = money._ruble + (double)_penny / 100;
	if (_m > m)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& output, const Money& money)
{
	output << money._ruble << "," << (int)money._penny;
	return output;
}

std::istream& operator>>(std::istream& input, Money& money)
{
	long ruble;
	unsigned char penny;
	std::string str;
	input >> str;
	ruble = stoi(str);
	int pos = str.find(',', 0);
	str = str.substr(pos+1);
	int p = stoi(str);
	penny = p;
	money = Money(ruble, penny);
	return input;
}