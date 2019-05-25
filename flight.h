
#pragma once
#include <iostream>
#include <string>

using namespace std;

class flight
{
public:
	string start;
	string finish;

	int price;

	flight()
	{
		start = '\0';
		finish = '\0';
		price = 0;
	}
	friend ostream& operator << (ostream &s, const flight &ptOut)
	{
		s << "\nFrom: " << ptOut.start << " \nTo: " << ptOut.finish << " \nPrice: " << ptOut.price << " \n";
		return s;
	}
	~flight() {}
};