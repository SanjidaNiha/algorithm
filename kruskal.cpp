#include"bits/stdc++.h"
using namespace std;
const int N= 1e5+6; //big n value
vector<int> parent(N);
vector<int> sz(N);
void make_set(int v){
    parent[v]= v;
    sz[v]=1;//size of v 1 initially
}
//returns parents
int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b)
{
    a= find_set(a);// parent find
    b= find_set(b);
    if(a!=b){
            //need to work with the small one to have less complexity
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b]=a;
        sz[a] += sz[b];
    }
}
int main()
{
    for(int i=0;i<N;i++)
    {
        make_set(i);//makes set for each node serially
    }

    int n,m;
    cin>>n>>m; //n num of vertices, m num of edges
    vector<vector<int>> edges;
    //taking input of u, v, w, v &u adjecent vertices and w weight
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});//pushing vertices into edges vector with weight
    }
    sort(edges.begin(),edges.end());//will be sorted according to weight
    int cost =0;//cost of mst
    //iterate in edges
    for(auto i : edges)
    {
        int w=i[0];
        int u=i[1];
        int v=i[2]; //(7,(1,2)) first w, second first u, second second v
        //cycle detect
        int x= find_set(u);
        int y= find_set(v);
        if(x==y){
            continue; //same set so cycle is created here
            //forces to execute the next iteration of the loop
        }
        else {
                cout<<u<<" "<<v<<"\n";
                cost += w;
                union_set(u,v);//no cycle so union them
        }
    }
    cout<<cost;
}
