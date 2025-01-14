/*
Given two nodes n1 and n2, The Lowest Common Ancestor (or LCA) is the lowest node in the tree that has both n1 and n2 as descendants.
Given two nodes n1 and n2, The Lowest Common Ancestor (or LCA) is the lowest node in the tree that has both n1 and n2 as descendants. In other words, LCA of n1 and n2 is the shared ancestor of n1 and n2 that is located farthest from the root. 
For example, consider the below tree
LCA of 4 and 5 is 2
LCA of 5 and 6 is 1
LCA of 7 and 2 is 1
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Definition of Tree
class Tree
{
    public:
            int data;
            Tree *left,*right;
    Tree(int val)
    {
        data=val;
        left=right=NULL;
    }
};

Tree* lca(Tree* root,Tree* p,Tree* q)
{
    // Approach we'll traverse the tree if left and right are 
    // null we return null, if we get our node then we return 
    // the node if our left and right both are not null
    // then mean the partiular node at which both are not null
    // is our lca 
    if(root==NULL || p==root || q==root) return root;
    Tree* left=lca(root->left,p,q);
    Tree* right=lca(root->right,p,q);
    if(left==NULL) return right;
    if(right==NULL) return left;
    else{
        // i.e both are not null we got our ans 
        return root;
    }
    
}
int main()
{
    Tree* root=new Tree(1);
    root->left=new Tree(2);
    root->right=new Tree(3);
    root->right->right=new Tree(9);
    Tree*q=root->left->left=new Tree(4);
    Tree* p=root->left->right=new Tree(7);
    /*
                    1
                2      3
            4     7        9 
    */

   Tree* Lca=lca(root,p,q);
   cout<<"LCA of "<<p->data<<" and "<<q->data<<" is "<<Lca->data<<"\n";
    return 0;
}