function maxSubarraySum(nums: number[]): number {
    // Handle case where all numbers are non-positive
    const maxNum = Math.max(...nums);
    if (maxNum <= 0) {
        return maxNum;
    }

    // Helper function to calculate prefix sums
    function getPrefixSums(arr: number[]): number[] {
        const prefixSums = [0];
        let sum = 0;
        for (const num of arr) {
            sum += num;
            prefixSums.push(sum);
        }
        return prefixSums;
    }

    // Helper function to solve one direction
    function solve(arr: number[]): number[] {
        const n = arr.length;
        const prefixSums = getPrefixSums(arr);
        const dp = new Array(n).fill(0);
        const mostRecent = new Map<number, number>();
        let s = 0;

        for (let i = 0; i < n; i++) {
            if (arr[i] < 0) {
                if (mostRecent.has(arr[i])) {
                    const prevIndex = mostRecent.get(arr[i])!;
                    const connect = prefixSums[i] - prefixSums[prevIndex + 1] + dp[prevIndex];
                    dp[i] = Math.max(s, connect);
                } else {
                    dp[i] = s;
                }
                mostRecent.set(arr[i], i);
            }
            s = Math.max(0, s + arr[i]);
        }
        return dp;
    }

    // Kadane's algorithm for maximum subarray sum
    function kadane(arr: number[]): number {
        let maxSoFar = -Infinity;
        let sum = 0;
        
        for (const num of arr) {
            sum = sum > 0 ? sum + num : num;
            maxSoFar = Math.max(maxSoFar, sum);
        }
        
        return maxSoFar;
    }

    // Two-way dynamic programming approach
    function twoWayDP(arr: number[]): number {
        const forward = solve(arr);
        const backward = solve([...arr].reverse()).reverse();
        
        let maxSum = -Infinity;
        for (let i = 0; i < arr.length; i++) {
            maxSum = Math.max(maxSum, forward[i] + backward[i]);
        }
        
        return maxSum;
    }

    // Get results from both approaches and return the maximum
    const ans0 = kadane(nums);
    const ans1 = twoWayDP(nums);
    
    return Math.max(ans0, ans1);
}