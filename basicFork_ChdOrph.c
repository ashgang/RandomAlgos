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

int main()
{
		int prPID = 0;
		printf ("Entering main function\n");
		/*
		 * NOTE: Fork system call, makes a copy of the parent to the child.
		 * To the parent it returns the childs PID, to the child it returns 0.
		 * So when we check for 0 it means we are in child
		 */
		if ((prPID = fork()) == 0)
		{
				printf ("We are in child\n");
				/*
				 * This sleep here will lead to a scenario where the parent process will end, since there is no wait but the child is still
				 * in sleep.  Since the child has no parent not its orphaned.  The child is adopted by init process, so the PPID of this
				 * child will be 1.  It can be seen in bash with this command "ps -f".  The PPID of child will be seen as 1.
				 */
				sleep (100);
		}
		else
		{
				printf ("We are in parent, child's PID: %d\n", prPID);
		}
		return 0;
}
