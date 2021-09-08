#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}Node;
Node *root;
void create()
{
    Node *p,*t;
    int x,f=1;
    queue <Node*> q;
    cout<<"Enter root: ";
    cin>>x;
    root = new Node;
    root->data=x;
    root->left=root->right=NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for(f=1;;f*=-1)
        {
            cout<<"Enter "<<p->data<<"'s ";
            (f>0)?cout<<"left: ":cout<<"right: ";
            cin>>x;
            if(x!=-1)
            {
                t = new Node;
                t->data = x;
                t->left=t->right=NULL;
                (f>0)?p->left=t:p->right=t;
                q.push(t);
            }
            if(f==-1)
                break;
        }
    }
}
void preorder(Node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        preorder(t->left);
        preorder(t->right);
    }
}
int main()
{
    create();
    preorder(root);
    cout<<endl;
}