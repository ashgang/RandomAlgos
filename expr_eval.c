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
#include <signal.h>

void push_op(char op);
void push_val(int val);
char pop_op();
int pop_val();
void evaluate();
char OpStack[20] = {0};
int ValStack[20] = {0};
int OpStack_capacity = 0;
int ValStack_capacity = 0;

#if 0
void signal_handler (int signal)
{
	printf ("SIGTERM/SIGQUIT received, process ending...\n");
	exit (0);
}
#endif

int main()
{
		int i;
		char exp[50] = {0};
		char cons_num = 0;

		printf ("********************************************************\n");
		printf ("This is exp eval program. Sample expected input:\n");
		printf ("Spaces between values, operators or paranthesis are not\n");
		printf ("tolerated and will result in wrong values\n");
		printf ("((4/2)*((2/1)+(8-2)))\n");
		printf ("********************************************************\n");
		//signal (SIGTERM, signal_handler);
		//signal (SIGQUIT, signal_handler);
		while (1) {
				printf("Enter the expression to be evaluated:\n");
				scanf("%s", exp);
				for(i = 0; exp[i] != '\0'; i++) {
						if((exp[i] >= 48) && (exp[i] <= 57)) {
								if (cons_num > 0) {
										push_val((pop_val() * 10) + (exp[i] - '0'));
								}
								else {
										push_val(exp[i] - '0');
								}
								cons_num++;
						}
						else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
								push_op(exp[i]);
								cons_num = 0;
						}
						else if(exp[i] == ')') {
								evaluate();
								cons_num = 0;
						}
						else {
								/*
								 ** This is illegal input or '(', which is supposed to be ignored
								 */
								cons_num = 0;
						}
				}
				/*
				 ** If the multiple group of exp is left out without final enclosure paranthesis,
				 ** pop out everything one-by-one and calculate it fully to result
				 */
				while (OpStack_capacity > 0) {
						if (ValStack_capacity > 1) {
								evaluate();
						}
						else {
								/*
								 ** Now something is seriously wrong, there are operators but there are not enough 
								 ** values to operate on.  So no point having operators, pop it out
								 */
								printf ("Not enough values! popping out operators!\n");
								while (OpStack_capacity > 0) {
										pop_op();
								}
						}
				}
				printf("Expression Result: %d\n", pop_val());
		}
		return 0;
}

void evaluate()
{
		int a, b, res;
		char c;

		/*
		 ** This is a precaution, not to try to execute with one value only.
		 ** This will lead to popping out the result
		 */
		if (ValStack_capacity < 2) {
				printf ("Not enough values!\n");
				return ;
		}

		a = pop_val();
		b = pop_val();
		c = pop_op();
		switch (c) {
				case '+':
						res = b + a;
						break;

				case '-':
						res = b - a;
						break;

				case '*':
						res = b * a;
						break;

				case '/':
						res = b / a;
						break;

				case 'e':
						printf("Operator Stack empty!\n");
						break;

				default:
						printf("Illegal operator!\n");
						break;
		}
		push_val(res);
}

void push_op(char op)
{
		int i;

		if(OpStack_capacity == 20)
		{
				printf ("Operator Stack full!\n");
				return ;
		}

		for(i = OpStack_capacity; i >= 0; i--)
		{
				OpStack[i+1] = OpStack[i];
		}
		OpStack[0] = op;
		OpStack_capacity++;

		//printf ("New Item had been added...\n");
		return ;
}

void push_val(int val)
{
		int i;

		if(ValStack_capacity == 20)
		{
				printf ("Value Stack full!\n");
				return ;
		}

		for(i = ValStack_capacity; i >= 0; i--)
		{
				ValStack[i+1] = ValStack[i];
		}
		ValStack[0] = val;
		ValStack_capacity++;

		//printf ("New Item had been added...\n");
		return ;
}

char pop_op()
{
		int i;
		char item;

		if (OpStack_capacity == 0)
		{
				printf("There are no entries in the list...\n");
				return 'e';
		}
		item = OpStack[0];
		for(i = 0; i < OpStack_capacity; i++)
		{
				OpStack[i] = OpStack[i+1];
		}
		OpStack_capacity--;
		printf ("Poped Item: %c\n", item);
		return item;
}

int pop_val()
{
		int i, item;

		if (ValStack_capacity == 0)
		{
				printf("There are no entries in the list...\n");
				return 0;
		}
		item = ValStack[0];
		for(i = 0; i < ValStack_capacity; i++)
		{
				ValStack[i] = ValStack[i+1];
		}
		ValStack_capacity--;
		printf ("Poped Item: %d\n", item);
		return item;
}
