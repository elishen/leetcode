class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        if not nums:
            return [-1, -1]
        low = 0
        high = len(nums) - 1

        if nums[low] > target or nums[high] < target:
            return [-1, -1]

        while (low <= high):
            mid = (low + high) // 2
            if nums[mid] >= target:
                high = mid - 1
            else:
                low = mid + 1
            print(low, high)

        left = low
        if nums[left] != target:
            return [-1, -1]

        high = len(nums) - 1
        while (low <= high):
            mid = (low + high) // 2
            if nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
            print(low, high)

        return [left, high]

s = Solution()

# print(s.searchRange([5, 7, 7, 8, 8, 10], 8))

print(s.searchRange([2, 2], 3))