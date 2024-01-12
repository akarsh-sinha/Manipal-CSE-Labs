def while_loop_example(limit):
    count = 0

    while count < limit:
        print(f"Current count: {count}")
        count += 1
    else:
        print("Loop finished, count reached the limit.")

while_loop_example(7)