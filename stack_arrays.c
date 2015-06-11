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

int push_item();
int pop_item();
void show_all();
void del_all();
int arr[20] = {0};
int stack_capacity = 0;

int main()
{
		int usrip;

		while (1) {
				printf("1. Push\n");
				printf("2. Pop\n");
				printf("3. Show All\n");
				printf("4. Delete All\n");
				printf("5. Exit\n");
				printf("Please enter an option\n");
				scanf("%d", &usrip);
				switch (usrip)
				{
						case 1:
								push_item();
								break;

						case 2:
								pop_item();
								break;

						case 3:
								show_all();
								break;

						case 4:
								del_all();
								break;

						case 5:
								del_all();
								printf ("\nExiting...\n");
								return 0;

						default:
								del_all();
								printf ("Hey Asshole! can you not see a list of options provided\n");
								printf ("Get lost... Exiting...\n");
								return 0;
				}
		}
		return 0;
}

int push_item()
{
		int item, i;

		printf ("\nEnter the item you want to add:");
		scanf ("%d", &item);

		if(stack_capacity == 10)
		{
				printf ("Stack full!\n");
				return 0;
		}

		for(i = stack_capacity; i >= 0; i--)
		{
				arr[i+1] = arr[i];
		}
		arr[0] = item;
		stack_capacity++;

		printf ("New Item had been added...\n");
		return 0;
}

int pop_item()
{
		int i, item;
		if (stack_capacity == 0)
		{
				printf("There are no entries in the list...\n");
				return 0;
		}
		item = arr[0];
		for(i=0;i<stack_capacity;i++)
		{
				arr[i]=arr[i+1];
		}
		stack_capacity--;
		printf ("Poped Item: %d\n", item);
		return 0;
}

void show_all()
{
		int i = 0;
		if (stack_capacity == 0)
		{
				printf("No entries to show...\n");
				return ;
		}
		printf ("*********************************************************************\n");
		printf ("The total list:\t");
		while (i < stack_capacity) {
				printf ("%d\t", arr[i++]);
		}
		printf ("\n*********************************************************************\n");
}

void del_all()
{
		printf ("Deleting all entries...\n");
		if(stack_capacity == 0)
		{
				printf ("No entries to delete!\n");
				return;
		}
		while (stack_capacity > 0)
		{
				arr[--stack_capacity] = 0;
		}
}

/****************************** END OF PROGRAM *******************************/
