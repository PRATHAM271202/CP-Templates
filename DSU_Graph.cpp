    class DisjointSet{
        
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            //n+1 because work with both 0based and 1 based indexing
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findUParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUParent(parent[node]);
        }
        
        void unionByRank(int u,int v){
            int ult_u=findUParent(u);
            int ult_v=findUParent(v);
            
            if(ult_u==ult_v) return;
            if(rank[ult_u] < rank[ult_v]){
                parent[ult_u]=ult_v;
            }
            else if(rank[ult_v] < rank[ult_u]){
                parent[ult_v]=ult_u;
            }
            else {
                parent[ult_v]=ult_u;
                rank[ult_u]++;
            }
        }
        
        void unionBySize(int u,int v){
            int ult_u=findUParent(u);
            int ult_v=findUParent(v);
            if(ult_u==ult_v) return;
            if(size[ult_u]< size[ult_v]){
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            else {
                  parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
            
        }
        
    };