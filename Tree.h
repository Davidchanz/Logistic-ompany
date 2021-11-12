#pragma once
#include "Strategy.h"

template <typename T> class Tree
{
public:
	Strategy<T>* comparator;
	Tree(Strategy <T>* compare = nullptr) : comparator(compare)
	{

	}
};