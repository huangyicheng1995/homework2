#include <stdio.h>

#include <omp.h>

int main()

{

    int i, n,j;

    double a[100], b[100], result;

    n = 100;

    result = 0.0;
    double start = omp_get_wtime( ); 

    for (i = 0; i < n; i++)

    {
        a[i] = i * 1.0;

        b[i] = i * 2.0;
    }
    printf("Vector a=\n");
    for (i=0;i<n;i++)
    {
	printf("%.16g\t",a[i]);
	if ((i+1)%10==0)
	{
		printf("\n");
	}
    }    
    printf ("\n");
    printf("Vector b=\n");
    for (i=0;i<n;i++)
    {
	printf("%.16g\t",b[i]);
	if ((i+1)%10==0)
	{
		printf("\n");
	}
    }    
    printf ("\n");
    #pragma omp parallel for private(i) reduction(+:result)

    for (i = 0; i < n; i++)

    {

        for (j=0;j<n;j++)
	{
		result = result + (a[i] * b[j]);
	}
    }
    double end = omp_get_wtime( );
    printf("start = %.16g\nend = %.16g\ntime= %.16g seconds\n",start,end,end- start); 
    printf("a*b= %12.6lf\n", result); 
    return 0;
}
