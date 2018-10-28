#include <stdio.h>
#include <omp.h>
int main()
{	
	int sum = 0;	
	int i;
    #pragma omp critical
    #pragma omp parallel for num_threads(4)
	for(i = 1; i <= 100; i++)
    { 
        if (i % 10 == 0)
            printf("Loop %d, Threads number = %d \n", i, omp_get_thread_num());	
        #pragma omp atomic
		sum += i;
	}	
	printf("sum = %d\n", sum);
    return 0;
}
