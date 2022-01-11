#include <iostream>

using namespace std;

const int N_MAX = 150;

char tree[N_MAX][2] = {0, };

void preorder(int cur, int idx){
    
    cout << (char)cur;
    if (tree[cur][0] != 0) preorder(tree[cur][0], idx);
    if (tree[cur][1] != 0) preorder(tree[cur][1], idx);
    
}

void inorder(int cur, int idx){
    
    if (tree[cur][0] != 0) inorder(tree[cur][0], idx);
    cout << (char)cur;
    if (tree[cur][1] != 0) inorder(tree[cur][1], idx);
    
}

void postorder(int cur, int idx){
    
    if (tree[cur][0] != 0) postorder(tree[cur][0], idx);
    if (tree[cur][1] != 0) postorder(tree[cur][1], idx);
    cout << (char)cur;
    
}


int main(){
    int N = 0;
    int idx = 0;
    
    cin >> N;
    
    for (int i=0; i<N; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        if (left != '.') tree[parent][0] = left;
        if (right != '.') tree[parent][1] = right;
    }
    
    //전위 순회
    preorder(0 + 'A', idx);
    cout << '\n';
    inorder(0 + 'A', idx);
    cout << '\n';
    postorder(0 + 'A', idx);
    cout << '\n';
    
}
