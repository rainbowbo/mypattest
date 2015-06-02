#include "iostream"
#include "fstream"
#include"stack"

using namespace std;
typedef struct Tree{
   int left=-1;
    int right=-1;
};
Tree tree[30];
int root,id,index;
bool isfirst= true;
void travse(int id){
    if (tree[id].left!=-1)
        travse(tree[id].left);
    if(tree[id].right!=-1)
        travse(tree[id].right);
    if(isfirst){
        cout<<id;
        isfirst= false;
    } else
        cout<<" "<<id;
}

int main(){
    int n;
    //ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>n;
    stack<int> s;
    char p[4];
    cin>>p>>id;
    root=id;
    s.push(root);
    bool ispush=true;
    for (int i = 0; i <2*n-1 ; ++i) {
        cin>>p;
        if(p[1]=='u'){
            cin>>id;
            if(ispush){
                tree[s.top()].left=id;
            } else{
                tree[index].right=id;
                ispush= true;
            }
            s.push(id);
        } else{
            ispush= false;
            index=s.top();
            s.pop();
        }
    }
     travse(root);
    cout<<endl;
    return 0;
}
