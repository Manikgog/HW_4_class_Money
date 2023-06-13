#ifndef _MONEY_H_
#define _MONEY_H_

#include <iostream>
#include <string>
#include "Money.h"

class Money
{
private:
	long _ruble;
	unsigned char _penny;

public:
	Money();

	Money(long ruble, unsigned char penny);
		
	Money(long ruble);
		
	Money(unsigned char penny);

	long GetRuble();

	unsigned char GetPenny();

	friend std::ostream& operator<<(std::ostream& output, const Money& money);

	friend std::istream& operator>>(std::istream& input, Money& money);
	
	Money operator+(const Money& m);

	Money operator-(const Money& m);

	Money operator+(double num);

	Money operator-(double num);

	Money operator*(Money& m);

	Money operator*(double num);

	Money operator/(Money& m);

	Money operator/(double num);

	bool operator==(const Money& money);

	bool operator<(const Money& money);

	bool operator>(const Money& money);

};


#endif 
