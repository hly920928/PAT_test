#include <stdio.h>
//#include <algorithm>
#include <vector>
#include "math.h"
//#include <iostream>
//#include <fstream>
//#include <queue>
//#include <functional>
using namespace std;
int maxSum;
vector<char>* maxSumVector;
void 	integerFactorization_re(int n, int k, int P, vector<char>&ans,int now,int pre,int sum) {
	if (k == 0)return;
	if (k >n)return;
	int max = (int)(pow(pre, P))* k;
	if(max<n)return;
	int maxPossibleSum=sum+k*pre;
	if(maxPossibleSum<=maxSum)return;
	for (int i = pre; i >= 1; i--) {
		int powered = pow(i, P);
		if (powered == n&& k==1) {
			ans[now] = i; sum += i;
			if(sum> maxSum){
				maxSum = sum;
				auto&_maxSumVector = *maxSumVector;
				_maxSumVector = ans;
			}
			return;
		}else if (powered < n) {
			ans[now] = i;
			integerFactorization_re(n - powered, k - 1, P, ans, now + 1, i,sum+i);
			}
		}
	}

int main()
{

	int N = 0; int K = 0; int P = 0;
	scanf("%d %d %d", &N, &K, &P);
	vector<char>_maxSumVector; maxSumVector = &_maxSumVector;
	vector<char>ans; ans.resize(K); maxSum = 0;
		int max = pow(N, (float)1 / (float)P);
	integerFactorization_re(N, K, P, ans, 0, max,0);
	if (_maxSumVector.size()!=0) {
		printf("%d =", N);
		for (int i = 0; i < K-1; i++) {
			printf(" %d^%d +", _maxSumVector[i],P);
		}
		printf(" %d^%d\n", _maxSumVector.back(), P);
	}
	else {
		printf("Impossible\n");
	}
    return 0;
}
