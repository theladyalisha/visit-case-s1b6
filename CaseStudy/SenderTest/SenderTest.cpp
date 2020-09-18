// Let Catch provide main():

#define CATCH_CONFIG_MAIN

#include<string>
#include"catch.hpp"
#include"Sender.h"
using namespace std;

TEST_CASE("Print string Sender") {
        string s1="Sender";
	print(s1);
	/*string s2;
	getline(cin,s2);*/
	REQUIRE(s1 == "Sender");
}
