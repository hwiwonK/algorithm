#include <iostream>
#include <string>

using namespace std;

const int N_MAX = 10000;

int s[N_MAX + 10] = {0, };
int answer[N_MAX + 10] = {0, };
int sn = 0;
//char commands[N_MAX + 10][5] = {0, };

int main(){
    int N;
    int ai = 0;
    
//    scanf("%d", &N);
    
    cin >> N;
    
    for (int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        
        if (cmd == "push"){
            int val;
            cin >> val;
            s[sn++] = val;
            
        } else if (cmd == "pop") {
            int tmp;
            tmp = sn > 0 ? s[--sn] : -1;
//            cout << tmp << '\n';
            answer[ai++] = tmp;
            
        } else if (cmd == "size") {
//            cout << sn << '\n';
            answer[ai++] = sn;
            
        } else if (cmd == "empty") {
            int tmp;
            tmp = sn > 0 ? 0 : 1;
//            cout << tmp << '\n';
            answer[ai++] = tmp;
            
        } else if (cmd == "top") {
            int tmp;
            tmp = sn > 0 ? s[sn-1] : -1;
//            cout << tmp << '\n';
            answer[ai++] = tmp;
            
        }
        
    }
    
    for (int i=0; i<ai; i++){
        cout << answer[i] << '\n';
    }
    
    return 0;
    
}




