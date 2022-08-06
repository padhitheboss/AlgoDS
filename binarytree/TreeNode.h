template<typename T>
class Tree{
    public:
        T data;
        Tree *left;
        Tree *right;
        Tree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~Tree(){
            delete left;
            delete right;
        }
};
