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
//left View of a Tree
//Logic: Whenever we encounter the levl for the first time we'll 
// Push the node in lef
//Preorder with level check
void leftView(Tree* root,vector<int>&lef,int lvl)
{
    if(root==NULL) return;
    if(lvl==lef.size()) // Just to check we reach the level for 
    // the first time
    lef.push_back(root->data);
    leftView(root->left,lef,lvl+1);
    leftView(root->right,lef,lvl+1);
}

//Reverse Preorder root right left
void rightView(Tree* root,vector<int>&righ,int lvl)
{
    if(root==NULL) return;
    if(lvl==righ.size()) // Just to check we reach the level for 
    // the first time
    righ.push_back(root->data);
    rightView(root->right,righ,lvl+1);
    rightView(root->left,righ,lvl+1);
    
}
// //left View of a Tree
// void leftView(Tree* root,vector<int>&lef)
// {
//     if(root==NULL) return;
//     lef.push_back(root->data);
//     leftView(root->left,lef);
//     if(root->left==NULL)
//     leftView(root->right,lef);

// }
int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->right->left = new Tree(4);
    root->right->right = new Tree(5);
   /*
                 1
              2     3
                  4     5
   */

  vector<int>lef;
  vector<int>righ;
  leftView(root,lef,0);
  rightView(root,righ,0);
  cout<<"\nLeft View of the Tree: ";
  for(auto it:lef) cout<<it<<" ";

  cout<<"\nRight View of the Tree: ";
  for(auto it :righ)
  {
    cout<<it<<" ";
  }  
  return 0;
}