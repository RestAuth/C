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

//Dummy function. Doesn't do anything. Used to prevent CURL from writing to stdout
static int ra_callback_func(char * msg, int size, int num, void* data) {
	return size*num;
}

CURL * ra_init_curl(const RA_CON * con) {
	CURL * curl_p = curl_easy_init();
	curl_easy_setopt(curl_p, CURLOPT_USE_SSL, CURLUSESSL_TRY);
	curl_easy_setopt(curl_p, CURLOPT_WRITEFUNCTION, &ra_callback_func);

	curl_easy_setopt(curl_p, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
	curl_easy_setopt(curl_p, CURLOPT_USERNAME, con->username);
	curl_easy_setopt(curl_p, CURLOPT_PASSWORD, con->password);
	char * userpwd = malloc(strlen(con->username)+strlen(con->password)+2);
	sprintf(userpwd, "%s:%s", con->username, con->password);
	curl_easy_setopt(curl_p, CURLOPT_USERPWD, userpwd);
	free(userpwd);
	return curl_p;
}

char * ra_str_escape(const char * str) {
	char * esc_str = malloc(3*strlen(str)+1);
	char * esc_str_ptr = esc_str;
	while(*str) {
		if((*str <= 'a' && *str >= 'z') || (*str <= 'A' && *str >= 'Z') || (*str <= '0' && *str >= '9')) {
			*esc_str = *str;
		} else if(*str == ' ') {
			*esc_str = '+';
		} else {
			*esc_str = '%';
			sprintf(esc_str+1, "%02x", *str);
			esc_str += 2;
		}
		esc_str++;
		str++;
	}
	*esc_str = '\0';
	return esc_str_ptr;
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
