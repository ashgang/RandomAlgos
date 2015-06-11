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
#include <string.h>

struct hel {
		char nam[10];
};

struct hello {
		struct hel blah;
		void (*fn_ptr)(char *);
};

void print_userIO_fn(char *);
void tak_fn_ptr(struct hello *);

int main(int argc, char *argv[])
{
		struct hello bh;
		printf ("In Main()\n");
		if(argc > 1)
		{
				printf ("Direct call to print function\n");
				print_userIO_fn(argv[1]);
		}
		else
		{
				memcpy(bh.blah.nam, "WonkyMind", 10);
				/*
				 * This is almost equivalent to registering a callback
				 */
				bh.fn_ptr = print_userIO_fn;
				printf ("Now name will be printed via callback\n");
				tak_fn_ptr(&bh);
#if 0
				printf ("print name: %s\n", bh.blah.nam);
#endif
		}
		return 0;
}

void print_userIO_fn(char *strng)
{
		printf ("In Fn: %s(), User Input: %s\n", __FUNCTION__, strng);
}

void tak_fn_ptr(struct hello *ptr)
{
#if 0
		printf ("print name: %s\n", ptr->blah.nam);
#endif
		ptr->fn_ptr(ptr->blah.nam);
}
