#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <functional>
using namespace std;

void  miceAndRice_A1056(istream& in){
	int numMice = 0; int sizeOfGroup = 0;
	in >> numMice >> sizeOfGroup;
	vector<int>weight; weight.resize(numMice);
	for (int i = 0; i < numMice; i++) {
		int nowW = 0; in >> nowW; weight[i]=nowW;
	}
	queue<int>miceID;
	for (int i = 0; i < numMice; i++) {
		int nowID = 0; in >> nowID; miceID.push(nowID);
	}
	vector<int>ans; ans.resize(numMice);
	auto cmp_II = [&](int a, int b) -> bool{
		return weight[a] < weight[b];
	};
	while (miceID.size() != 1) {
		int size = miceID.size();
		int turn = size / sizeOfGroup; int lastGroupSize = size % sizeOfGroup;
		int remain = turn; if (lastGroupSize != 0)remain++;
		vector < int >  temp; temp.resize(sizeOfGroup);
		for (int i = 0; i < turn; i++) {
			for (int j= 0; j< sizeOfGroup; j++) {
				temp[j] = miceID.front(); miceID.pop();
			}
			auto itr = max_element(temp.begin(), temp.end(), cmp_II);
			for (int id : temp) {
				if (id == *itr) {
					miceID.push(id);
				}else {
					ans[id] = remain + 1;
				}
			}
		}
		if (lastGroupSize != 0) {
			temp.resize(lastGroupSize);
			for (int j = 0; j < lastGroupSize; j++) {
				temp[j] = miceID.front(); miceID.pop();
			}
			auto itr = max_element(temp.begin(), temp.end(), cmp_II);
			for (int id : temp) {
				if (id == *itr) {
					miceID.push(id);
				}else {
					ans[id] = remain + 1;
				}
			}
		}
	}
	ans[miceID.front()] = 1;
	for (int i = 0; i < numMice - 1; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[numMice-1]);
}
int main()
{

	//fstream in;
	//in.open("./InputData/A1056_Mice_and_Rice.txt");
	miceAndRice_A1056(cin);
    return 0;
}
