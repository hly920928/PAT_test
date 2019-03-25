#include <stdio.h>
#include<algorithm>
#include <string>
using namespace std;
void toStr(char* str,int i){
    str[4]='\0';
     str[3]=i%10+'0';i/=10;
     str[2]=i%10+'0';i/=10;
      str[1]=i%10+'0';i/=10;
      str[0]=i%10+'0';
}
int toInt(char* str){
    int ans=0;
    ans=(str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0');
    return ans;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    char a[5];
    char b[5];
    char d[5];
    toStr(b,n);
    sort(b,b+4);
    copy(b,b+4,a);
    reverse(a,a+4);
    int diff=toInt(a)-toInt(b);

    if(diff==0){
        printf("%s - %s = 0000\0",a,b);
        return 0;
    }
     toStr(d,diff);
     int t=0;
    while(diff!=6174&&t<10){
        printf("%s - %s = %s\n",a,b,d);
      toStr(b,diff);
      sort(b,b+4);
      copy(b,b+4,a);
       reverse(a,a+4);
       diff=toInt(a)-toInt(b);
       toStr(d,diff);
       t++;
    }
     printf("%s - %s = 6174\n",a,b);
    return 0;
}
