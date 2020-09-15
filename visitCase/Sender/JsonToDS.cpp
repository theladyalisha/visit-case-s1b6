#include<iostream>
#include<fstream>
#include <sstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
using namespace std;

void Aggregation1(ojson tasks)
{
	for (const auto& member : tasks[2].object_range())
	{
		string s = member.key();
		if (s.compare("TimeId"))
			std::cout << member.key() << "=" << member.value() << std::endl;
	}
	getchar();
	return 0;
}