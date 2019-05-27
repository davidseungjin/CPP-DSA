#include <iostream>

using namespace std;

int number = 15;

typedef struct node *nodePointer;
typedef struct node{
    int data;
    nodePointer left, right;
} node;

// 전위
void preorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        cout << pointer->data << ' ';
        preorder(pointer->left);
        preorder(pointer->right);
    }
}

// 중위
void inorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        inorder(pointer->left);
        cout << pointer->data << ' ';
        inorder(pointer->right);
    }
}

// 후위
void postorder(nodePointer pointer){
    if(pointer){
        // pointer가 null이 아니라면
        postorder(pointer->left);
        postorder(pointer->right);
        cout << pointer->data << ' ';
    }
}

int main(void){
    node nodes[number+1];
    // 초기화
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


출처: https://hongku.tistory.com/160?category=804730 [IT에 취하개 :: 취미로 하는 개발]
