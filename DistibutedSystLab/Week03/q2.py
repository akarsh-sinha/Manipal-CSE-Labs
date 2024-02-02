import numpy as np 

A = np.array([(3,4,5),(12,6,1),(83,35,13)])
rowsum = np.sum(A, axis = 1)
print("Row Sum = ", rowsum)
colsum = np.sum(A, axis = 0)
print("Column Sum = ", colsum)