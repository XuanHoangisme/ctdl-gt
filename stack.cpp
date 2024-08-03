#include<iostream>
using namespace std;

//cau truc node
struct node
{
    int value;
    node *next;
};

//khoi tao node
void init(node *&head)
{
   head=NULL;
}

//khoi tao gia tri cho node
node *createnode(int x)
{
    node *p=new node;
    p->value=x;
    p->next=NULL;
}

//them phan tu vao stack
void push(node *&head,int x)
{
    node *p=createnode(x);
    if(head==NULL)//danh sach rong
    {
        head=p;
    }
    else
    {
        node*last =head;
        while(last->next!=NULL)
        {
            last=last->next;
        }
        last->next=p;
        last=p;
    }
}

//lay phan tu ra stack
void pop(node *&head)
{
    if(head!=NULL)//stack co phan tu
    {
        node *p=head;
        node *prev=NULL;
        while(p->next !=NULL)
        {
            prev=p;
            p=p->next;
        }
        if(prev==NULL)//danh sach chi co 1 phan tu
        {
            cout<<p->value;
            delete(p);
        }
        else
        {
            cout<<p->value;
            prev->next=NULL;
            delete(p);
        }  
    }
}

//kiem tra stack rong
bool isEmpty(node *head)
{
    return head==NULL;
}

//chuyen so nguyen duong sang nhi phan
void tobinary(node *&head,int x)
{
    while(x!=0)
    {
        push(head,x%2);//them phan tu du vao stack
        x/=2;
    }
    while(isEmpty(head)==0)//danh sach chua rong
    {
        pop(head);
    }
}
int main()
{
    node *head;
    init(head);
    tobinary(head,2);
}