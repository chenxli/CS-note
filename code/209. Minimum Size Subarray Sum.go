func minSubArrayLen(s int, nums []int) int {
    left := 0
    ans := 1 << 30
    sum := 0
    for right := 0; right < len(nums); right++ {
        sum += nums[right]
        for sum >= s {
            if ans > right - left + 1 {
                ans = right - left + 1
            }
            sum -= nums[left]
            left++
        }
    }
    if ans == 1 << 30 {
        return 0
    } else {
        return ans
    }
}