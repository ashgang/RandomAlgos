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
#include <stdlib.h>

/*
 * Usable enums
 */
typedef enum
{
	FALSE = 0,
	TRUE
} Boolean;

/*
 * Forward declarations
 */
Boolean linearSearch (int numItems, int searchItem);
Boolean linearSearchSentinel (int numItems, int searchItem);

/*
 * Global variables
 */
int searchArr[100] = {0};

int main ()
{
	int numItems = 0, i, searchItem = 0, algoIdx = 0;
	Boolean itemFound = FALSE;

	printf ("\nEnter the number of items in search array (1-100): ");
	while (1)
	{
		scanf ("%d", &numItems);
		if ((numItems <= 100) && (numItems > 0))
		{
			break;
		}
		printf ("\nEntered value is greater than 100 or is negative, please enter a value between 1-100: ");
	}
	printf ("\nPlease enter the list of values to fill the search array:");
	for (i = 0; i < numItems; i++)
	{
		scanf ("%d", &searchArr[i]);
	}

	while (1)
	{
		printf ("\nEnter the search item:");
		scanf ("%d", &searchItem);

		printf ("\nList of search algo's available:\n");
		printf ("1) Linear search\n2) Linear search with sentinel\n3) Exit\n");
		printf ("Choose one:");
		scanf ("%d", &algoIdx);

		switch (algoIdx)
		{
			case 1:
				itemFound = linearSearch (numItems, searchItem);
				break;
			case 2:
				itemFound = linearSearchSentinel (numItems, searchItem);
				break;
			case 3:
				printf ("\nExiting...\n");
				exit(0);
			default:
				printf ("\nOption not available, defaulting to Linear search!\n");
				itemFound = linearSearch (numItems, searchItem);
				break;
		}

		if (itemFound == TRUE)
		{
			printf ("Holy Cow!!! Item %d is found in the DB\n", searchItem);
		}
		else
		{
			printf ("Oops! The item you requested is not found in the DB\n");
		}
	}

	return 0;
}

Boolean linearSearch (int numItems, int searchItem)
{
	int i = 0;

	printf ("Starting a Linear search!!!\n");
	for (i = 0; i < numItems; i++)
	{
		if (searchArr[i] == searchItem)
		{
			return TRUE;
		}
	}

	return FALSE;
}

/*
 * Here although complexity increases mildly we reduce the if checking that runs 
 * for every iteration thereby improving the performance.  This uses a sentinel 
 * to check for boundary conditions
 */
Boolean linearSearchSentinel (int numItems, int searchItem)
{
	int lastVarTemp = 0, i = 0;

	printf ("Starting a Linear search with sentinel!!!\n");
	lastVarTemp = searchArr[numItems - 1];
	searchArr[numItems - 1] = searchItem;
	i = 0;
	while (searchArr[i] != searchItem)
	{
		i++;
	}
	searchArr[numItems - 1] = lastVarTemp;
	
	if ((i < (numItems - 1)) || (lastVarTemp == searchItem))
	{
		return TRUE;
	}
	
	return FALSE;
}

/************************************ END OF PROGRAM *****************************************/
