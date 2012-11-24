/*
 * helpers.h
 *
 *  Created on: Apr 12, 2012
 *      Author: gabriel
 */

#ifndef HELPERS_H_
#define HELPERS_H_

#include <curl/curl.h>
#include "restauth.h"

CURL * ra_init_curl(const RA_CON *);
size_t ra_curl_read(void * ptr, size_t size, size_t nmemb, void * userdata);
char * ra_str_escape(const char *);
void ra_curl_error(CURLcode);
void ra_error(int);

#endif /* HELPERS_H_ */
