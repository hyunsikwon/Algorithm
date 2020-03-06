//
//  main.cpp
//  트리 순회_#1991
//
//  Created by 원현식 on 2020/03/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

char tree[27][2];
char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void preorderTraversal(int current){
    
    cout << alphabet[current];
    if (tree[current][0] != '.') preorderTraversal(tree[current][0] - 'A');
    if (tree[current][1] != '.') preorderTraversal(tree[current][1] - 'A');
    
}

void inorderTraversal(int current){
    
    if (tree[current][0] != '.') inorderTraversal(tree[current][0] - 'A');
    cout << alphabet[current];
    if (tree[current][1] != '.') inorderTraversal(tree[current][1] - 'A');
    
}

void postorderTraversal(int current){
    
    if (tree[current][0] != '.') postorderTraversal(tree[current][0] - 'A');
    if (tree[current][1] != '.') postorderTraversal(tree[current][1] - 'A');
    cout << alphabet[current];
             
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;

        tree[parent - 'A'][0] = leftChild;
        tree[parent - 'A'][1] = rightChild;
    }

    // 전위
    preorderTraversal(0);
    cout << '\n';
    
    // 중위
    inorderTraversal(0);
    cout << '\n';
    
    // 후위
    postorderTraversal(0);
    cout << '\n';
    
}
