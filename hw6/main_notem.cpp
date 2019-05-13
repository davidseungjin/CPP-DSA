e

using namespace std;

class TreeNode{
public:
    string key;
    int info;
    TreeNode* left;
    TreeNode* right;
    
public:
    // Constructor
    TreeNode(string k, int e, TreeNode* l, TreeNode* r)
    : key(k), info(e), left(l), right(r){}
    static TreeNode* newNode(string k, int e, TreeNode* l, TreeNode* r){
        return new TreeNode(k, e, l, r);
    }
    
    static TreeNode* insert(string key, int info, TreeNode* RootT){
        if (RootT != NULL){
            RootT = newNode(key, info, nullptr, nullptr);
            TreeNode* t = RootT;
            while (t->key !=  key){
                if (key < t->key){
                    if (t->left != NULL)
                        t->left = newNode(key, info, NULL, NULL);
                        t = t->left;
                }else if(key > t->key){
                    if (t->right != NULL)
                        t->right = newNode(key, info, NULL, NULL);
                        t = t->right;
                }
            }
        t->info = info;

        cout << t -> info << "  t -> info" << endl;
        cout << t -> key << "   t -> key" << endl;

        return RootT;
        }
    }
    
    static TreeNode* find(string key , TreeNode* t){
        while (t != nullptr){
            if ( key  <  t->key )
                t = t->left;
            else if ( key  >  t->key )
                t = t->right;
            else // found it!
                cout << "t-key is " << t->key << endl;
                cout << "key is " << key << endl;
                return t;
            // this below is cout.
            
            
        }
        return nullptr;
    }
    static TreeNode* remove(string key , TreeNode* t){
        TreeNode* toRemove = find(key, t); // must do in-line, assn
        if (toRemove -> left  ==  nullptr){
            if ( toRemove -> right  ==  nullptr )
                return NULL;
            else
                return toRemove -> right;
        }else if( toRemove -> right == nullptr ){
            return toRemove->left;
        }else{  // hard case, two children
//          Need to look at and implement!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//           TreeNode* predecessorNode = findPred(key, toRemove);
//         swapKeyAndInfo(predecessorNode, toRemove);
//           toRemove = remove(key, toRemove);
            return toRemove;
        }
    }
    static void print(ostream &out , TreeNode* t){
        if ( t ){
            out << '[';
            print(out, t->left);
            out << '(' << t->key << ',' << t->info << ')';
            print(out, t->right);
            out << ']';
        }else
            out << "nullptr";
    }
    
//    void deleteNode(TreeNode* t) { delete t; }            delete this statement
    static void deleteTree(TreeNode* t);
};

/*
static void deleteNode(TreeNode* t){
    --nodesCreated;
    delete t;
}
*/


static void deleteTree(TreeNode* t){
    if ( t ){
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;            //deleteNode(t); <--- I don't think it is necessary.
    }
}

class BinarySearchTree{
    TreeNode* root;
public:
    void insert(string key, int info);
    int find(string key);
    void remove(string key);
    void print(ostream & out);
};

void BinarySearchTree::insert(string key, int info){
    root = TreeNode::insert(key, info, root);
}
        
int BinarySearchTree::find(string key){
    cout << "1.             find function of BST class" << endl;
    TreeNode* t = TreeNode::find(key, root);
/*
    if ( !t ){
        insert(key, int());
        t = TreeNode::find(key, root);
    }
*/
    cout << "2.             find function of BST class" << endl;
    return t->info;
}

void BinarySearchTree::remove(string key){
    root = TreeNode::remove(key, root);
}


void BinarySearchTree::print(ostream& out){
    TreeNode::print(out, root);
    
}

        
void insertAllWords(BinarySearchTree& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*10; i++){
            
            getline(f,w);
            cout << "w is " << w << endl;
            T.insert(w, 1);               // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void findAllWords(BinarySearchTree& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
        for(int i=0; i < partition*10; i++){
            getline(f, w);
            T.find(w);               // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "findAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}
        
void removeAllWords(BinarySearchTree& T, int partition, string& input_file){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
//        while(getline(f, w)){
        for(int i=0; i < partition*4500; i++){
            T.remove(w);               // test test test test
        }
    }
    
    t.elapsedUserTime(eTime);
    f.close();
    cout << "removeAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}
        
void measureAll(string input_file, BinarySearchTree& T){
    for (int i=1; i<=1; ++i){
        BinarySearchTree T;             //important to start with an empty Tree here
        insertAllWords(T, i, input_file);
        
        
        
        
//        T.print(ostream& out);
        
        
        
        findAllWords(T, i, input_file);
//        removeAllWords(T, i, input_file);
        cout << "test" << endl;
    }
}
        
int main(int argc, char* argv[]){
            
    const char* input_file = argc == 2? argv[1] : "random_5.txt";

    BinarySearchTree D;
    
    measureAll(input_file, D);

    return 0;
}
