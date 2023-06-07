#include<stdio.h>
#include<stdlib.h>
void prefix(char *str,int n){
    int r,k=0,*pi;
    pi = malloc(sizeof(int)*(n+1));
    pi[1]=0;
    printf("1: 1\n");
    for(int i=2;i<=n;i++){
        while(k>0 && str[k]!=str[i-1])
            k = pi[k];
        if(str[k]==str[i-1])
            k++;
        pi[i]=k;
        r = i-pi[i];
        if(i%r==0)
            printf("%d: %d\n",i,r);
        else
            printf("%d: %d\n",i,i);
    }
}
int main(){
    char* str;
    int n,r;
    scanf("%d",&n);
    str = (char*)malloc(sizeof(char)*n);
    scanf("%s",str);
    prefix(str,n);
}