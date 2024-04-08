class Solution {
public:
    
bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int>&stack)
{
    stack[src] = true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i : adj[src]){
            if(!visited[i] && iscycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }
    stack[src]=false;
    return false;
}
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        bool cycle = false;
    vector<int>stack(numCourses,0);
    vector<bool> visited(numCourses, 0);

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && iscycle(i,adj, visited,stack))
        {
            cycle= true;
        }
    }
         if(!cycle){    
            return true;
         }else{
             return false;
         }
    }
};
