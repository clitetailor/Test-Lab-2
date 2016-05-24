#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * output_file = fopen("output.txt", "rt");
	
	int i;
	int temp;
	int count = 0;
	while (!feof(output_file))
	{
		fscanf(output_file, "%d", &temp);
		printf("%d\n", temp);
		++count;
	}
	
	fclose(output_file);
	printf("\nCount: %d\n", count);
	
	return 0;
}