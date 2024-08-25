#include<iostream>
using namespace std;

//cau truc node
struct node
{
    int value;
    node *next;
    node *previous;
};

//double
struct doublelinkedlist
{
    node *head;//phan tu dau tien trong danh sach
    node *tail;//phan tu cuoi cung trong danh sach
};

//khoi tao node 
void init(doublelinkedlist &ls)
{
    ls.head=ls.tail=NULL;
}

//khoi tao gia tri cho node
node* creatnode(int x)
{
    node *p=new node;
    p->value=x;
    p->next=NULL;
    p->previous=NULL;
    return p;
}

//them phan tu vao dau danh sach
void addfirst(doublelinkedlist &ls,int x)
{
    node *p=creatnode(x);
    if(ls.head==NULL)//danh sach rong
    {
        ls.head=ls.tail=p;
    }
    else
    {
        p->next=ls.head;
        ls.head->previous=p;
        ls.head=p;
    }
}

//them phan tu vao cuoi danh sach
void addlast(doublelinkedlist &ls,int x)
{
    node *p=creatnode(x);
    if(ls.head==NULL)//danh sach rong
    {
        ls.head=ls.tail=p;
    }
    else
    {
        p->previous=ls.tail;
        ls.tail->next=p;
        ls.tail=p;
    }
}

//them phan tu sau phan tu chi dinh
void addafter(doublelinkedlist &ls,int v,int x)
{
        node *q=ls.head;
        while(q!=NULL&&q->value!=v)
        {
            q=q->next;
        }
        if(q!=NULL)//tim thay phan de chen vao sau
        {
            if(q==ls.tail)//phan tu can them vao o cuoi danh sach
            {
                addlast(ls,x);
            }
            else
            {
                 node *p=creatnode(x);//khoi tao gia tri can them vao danh sach
                p->next=q->next;
                q->next->previous=p;
                q->next=p;
                p->previous=q;
            }
           
        }
        
}

//xoa phan tu o dau danh sach
void deletefirst(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        if(ls.head==ls.tail)//danh sach chi co 1 phan tu
        {
            ls.head=ls.tail=NULL;
        }
        else
        {
            node *p=ls.head;
            ls.head=p->next;
            ls.head->previous=NULL;
            p->next=NULL;
            delete(p);//xoa phan tu o cuoi danh sach
        }
        
    }
}

//xoa phan tu o cuoi danh sach
void deletelast(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        if(ls.head==ls.tail)//danh sach chi co 1 phan tu
        {
            ls.head=ls.tail=NULL;
        }
        else
        {
            node *p=ls.tail;
            ls.tail=p->previous;
            p->previous->next=NULL;
            p->previous=NULL;
            delete(p);//xoa phan tu o cuoi danh sach
        }
        
    }
}

//xoa phan tu chi dinh
void deletenode(doublelinkedlist &ls,int x)
{
    if(ls.head!=NULL)//danh sach co phan tu de xoa
    {
        node *p=ls.head;
        node *prev=NULL;
        while(p!=NULL&&p->value!=x)
        {
            prev=p;
            p=p->next;
        }
        if(p!=NULL)//tim thay phan tu de xoa
        {
            if(p->next==NULL)//phan tu can xoa o cuoi danh sach
            {
                deletefirst(ls);
            }
            else
            {
                prev->next=p->next;
                p->next->previous=prev;
                p->next=NULL;
                p->previous=NULL;
                delete(p);//xoa phan tu
            }  
        }
    }
}

//tim kiem phan tu trong danh sach
void find(const doublelinkedlist ls,int v)
{
    
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        while(p!=NULL&&p->value!=v)
        {
            p=p->next;
        }    
        if(p!=NULL)//tim thay phan tu
        {
            cout<<"phan tu can tim la: "<<p->value;
        }
        else
        {
            cout<<"khog tim thay phan tu can tim"<<endl;
        }
    }
}

//ham hoan vi
void swap(node *a,node *b)
{
    node *temp=a;
    a=b;
    b=temp;
}

/*-------------------------------CAI DAT CAC THUAT TOAN---------------------------------*/

//thuat toan selection sort(thuat toan lua chon)
void selection_sort(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        for(p;p!=ls.tail;p=p->next)
        {
            node *q=p;
            node *j=p->next;
            for(j;j!=NULL;j=j->next)
            {
                if(j->value<q->value) q=j;//tim duoc vi tri trong danh sach co phan tu nho
            }
            swap(p->value,q->value);//doi vi tri, dua vi tri nho nhat len dau
        }
    }
}

//Thuat toan InterchangeSort (thuat toan sap xep doi cho truc tiep)
void insertchange_sort(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        node *q;
        for(p;p!=ls.tail;p=p->next)
        {
            for(q=p->next;q!=NULL;q=q->next)
            {
                if(p->value > q->value) swap(p->value,q->value);
            }
        }
    }
}

//thuat toan bubble sort( thuat toan sap xep noi bot)
void bubble_sort(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;//gan phan tu dau danh sach vao p
        node *q;
        for(p;p!=ls.tail;p=p->next)
        {
            for(q=ls.tail;q!=p;q=q->previous)
            {
                if(q->value<q->previous->value) swap(q->value,q->previous->value);
            }
        }
    }
}

//thuat toan insertion sort( sap xep chen )
void insertion_sort(doublelinkedlist &ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;//gan p vao phan tu dau danh sach
        for(p=p->next;p!=NULL;p=p->next)
        {
            node *q=p;
            int t=p->value; //gia tri can mang so sanh voi cac phan tu cua day con
            for(q;q!=ls.head&&q->previous->value>t;q=q->previous)
            {
                q->value=q->previous->value;
            }
            q->value=t;
        }
    }
}

//xuat danh sach 
void output(const doublelinkedlist ls)
{
    if(ls.head!=NULL)//danh sach co phan tu
    {
        node *p=ls.head;
        while(p!=NULL)
        {
            cout<<p->value<<"\t";
            p=p->next;
        }
    }
}

/*--------------------------HAM MAIN CHINH-----------------------------*/
int main()
{
    doublelinkedlist ls;
    init(ls);
    addfirst(ls,4);
    addfirst(ls,5);
    addlast(ls,6);
    addlast(ls,7);
    addafter(ls,5,9999);
   // deletefirst(ls);
   // deletelast(ls);
   // deletenode(ls,7);
   // find(ls,6);
    cout<<"DANH SACH CAC PHAN TU: "<<endl;
    output(ls);
    cout<<endl;
    cout<<"DANH SACH SAU KHI SAP XEP LUA CHON SELECTION SORT:"<<endl;
    selection_sort(ls);
    output(ls);
    cout<<endl;
    cout<<"DANH SACH SAU KHI SAP XEP CHEN INSERTION SORT:"<<endl;
    insertion_sort(ls);
    output(ls);
    cout<<endl;
    cout<<"DANH SACH SAU KHI SAP XEP NOI BOT BUBBLE SORT:"<<endl;
    bubble_sort(ls);
    output(ls);
    cout<<endl;
    cout<<"DANH SACH SAU KHI SAP XEP DOI CHO TRUC TIEP INTERCHANGE SORT:"<<endl;
    insertchange_sort(ls);
    output(ls);
    system("pause");
}