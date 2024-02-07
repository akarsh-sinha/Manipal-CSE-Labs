def binary_search(arr, l, r, x):
    if l <= r:
        mid = (l + r) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, l, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, r, x)
    else:
        return -1

arr = [1, 2, 8, 13, 19, 23, 31]
target = int(input('Enter number to be searched: '))
result = binary_search(arr, 0, len(arr)-1, target)
if result != -1:
    print("Element is present at index: ", result)
else:
    print("Element is not present in array")
