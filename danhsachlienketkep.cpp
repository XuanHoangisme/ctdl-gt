#include<iostream>
using namespace std;
struct node 
{
    int value;
    node *next;
    node *pevious;
};


struct doublelinkedlist
{
    node *head;//luon tro den phan tu dau tien
    node *tail; // luon tro den phan tu cuoi cung
};

//khoi tao node
void init(doublelinkedlist &ls)
{
    ls.head=NULL;
    ls.tail =NULL;
}
//khoi tao gia tri cho node
node *createnode(int x)
{
    node *p= new node;
    p->value =x;
    p->pevious =NULL;
    p->next =NULL;
    return p;
};

//them phan tu vao dau danh sach
void addfirst(doublelinkedlist &ls,int x)
{
    node *p =createnode(x);
    if(ls.head==NULL)//danh sach rong
    {
        ls.head=ls.tail=p;
    }
    else
    {
        p->next=ls.head;
        ls.head->pevious=p;
        ls.head=p;
    }
}

//them phan tu vao cuoi danh sach
void addlast(doublelinkedlist &ls,int x)
{
    node *p=createnode(x);
    if(ls.head==NULL)
    {
        ls.head=ls.tail=p;
    }
    else
    {
        ls.tail->next=p;
        p->pevious=ls.tail;
        ls.tail=p;
    }  
}

//them phan tu vao sau mot phan tu
void addafter(doublelinkedlist &ls,int v,int x)
{
    node *q=ls.head;
    while(q!=NULL&& q->value!=v)
    {
        q=q->next;
    }
    if(q!=NULL)//tim thay phan tu can chen vao sau 
    {
        if(q==ls.tail)//phan tu can chen vao sau o cuoi danh sach
        {
            addlast(ls,x);
        }
        else
        {
            node *p=createnode(x);
            p->next=q->next;
            q->next->pevious=p;
            q->next=p;
            p->pevious=p;
        }
    }
}

//xoa phan tu o dau danh sach
void deletefirst(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu de xoa
    {
        node *p=ls.head;
        if(p->next==NULL)//danh sach chi co 1 phan tu
        {
            ls.tail=NULL;
            ls.head=NULL;
        }
        else
        {
            ls.head=p->next;
            p->next->pevious=NULL;
            p->next=NULL;
        }
        delete(p);
    }  
}

//xoa phan tu o cuoi danh sach
void deletelast(doublelinkedlist &ls)
{
    if(ls.tail!=NULL)//danh sach co phan tu de xoa
    {
        if(ls.tail->pevious==NULL)//danh sach chi co 1 phan tu
        {
            ls.tail=ls.head=NULL;
        }
        else
        {
            node *p=ls.tail;
            ls.tail=p->pevious;
            p->pevious->next=NULL;
            p->pevious=NULL;
            delete(p);//xoa phan tu cuoi cung cua danh sach
        }  
    }
}

//xoa 1 phan tu chi dinh trong danh sach
void deletenode(doublelinkedlist &ls,int x)
{
    node *p=ls.head;
    node *prev=NULL;
    if(ls.head!=NULL)//danh sach luon co phan tu
    {
            while(p!=NULL &&p->value!=x)
            {
                prev=p;
                p=p->next;
            }
        if(p!=NULL)
        {
            if(prev==NULL)//danh sach chi co 1 phan tu
            {
                deletefirst(ls);
            }
        else
        {
            prev->next=p->next;
            p->next->pevious=prev;
            p->next=NULL;
            p->pevious=NULL;
            delete(p);
        }
        }  
    }

}
//tim kiem phan tu dau danh sach
void searchnode(doublelinkedlist ls,int x)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        while(p!=NULL &&p->value!=x)
        {
            p=p->next;
        }
        if(p!=NULL)//tim thay phan tu can tim trong danh sach
        {
            cout<<"gia tri can tim la: "<<p->value<<endl;
        }
        else
        {
            cout<<"khong tim thay gia tri can tim";
        }
    }
}
//xuat tu trai sang phai
void outputlefttoright(doublelinkedlist ls)
{
    node *p=ls.head;
    while(p!=NULL)
    {
        cout<<p->value<<"\t";
        p=p->next;
    }
}
//xuat tu phai sang trai
void outputrighttoleft(doublelinkedlist ls)
{
    node *p=ls.tail;
    while(p!=NULL)
    {
        cout<<p->value<<"\t";
        p=p->pevious;
    }
}
int main()
{
    doublelinkedlist ls;
    init(ls);
      addlast(ls,4);
     addfirst(ls,10);
    addfirst(ls,9);
   addfirst(ls,8);
    addlast(ls,99);
    //  addafter(ls,9,999);
 //   outputlefttoright(ls);
   // deletefirst(ls);
   //deletelast(ls);
   deletenode(ls,999);
    cout<<endl;
    outputlefttoright(ls);
    cout<<endl;
   // searchnode(ls,99);
  // outputrighttoleft(ls);
}