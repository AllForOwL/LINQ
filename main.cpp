#include "cpplinq.hpp"
#include <iostream>
#include <math.h>
#include <chrono>
#include <ctime>

using namespace cpplinq;

const int QUENTITY_ELEMENT_1 = 10000;
const int QUENTITY_ELEMENT_2 = 100000;
const int QUENTITY_ELEMENT_3 = 1000000;

const int QUENTITY_ELEMENT = QUENTITY_ELEMENT_2;

int SumElement(bool i_pair, bool i_allElement)
{
	int _arrElements[QUENTITY_ELEMENT];

	for (int i = 0; i < QUENTITY_ELEMENT; i++)
	{
		_arrElements[i] = rand() % 500 + 10;
	}

	if (i_pair && !i_allElement)
	{
		return
			from_array(_arrElements)
			>> where([](int i) {return i % 2 == 0; })
			>> sum()
			;
	}
	else if (!i_allElement)
	{
		return
			from_array(_arrElements)
			>> where([](int i) {return i % 2 != 0; })
			>> sum()
			;
	}
	else
	{
		return
			from_array(_arrElements)
			>> where([](int i) {return i; })
			>> sum()
			;
	}
}

int g_avarage = 0;
int Square(int i_value)
{
	return pow(i_value - g_avarage, 2);
}

int StandardDerivation()
{
	int _arrElements[QUENTITY_ELEMENT];
	for (int i = 0; i < QUENTITY_ELEMENT; i++)
	{
		_arrElements[i] = rand() % 500 + 10;
	}

	g_avarage = from_array(_arrElements)
					>> where([](int i) {return i; })
					>> avg();

	int _arrAvarage[QUENTITY_ELEMENT];
	for (int i = 0; i < QUENTITY_ELEMENT; i++)
	{
		_arrAvarage[i] = Square(_arrElements[i]);
	}

	g_avarage = from_array(_arrAvarage)
					>> where([](int i) {return i; })
					>> avg();

	return sqrt(g_avarage);
}

using ui = unsigned long long;

int main()
{
	std::chrono::time_point<std::chrono::system_clock> _start, _end;
	_start = std::chrono::system_clock::now();

	ui _sumPairElement		= SumElement(true, false);
	ui _sumNoPairElemet		= SumElement(false, false);
	ui _sumAllElement		= SumElement(false, true);
	ui _standardDerivation	= StandardDerivation();
	
	_end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = _end - _start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(_end);

	std::cout	<< "sum pair element = "	<< _sumPairElement		<< std::endl
				<< "sum no pair element = " << _sumNoPairElemet		<< std::endl
				<< "sum all element = "		<< _sumAllElement		<< std::endl
				<< "standard derivation = " << _standardDerivation	<< std::endl
	<< std::endl;
	std::cout << "time: " << elapsed_seconds.count() << std::endl << std::endl;

	system("pause");
	return 0;
}