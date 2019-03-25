#include <iostream>
#include <stdio.h>
#include <vector>
#include  "myHeaders.h"
using namespace std;
int main()
{
    FILE * pFile;
    pFile = fopen ("./InputData/1062_Talent_and_Virtue.txt","r");
  int n=0;  int L=0;int H=0;
  fscanf (pFile,"%d %d %d",&n,&L,&H);
  vector<personTalentAndVirtueData>ans;
rankByTalentAndVirtue(pFile,n,L,H,ans);
  //printf("%d %d %d\n",n,L,H);


  int total=ans.size();
  printf("%d\n",total);
  for(int i=0;i<total;i++){
     printf("%d %d %d\n",ans[i].personData.ID,ans[i].personData.virtue,ans[i].personData.talent);
  }
  fclose(pFile);

    return 0;
}
