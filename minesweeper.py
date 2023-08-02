def count_adjacent_mines(field, row, col):
    count = 0
    for i in range(row - 1, row + 2):
        for j in range(col - 1, col + 2):
            if i >= 0 and i < len(field) and j >= 0 and j < len(field[0]):
                if field[i][j] == '*':
                    count += 1
    return count

# Read the input fields
field_number = 1
while True:
    n, m = map(int, input().split())

    if n == 0 and m == 0:
        break

    # Read the field
    field = []
    for _ in range(n):
        row = input()
        field.append(row)

    # Print the field number
    if field_number > 1:
        print()

    print(f"Field #{field_number}:")
    field_number += 1

    # Process each square of the field
    for i in range(n):
        for j in range(m):
            if field[i][j] == '.':
                # Count adjacent mines for safe squares
                count = count_adjacent_mines(field, i, j)
                field[i] = field[i][:j] + str(count) + field[i][j+1:]

    # Print the modified field
    for row in field:
        print(row)
