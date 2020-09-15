#include <jsoncons/json.hpp>

class Person
{
	std::string time_id;
	int count;
	//std::string name_;
	//size_t year_;
	//double grade_;
public:
	const std::string& get_name() const
	{
		return name_;
	}
	void set_name(const std::string& value)
	{
		name_ = value;
	}
	size_t get_year() const
	{
		return year_;
	}
	void set_year(size_t value)
	{
		year_ = value;
	}
	double get_grade() const
	{
		return grade_;
	}
	void set_grade(double value)
	{
		grade_ = value;
	}
};

class Students
{
	std::vector<Person> students_;
public:
	Students(const std::vector<Person>& students)
	{
		students_ = students;
	}
	const std::vector<Person>& get_students() const { return students_; }
};

JSONCONS_ALL_GETTER_SETTER_NAME_TRAITS(Person, (get_name, set_name, "name"),
(get_year, set_year, "year"),
(get_grade, set_grade, "grade"))
JSONCONS_ALL_CTOR_GETTER_NAME_TRAITS(Students, (get_students, "students"))

const std::string input = R"(
{
    "Foot": [
        {
    "TIME_ID": "SEP010000",
    "ID": "1",
    "FROM": "0:00:00",
    "TO": "0:29:00",
    "DATE": "01-09-2020",
    "DAY": "THURSDAY",
    "COUNTS": "57"
  },
  {
    "TIME_ID": "SEP010030",
    "ID": "2",
    "FROM": "0:30:00",
    "TO": "0:59:00",
    "DATE": "01-09-2020",
    "DAY": "THURSDAY",
    "COUNTS": 
    ]
}
)";

int main()
{
	std::istringstream is(input);

	Students result = jsoncons::decode_json<Students>(is);

	std::cout << "(1)\n";
	for (const auto& person : result.get_students())
	{
		std::cout << person.get_name() << ", " << person.get_year() << ", " << person.get_grade() << "\n";
	}
	std::cout << "\n";

	std::ostringstream os;
	jsoncons::encode_json(result, os, jsoncons::indenting::indent);

	std::cout << "(2)\n";
	std::cout << os.str() << "\n";
	getchar();
}



//#include<iostream>
//#include <jsoncons/json.hpp>
//#include <jsoncons_ext/csv/csv.hpp>
//
//using namespace jsoncons;
//using namespace std;
//
//class Data
//{
//	string from_time;
//	string to_time;
//	string day;
//	int count;
//};
//int main()
//{
//
//	std::ifstream is("FootFallData.csv");
//
//	csv::csv_options options;
//	options.assume_header(true)
//		.trim(true)
//		.ignore_empty_values(true)
//		.column_types("string,string,string,string,string,string,string");
//	ojson tasks = csv::decode_csv<ojson>(is, options);
//	getchar();
//	return 0;
//}