#include "iostream"
#include "fstream"
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}List;
List L,*PtrL;

int main(){
    int n,k;
    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin>>PtrL>>n>>k;
    for (int i = 0; i <n ; ++i) {

    }

}