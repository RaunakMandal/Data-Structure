#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}Node;
void create(Node* root)
{
    Node *p,*t;
    int x,f=1;
    queue <Node*> q;
    cout<<"Enter root: ";
    cin>>x;
    root->data=x;
    root->left=root->right=NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for(f=0;f<2;f++)
        {
            cout<<"Enter "<<p->data<<"'s ";
            (f==0)?cout<<"left: ":cout<<"right: ";
            cin>>x;
            if(x==-2)
                break;
            if(x!=-1)
            {
                t = new Node;
                t->data = x;
                t->left=t->right=NULL;
                (f==0)?p->left=t:p->right=t;
                q.push(t);
            }
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
void inorder(Node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}
void postorder(Node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        cout<<t->data<<" ";
    }
}
void itPreorder(Node *t)
{
    stack<Node*> st;
    while (t!=NULL||!st.empty())
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            st.push(t);
            t=t->left;
        }
        else
        {
            t=st.top();
            st.pop();
            t=t->right;
        }
    }   
}
void itInorder(Node *t)
{
    stack<Node*> st;
    while (t!=NULL||!st.empty())
    {
        if(t!=NULL)
        {
            st.push(t);
            t=t->left;
        }
        else
        {
            t=st.top();
            st.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }   
}
void levelOrder(Node* p)
{
    queue <Node*> q;
    cout<<p->data;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left)
        {
            cout<<" "<<p->left->data;
            q.push(p->left);
        }
        if(p->right)
        {
            cout<<" "<<p->right->data;
            q.push(p->right);
        }
    }
}
int main()
{
    Node *root;
    root = new Node;
    create(root);
    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nIterative Preorder: ";
    itPreorder(root);
    cout<<"\nIterative Inorder: ";
    itInorder(root);
    cout<<"\nLevel Order: ";
    levelOrder(root);
    cout<<endl;
}