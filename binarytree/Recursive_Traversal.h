#include<iostream>
using namespace std;
void RPreorder(Tree<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    RPreorder(root->left);
    RPreorder(root->right);
}
void RInorder(Tree<int> *root){
    if(root == NULL){
        return;
    }
    RInorder(root->left);
    cout<<root->data<<" ";
    RInorder(root->right);
}
void RPostorder(Tree<int> *root){
    if(root == NULL){
        return;
    }
    RPostorder(root->left);
    RPostorder(root->right);
    cout<<root->data<<" ";
}