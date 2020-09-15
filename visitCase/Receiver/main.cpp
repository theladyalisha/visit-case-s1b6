#include<iostream>
#include<Aggregations.h>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
using namespace jsoncons;
using namespace std;

int main()
{
	Aggregations obj;
	ojson jsonData=obj.ConvertToJson();
	obj.Aggregation1(jsonData);
	//obj.check();
	getchar();
	return 0;
}