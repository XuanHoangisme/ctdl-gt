#include<iostream>
using namespace std;

//cau truc cay
struct node
{
    int key;
    node *right; //con tro den cay con tro phai
    node *left; //con tro den cay con tro trai
};

//khoi tao cay
void init(node *&root)
{
    root=NULL;
}

//khoi tao gia tri cho nut
node *creatnode(int x)
{
    node *p=new node;
    p->key=x;
    p->right=NULL;
    p->left=NULL;
    return p;
}

//chen phan tu vao cay
void insertnode(node *&root,int x)
{
    //Tim vi tri can chen
    if(root==NULL)//cay rong
    {
        root=creatnode(x);        
    }
    else
    {
        node *p=root;
        node *parent=NULL;
        while(p!=NULL && p->key!=x)
        {
            parent=p; //luu vi tri truoc do
            if(p->key>x) p=p->left; //tro den cay con tro trai
            else
            {
                p=p->right;   //tro den cay con tro phai
            }
        }
        //Thuc hien chen
        if(p==NULL)
        {
            p=creatnode(x);//gia tri can them vao cay
            if(parent->key>x)
            {
                parent->left=p;
            }
            else
            {
                parent->right=p;
            }
        }
    }
    
}

//xoa nut
void deletenode(node *&root,int x)
{
    if(root!=NULL)//cay khong rong
    {
        node *p=root;
        node *parent=NULL;
        while(p!=NULL &&p->key!=x)
        {
            parent=p;
            if(p->key>x) p=p->left;
            else p=p->right;
        }
        if(p!=NULL)//tim thay nut can xoa
        {
            if(p->left!=NULL && p->right!=NULL)
            {
                //xoa nut co 2 cay con
                parent =p;
                node *r=p->right;//tim phan tu trai nhat ben con tro phai
                while(r->left!=NULL)
                {
                    parent=r;
                    r=r->left;
                }
                p->key=r->key;
                p=r;
            }
            //xoa nut la hoac xoa nut ma chi co 1 nut con
            node *t;
            if(p->left==NULL) t=p->right;
            else if(p->right==NULL) t=p->left;
            if(parent->key>p->key)
            {
                parent->left=t;
            }
            else parent->right=t;
            delete(p);//xoa nut
            /*---------------------------------------*/
        }
    }
}
//tim kiem nut
node* search(node *root,int x)
{
        node *p=root;
        while(p!=NULL && p->key!=x)
        {
            if(p->key>x) p=p->left;
            else p=p->right;
        }
        return p;   
}

//duyet theo thu tu truoc (node -left-right)
void nlr(node *root)
{
    if(root!=NULL)//cay khong rong
    {
        cout<<root->key<<"\t";
        nlr(root->left);
        nlr(root->right);
    }
}

//duyet theo thu tu giua (lefr-node-right)
void lnr(node *root)
{
    if(root!=NULL)//cay khong rong
    {
        lnr(root->left);
        cout<<root->key<<"\t";
        lnr(root->right);
    }
}

//duyet theo thu tu sau (left-right-node)
void lrn(node *root)
{
    if(root!=NULL)//cay khong rong
    {
        lrn(root->left);
        lrn(root->right);
        cout<<root->key<<"\t";
    }
}
int main()
{
    node *root;
    init(root);
    insertnode(root,20);
    insertnode(root,10);
    insertnode(root,9);
    insertnode(root,6);
    insertnode(root,15);
    insertnode(root,11);
    insertnode(root,16);
    insertnode(root,40);
    insertnode(root,25);
    insertnode(root,45);
    insertnode(root,22);
    cout<<"Duyet cay theo thu tu truoc:"<<endl;
    nlr(root);
    cout<<endl;
    cout<<"Duyet cay theo thu tu duyet giua:"<<endl;
    lnr(root);
    cout<<endl;
    cout<<"Duyet cay theo thu tu duyet sau:"<<endl;
    lrn(root);
    //if(search(root,90)!=NULL) cout<<"tim thay 90"<<endl;
    //else cout<<"khong tim thay 90"<<endl;
   // if(search(root,1)!=NULL) cout<<"tim thay 1"<<endl;
    //else cout<<"khong tim thay 1"<<endl;
}