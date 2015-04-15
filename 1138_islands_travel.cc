#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct Node {
    int x;
    int y;
};

//TLE Bellman-Ford 
int main() {
    int N;
    int *dp;
    Node* store;
    int i,j,k,temp;
    bool flag;

    cin>>N;
    if(N<=1) {
        cout<<"0"<<endl;
        return 0;
    }
    dp = new int[N];
    store = new Node [N];
    for(i=0;i<N;++i)
        cin>>store[i].x>>store[i].y;
    dp[0]=0;
    for(i=1;i<N;++i)
        dp[i]=min(abs(store[i].x - store[0].x),abs(store[i].y-store[0].y));
    
    for(k=0;k<N;++k) {
        flag = false;
        for(i=1;i<N;++i) {
            for(j=1;j<N;++j) {
                if(j==i || dp[j] >= dp[i])
                    continue;
                temp = min(abs(store[j].x-store[i].x),abs(store[j].y-store[i].y)) + dp[j];
                if(temp < dp[i]) {
                    dp[i] = temp;
                    flag =true;
                }
            }
        }
        if(flag == false)
            break;
    }
    cout<<dp[N-1]<<endl;
    return 0;
}

//TLE dijkstra
int main() {
    int N;
    int *dp;
    Node* store;
    int i,j,k,temp,next;
    bool *sign;

    cin>>N;
    if(N<=1) {
        cout<<"0"<<endl;
        return 0;
    }
    dp = new int[N];
    store = new Node [N];
    sign = new bool [N];
    for(i=0;i<N;++i)
        cin>>store[i].x>>store[i].y;
    dp[0]=0;
    for(i=1;i<N;++i)
        dp[i]=min(abs(store[i].x - store[0].x),abs(store[i].y-store[0].y));
    sign[0]=true;
    for(i=1;i<N;++i)
        sign[i]=false;
    for(i=0;i<N;++i) {
        temp = INT_MAX;
        for(j=1;j<N;++j) {
            if(!sign[j] && dp[j] < temp) {
                temp=dp[j];
                next = j;
            }
        }
        if(next == N-1)
            break;
        sign[next]=true;
        for(j=1;j<N;++j) {
            temp = min(abs(store[next].x-store[j].x),abs(store[next].y-store[j].y))+dp[next];
            if(temp < dp[j])
                dp[j]=temp;
        }
    }
    cout<<dp[N-1]<<endl;
    return 0;
}
