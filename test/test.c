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
	num_tests++;
	printf("Running Test %d\n", num_tests);
	if (test())
		solved_tests++;
}

int cant_login() {
	RA_CON * con = ra_init(SRV_ADR, SRV_USER, "");
	ra_cleanup(con);
}

int correct_user() {
	if(ra_auth(glob_con, "foo", "barbar"))
		return 1;
	return 0;
}

int incorrect_user() {
	if(ra_auth(glob_con, "foo", "bur") == 0)
		return 1;
	return 0;
}

int main(int argc, char ** argv) {
	ra_global_init();
	glob_con = ra_init(SRV_ADR, SRV_USER, SRV_PWD);

	testhelper(correct_user);
	testhelper(incorrect_user);

	printf("Solved %d/%d tests.\n", solved_tests, num_tests);
	ra_cleanup(glob_con);
	if(solved_tests < num_tests)
		return 1;
	return 0;
}
