a = int(input('Enter first no. : '))
b = int(input('Enter second no. : '))
c = int(input('Enter 1 for Addition,\n2 for Subtraction,\n3 for Multiplication,\n4 for Division\n'))
if (c == 1):
    print('Answer = ',(a + b))
elif(c == 2):
    print('Answer = ',(a - b))
elif(c == 3):
    print('Answer = ',(a * b))
elif(c == 4):
    print('Answer = ',(a / b))
else:
    print('Invalid Choice')
    