#include<iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
//khoi tao node dau tien==NULL
void init(Node *&head)
{
    head=NULL;
}
//khoi tao gia tri cua Node
Node *createNode(int x)
{
    Node *p=new Node;
    p->value=x;
    p->next=NULL;
    return p;
}
//them phan tu vao dau danh sach
void addfirst(Node *&head,int x)
{
    Node *p = createNode(x);
    //dua gia tri vao dau cua danh sach
    p->next=head;
    head=p;
}
//them phan tu vao cuoi ds
void addlast(Node *&head,int x )
{
    Node *p=createNode(x);
    //neu danh sach rong thi chen vao dau danh sach
    if(head==NULL){
        head=p;
    }
    else
    {
        Node *last=head;
        //xac dinh node cuoi cung
        while(last->next!=NULL)
        {
            last=last->next;
        }
        //chen vao cuoi
        last->next=p;
    }
}
//them phan tu vao sau 1 phan tu khac trong danh sach
void addafter(Node *&head,int v,int x)
{
    Node *p=createNode(x);
    //tim node co gia tri la v
    Node *q=head;
    while(q!=NULL&& q->value!=v)
    {
        q=q->next;
    }
    //q la node dai dien cho v tren danh sach 
    if(q!=NULL)//kiem tra xem trong danh sach co phan tu v khong
    {
        p->next=q->next;
        q->next=p;
    }
}
//xoa phan tu dau trong danh sach
void deletefirst(Node *&head)
{
    if(head!=NULL)//kiem tra xem danh sach co rong khong
    {
        Node *p=head;
        head=p->next;
        p->next=NULL;
    delete(p);
    }
}
//xoa phan tu cuoi cung trong danh sach
void deletelast(Node *&head)
{
    if(head!=NULL)
    {
        //xac dinh nut cuoi cung va nut truoc cua nut cuoi cung
        Node *last=head;
        Node *prev=NULL;
        while(last->next!=NULL)
        {
            prev=last;
            last=last->next;
        }
        //neu danh sach chi co 1 phan tu
        if(prev==NULL)
        {
            delete(last);
            //cach 2:
            //deletefirst(head);
        }
        else
        {
        //xoa phan tu cuoi cung cua danh sach
        prev->next=NULL;
        delete(last);
        }
    }
}
//xoa 1 phan tu chi dinh trong danh sach
void deletenode(Node *&head,int v)
{
    Node *p=head;
    Node *prev=NULL;
    if(head!=NULL)
    {
    while(p!=NULL && p->value!=v)
    {
        prev=p;
        p=p->next;
    }
    if(p!=NULL)//tim thay phan tu can xoa
    {
        if(prev==NULL) //danh sach chi co 1 phan tu
        {
            deletefirst(head);
        }
        else
        {
            prev->next= p->next;
            p->next=NULL;
            delete(p);
        }
    }
    }
}
//xuat cac phan tu ra
void output(Node *head)
{
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->value<<"\t";
        p=p->next;
    }
}
int main()
{
    Node *head;
    init(head);
    addlast(head,89);
    addfirst(head,15);
    addfirst(head,10);
    addfirst(head,9);
   // addlast(head,1000);
    output(head);
    cout<<endl;
   // addafter(head,10,8876);
    //output(head);
    //deletefirst(head);
   // deletelast(head);
   deletenode(head,9090909);
    cout<<endl;
    output(head);
}