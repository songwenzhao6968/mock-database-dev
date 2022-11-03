//
// Created by Songwen Zhao on 11/02/22.
//

#include <cstdio>
#include <cassert>
#include <cstring>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;
string head = ""
"{\n"
"    \"t_transaction\": {\n"
"        \"schema\": {\n"
"            \"field\": [\n"
"                [\"transaction_id\", \"uint32\"],\n"
"                [\"user_id\", \"uint32\"],\n"
"                [\"sector_name\", \"str\"],\n"
"                [\"asset_name\", \"str\"],\n"
"                [\"asset_type\", \"str\"],\n"
"                [\"volume\", \"int16\"],\n"
"                [\"volume_for_buy\", \"int16\"],\n"
"                [\"volume_for_sell\", \"int16\"],\n"
"                [\"price\", \"int32\"],\n"
"                [\"price_for_buy\", \"int32\"],\n"
"                [\"price_for_sell\", \"int32\"],\n"
"                [\"is_buy\", \"bool\"],\n"
"                [\"date\", \"uint32\"]\n"
"            ],\n"
"            \"key\": {\n"
"                \"transaction_id\": \"primary\"\n"
"            }\n"
"        },\n"
"        \"data\": [\n";

string tail = ""
"        ]\n"
"    }\n"
"}\n";

string sector_name[6] = {
	"Tech sector",
	"Food sector",
	"Energy sector",
	"Industrials sector",
	"Utilities sector",
	"Healthcare sector"
};

string asset_name[8] = {
	"Apple",
	"Google",
	"Microsoft",
	"Amazon",
	"Meta",
	"Tesla",
	"Exxon Mobil",
	"P&G"
};

string asset_type[5] = {
	"Equities",
	"Fixed income",
	"Cash",
	"Currencies",
	"Commodities"
};

uint date[5] = {
	20221001,
	20221002,
	20221003,
	20221004,
	20221005
};

string outInt(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

string outString(string x){
	return "\""+x+"\"";
}

string outBool(bool x){
	return x?"true":"false";
}

int main(int argc, char* argv[]) {
	int n = 60, m = 15; // n: the number of transactions m: the number of users
	random_device rd;
	default_random_engine r{rd()};
	uniform_int_distribution<int> volume(-1000, 1000);
	uniform_int_distribution<int> price_pv(50, 500);

	string data="";
	for (int i=0; i<n; ++i){
		string record = "[" + outInt(i);
		record += ", "+outInt(r()%m);
		record += ", "+outString(sector_name[r()%6]);
		record += ", "+outString(asset_name[r()%8]);
		record += ", "+outString(asset_type[r()%5]);
		int V = volume(r);
		record += ", "+outInt(V);
		if (V>0) record += ", "+outInt(0)+", "+outInt(V);
		else record += ", "+outInt(-V)+", "+outInt(0);
		int P = V*price_pv(r);
		record += ", "+outInt(P);
		if (V>0) record += ", "+outInt(0)+", "+outInt(P);
		else record += ", "+outInt(-P)+", "+outInt(0);
		if (V>0) record += ", "+outBool(false);
		else record += ", "+outBool(true);
		record += ", "+outInt(date[i/(n/5)]);
		record += "]";
		if (i<n-1) data += "\t\t\t"+record+",\n";
		else data += "\t\t\t"+record+"\n";
	}
	ofstream fout("../example/data/server/db.json");
	fout << head << data << tail;
	fout.close();
	return 0;
}