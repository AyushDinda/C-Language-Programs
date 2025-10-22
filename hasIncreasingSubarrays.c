#include <stdbool.h>
#include <stdio.h>

bool hasIncreasingSubarrays(int* nums, int n, int k) {
    int cur = 0;
    int pre = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cur++;
        // If this run ends here (end of array or next is not greater)
        if (i == n - 1 || nums[i] >= nums[i + 1]) {
            int opt1 = cur / 2;                  // split current run in half
            int opt2 = (pre < cur) ? pre : cur;  // tail of previous + head of current
            int better = (opt1 > opt2) ? opt1 : opt2;
            if (better > mx) mx = better;        // update max possible k
            pre = cur;                           // shift runs
            cur = 0;
        }
    }
    return mx >= k;
}

// Example usage
int main() {
    int nums[] = {1, 2, 3, 1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    if (hasIncreasingSubarrays(nums, n, k))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
