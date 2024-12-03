bool customComparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0]; //max heap
}
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MIN));
        priority_queue<vector<int>, vector<vector<int>>, decltype(&customComparator)> pq(customComparator);
        
        if(grid[0][0])  health--;
        if(health==0)   return 0;
        v[0][0]=health;
        pq.push({health,0,0});
        while(!pq.empty()){
            auto top=pq.top();
            cout<<top[0]<<" "<<top[1]<<" "<<top[2]<<endl;
            pq.pop();
            int i=top[1],j=top[2],h=top[0];
            //up
            if(i>0){
                if(grid[i-1][j]){
                    if(v[i-1][j]==INT_MIN){
                        v[i-1][j]=h-1;
                        if(v[i-1][j]>0)
                            pq.push({v[i-1][j],i-1,j});
                    }
                }
                else{
                    if(v[i-1][j]<v[i][j]){
                        v[i-1][j]=v[i][j];
                        pq.push({v[i-1][j],i-1,j});
                    }
                }
            }
            //down
            if(i+1<n){
                if(grid[i+1][j]){
                    if(v[i+1][j]==INT_MIN){
                        v[i+1][j]=h-1;
                        if(v[i+1][j]>0)
                            pq.push({v[i+1][j],i+1,j});
                    }
                }
                else{
                    if(v[i+1][j]<v[i][j]){
                        v[i+1][j]=v[i][j];
                        pq.push({v[i+1][j],i+1,j});
                    }
                }
            }
            //right
            if(j+1<m){
                if(grid[i][j+1]){
                    if(v[i][j+1]==INT_MIN){
                        v[i][j+1]=h-1;
                        if(v[i][j+1]>0)
                            pq.push({v[i][j+1],i,j+1});
                    }
                }
                else{
                    if(v[i][j+1]<v[i][j]){
                        v[i][j+1]=v[i][j];
                        pq.push({v[i][j+1],i,j+1});
                    }
                }
            }
            //left
            if(j>0){
                if(grid[i][j-1]){
                    if(v[i][j-1]==INT_MIN){
                        v[i][j-1]=h-1;
                        if(v[i][j-1]>0)
                            pq.push({v[i][j-1],i,j-1});
                    }
                }
                else{
                    if(v[i][j-1]<v[i][j]){
                        v[i][j-1]=v[i][j];
                        pq.push({v[i][j-1],i,j-1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
        return v[n-1][m-1]>0?true:false;
    }
};