# ADDITION OF MATRIX
row = int(input("Enter the number of rows: "))
col = int(input("Enter the number of columns: "))
m1 = [[0 for i in range(col)] for i in range(row)]
m2 = [[0 for i in range(col)] for i in range(row)]
ans = [[0 for i in range(col)] for i in range(row)]

for n in range(2):
    print(f"Enter data for matrix {n+1} : ")
    for i in range(row):
        for j in range(col):
            if n == 0:
                m1[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))
            else:
                m2[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))

for i in range(row):
    for j in range(col):
        ans[i][j] = m1[i][j] + m2[i][j]

print("Addition of matrices:", ans)

# SUBTRACTION OF MATRIX
row = int(input("Enter the number of rows: "))
col = int(input("Enter the number of columns: "))
m1 = [[0 for i in range(col)] for i in range(row)]
m2 = [[0 for i in range(col)] for i in range(row)]
ans = [[0 for i in range(col)] for i in range(row)]

for n in range(2):
    print(f"Enter data for matrix {n+1} : ")
    for i in range(row):
        for j in range(col):
            if n == 0:
                m1[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))
            else:
                m2[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))

for i in range(row):
    for j in range(col):
        ans[i][j] = m1[i][j] - m2[i][j]

print("Subtraction of matrices:", ans)

# MULTIPLICATION OF MATRIX
row = int(input("Enter the number of rows: "))
col = int(input("Enter the number of columns: "))
m1 = [[0 for i in range(col)] for i in range(row)]
m2 = [[0 for i in range(col)] for i in range(row)]
ans = [[0 for i in range(col)] for i in range(row)]

for n in range(2):
    print(f"Enter data for matrix {n+1} : ")
    for i in range(row):
        for j in range(col):
            if n == 0:
                m1[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))
            else:
                m2[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))

if row == col:
    for i in range(row):
        for j in range(row):
            for k in range(col):
                ans[i][j] += m1[i][k] * m2[k][j]
    print("Matrix 1 is", m1)
    print("Matrix 2 is", m2)
    print("Multiplication of matrices is", ans)
else:
    print("Multiplication not possible for non-square matrices.")

# TRANSPOSE OF MATRIX
row = int(input("Enter the number of rows: "))
col = int(input("Enter the number of columns: "))
m1 = [[0 for i in range(col)] for i in range(row)]
ans = [[0 for i in range(row)] for i in range(col)]

print("Enter data for the matrix:")
for i in range(row):
    for j in range(col):
        m1[i][j] = int(input(f"Enter data for row {i+1} and column {j+1}: "))

for i in range(row):
    for j in range(col):
        ans[j][i] = m1[i][j]

print("Original Matrix:", m1)
print("Transpose of the matrix:", ans)
