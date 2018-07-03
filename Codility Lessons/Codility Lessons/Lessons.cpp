#include "stdafx.h"
#include "Lessons.h"
#include <iostream>

using namespace std;

namespace Lesson_1
{
	int solution(int N) {
		// write your code in C++14 (g++ 6.2.0)

		int remainder{}, divisor{};
		bool gap_start{};
		int count{};
		int max_gap{};

		while (N >= 1) {
			remainder = N - (N / 2) * 2;
			divisor = N / 2;

			if (!gap_start && remainder) gap_start = true;
			else if (gap_start && !remainder) ++count;
			else if (gap_start && count && remainder) { if (count > max_gap) max_gap = count; count = 0; }
			else if (gap_start && !count && remainder) { count = 0; }


			N = divisor;
		}

		return max_gap;
	}

}


void Lessons::_1()
{
	cout << "Max gap: " << Lesson_1::solution(17) << endl;
}
