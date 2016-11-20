#include "cpplinq.hpp"
#include <iostream>

const int QUENTITY_ELEMENT = 10000;

int SumElement(bool i_pair, bool i_allElement)
{
	using namespace cpplinq;

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

int main()
{
	int _sumPairElement		= SumElement(true, false);
	int _sumNoPairElemet	= SumElement(false, false);
	int _sumAllElement		= SumElement(false, true);

	std::cout	<< "sum pair element = "	<< _sumPairElement	<< std::endl
				<< "sum no pair element = " << _sumNoPairElemet << std::endl
				<< "sum all element = "		<< _sumAllElement	<< std::endl
	<< std::endl;

	system("pause");
	return 0;
}