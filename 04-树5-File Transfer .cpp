#include "iostream"
#include "fstream"
using namespace std;
typedef struct Tree{
    int parent;
    int id;
};
Tree tree[10001];
int findroot(int id){
    int i;
    i=id;
    while (tree[i].parent>0){
        i=tree[i].parent;
    }
    return i;
}

int main() {
    int n,n1,n2;
    int root1,root2;
    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>n;
    char c;
    for (int i = 1; i <=n ; ++i) {
        tree[i].id=i;
        tree[i].parent=-1;
    }
    while (cin>>c&&c!='S'){
        if(c=='I'){
            cin>>n1>>n2;
            root1=findroot(n1);
            root2=findroot(n2);
            if(tree[root1].parent>=tree[root2].parent){
                    tree[root1].parent=root2;
                    tree[root2].parent-=1;
                } else{
                    tree[root2].parent=root1;
                    tree[root1].parent-=1;
                }

        }
        else if(c=='C'){
            cin>>n1>>n2;
            root1=findroot(n1);
            root2=findroot(n2);
            if(root1!=root2){
               cout<<"no"<<endl;
            } else{
               cout<<"yes"<<endl;
            }
        }
    }
    int k=0;
    for (int j = 1; j <=n ; ++j) {
        if(tree[j].parent<0)
            k++;
    }
    if(k==1)
        cout<<"The network is connected."<<endl;
    else
        cout<<"There are "<<k<<" components."<<endl;



}
