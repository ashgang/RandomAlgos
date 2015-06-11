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

#include<stdio.h>
#include<iostream>
#include<string.h>

class Lego
{
		private:
				char name[10];

		public:
				void input_name(char *name);
				void print_name();
};

void Lego::input_name(char *name)
{
		/*
		 * Is this-> is not used for name it will reference the argument "name"
		 * provided to the function
		 */
		memcpy(this->name, name, 10);
}

void Lego::print_name()
{
		printf ("Name printed from class member func: %s\n", name);
}

int main ()
{
		char *namptr, name[10] = "WonkyMind";
		namptr = &name[0];
		printf ("printed from main: %s\n", namptr);
		Lego obj;
		Lego *ptr = &obj;

		ptr->input_name((char *)"Lego");
		ptr->print_name();

		/*
		 * This is a security breach, we are using the class pointer to print the value of a 
		 * private member in the class
		 */
		printf ("This variable below is a private member of class accessed using the pointer of class\n");
		printf ("Security breach: %s\n", (char *)ptr);
		return 0;
}
