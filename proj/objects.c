/*
 * Note: this file originally auto-generated by mib2c using
 *        $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <time.h>
#include <sys/utsname.h>
#include "objects.h"


int integer = 100; //r/w integer variable, the default value is 100
int integer_bak; //backup integer variable
int length; //variable for string length computing

/** Initializes the objects module */
void
init_objects(void)
{
    const oid loginString_oid[] = { 1,3,6,1,3,22,1 };
    const oid dateString_oid[] = { 1,3,6,1,3,22,2 };
    const oid integer_oid[] = { 1,3,6,1,3,22,3 };
    const oid sysInfo_oid[] = { 1,3,6,1,3,22,4 };

  DEBUGMSGTL(("objects", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("loginString", handle_loginString,
                               loginString_oid, OID_LENGTH(loginString_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("dateString", handle_dateString,
                               dateString_oid, OID_LENGTH(dateString_oid),
                               HANDLER_CAN_RONLY
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("integer", handle_integer,
                               integer_oid, OID_LENGTH(integer_oid),
                               HANDLER_CAN_RWRITE
        ));
    netsnmp_register_scalar(
        netsnmp_create_handler_registration("sysInfo", handle_sysInfo,
                               sysInfo_oid, OID_LENGTH(sysInfo_oid),
                               HANDLER_CAN_RONLY
        ));
}

int
handle_loginString(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    char login[9] = "xjurka08"; //create an array containing the login string
    switch(reqinfo->mode) {

        case MODE_GET:
	    	
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     /* XXX: a pointer to the scalar's data */login,
                                     /* XXX: the length of the data in bytes */sizeof(login)-1);
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_loginString\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_dateString(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    struct timespec time; //create a structure for date and time
    char buff[25]; //array for the string storage

    switch(reqinfo->mode) {

        case MODE_GET:

		
    
    		timespec_get(&time, TIME_UTC); //get the time and date info
    
    		strftime(buff, sizeof buff, "%FT%TZ", gmtime(&time.tv_sec)); //convert it to the RFC 3339 format

			//compute the length of the date and time string
			length = 0;

    		while(buff[length] != 0x0) //repeat until you find the terminating null char
    		{
        		length++;
    		}

            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     /* XXX: a pointer to the scalar's data */buff,
                                     /* XXX: the length of the data in bytes */length);
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_dateString\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_integer(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    int ret;
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */
    
    switch(reqinfo->mode) {

        case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     /* XXX: a pointer to the scalar's data */&integer,
                                     /* XXX: the length of the data in bytes */sizeof(integer));
            break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
        case MODE_SET_RESERVE1:
                /* or you could use netsnmp_check_vb_type_and_size instead */
            ret = netsnmp_check_vb_type(requests->requestvb, ASN_INTEGER);
            if ( ret != SNMP_ERR_NOERROR ) {
                netsnmp_set_request_error(reqinfo, requests, ret );
            }
            break;

        case MODE_SET_RESERVE2:
            /* XXX malloc "undo" storage buffer */ integer_bak = integer; //backup the integer
            break;

        case MODE_SET_FREE:
            break;

        case MODE_SET_ACTION:
			integer = *(requests->requestvb->val.integer); //load the integer value
            break;

        case MODE_SET_COMMIT:
            break;

        case MODE_SET_UNDO:
			integer = integer_bak; //load the backup
            break;

        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_integer\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
int
handle_sysInfo(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info   *reqinfo,
                          netsnmp_request_info         *requests)
{
    /* We are never called for a GETNEXT if it's registered as a
       "instance", as it's "magically" handled for us.  */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    struct utsname sys; //system info structure
	char string[50]; //string buffer

    switch(reqinfo->mode) {

        case MODE_GET:

		  
    		uname(&sys); //get the system info

			sprintf(string, "Your operating system is %s!", sys.sysname); //load the string buffer with data
			
			//compute the length of the date and time string
			length = 0;

    		while(string[length] != 0x0) //repeat until you find the terminating null char
    		{
        		length++;
    		}
    
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     /* XXX: a pointer to the scalar's data */string,
                                     /* XXX: the length of the data in bytes */length);
            break;


        default:
            /* we should never get here, so this is a really bad error */
            snmp_log(LOG_ERR, "unknown mode (%d) in handle_sysInfo\n", reqinfo->mode );
            return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
