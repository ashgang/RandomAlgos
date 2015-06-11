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
#include<pthread.h>

void th_fn();

int main ()
{
		pthread_t th_id;
		/*
		 ** This is the POSIX API to create a thread
		 */
		pthread_create (&th_id, NULL, (void *)&th_fn, NULL);
		/*
		 ** This will make the main thread wait until the created thread ends
		 ** if the main thread exits before the created thread is run, it will 
		 ** end the other thread too
		 */
		pthread_join(th_id, NULL);
		return 0;
}

void th_fn()
{
		printf ("This is printed from th1\n");
}

