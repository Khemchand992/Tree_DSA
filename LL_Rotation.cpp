
#include <iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int Height(Node *p){
    int hr,hl;
   hr=p && p->rchild?p->rchild->height:0;
   hl=p&& p->lchild?p->lchild->height:0;
   
   return hr>hl?hr+1:hl+1;
}

int balanceFactor(Node *p){
    int hr,hl;
   hr=p && p->rchild?p->rchild->height:0;
   hl=p&& p->lchild?p->lchild->height:0;
   
   return hl-hr;
}

Node *LLRotation(Node *p){
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    pl->rchild=p;
  p->lchild=plr;
    
    
    p->height=Height(p);
    pl->height=Height(pl);
    if(p==root)
    root=pl;
    
    return pl;
    
}
Node *Rinsert(struct Node *p,int key){
    
    Node *t;
    if(p==NULL){
        t=new Node;
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        p=t;
    }
    else if(p->data<key){
        p->rchild=Rinsert(p->rchild,key);
    }
    else if(p->data>key){
        p->lchild=Rinsert(p->lchild,key);
    }
    
    p->height=Height(p);
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)//LL Rotation 
    {
        return LLRotation(p);
    }
    return p;
}

void preOrder(Node *p){
    if(p){
        cout<<p->data<<" :  "<<Height(p)<<" : " <<balanceFactor(p)<<endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
    
}

int main()
{
    root=Rinsert(root,30);
    Rinsert(root,10);
    Rinsert(root,5);
    preOrder(root);
    return 0;
}
