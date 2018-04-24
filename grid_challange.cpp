#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char st[n][n];
        int flag=0;

        for(int i=0;i<n;i++) {
            for(int j=0; j <n ;j++) {
                cin >> st[i][j];
            }
        }
        for(int i=0;i<n;i++)
            sort(st[i],st[i]+n);

        for(int i=0; i < n; i++) {
            for(int j = 0; j<n-1;j++) {
                if(st[j][i] > st[j+1][i]) {
                    flag=1;
                }

            }
        }

        if(flag == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}


/*
5
ebacd
fghij
olmkn
trpqs
xywuv

5
xywuv
ebacd
fghij
olmkn
trpqs



*/
