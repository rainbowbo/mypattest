#include "iostream"
#include "fstream"
#include "string.h"
#include "queue"
using namespace std;
int a[11][11];
int map[11];
int n,m;
void DFS(int i){
    map[i]=1;
    cout<<i<<" ";
    for (int k = 0; k <n ; ++k) {
        if (a[i][k]==1&&!map[k]){
            DFS(k);
        }
    }

}
void BFS(int i){
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        if (!map[k]) {
            cout << k << " ";
            map[k] = 1;
            for (int j = 0; j < n; ++j) {
                if (a[k][j] == 1 && !map[j])
                    q.push(j);
            }
        }
    }

}



int main() {

    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>n>>m;
    memset(a,0, sizeof(a));
    memset(map,0,sizeof(map));
    int i,j;
    for (int k = 0; k <m ; ++k) {
        cin>>i>>j;
        a[i][j]=a[j][i]=1;
    }


    for (int l = 0; l <n ; ++l) {
           if (map[l]==0){
               cout<<"{ ";
               DFS(l);
               cout<<"}"<<endl;
            }
    }

    memset(map,0, sizeof(map));
    for (int i = 0; i < n; ++i) {
        if(map[i]==0){
            cout<<"{ ";
            BFS(i);
            cout<<"}"<<endl;
        }
    }

    return  0;


}
