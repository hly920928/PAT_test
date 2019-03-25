#include  "myHeaders.h"
#include <vector>
#include <stdio.h>
#include<algorithm>
using namespace std;
int ThreenPlusOne(int n){
      if(n==1)return 0;
    if(n%2==0){
        return ThreenPlusOne(n/2)+1;
    }else{
         return ThreenPlusOne((3*n+1)/2)+1;
    }
}


personTalentAndVirtue producePersonTalentAndVirtue(int v,int t,int id,int L,int H){
            personTalentAndVirtue now;
               if(v>=H&&t>=H){
                     now.type=personTalentAndVirtueType::sage;
               }else if(v>=H&&(t<H&&t>=L)){
                      now.type=personTalentAndVirtueType::nobleMan;
               }else if((v>=L)&&(t>=L)&&(v>=t)){
                      now.type=personTalentAndVirtueType::foolMan_v1;
               }else if((v>=L)&&(t>=L)&&(v<t)){
                      now.type=personTalentAndVirtueType::foolMan_v2;
               }else{
                     now.type=personTalentAndVirtueType::smallMan;
               }
               now.totalScores=v+t;now.ID=id;now.virtue=v;now.talent=t;
               return now;
       }
bool compare_vI(const personTalentAndVirtueData&a,const personTalentAndVirtueData&b){
    return a.personLL>b.personLL;
}
bool compare_v2(const personTalentAndVirtueData&a,const personTalentAndVirtueData&b){
    return a.personLL>b.personLL;
}
void rankByTalentAndVirtue(FILE * pFile,int n,int L,int H,vector<personTalentAndVirtueData>&ans){
         for(int i=0;i<n;i++){
            personTalentAndVirtueData now;
            int id=0;int v=0;int t=0;
            fscanf(pFile,"%d %d %d",&id,&v,&t);
            now.personData=producePersonTalentAndVirtue(v,t,id,L,H);
            //printf("%d %d %d %d\n",now.personData.ID,now.personData.virtue,now.personData.talent,now.personData.type);
        if(now.personData.type!=personTalentAndVirtueType::smallMan){
                ans.push_back(now);
            }
            //printf("%d %d %d\n",id,v,t);
         }
         sort(ans.begin(),ans.end(),compare_vI);
}
