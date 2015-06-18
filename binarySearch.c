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
* See the License for the specific language governing permissions and 
* limitations under the License.
***************************************************************************/

#include <stdio.h>

/*
 * Usable enums
 */
typedef enum
{
	FALSE = 0,
	TRUE
} Boolean;

Boolean binarySearch (int *inArr, int searchItem, int numItems);

int main ()
{
	int numItems = 0, i = 0, inArr[100] = {0}, searchItem = 0, sortAlgoCh = 0;

	do
	{
		printf ("\nEnter the number of items (1-100):");
		scanf ("%d", &numItems);
	} while (numItems <=0 || numItems > 100);

	for (i = 0; i < numItems; i++)
	{
		scanf ("%d", &inArr[i]);
	}

	printf ("\nEnter the search item: ");
	scanf ("%d", &searchItem);
	
	printf ("\n 1) Selection Sort \n 2) Insertion Sort \n Choose sorting algo:");
	scanf ("%d", &sortAlgoCh);

	switch (sortAlgoCh)
	{
		case 1:
			selectionSort (inArr, numItems);
			break;

		case 2:
			insertionSort (inArr, numItems);
			break;

		default:
			/*
			 * Wrong input, so default it to the most optimal sort algo in the list
			 */
			insertionSort (inArr, numItems);
			break;
	}

	if (binarySearch (inArr, searchItem, numItems) == TRUE)
	{
		printf ("Item found!\n");
	}
	else
	{
		printf ("Item not found in the array\n");
	}
	return 0;
}

Boolean binarySearch (int *inArr, int searchItem, int numItems)
{
	int fwd = 0, bwd = 0, inter = 0;

	if (inArr == NULL)
	{
		printf ("Input Error! Can't proceed further!\n");
		return FALSE;
	}
	bwd = numItems;
	while (fwd <= bwd)
	{
		inter = (fwd + bwd)/2;
		if (inArr[inter] == searchItem)
		{
#ifdef PRINT_RESULT
			printf ("Item Found!!!\n");
#endif
			return TRUE;
		}
		else if (inArr[inter] > searchItem)
		{
			bwd = inter - 1;
		}
		else
		{
			fwd = inter + 1;
		}
	}

	return FALSE;
}
