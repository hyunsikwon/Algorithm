//
//  main.cpp
//  효율적인 화폐 구성_cpp
//
//  Created by 원현식 on 2020/09/24.
//

#include <iostream>

using namespace std;

int d[10001] = {0,};

int dp(int n) {
    
    if (d[n] != -1) {
        return d[n];
    }
    
    
    
    return 0;
}
 
int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    int arr[10001];
    fill_n(arr, M+1, -1);
    
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[a] = 1;
    }
    
    for (int i = 2; i <= M; i++) {
        if (arr[i] == 1) {continue;}
        
        for (int j = 1; j <= i/2; j++) {
            if (arr[j] != -1 && arr[i-j] != -1) {
                if (arr[i] == -1) {
                    arr[i] = arr[j] + arr[i-j];
                    continue;
                }
                
                if (arr[j] + arr[i-j] < arr[i]) {
                    arr[i] = arr[j] + arr[i-j];
                }
                
            }
            
        }

    }
    
    for (int i = 1; i <= M; i++) {
        cout << arr[i] << ' ';
    }
    
    
    cout << arr[M];

}
