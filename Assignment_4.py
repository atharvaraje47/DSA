# Node class for Binary Search Tree
class Node:
   def __init__(self, key):
       self.key = key
       self.left = None
       self.right = None
# a) Insert a new key and handle duplicate entries
def insert(root, key):
   if root is None:
       return Node(key)
   if key == root.key:
       print("Duplicate entry ignored:", key)
   elif key < root.key:
       root.left = insert(root.left, key)
   else:
       root.right = insert(root.right, key)
   return root
# Helper function to find minimum key node in a subtree
def findMin(node):
   curr = node
   while curr.left is not None:
       curr = curr.left
   return curr
# b) Delete a key from the Binary Search Tree
def deleteNode(root, key):
   if root is None:
       return None
   if key < root.key:
       root.left = deleteNode(root.left, key)
   elif key > root.key:
       root.right = deleteNode(root.right, key)
   else:
       # Case 1 & 2: Node with only one child or no child
       if root.left is None:
           return root.right
       elif root.right is None:

           return root.left
       # Case 3: Node with two children
       temp = findMin(root.right)
       root.key = temp.key
       root.right = deleteNode(root.right, temp.key)
   return root
# c) Search for a key in the BST
def search(root, key):
   if root is None or root.key == key:
       return root
   if key < root.key:
       return search(root.left, key)
   else:
       return search(root.right, key)
# d) Display tree (Inorder Traversal)
def inorder(root):
   if root is not None:
       inorder(root.left)
       print(root.key, end=" ")
       inorder(root.right)
# e) Display Depth of the tree
def depth(root):
   if root is None:
       return 0
   return 1 + max(depth(root.left), depth(root.right))
# f) Convert tree into its Mirror Image
def mirror(root):
   if root is not None:
       root.left, root.right = mirror(root.right), mirror(root.left)
   return root
# g) Create an exact copy of the tree
def copyTree(root):
   if root is None:
       return None
   newNode = Node(root.key)
   newNode.left = copyTree(root.left)

   newNode.right = copyTree(root.right)
   return newNode
# h) Display all parent nodes with their child nodes
def displayParents(root):
   if root is not None and (root.left or root.right):
       l = root.left.key if root.left else None
       r = root.right.key if root.right else None
       print("Parent:", root.key, "-> Left:", l, "Right:", r)
       displayParents(root.left)
       displayParents(root.right)
# i) Display all leaf nodes
def displayLeaves(root):
   if root is not None:
       if root.left is None and root.right is None:
           print(root.key, end=" ")
       displayLeaves(root.left)
       displayLeaves(root.right)
# j) Display tree level-wise using a queue list
def levelOrder(root):
   queue = [root]
   while len(queue) > 0:
       curr = queue.pop(0)
       print(curr.key, end=" ")
       if curr.left: queue.append(curr.left)
       if curr.right: queue.append(curr.right)
# Driver Code
root = None
for k in [50, 30, 70, 20, 40, 60, 80, 30]:
   root = insert(root, k)
print("Inorder Traversal:", end=" "); inorder(root); print()
print("Search 40:", "Found" if search(root, 40) else "Not Found")
print("Depth of Tree:", depth(root))
displayParents(root)
print("Leaf Nodes:", end=" "); displayLeaves(root); print()
print("Level Wise Display:", end=" "); levelOrder(root); print()
copied = mirror(copyTree(root))
print("Mirror Inorder:", end=" "); inorder(copied); print()
root = deleteNode(root, 30)
print("Inorder After Deleting 30:", end=" "); inorder(root); print()
