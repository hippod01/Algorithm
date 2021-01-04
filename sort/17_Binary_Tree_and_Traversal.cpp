// 이진 트리에서 데이터를 탐색하는 크게 세 가지 방법

// ① 전위 순회(Preorder Traversal)
//   하나의 노드에 방문했을 때 다음의 순서를 따릅니다.

//   (1) 먼저 자기 자신을 처리합니다.
//   (2) 왼쪽 자식을 방문합니다.
//   (3) 오른쪽 자식을 방문합니다.

// ② 중위 순회(Inorder Traversal)
//   하나의 노드에 방문했을 때 다음의 순서를 따릅니다.

//   (1) 왼쪽 자식을 방문합니다.
//   (2) 먼저 자기 자신을 처리합니다.
//   (3) 오른쪽 자식을 방문합니다.

// ③ 후위 순회(Postorder Traversal)
//   (1) 왼쪽 자식을 방문합니다.
//   (2) 오른쪽 자식을 방문합니다.
//   (3) 먼저 자기 자신을 처리합니다.

#include <iostream>

using namespace std;

int number = 15;

//하나의 노드 정보를 선언합니다.(구조체)
typedef struct node *treePointer;
typedef struct node{
    int data;
    treePointer leftChild, rightChild;
} node;

//전위 순회 구현
void preorder(treePointer ptr){
    if(ptr){
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// 중위 순회 구현
void inorder(treePointer ptr){
    if(ptr){
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

// 후위 순회 구현
void postorder(treePointer ptr){
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void){
    node nodes[number+1];

    for(int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
    
    for(int i=1; i<=number; i++){
        if(i%2 == 0)
            nodes[i/2].leftChild = &nodes[i];
        else
            nodes[i/2].rightChild = &nodes[i];

    }
    preorder(&nodes[1]);
    cout <<  endl;
    inorder(&nodes[1]);
    cout <<  endl;
    postorder(&nodes[1]);
}