#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct plus
{
	int x_1;
	int x_2;
	int x_y;
	int x; 
	int y; 
	int y_1;
	int y_2;
	int total;
}plus_t;
 
int main()
{
	int ROW, COLUMN ,i,j, temp_col =0;
	char row_colunm[20] = {0};
	gets(&row_colunm);
	sscanf(row_colunm, "%d  %d", &ROW, &COLUMN);
	int *A = (int *)malloc(ROW * COLUMN * sizeof(int));
	for(i=0;i<ROW;i++)
	{
		char str[80] ;
		char *token;
		gets(&str);
		int LOOP_COLUMN =0;
		token = strtok(str, " ");
		while( token != NULL ) 
		{
			*(A + i*LOOP_COLUMN + temp_col++) = atoi(token);
			token = strtok(NULL, " ");
		}
		LOOP_COLUMN++;
	}

	plus_t *plus_array = (struct plus *)malloc((ROW-2) * (COLUMN-2) * sizeof(plus_t));
	plus_t* Max_array=plus_array;
	for (i = 1; i <  (ROW-1); i++)
	{
                for (j = 1; j < (COLUMN-1); j++)
		{	
			Max_array->x_1 = *(A + (i+1)*COLUMN + j);
			Max_array->x_2 = *(A + (i-1)*COLUMN + j);
			Max_array->x = (i*COLUMN);
			Max_array->y = j;
			Max_array->x_y = *(A + i*COLUMN + j);
			Max_array->y_1 = *(A + i*COLUMN + (j+1));
			Max_array->y_2 = *(A + i*COLUMN + (j-1));
			Max_array->total = (*(A + i*COLUMN + j) + *(A + i*COLUMN + (j+1)) + *(A + i*COLUMN + (j-1)) + *(A + (i-1)*COLUMN + j) + *(A + (i+1)*COLUMN + j));
			Max_array++;
		}
	}
	return(0);
}
