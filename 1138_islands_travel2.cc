#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int NN = 100000+10;

class Node{
    public:
    int val;
    int id;
    void init(int v,int pos){
        val = v;
        id = pos;
    }
    bool operator <(const Node& n2) const {
        return val < n2.val;
    }
};

Node xx[NN],yy[NN];

class Node2 {
    public:
    int dis;
    int id;
    void init(int v,int pos){
        dis = v;
        id = pos;
    }
    bool operator <(const Node2& n2) const {
        return dis>n2.dis;
    }
};

priority_queue<Node2> pq;
int sign[NN];
int rx[NN],ry[NN];

int solve(int N) {
    Node2 tempNode;
    Node2 tNode;
    int px,py,temp_dis;
    tempNode.init(0,0);
    pq.push(tempNode);
    while(!pq.empty()) {
        tNode = pq.top();
        pq.pop();
        sign[tNode.id] = 1;
        if(tNode.id == N-1)
            return tNode.dis;
        px = rx[tNode.id];
        py = ry[tNode.id];
        if(px-1>=0) {
            if(sign[xx[px-1].id]==0) {
                temp_dis = abs(xx[px-1].val - xx[px].val)+tNode.dis;
                tempNode.init(temp_dis, xx[px-1].id);
                pq.push(tempNode);
            }
        }
        if(px+1<N) {
            if(sign[xx[px+1].id]==0) {
                temp_dis = abs(xx[px+1].val - xx[px].val)+tNode.dis;
                tempNode.init(temp_dis, xx[px+1].id);
                pq.push(tempNode);
            }
        }
        if(py-1>=0) {
            if(sign[yy[py-1].id]==0) {
                temp_dis = abs(yy[py-1].val - yy[py].val)+tNode.dis;
                tempNode.init(temp_dis, yy[py-1].id);
                pq.push(tempNode);
            }
        }
        if(py+1<N) {
            if(sign[yy[py+1].id]==0) {
                temp_dis = abs(yy[py+1].val - yy[py].val)+tNode.dis;
                tempNode.init(temp_dis, yy[py+1].id);
                pq.push(tempNode);
            }
        }
    }
}

int main() {
    int T,N;
    int i,j,k;
    int x,y;

    cin>>N;
    for(j=0;j<N;++j) {
        cin>>x>>y;
        xx[j].init(x,j);
        yy[j].init(y,j);
    }
    sort(xx,xx+N);
    sort(yy,yy+N);
    memset(sign,0,NN*sizeof(int));
    for(j=0;j<N;++j) {
        rx[xx[j].id] = j;
        ry[yy[j].id] = j;
    }
    cout<<solve(N)<<endl;
    return 0;
}
