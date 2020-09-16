#include <fstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>
#include<CSVCheckerAndUpdater.h>

using namespace jsoncons; 

class Converter:public CSVCheckerAndUpdater
{
private:
	//CSVCheckerAndUpdater obj;
public:
	ojson ConvertToJson(); // converts csv to json
};
