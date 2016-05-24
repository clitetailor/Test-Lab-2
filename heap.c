#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int * a, int * b)
{
	int n = *b;
	*b = *a;
	*a = n;
}

int leftchildnode(int n)
{
	return 2 * n + 1;
}

int rightchildnode(int n)
{
	return 2 * n + 2;
}

int parentnode(int n)
{
	return (n-1) / 2;
}

void siftDown(int * a, int start, int count)
{
	int i = start;
	
	int imax = parentnode(count + 1);
	while (i < imax)
	{
		int currentnodeindex = i;
		int leftnodeindex = leftchildnode(i);
		int rightnodeindex = rightchildnode(i);
		
		if (leftnodeindex < count && a[leftnodeindex] < a[i])
		{
			i = leftnodeindex;
		}
		
		if (rightnodeindex < count && a[rightnodeindex] < a[i])
		{
			i = rightnodeindex;
		}
		
		if (i != currentnodeindex)
		{
			swap( &a[currentnodeindex] , &a[i] );
		}
		else
			break;
	}
}

void heapify(int * a, int count)
{
	int i;
	
	for (i = parentnode(count - 1); i > -1; --i)
	{
		siftDown(a, i, count);
	}
}


// Haven't heapify
void heapsort(int * a, int count)
{
	int end = count - 1;
	
	while (end > 0)
	{
		swap( &a[0], &a[end]);
		siftDown(a, 0, end);
		--end;
	}
}

int main(int argc, char ** argv)
{
	// ------------------------------ //
	time_t t;
	time(&t);
	srand((unsigned) t);
	
	clock_t timing;
	timing = clock();
	// ------------------------------ //
	
	// Timing region
	
	// Initiallize
	int a[500000];
	
	// Session 1
	FILE * input_file = fopen("input.txt", "r");
	
	int i;
	for (i = 0; i < 500000; ++i)
	{
		fscanf(input_file, "%d", a + i);
	}
	
	// Heapify
	heapify(a, 500000);
	
	// Session 2
	FILE * temp_file = fopen("temp.txt", "w");
	
	int temp;
	for (i = 0; i < 500000; ++i)
	{
		fscanf(input_file, "%d", &temp);
		
		if (temp > a[0])
		{
			fprintf(temp_file, "%d ", a[0]);
			a[0] = temp;
			siftDown(a, 0, 500000);
		}
		else
		{
			fprintf(temp_file, "%d ", temp);
		}
	}
	
	fclose(temp_file);
	
	// Sort
	heapsort(a, 500000);
	
	FILE * output_file = fopen("output.txt", "w");
	
	for (i = 0; i < 500000; ++i)
	{
		fprintf(output_file, "%d ", a[i]);
	}
	
	// Session 3
	temp_file = fopen("temp.txt", "r");
	
	if (temp_file == NULL)
	{
		printf("Error!\n");
		return 0;
	}
	
	fseek(temp_file, 0, SEEK_SET);
	
	i = 0;
	while (fscanf(temp_file, "%d", a + i) == 1)
	{
		++i;
	}
	
	// Heap Sort
	heapify(a, 500000);
	heapsort(a, 500000);
	
	for (i = 0; i < 500000; ++i)
	{
		fprintf(output_file, "%d ", a[i]);
	}
	
	fclose(temp_file);
	fclose(input_file);
	fclose(output_file);
	
	// ------------------------------ //
	timing = clock() - timing;
	// ------------------------------ //
	
	printf("\n\n%d ms\n", timing);
	
	return 0;
}