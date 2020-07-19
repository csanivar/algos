class Solution {
    
    HashSet<Integer> visited = new HashSet<>();
    HashSet<Integer> visiting = new HashSet<>();
    HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
    Stack<Integer> res = new Stack<>();
    
    public boolean dfs(int src) {
        if(visiting.contains(src)) {
            return false;
        }
        visiting.add(src);
        for(int i: graph.get(src)) {
            if(!visited.contains(i)) {
                if(!dfs(i)) return false;
            }
        }
        visited.add(src);
        res.push(src);
        return true;
    }
    
    public int[] findOrder(int numCourses, int[][] edges) {
        for(int i=0; i<numCourses; i++) {
            graph.put(i, new ArrayList());
        }
        for(int i=0; i<edges.length; i++) {
            ArrayList<Integer> l = graph.get(edges[i][0]);
            l.add(edges[i][1]);
            graph.put(edges[i][0], l);
        }
        for(int src: graph.keySet()) {
            if(!visited.contains(src)) {
                visiting.clear();
                if(!dfs(src)) {
                    return new int[0];
                }
            }
        }
        int[] ans = new int[numCourses];
        int i = numCourses-1;
        while(!res.empty()) {
            ans[i--] = res.pop();
        }
        return ans;
    }
}
