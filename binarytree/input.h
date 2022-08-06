#include<iostream>

//-1 means end of subtree. NULL int the left and right.
//5 1 1 6 9 -1 -1 -1 9 -1 -1 4 -1 -1 2 -1 -1
Tree<int>* input_tree(){
    int dat;
    cin>>dat;
    if(dat == -1){
        return NULL;
    }
    Tree<int> *root = new Tree<int>(dat);
    Tree<int> *le = input_tree();
    Tree<int> *ri = input_tree();
    root->left = le;root->right = ri;
    return root;
}

//5 1 2 1 4 -1 -1 6 9 -1 -1 9 -1 -1 -1 -1 -1

Tree<int>* level_input(){
    queue<Tree<int>*> q;
    int dat;
    cin>>dat;
    Tree<int> *root = new Tree<int>(dat);
    q.push(root);
    while(!q.empty()){
        Tree<int> *top = q.front();
        q.pop();
        int ldat;
        //cout<<"Enter Left Child of"<<top->data<<":";
        cin>>ldat;
        if(ldat == -1){
            top->left = NULL;
        }else{
            Tree<int> *le = new Tree<int>(ldat);
            top->left = le;
            q.push(le);
        }
        int rdat;
        //cout<<"Enter Right Child of"<<top->data<<":";
        cin>>rdat;
        if(rdat == -1){
            top->right = NULL;
        }else{
            Tree<int> *ri = new Tree<int>(rdat);
            top->right = ri;
            q.push(ri);
        }
    }
    return root;
}