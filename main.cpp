#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;
void CourseListforStudentSolver(istream& in) {
	int N = 0; int K = 0;
	in >> N >>K;
	unordered_map<string, vector<bool>>table;
	for (int id = 0;id <K; id++) {
		int i = 0; int Ni = 0;
		in >>i >> Ni;
		for (int sid = 0; sid < Ni; sid++) {
			string studID;
			in >> studID;
			if (table.find(studID) == table.end()) {
				table[studID] = vector<bool>();
				table[studID].resize(K+1);
				auto&now = table[studID];
				for (int kid = 0; kid <= K; kid++) now[kid] = false;
			}
			table[studID][i] = true;
		}
	}
	for (int sid = 0; sid < N; sid++) {
		string studID;
		in >> studID;
		if (table.find(studID) == table.end()) {
			//out << studID << " " << 0<< endl;
			printf("%s 0\n", studID.data());
			continue;
		}
		auto&now = table[studID];
		int numK = 0;
		string str="";
		for (int i = 1; i <= K; i++) {
			if (now[i]) { str = str + " "+to_string(i); numK++; }
		}
		//out << studID<<" "<< numK<< str<<endl;
		printf("%s %d %s\n", studID.data(), numK, str.data());
	}
}
int main()
{

	//fstream in;
	//in.open("./InputData/A1039.txt");
	CourseListforStudentSolver(cin);
    return 0;
}
