#include <stdio.h>

#define MAX 100
#define INF 1000000000

int p[MAX];        
int dp[MAX][MAX];  
int MCM(int i, int j) {

    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min = INF;

    for (int k = i; k < j; k++) {

        int cost = MCM(i, k) +
                   MCM(k + 1, j) +
                   p[i - 1] * p[k] * p[j];

        if (cost < min)
            min = cost;
    }

    dp[i][j] = min;
    return min;
}

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int rows[n], cols[n];
    for (int i = 0; i < n; i++) {
        printf("Enter rows and cols of Matrix A%d: ", i + 1);
        scanf("%d %d", &rows[i], &cols[i]);

        // Validate multiplication condition
        if (i > 0 && rows[i] != cols[i - 1]) {
            printf("Invalid dimensions! Cannot multiply.\n");
            return 0;
        }
    }

    p[0] = rows[0];
    for (int i = 1; i <= n; i++) {
        p[i] = cols[i - 1];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;

    int result = MCM(1, n);

    printf("Minimum multiplication cost = %d\n", result);

    return 0;
}