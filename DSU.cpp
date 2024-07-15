#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank, size;
public:
    DisjointSet(int n){
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds1(7), ds2(7);
    ds1.unionByRank(1, 2);
    ds1.unionByRank(2, 3);
    ds1.unionByRank(4, 5);
    ds1.unionByRank(6, 7);
    ds1.unionByRank(5, 6);

    ds2.unionByRank(1, 2);
    ds2.unionByRank(2, 3);
    ds2.unionByRank(4, 5);
    ds2.unionByRank(6, 7);
    ds2.unionByRank(5, 6);

    cout << "In Union rank before " << endl;
    if (ds1.findUPar(3) == ds1.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    cout << "In Union size before " << endl;
    if (ds2.findUPar(3) == ds2.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    cout << endl;

    ds1.unionByRank(3, 7);
    ds2.unionByRank(3, 7);

    cout << "In Union rank after " << endl;
    if (ds1.findUPar(3) == ds1.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    cout << "In Union size after " << endl;
    if (ds2.findUPar(3) == ds2.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
}
