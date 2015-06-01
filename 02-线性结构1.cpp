#include<iostream>
using namespace std;
int main()
{
    int c,e;
    bool cas=true;
    bool test=true;
    while(cin>>c>>e)
    {
        if(e==0&&cas)
        {
            c=0;
            cout<<c<<" "<<e;
            cas=false;
            break;
        }
        cas=false;
        if(e==0&&!cas)
        {
            break;
        }
        if(test){
        cout<<c*e<<" "<<e-1;
        test=false;
        }   
        else   
        cout<<" "<<c*e<<" "<<e-1;
    }
}
