class Solution:
    # def dfs(self, i, adj, component, num):
    #     if component[i]:
    #         return
    #     component[i] = num
    #     for child in adj[i]:
    #         self.dfs(child, adj, component, num)

    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)] 
        for edge in edges:
            adj[edge[0]].append(edge[1])  
            adj[edge[1]].append(edge[0])

        def dfs(i, adj):
            if component[i]:
                return
            component[i] = num
            for child in adj[i]:
                dfs(child, adj)

        component = [0] * n
        num = 1

        for i in range(n):
            if component[i] == 0:
                dfs(i, adj)
                num += 1

        andValue = [(1 << 17) - 1] * num
        for edge in edges:
            u = edge[0]
            andValue[component[u]] = andValue[component[u]] & edge[2]

        ans = []

        for q in query:
            ans.append(
                andValue[component[q[0]]] if component[q[0]] == component[q[1]] else -1
            )
        return ans
