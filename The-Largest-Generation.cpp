#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;
#define MAXN 100
typedef struct Tree{
     int parent=-1;
     int level=1;
};
Tree tree[MAXN];
int main() {

    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    int n,m;
    cin>>n>>m;
    int parent,k,child;
    for (int i = 0; i <m ; ++i) {
        cin>>parent>>k;
        for (int j = 0; j <k ; ++j) {
            cin>>child;
            tree[child].parent=parent;
        }
    }
    int maxlevel=1;
    for (int i = 0; i <n ; ++i) {
        int level=1;
        int p=tree[i].parent;
        while (p>0){
            level++;
            p=tree[p].parent;
        }
        if(level>maxlevel)
            maxlevel=level;
        tree[i].level=level;
    }
    int maxnum=0,h;
    for (int i = 1; i <=maxlevel ; ++i) {
        int num=0;
        for (int j = 0; j <n ; ++j) {
            if(tree[j].level==i)
                num++;
        }
        if(num>maxnum){
            maxnum=num;
            h=i;
        }
    }
    cout<<maxnum<<" "<<h<<endl;
    return  0;
}
