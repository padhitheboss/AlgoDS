#include<stdio.h>
using namespace std;

void levelorder(Tree<int> *root){
    queue<pair<Tree<int>*,int>>q;
    q.push({root,0});int prev = -1;
    while(!q.empty()){
        pair<Tree<int>*,int> top = q.front();
        q.pop();
        if(top.first->left){q.push({top.first->left,top.second+1});}
        if(top.first->right){q.push({top.first->right,top.second+1});}
        if(prev+1 == top.second){cout<<"\n";prev = top.second;}
        cout<<top.first->data;
    }
}
void IPreorder(Tree<int> *root){

}

void IInorder(Tree<int> *root){

}

void IPostorder(Tree<int> *root){

}