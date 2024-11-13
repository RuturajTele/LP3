def knapsack_dp(W, wt, val, n):
    # Create a table to store results of subproblems
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    
    # Fill the table in a bottom-up manner
    for i in range(n + 1):
        for w in range(W + 1):
            # Base case: No items or no capacity
            if i == 0 or w == 0:
                K[i][w] = 0
            # If the current item can be included in the knapsack
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                # If the current item cannot be included
                K[i][w] = K[i - 1][w]
    
    # The maximum value is in the bottom-right cell of the table
    return K[n][W]

# Input handling
print("Enter Number of elements")
n = int(input())
wt = []
val = []
wt = list(map(int, input("Enter Weight: ").split()))
val = list(map(int, input("Enter value: ").split()))

print("Enter Capacity")
W = int(input())

# Output the maximum possible profit
print("Maximum possible profit =", knapsack_dp(W, wt, val, n))


# Enter Number of elements
# 4
# Enter Weight: 10 20 30 40
# Enter value: 60 100 120 150
# Enter Capacity
# 50
