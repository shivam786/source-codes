#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<climits>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
node* newNode(int d)
{
    node* x=new node;
    x->data=d;
    x->left=NULL;
    x->right=NULL;
    return x;
}
int its(node* x)
{
    if(x==NULL)
        return INT_MIN;
    int res=x->data;
    int lres=its(x->left);
    int rres=its(x->right);
    res=max(res,max(lres,rres));
    return res;
}
int main()
{
   struct node *root = newNode(1);
   root->left        = newNode(2);
   root->right       = newNode(3);
   root->left->left  = newNode(4);
   root->left->right = newNode(5);
   root->left->left->left  = newNode(6);
   root->left->left->right = newNode(7);
    cout<<its(root);
    return 0;
}
