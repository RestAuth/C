/*
 * restauth.h
 *
 *  Created on: Apr 2, 2012
 *      Author: gabriel
 */

#ifndef RESTAUTH_H_
#define RESTAUTH_H_

struct ra_struct {
	char * address;
	char * username;
	char * password;
};
typedef struct ra_struct RA_CON;
typedef char ra_bool;

extern void ra_global_init();
extern RA_CON * ra_init(const char * address, const char * username, const char * password);
extern void ra_cleanup(RA_CON*);

extern int ra_auth(const RA_CON *, const char * user, const char * password);
extern int ra_list_users(const RA_CON *, char ** userlist);
extern int ra_user_exists(const RA_CON *, const char * user);
extern int ra_user_in_group(const RA_CON *, const char * user, const char * password);
extern int ra_user_get_groups(const RA_CON*, const char * user, char ** grouplist);

extern int ra_create_user(const RA_CON *, const char * user);
extern int ra_delete_user(const RA_CON *, const char * user);
extern int ra_change_pw(const RA_CON *, const char* user, const char* password);

extern int ra_get_prop(const RA_CON *, const char * user, const char * prop, char * data);
extern int ra_set_prop(const RA_CON *, const char * user, const char * prop, const char * data, ra_bool overwrite);
extern int ra_del_prop(const RA_CON *, const char * user, const char * prop);

extern int ra_list_groups(const RA_CON *, char ** grouplist);
extern int ra_group_exists(const RA_CON *, const char * group);
extern int ra_group_list_groups(const RA_CON *, const char * group, char ** grouplist);
extern int ra_group_list_users(const RA_CON *, const char * group, char ** userlist);

extern int ra_create_group(const RA_CON *, const char * group);
extern int ra_delete_group(const RA_CON *, const char * group);
extern int ra_group_add_group(const RA_CON *, const char * p_group, const char * group);
extern int ra_group_add_user(const RA_CON *, const char * group, const char * user);
extern int ra_group_del_group(const RA_CON *, const char * p_group, const char * group);
extern int ra_group_del_user(const RA_CON *, const char * group, const char * user);

#endif /* RESTAUTH_H_ */
