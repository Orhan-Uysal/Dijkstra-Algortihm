
#include<bits/stdc++.h>
#define EPS                         1e-9
#define r(s,a) for(int i=0;i<s;i++) cin>>a[i];
#define p(s,a) for(int i=0;i<s;i++) cout<<a[i]<<" ";
#define X first
#define Y second
#define one_C  __builtin_popcount
#define INF 1000000001
#define N 10000000//1b
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;
typedef pair<int,int> ip;

int n,tree[N],a[N];

void build(int v,int l,int r){
    if(l==r)
        tree[v] = a[l];
    else{
        int m= (l+r)/2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}
int sum1(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(l==tl && r==tr)
        return tree[v];
    int tm= (tl+tr)/2;
    return sum1(v*2,tl,tm,l,min(r,tm)) + sum1(v*2+1,tm+1,tr,max(tm+1,l),r);
}
int sum2(int a,int b){
    a+=n,b+=n;
    int s =0;
    while(a<=b){
        if(a%2 ==1) s+=tree[a++];
        if(b%2 ==0 ) s+=tree[b--];
        a/=2,b/=2;
    }
    return s;
}
int add(int k,int x){
    k+=n;
    tree[k]+=x;
    for(k/=2;k>=1;k/=2){
        tree[k]=tree[k*2]+tree[k*2+1];
    }
}

int main(){
    cin >> n;
    r(n,a)
    build(1,0,n-1);
    p(n*4,tree)
    cout << endl;
    cout << sum1(1,0,n-1,1,4)<<endl;
    //cout << sum2(1,4)<<endl;
    add(4,10);
    p(n*4,tree)
    cout << sum1(1,0,n-1,1,4)<<endl;
}
