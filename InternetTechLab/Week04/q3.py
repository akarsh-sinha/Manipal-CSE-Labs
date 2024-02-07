class My_solution:
    def pow(self, x, n):
        if(n == 1):
            return x
        if (n % 2 == 0):
            return (pow(x, n // 2) * pow(x, n // 2))
        else:
            return (x * pow(x, n // 2) * pow(x, n // 2))

x = int(input("Enter a number x: "))
n = int(input("Enter a number y: "))
obj = My_solution()
print(obj.pow(x, n))