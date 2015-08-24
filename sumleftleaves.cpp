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
bool isLeaf(node* a)
{
    if(a==NULL)
        return false;
    if(a->left==NULL&&a->right==NULL)
        return true;
    return false;
}
int its(node* root)
{
   int res=0;
   if(root!=NULL)
   {
       if(isLeaf(root->left))
            res+=root->left->data;
       else
            res+=its(root->left);
       res+=its(root->right);
   }
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
