import numpy as np

A = np.array ([2,5,10])
print(A.dtype)
B = np.array ([2.4,10.6,5.2])
print(B.dtype, "\n")

A = np.array([(3,4,5),(12,6,1)])
print(A, "\n")

Z = np.zeros((2,4)) # will create zero matrix of dimension 2x4
print(Z, "\n")

O = np.ones((3,3)) # will create one’s matrix of dimension 3x3
print(O, "\n")

S=np.arange(16,32)
print(S)