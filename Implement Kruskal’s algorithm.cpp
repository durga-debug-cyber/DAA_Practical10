def find(parent, vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find(parent, parent[vertex])
    return parent[vertex]


def union(parent, rank, u, v):
    root_u = find(parent, u)
    root_v = find(parent, v)

    if root_u != root_v:
        if rank[root_u] < rank[root_v]:
            parent[root_u] = root_v
        elif rank[root_u] > rank[root_v]:
            parent[root_v] = root_u
        else:
            parent[root_v] = root_u
            rank[root_u] += 1


V = 5

edges = [
    (2, 0, 1),
    (3, 1, 2),
    (6, 0, 3),
    (8, 1, 3),
    (5, 1, 4),
    (7, 2, 4),
    (9, 3, 4)
]

edges.sort()

parent = list(range(V))
rank = [0] * V

mst = []
total_cost = 0

for weight, u, v in edges:

    if find(parent, u) != find(parent, v):
        union(parent, rank, u, v)

        mst.append((u, v, weight))
        total_cost += weight

        if len(mst) == V - 1:
            break

print("Edges in Minimum Spanning Tree:")

for u, v, weight in mst:
    print(u, "-", v, ":", weight)

print("Minimum Cost =", total_cost)
