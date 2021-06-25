/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int finalCount = 0;

void helper(int base, int* nums, bool* visited, int current, int start) {
    int size = sizeof(nums) / sizeof(int) + 1;
    for (int i = start; i < size; i++) {
        int next = (current + nums[i]) % base;
        if (visited[next] == false) {
            visited[next] = true;
            finalCount++;
            helper(base, nums, visited, next, i);
        }
    }
}

void test(int n, int base) {
    bool* visited = (bool*) calloc(base, sizeof(bool));
    int* nums = (int*) calloc(n, sizeof(int));
    int* newNums = (int*) calloc(n, sizeof(int));
    int count = 0;
    
    for (int i = 0; i < base; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n; i++) {
        if (visited[nums[i] % base] == false) {
            visited[nums[i] % base] = true;
            newNums[count] = nums[i] % base;
            count++;
            finalCount++;
        }
    }
    for (int i = 0; i < count; i++) {
        helper(base, newNums, visited, newNums[i], i);
    }
    printf("%d\n", finalCount);
    finalCount = 0;
    for (int i = 0; i < base; i++) {
        if (visited[i] == true) printf("%d ", i);
    }
    printf("\n");
    free(visited);
    free(nums);
    free(newNums);
}

int main()  {
    int n, k;
    while (scanf("%d%d", &n, &k) > 0) {
        test(n, k);
    }
}
