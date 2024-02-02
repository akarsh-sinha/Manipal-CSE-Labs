import numpy as np 

num = int(input("Enter a number: "))
A = np.array([1])

for i in range(2, num + 1):
	if(num % i == 0):
		A = np.append(A, i)

print("Factors: ", A)