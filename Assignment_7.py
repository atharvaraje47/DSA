# Function to merge two sorted sublists of online orders by delivery time
def mergeOrders(leftHalf, rightHalf):
   mergedList = []
   i = 0
   j = 0
   # Compare delivery times (index 2 of each order tuple)
   while i < len(leftHalf) and j < len(rightHalf):
       if leftHalf[i][2] <= rightHalf[j][2]:
           mergedList.append(leftHalf[i])
           i = i + 1
       else:
           mergedList.append(rightHalf[j])
           j = j + 1
   # Copy any remaining orders from the left half
   while i < len(leftHalf):
       mergedList.append(leftHalf[i])
       i = i + 1
   # Copy any remaining orders from the right half
   while j < len(rightHalf):
       mergedList.append(rightHalf[j])
       j = j + 1
   return mergedList
# Recursive Divide and Conquer Merge Sort function
def mergeSortOrders(orders):
   # Base case: a list of 0 or 1 order is already sorted
   if len(orders) <= 1:
       return orders
   # Divide step: find the middle index
   mid = len(orders) // 2
   leftSublist = orders[:mid]
   rightSublist = orders[mid:]
   # Conquer step: recursively sort both halves
   sortedLeft = mergeSortOrders(leftSublist)
   sortedRight = mergeSortOrders(rightSublist)

   # Combine step: merge the sorted halves
   return mergeOrders(sortedLeft, sortedRight)
# Function to display the list of online orders
def displayOrders(orderList):
   for order in orderList:
       orderId = order[0]
       itemName = order[1]
       deliveryTime = order[2]
       print(orderId, "|", itemName, "|", deliveryTime, "mins")
# Function to find the quickest and longest delivery orders
def showSummary(sortedOrders):
   quickest = sortedOrders[0]
   longest = sortedOrders[-1]
   print("\nFirst Priority (Quickest):", quickest[0], "-", quickest[2], "mins")
   print("Last Priority (Longest)  :", longest[0], "-", longest[2], "mins")
# Driver Code
if __name__ == "__main__":
   # Each order is represented as: (Order ID, Item Name, Delivery Time in mins)
   onlineOrders = [
       ("ORD-101", "Groceries", 45),
       ("ORD-102", "Medicines", 15),
       ("ORD-103", "Electronics", 60),
       ("ORD-104", "Hot Food", 25),
       ("ORD-105", "Bakery Item", 20),
       ("ORD-106", "Stationery", 35)
   ]
   print("Online Orders Before Sorting:")
   displayOrders(onlineOrders)
   # Sort orders by estimated delivery time using Merge Sort
   prioritizedOrders = mergeSortOrders(onlineOrders)
   print("\nOnline Orders After Merge Sort (Quickest First):")
   displayOrders(prioritizedOrders)
   showSummary(prioritizedOrders)
