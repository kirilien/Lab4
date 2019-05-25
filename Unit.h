#pragma once
#include <assert.h>
#include "pch.h"
#include "list_funcs.h"
#include "flight.h"
#include "dijkstra.h"
#include "adjacency.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;
void test_all() {
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);
	List<flight> flights_list;
	flight buffer;
	buffer.start = "�����-���������";
	buffer.finish = "������";
	buffer.price = 10;
	flights_list.push_back(buffer);

	buffer.start = "������";
	buffer.finish = "�����-���������";
	buffer.price = 20;
	flights_list.push_back(buffer);

	buffer.start = "������";
	buffer.finish = "���������";
	buffer.price = 40;
	flights_list.push_back(buffer);

	buffer.start = "���������";
	buffer.finish = "������";
	buffer.price = 35;
	flights_list.push_back(buffer);

	buffer.start = "�����-���������";
	buffer.finish = "���������";
	buffer.price = 14;
	flights_list.push_back(buffer);

	buffer.start = "���������";
	buffer.finish = "�����-���������";
	buffer.price = 10;
	flights_list.push_back(buffer);

	buffer.start = "�����������";
	buffer.finish = "���������";
	buffer.price = 13;
	flights_list.push_back(buffer);

	buffer.start = "���������";
	buffer.finish = "�����������";
	buffer.price = 8;
	flights_list.push_back(buffer);

	buffer.start = "�����-���������";
	buffer.finish = "�����������";
	buffer.price = 20;
	flights_list.push_back(buffer);

	buffer.start = "������";
	buffer.finish = "���������";
	buffer.price = 15;
	flights_list.push_back(buffer);

	dijkstra result1(flights_list);
	dijkstra result2(flights_list);
	string test1, test2;

	//---------------------------test 1 -adjuiced nodes with min price on their edge
	test1 = "�����-���������";
	test2 = "������";
	assert(result1.dij_shortest(test1, test2)==10);
	cout << "\ntest - simple adjuiced nodes - succsesful\n";

	//---------------------------test 2 -adjuiced nodes with not min price on their edge
	test1 = "������";
	test2 = "���������";
	assert(result2.dij_shortest(test1, test2) == 34);
	cout << "\ntest - complex adjuiced nodes - succsesful\n";
	//clrscr();
}