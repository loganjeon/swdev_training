/*
 * =====================================================================================
 *
 *       Filename:  simple_project3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2018 17:14:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "simple_project3.h"
#include "libfoo.h"

int main()
{
	printf("%s\n", global_foo);
	display_stuff("I'm printed via a library call.");
	return 0;
}

