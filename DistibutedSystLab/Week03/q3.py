import numpy as np

l = [10, 9, -2, 3]
arr = np.array(l, dtype=float)
print(arr, "\n")

tup = (10, 9, -2, 3.2)
arr = np.array(tup)
print(arr, "\n")

arr = np.zeros((3, 4))
print(arr, "\n")

arr = np.arange(0, 21, 5)
print(arr, "\n")

arr = np.array([np.arange(0, 4), np.arange(4, 8), np.arange(8, 12)])
arr = arr.reshape((2, 2, 3))
print(arr, "\n")

arr = np.array([np.arange(0, 4), np.arange(4, 8), np.arange(8, 12)])
print(arr)
print("Maximum element: ", arr.max(), "\nMinimum element: ", arr.min())
print("Sum of elements: ", arr.sum())
print("Columnwise max: ", arr.max(axis = 0))
print("Columnwise min: ", arr.min(axis = 0))
print("Row wise max: ", arr.max(axis = 1))
print("Row wise min: ", arr.min(axis = 1))