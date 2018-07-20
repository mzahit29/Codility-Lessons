#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <stack>

using namespace std;

class Utility
{
	static int counter_;
public:
	template <typename T>
	static void print_vector(const vector<T> &v);
	template <typename T>
	static void print_list(const list<T> &l);
	template <typename T>
	static void print_queue(const queue<T> &q);
	template <typename T>
	static void print_deque(const deque<T> &d);
	template <typename T>
	static void print_pqueue(const priority_queue<T> &pq);
	template <typename T>
	static void print_set(const set<T> &set);
	template <typename T>
	static void reverse_queue(queue<T> &q);
	template <typename T, size_t size>
	static size_t array_size(T(&arr)[size]);
	template <typename T, size_t size>
	static void print_array(T(&arr)[size]);

	static int get_id();
};

inline int Utility::get_id()
{
	return ++counter_;
}

int Utility::counter_ = 0;

template <typename T>
void Utility::print_vector(const vector<T>& v)
{
	for (auto &x : v)
	{
		cout << " " << x;
	} cout << endl;
}

template <typename T>
void Utility::print_list(const list<T>& l)
{
	for (auto &x : l)
	{
		cout << " " << x;
	} cout << endl;
}

template <typename T>
void Utility::print_queue(const queue<T>& q)
{
	queue<T> temp = q;
	while (!temp.empty())
	{
		cout << " " << temp.front();
		temp.pop();
	} cout << endl;
}

template <typename T>
void Utility::print_deque(const deque<T>& d)
{
	for (auto &x : d)
	{
		cout << " " << x;
	} cout << endl;
}

template <typename T>
void Utility::print_pqueue(const priority_queue<T>& pq)
{
	priority_queue<T> temp = pq;
	while(!temp.empty())
	{
		cout << " " << temp.top();
		temp.pop();
	} cout << endl;
}

template <typename T>
void Utility::print_set(const set<T>& set)
{
	for (auto &x : set)
	{
		cout << " " << x;
	} cout << endl;
}

template <typename T>
void Utility::reverse_queue(queue<T>& q)
{
	stack<T> st;
	while(!q.empty())
	{
		st.push(q.front());
		q.pop();
	}

	while(!st.empty())
	{
		q.push(st.top());
		st.pop();
	}
}

template <typename T, size_t size>
size_t Utility::array_size(T(&arr)[size])
{
	return size;
}

template <typename T, size_t size>
void Utility::print_array(T(& arr)[size])
{
	// Range based
	//for (auto i : arr)
	//{
	//	cout << " " << i;
	//} cout << endl;

	// OR with iterator (note that size is captured as template parameter)
	for (T * it = arr; it != arr + size; ++it)
	{
		cout << *it << " ";
	}
}


