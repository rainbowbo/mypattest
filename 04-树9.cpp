#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;
typedef struct Tree{
    int data;
};
Tree tree[1001];
int size=0;

void insert(int item){
    int i=size+1;
    for (;i>=2&&tree[i/2].data>item ;i/=2) {
        tree[i].data=tree[i/2].data;
    }
    tree[i].data=item;

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
    int n,m,item;
//    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    int t;
    cin>>n>>m;
    for (int i = 1; i <=n ; ++i) {
        cin>>item;
        insert(item);
        size++;

    }
   for (int l = 0; l <m ; ++l) {
       cin>>t;
       findPath(t);
    }


    return  0;


}
