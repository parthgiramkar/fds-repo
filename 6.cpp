def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [x for x in arr[1:] if x <= pivot]
    right = [x for x in arr[1:] if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)


n = int(input("Enter the number of students: "))
percentages = []


for i in range(n):
    percentage = float(input(f"Enter percentage of student {i + 1}: "))
    percentages.append(percentage)


sorted_percentages = quick_sort(percentages)


print("\nSorted percentages:", sorted_percentages)
print("Top 5 scores:", sorted_percentages[-5:][::-1] if len(sorted_percentages) >= 5 else sorted_percentages[::-1])
