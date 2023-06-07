#include"akihabara.h"
#include<stdio.h>
#include<stdlib.h>
int Array[50000000];
int m=130000001;
long long int P1=4302206801;
long long int P2=4311866567;
int main() {
    unsigned int N = getN();
    long long int K = getK();
    getArray(N, Array);
    long long int compare,h1,h2,index,LeftSum=0,count=0;
    long long int *table;
    int *num;
    table=(long long int*)malloc(sizeof(long long int)*m);
    num=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<N;i++){
        LeftSum+=Array[i];
        compare=LeftSum-K;
        if(compare==0)
            count++;
        h1=(compare%P1+P1)%P1;
        h2=(compare%P2+P2)%P2;
        if(h2==0)
            h2=134217727;
        index=(h1+h2)%m;
        h2=h2%m;
        while(table[index]!=compare&&(table[index]!=0||num[index]!=0)){
            index+=h2;
            if(index>=m)
                index-=m;
        }
        if(table[index]==compare)
            count+=num[index];
        
        h1=(LeftSum%P1+P1)%P1;
        h2=(LeftSum%P2+P2)%P2;
        if(h2==0)
            h2=134217727;
        index=(h1+h2)%m;
        h2=h2%m;
        while(table[index]!=LeftSum&&(table[index]!=0||num[index]!=0)){
            index+=h2;
            if(index>=m)
                index-=m;
        }
        if(table[index]==LeftSum)
            num[index]++;
        else{
            table[index]=LeftSum;
            num[index]++;
        }
    }
    printf("%lld\n",count);
}