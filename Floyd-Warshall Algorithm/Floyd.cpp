#include<bits/stdc++.h>
#define EPS                         1e-9
#define f(s,a) for(int i=0;i<s;i++) cin>>a[i];
#define p(s,a) for(int i=0;i<s;i++) cout<<a[i]<<" ";
#define X first
#define Y second
#define one_C  __builtin_popcount
#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<ll,ll> llp;

const int MOD=1e9+7;

ll edges[401][401],x[1001],y[1001];
priority_queue <llp> q;
ll dis[10001][10001],n;
bool vis[10][10001];
ll m,tek;

void spfa(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j]=0;
            else if(edges[i][j]) dis[i][j]=edges[i][j];
            else
                dis[i][j]=INF;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

}

int main() {
    int a,b,c,s;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            cin >> a >>b>>c;
            edges[a][b]=c;
        }
        spfa(s);
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> x[i] >>y[i];
        }
        for(int i=1;i<=n;i++){
            if(dis[x[i]][y[i]]==INF) cout << "-1"<<endl;
            else cout << dis[x[i]][y[i]]<<endl;
        }
        cout << endl;
}
