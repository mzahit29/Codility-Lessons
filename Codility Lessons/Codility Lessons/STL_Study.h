#pragma once
#include "stdafx.h"


template <typename T>
class Incrementer
{
	T amount_{};
public:
	Incrementer() : Incrementer(0) {}
	Incrementer(T amount) : amount_(amount) {}
	T& operator()(T &i) { i += amount_; return i; }
};


class STL_Study
{
public:
	static void _1();
};