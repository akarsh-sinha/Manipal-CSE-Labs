class My_solution:
    def __init__(self):
        self.subsets = []

    def generateSubsets(self, nums):
        self.subsets = []
        self.backtrack(nums, 0, [])
        return self.subsets

    def backtrack(self, nums, index, current):
        self.subsets.append(current[:])
        for i in range(index, len(nums)):
            current.append(nums[i])
            self.backtrack(nums, i + 1, current)
            current.pop()


nums = input("Enter distinct integers separated by spaces: ").split()
nums = [int(num) for num in nums]
obj = My_solution()
print(obj.generateSubsets(nums))
