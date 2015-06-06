#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;
typedef struct Tree{
    int data;
    int left=-1;
    int right=-1;
};
Tree tree[1001];
void shirft(int id){
    int parent=id/2;
    int child=id;
    if(tree[parent].right!=-1&&tree[tree[parent].right].data<tree[id].data){
        child++;
    }
    if(tree[parent].data>tree[child].data){
        int tmp1;
        tmp1=tree[parent].data;

        tree[parent].data=tree[child].data;

        tree[child].data=tmp1;

        if(parent>1)
            shirft(parent);

    }


}
void findPath(int id){
    int tmp=id;
    while (tmp>0){
        if (tmp==1)
            cout<<tree[tmp].data<<endl;
        else
            cout<<tree[tmp].data<<" ";
        tmp/=2;
    }


}

int main() {
    int n,m;
    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    int t;
    cin>>n>>m;
    for (int i = 1; i <=n ; ++i) {
        cin >> tree[i].data;
    }
    for (int j = 1; 2*j<=n ; ++j) {
        tree[j].left=2*j;
        if(2*j+1<=n)
            tree[j].right=2*j+1;
    }
    for (int k = n; k >1 ;k--) {
        shirft(k);
    }
   for (int l = 0; l <m ; ++l) {
       cin>>t;
       findPath(t);
    }


    return  0;


}
