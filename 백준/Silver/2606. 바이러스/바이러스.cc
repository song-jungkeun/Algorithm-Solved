#include <iostream>
#define MAX 101

using namespace std;

int N, M;
int cnt = 0;
int map[MAX][MAX];
bool visited[MAX];

void DFS(int node){
    visited[node] = true;
    cnt++;

    for(int i = 1; i <= N; ++i){
        if(map[node][i] == true && visited[i] == false){
            DFS(i);
        }
    }

}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(1);
    cout << cnt - 1 << "\n";

    return 0;
}