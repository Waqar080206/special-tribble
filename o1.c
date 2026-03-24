 //To implement the 0/1 knapsack problem using DP Approach.
#include <stdio.h>
int max(int a, int b) {
 return (a > b) ? a : b;
}
void knapsack(int n, int W, int weight[], int value[]) {
 int c[n+1][W+1];
 
 for (int i = 0; i <= n; i++) {
 for (int w = 0; w <= W; w++) {
 if (i == 0 || w == 0)
 c[i][w] = 0;
 else if (weight[i-1] <= w)
 c[i][w] = max(value[i-1] + c[i-1][w - weight[i-1]], c[i-1][w]);
 else
 c[i][w] = c[i-1][w];
 }
 }
 


 int w= W;
 printf("Selected items (1-based index): ");
 for (int i = n; i > 0 && w > 0; i--) {
 if (c[i][w] != c[i-1][w]) {
 printf("%d ", i);
 w -= weight[i-1];
 }
 }
 printf("\n");
  printf("\n Value Being = %d\n", c[n][W]);
}
int main() {
 int n, W;
 printf("Enter number of items: ");
 scanf("%d", &n);
 int value[n], weight[n];
 printf("Enter values of items:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &value[i]);
 }
 printf("Enter weights of items:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &weight[i]);
 }
 printf("Enter capacity of knapsack: ");
 scanf("%d", &W);
 knapsack(n, W, weight, value);
 return 0;
}