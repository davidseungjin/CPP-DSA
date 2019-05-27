#include <iostream>

using namespace std;

int number = 15;

typedef struct node *nodePointer;
typedef struct node{
    int data;
    nodePointer left, right;
} node;

void preorder(nodePointer pointer){
    if(pointer){
        cout << pointer->data << ' ';
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

void inorder(nodePointer pointer){
    if(pointer){
        inorder(pointer->left);
        cout << pointer->data << ' ';
        inorder(pointer->right);
    }
}

void postorder(nodePointer pointer){
    if(pointer){
        postorder(pointer->left);
        postorder(pointer->right);
        cout << pointer->data << ' ';
    }
}

int main(void){
    node nodes[number+1];
    for(int i=1; i<= number; i++){
        nodes[i].data = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    
    for(int i=2; i<=number; i++){
        if(i%2==0){
            nodes[i/2].left = &nodes[i];
        }else{
            nodes[i/2].right = &nodes[i];
        }
    }
    
    preorder(&nodes[1]);
    cout << endl;
    inorder(&nodes[1]);
    cout << endl;
    postorder(&nodes[1]);
    cout << endl;
    
    return 0;
}
