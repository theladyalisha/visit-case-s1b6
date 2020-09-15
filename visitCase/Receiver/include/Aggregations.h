#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include<vector>
using namespace jsoncons;

class Aggregations
{
//private:
	//vector<pair <string,string> >  v;

public:
	ojson ConvertToJson();
	void check();
	void Aggregation1(ojson);  //avg footfall per hour over a day
};