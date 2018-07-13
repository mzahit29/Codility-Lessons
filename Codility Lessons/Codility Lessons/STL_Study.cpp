#include "stdafx.h"
#include "STL_Study.h"

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>


using namespace std;

// Predicate
bool greater_than_zero(int i) { return i > 0; }


void STL_Study::_1()
{
	vector<double> v;
	pair<int, int> p{ 4, 4 };
	cout << p.first << " - " << p.second << endl;


	p = make_pair<int, int>(3, 3);
	cout << p.first << " - " << p.second << endl;



	list<int> A{ 6,3,4, 55, 4, 3 ,-1 };
	auto print_list = [](list<int> & A) {
		for (list<int>::iterator it = A.begin(); it != A.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	};
	print_list(A);
	A.pop_back();
	print_list(A);
	A.pop_front();
	print_list(A);
	A.push_back(2);
	print_list(A);
	A.push_front(555);
	print_list(A);
	A.sort();
	print_list(A);
	A.reverse();
	print_list(A);
	A.sort();
	print_list(A);
	A.erase(unique(A.begin(), A.end()), A.end());
	print_list(A);



	queue<int> q;
	q.push(44);
	q.push(2);
	q.push(33);
	q.push(-1);
	q.push(77);
	q.push(77);
	q.push(13);
	q.pop();
	auto print_queue = [](queue<int> q)
	{
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	};
	print_queue(q);
	print_queue(q);

	auto reverse_queue = [](queue<int> &q)
	{
		stack<int> st;
		while (!q.empty())
		{
			st.push(q.front());
			q.pop();
		}

		while (!st.empty())
		{
			q.push(st.top());
			st.pop();
		}
	};

	reverse_queue(q);
	print_queue(q);



	deque<int> deq;
	deq.push_back(5);
	deq.push_back(1);
	deq.push_back(8);
	deq.push_back(4);
	deq.push_back(3);
	deq.push_back(888);

	auto print_deque = [](const deque<int> & deq)
	{
		for (auto i : deq)
		{
			cout << i << " ";
		}
		cout << endl;
	};

	print_deque(deq);
	deq.pop_back();
	print_deque(deq);
	deq.pop_front();
	print_deque(deq);

	cout << deq.front() << " is at the front of the queue" << endl;



	cout << "All values in the deque is bigger than zero : " << all_of(deq.begin(), deq.end(), [](int i) {return i > 0; }) << endl;
	deq.push_back(-2);
	print_deque(deq);
	cout << "All values in the deque is bigger than zero : " << boolalpha << all_of(deq.begin(), deq.end(), greater_than_zero) << endl;

	cout << "There is an element with value 4 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 4; }) << endl;
	cout << "There is an element with value 74 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;
	cout << "There is no element with value 74 in list : " << none_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;

	cout << "Before incrementing list elements by 1: " << endl;
	print_list(A);
	cout << "Incrementing values in the list" << endl;
	for_each(A.begin(), A.end(), [](int &i) { i++; });
	print_list(A);

	for_each(A.begin(), A.end(), Incrementer<int>());
	print_list(A);
	for_each(A.begin(), A.end(), Incrementer<int>(4));
	print_list(A);

	Incrementer<int>(8)(*(A.begin()));
	*(A.begin()) += 8;
	print_list(A);




	// std::mismatch(..)
	//                          v                      v      Predicate is abs(diff) < 10
	vector<int> scores{ 50, 43, 22, 45, 99,    45, 38, 45, 67, 90 };

	using vIt = vector<int>::iterator;

	vIt first1 = scores.begin();
	vIt last1 = first1 + 5;;
	vIt first2 = last1;
	vIt last2 = first2 + 5;

	// Returns a pair of iterators for each range, which do not satisfy the predicate
	pair<vIt, vIt> mismatch_pair = mismatch(first1, last1, first2, last2, [](int &lhs, int &rhs) { return abs(lhs - rhs) < 10; });

	cout << "First mismatch: " << *(mismatch_pair.first) << " - " << *(mismatch_pair.second) << endl;

	// std::count()
	int count_ = count(scores.begin(), scores.end(), 45);
	cout << "Value 45 exists " << count_ << " times in scores vector" << endl;

	int count_2 = count_if(scores.begin(), scores.end(), [](int x) { return abs(45 - x) < 5; });
	cout << "There are " << count_2 << " items +-5 vicinity of 45" << endl;

	vector<int>::iterator it_for_38 = find(scores.begin(), scores.end(), 38);
	cout << *it_for_38 << endl;

	auto it_divisible_by_3 = find_if(scores.begin(), scores.end(), [](int x) { return x % 3 == 0; });
	if (it_divisible_by_3 != scores.end())
	{
		cout << "First value divisible by 3 is : " << *it_divisible_by_3 << endl;
	}

	// std::find_first_of(): Search elements of v1_source in v1_dest
	vector<int> v1_source{9 ,7, 10, 1, 857};
	vector<int> v1_dest{0, 2, 1, 4};

	vector<int>::iterator match_it = find_first_of(v1_source.begin(), v1_source.end(), v1_dest.begin(), v1_dest.end());
	if (match_it != v1_source.end()) {
		cout << "First matching valeu of v1_source is : " << *match_it << endl;
		cout << "It's distance from the beginning element of vector is : " << distance(v1_source.begin(), match_it) << endl;
	}

	// std::adjacent_find(): Find the first occurence of repeating values
	vector<int> v2{ 0, 2, 0, 2, 4, 4, 9 };
	auto adj_it = adjacent_find(v2.begin(), v2.end());
	cout << "First repeating adjacent element is : " << *adj_it << endl;


	// std::search() : searches the first occurrence of subsequence of elements
	const string source = "Sometimes the best practice is to rest";
	const string search_str = "best practice";
	auto sub_it = search(source.begin(), source.end(), search_str.begin(), search_str.end());
	if (sub_it != source.end())
	{
		cout << "\"best practice\" exists in string : " << endl;
		cout << source << endl;
		int dist = distance(source.begin(), sub_it);
		while (dist) { cout << " "; --dist; }
		cout << "^" << endl;
	}

}