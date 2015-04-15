#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

bool isTrue(map<char,int> &store, int x, int y, int z) {
    int xx=abs(store['R']-store['Y']);
    int yy=abs(store['R']-store['B']);
    int zz=abs(store['Y']-store['B']);
    if(xx==x) {
        if(yy==y && zz==z)
            return true;
        else if(yy==z && zz==y)
            return true;
    }
    else if(xx==y) {
        if(yy==x && zz==z) 
            return true;
        else if(yy==z && zz==x)
            return true;
    }
    else if(xx==z) {
        if(yy==x && zz==y)
            return true;
        else if(yy==y && zz==x)
            return true;
    }
    return false;
}

int main() {
    int x,y,z,len;
    string s;
    int maxnum=0,temp;
    map<char,int> store;
    int i;

    cin>>x>>y>>z;
    cin>>s;
    len=s.size();
    store['R']=0;
    store['Y']=0;
    store['B']=0;
    temp=0;
    for(i=0;i<len;++i) {
        store[s[i]]++;
        temp++;
        if(isTrue(store,x,y,z)) {
            if(temp > maxnum)
                maxnum = temp;
            store['R']=0;
            store['Y']=0;
            store['B']=0;
            temp=0;
        }
    }
    if(temp > maxnum)
        maxnum=temp;
    cout<<maxnum<<endl;
    return 0;
}
