# Manhattan Distance Heuristic function h(n) = |r1 - r2| + |c1 - c2|
def manhattanHeuristic(cellA, cellB):
   rowDiff = abs(cellA[0] - cellB[0])
   colDiff = abs(cellA[1] - cellB[1])
   return rowDiff + colDiff
# Check if a grid cell (r, c) is inside the maze and not a wall
def isValidCell(maze, r, c):
   rows = len(maze)
   cols = len(maze[0])
   if r >= 0 and r < rows and c >= 0 and c < cols:
       if maze[r][c] == 0:
           return True
   return False
# A* (A-Star) Search Algorithm to find the optimal path from start to goal
def aStarMazeSearch(maze, start, goal):
   # Each entry in openList: [f_score, g_score, current_cell, path_list]
   initialH = manhattanHeuristic(start, goal)
   openList = [[initialH, 0, start, [start]]]
   visited = []
   # 4-directional movement: Up, Down, Left, Right
   directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
   while len(openList) > 0:
       # Sort openList so node with minimum f(n) = g(n) + h(n) is at index 0
       openList.sort()
       currentRecord = openList.pop(0)
       f = currentRecord[0]
       g = currentRecord[1]
       curr = currentRecord[2]
       path = currentRecord[3]
       # Goal test
       if curr == goal:
           return path
       if curr in visited:

           continue
       visited.append(curr)
       # Explore valid neighbors
       for dr, dc in directions:
           nextRow = curr[0] + dr
           nextCol = curr[1] + dc
           neighbor = (nextRow, nextCol)
           if isValidCell(maze, nextRow, nextCol) and neighbor not in visited:
               newG = g + 1
               newH = manhattanHeuristic(neighbor, goal)
               newF = newG + newH
               openList.append([newF, newG, neighbor, path + [neighbor]])
   return None
# Function to visualize the maze and the agent's optimal path
def displayMaze(maze, path, start, goal):
   rows = len(maze)
   cols = len(maze[0])
   for r in range(rows):
       rowStr = ""
       for c in range(cols):
           cell = (r, c)
           if cell == start:
               rowStr += "S "
           elif cell == goal:
               rowStr += "G "
           elif maze[r][c] == 1:
               rowStr += "# "
           elif path is not None and cell in path:
               rowStr += "* "
           else:
               rowStr += ". "
       print(rowStr)
# Driver Code for Static and Dynamic Maze Navigation
if __name__ == "__main__":
   # 0 = Free Corridor, 1 = Wall / Obstacle
   maze = [
       [0, 0, 0, 1, 0],

       [0, 1, 0, 1, 0],
       [0, 1, 0, 0, 0],
       [0, 0, 1, 1, 0],
       [1, 0, 0, 0, 0]
   ]
   startPos = (0, 0)
   goalPos = (4, 4)
   print("1. Static Maze Navigation (S=Start, G=Goal, *=Path, #=Wall):")
   staticPath = aStarMazeSearch(maze, startPos, goalPos)
   displayMaze(maze, staticPath, startPos, goalPos)
   print("Optimal Path:", staticPath)
   print("Total Steps :", len(staticPath) - 1)
   print("\n2. Dynamic Maze Navigation (Dynamic Obstacle added at (2, 4)):")
   maze[2][4] = 1
   dynamicPath = aStarMazeSearch(maze, startPos, goalPos)
   displayMaze(maze, dynamicPath, startPos, goalPos)
   print("Replanned Path:", dynamicPath)
   print("Total Steps   :", len(dynamicPath) - 1)
