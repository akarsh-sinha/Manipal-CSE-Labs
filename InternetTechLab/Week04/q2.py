class My_solution:
    arr = []
    target = 0
    def __init__(self, arr, target):
        self.arr = arr
        self.target = target
    def twoSum(self):
        mp = {self.arr[i] : i + 1 for i in range(len(self.arr))}
        for i in range(len(self.arr)):
            key = self.target - self.arr[i]
            if (key in mp):
                return {mp[self.arr[i]], mp[key]}
        return {-1, -1}

arr = [int(x) for x in input('Enter elements of array: ').split()]
target = int(input("Enter target: "))
obj = My_solution(arr, target)
print(obj.twoSum())