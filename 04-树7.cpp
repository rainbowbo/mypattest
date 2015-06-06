#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;
typedef struct Tree{
    int data=-1;
    int left=-1;
    int right=-1;
};
int size;
Tree tree[101];
void insert(int data,int i){
      if(tree[i].data==-1) {
          tree[i].data = data;
          return;
      } else{
          if(data<tree[i].data) {
              if(tree[i].left==-1)
                  tree[i].left=size;
              insert(data,tree[i].left);
            //  cout<<"left";
          } else if(data>tree[i].data){
              if(tree[i].right==-1)
                  tree[i].right=size;
              insert(data,tree[i].right);
          //    cout<<"right";
          }
      }

}

int main() {
    int n,m;
    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>n>>m;
    int item;
    while (n--) {
            size = 0;
            for (int i = 0; i < m; ++i) {
                cin >> item;
                tree[i].data=tree[i].left=tree[i].right=-1;
                insert(item, 0);
                size++;
            }
        int ok=1;
        for (int j = 0; j <m ; ++j) {
            if(tree[j].left!=-1&&tree[j].right!=-1)
                ok=0;
        }
        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        }





    return  0;


}
