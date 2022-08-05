#include<vector>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> childern;
    TreeNode(int data){
        this->data = data;
    }
    ~TreeNode(){
        for(int i = 0;i<childern.size();i++){
            int bak = childern[i]->data;
            delete childern[i];
            cout<<"\nDestructor called for"<<bak;
        }
    }
} ;