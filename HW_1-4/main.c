#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    struct ArrayStack{
        int top;
        int capacity;
        int *array;
    };
    struct ArrayStack *CreateStack(){
        struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
        if(!S)return NULL;
        S->capacity =4;
        S->top = -1;
        S->array=(int*)malloc(S->capacity*sizeof(int));
        if(!S->array) return NULL;
        return S;
    }
    int IsEmptyStack(struct ArrayStack *S){
        return (S->top == -1);
    }
    int IsFullStack(struct ArrayStack *S) {
        return (S->top == S->capacity-1);
    }
    void Enlarge(struct ArrayStack *S){
        S->capacity = S->capacity*2;
        S->array=(int*)realloc(S->array,S->capacity*sizeof(int));
    }
    void Push(struct ArrayStack *S,int data){
        if(IsFullStack(S))
            Enlarge(S);
            S->array[++S->top]=data;
    }
    int Pop(struct ArrayStack *S){
        if(IsEmptyStack(S)){
            //printf("Stack is Empty");
            return 0;
        }else
            return (S->array[S->top--]);
    }
    int* CreateArray(int n,int* ptr){
        ptr = (int*)malloc(n*sizeof(int));
        return ptr;
    }
    //The function that pop until Stack is empty or less than top and record
    void PUSIEOLTTAR(struct ArrayStack* S,int i,int s,int*r,int*arr,struct ArrayStack*K){
        while(s>=S->array[S->top]){
            int cur = Pop(K);
            Pop(S);
            if(i-cur<=r[cur])
                arr[cur]=i;
            else arr[cur] = r[cur]+cur; 
        if(IsEmptyStack(S))
        return;
        }
    }
    int *CountPowa(struct ArrayStack* S,int* s,int* r,int n){
        int *ptr;
        struct ArrayStack* K;
        K=CreateStack();
        ptr = CreateArray(n,ptr);
        for(int i=0;i<n;i++){
            ptr[i]=-1;
            if(IsEmptyStack(S)){
                Push(S,s[i]);
                Push(K,i);
            }
            else{
                PUSIEOLTTAR(S,i-1,s[i],r,ptr,K);
                Push(S,s[i]);
                Push(K,i);
            }
        }
        PUSIEOLTTAR(S,n-1,2147483647,r,ptr,K);
        return ptr;
    }
    int *change(int*arr1,int n){
        int *arr2;
        arr2=CreateArray(n,arr2);
        for(int i=0;i<n;i++)
        arr2[n-i-1]=arr1[i];
        return arr2;
    }
int main(){
    int n,*s,*r,*right,*left;
    scanf("%d",&n);
    s = CreateArray(n,s);
    r = CreateArray(n,r);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&r[i]);
    //start of algorithm
    struct ArrayStack *S;
    S = CreateStack();
    right = CountPowa(S,s,r,n);
    left = CountPowa(S,change(s,n),change(r,n),n);
    for(int i=0;i<n;i++)
    printf("%d %d\n",n-1-left[n-i-1],right[i]);
}