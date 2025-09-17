

#include <iostream>
// #include <vector>
using namespace std;
#include <list>


/*


10th Sep 2025 (Wednesday - ISRO ICRB 2025 exam postponed which was held on 14th Sep Sunday Lucknow)


kisi bhi graph ko banane ke liye Edges and Vertices ki info ko store karna hota hai  -- ek popular method: ADJANCENCY LIST

List: is diff from vector or LinkdList 
we can imagine doubly LL where front and back; we can apply pop_front, push_back and push_front, push_pop, size()
Har vertex ke liye ek list of neighbors maintain karte hain.



*/




class Graph {
    int V;   // number of vertices
    list<int> *l;  //int *arr     adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];

        //arr = new int[V]
    }

    void addEdge(int u, int v) {   //TC=O(V+E)
        l[u].push_back(v);
        l[v].push_back(u);   // undirected graph ke liye
    }


    void printAdjList() {   //TC=O(V+E)
        for(int i=0; i<V; i++) {
            cout << i << " : ";
            for(int neigh : l[i]) {
                cout << neigh << " ";
            }
            
            cout << endl;
        }
    }

};






int main() {

    Graph g(5);

    g.addEdge(0, 1);   
    g.addEdge(1, 2);   
    g.addEdge(1, 3);   
    g.addEdge(2, 3);   
    g.addEdge(2, 4);   


    g.printAdjList();


    return 0;
}


 //TC=O(V+E) = SC

 