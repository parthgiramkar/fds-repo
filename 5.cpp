def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j]


n = int(input("Enter the number of students: "))
percentages = []


for i in range(n):
    percentage = float(input(f"Enter percentage of student {i + 1}: "))
    percentages.append(percentage)


print("\nChoose sorting method:")
print("1. Selection Sort")
print("2. Bubble Sort")
choice = int(input("Enter your choice (1 or 2): "))

if choice == 1:
    selection_sort(percentages)
    print("Sorted percentages using Selection Sort:", percentages)
elif choice == 2:
    bubble_sort(percentages)
    print("Sorted percentages using Bubble Sort:", percentages)
else:
    print("Invalid choice!")

print("Top 5 scores:", percentages[-5:][::-1] if len(percentages) >= 5 else percentages[::-1])
