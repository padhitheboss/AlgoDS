#include<bits/stdc++.h>
#include "TreeNode.h"
#include "Recursive_Traversal.h"
#include "input.h"
#include "Iterative_Traversal.h"
using namespace std;

int count_nodes(Tree<int>* root){
    if(root == NULL){
        return 0;
    }
    int lc = count_nodes(root->left);
    int rc = count_nodes(root->right);
    return lc + rc +1 ;
}
int count_leaf(Tree<int> * root){
    if(root== NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return count_leaf(root->left) + count_leaf(root->right);

}
int height_tree(Tree<int> *root){
    if(root == NULL){
        return 0;
    }
    return max(height_tree(root->left),height_tree(root->right)) + 1;
}
bool ifexist(Tree<int> *root,int key){
    if(root == NULL){return false;}
    if(root->data == key){
        return true;
    }
    if(ifexist(root->left,key)){return true;}
    if(ifexist(root->right,key)){return true;}
    return false;
}
void mirror(Tree<int> *root){
    if(root == NULL){
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}
int main(){
    // Tree<int> *root = new Tree<int>(3);
    // Tree<int> *l = new Tree<int>(1);
    // Tree<int> *r = new Tree<int>(2);
    // root->left = l;root->right = r;
    //cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
    Tree<int> *root = level_input();// input_tree();
    // cout<<"\nPrinting Preorder Traversal"<<endl;
    // RPreorder(root);
    // cout<<"\nPrinting Inorder Traversal"<<endl;
    // RInorder(root);
    // cout<<"\nPrinting Postorder Traversal"<<endl;
    // RPostorder(root);
    // cout<<"\n";
    // cout<<count_nodes(root)<<endl;
    // cout<<"\n";
    // cout<<count_leaf(root)<<endl;
    // cout<<"\n";
    // cout<<height_tree(root)<<endl;
    // int key;cin>>key;
    //cout<<ifexist(root,key);
    levelorder(root);
    mirror(root);
    levelorder(root);
    return 0;
}