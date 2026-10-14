#include <stdio.h>
int arr[20];
int subset[20];
int result[1048576][20];
int resultSize[1048576];
int count = 0;

void findSubsets(int index, int sum, int size) {
    if (index == n) {
        if (sum == target) {
            for (int i = 0; i < size; i++) {
                result[count][i] = subset[i];
            }
            resultSize[count] = size;
            count++;
        }
        return;
    }

    // Include current element
    subset[size] = arr[index];
    findSubsets(index + 1, sum + arr[index], size + 1);

    // Exclude current element
    findSubsets(index + 1, sum, size);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    findSubsets(0, 0, 0);

    if (count == 0) {
        printf("-1\n");
    } else {
        // Print in reverse order of discovery
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < resultSize[i]; j++) {
                printf("%d", result[i][j]);

                if (j < resultSize[i] - 1)
                    printf(" ");
            }
            printf(" \n");
        }
    }

    return 0;
}
