#include<iostream>
#include<fstream>
#include <sstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include<Aggregations.h>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>
#include <ctime>
#include <time.h> 
using jsoncons::jsonpath::json_query;

using namespace jsoncons;
using namespace std;


//ojson Aggregations::ConvertToJson()
//{
//	std::ifstream is("FootFallData.csv");
//
//	csv::csv_options options;
//	options.assume_header(true)
//		.trim(true)
//		.ignore_empty_values(true)
//		.column_types("string,string,string,string,string,string,string");
//	ojson tasks = csv::decode_csv<ojson>(is, options);
//	//std::ofstream o("FootFallData.json");    //write json data to json file
//	//o << std::setw(4) << tasks << std::endl;
//	//std::cout << "(1)\n" << pretty_print(tasks) << "\n\n";
//	return tasks;
//}




void Aggregations::AvgFootfallPerHour(vector<Data> v)
{

	double avg;
	long int sum;
	double no_of_entries_of_day = 48;
	cout << "Average footfall per hour\n";
	for (int j = 0; j < v.size(); j += 48)
	{
		sum = 0;
		for (int i = j; i < j + 48; i++)
		{
			sum += v[i].count;
		}
		avg = sum / 24;
		cout << avg<<"\n";
	}
}
