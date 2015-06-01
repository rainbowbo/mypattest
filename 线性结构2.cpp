#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;
#define MAX 100000
typedef struct Node {
    int address;
    int data;
    int next;
} List[MAX];
List L;

int main() {
    int n, k;
    int addr, head;
    ifstream cin("/home/song/ClionProjects/mysuanfa/a.txt");
    cin >> addr >> n >> k;
    head = addr;
    for (int i = 0; i < n; ++i) {
        cin >> addr;
        cin >> L[addr].data;
        cin >> L[addr].next;
    }
    Node PtrL;
    PtrL.next = head;
    int p = L[head].next;
    int flag = 0;
    int pp;
    for (int j = 0; j < n / k; ++j) {
        if (!flag) {
            for (int i = 0; i < k - 1; ++i) {
                L[head].next = L[p].next;
                L[p].next = PtrL.next;
                PtrL.next = p;
                p = L[head].next;
            }
            flag = 1;
            //in order to printf the linklist there must be a head node ,it is needed to reverse the list for the first time;
        }
        else {
            pp = head;
            head = p;
            p = L[p].next;
            for (int i = 0; i < k - 1; ++i) {
                L[head].next = L[p].next;
                L[p].next = L[pp].next;
                L[pp].next = p;
                p = L[head].next;
            }

        }
    }

    p = PtrL.next;
    while (p != -1) {
        printf("%05d %d", p, L[p].data);
        p = L[p].next;
        if (p == -1)
            cout << " " << -1 << endl;
        else
            printf(" %05d\n", p);
    }


}
