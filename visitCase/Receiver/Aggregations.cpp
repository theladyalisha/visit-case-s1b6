#include<iostream>
#include<fstream>
#include <sstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
//#include<Aggregations.h>
#include <type_traits>
#include <typeinfo>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>

using jsoncons::jsonpath::json_query;

using namespace jsoncons;
using namespace std;

class Data
{
public:
	//std::string time_id;
	std::basic_string<char, struct std::char_traits<char>> from_time;
	string to_time;
	string date;
	string day;
	int count;
};

class Aggregations:public Data
{
	//private:
	//vector<pair <string,string> >  v;

public:
	Data d;
	ojson ConvertToJson();
	void Aggregation1(ojson);  //avg footfall per hour over a day
	void check();
};
ojson Aggregations::ConvertToJson()
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
	cout<<tasks.as_string();
	return tasks;
}

void Aggregations::Aggregation1(ojson tasks)
{
	//vector<pair<string, int>> v;
	//pair<string, int>p;
	vector<string>v;
	string str;
	for (std::size_t i = 0; i < tasks.size(); i++)
	{
		for (const auto& member : tasks[i].object_range())
		{
			string s = member.key();
			string x = member.value().as<std::string>();
			//cout << typeid(x).name()<<endl;
			if (s == "FROM")
			{
				v.push_back(x);
			}
			/*else if (s == "TO")
			{
				d.to_time = x;
				cout << d.to_time;
			}
			else if (s == "DATE")
			{
				
				d.date = x;
				cout << d.date;
			}*/
			if(s=="COUNTS")
			{	
				int y = stoi(x);
				d.count = y;
				//v[i].second = y;
				cout << "count="<< d.count;
			}
		}
		//v.push_back(make_pair(x, y));
		
	}
	/*for (auto i : v)
	{
		cout << i.count<<" "<<i.from_time<<"\n";
	}*/
}

void Aggregations::check()
{
	cout << "hello";
	std::ifstream is("FootFallData.json");
	json booklist = json::parse(is);
	json result6 = json_query(booklist, "$.TIME_ID");
	cout << "(6)\n" << pretty_print(result6) << std::endl;
}