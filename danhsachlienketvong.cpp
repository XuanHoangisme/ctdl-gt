#include<iostream>
using namespace std;
//cau truc node
struct node
{
    int value;
    node *next;
};

struct circlelinkedlist
{
    node *head;//phan tu dau cua danh sach
    node *tail;//phan tu cuoi cua danh sach
};

//khoi tao node
void init(circlelinkedlist &ls)
{
    ls.head=ls.tail=NULL;
}

//khoi tao gia tri cho node
node *createnode(int x)
{
    node *p=new node;
    p->value=x;
    p->next=NULL;
    return p;
}

//them phan tu vao dau danh sach
void addfirst(circlelinkedlist &ls,int x)
{
    node *p=createnode(x);//gia tri node can them vao danh sach
    if(ls.head==NULL) //danh sach rong
    {
        ls.head=ls.tail=p;
        ls.tail->next=ls.head;
    }
    else
    {
        p->next=ls.head;
        ls.head=p;
        ls.tail->next=ls.head;
    }

}

//them phan tu vao cuoi danh sach
void addlast(circlelinkedlist &ls,int x)
{
    node*p=createnode(x);//gia tri can them vao
    if(ls.head==NULL)//danh sach rong
    {
        ls.head=ls.tail=p;
        ls.tail->next=ls.head;
    }
    else
    {
        ls.tail->next=p;
        ls.tail=p;
        p->next=ls.head;
    }
}

//them phan tu vao sau 1 phan tu bat ky
void addafter(circlelinkedlist &ls,int v,int x)
{
    node *p=createnode(x);//gia tri can them vao danh sach
    node *q=ls.head;
    if(ls.head!=NULL)//danh sach co phan tu
    {
        while(q!=NULL && q->value !=v)
        {
            q=q->next;
        }
        if(q==ls.tail)//vi tri can them o cuoi danh sach
        {
            addlast(ls,x);
        }
        else
        {
            p->next=q->next;
            q->next=p;
        }   
    }
}

//xoa phan tu o dau danh sach
void deletefirst(circlelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu de xoa
    {
        if(ls.head==ls.tail)//danh sach chi co 1 phan tu
        {
            ls.head=ls.tail=NULL;
        }
        else
        {
            node *p=ls.head;
            ls.head=p->next;
            ls.tail->next=ls.head;
            p->next=NULL;
            delete(p);//xoa phan tu dau tien
        }  
    }
}

//xoa phan tu o cuoi danh sach
void deletelast(circlelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu de xoa
    {
        node *p=ls.head;
        node *prev=NULL;
        while(p !=ls.tail)
        {
            prev=p;
            p=p->next;
        }
        if(prev==NULL)//danh sach chi co 1 phan tu
        {
            ls.head=ls.tail=NULL;
        }
        else
        {
             ls.tail=prev;
             ls.tail->next=ls.head;
             p->next=NULL;
        }
        delete(p);//xoa phan tu o cuoi danh sach
        
    }
}

//xoa 1 phan tu chi dinh trong danh sach
void deletenode(circlelinkedlist &ls,int v)
{
    if(ls.head!=NULL)//danh sach co phan tu de xoa
    {
         node *p=ls.head;
         node *prev=NULL;
         while(p->value!=v)
         {
            prev=p;
            p=p->next;
         }
         
         if(p==ls.head)//phan tu can xoa o dau danh sach
         {
            deletefirst(ls);
         }
         else
         {
            prev->next=p->next;
            p->next=NULL;
           
         }
         delete(p);//xoa phan tu  
    }
   
}
//xuat phan tu ra man hinh
void output(circlelinkedlist ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        do
        {
            cout<<p->value<<"\t";
            p=p->next;
        } while (p!=ls.head);
    }
}
int main()
{
    circlelinkedlist ls;
    init(ls);
    //addfirst(ls,5);
    //addfirst(ls,1);
    //deletefirst(ls);
    //addafter(ls,1,4);
    addfirst(ls,9);
    
    addlast(ls,4);
    //addafter(ls,4,10);
    //addlast(ls,3);
    //addlast(ls,5);
    output(ls);
    cout<<endl;
    //deletelast(ls);
    deletenode(ls,9);
    output(ls);
}