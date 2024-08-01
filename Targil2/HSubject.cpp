#pragma once
#include <iostream>
#include <string>
#include <list>
#include "HashTable.h"
#include "HSubject.h"
#include<algorithm>
using namespace std;


void HSubject::printS(string ky)
{
	int isExist = search(ky);
	if (isExist == -1)  //Checking if the key exists
	{
		cout << "ERROR" << endl;
		return;
	}
	int numOfTopic = arr[isExist].data.size();
	cout << "Subject " << arr[isExist].key << " " << numOfTopic << " topics:" << endl;
	for (list<string>::iterator it = arr[isExist].data.begin(); it != arr[isExist].data.end(); it++)
		cout << (*it) << " ";
	cout << endl;
}

void HSubject::printN(string ky, int N)
{
	int x = search(ky);
	if (x == -1)
		cout << "ERROR" << endl;
	else
	{
		int count = 0;
		for (list<string>::iterator iter = (arr[x].data).begin(); iter != (arr[x].data).end(); iter++)
		{
			count++;
			if (count > N)
				break;
			cout << *iter << " ";

		}
		cout << endl;

	}
}

void HSubject::print()
{
	cout << "All subjects and titles:" << endl;
	list<string> sortList;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag == full)
			sortList.push_back(arr[i].key);
	}
	sortList.sort();
	auto it = sortList.begin();
	while (it != sortList.end())
	{
		int n = search(*it);
		cout << *it << ": ";
		printN(*it, arr[n].data.size());
		it++;
	}
}

void HSubject::startNewTable()
{
	for (int i = 0; i < size; i++)
	{
		arr[i].flag = empty;
	}
}

void HSubject::addSubjectAndTitle(string s, string t)
{
	int index = search(s);
	if (index == -1)
	{
		list<string> ls;
		ls.push_back(t);
		add(s, ls);
	}
	else
		arr[index].data.push_front(t);
}
