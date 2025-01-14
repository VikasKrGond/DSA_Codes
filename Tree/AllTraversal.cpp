#include <iostream>
#include <stack>
#include <vector>
#include<queue>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        data = val;
        left = right = NULL;
    }
};
//Level Order Traversal
//Level order means the the BFS search 
//In level order traversal we have the ds i.e queue in which we'll
// push the root first then run a loop till the queue is empty
// pop the node but push it's child i.e left and right into the stack
void levelOrder(Tree* root)
{   if(root==NULL) cout<<"Empty Tree";
    queue<Tree*>st;
    st.push(root);
    vector<int>lvlOrder;
    while(!st.empty())
    {
        Tree* node=st.front();
        lvlOrder.push_back(st.front()->data);
        st.pop();
        if(node->left!=NULL)st.push(node->left);
        if(node->right!=NULL) st.push(node->right);
    }
    for(auto it : lvlOrder) cout<<it<<" ";
    cout<<endl;
}

// Iterative Solutions
void ino_it(Tree *root)
{
    vector<int> ino;
    if (root == NULL)
    {
        cout << "\nEmpty Tree";
        return;
    }
    stack<Tree *> st;
    st.push(root);
    while (!st.empty())
    {
        // if left node exist then pus it into the stack
        while (root->left != NULL)
        {
            st.push(root->left);
            root = root->left;
        }
        Tree *node = st.top();
        st.pop();
        ino.push_back(node->data);
        if (node->right != NULL)
        {
            st.push(node->right);
        }
    }
    cout << "\n Printing the interative inorder : ";
    for (int &it : ino)
    {
        cout << it << " ";
    }
}

void pre_it(Tree *root)
{
    if (root == NULL)
    {
        cout << "\nEmpty Tree";
        return;
    }
    stack<Tree *> st;
    st.push(root);
    cout << "\n Printing the interative preorder : ";
    while (!st.empty())
    {
        Tree *node = st.top();
        st.pop();
        cout<<node->data<<" ";
        // Push right child first (so left is processed first)
        if (node->right != NULL)
        {
            st.push(node->right);
        }
        if (node->left != NULL)
        {
            st.push(node->left);
        }
    }
}
/*
Postorder traversal is a little trickier because we need to ensure that both children are visited before the root. One way to do this iteratively is to use two stacks:
Push the root onto the first stack.
While the first stack is not empty:
Pop a node from the first stack and push it onto the second stack.
Push the left child and then the right child of the node onto the first stack.
Once the first stack is empty, the second stack will contain nodes in postorder, so we just pop from the second stack and print the values.
*/
void post_it(Tree *root)
{
    vector<int> post;
    if (root == NULL)
    {
        cout << "\nEmpty Tree";
        return;
    }
    stack<Tree *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Tree *node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != NULL)
            st1.push(node->left);
        if (node->right != NULL)
            st1.push(node->right);
    }
    cout << "\n Printing the interative Postorder : ";
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// Recursuve Solution
void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(3);
    root->right = new Tree(4);
    root->left->left = new Tree(2);
    /*
                 1
               3     4
             2
    */
    cout << "Printing the inorder traversal of Tree: ";
    inorder(root);
    cout << "\nPrinting the preorder traversal of Tree: ";
    preorder(root);
    cout << "\nPrinting the postorder traversal of Tree: ";
    postorder(root);

    ino_it(root);
    pre_it(root);
    post_it(root);
    cout<<"\nPrinting the Level Order Traversal : ";
    levelOrder(root);
    return 0;
}