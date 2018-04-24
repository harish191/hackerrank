#include<iostream>
using namespace std;
int main()
{
    int t,n;
    cin >> t;
    while(t--) {
        cin>> n;
        int cnt=0;
        while(n%3!=0) {
            n=n-5;
            cnt++;
        }
        if(n < 0)
            cout<<"-1"<<endl;

        else {
                while(n!=0) {
                    n=n-3;
                    cout<<"555";
                }

                for(int i=0;i<cnt;i++)
                    cout<<"33333";

        cout<<endl;
        }

    }
    return 0;
}
