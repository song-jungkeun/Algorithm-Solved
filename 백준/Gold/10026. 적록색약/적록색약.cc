/*문제 : https://www.acmicpc.net/problem/10026
  알고리즘 : DFS
  날자 : 26/03/03
*/

#include <iostream>
#include <string>

using namespace std;

int n;
string map[101];
int visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) 
            continue;
		if (visited[nx][ny] == 0 && map[nx][ny] == map[x][y]) { 
			visited[nx][ny] = 1;
			dfs(nx, ny); 
		}
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                cnt++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt << " ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 'G')
                map[i][j] = 'R';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }

    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == 0){
                cnt++;
                visited[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt;

    return 0;
}