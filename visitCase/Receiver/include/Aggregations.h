#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include<vector>
#include<DataReceiver.h>
using namespace jsoncons;

class Aggregations
{
//private:
	//vector<pair <string,string> >  v;
	
public:
	DataReceiver *obj;
	void AvgFootfallPerHour(vector<Data> v);  //avg footfall per hour over a day
	void AvgDailyFootfallInWeek(vector<Data> v);  //avg daily footfall in a week
};