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
	static void containers_run();
	static void algorithms_sequence_operations_run();
	static void algorithms_modifying_sequence_operations_run();
	static void algoirthms_sorting_operations_run();
};