/*
 * restauth.c
 *
 *  Created on: Apr 24, 2012
 *      Author: gabriel
 */

#define USER_PATH "/users/"
#define PASSWORD_PREFIX "password="

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restauth.h"
#include "helpers.h"

void ra_global_init() {
	curl_global_init(CURL_GLOBAL_SSL);
}

RA_CON * ra_init(const char * address, const char * username, const char * password) {
	RA_CON * con = malloc(sizeof(RA_CON));
	con->address = malloc(strlen(address));
	con->username = malloc(strlen(username));
	con->password = malloc(strlen(password));

	strcpy(con->address, address);
	strcpy(con->username, username);
	strcpy(con->password, password);

	return con;
}

void ra_cleanup(RA_CON * con) {
	free(con->address);
	free(con->username);
	free(con->password);
	free(con);
}

int ra_check_server(RA_CON * con) {
	CURL * session = ra_init_curl(con);

}

int ra_auth(const RA_CON * con, const char * user, const char * password) {
	CURL * session = ra_init_curl(con);
	char * address = malloc(strlen(con->address)+strlen(USER_PATH)+strlen(user)+2);
	sprintf(address, "%s%s%s/", con->address, USER_PATH, user);
	curl_easy_setopt(session, CURLOPT_URL, address);
	free(address);

	char * post_data = malloc(strlen(PASSWORD_PREFIX)+strlen(password)+1);
	sprintf(post_data, "%s%s", PASSWORD_PREFIX, password);
	curl_easy_setopt(session, CURLOPT_POSTFIELDS, post_data);

	CURLcode err = curl_easy_perform(session);
	free(post_data);

	if(err != 0) {
		ra_curl_error(err);
		curl_easy_cleanup(session);
		return -1;
	}
	long response;
	curl_easy_getinfo(session, CURLINFO_RESPONSE_CODE, &response);
	curl_easy_cleanup(session);
	switch(response) {
	case 204:
		return 1;
	case 404:
		return 0;
	default:
		ra_error(response);
		return -1;
	}
}
