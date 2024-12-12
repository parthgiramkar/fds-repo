def Ternary_Search(arr, left, right, x):
    if right >= left:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3
        
        # Check if the element is at mid1 or mid2
        if arr[mid1] == x:
            return True
        if arr[mid2] == x:
            return True
        
        # Search in the left third
        if x < arr[mid1]:
            return Ternary_Search(arr, left, mid1 - 1, x)
        # Search in the right third
        elif x > arr[mid2]:
            return Ternary_Search(arr, mid2 + 1, right, x)
        # Search in the middle third
        else:
            return Ternary_Search(arr, mid1 + 1, mid2 - 1, x)
    return False

# Input number of members
n = int(input("Enter number of club members: "))

# Input roll numbers of the members
members = []
for i in range(n):
    roll_number = int(input(f"Enter roll number of member {i+1}: "))
    members.append(roll_number)

# Sort members' roll numbers in ascending order
members.sort()

print("\nSorted Roll Numbers:", members)

# Input the roll number to search for
roll_to_search = int(input("Enter roll number to search for: "))

# Perform Ternary Search
if Ternary_Search(members, 0, len(members) - 1, roll_to_search):
    print(f"Roll number {roll_to_search} is a member of the club.")
else:
    print(f"Roll number {roll_to_search} is not a member of the club.")
