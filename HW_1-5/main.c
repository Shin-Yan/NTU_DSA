#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    //definition of data type "ListNode" which is used for doubly linked list
    typedef struct ListNode{
        char data;
        struct ListNode *next;
        struct ListNode *prev;
    }node;
    void insert(node* x,char c){
        node* new;
        new = (node*)malloc(sizeof(node));
        new->data = c;
        new->next = x->next;
        new->prev = x;
        x->next->prev = new;
        x->next = new;
    }
    void Delete(node* x,node* y){
        node *tmp,*tmp1;
        tmp = x;
        x->prev->next = y;
        tmp1 = x->prev;
        y->prev = tmp1;
    }
    void ReverseList(node* w,node* x,node* y,node* z){
        if(w==x||w->next==x)
            return;
        w->prev->next = y->next;
        y->next->prev = w->prev;
        x->prev->next = z->next;
        z->next->prev = x->prev;
        w->prev = y;
        y->next = w;
        x->prev = z;
        z->next = x;
    }
    void printlist(node* head,node* tail){
        node* tmp;
        for(tmp=head->next;tmp!=tail;tmp=tmp->next)
            printf("%c",tmp->data);
        printf("\n");
    }
int main(){
    node *head1,*tail1,*cursor1,*curpos1,*head2,*tail2,*cursor2,*curpos2,*tmp1,*tmp2;
    head1 = (node*)malloc(sizeof(node));
    tail1 = (node*)malloc(sizeof(node));
    head2 = (node*)malloc(sizeof(node));
    tail2 = (node*)malloc(sizeof(node));
    int n,R,left,SM,j;
    scanf("%d",&n);
    char ch[n][1000001], in[1000001];

    for(int i=0;i<n;i++){
        scanf("%s",in);
        strcpy(ch[i],in);
    }
    head1->prev = NULL;
    tail1->next = NULL;
    head2->prev = NULL;
    tail2->next = NULL;
    for(int i=0;i<n;i++){
        head1->next = tail1;    
        tail1->prev = head1;
        cursor1 = tail1;
        curpos1 = NULL;
        head2->next = tail2;
        tail2->prev = head2;
        cursor2 = head2;
        curpos2 = NULL;
        R = left = SM = j = 0;
            while(ch[i][j]!='\0'){
            //selection mode
            if(SM){
                if(R && ch[i][j]!='R'){
                    if(R%2==1){
                        if(left == -1){
                            tmp1 = cursor1->prev;
                            tmp2 = cursor2->next;
                            ReverseList(cursor1,curpos1,curpos2,cursor2);
                            cursor1 = tmp1->next;
                            cursor2 = tmp2->prev;
                        }
                        else if (left == 1){
                            tmp1 = curpos1->prev;
                            tmp2 = curpos2->next;
                            ReverseList(curpos1,cursor1,cursor2,curpos2);
                            curpos1 = tmp1->next;
                            curpos2 = tmp2->prev;
                        }
                    }
                    R = 0;
                }
                if(ch[i][j]>=97 && ch[i][j]<=122){
                   if(left==-1){
                        Delete(cursor1,curpos1);
                        Delete(curpos2->next,cursor2->next);
                        cursor1 = curpos1;
                        cursor2 = curpos2;
                    }
                    else if(left==1){
                        Delete(curpos1,cursor1);
                        Delete(cursor2->next,curpos2->next);
                    }
                    insert(cursor1->prev,ch[i][j]);
                    insert(cursor2,ch[i][j]);
                    SM = 0;
                }
                else{
                switch(ch[i][j]){
                    case 'V':
                        SM = 0;
                        cursor1 = curpos1;
                        cursor2 = curpos2; 
                        break;
                    case 'H':
                        if(curpos1->prev == head1)
                            break;
                        if(curpos1 == cursor1)
                            left =1;
                        curpos1 = curpos1->prev;
                        curpos2 = curpos2->next;
                        break;
                    case 'L':
                        if(curpos1 == tail1)
                            break;
                        if(curpos1 == cursor1)
                            left = -1;
                        curpos1 = curpos1->next;
                        curpos2 = curpos2->prev;
                        break;
                    case 'D':
                        if(cursor1 != curpos1)
                            SM = 0;
                        if(left==-1){
                            Delete(cursor1,curpos1);
                            Delete(curpos2->next,cursor2->next);
                            cursor1 = curpos1;
                            cursor2 = curpos2;
                        }
                        else if(left==1){
                            Delete(curpos1,cursor1);
                            Delete(cursor2->next,curpos2->next);
                        }
                        break;
                    case 'R':
                        R++;
                        break;
                    case 'I':
                        curpos1 = head1->next;
                        curpos2 = tail2->prev;
                        if(curpos1!=cursor1)
                            left =1;
                        break;
                    case 'A':
                        curpos1 = tail1;
                        curpos2 = head2;
                        if(curpos1!=cursor1)
                            left =-1;
                        break;
                }
                }
                if(cursor1 == curpos1)
                left = 0;
            }
            //normal mode
            else{
                if(ch[i][j]>=97 && ch[i][j]<=122){
                    insert(cursor1->prev,ch[i][j]);
                    insert(cursor2,ch[i][j]);
                }
                else{
                switch(ch[i][j]){
                    case 'V':
                        SM = 1;
                        curpos1 = cursor1;
                        curpos2 = cursor2;
                        left =0 ;
                        break;
                    case 'H':
                        if(cursor1->prev!=head1){
                            cursor1 = cursor1->prev;
                            cursor2 = cursor2->next;
                        }
                        break;
                    case 'L':
                        if(cursor1!=tail1){
                            cursor1 = cursor1->next;
                            cursor2 = cursor2->prev;
                        }
                        break;
                    case 'I':
                        cursor1 = head1->next;
                        cursor2 = tail2->prev;
                        break;
                    case 'A':
                        cursor1 = tail1;
                        cursor2 = head2;
                        break;
                }
            }
            }
            j++;
        }
        if(R%2==1){
            if(left == -1){
                tmp1 = cursor1->prev;
                tmp2 = cursor2->next;
                ReverseList(cursor1,curpos1,curpos2,cursor2);
                cursor1 = tmp1->next;
                cursor2 = tmp2->prev;
            }
            else if (left == 1){
                tmp1 = curpos1->prev;
                tmp2 = curpos2->next;
                ReverseList(curpos1,cursor1,cursor2,curpos2);
                curpos1 = tmp1->next;
                curpos2 = tmp2->prev;
            }
        }
        printlist(head1,tail1);
    }
return 0;
}