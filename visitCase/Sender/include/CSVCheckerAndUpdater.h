

class CSVCheckerAndUpdater
{
public:
	CSVCheckerAndUpdater() {}
	void ReadAndCheckRecord();  //reads and checks values in the records
	void UpdateRecord();  //writes into csv if required after taking from manual log reader
	~CSVCheckerAndUpdater() {}
};