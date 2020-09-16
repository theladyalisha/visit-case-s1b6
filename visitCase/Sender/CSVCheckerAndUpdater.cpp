#include<CSVCheckerAndUpdater.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>
#include <sstream>
using namespace std;

void CSVCheckerAndUpdater::ReadAndCheckRecord()
{
	ifstream csvFile;
	csvFile.open("FootFallData.csv");
	if (!csvFile.is_open())
	{
		cout << "Path Wrong!!!!" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	getline(csvFile, line); // skip the 1st line

	while (getline(csvFile, line))
	{
		if (line.empty()) // skip empty lines:
		{
			cout << "empty line!" << endl;
			continue;
		}
		istringstream iss(line);
		string lineStream;

		vector <string> row;
		vector <vector<string>> record;
		while (getline(iss, lineStream, ','))
		{
			row.push_back(lineStream);
		}

		//for (auto i = row.begin(); i != row.end(); ++i)
		//{
		//	cout << *i << " ";
		//	if ((*i) == "-")
		//		cout << "Entry not found";    // call Alerter and Manual Log Reader
		//}

		record.push_back(row);
		for (int i = 0; i < record.size(); i++) {
			for (int j = 0; j < record[i].size(); j++)
				cout << record[i][j] << " ";
			cout << endl;
		}

	}
	csvFile.close();
}

