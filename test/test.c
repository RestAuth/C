/*
 * test.c
 *
 *  Created on: Apr 28, 2012
 *      Author: gabriel
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "../src/restauth.h"

#define SRV_ADR "localhost:8000"
#define SRV_USER "vowi"
#define SRV_PWD "vowi"

static RA_CON * glob_con;

static int num_tests = 0;
static int solved_tests = 0;

void testhelper(int (*test)()) {
	printf("===================\n");
	num_tests++;
	printf("Running Test %d\n", num_tests);
	if (test()) {
		printf("Finished Test %d\n", num_tests);
		solved_tests++;
	} else {
		printf("Error in Test %d\n", num_tests);
	}
	printf("===================\n");
}

int cant_login() {
	RA_CON * con = ra_init(SRV_ADR, SRV_USER, "");
	ra_cleanup(con);
}

int correct_user() {
	int returnVal = ra_auth(glob_con, "foo", "barbar");
	if(returnVal == 1)
		return 1;
	if(returnVal == -1)
		printf("Error occured. errno: %s\n", strerror(errno));
	return 0;
}

int incorrect_user() {
	int returnVal = ra_auth(glob_con, "foo", "bur");
	printf("Return value: %d\n", returnVal);
	if(returnVal == 0)
		return 1;
	if(returnVal == -1)
		printf("Error occured. errnor: %s\n", strerror(errno));
	return 0;
}

int user_in_group() {
	int returnVal = ra_user_in_group(glob_con, "foo", "grp");
	if(returnVal == 1)
		return 1;
	if(returnVal == -1)
		printf("Error occured. errno: %s\n", strerror(errno));
	return 0;
}

int main(int argc, char ** argv) {
	ra_global_init();
	glob_con = ra_init(SRV_ADR, SRV_USER, SRV_PWD);

	testhelper(cant_login);
	testhelper(correct_user);
	testhelper(incorrect_user);
	testhelper(user_in_group);

	printf("Solved %d/%d tests.\n", solved_tests, num_tests);
	ra_cleanup(glob_con);
	if(solved_tests < num_tests)
		return 1;
	return 0;
}
