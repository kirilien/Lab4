#pragma once
#include <iostream>
#include <string>
#include "list_funcs.h"

using namespace std;

class adjacency
{
public:
	string departure;
	//bool checked=0;

	List<string> arrivals;
	List<int> arrival_prices;
	
	adjacency()
	{	
	}
	
	~adjacency() {}
};
class dijkstra_node
{
public:
	adjacency curr_node;
	int path_price;
	string path="\0";
	dijkstra_node(adjacency *curr_node, int path_price)
	{
		this->curr_node = *curr_node;

		this->path_price = path_price;
		for (int i = 0; i < curr_node->arrival_prices.get_size(); i++) {
			int curr_price = curr_node->arrival_prices.at(i) + path_price; //updating prices to arrivals - increasing they to (arrival(i)+path_price)
			curr_node->arrival_prices.set(i, curr_price);
		}

	}
	
	dijkstra_node() {}
	~dijkstra_node() {}
};

