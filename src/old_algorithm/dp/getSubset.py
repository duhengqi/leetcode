import time
def L(nums, i):
    if i == len(nums)-1:
        return 1
    max_len = 1
    for j in range(i+1, len(nums)):
        if nums[j] > nums[i]:
            max_len = max(max_len,L(nums,j)+1)
    return max_len

start_time = time.time()

def length_of_LIS(nums):
    return max(L(nums,i) for i in range(len(nums)))

nums = [1, 5, 2, 4, 3]

print(length_of_LIS(nums))

print("Toos %.4f sec." % (time.time()-start_time))