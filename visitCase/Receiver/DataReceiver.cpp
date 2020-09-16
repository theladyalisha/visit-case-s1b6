#include<iostream>
#include<fstream>
#include <sstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include<DataReceiver.h>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>

using jsoncons::jsonpath::json_query;

using namespace jsoncons;
using namespace std;

//struct Data
//{
//public:
//
//	std::string from_time;
//	string to_time;
//	string date;
//	string day;
//	int count;
//}d;
//
//class DataReceiver :public Data
//{
//public:
//	ojson ConvertToJson();
//	void Aggregation1(ojson);  //avg footfall per hour over a day
//};
ojson DataReceiver::ConvertToJson()
{
	std::ifstream is("FootFallData.csv");

	csv::csv_options options;
	options.assume_header(true)
		.trim(true)
		.ignore_empty_values(true)
		.column_types("string,string,string,string,string,string,string");
	ojson tasks = csv::decode_csv<ojson>(is, options);
	//std::ofstream o("FootFallData.json");    //write json data to json file
	//o << std::setw(4) << tasks << std::endl;
	//std::cout << "(1)\n" << pretty_print(tasks) << "\n\n";
	return tasks;
}

vector<Data> DataReceiver::ReadJson(ojson tasks)
{
	vector<Data> v;
	for (std::size_t i = 0; i < tasks.size(); i++)
	{
		for (const auto& member : tasks[i].object_range())
		{
			string s = member.key();
			string x = member.value().as<std::string>();
			if (s == "FROM")
			{
				d.from_time = x;
				//cout <<"From time: "<< d.from_time<<endl;
			}
			else if (s == "TO")
			{
				d.to_time = x;
				//cout << d.to_time;
			}
			else if (s == "DATE")
			{
				d.date = x;
				//cout << d.date;
			}
			if (s == "COUNTS")
			{
				int y = stoi(x);
				d.count = y;
				//cout << "count="<< d.count;
			}
		}
		v.push_back(d);
	}
	return v;
}