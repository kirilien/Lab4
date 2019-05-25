// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "list_funcs.h"
#include "flight.h"
#include "dijkstra.h"
#include "adjacency.h"
#include "Unit.h"
#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;

template <class T>
void separating_str(List<T> *graph_list);

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	
		cout << "\n";
		test_all();
		

	string str;
	List<string> *rec_list= new List<string>;

	ifstream in("input.txt");
	while (getline(in, str)) {
		rec_list->push_back(str);
		
	}
	
	
	separating_str(rec_list);
	_getch();
}
template <class T>
void separating_str(List<T> *rec_list) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List<flight> flights_list;// = new List<flight>;
	
	string temp_sep, sity1, sity2, pr1, pr2;
	int cost1, cost2, sublen;
	for (int i = 0; i < rec_list->get_size(); i++) {
		temp_sep = rec_list->at(i);
		//first sity

		sublen = temp_sep.find_first_of(";");
		sity1 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen+1);
		//second sity

		sublen = temp_sep.find_first_of(";");
		sity2 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen+1);
		//first price

		sublen = temp_sep.find_first_of(";");
		pr1 = temp_sep.substr(0, sublen);
		temp_sep.erase(0, sublen+1);
		if (pr1 == "N/A")
			cost1 = -1;
		else
			cost1 = atoi(pr1.c_str());

		//second price
		pr2 = temp_sep;
		if (pr2 == "N/A")
			cost2 = -1;
		else
			cost2 = atoi(pr2.c_str());

		//forming a flight-record
		if (cost1 > 0) {
			flight nextflight; 
			nextflight.start = sity1;
			nextflight.finish = sity2;
			nextflight.price = cost1;
			flights_list.push_back(nextflight);
		}
		if (cost2 > 0) {
			flight nextflight ; 
			nextflight.start = sity2;
			nextflight.finish = sity1;
			nextflight.price = cost2;
			flights_list.push_back(nextflight);
		}
	}
	//for (int i = 0; i < flights_list.get_size(); i++)
		//cout << flights_list.at(i);
	dijkstra result(flights_list);
	string point1, point2;
	cout << "\n";
	getline(cin, point1);
	getline(cin, point2);
	//adjacency *res = result.find(point1);
	result.dij_shortest(point1, point2);

	//flights_list.print_to_console();

}
