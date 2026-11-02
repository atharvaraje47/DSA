# Represent College Campus Graph using Adjacency List and Adjacency Matrix
departments = ["Admin", "IT", "CS", "ENTC", "Library"]
V = len(departments)
# Initialize V x V Adjacency Matrix with 0
adj_matrix = []
for i in range(V):
   adj_matrix.append([0] * V)
# Initialize Adjacency List dictionary
adj_list = {}
for d in departments:
   adj_list[d] = []
# List to store all weighted edges (distance, u, v)
edges = []
# Function to add an undirected weighted link between two departments
def addEdge(u, v, dist):
   adj_matrix[u][v] = dist
   adj_matrix[v][u] = dist
   dept_u = departments[u]
   dept_v = departments[v]
   adj_list[dept_u].append((dept_v, dist))
   adj_list[dept_v].append((dept_u, dist))
   edges.append((dist, u, v))
# Display Adjacency List and Adjacency Matrix
def displayGraph():
   print("College Campus Adjacency List:")
   for d in departments:
       print(d, "->", adj_list[d])
   print("\nCollege Campus Adjacency Matrix:")
   for i in range(V):
       print(departments[i], ":", adj_matrix[i])
# Helper functions for Disjoint Set (Union-Find) in Kruskal's Algorithm
def findParent(parent, i):

   while parent[i] != i:
       i = parent[i]
   return i
def unionSets(parent, u, v):
   root_u = findParent(parent, u)
   root_v = findParent(parent, v)
   parent[root_u] = root_v
# a) Kruskal's Algorithm to find Minimum Spanning Tree
def kruskalMST():
   edges.sort()
   parent = []
   for i in range(V):
       parent.append(i)
   total_distance = 0
   edge_count = 0
   print("\nMinimum Spanning Tree using Kruskal's Algorithm:")
   for dist, u, v in edges:
       root_u = findParent(parent, u)
       root_v = findParent(parent, v)
       if root_u != root_v:
           unionSets(parent, root_u, root_v)
           total_distance += dist
           edge_count += 1
           print(departments[u], "-", departments[v], ":", dist, "m")
           if edge_count == V - 1:
               break
   print("Total Minimum Distance (Kruskal):", total_distance, "m")
# b) Prim's Algorithm to find Minimum Spanning Tree
def primMST():
   visited = [False] * V
   visited[0] = True
   total_distance = 0
   print("\nMinimum Spanning Tree using Prim's Algorithm:")
   for _ in range(V - 1):
       min_dist = 999999

       u_selected = -1
       v_selected = -1
       for i in range(V):
           if visited[i]:
               for j in range(V):
                   if not visited[j] and adj_matrix[i][j] > 0:
                       if adj_matrix[i][j] < min_dist:
                           min_dist = adj_matrix[i][j]
                           u_selected = i
                           v_selected = j
       visited[v_selected] = True
       total_distance += min_dist
       print(departments[u_selected], "-", departments[v_selected], ":", 
min_dist, "m")
   print("Total Minimum Distance (Prim):", total_distance, "m")
# Driver Code: Add distances between campus departments (in meters)
addEdge(0, 1, 10)
addEdge(0, 2, 20)
addEdge(1, 2, 5)
addEdge(1, 3, 15)
addEdge(2, 4, 8)
addEdge(3, 4, 12)
displayGraph()
kruskalMST()
primMST()
