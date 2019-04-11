#include "graph.h"
int main()
{
    graph G;
    G = createGraph();
    //Hasil Output setelah createGraph() seharusnya:
    //Simpul asal: 1, 10, 17,
    //Simpul tujuan: 1, 10, 17, 21,

    //-- your code --
    adrVertex p,q;
    p = firstSource(G);
    cout << "simpul asal: ";
    while (p != NULL){
        cout << numVertex(p) << ",";
        p = nextVertex(p);
    }
    cout<<endl;
    cout << "simpul tujuan: ";
    q = firstDest(G);
    while (q != NULL){
        cout << numVertex(q) << ",";
        q = nextVertex(q);
    }
    cout<<endl;
    cout<<endl;
    int asal,tujuan;
    int i = 1;
    adrEdge t;
    while (i <= 6){
        cout << " -- Masukkan edge -- " << endl;
        cout << "\tasal  : ";
        cin >> asal;
        cout << "\ttujuan: ";
        cin >> tujuan;
        t = createEdge(asal,tujuan);
        addEdge(G,t);
        i++;
    }
    cout<<endl;
    cout<< "Graph G:" <<endl;
    adrVertex l = firstSource(G);
    while (l != NULL){
        adrEdge e = firstEdge(l);
        while (e != NULL){
            cout << source(e) << " ke " << dest(e) ;
            cout << endl;
            e = sNextEdge(e);
        }
        l = nextVertex(l);
    }
    //-- your code --

    return 0;
}
