// function count(num1: string, num2: string, min_sum: number, max_sum: number): number {
    
// };
function count(
  année1: string,
  année2: string,
  somme_min: number,
  somme_max: number
): number {
  const MODULO = 1_000_000_007;

  function digitSum(n: string): number {
    return n.split("").reduce((sum, digit) => sum + parseInt(digit), 0);
  }

  function countValidYears(maxYear: string, maxSum: number): number {
    const memo = new Map<string, number>();

    function dfs(
      pos: number,
      tight: boolean,
      currentSum: number
    ): number {
      if (currentSum > maxSum) return 0;
      if (pos === maxYear.length) return 1;

      const key = `${pos},${tight},${currentSum}`;
      if (memo.has(key)) return memo.get(key)!;

      const limit = tight ? parseInt(maxYear[pos]) : 9;
      let total = 0;

      for (let digit = 0; digit <= limit; digit++) {
        total += dfs(
          pos + 1,
          tight && digit === limit,
          currentSum + digit
        );
        total %= MODULO;
      }

      memo.set(key, total);
      return total;
    }

    return dfs(0, true, 0);
  }

  function rangeCount(lower: string, upper: string, minSum: number, maxSum: number): number {
    function countInRange(year: string, minSum: number, maxSum: number): number {
      const maxCount = countValidYears(year, maxSum);
      const minCount = countValidYears(year, minSum - 1);
      return (maxCount - minCount + MODULO) % MODULO;
    }

    const countUpper = countInRange(upper, somme_min, somme_max);
    const countLower = countInRange((BigInt(lower) - BigInt(1)).toString(), somme_min, somme_max);

    return (countUpper - countLower + MODULO) % MODULO;
  }

  return rangeCount(année1, année2, somme_min, somme_max);
}
