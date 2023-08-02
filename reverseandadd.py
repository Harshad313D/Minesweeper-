def reverse_and_add_palindrome(num):
    iterations = 0

    while True:
        # Convert the number to a string and check if it's a palindrome
        num_str = str(num)
        if num_str == num_str[::-1]:
            break

        # Reverse the number, add it to the original, and update the number
        reversed_num = int(num_str[::-1])
        num += reversed_num
        iterations += 1

    return iterations, num

# Read the number of test cases
num_test_cases = int(input())

# Process each test case
for _ in range(num_test_cases):
    num = int(input())
    iterations, palindrome = reverse_and_add_palindrome(num)
    print(f"{iterations} {palindrome}")
