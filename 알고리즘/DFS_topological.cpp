#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph { 
    int V;
    list<int>* adj; 
    void DFS(int v, bool visited[], stack<int>& Stack); 
  
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
    void topologicalSort(); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
void Graph::DFS(int v, bool visited[], stack<int>& Stack) 
{  
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFS(*i, visited, Stack); 
  
    Stack.push(v); 
} 
  
 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
    bool* visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;  
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFS(i, visited, Stack); 
  
    while (Stack.empty() == false) { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 


int main(){
    Graph g(4); //vertex 개수
    g.addEdge(0,2);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(2,1);

    cout << "Topological Sort of the give graph ";
    g.topologicalSort();
    return 0;
}