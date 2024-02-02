import numpy as np 
A1=np.array([(3,4,5),(12,6,1)])
A2=np.array([(1,2,6),(-4,3,8)])

D1=np.vstack((A1,A2))
D2=np.hstack((A1,A2))

print(D1, "\n")
print(D2)