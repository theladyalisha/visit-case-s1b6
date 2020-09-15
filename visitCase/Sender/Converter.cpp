//#include <fstream>
//#include <jsoncons/json.hpp>
//#include <jsoncons_ext/csv/csv.hpp>
//
//using namespace jsoncons;

#include<Converter.h>

using namespace std;

ojson Converter::ConvertToJson()
{
	std::ifstream is("FootFallData.csv");

	csv::csv_options options;
	options.assume_header(true)
		.trim(true)
		.ignore_empty_values(true)
		.column_types("string,string,string,string,string,string,string");
	ojson tasks = csv::decode_csv<ojson>(is, options);
	std::ofstream o("FootFallData.json");    //write json data to json file
	o << std::setw(4) << tasks << std::endl;
	std::cout << "(1)\n" << pretty_print(tasks) << "\n\n";
	return tasks;
	
}