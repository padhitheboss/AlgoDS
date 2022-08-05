template<typename T>
class Tree{
    public:
        T data;
        Tree *left;
        Tree *right;
        Tree(int data){
            this->data = data;
        }
        ~Tree(){
            delete left;
            delete right;
        }
};
