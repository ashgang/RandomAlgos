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

int binarySearch (int *inArr, int searchItem);

int main ()
{
	int numItems = 0, i = 0, inArr[100] = {0}, searchItem = 0;

	do
	{
		printf ("\nEnter the number of items (1-100):");
		scanf ("%d", &numItems);
	} while (numItems <=0 || numItems > 100);

	for (i = 0; i < numItems; i++)
	{
		scanf ("%d", &inArr[i]);
	}

	selectionSort (inArr, numItems);
	binarySearch (inArr, searchItem);
}

int binarySearch (int *inArr, int searchItem)
{
	return 0;
}
