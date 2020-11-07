func subarraysWithKDistinct(A []int, K int) int {
    count := make(map[int]int)
    left := 0
    nsub := 0
    ans := 0
    cnt := 0
    for right := 0; right < len(A); right++ {
        count[A[right]]++
        if count[A[right]] == 1 {
            cnt++
        }
        
        if cnt > K {
            count[A[left]]--
            left++
            cnt--
            nsub = 0
        }
        
        if cnt == K {
            for count[A[left]] > 1 {
                nsub++
                count[A[left]]--
                left++
            }
            ans += nsub + 1
        }
    }
    return ans
}