#include <iostream>
#include <cstdlib>

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
    TreeNode* newNode(string k, int e, TreeNode* l, TreeNode* r){
        return new TreeNode(k, e, l, r);
    }
    TreeNode* insert(string key, int info, TreeNode* RootT){
        if (RootT != NULL)
            RootT = newNode(key, 1, nullptr, nullptr);
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
        return RootT;
    }
    TreeNode* find(string key , TreeNode* t){
        while (t != nullptr){
            if ( key  <  t->key )
                t = t->left;
            else if ( key  >  t->key )
                t = t->right;
            else // found it!
                return t;
        }
        return nullptr;
    }
    TreeNode* remove(string key , TreeNode* t){
        TreeNode* toRemove = find(key, t); // must do in-line, assn
        if (toRemove -> left  ==  nullptr){
            if ( toRemove -> right  ==  nullptr )
                return NULL;
            else
                return toRemove -> right;
        }else if( toRemove -> right == nullptr ){
            return toRemove->left;
        }else{  // hard case, two children
            TreeNode* predecessorNode = findPred(key, toRemove);
            swapKeyAndInfo(predecessorNode, toRemove);
            toRemove = remove(key, toRemove);
            return toRemove;
        }
    }
    void print(ostream & out , TreeNode * t);
    void deleteNode(TreeNode* t) { delete t; }
    void deleteTree(TreeNode* t);
};

//
//TreeNode::TreeNode* newNode(string k, int e,TreeNode * l, TreeNode * r)
//{
//    ++nodesCreated;
//    return new TreeNode(k, e, l, r);
//}
//
//TreeNode::insert(string key, int info, TreeNode *RootT ){
//    if (RootT != NULL)
//        RootT = newNode(key, info, nullptr, nullptr);
//    TreeNode* t = RootT;
//    while (t->key !=  key){
//        if (key < t->key){
//            if (t->left != NULL)
//                t->left = newNode(key, info, NULL, NULL);
//            t = t->left;
//        }else if(key > t->key){
//            if (t->right != NULL)
//                t->right = newNode(key, info, NULL, NULL);
//            t = t->right;
//        }
//    }
//    t->info = info;
//    return RootT;
//}

//TreeNode::find(string key, TreeNode* t){
//    while (t != nullptr){
//        if ( key  <  t->key )
//            t = t->left;
//        else if ( key  >  t->key )
//            t = t->right;
//        else // found it!
//            return t;
//    }
//    return nullptr;
//}
//
//TreeNode::remove( string key, TreeNode* t )
//{
//    TreeNode* toRemove = find(key, t); // must do in-line, assn
//    if (toRemove -> left  ==  nullptr){
//        if ( toRemove -> right  ==  nullptr )
//            return NULL;
//        else
//            return toRemove -> right;
//    }else if( toRemove -> right == nullptr ){
//            return toRemove->left;
//    }else{  // hard case, two children
//        TreeNode * predecessorNode = findPred(key, toRemove);
//        swapKeyAndInfo(predecessorNode, toRemove);
//        toRemove = remove(key, toRemove);
//        return toRemove;
//    }
//}

void TreeNode::print(ostream & out, TreeNode* t)
{
    if ( t ){
        out << '[';
                 print(out, t->left);
                 out << '(' << t->key << ',' << t->info << ')';
                 print(out, t->right);
                 out << ']';
    }else
        out << "nullptr";
}

static void deleteNode(TreeNode* t){
    --nodesCreated;
    delete t;
}
        

static void deleteTree(TreeNode* t){
    if ( t ){
        deleteTree(t->left);
        deleteTree(t->right);
        deleteNode(t);
    }
}

class BinarySearchTree{
    TreeNode * root;
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
    TreeNode* t = TreeNode::find(key, root);
    if ( !t ){
        insert(key, int());
        t = TreeNode::find(key, root);
    }
    return t->info;
}

void BinarySearchTree::remove(string key){
    root = TreeNode::remove(key, root);
}
        
void BinarySearchTree::print(ostream& out){
    TreeNode::print(out, root);
}

        
void insertAllWords(BinarySearchTree& T, int partition, char *fileName){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
//        while(getline(f, w)){
        for(int i=0; partition*4500; i++){
            L.insert(w, 1);               // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}

void findAllWords(BinarySearchTree & T, int partition, char *fileName){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
//        while(getline(f, w)){
        for(int i=0; partition*4500; i++){
            L.find(w);               // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}
        
void removeAllWords(BinarySearchTree & T, int partition, char *fileName){
    Timer t;
    double eTime;
    ifstream f(input_file.c_str());
    t.start();
    string w;
    if(f.is_open()){
//        while(getline(f, w)){
        for(int i=0; partition*4500; i++){
            L.remove(w);               // test test test test
        }
    }
    t.elapsedUserTime(eTime);
    f.close();
    cout << "insertAllWords time of\t" << "partition\t" << partition << " is " << eTime << endl;
}
        
void measureAll(char *fileName, BinarySearchTree& T){
    for (int i=1; i<=10; ++i){
//       BinarySearchTree T; important to start with an empty Tree here
        insertAllWords(T, i, fileName);
        findAllWords(T, i, fileName);
        removeAllWords(T, i, fileName);
    }
}
        
int main(int argc, char* argv[]){
            
    const char* input_file = argc == 2? argv[1] : "random_5.txt";

    TreeNode D;
    
    measureAll(input_file, D);

    return 0;
}
