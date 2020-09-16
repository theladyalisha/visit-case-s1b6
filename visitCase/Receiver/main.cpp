#include<iostream>
#include<DataReceiver.h>
#include<Aggregations.h>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
using namespace jsoncons;
using namespace std;

int main()
{
	DataReceiver obj;
	ojson jsonData=obj.ConvertToJson();
	vector<Data> d=obj.ReadJson(jsonData);
	Aggregations cobj;
	cobj.AvgFootfallPerHour(d);
	getchar();
	return 0;
}