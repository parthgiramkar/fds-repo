import numpy


def input_matrix(name, rows, cols):
    print(f"Enter the elements of matrix {name} row by row, separated by spaces:")
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i + 1} with {cols} elements: ").split()))
        matrix.append(row)
    return numpy.array(matrix)


rows = int(input("Enter the number of rows for the matrices: "))
cols = int(input("Enter the number of columns for the matrices: "))


x = input_matrix('X', rows, cols)
y = input_matrix('Y', rows, cols)


print("\nThe element-wise addition of matrices is: ")
print(numpy.add(x, y))

print("\nThe element-wise subtraction of matrices is: ")
print(numpy.subtract(x, y))

print("\nThe product of matrices is: ")
print(numpy.dot(x, y))

print("\nThe transpose of the first matrix is: ")
print(x.T)
