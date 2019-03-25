#ifndef MYHEADERS_H_INCLUDED
#define MYHEADERS_H_INCLUDED
#include  "myHeaders.h"
#include <vector>
#include <stdio.h>
int ThreenPlusOne(int n);
enum class personTalentAndVirtueType:unsigned char{
smallMan,
foolMan_v2,
foolMan_v1,
nobleMan,
sage
};
struct personTalentAndVirtue{
       unsigned int ID;
       unsigned char talent;
       unsigned char virtue;
       unsigned char totalScores;
       personTalentAndVirtueType type;
       personTalentAndVirtue():ID(0),totalScores(0),type(personTalentAndVirtueType::smallMan),virtue(0),talent(0){};
};
union personTalentAndVirtueData{
    unsigned long long personLL;
    personTalentAndVirtue personData;
    personTalentAndVirtueData():personLL(0){};
};
void rankByTalentAndVirtue(FILE * pFile,int n,int L,int H,std::vector<personTalentAndVirtueData>&ans);
#endif // MYHEADERS_H_INCLUDED
