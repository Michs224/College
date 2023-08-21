#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k, b;
    cin >> n >> k >> b;
    long long cost[n+1], parent[n+1];

    for(long long i = 1; i <= n; i++)
        parent[i] = i;

    for(long long i = 1; i <= n; i++)
        cin >> cost[i];

    for(long long i = 1; i <= k; i++){
        long long x, y;
        cin >> x >> y;
        if(cost[x] > cost[y]){
            long long parentUpdate = y;
            long long costUpdate = cost[y];
            long long parentBefore = parent[x];
            for(long long j = 1; j <= n; j++){
                if(parent[j] == parentBefore){
                    parent[j] = parentUpdate;
                    cost[j] = costUpdate;
                }
            }
        }else{
            long long parentUpdate = x;
            long long costUpdate = cost[x];
            long long parentBefore = parent[y];
            for(long long j = 1; j <= n; j++){
                if(parent[j] == parentBefore){
                    parent[j] = parentUpdate;
                    cost[j] = costUpdate;
                }
            }
        }
    }
    
    for(long long i = 1; i <= b; i++){
        long long unionCost[n+1];
        memset(unionCost, 0, sizeof(unionCost));
        long long minimumCost = INT_MAX, minimumCostParent = 0;
        for(long long j = 1; j <= n; j++){
            unionCost[parent[j]] += cost[j];
            if(cost[j] < minimumCost){
                minimumCost = cost[j];
                minimumCostParent = parent[j];
            }
        }

        long long maxCostUnionParent = 0;
        long long maxCostUnion = 0;
        for(long long j = 1; j <= n; j++){
            if(unionCost[j] > maxCostUnion){
                maxCostUnion = unionCost[j];
                maxCostUnionParent = parent[j];
            }
        }
        
        for(long long j = 1; j <= n; j++){
            if(parent[j] == maxCostUnionParent){
                cost[j] = minimumCost;
                parent[j] = minimumCostParent;
            }
        }
    }

    long long res = 0;
    for(long long i = 1; i <= n; i++)
        res += cost[i];

    cout << res << endl;

return 0;
}