class ItemValue:
    def __init__(self, wt_, val_, ind_):
        self.wt = wt_
        self.val = val_
        self.ind = ind_
        self.cost = val_ / wt_  # Calculate cost per weight unit

    def __lt__(self, other):
        # This ensures sorting in descending order based on cost per weight
        return self.cost > other.cost

def fractionalKnapSack(wt, val, capacity):
    # Create a list of ItemValue objects
    iVal = [ItemValue(wt[i], val[i], i) for i in range(len(wt))]
    
    # Sort the items in decreasing order based on their cost/weight ratio
    iVal.sort()

    totalValue = 0  # To store the total value of items in the knapsack
    
    # Process each item
    for i in iVal:
        curWt = i.wt
        curVal = i.val

        # If the item can be fully accommodated in the remaining capacity
        if capacity - curWt >= 0:
            capacity -= curWt
            totalValue += curVal
        else:
            # If the item cannot be fully accommodated, take the fraction of it
            fraction = capacity / curWt
            totalValue += curVal * fraction
            capacity = 0  # Knapsack is full now
            break

    return totalValue

if __name__ == "__main__":
    # Example input
    wt = [10, 60, 20, 40]
    val = [50, 40, 100, 150]
    capacity = 50
    
    # Call the fractional knapsack function
    maxValue = fractionalKnapSack(wt, val, capacity)
    
    # Output the maximum value in the knapsack
    print("Maximum value in Knapsack =", maxValue)
