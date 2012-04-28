/*
 * helpers.c
 *
 *  Created on: Apr 28, 2012
 *      Author: gabriel
 */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <curl/curl.h>
#include "helpers.h"

CURL * ra_init_curl(const RA_CON * con) {
	CURL * curl_p = curl_easy_init();
	curl_easy_setopt(curl_p, CURLOPT_USE_SSL, CURLUSESSL_TRY);

	curl_easy_setopt(curl_p, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
	curl_easy_setopt(curl_p, CURLOPT_USERNAME, con->username);
	curl_easy_setopt(curl_p, CURLOPT_PASSWORD, con->password);
	char * userpwd = malloc(strlen(con->username)+strlen(con->password)+1);
	sprintf(userpwd, "%s%s", con->username, con->password);
	curl_easy_setopt(curl_p, CURLOPT_USERPWD, userpwd);
	free(userpwd);
	return curl_p;
}

void ra_curl_error(CURLcode err) {
	switch(err) {
	default:
		errno = ENOKEY;
		break;
	}
}

void ra_error(int code) {
	switch(code) {
	case 400:
		errno = EINVAL;
		break;
	case 401:
		errno = EACCES;
		break;
	case 403:
		errno = EPERM;
		break;
	default:
		errno = ENOKEY;
		break;
	}
}
