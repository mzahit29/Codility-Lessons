#include "stdafx.h"
#include "Lessons.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Iterations
namespace Lesson_1
{
	int solution(int N) {
		// write your code in C++14 (g++ 6.2.0)

		int count{};
		int max_gap{};
		bool peak_has_begun{};

		while (N >= 1) {
			const int remainder = N % 2;

			if (remainder)
			{
				peak_has_begun = true;
				max_gap = std::max(max_gap, count);
				count = 0;
			}
			else
			{
				if (peak_has_begun) ++count;
			}

			N /= 2;
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
	//		++count_map[x];  // Default constructs the object if the key is not present
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

	int solution(vector<int> & A)
	{
		int result = 0;
		for (size_t i = 1; i < A.size() + 1; ++i)
		{
			result ^= A[i - 1];
			result ^= i;
		}
		result ^= A.size() + 1;

		return result;
	}

	int solution2(vector<int> & A)
	{
		int sum{};
		for (auto i : A)
		{
			sum += i;
		}

		int min_difference{std::numeric_limits<int>::max()};
		int sum_part_a{};
		for(int i = 1; i < A.size(); ++i) // P = [1, N-1]
		{
			sum_part_a += A[i - 1];
			int cur_diff = abs((2 * sum_part_a) - sum);
			if (cur_diff < min_difference)
			{
				min_difference = cur_diff;
			}
		}

		return min_difference;
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

	vector<int> v{ 1, 3, 2, 5 };
	cout << "Missing element: " << Lesson_3::solution(v) << endl;

	vector<int> v2{ 3, 1, 2, 4, 3 };
	cout << "Min difference of parts: " << Lesson_3::solution2(v2) << endl;
}
