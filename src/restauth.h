/*
 * restauth.h
 *
 *  Created on: Apr 2, 2012
 *      Author: gabriel
 */

#ifndef RESTAUTH_H_
#define RESTAUTH_H_

struct ra_struct;
typedef struct ra_struct RA_CON;
typedef char ra_bool;

extern int ra_global_init();
extern RA_CON * ra_init(const char *, const char *, const char *);
extern ra_cleanup(RA_CON*);

extern int ra_auth(const RA_CON *, const char *, const char *);
extern int ra_list_users(const RA_CON *, char **);
extern int ra_user_exists(const RA_CON *, const char *);
extern int ra_user_in_group(const RA_CON *, const char *, const char *);
extern int ra_user_get_groups(const RA_CON*, const char *, char **);

extern int ra_create_user(const RA_CON *, const char *);
extern int ra_delete_user(const RA_CON *, const char *);
extern int ra_change_pw(const RA_CON *, const char*, const char*);

extern int ra_get_prop(const RA_CON *, const char *, const char *, char *);
extern int ra_set_prop(const RA_CON *, const char *, const char *, const char *, ra_bool=1);
extern int ra_del_prop(const RA_CON *, const char *, const char *);

extern int ra_list_groups(const RA_CON *, char **);
extern int ra_group_exists(const RA_CON *, const char *);
extern int ra_group_list_groups(const RA_CON *, const char *);
extern int ra_group_list_users(const RA_CON *, const char *);

extern int ra_create_group(const RA_CON *, const char *);
extern int ra_delete_group(const RA_CON *, const char *);
extern int ra_group_add_group(const RA_CON *, const char *, const char *);
extern int ra_group_add_user(const RA_CON *, const char *, const char *);
extern int ra_group_del_group(const RA_CON *, const char *, const char *);
extern int ra_group_del_user(const RA_CON *, const char *, const char *);

#endif /* RESTAUTH_H_ */
