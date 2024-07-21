#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

const int mod=(int)1e9+7;

void fast(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
}
const int maxn=10005;
int n,c,x,y;
vi parent(maxn),ennemy(maxn,-1);

int find(int x){
    while(parent[x]!=x)x=parent[x];
    return x;
}

void join(int x,int y){
    x=find(x);
    y=find(y);
    parent[x]=y;
}
//note every element may have one or 0 ennemy,if he has 2 (group of) ennemies , merge them they are friends
void set_friend(int x,int y){
    if(ennemy[y]!=-1)ennemy[y]=find(ennemy[y]);
    if(ennemy[x]!=-1)ennemy[x]=find(ennemy[x]);

    x=find(x);y=find(y);

    if(ennemy[y]!=-1)ennemy[y]=find(ennemy[y]);
    if(ennemy[x]!=-1)ennemy[x]=find(ennemy[x]);

    if(x==y){
        return;
    }
    if(x==ennemy[y]){
        cout<<-1<<endl;
        return;
    }
    //join the 2 elements an there ennemies if exist
    join(x,y);// y is the big parent
    if(ennemy[x]!=-1 && ennemy[y]!=-1)join(ennemy[x],ennemy[y]);//enemmy of y is the big parent
    else if(ennemy[y]==-1)ennemy[y]=ennemy[x];
    //no need to fix ennemy
}

void set_ennemy(int x,int y){
    if(ennemy[y]!=-1)ennemy[y]=find(ennemy[y]);
    if(ennemy[x]!=-1)ennemy[x]=find(ennemy[x]);

    x=find(x);
    y=find(y);

    if(ennemy[y]!=-1)ennemy[y]=find(ennemy[y]);
    if(ennemy[x]!=-1)ennemy[x]=find(ennemy[x]);

    if(x==y){
        cout<<-1<<endl;
        return;
    }
    if(x==ennemy[y]){
        return;
    }
    //here we have a new ennemy
    //if we join(x,y) the final representent is y
    if(ennemy[y]!=-1) //we merge x and the ennemy
        join(x, ennemy[y]);
    else ennemy[y]=x;

    if(ennemy[x]!=-1)//we merge y and ennemy of x
        join(y,ennemy[x]);
    else ennemy[x]=y;
}

int isfriend(int x,int y){
    return find(x)==find(y);
}

int isennemy(int x,int y){
    return find(x)==ennemy[find(y)];
}

int main(){fast();
    cin>>n;
    for(int i=0;i<n;i++)parent[i]=i;
    while(cin>>c>>x>>y){
        if(c==0)break;
        //for(int i=0;i<n;i++)cout<<parent[i]<<" ";cout<<endl;
        if(c==1)set_friend(x,y);
        else if(c==2)set_ennemy(x,y);
        else if(c==3)cout<<isfriend(x,y)<<endl;
        else if(c==4)cout<<isennemy(x,y)<<endl;
        //cout<<"here is query"<<" "<<c<<" "<<x<<" "<<y<<endl;
        //cout<<"here is parents ";for(int i=0;i<n;i++)cout<<parent[i]<<" ";cout<<endl;
        //cout<<"here is ennemy ";for(int i=0;i<n;i++)cout<<ennemy[i]<<" ";cout<<endl;
    }
    return 0;
}