#include "stdafx.h"
#include "STL_Study.h"
#include "Utility.h"

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
#include <iterator>
#include <functional>


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



	list<int> A{ 6, 3, 4, 55, 4, 3 ,-1 };
	
	Utility::print_list(A);
	A.pop_back();
	Utility::print_list(A);
	A.pop_front();
	Utility::print_list(A);
	A.push_back(2);
	Utility::print_list(A);
	A.push_front(555);
	Utility::print_list(A);
	A.sort();
	Utility::print_list(A);
	A.reverse();
	Utility::print_list(A);
	A.sort();
	Utility::print_list(A);
	A.erase(unique(A.begin(), A.end()), A.end());
	Utility::print_list(A);



	queue<int> q;
	q.push(44);
	q.push(2);
	q.push(33);
	q.push(-1);
	q.push(77);
	q.push(77);
	q.push(13);
	q.pop();

	Utility::print_queue(q);
	Utility::print_queue(q);


	cout << "Reversing queue: " << endl;
	Utility::reverse_queue(q);
	Utility::print_queue(q);



	deque<int> deq;
	deq.push_back(5);
	deq.push_back(1);
	deq.push_back(8);
	deq.push_back(4);
	deq.push_back(3);
	deq.push_back(888);

	Utility::print_deque(deq);
	deq.pop_back();
	Utility::print_deque(deq);
	deq.pop_front();
	Utility::print_deque(deq);

	cout << deq.front() << " is at the front of the queue" << endl;




	// std::priority_queue: keeps the underlying data in order (with default greater compare, or the comparer you provide)
	priority_queue<int> pq;
	for(int x : { 1, 8, 5, 6, 3, 4, 0, 9, 7, 2 })
	{
		pq.push(x);
	}


	Utility::print_pqueue(pq);

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
		cout << " " << temp.top();
		temp.pop();
	} cout << endl;





	// std::set : stores unique elements following a specific order
	int myints[] = { 1,4,2,8,20,3,45,1 };
	set<int> myset(myints, myints+4);

	Utility::print_set(myset);

	myset.insert(6);
	Utility::print_set(myset);
	//auto it_set = myset.find(4);		// This works
	//auto it_set = find(myset.begin(), myset.end(), 4);   // This works
	auto it_set = find(begin(myset), end(myset), 4);    // This works
	if (it_set != myset.end())
	{
		myset.erase(it_set);
	}
	Utility::print_set(myset);

	set<int> myset2(myints + 4, myints + 8);
	myset.swap(myset2);
	Utility::print_set(myset);
	myset.insert(1);  // 1 is already in set, so it is not added (elements are unique in set)
	Utility::print_set(myset);
	cout << "Size of myset is : " << myset.size() << endl;
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

	cout << "All values in the deque is bigger than zero : " << all_of(deq.begin(), deq.end(), [](int i) {return i > 0; }) << endl;
	deq.push_back(-2);
	Utility::print_deque(deq);
	cout << "All values in the deque is bigger than zero : " << boolalpha << all_of(deq.begin(), deq.end(), greater_than_zero) << endl;
	list<int> A{ 6,3,4, 55, 4, 3 ,-1 };
	cout << "There is an element with value 4 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 4; }) << endl;
	cout << "There is an element with value 74 in list : " << any_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;
	cout << "There is no element with value 74 in list : " << none_of(A.begin(), A.end(), [](int i) { return i == 74; }) << endl;

	cout << "Before incrementing list elements by 1: " << endl;
	Utility::print_list(A);
	cout << "Incrementing values in the list" << endl;
	for_each(A.begin(), A.end(), [](int &i) { i++; });
	Utility::print_list(A);

	for_each(A.begin(), A.end(), Incrementer<int>());
	Utility::print_list(A);
	for_each(A.begin(), A.end(), Incrementer<int>(4));
	Utility::print_list(A);

	Incrementer<int>(8)(*(A.begin()));
	*(A.begin()) += 8;
	Utility::print_list(A);




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
		Utility::print_vector(v3);
		int dist = distance(v3.begin(), it_con);
		while (dist) { cout << "  "; --dist; }
		cout << " ^" << endl;
	}
}


