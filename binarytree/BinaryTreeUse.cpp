#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
int main(){
    Tree<int> *root = new Tree<int>(3);
    Tree<int> *left = new Tree<int>(1);
    Tree<int> *right = new Tree<int>(2);
    root->left = left;root->right = right;
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
    return 0;
}