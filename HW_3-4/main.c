#include<stdlib.h>
#include<stdio.h>
struct Node{
    int index;
    struct Node* parent;
} typedef node;
node* makenode(int n){
    node* new_node;
    new_node= malloc(sizeof(struct Node));
    new_node->index = n;
    return new_node;
}
node* findroot(node* N){
    while(N->parent!=NULL){
        N=N->parent;
    }
    return N;
}
int main(){
    int N,M,p,q,w=0,a,b;
    char op;
    int *num;
    scanf("%d %d",&N,&M);
    int input[M+1][2];
    char inputc[M+1];
    for(int i=0;i<M;i++){
        scanf(" %c",&inputc[i]);
        if(inputc[i]=='u')
            scanf("%d %d",&input[i][0],&input[i][1]);
        else
            scanf("%d",&input[i][0]);
    }
    num=(int*)malloc(sizeof(int)*(1000001));
    node* data[N+1];
    node* roots[M+1];
    roots[0]=makenode(0);
    roots[0]->parent=NULL;
    for(int i=1;i<=N;i++){
        data[i]=makenode(i);
        data[i]->parent=roots[0];
    }
    num[0]=N;
    for(int i=0;i<M;i++){
        op=inputc[i];
        p=input[i][0];
        q=input[i][1];
        if(op=='w'){
            w++;
            num[findroot(data[p])->index]--;
            roots[w]=makenode(w);
            roots[w]->parent = NULL;
            data[p]=makenode(p);
            data[p]->parent=roots[w];
            num[w]++;
        }
        else if(op=='u'){
            a=findroot(data[p])->index;
            b=findroot(data[q])->index;
            if(a<b){
                if(a!=0){
                    roots[a]->parent=roots[b];
                    num[b]+=num[a];
                    num[a]=0;
                }
                else{
                    data[p]->parent=roots[b];
                    num[b]++;
                    num[0]--;
                }
            }
            else if(a>b){
               if(b!=0){
                    roots[b]->parent=roots[a];
                    num[a]+=num[b];
                    num[b]=0;
                }
                else{
                    data[q]->parent=roots[a];
                    num[a]++;
                    num[0]--;
                }
            }
        }
        else if(op=='h'){
            a=findroot(data[p])->index;
            if(a!=0){
                num[a]--;
                data[p]->parent = roots[0];
                num[0]++;
            }
        } 
        else if(op=='a'){
            printf("%d\n",findroot(data[p])->index);
        }
        else if(op=='n'){
            printf("%d\n",num[p]);
        }
    }
    return 0;
}