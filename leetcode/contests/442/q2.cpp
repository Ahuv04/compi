//https://leetcode.com/problems/properties-graph/
//3493. Properties Graph
class Graph {
    int V; 
    list<int>* adj;
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    int connectedComponents();
};

int Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    int ans=0;
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            DFSUtil(v, visited);
            ans+=1;
        }
    }
    delete[] visited;
    return ans;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


class Solution {
public:

bool intersect(set<int> a, set<int> b, int k){
        int ans=0;
        for(int n : a){
            if(b.find(n)!=b.end()) ans+=1;
        }
        return ans>=k;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int ans=0;
        vector<pair<int,int>> edges;

        int m=properties.size();
        Graph g = Graph(m);

        for(int i=0;i<m;i++){
            set<int> s1(properties[i].begin(), properties[i].end());
            for(int j=i+1;j<m;j++){
                set<int> s2(properties[j].begin(), properties[j].end());

                int ans_temp=0;
                for(int n : s1){
                    if(s2.find(n)!=s2.end()) ans_temp+=1;
                }
                if(ans_temp>=k){
                    g.addEdge(i,j);  
                }
            }
        }
        ans=g.connectedComponents();

        return ans;
        
    }
};