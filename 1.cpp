marklist = []
n = int(input("Enter number of Students - "))
print()
for i in range(n):
  marks = int(input(f'Enter marks of student {i+1} - '))
  marklist.append(marks)
print()
print(f"The marklist of students is - {marklist}")
sum = 0
for marks in marklist:
 sum += marks
print(f"The sum of marks is = {sum}")
print(f"The average marks of students is = {sum/n}")
highest = -1
lowest = 999
for marks in marklist:
 if marks > highest:
     highest = marks
 if marks < lowest:
     lowest = marks

print(f'The highest score of class is - {highest}')
print(f'The lowest score of class is - {lowest}')
freq = {}
for marks in marklist:
 if marks in freq:
    freq[marks] += 1
 else:
    freq[marks] = 1

print(f'The frequency of marks is - {freq}')
