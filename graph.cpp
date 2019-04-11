#include "graph.h"

adrVertex createVertex(int nomor){
    adrVertex P;
    P = new elmtVertex;
    numVertex(P) = nomor;
    firstEdge(P) = NULL;
    nextVertex(P) = NULL;
    return P;
}
graph createGraph(){
    graph G;
    adrVertex P;

    //source
    P = createVertex(1);
    firstSource(G) = P;
    P = createVertex(10);
    nextVertex(firstSource(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstSource(G))) = P;

    //destination
    P = createVertex(1);
    firstDest(G) = P;
    P = createVertex(10);
    nextVertex(firstDest(G)) = P;
    P = createVertex(17);
    nextVertex(nextVertex(firstDest(G))) = P;
    P = createVertex(21);
    nextVertex(nextVertex(nextVertex(firstDest(G)))) = P;

    return G;
}
adrEdge createEdge(int asal, int tujuan){
    adrEdge P = new elmtEdge;
    source(P) = asal;
    dest(P) = tujuan;
    sNextEdge(P) = NULL;
    dNextEdge(P) = NULL;
    return P;
}
adrVertex sourceVertex(int numVertex, graph G){
    adrVertex temp = NULL;
    adrVertex p = firstSource(G);
    while ((numVertex(p) != numVertex) && (p != NULL)) {
        p = nextVertex(p);
    }
    if (numVertex(p) == numVertex){
        temp = p;;
    }
    return temp;
}
adrVertex destinationVertex(int numVertex, graph G){
    adrVertex temp = NULL;
    adrVertex p = firstDest(G);
    while ((numVertex(p) != numVertex) && (p != NULL)) {
        p = nextVertex(p);
    }
    if (numVertex(p) == numVertex){
        temp = p;
    }
    return temp;
}

void addEdge (graph &G,adrEdge p){
    adrVertex asal = sourceVertex(source(p),G);
    adrVertex tujuan = destinationVertex(dest(p),G);
    if ((asal != NULL) && (tujuan != NULL)){
        if ((firstEdge(asal) == NULL) && (firstEdge(tujuan) == NULL)){
            firstEdge(tujuan) = p;
            firstEdge(asal) = p;
        } else {
            sNextEdge(p) = firstEdge(asal);
            firstEdge(asal) = p;
            dNextEdge(p) = firstEdge(tujuan);
            firstEdge(tujuan) = p;
        }
    } else {
        cout << "simpul asal atau simpul tujuan tidak ada" <<endl;
    }
}
