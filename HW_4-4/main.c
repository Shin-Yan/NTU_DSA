#include<stdio.h>
#include<stdlib.h>
int counter[1000001];
struct Node{
    int key;
    struct Node* next;
}typedef node;
node* makenode(int k){
    node* new;
    new=(node*)malloc(sizeof(node));
    new->key=k;
    new->next=NULL;
    return new;
}
void insert(node* v,int k){
    node* new=makenode(k);
    new->next=v->next;
    v->next=new;
}
int DFS(node** adj,int* start,int n,int p){
    node* s=adj[n];
    int k=s->key;
    while(s->next){
        s=s->next;
        if(s->key!=p)
            counter[n]+=DFS(adj,start,s->key,k);
    }
    if(start[n])counter[n]++;
    return counter[n];
}
long long int* countingsort(int *arr,int n){
    int *counting;
    long long int *output; 
    counting=(int*)malloc(sizeof(int)*1000001);
    output=(long long int*)malloc(sizeof(long long int)*(n+1));
    for(int i=1;i<=n;i++)
        counting[arr[i]]++;
    for(int i=1;i<=1000001;i++)
        counting[i]=counting[i]+counting[i-1];
    for(int i=n;i>=1;i--){
        output[counting[arr[i]]]=arr[i];
        counting[arr[i]]--;
    }
    return output;
}
int main(){
    int n,m,u,v,x;
    scanf("%d%d",&n,&m);
    int *start,*d;
    node **adj;
    long long int *CAS,*dAS,last_answer=0;
    start=(int*)malloc(sizeof(int)*(1000001));
    adj=(node**)malloc(sizeof(node*)*(n+1));
    d=(int*)malloc(sizeof(int)*(n+1));
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        start[x]++;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
        adj[i]=makenode(i);
        adj[i]->next=NULL;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        if(!adj[u]->next)
            adj[u]->next=makenode(v);
        else
            insert(adj[u],v);
        if(!adj[v]->next)
            adj[v]->next=makenode(u);
        else
            insert(adj[v],u);
    }
    DFS(adj,start,1,-1);
    dAS=countingsort(d,n);
    CAS=countingsort(counter,n);
    for(int i=1;i<n;i++)
        last_answer+=dAS[i]*CAS[i];
    printf("%lld\n",last_answer);
    /*for(int i=1;i<=n;i++){
        node* s=adj[i];
        do{
            printf("%d ",s->key);
            s=s->next;
        }
        while(s);
        printf("\n"); 
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",d[i],CAS[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%d: %d times \n",i,counter[i]);
    }*/
}