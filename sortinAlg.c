/**************************************************************************
*  Copyright 2015 wonkymind86@gmail.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and·
* limitations under the License.
***************************************************************************/

#include <stdio.h>

#define PRINT_RESULT

/*
 * Helper functions
 */
static void swap (int *a, int *b)
{
	int temp = 0;

	if ((a == NULL) || (b == NULL))
	{
		printf ("Input Error! Can't continue further!\n");
		return ;
	}

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * This is a bunch of sorting algorithms intented to make it available as library.
 * So any program that needs sorting as intermediate output can link this library
 * and chose an algorithm of their choice.
 */

/*
 * Selection sort is an in-place sorting algorithm with a best and worst case performance
 * of O(n^2)
 */
void selectionSort (int *inArr, int numItems)
{
	int i = 0, j = 0, smallestItem = 0;

	if ((inArr == NULL) || (numItems <= 0))
	{
		printf ("Input Error! Can't continue further\n");
		return ;
	}
	
	for (i = 0; i < numItems; i++)
	{
		smallestItem = i;
		for (j = i + 1; j < numItems; j++)
		{
			if (inArr[smallestItem] > inArr[j])
			{
				smallestItem = j;
			}
		}
		if (smallestItem != i)
		{
			swap (&inArr[i], &inArr[smallestItem]);
		}
#ifdef TEST_SORT	
		printf ("\nIntermediate sorted Array:");
		for(j = 0; j < numItems; j++)
		{
			printf ("%d\t", inArr[j]);
		}
#endif
	}

#ifdef PRINT_RESULT
	printf ("\nSorted Array:");
	for(j = 0; j < numItems; j++)
	{
		printf ("%d\t", inArr[j]);
	}
	printf ("\n");
#endif
}

