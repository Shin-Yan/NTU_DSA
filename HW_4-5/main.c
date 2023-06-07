#include<stdio.h>
#include<stdlib.h>
int Queue[500001];
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
struct Queue{
    int *arr;
    int front;
    int back;
    int size;
}typedef queue;
queue* makeQueue(int N){
    queue* Q;
    Q=(queue*)malloc(sizeof(queue));
    Q->arr=(int*)malloc(sizeof(int)*(N+1));
    Q->size=N;
    Q->front=0;
    Q->back=0;
    return Q;
}
int isEmpty(queue* Q){
    if(Q->front==Q->back)
        return 1;
    else
        return 0;
}
int Pop(queue* Q){
    int k=Q->arr[Q->front];
    Q->arr[Q->front]=0;
    Q->front++;
    if(Q->front>Q->size)
        Q->front=0;
    Queue[k]=0;
    return k;
}
void Push(queue* Q,int k){
    Q->arr[Q->back]=k;
    Q->back++;
    if(Q->back>Q->size)
        Q->back=0;
    Queue[k]=1;
}
void BFS(node **adj,queue *Q,int *a,int *time,int s){
    while(!isEmpty(Q)){
        int n=Pop(Q),m;
        node* now=adj[n];
        int height;
        if(a[n]>time[n])
            height=a[n];
        else
            height=time[n];
        while(now->next){
            now=now->next;
            m=now->key;
            if(a[m]<=height&&time[n]<time[m]){
                time[m]=time[n];
                if(!Queue[m])
                    Push(Q,m);
            }
            else if(a[m]>height&&a[m]<time[m]){
                time[m]=a[m];
                if(!Queue[m])
                    Push(Q,m);
            }
        }
    }
    return;  
}
int main(){
    int N,M,u,v,s,t;
    node** adj;
    int *a,*time;
    scanf("%d%d",&N,&M);
    a=(int*)malloc(sizeof(int)*(N+1));
    time=(int*)malloc(sizeof(int)*(N+1));
    for(int i=1;i<=N;i++)
        time[i]=1000000001;
    adj=(node**)malloc(sizeof(node*)*(N+1));
    
    queue* Q=makeQueue(N);
    for(int i=1;i<=N;i++)
        adj[i]=makenode(i);
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        if(adj[u]->next) 
            insert(adj[u],v);
        else 
            adj[u]->next=makenode(v);
        if(adj[v]->next) 
            insert(adj[v],u);
        else 
            adj[v]->next=makenode(u);
    }
    for(int i=1;i<=N;i++)
        scanf("%d",&a[i]);
    scanf("%d%d",&s,&t);
    time[s]=0;
    Push(Q,s);
    BFS(adj,Q,a,time,s);
    printf("%d\n",time[t]);
    return 0;
}