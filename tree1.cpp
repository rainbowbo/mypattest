#include "iostream"
#include "fstream"
#include "queue"
using  namespace std;
typedef struct Tree{
    int index;
    int left;
    int right;
};
Tree tree[10];
int cnt;
int travse(int id) {
    //  cout << "id=" << id << " " << "left=" << tree[id].left << " " << "right=" << tree[id].right << " ";
    if (id == -1)
        return 0;
    return 1+travse(tree[id].left)+travse(tree[id].right);

}


int main(){
   // ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    int n;
    cin>>n;
    char left,right;
    for (int i = 0; i <n ; ++i) {
        tree[i].index=i;
        cin>>left>>right;
        if(left=='-')
            tree[i].left=-1;
        else
            tree[i].left=left-'0';

        if (right=='-')
            tree[i].right=-1;
        else
            tree[i].right=right-'0';
    }
    int root;

    for (int j = 0; j <n ; ++j) {
        cnt=travse(j);
        if (cnt==n){
            root=j;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    while (!q.empty()){
        cnt=q.front();
        q.pop();
        if(tree[cnt].left!=-1)
            q.push(tree[cnt].left);
        if(tree[cnt].right!=-1)
            q.push(tree[cnt].right);
        if (tree[cnt].left==-1&&tree[cnt].right==-1){
            if(q.empty())
                cout<<cnt<<endl;
            else
                cout<<cnt<<" ";
        }

    }
    return 0;
}
