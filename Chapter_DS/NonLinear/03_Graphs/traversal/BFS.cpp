


#include <iostream>
using namespace std;
#include <list>
#include <queue>

#include <vector>


/*

17th Sep 2025 (Wednesday - Happy Vishkararama Puja) LecNo: 110 by ShardhaDi

traversal in tree always start from node, but in Graph kahi se kar sakte hai
In Graph mark the VisitedNode is very very imp for BFS, DFS because there is many cycle where as in Graph, but in tree no req because waha Hierichial stru. hota hai parents-child relation


BFS: traval to immediate neighbour node first
Queue datastru we will use for BFS as similar to Binary tree main karte the


*/



class Graph {
    int v;   // number of vertices
    list<int> *l;  //int *arr     adjacency list

public:
    Graph(int v) {
        this->v = v;
        l = new list<int> [v];

        //arr = new int[v]
    }

    void addEdge(int u, int v) {   //TC=O(v+E)
        l[u].push_back(v);
        l[v].push_back(u);   // undirected graph ke liye
    }

    //BFS Traversal
    void bfs() {  //TC=O(V+E)
        queue<int> Q;
        vector<bool> visitedNode(v, false);

        Q.push(0);
        visitedNode[0] = true;

        while(Q.size() > 0) {
            int u = Q.front();   //u-v    yaha u=source, v=destinatoin
            Q.pop();

            cout << u << " ";

            // Explore all neighbors of u
            for(int v : l[u]) {         //v -> immediate neigh
                if(!visitedNode[v]) {
                    visitedNode[v] = true;
                    Q.push(v);

                } 
            }
        }

        cout << endl;
    }


    
    

};






int main() {

    Graph g(5);

    g.addEdge(0, 1);   
    g.addEdge(1, 2);   
    g.addEdge(1, 3);   
    g.addEdge(2, 3);   
    g.addEdge(2, 4);   

    cout << "BFS Traversal: ";
    g.bfs();


    return 0;
}


 //TC=O(v+E) = SC