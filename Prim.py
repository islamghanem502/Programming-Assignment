import heapq

def prim_mst(graph, V):
    key = [float('inf')] * V  
    in_mst = [False] * V  
    parent = [-1] * V  

    pq = []
    heapq.heappush(pq, (0, 0))  
    key[0] = 0

    while pq:
        weight, u = heapq.heappop(pq)  

        if in_mst[u]:
            continue

        in_mst[u] = True  

        for weight, v in graph[u]:
            if not in_mst[v] and weight < key[v]:
                key[v] = weight
                heapq.heappush(pq, (key[v], v))
                parent[v] = u  

    print("Edges in MST:")
    for i in range(1, V):
        print(f"{parent[i]} - {i} with weight {key[i]}")

def main():
    V, E = map(int, input("Enter number of vertices and edges: ").split())

    graph = [[] for _ in range(V)]
    print("Enter the edges (u, v, weight):")
    for _ in range(E):
        u, v, weight = map(int, input().split())
        graph[u].append((weight, v))
        graph[v].append((weight, u))  

    prim_mst(graph, V)

if __name__ == "__main__":
    main()
