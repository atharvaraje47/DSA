# Function to calculate Profit-to-Weight ratio for each parcel
def calculateRatios(parcels):
   parcelData = []
   for p in parcels:
       parcelId = p[0]
       weight = p[1]
       profit = p[2]
       ratio = profit / weight
       parcelData.append([ratio, weight, profit, parcelId])
   return parcelData
# Function to sort parcels in descending order of Profit/Weight ratio
def sortByRatioDescending(parcelData):
   n = len(parcelData)
   for i in range(n - 1):
       for j in range(n - i - 1):
           if parcelData[j][0] < parcelData[j + 1][0]:
               temp = parcelData[j]
               parcelData[j] = parcelData[j + 1]
               parcelData[j + 1] = temp
# Function to display available parcels and their P/W ratios
def displayParcels(parcelData):
   print("Parcels Sorted by Profit/Weight Ratio:")
   for item in parcelData:
       ratio, weight, profit, pid = item
       print(pid, "| Weight:", weight, "kg | Profit:", profit, "| Ratio:", round(ratio, 2))
# Greedy Fractional Knapsack function to maximize shipping profit
def fractionalKnapsack(parcels, truckCapacity):
   parcelData = calculateRatios(parcels)
   sortByRatioDescending(parcelData)
   displayParcels(parcelData)
   remainingCapacity = truckCapacity
   totalProfit = 0.0
   print("\nTruck Loading Steps (Max Capacity =", truckCapacity, "kg):")
   for item in parcelData:
       ratio = item[0]
       weight = item[1]

       profit = item[2]
       pid = item[3]
       if remainingCapacity == 0:
           break
       # If the complete parcel fits into the truck
       if weight <= remainingCapacity:
           remainingCapacity = remainingCapacity - weight
           totalProfit = totalProfit + profit
           print(pid, "-> Loaded Full (100%) | Weight:", weight, "kg | Profit:", profit)
       else:
           # Load fractional part of the parcel to fill remaining capacity
           fraction = remainingCapacity / weight
           partialProfit = profit * fraction
           totalProfit = totalProfit + partialProfit
           percent = round(fraction * 100, 1)
           print(pid, "-> Loaded Partial (", percent, "%) | Weight:", 
remainingCapacity, "kg | Profit:", partialProfit)
           remainingCapacity = 0
   print("\nTotal Weight Loaded:", truckCapacity - remainingCapacity, "kg")
   print("Maximum Profit Achieved:", totalProfit)
# Driver Code
if __name__ == "__main__":
   # Each parcel: (Parcel ID, Weight in kg, Profit)
   shippingParcels = [
       ("Parcel-1", 10, 60),
       ("Parcel-2", 20, 100),
       ("Parcel-3", 30, 120),
       ("Parcel-4", 15, 90)
   ]
   maxTruckCapacity = 50
   fractionalKnapsack(shippingParcels, maxTruckCapacity)
