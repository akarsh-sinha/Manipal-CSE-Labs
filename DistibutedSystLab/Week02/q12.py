def printNegative(numbers):
    i = 0

    while i < len(numbers):
        current_number = numbers[i]

        if current_number < 0:
            print(current_number)

        i += 1

numbers_list = [13, 2, -7, 9, 2, -4, -3]
print("Negative Numbers:")
printNegative(numbers_list)