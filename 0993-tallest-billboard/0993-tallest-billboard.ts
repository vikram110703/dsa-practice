// function tallestBillboard(rods: number[]): number {
    
// };

const dp: number[][] = Array.from({ length: 21 }, () => Array(10001).fill(-1));

function solve(candies: number[], index: number, varValue: number): number {
    if (index === candies.length) {
        return varValue === 0 ? 0 : Number.MIN_SAFE_INTEGER;
    }
    if (dp[index][varValue + 5000] !== -1) {
        return dp[index][varValue + 5000];
    }

    const option1 = solve(candies, index + 1, varValue);
    const option2 = solve(candies, index + 1, varValue + candies[index]) + candies[index];
    const option3 = solve(candies, index + 1, varValue - candies[index]);

    dp[index][varValue + 5000] = Math.max(option1, Math.max(option2, option3));
    return dp[index][varValue + 5000];
}

function tallestBillboard(candies: number[]): number {
    dp.forEach(row => row.fill(-1)); // Reset DP array
    return solve(candies, 0, 0);
}

