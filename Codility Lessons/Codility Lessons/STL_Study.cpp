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
#include <set>


using namespace std;

// Predicate
bool greater_than_zero(int i) { return i > 0; }


void STL_Study::containers_run()
{
	cout << "\n\n" << "STL CONTAINER OPERATIONS" << "__________________________\n" << endl;

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




	// std::priority_queue: keeps the underlying data in order (with default greater compare, or the comparer you provide)
	auto print_pqueue = [](priority_queue<int> &pq)
	{
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	};

	priority_queue<int> pq;
	for(int x : { 1, 8, 5, 6, 3, 4, 0, 9, 7, 2 })
	{
		pq.push(x);
	}


	print_pqueue(pq);

	// Specifying the underlying container and comparer
	auto cmp = [](int lhs, int rhs) { return rhs < lhs; };
	priority_queue<int, vector<int>,  decltype(cmp)> pq2(cmp);
	for (int y : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
	{
		pq2.push(y);
	}
	priority_queue<int, vector<int>, decltype(cmp)> temp = pq2;
	while(!temp.empty())
	{
		cout << temp.top() << " ";
		temp.pop();
	} cout << endl;





	// std::set : stores unique elements following a specific order
	int myints[] = { 1,4,2,8,20,3,45,1 };
	set<int> myset(myints, myints+4);
	auto print_set = [](set<int> &myset)
	{
		for (auto i : myset)
		{
			cout << i << " ";
		}cout << endl;
	};
	print_set(myset);

	myset.insert(6);
	print_set(myset);
	//auto it_set = myset.find(4);		// This works
	//auto it_set = find(myset.begin(), myset.end(), 4);   // This works
	auto it_set = find(begin(myset), end(myset), 4);    // This works
	if (it_set != myset.end())
	{
		myset.erase(it_set);
	}
	print_set(myset);

	set<int> myset2(myints + 4, myints + 8);
	myset.swap(myset2);
	print_set(myset);
	myset.insert(1);  // 1 is already in set, so it is not added (elements are unique in set)
	print_set(myset);
	cout << "Size of myset is : " << myset.size() << endl;
	for (auto & x : myset) cout << x << " ";
	cout << endl;
	for (auto & x : myset) cout << x << " ";
	cout << endl;


}

void STL_Study::algorithms_sequence_operations_run()
{
	cout << "\n\n\n" << "ALGORITHMS SEQUENCE OPERATIONS" << "__________________________\n" << endl;
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
	cout << "All values in the deque is bigger than zero : " << all_of(deq.begin(), deq.end(), [](int i) {return i > 0; }) << endl;
	deq.push_back(-2);
	print_deque(deq);
	cout << "All values in the deque is bigger than zero : " << boolalpha << all_of(deq.begin(), deq.end(), greater_than_zero) << endl;
	list<int> A{ 6,3,4, 55, 4, 3 ,-1 };
	cout << "There is an element with value 4 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 4; }) << endl;
	cout << "There is an element with value 74 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;
	cout << "There is no element with value 74 in list : " << none_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;


	auto print_list = [](list<int> & A) {
		for (list<int>::iterator it = A.begin(); it != A.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	};

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

	// std::find_end(..): Find the last sequence that matches the given vector
	vector<int> v_{ 0,0,0,0,1,1,0,0,1,1,0,1 };
	vector<int> t_{ 1,1,0 };
	cout << "Searching for the last occurence of pattern: ";
	for (auto &x : t_) { cout << x; } cout << endl;
	auto it_end = find_end(v_.begin(), v_.end(), t_.begin(), t_.end());
	if (it_end != v_.end())
	{
		for (auto &x : v_) { cout << x; } cout << endl;
		int dist = distance(v_.begin(), it_end);
		while (dist) { cout << " "; --dist; }
		cout << "^" << endl;
	}

	// std::find_first_of(): Search elements of v1_source in v1_dest
	vector<int> v1_source{ 9 ,7, 10, 1, 857 };
	vector<int> v1_dest{ 0, 2, 1, 4 };

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

	// std::search_n(..) : find count of consecutive values
	vector<int> v3{ 0,0,0,1,0,1,1,0,1,1,1,0,1 };
	auto it_con = search_n(v3.begin(), v3.end(), 3, 1);
	if (it_con != v3.end())
	{
		cout << "Found 3 consecutive 1's in v3 vector" << endl;
		for (auto x : v3) cout << x;
		cout << endl;
		int dist = distance(v3.begin(), it_con);
		while (dist) { cout << " "; --dist; }
		cout << "^" << endl;
	}
}


template <typename T, int size>
int arr_size(T(&arr)[size])
{
	return size;
}

class Empty {};
void STL_Study::algoirthms_sorting_operations_run()
{
	cout << "\n\n\n" << "ALGORITHMS SORTING OPERATIONS" << "__________________________\n" << endl;

	auto print_vector = [](vector<int> &v)
	{
		for (auto & x : v) { cout << x << " "; }
		cout << endl;
	};


	int a[] = { 4,1,2,6,22,10 };
	cout << "Array size: " << arr_size(a);
	cout << "\n" << "Array before sort: \n\t";
	for (auto i : a) { cout << i << " "; }

	sort(a, a + (sizeof(a)/sizeof(int)));
	cout << "\n" << "Array after sort: \n\t";
	for (auto i : a) { cout << i << " "; } cout << endl;
	for (int * it = a; it != a + (sizeof(a) / sizeof(int)); ++it)
	{
		cout << *it << " ";
	}

	int b[] = { 1,5,2 };
	// sizes are different therefore different types
	cout << "Types of a and b arrays are equal : " << boolalpha << (typeid(a) == typeid(b)) << endl;
	cout << "a[int] type is : " << typeid(a).name() << endl;  // int [6]
	cout << "b[int] type is : " << typeid(b).name() << endl;  // int [3]


	int c[] = {0,0,1};
	// sizes are the same therefore same types
	cout << "Types of b and c arrays are equal : " << boolalpha << (typeid(b) == typeid(c)) << endl;
	cout << "b[int] type is : " << typeid(b).name() << endl;  // int [6]
	cout << "c[int] type is : " << typeid(c).name() << endl;  // int [3]


	// check if range is sorted in ascending order
	vector<int> v{8,4,17,0,1,5};
	cout << "Before sort___________:" << endl;
	print_vector(v);
	sort(v.begin(), v.end() - 2);
	cout << "After sort___________:" << endl; 
	print_vector(v);

	cout << "Vector is sorted in range v.begin() - (v.end() - 2) : " << boolalpha << is_sorted(v.begin(), v.end() - 2) << endl;
	cout << "Vector is sorted in range v.begin() - v.end() : " << boolalpha << is_sorted(v.begin(), v.end()) << endl;

	// find the iterator where the vector is sorted until
	vector<int>::iterator it = is_sorted_until(v.begin(), v.end());
	int dist = distance(v.begin(), it);
	print_vector(v);
	while (dist--) cout << "  "; cout << "^" << endl;
	cout << "Vector is sorted until: " << *it << endl;




	// nth element: it finds the nth element that would be at position n if the list was sorted.
	// note that the implementation doesn't have to sort the list fully, it can bail out whenever it is sure what the 
	// nth element will be.
	// "std::sort sorts all the elements. std::nth_elenemt doesn't. It just puts the nth element in the nth positions, 
	// with smaller or equal elements on one side and larger or equal elements on the other. It is used if you want to 
	// find the nth element (obviously) or if you want the n smallest or largest elements. A full sort satisfies these 
	// requirements."
	std::vector<int> v3{ 9,3,6,2,1,7,8,5,4,0 };

	std::nth_element(v3.begin(), v3.begin() + v3.size() / 2, v3.end());
	std::cout << "The median is " << v3[v3.size() / 2] << '\n';

	std::nth_element(v3.begin(), v3.begin() + 1, v3.end(), std::greater<int>());
	std::cout << "The second largest element is " << v3[1] << '\n';
	print_vector(v3);
	cout << "Note that the vector is sorted for this example BUT IT DIDN'T HAVE TO BE!" << endl;

	// Compiler dependent but usually 1 byte. This is required to be able to differentiate two different "Empty" objects.
	cout << "Size of an empty class: " << sizeof(Empty) << endl;
}
