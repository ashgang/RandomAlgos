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
** This is the linked list structure -> its a self-referencial structure
*/
struct lnlst {
		int data;
		struct lnlst *next;
		/*
		 ** If we are using double linked list we need a prev ptr, this is not used in this program
		 ** We are implementing a mere single linked list here.
		 */
		struct lnlst *prev;
};

int add_item(struct lnlst *);
int del_item(struct lnlst *);
int traverse(struct lnlst *);
void show_all(struct lnlst *);
void del_all(struct lnlst *);

int main()
{
		int usrip;
		struct lnlst *head;

		head = (struct lnlst *)malloc(sizeof(struct lnlst));
		head->data = 0;
		head->next = NULL;

		while (1) {
				printf("1. Add\n");
				printf("2. Delete\n");
				printf("3. Traverse\n");
				printf("4. Show All\n");
				printf("5. Delete All\n");
				printf("6. Exit\n");
				printf("Please enter an option\n");
				scanf("%d", &usrip);
				switch (usrip)
				{
						case 1:
								add_item(head);
								break;

						case 2:
								del_item(head);
								break;

						case 3:
								traverse(head);
								break;

						case 4:
								show_all(head);
								break;

						case 5:
								del_all(head);
								break;

						case 6:
								del_all(head);
								printf ("\nExiting...\n");
								return 0;

						default:
								del_all(head);
								printf ("Hey Ass****! can you not see a list of options provided\n");
								printf ("Get lost... Exiting...\n");
								return 0;
				}
		}
		return 0;
}

int add_item(struct lnlst *head)
{
		int item;
		struct lnlst *trv;
		struct lnlst *newitm;

		trv = head;
		printf ("\nEnter the item you want to add:");
		scanf ("%d", &item);

		while(trv->next != NULL) {
				trv = trv->next;
		}
		newitm = (struct lnlst *)malloc(sizeof(struct lnlst ));
		trv->next = newitm;
		newitm->data = item;
		newitm->next = NULL;
		printf ("New Item had been added...\n");
		return 0;
}

int del_item(struct lnlst *head)
{
		struct lnlst *trv;
		struct lnlst *nxtitm;
		int item;

		trv = head;
		printf ("Enter the item to delete: ");
		scanf ("%d", &item);

		if (trv->next == NULL)
		{
				printf("There are no entries in the list...\n");
				return 0;
		}
		while(trv->next != NULL)
		{
				if (trv->next->data == item)
				{
						nxtitm = trv->next;
						trv->next = nxtitm->next;
						nxtitm->next = NULL;
						free(nxtitm);
						printf ("Item found and deleted!\n");
						return 0;
				}
				trv = trv->next;
		}
		printf ("Item not found...\n");
		return 0;
}

int traverse(struct lnlst *head)
{
		return 0;
}

void show_all(struct lnlst *head)
{
		struct lnlst *trv;
		trv = head;
		if (trv->next == NULL)
		{
				printf("No entries to show...\n");
				return ;
		}
		printf ("*********************************************************************\n");
		printf ("The total list:\t");
		while (trv->next != NULL) {
				/*
				 ** Head is for reference so do not print it
				 */
				trv = trv->next;
				printf ("%d\t", trv->data);
		}
		printf ("\n*********************************************************************\n");
}

void del_all(struct lnlst *head)
{
		struct lnlst *trv;
		struct lnlst *nxtitm;

		printf ("Deleting all entries...\n");
		trv = head;
		if(trv->next == NULL)
		{
				printf ("No entries to delete!\n");
				return;
		}
		while (trv->next != NULL)
		{
				head->next = trv->next->next;
				trv->next = NULL;
				free(trv);
				trv = head;
		}
}

/******************************* END OF PROGRAM *************************************/
