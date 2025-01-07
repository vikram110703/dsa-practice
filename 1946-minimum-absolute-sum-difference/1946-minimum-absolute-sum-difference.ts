function minAbsoluteSumDiff(nums1: number[], nums2: number[]): number {
    const MOD = 1e9 + 7;
    const n = nums1.length;
    
    // Calculate actual differences and their sum
    const diff: number[] = [];
    const temp: number[] = [];
    let actualDiff = 0;
    
    for (let i = 0; i < n; i++) {
        const val = Math.abs(nums1[i] - nums2[i]);
        diff.push(val);
        actualDiff = (actualDiff + val) % MOD;
    }
    
    // Create sorted copy of nums1 for binary search
    const sortedNums1 = [...nums1].sort((a, b) => a - b);
    
    // Helper function to implement C++'s lower_bound
    function lowerBound(arr: number[], target: number): number {
        let left = 0;
        let right = arr.length;
        
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
    
    // Calculate potential improvements
    for (let i = 0; i < n; i++) {
        const j = lowerBound(sortedNums1, nums2[i]);
        
        if (j === 0) {
            // If j is the first index
            temp.push(Math.abs(nums2[i] - sortedNums1[j]));
        } else if (j === n) {
            // If j is beyond the last index
            temp.push(Math.abs(nums2[i] - sortedNums1[j - 1]));
        } else {
            // Compare with both adjacent values
            const val = Math.min(
                Math.abs(nums2[i] - sortedNums1[j - 1]),
                Math.abs(nums2[i] - sortedNums1[j])
            );
            temp.push(val);
        }
    }
    
    // Find maximum improvement
    let maxImprovement = 0;
    for (let i = 0; i < n; i++) {
        maxImprovement = Math.max(maxImprovement, diff[i] - temp[i]);
    }
    
    // Calculate final result
    const ans = ((actualDiff - maxImprovement + MOD) % MOD);
    
    return ans;
}