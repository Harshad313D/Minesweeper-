def count_carry_operations(num1, num2):
    carry = 0
    carry_operations = 0

    while num1 > 0 or num2 > 0:
        digit1 = num1 % 10
        digit2 = num2 % 10

        sum_digits = digit1 + digit2 + carry
        if sum_digits >= 10:
            carry = 1
            carry_operations += 1
        else:
            carry = 0

        num1 //= 10
        num2 //= 10

    return carry_operations

# Read input until '0 0' is encountered
while True:
    num1, num2 = map(int, input().split())

    if num1 == 0 and num2 == 0:
        break

    carry_operations = count_carry_operations(num1, num2)

    if carry_operations == 0:
        print("No carry operation.")
    elif carry_operations == 1:
        print("1 carry operation.")
    else:
        print(f"{carry_operations} carry operations.")
