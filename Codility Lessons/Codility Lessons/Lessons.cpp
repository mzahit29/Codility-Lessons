#include "stdafx.h"
#include "Lessons.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Iterations
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

// Arrays
namespace Lesson_2
{
	vector<int> solution(vector<int> &A, int K) {
		// write your code in C++14 (g++ 6.2.0)

		// Empty vector
		if (A.size() == 0) return A;

		int fall = K % A.size();  // How many numbers that will fall from the end
		int beg = (A.size() - fall) % A.size();  // This is the beginning element that must be the first element of result

		vector<int> result;
		auto it = A.begin() + beg;
		do {
			result.push_back(*it);
			++it;

			//We want to rotate the iterator back to beginning when we reach A.end()
			if (it == A.end()) {
				it = A.begin();
			}
		} while (it != A.begin() + beg);  // end the iteration when we have come back to beginning iterator


		return result;
	}

	// Finding the odd occurrences in a vector
	// Fails on one test case with million elements [Correctness: %100, Performance: %75]
	// Also fails on O(1) space complexity, since I am using a map and space complexity becomes O(N)
	//int solution(vector<int> &A) {
	//	// write your code in C++14 (g++ 6.2.0)

	//	map<int, int> count_map;


	//	for(auto x : A)
	//	{
	//		++count_map[x];
	//	}

	//	for (auto x : count_map)
	//	{
	//		if (x.second % 2 == 1) return x.first;
	//	}

	//	return 0;
	//}

	// Finding the odd occurrences in a vector %100 success
	int solution(vector<int> &A)
	{
		int result = 0;
		for (auto x : A)
		{
			result ^= x;
		}

		return result;
	}
}

// Time complexity
namespace Lesson_3
{
	// Frog Jump O(1) time complexity, O(1) space complexity
	int solution(int X, int Y, int D) {

		int jumps{};

		// Readable form
		/*int distance = Y - X;
		int divisor = distance / D;
		int remainder = distance % D;
		if (remainder) jumps = divisor + 1;
		else jumps = divisor;*/

		// OR more compact form
		jumps = (Y - X) / D + (((Y - X) % D) ? 1 : 0);

		return jumps;

	}
}

void Lessons::_1()
{
	cout << "Max gap: " << Lesson_1::solution(17) << endl;
}

void Lessons::_2()
{
	vector<int> v{ 1,2,3,4,5,6,7 };
	int shift_count = 864;
	auto result = Lesson_2::solution(v, shift_count);

	cout << "Shift count: " << shift_count << endl;
	cout << "Array before rotation" << endl;
	for (auto &x : v)
	{
		cout << x << " ";
	}
	cout << "\nArray after rotation" << endl;
	for (auto &x : result)
	{
		cout << x << " ";
	}
	cout << endl;

	vector<int> v2{ 4, 3, 1, 4, 3, 1, 9, 3, 3, 4, 5, 5, 4, 8, 8, 9, 21 };
	cout << "Unpaired element: " << Lesson_2::solution(v2) << endl;
}

void Lessons::_3()
{
	cout << "Jumps: " << Lesson_3::solution(10, 85, 30) << endl;
}
