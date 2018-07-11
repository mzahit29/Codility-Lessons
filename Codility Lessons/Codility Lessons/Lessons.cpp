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
		for(size_t i = 1; i < A.size(); ++i) // P = [1, N-1]
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

namespace Lesson_4
{
	int solution(vector<int> & A)
	{
		// Assume A is a permutation from 1 to N in random order. If you XOR it with list [1, ..., N] then you should
		// get 0 as a result otherwise non zero.
		int result = 0;
		for (size_t i = 1; i < A.size() + 1; ++i)
		{
			result ^= A[i - 1];
			result ^= i;
		}

		return (result != 0) ? 0 : 1;
	}

	int solution(int X, vector<int> &A)
	{
		// Find the permutation XOR of [1, X]
		int perm_sum{};
		for (int i = 1; i < X + 1; ++i) {
			perm_sum += i;
		}

		// Create a map of to hold already encountered positions
		map<int, bool> encounter_map;

		for (size_t i = 0; i < A.size(); ++i)
		{
			int val = A[i];
			if (val < X + 1) // We only care about positions [1, X]
			{
				if (!encounter_map[val])  // If not encountered that position before
				{
					encounter_map[val] = true;  // Save it to encountered map
					perm_sum -= val;
					if (perm_sum == 0) return i;
				}
			}
		}

		return -1;
	}

	int solution2(vector<int> & A)
	{
		// array A of N integers where N [1, 100000], each integer [-1,000,000 , +-1,000,000]
		// by pigeonhole principle we know that at least one of the integers between [1, 100001] will not be in the list
		const int N = 100000;
		int exists[N + 2]{};

		for (auto i : A)
		{
			if (0 < i && i < N + 2)
			{
				exists[i] = 1;
			}
		}

		for (int i = 1; i < N + 2; ++i)
		{
			if (!exists[i]) return i;
		}

		return 1;
	}

	// MaxCounters
	vector<int> solution3(int N, vector<int> &A)
	{
		vector<int> result(N, 0); // Vector of N counters all initialized to 0

		int max_counter{};

		for (auto i : A)
		{
			if (i == N + 1)
			{
				for (auto &elem : result)
				{
					elem = max_counter;
				}
			} else
			{
				++result[i - 1];
				if (result[i - 1] > max_counter) max_counter = result[i - 1];

			}
		}

		return result;
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

void Lessons::_4()
{
	vector<int> v{ 1, 5, 2, 4 };
	cout << "Is permutation returned: " << Lesson_4::solution(v) << endl;

	vector<int> v2{ 1,3,1,4,2,3,5,4 };
	int dest{5};
	cout << "Positions 1 to " << dest << " are filled in " << Lesson_4::solution(dest, v2) << " seconds" << endl;

	vector<int> v3{ 1, 3, 6, 4, 1, 2 };
	cout << "Smallest not occuring integer is " << Lesson_4::solution2(v3) << endl;

	// max counter
	vector<int> v4{ 3, 4, 4, 6, 1, 4, 4 };
	for (auto x : Lesson_4::solution3(5, v4))
	{
		cout << x << " ";
	} cout << endl;
}
