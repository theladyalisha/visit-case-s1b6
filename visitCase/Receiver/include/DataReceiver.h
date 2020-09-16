#pragma once

#include<iostream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>
using namespace jsoncons;
using namespace std;

struct Data
{
public:
	string from_time;
	string to_time;
	string date;
	string day;
	int count;
};

class DataReceiver
{
public:
	Data d;
	ojson ConvertToJson();
	vector<Data> ReadJson(ojson);  //avg footfall per hour over a day
};