class A
{
	static int counter_;
public:
	int id;
	int stored_val;
	A() : id(++counter_) { cout << "A() " << id << endl; }
	A(int x) : stored_val(x), id(++counter_) { cout << "A(int x) " << id << endl; }
	A(const A &other) : id(++counter_) { cout << "A(const A &other) " << id << endl; }
	//A(A &&other) : id(other.id) { other.id = -1; cout << "A(A &&other) " << id << endl; }
	A& operator=(const A &other) { id = ++counter_;  cout << "operator=(const A &other) " << id << endl; return *this; }
	//A& operator=(A &&other) { id = other.id; other.id = -1; cout << "operator=(A &&other) " << id << endl; return *this; }
	~A() { cout << "~A()" << endl; }
	friend ostream & operator<<(ostream& out, const A& obj)
	{
		return out << "A object with id : " << obj.id << endl;
	}

};

int A::counter_ = 0;

// Example functional implementation
template <typename T>
class my_less
{
public:
	bool operator()(const T &lhs, const T &rhs)
	{
		return lhs < rhs;
	}
};

void STL_Study::algorithms_modifying_sequence_operations_run()
{
	cout << "\n\n\n" << "ALGORITHMS MODIFYING SEQUENCE OPERATIONS" << "__________________________\n" << endl;

	// COPYING A VECTOR
	vector<char> v{ 'a', 's', 'm', 'l' };
	// Method 1
	vector<char> v_dest = v;
	// OR Method 2
	//vector<char> v_dest;
	// If you do not use back_inserter program will crash! Because destination vector has 0 elements and copy is trying
	// to dereference the empty vector's iterator which is nullptr.
	// Using back_inserter(Container &) or back_insert_iterator<..>(Container)
	// back_inserter is a convenience function template that constructs a std::back_insert_iterator 
	// for the container c with the type deduced from the type of the argument.
	// std::back_insert_iterator is an OutputIterator that appends to a container for which it was constructed.
	// The container's push_back() member function is called whenever the iterator (whether dereferenced or not)
	// is assigned to. Incrementing the std::back_insert_iterator is a no-op.
	//copy(v.begin(), v.end(), back_inserter(v_dest)); 
	// OR Method 3
	//vector<char> v_dest(v.size());  // You have to allocate enough space if back_inserter is not used.
	//copy(v.begin(), v.end(), v_dest.begin());

	Utility::print_vector<char>(v_dest);

	// COPYING A VECTOR copy_if(..)
	vector<char> v_dest_2;
	copy_if(v.begin(), v.end(), back_inserter(v_dest_2), [](char c) { return c < 'm'; });
	//copy_if(v.begin(), v.end(), back_insert_iterator<decltype(v_dest_2)>(v_dest_2), [](char c) { return c < 'm'; });
	Utility::print_vector(v_dest_2);


	// HOW COPY IS IMPLEMENTED INTERNALLY:
	//vector<int> v_s{1,1,0};
	//vector<int> v_d;
	//auto input_it = v_s.begin();
	//auto input_last = v_s.end();
	//auto output_it = v_d.begin();

	//// How copy works
	//while(input_it != input_last)
	//{
	//	*output_it++ = *input_it++;  // output_it dereference will crash the program since it is nullptr
	//}


	// copy_n(..)
	vector<int> scores{ 0, 20, 14, 13, 22, 14 };
	vector<int> scores_copy;
	copy_n(scores.begin(), 3, back_inserter(scores_copy));
	Utility::print_vector(scores_copy);


	// copy_backward(..) => doesn't reverse the order of the elements, simply reverses the order of transfer
	vector<int> scores_backward(scores.size());
	copy_backward(scores.begin(), scores.end(), scores_backward.end());
	Utility::print_vector(scores_backward);


	// move(..) => triggers the move constructor of elements. 
	vector<A> v_A(4), v_A_dest(4); // Triggers 4 + 4 constructors of A class

	cout << "Moving vector" << endl;
	move(v_A.begin(), v_A.end(), v_A_dest.begin());  // Triggers move operator
	cout << "Move doesn't empty the source vector, it copies with *d_first++ = std::move(*first++),\n";
	cout << "turning the object to r-value reference using move and thereby triggering the move constructor\n";
	cout << "In our example, objects residing in source vector after being moved with move operator their id is set to -1" << endl;
	cout << "Source vector with size: " << v_A.size() << " => " << endl;
	Utility::print_vector(v_A);
	cout << "Destination vector with size: " << v_A_dest.size() << " => " << endl;
	Utility::print_vector(v_A_dest);

	// move_backward(..) => moves from last to first order
	cout << "Moving backwards\n";
	move_backward(v_A_dest.begin(), v_A_dest.end(), v_A.end());
	Utility::print_vector(v_A);
	Utility::print_vector(v_A_dest);

	// fill(..) => copy assigns the value to the vector range
	cout << "Filling vector\n";
	fill(v_A_dest.begin(), v_A_dest.end(), A());
	Utility::print_vector(v_A_dest);
	
	// fill_n(..) => copy assigns to n elements starting from the given iterator
	cout << "Filling n elements of vector\n";
	fill_n(v_A_dest.begin(), 2, A());
	Utility::print_vector(v_A_dest);


	// transform(..) => applies given function to a range and stores the result in another range
	cout << "Transforming first 2 elements of vector\n";
	transform(v_A_dest.begin(), v_A_dest.begin() + 2, v_A_dest.begin() + 2, [](A& obj) -> A { A temp(obj); temp.id = temp.id * 100 + obj.id; return temp; });
	Utility::print_vector(v_A_dest);

	string s("Hello algorithms");
	cout << R"(Transforming: ")" << s << R"(")";
	size_t pos = s.find("algo");
	auto it_begin = s.begin() + pos;
	//transform(it, s.end(), it, [](unsigned char c) -> unsigned char { return toupper(c); }); // Lambda version
	transform(it_begin, s.end(), it_begin, toupper);
	cout << R"( => ")" << s << R"(")" << endl;

	// generate(..) => assigns the result of successive function calls to every element in a range
	vector<int> points{ 10, 5, 20, 13, 34, 55, 0 };
	cout << "generate(..)\n";
	Utility::print_vector(points);
	generate(points.begin() + 2, points.end(), Utility::get_id);
	Utility::print_vector(points);

	// generate_n(..)
	cout << "generate_n(..)\n";
	generate_n(points.begin(), 2, Utility::get_id);
	Utility::print_vector(points);

	// remove  (erase-remove-idiom) => remove returns the Past-the-end iterator for the new range of values 
	cout << "remove(..)\n"; 
	points.erase(remove(points.begin(), points.end(), 22), points.end());
	Utility::print_vector(points);

	// remove_if
	cout << "remove_if(..)\n";
	points.erase(remove_if(points.begin(), points.end(), [](int i) {return i % 3 == 0; }), points.end());
	Utility::print_vector(points);

	// remove_copy(..) => copies a range of elements omitting those that are equal to the value given as last parameter
	cout << "remove_copy(..)\n";
	vector<int> copy_points;
	remove_copy(points.begin(), points.end(), back_inserter(copy_points), 7);
	Utility::print_vector(copy_points);

	string text{ "Text with     some                spaces" };
	cout << "Before: " << text << endl;
	cout << "After: " << endl;
	remove_copy(text.begin(), text.end(), ostream_iterator<char>(cout), ' ');
	cout << '\n';

	// remove_copy_if(..) => copies a range of elements omitting those that satisfy predicate
	cout << "remove_copy_if(..)\n";
	vector<int> copy_if_ints{ 1,2,3,4,5,6 };
	vector<int> copy_if_ints_dest;
	remove_copy_if(copy_if_ints.begin(), copy_if_ints.end(), back_inserter(copy_if_ints_dest), [](int x) { return x < 4; });
	Utility::print_vector(copy_if_ints);
	Utility::print_vector(copy_if_ints_dest);


	// replace(..) => replaces the value given to another value on the same vector
	cout << "replace(..)\n";
	vector<int> replace_ints{ 1,2,3,4,5,6 };
	cout << "Before replace: ";
	Utility::print_vector(replace_ints);
	replace(replace_ints.begin(), replace_ints.end(), 2, 22);
	cout << "After replace: ";
	Utility::print_vector(replace_ints);

	// replace_if(..) => replaces the values satisfying the criteria to another value on the same vector
	cout << "replace(..)\n";
	vector<int> replace_if_ints{ 1,2,3,4,5,6 };
	cout << "Before replace: ";
	Utility::print_vector(replace_ints);
	replace_if(replace_if_ints.begin(), replace_if_ints.end(), [](int x) { return x % 3 == 0; }, 88);
	// using a functional class to use as a predicate. my_less requires to parameters to compare, but we want to turn it into
	// a function which only takes one argument and returns true if it is less than 5
	//cout << "3 is less than 5 : " << boolalpha << my_less<int>()(3, 5) << endl;
	cout << "After replace: ";
	Utility::print_vector(replace_if_ints);
	// Using std::less<T>
	//replace_if(replace_if_ints.begin(), replace_if_ints.end(), std::bind(std::less<int>(), std::placeholders::_1, 5), -1);
	// Using our own my_less<T> functional
	replace_if(replace_if_ints.begin(), replace_if_ints.end(), std::bind(my_less<int>(), std::placeholders::_1, 5), -1);
	cout << "After replace: ";
	Utility::print_vector(replace_if_ints);


	// replace_copy(..) => copies a range but replaces the ones with certain value in destination
	cout << "replace_copy(..)\n";
	vector<int> replace_copy_ints{ 1,2,3,4,5,6,7,8 };
	vector<int> replace_copy_ints_dest;
	replace_copy(replace_copy_ints.begin(), replace_copy_ints.end(), back_inserter(replace_copy_ints_dest), 2, 99);
	Utility::print_vector(replace_copy_ints);
	Utility::print_vector(replace_copy_ints_dest);

	// replace_copy_if(..) => copies a range but replaces the ones that satisfy the predicate
	cout << "replace_copy_if(..)\n";
	vector<int> replace_copy_if_ints{ 1,2,3,4,5,6,7,8 };
	vector<int> replace_copy_if_ints_dest;
	replace_copy_if(replace_copy_if_ints.begin(), replace_copy_if_ints.end(), back_inserter(replace_copy_if_ints_dest),
		std::bind(std::greater_equal<int>(), std::placeholders::_1, 5), 114);
	Utility::print_vector(replace_copy_if_ints);
	Utility::print_vector(replace_copy_if_ints_dest);


	// swap(..) => object has to be move constructibe and move assignable.
	cout << "swap(..)\n";
	A a{ 7 }, b{ 44 };
	cout << "Before swap\t" << "a: " << a << " b: " << b << endl;
	swap(a, b);
	cout << "After swap\t" << "a: " << a << " b: " << b << endl;


}


