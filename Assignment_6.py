# Function to maintain the Max-Heap property for subtree rooted at index i
def maxHeapify(arr, n, i):
   largest = i
   left = 2 * i + 1
   right = 2 * i + 2
   # Check if left child exists and is greater than current largest
   if left < n and arr[left] > arr[largest]:
       largest = left
   # Check if right child exists and is greater than current largest
   if right < n and arr[right] > arr[largest]:
       largest = right
   # If largest is not the root, swap and recursively heapify affected subtree
   if largest != i:
       temp = arr[i]
       arr[i] = arr[largest]
       arr[largest] = temp
       maxHeapify(arr, n, largest)
# Function to build a Max-Heap from an unsorted array
def buildMaxHeap(arr, n):
   # Start from the last non-leaf node and move up to the root
   lastNonLeaf = (n // 2) - 1
   for i in range(lastNonLeaf, -1, -1):
       maxHeapify(arr, n, i)
# Function to display array elements
def displayArray(label, arr):
   print(label, arr)
# Function to sort an array in ascending order using Heap Sort
def heapSort(arr):
   n = len(arr)
   # Step 1: Build Max-Heap from input array
   buildMaxHeap(arr, n)
   displayArray("Constructed Max-Heap:", arr)

   # Step 2: Extract maximum element from root one by one
   print("\nStep-by-Step Extraction Passes:")
   step = 1
   for i in range(n - 1, 0, -1):
       # Swap current root (maximum) with the end of the unsorted heap
       temp = arr[0]
       arr[0] = arr[i]
       arr[i] = temp
       # Restore Max-Heap property on the reduced heap of size i
       maxHeapify(arr, i, 0)
       print("Pass", step, "->", arr)
       step += 1
# Function to verify if array is sorted in ascending order
def isSortedAscending(arr):
   for i in range(len(arr) - 1):
       if arr[i] > arr[i + 1]:
           return False
   return True
# Driver Code
if __name__ == "__main__":
   numbers = [45, 12, 85, 32, 89, 39, 69, 44]
   displayArray("Original Unsorted Array:", numbers)
   print("Number of Elements:", len(numbers))
   print()
   heapSort(numbers)
   print()
   displayArray("Final Sorted Array (Ascending):", numbers)
   if isSortedAscending(numbers):
       print("Verification: Array is sorted in ascending order.")
