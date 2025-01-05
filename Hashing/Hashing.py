# Initialize the hash table with empty buckets
HT = [[] for _ in range(10)]
print("Blank Hash Table: ", HT)

# Function to insert a key-value pair
def insert(HT, key, value):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i, kv in enumerate(bucket):
        k, v = kv
        if key == k:
            exist = True
            break
    if exist:
        bucket[i] = (key, value)
    else:
        bucket.append((key, value))

# Function to delete a key-value pair
def delete(HT, key):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i, kv in enumerate(bucket):
        k, v = kv
        if key == k:
            exist = True
            break
    if exist:
        del bucket[i]
    else:
        print("Element not found to delete.")

# Function to search for a key
def search(HT, key):
    loc = key % 10
    bucket = HT[loc]
    exist = False
    for i, kv in enumerate(bucket):
        k, v = kv
        if key == k:
            exist = True
            break
    if exist:
        print("Element found: ", v)
    else:
        print("Element not found.")

# Function to display the hash table
def display(HT):
    for i, bucket in enumerate(HT):
        print("Bucket", i, "Elements:", bucket)

# Main program
while True:
    print("\n1. Insert")
    print("2. Delete")
    print("3. Search key")
    print("4. Print Hash Table")
    print("0. Exit")
    ch = int(input("Enter choice: "))
    if ch == 1:
        key = int(input("Enter key: "))
        value = input("Enter value: ")
        insert(HT, key, value)
    elif ch == 2:
        key = int(input("Enter the key: "))
        delete(HT, key)
    elif ch == 3:
        key = int(input("Enter the key: "))
        search(HT, key)
    elif ch == 4:
        display(HT)
    elif ch == 0:
        break
    else:
        print("Wrong choice.")