class Empty {};
void STL_Study::algoirthms_sorting_operations_run()
{
	cout << "\n\n\n" << "ALGORITHMS SORTING OPERATIONS" << "__________________________\n" << endl;

	int a[] = { 4, 1, 2, 6, 22, 10 };
	cout << "Array size: " << Utility::array_size(a);
	cout << "\n" << "Array before sort: \n\t";
	Utility::print_array(a);

	// Remember sort expects beginning and ending iterators. In arrays the pointers are treated as iterators.
	sort(a, a + (sizeof(a)/sizeof(int)));
	cout << "\n" << "Array after sort: \n\t";
	Utility::print_array(a);


	int b[] = { 1, 5, 2 };
	// sizes are different therefore different types
	cout << "Types of a and b arrays are equal : " << boolalpha << (typeid(a) == typeid(b)) << endl;
	cout << "a[int] type is : " << typeid(a).name() << endl;  // int [6]
	cout << "b[int] type is : " << typeid(b).name() << endl;  // int [3]


	int c[] = { 0, 0, 1 };
	// sizes are the same therefore same types
	cout << "Types of b and c arrays are equal : " << boolalpha << (typeid(b) == typeid(c)) << endl;
	cout << "b[int] type is : " << typeid(b).name() << endl;  // int [6]
	cout << "c[int] type is : " << typeid(c).name() << endl;  // int [3]


	// check if range is sorted in ascending order
	vector<int> v{ 8, 4, 17, 0, 1, 5 };
	cout << "Before sort___________:" << endl;
	Utility::print_vector(v);
	sort(v.begin(), v.end() - 2);
	cout << "After sort___________:" << endl; 
	Utility::print_vector(v);

	cout << "Vector is sorted in range v.begin() - (v.end() - 2) : " << boolalpha << is_sorted(v.begin(), v.end() - 2) << endl;
	cout << "Vector is sorted in range v.begin() - v.end() : " << boolalpha << is_sorted(v.begin(), v.end()) << endl;

	// find the iterator where the vector is sorted until
	vector<int>::iterator it = is_sorted_until(v.begin(), v.end());
	int dist = distance(v.begin(), it);
	Utility::print_vector(v);
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
	Utility::print_vector(v3);
	cout << "Note that the vector is sorted for this example BUT IT DIDN'T HAVE TO BE!" << endl;

	// Compiler dependent but usually 1 byte. This is required to be able to differentiate two different "Empty" objects.
	cout << "Size of an empty class: " << sizeof(Empty) << endl;
}
