#include<bits/stdc++.h>
#define EPS                         1e-9
#define f(s,a) for(int i=0;i<s;i++) cin>>a[i];
#define p(s,a) for(int i=0;i<s;i++) cout<<a[i]<<" ";
#define X first
#define Y second
#define one_C  __builtin_popcount
#define INF 10000000000000001

using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;

vector<llp>mp[100005];
priority_queue <llp> q;
ll n,m,dis[100005],p[100005];
bool vis[100005];

void deg(ll k){
    if(p[k]!=-1)
        deg(p[k]);
    cout << k <<" ";
}

void dijk(ll x){
    for(ll i=1;i<=n;i++){
        dis[i]=INF;
        p[i]=-1;
    }
    dis[x]=0;
    q.push({0,x});
    while(!q.empty()){
        ll s=q.top().Y;
        q.pop();
        for(auto v:mp[s]){
            ll b=v.X,w=v.Y;
            if(dis[s]+w<dis[b]){
                p[b]=s;
                dis[b]=dis[s]+w;
                q.push({-dis[b],b});//priority queue finds maximum elements, while we want to find minimum elements.
            }

        }
    }

}
int main(){
    ll a,b,w;
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a >> b >> w;
        mp[a].push_back({b,w});
        mp[b].push_back({a,w});

    }
    dijk(1);
    if(dis[n]==INF){
        cout << "-1";
        return 0;
    }
    deg(p[n]);
    cout << n;
}
