#include <vector>
#include <iostream>
#include <fstream>
//#include <string>
#include <queue>
//#include <list>
//#include <unordered_map>
//#include <functional>
#include "stdio.h"
//#include "math.h"
using namespace std;

struct BiNode {
	int val;
	int leftId;
	int rightId;
	BiNode(int v = -1, int l = -1, int r = -1) :val(v), leftId(l) , rightId(r) {};
};
vector<BiNode>*_tableBiNode;
int* _inorder;
int* _postorder;
int* _id_In_inorder;
int buildTreeAndReturnRootId(int begin_in, int end_in, int begin_post, int end_post) {
	if (end_in<0 || begin_in <0 || end_post < 0 || begin_post < 0)return -1;
	if (end_in <begin_in  || end_post<begin_post )return -1;
	if (end_in == begin_in  && end_post ==begin_post ) {
		int nowID = _tableBiNode->size();
		_tableBiNode->push_back(BiNode(_inorder[begin_in]));
		return nowID;
	}
	//auto& table = *_tableBiNode;
	int rootVal = _postorder[end_post];
	int posIn_inorder = _id_In_inorder[rootVal];
	int leftLen = posIn_inorder - begin_in;
	int leftID = buildTreeAndReturnRootId(begin_in, posIn_inorder - 1, begin_post, begin_post + leftLen - 1);
	int rightID = buildTreeAndReturnRootId(posIn_inorder + 1, end_in , begin_post + leftLen, end_post-1);
	int nowID = _tableBiNode->size();
	_tableBiNode->push_back(BiNode(rootVal, leftID, rightID));
	return nowID;
}
int main()
{
	vector<BiNode>table; table.reserve(32); _tableBiNode = &table ;
	//fstream in; in.open("./InputData/A1020_Tree_Traversals.txt");
	int inorder[32]; int postorder[32]; int id_In_inorder[32];
	int N = 0; cin >> N;

	for (int i = 0; i < N; i++)cin >> postorder[i];
	for (int i = 0; i < N; i++)cin >> inorder[i];
	_inorder = inorder; _postorder = postorder;
	for (int i = 0; i < N; i++)id_In_inorder[inorder[i]] = i;
	_id_In_inorder = id_In_inorder;
	int root=buildTreeAndReturnRootId(0, N - 1, 0, N - 1);
	queue<int> id; id.push(root); vector<int>ans; ans.reserve(32);
	while (id.size() != 0) {
		ans.push_back(table[id.front()].val);
		int lid = table[id.front()].leftId;
		if(lid!=-1)id.push(lid);
		int rid = table[id.front()].rightId;
		if (rid != -1)id.push(rid);
		id.pop();
	}
	for (int i = 0; i < N - 1; i++)printf("%d ", ans[i]);
	printf("%d\n", ans.back());
    return 0;
}
