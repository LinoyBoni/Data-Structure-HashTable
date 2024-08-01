#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "HashTable.h"
#include<algorithm>


template<typename T, typename K>
inline bool HashTable<T, K>::prime(int n)
{
	int c = 0;

	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
			c++;
	}

	if (c > 0) {
		return false;
	}
	return true;
}

template<typename T, typename K>
inline int HashTable<T, K>::hash(K key, int i)
{
	return ((h1(key) + i * h2(key)) % size);
	return 0;
}

template<typename T, typename K>
inline HashTable<T, K>::HashTable(int m)
{
	while (prime(m) == false)
	{
		m++;
	}
	size = m;
	arr = new Item<T, K>[size];
}

template<typename T, typename K>
inline HashTable<T, K>::~HashTable()
{
	if (arr) {
		delete[]arr;
	}
	arr = nullptr;
}

template<typename T, typename K>
inline void HashTable<T, K>::add(K& key, T& dat)
{
	int x = h1(key);
	Item<T, K> t;
	t.data = data;
	t.key = key;
	t.flag = full;
	int i = 0;
	while (arr[x].flag == full)
	{
		i++;
		x = hash(key, i);
	}
	arr[x] = t;
	return;
}

template<typename T, typename K>
inline int HashTable<T, K>::remove(K key)
{
	int x = search(k);
	if (arr[x].flag == full)
	{
		arr[x].flag = deleted;
	}
	return 0;
}

template<typename T, typename K>
inline int HashTable<T, K>::search(K key)
{
	return 0;
}

template<typename T, typename K>
inline void HashTable<T, K>::print()
{
	list<string> list1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag == full)
			list1.push_front(arr[i].key);
	}
	list1.sort();
	for (list<string>::iterator iter = list1.begin(); iter != list1.end(); iter++)
	{

		cout << *iter << " ";
		cout << endl;
	}
}

