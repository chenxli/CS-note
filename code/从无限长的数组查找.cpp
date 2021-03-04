public class FindKIndexFromInfinteArray {
    public static int solution(int[] array, int target){
        int result = -1;
        // 处理边界与特殊值
        if(array == null || array.length == 0)    return result;
        if(array[0] == Integer.MAX_VALUE)    return result;
        else if(array[0] == target)    return 1;
        
        int i = 1;
        while(array[i] != Integer.MAX_VALUE){// 遇到MAX就停止
            if(array[i] == target)    return i;// 在循环中如果碰到刚好等于目标值，就直接返回
            i *= 2;//2，4，8，16，32。。。以指数级别上升
        }
        // 此时i定位到一个右边界，开始进行二分查找，从0到i
        result = binarySearch(array, target, 0, i);
        return result;
    }
    /** 二分查找*/
    private static int binarySearch(int[] array, int target, int low, int high) {
        int left = low, right = high - 1;
        /* 如果这里是 int right = n 的话，那么下面有两处地方需要修改，以保证一一对应：    
         * 1、下面循环的条件则是while(left < right)    
         * 2、循环内当array[middle]>value 的时候，right = mid 
         */
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(array[mid] > target)        right = mid - 1;
            else if(array[mid] < target)    left = mid + 1;
            else    return mid;
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4,7,9,11,18,20,31,36,65,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE};
        System.out.println(solution(nums, 31));
    }
}