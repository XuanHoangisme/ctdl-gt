#include<iostream>
using namespace std;
//cau truc node
struct node 
{
    int value;
    node *next;
    node *previous;
};

struct dobublelinkedlist
{
    node *head;
    node *tail;
};
//khoi tao node 
void init(dobublelinkedlist &ls)
{
    ls.head=ls.tail=NULL;
}

//khoi tao gia tri cho node
node *createnode(int x)
{
    node *p=new node;
    p->value=x;
    p->next=NULL;
    p->previous=NULL;
}

//them phan tu vao queue
void enqueue(dobublelinkedlist &ls,int x)
{
    node *p=createnode(x);
    if(ls.head==NULL)//queue chua co phan tu
    {
        ls.head=ls.tail=p;
    }
    else
    {
        ls.tail->next=p;
        p->previous=ls.tail;
        ls.tail=p;
    }
}

//lay phan tu ra khoi queue
void dequeue(dobublelinkedlist &ls)
{
    if(ls.head!=NULL)//trong queue co phan tu
    {
        node *p=ls.head;
        if(ls.head==ls.tail)//chi co 1 phan tu
        {
            cout<<ls.head->value<<"\t";
            ls.head=ls.tail=NULL;
        }
        else
        {
            cout<<p->value<<"\t";
            p->next->previous=NULL;
            ls.head=p->next;
            p->next=NULL;
            delete(p);
        }

    }
}
void output(dobublelinkedlist ls)
{
    node *p=ls.head;
    if(ls.head!=NULL)//danh sach co phan tu
    {
        while(p!=NULL)
        {
            cout<<p->value<<"\t";
            p=p->next;
        }
    }
}

//kiem tra danh sach rong
bool isEmpty(dobublelinkedlist ls)
{
    return ls.head==NULL;
}

//xuat chuoi
void FIFO(dobublelinkedlist ls)
{
    while(isEmpty(ls)==0)
    {
        dequeue(ls);
    }
}
int main()
{
    dobublelinkedlist ls;
    init(ls);
    enqueue(ls,4);
    enqueue(ls,8);
   // enqueue(ls,10);
   // enqueue(ls,1);
    FIFO(ls); 
}