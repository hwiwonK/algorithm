#include <iostream>
#include <string>

using namespace std;

const int N_MAX = 10000;

int q[N_MAX + 10] = {0, };
int answer[N_MAX + 10] = {0, };
int head = -1;
int tail = -1;

int main(){
    int N;
    int ai = 0;
        
    cin >> N;
    
    for (int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        
        if (cmd == "push"){
            int val;
            cin >> val;
            q[++tail] = val;
            
        } else if (cmd == "pop") {
            int tmp;
            tmp = (tail - head) > 0 ? q[++head] : -1;
            answer[ai++] = tmp;
            
        } else if (cmd == "size") {
            answer[ai++] = tail - head;
            
        } else if (cmd == "empty") {
            int tmp;
            tmp = (tail - head) > 0 ? 0 : 1;
            answer[ai++] = tmp;
            
        } else if (cmd == "front") {
            int tmp;
            tmp = (tail - head) > 0 ? q[head + 1] : -1;
            answer[ai++] = tmp;
            
        } else if (cmd == "back") {
            int tmp;
            tmp = (tail - head) > 0 ? q[tail] : -1;
            answer[ai++] = tmp;
        }
        
    }
    
    for (int i=0; i<ai; i++){
        cout << answer[i] << '\n';
    }
    
    return 0;
    
}




