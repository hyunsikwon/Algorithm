//
//  main.cpp
//  단체사진 찍기_cpp
//
//  Created by 원현식 on 2020/11/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int answer;
map<int, char> dic;
bool visited[8];

void check(vector<int> arr, vector<string> data) {
    for (string d: data) {
        char friend1 = d[0];
        char friend2 = d[2];
        char condition = d[3];
        int n = d[4] - '0';
        
        int friend1Loc = 0;
        int friend2Loc = 0;
        for (int i = 0; i < 8; i++) {
            if (dic[arr[i]] == friend1) {
                friend1Loc = i;
            } else if (dic[arr[i]] == friend2) {
                friend2Loc = i;
            }
        }
        
        if (condition == '=') {
            if (abs(friend1Loc-friend2Loc) != n+1) {
                return;
            }
        } else if(condition == '<') { // A~B<3 A와 B 간격은 2이하이다. a c c b
            if (abs(friend1Loc-friend2Loc) > n) {
                return;
            }
            
        } else if (condition == '>') { // A~B>3 A와 B 간격은 4이상 이다. a c c c c b
            if (abs(friend1Loc-friend2Loc) < n+2) {
                return;
            }
        }
    }
    answer++;
}

void dfs(int depth, int N, vector<int> arr, vector<string> data) {
    if (depth == N-1) {
        check(arr, data);
        return;
    }
        
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        arr.push_back(i);
        dfs(depth+1, N, arr, data);
        arr.pop_back();
        visited[i] = false;
    }
}

int solution(int n, vector<string> data) {
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    answer = 0;

    dic[0] = 'A';
    dic[1] = 'C';
    dic[2] = 'F';
    dic[3] = 'J';
    dic[4] = 'M';
    dic[5] = 'N';
    dic[6] = 'R';
    dic[7] = 'T';
    
    for (int i = 0; i < 8; i++) {
        visited[i] = false;
    }
    
    vector<int> arr;
    dfs(-1, 8, arr, data);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};
//    vector<string> data = {"M~C<2", "C~M>1"}; // result 0

    cout << solution(n, data) << '\n';
    cout << 3648 << '\n';
    
    
//    dic[0] = 'A';
//    dic[1] = 'C';
//    dic[2] = 'F';
//    dic[3] = 'J';
//    dic[4] = 'M';
//    dic[5] = 'N';
//    dic[6] = 'R';
//    dic[7] = 'T';
//    int n = 1;
//    vector<string> data = {"A~C>3"};
//    vector<int> arr = {0,3,2,4,5,1,6,7};
//
//    if (check(arr, data)) {
//        printf("TRUE");
//    } else printf("FALSE");
    
}

/*
 1. 1 <= n <= 100, 조건의 개수 n.
 
 2. data의 원소는 다섯 글자로 구성된 문자열이다. 각 원소의 조건은 다음과 같다.
 
 3. 첫 번째 글자와 세 번째 글자는 다음 8개 중 하나이다. {A, C, F, J, M, N, R, T} 각각 어피치, 콘, 프로도, 제이지, 무지, 네오, 라이언, 튜브를 의미한다. 첫 번째 글자는 조건을 제시한 프렌즈, 세 번째 글자는 상대방이다. 첫 번째 글자와 세 번째 글자는 항상 다르다.
 
 4. 두 번째 글자는 항상 ~이다.
 
 5. 네 번째 글자는 다음 3개 중 하나이다. {=, <, >} 각각 같음, 미만, 초과를 의미한다.
 
 6. 다섯 번째 글자는 0 이상 6 이하의 정수의 문자형이며, 조건에 제시되는 간격을 의미한다. 이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수이다.
 */
