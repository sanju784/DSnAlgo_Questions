/*********************************************
*
*  Matrix Product Parenthesizations
*
*/////////////////////////////////////////////

#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int arr[], int n)
{
    int m[n][n];

    int i, j, k, L, q;

    for(i=1;i<n;i++)
        m[i][i] = 0;

        for(L=2;L<n;L++)
        {
            for(i=1;i<n-L+1;i++)
            {
                j=i+L-1;
                m[i][j] = INT_MAX;
                for(k=i;k<=j-1;k++)
                {
                    q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    if(q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
        return m[1][n-1];
}

void main()
{
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum needed multiplication is %d", matrixChainMultiplication(arr, n));
}