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

int maxDepth(Tree* root)
{
    if(root==NULL) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
}
int main()
{
    Tree* root=new Tree(1);
    root->left=new Tree(2);
    root->right=new Tree(4);
    root->left->left=new Tree(5);
    cout<<"Maximum Depth of Tree is: "<<maxDepth(root);
    return 0;

}