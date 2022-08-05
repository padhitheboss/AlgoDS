#include<bits/stdc++.h>
#include "tree.h"
using namespace std;
void PrintTree(TreeNode<int> *root){
    cout<<root->data<<":";
    for(int i =0;i<root->childern.size();i++){
        cout<<root->childern[i]->data;
    }
    cout<<"\n";
    for(int i =0;i<root->childern.size();i++){
        PrintTree(root->childern[i]);
    }
}
TreeNode<int> * TakeInput(){
    queue<TreeNode<int>*> q;
    int rd;
    //cout<<"Enter Root Data: ";
    cin>>rd;
    TreeNode<int> *root =new TreeNode<int>(rd);
    q.push(root);
    while (!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        int n = 0;
        //cout<<"Enter Number of Children for"<<front->data<<":";
        cin>>n;
        for(int i = 0;i<n;i++){
            int dat = 0;
            //cout<<"Enter "<<i<<"th child for "<<front->data<<":";
            cin>>dat;
            TreeNode<int> *child = new TreeNode<int>(dat);
            front->childern.push_back(child);
            q.push(child);
        }
    }
    return root;
}
int countNodes(TreeNode<int> *root){
    int ans = 1;
    for(int i = 0;i<root->childern.size();i++){
        ans += countNodes(root->childern[i]);
    }
    return ans;
}
int height(TreeNode<int> *root){
    int ans = -1;
    for(int i = 0;i<root->childern.size();i++){
        ans = max(ans,height(root->childern[i]));
    }
    return ans+1;
}
void printChildatn(TreeNode<int> *root,int index){
    if(index == 0){
        cout<<root->data;
        return;
    }
    for(int i = 0;i<root->childern.size();i++){
        printChildatn(root->childern[i],index-1);
    }
}
int findleaf(TreeNode<int> *root){
    int ans = 0;
    if(root->childern.size()==0){
        return 1;
    }
    for(int i = 0;i<root->childern.size();i++){
        ans += findleaf(root->childern[i]);
    }
    return ans;
}
void preorder(TreeNode<int> *root){
    cout<<root->data;
    for(int i = 0;i<root->childern.size();i++){
        preorder(root->childern[i]);
    }
}
void postorer(TreeNode<int> *root){
    for(int i = 0;i<root->childern.size();i++){
        postorer(root->childern[i]);
    }
    cout<<root->data;
}
int main(){
    // TreeNode<int> *root = new TreeNode<int> (1);
    // TreeNode<int> *right = new TreeNode<int>(2);
    // TreeNode<int> *left = new TreeNode<int>(3);
    // root->childern.push_back(right);
    // root->childern.push_back(left);

    TreeNode<int> *root = TakeInput();
    PrintTree(root);
    cout<<countNodes(root)<<endl;
    cout<<height(root)<<endl;
    printChildatn(root,4);
    cout<<"\n";
    cout<<findleaf(root);
    cout<<"\n"<<"\n";
    preorder(root);
    cout<<"\n"<<"\n";
    postorer(root);
    delete root;
}
//5 2 1 2 2 1 4 0 2 6 9 0 1 9 0 0