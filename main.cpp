#include <stdio.h>
#include<algorithm>
int maxNum=999999;
using namespace std;
int n=0;int L=0;int H=0;int remainN=0;
struct Student{
    unsigned int id;
    unsigned char t;
    unsigned char v;
    unsigned char sum;
    unsigned char type;
    Student(int _id=0,int _v=0,int _t=0):id(maxNum-_id),t(_t),v(_v),sum(_v+_t){
          if(v<L||t<L){
            type=1;
            remainN--;
          }else if(v>=H&&t>=H){
                type=5;
          }else if(v>=H&&t<H){
                type=4;
          }else if(v>=t){
                type=3;
          }else   type=2;
    }
};
union StudentData{
    unsigned long long data;
    Student student;
    StudentData(unsigned long long _d=0):data(_d){};
};
bool cmp(const Student&a,const Student&b){
    if(a.type!=b.type)return a.type>b.type;
    if(a.sum!=b.sum)return a.sum>b.sum;
     if(a.v!=b.v)return a.v>b.v;
    return a.id>b.id;
}
int main()
{
    //FILE * pFile;pFile = fopen ("./InputData/1062_Talent_and_Virtue.txt","r");fscanf(pFile,"%d %d %d",&n,&L,&H);
    scanf("%d %d %d",&n,&L,&H);
    remainN=n;
    //Student studTable[100010];
    unsigned long long _studTable[100010];
    int endID=0;
    for(int i=0;i<n;i++){
        int id=0;int v=0;int t=0;
        //fscanf(pFile,"%d %d %d",&id,&v,&t);
        scanf("%d %d %d",&id,&v,&t);
        Student now(id,v,t);
        if(now.type!=1){
                StudentData stdt;stdt.student=now;
            _studTable[endID]=stdt.data;
            endID++;
        }
    }
    //sort(studTable,studTable+endID,cmp);
       sort(_studTable,_studTable+endID);
    printf("%d\n",endID);
 Student* studTable=( Student*)_studTable;
 //for(int i=0;i<endID;i++)printf("%d %d %d\n",maxNum-studTable[i].id,studTable[i].v,studTable[i].t);
  for(int i=endID-1;i>=0;i--)printf("%d %d %d\n",maxNum-studTable[i].id,studTable[i].v,studTable[i].t);
    return 0;
}
