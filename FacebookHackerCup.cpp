#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
typedef long long ll;
const int INF =10000;
const int N = 27;

bool vis[N];
//vector<int> graph[N];
int dist[N];

void augmentedBFS(int src,vector<int>graph[N])
{
    queue<int> q;
    //hh
    q.push(src);
    vis[src]=true;
    dist[src]=0;
    while (!q.empty())
    {
        int parent =q.front();
        q.pop();
        for (auto child : graph[parent])
        {
            if (!vis[child])
            {
                vis[child]=true;
                q.push(child);
                dist[child]=1+dist[parent];
            }
        }
    }
}
void distCharsInString(string s,vector<int> &caracters)
{
    sort(s.begin(),s.end());
    char aux;
    for (auto i:s)
    {
        if (i!=aux)
        {
            caracters.pb(i-'A');
            aux=i;
        }
    }
}




int main() {


    freopen("WorkingTests.txt", "r", stdin);
    int t;
    string s;

    int k;
    cin >> t;
    int T=t;
    while(t--)
    {
        string nodes = "";
        vector<int>graph[N];
        memset (vis,false,sizeof(vis));
        //memset (dist,INF,sizeof(dist));
        for (int i=0;i<N;i++)
        {
            dist[i] = INF;
        }
        cin>> s;
        cin>>k;
        for (int i=0;i<k;i++)
        {
            char Ai;
            char Bi;
            cin>>Ai>>Bi;
            graph[(int)Ai - 65].pb((int) Bi -65 );
            nodes = nodes + (Ai) ;
            nodes = nodes + (Bi) ;
        }
        nodes = nodes + s;
        vector<int> caracters;
        distCharsInString(nodes,caracters);
        int res=INF;
        for (int i=0;i<caracters.size();i++)
        {
            int ith=caracters[i];
            int cost = 0 ;
            //cout << "im in i";
            for (int j=0;j<caracters.size();j++)
            {

                if (i!=j)
                {
                    //cout << "im in j";
                    int jth = caracters[j];
                    augmentedBFS(jth,graph);
                    cost += dist[ith]*count(s.begin(),s.end(),(char)(jth+65));
                    //cout << " ith element "<< ith << " jth element  "<<jth << "    cost   "<< cost << endl;
                    //cout <<"dist de :"<<jth<<" à "<< ith<<" est : "<<  dist[ith]<<endl;
                    memset (vis,false,sizeof(vis));
                    //memset (dist,INF,sizeof(dist));
                    for (int i=0;i<N;i++)
                    {
                        dist[i] = INF;
                    }
                }

            }
            res = min(res,cost);

        }

        if (res >= INF)
            cout << "Case #"<< T-t <<":  "<< -1<<endl;
        else
            cout << "Case #"<< T-t <<":  "<< res <<endl;






    }






}




