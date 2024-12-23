class Set:
    # Constructor to initialize the set
    def __init__(self, n):
        self.s = []
        for i in range(n):
            e = int(input(f"Enter Element {i + 1}: "))
            if e not in self.s:
                self.s.append(e)

    # Method to add an element to the set
    def add(self, e):
        if e not in self.s:
            self.s.append(e)

    # Method to delete an element from the set
    def delete(self, e):
        if e in self.s:
            self.s.remove(e)

    # Method to compute the intersection with another set
    def intersect(self, s2):
        res = []
        for i in self.s:
            if i in s2.s:
                res.append(i)
        return res

    # Method to compute the union with another set
    def union(self, s2):
        res = self.s.copy()
        for i in s2.s:
            if i not in self.s:
                res.append(i)
        return res

    # Method to compute the difference with another set
    def diff(self, s2):
        res = []
        for i in self.s:
            if i not in s2.s:
                res.append(i)
        return res

    # Method to compute all subsets of the set
    def subset(self):
        res = []
        res.append("phi")  # Empty set
        n = 2 ** len(self.s)
        for i in range(n):
            subset = []
            for j in range(len(self.s)):
                if i & (1 << j):  # Check if j-th bit is set
                    subset.append(self.s[j])
            res.append(subset)
        return res

# Example Usage:
# Create two sets
n1 = int(input("Enter the number of elements for Set 1: "))
set1 = Set(n1)

n2 = int(input("Enter the number of elements for Set 2: "))
set2 = Set(n2)

# Display operations
print("\nSet 1:", set1.s)
print("Set 2:", set2.s)

print("\nUnion:", set1.union(set2))
print("Intersection:", set1.intersect(set2))
print("Difference (Set1 - Set2):", set1.diff(set2))
print("Subsets of Set 1:", set1.subset())
