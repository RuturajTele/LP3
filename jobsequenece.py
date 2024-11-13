class Node:
    def __init__(self, freq_, symbol_, left_=None, right_=None):
        self.freq = freq_
        self.symbol = symbol_
        self.left = left_
        self.right = right_
        self.huff = ""

# Function to print Huffman codes recursively
def print_nodes(node, val=""):
    new_val = val + str(node.huff)
    if node.left:
        print_nodes(node.left, new_val)
    if node.right:
        print_nodes(node.right, new_val)
    if not node.left and not node.right:  # Leaf node
        print(f"{node.symbol} -> {new_val}")

# Input characters and frequencies
chars = ["a", "b", "c", "d", "e", "f"]
freq = [10, 4, 9, 7, 1, 15]

# Create a list of nodes (each representing a symbol and frequency)
nodes = [Node(freq[x], chars[x]) for x in range(len(chars))]

# Build the Huffman tree
while len(nodes) > 1:
    # Sort nodes based on frequency
    nodes = sorted(nodes, key=lambda x: x.freq)
    
    # Take two nodes with the smallest frequency
    left = nodes[0]
    right = nodes[1]
    
    # Assign Huffman values
    left.huff = '0'
    right.huff = '1'
    
    # Create a new internal node with combined frequency
    newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
    
    # Remove the two nodes from the list and add the new node
    nodes = nodes[2:]  # Remove the first two nodes
    nodes.append(newNode)  # Add the new node

# Print the characters and their frequencies
print("Characters:", f'[{", ".join(chars)}]')
print("Frequency:", freq, "\n\nHuffman Encoding:")
# Print the Huffman codes
print_nodes(nodes[0])
