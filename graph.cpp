#include "graph.h"
#include <queue>
#include <fstream>
using namespace std;

void graph::add_node(float x,float y){
    ns.push_back({(int)ns.size(),x,y});
}

void graph::add_edge(int u,int v){
    if(u!=v) es.push_back({u,v});
}

vector<int> graph::bfs(int s){
    vector<int> ord;
    if(s<0||s>=ns.size()){
        return ord;
    }
    vector<int> vis(ns.size(),0);
    queue<int> q;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int v=q.front(); q.pop();
        ord.push_back(v);
        for(auto &e:es){
            if(e.u==v && !vis[e.v]){
                vis[e.v]=1;
                q.push(e.v);
            }
        }
    }
    return ord;
}

void graph::dfs_go(int v,vector<int>& vis,vector<int>& ord){
    vis[v]=1;
    ord.push_back(v);
    for(auto &e:es){
        if(e.u==v && !vis[e.v]){
            dfs_go(e.v,vis,ord);
        }
    }
}
vector<int> graph::dfs(int s){
    vector<int> ord;
    if(s<0||s>=ns.size()){
        return ord;
    }
    vector<int> vis(ns.size(),0);
    dfs_go(s,vis,ord);
    return ord;
}
const vector<node>& graph::nodes() const{
    return ns;
}
const vector<edge>& graph::edges() const{
    return es;
}
void graph::clear(){
    ns.clear();
    es.clear();
}
void graph::save(const char* f){
    ofstream out(f);
    out<<ns.size()<<"\n";
    for(auto &n:ns){
        out<<n.x<<" "<<n.y<<"\n";
    }
    out<<es.size()<<"\n";
    for(auto &e:es){
        out<<e.u<<" "<<e.v<<"\n";
    }
}
void graph::load(const char* f){
    ifstream in(f);
    if(!in.is_open()){
         return;
    }
    clear();
    int n,m;
    in>>n;
    for(int i=0;i<n;i++){
        float x,y;
        in>>x>>y;
        add_node(x,y);
    }
    in>>m;
    for(int i=0;i<m;i++){
        int u,v;
        in>>u>>v;
        add_edge(u,v);
    }
}
