#include <fstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/csv/csv.hpp>


using namespace jsoncons; 

class Converter
{
private:
	//CSVCheckerAndUpdater obj;
public:
	ojson ConvertToJson(); // converts csv to json
};
