#include "iostream"
#include "fstream"
#include "cstdio"
#include "string.h"
#include "queue"
using namespace std;
#define MAX 10001
int n,m;
int s[MAX][MAX];
int map[MAX];
double num;
void BFS(int i){
    queue<int> q[2];
    int a,b,dist;
    a=0,b=1;
    dist=-1;
    q[a].push(i);
    while (!q[a].empty()){
        swap(a,b);
        dist++;
        while (!q[b].empty()&&dist<=6){
            int k=q[b].front();
            q[b].pop();
            num++;
            if(!map[k]){
                map[k]=1;
                for (int j = 1; j <=n ; ++j) {
                    if(s[k][j]==1&&!map[j])
                        q[a].push(j);
                }

            }

        }


    }

}


int main() {

//    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>n>>m;
    memset(s,0, sizeof(s));
    int x,y;
    for (int i = 0; i <m ; ++i) {
        cin>>x>>y;
        s[x][y]=s[y][x]=1;
    }
    for (int j = 1; j <=n ; ++j) {
        memset(map,0, sizeof(map));
        num=0.0;
        BFS(j);
        printf("%d: %.2f",j,100*num/n);
        cout<<"%"<<endl;
   }

    return  0;


}
