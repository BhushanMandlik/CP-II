# By using backtracking pseudocode from pdf (Implementation of generating all possible subsets)

def subsets(nums):
    res = []
    backtrack(res, [], nums, 0)
    return res

def backtrack(res, temp, nums, start):
    #print(temp)
    res.append(temp[:])
    for i in range(start, len(nums)):
        temp.append(nums[i])
        backtrack(res, temp, nums, i + 1)
        #print("hello")
        temp.pop() # Backtrack

print(subsets([1, 2, 3]))