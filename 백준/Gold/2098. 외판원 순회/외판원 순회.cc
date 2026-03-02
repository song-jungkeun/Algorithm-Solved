/*문제 : https://www.acmicpc.net/problem/2098
  알고리즘 : DP, bitmasking
  티어 : Gold1
  날자 : 26/03/02
*/

#include <iostream>
#include <cstring>

using namespace std;

#define INF 987654321;

int n, map[16][16];
int dp[16][1<<16]; // dp[현재위치][방문집합]


int dfs(int cur, int visit){
    
    if (visit == (1<<n)-1){ //탐색 완료
        if(map[cur][0] == 0) //이동불가능
            return INF;
        return map[cur][0];
    }
    
    if (dp[cur][visit] != -1) //이미 탐색했으면
        return dp[cur][visit];
    
    dp[cur][visit] = INF;
    
    for (int i=0; i<n; i++){
        if (map[cur][i]==0) 
            continue;
        if ((visit & (1<<i)) == (1<<i)) 
            continue;
        dp[cur][visit] = min(dp[cur][visit], map[cur][i] + dfs(i, visit | 1<<i));
    }
    
    return dp[cur][visit];
}

int main() {
    
    cin>>n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp)); //dp배열 -1로 초기화
    cout<<dfs(0,1);
    
    return 0;
}