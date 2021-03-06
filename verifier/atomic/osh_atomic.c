/*
 * Copyright (c) 2014      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */
#include "osh_def.h"
#include "osh_cmn.h"
#include "osh_log.h"

#include "osh_tests.h"
#include "osh_atomic_tests.h"

const TE_NODE atomic_tcs[] =
{
    { NULL, osh_atomic_tc1,  "int_swap",       aopt_set_string( "tc1" ), 	"shmem_int_swap(): A simple test.",        TEST_RUN},
    { NULL, osh_atomic_tc2,  "long_swap",      aopt_set_string( "tc2" ), 	"shmem_long_swap(): A simple test.",       TEST_RUN},
    { NULL, osh_atomic_tc3,  "swap",           aopt_set_string( "tc3" ), 	"shmem_swap(): A simple test.",            TEST_RUN},
    { NULL, osh_atomic_tc4,  "longlong_swap",  aopt_set_string( "tc4" ), 	"shmem_longlong_swap(): A simple test.",   TEST_RUN},
    { NULL, osh_atomic_tc5,  "float_swap",     aopt_set_string( "tc5" ), 	"shmem_float_swap(): A simple test.",      TEST_RUN},
    { NULL, osh_atomic_tc6,  "double_swap",    aopt_set_string( "tc6" ), 	"shmem_double_swap(): A simple test.",     TEST_RUN},
    { NULL, osh_atomic_tc7,  "int_cswap",      aopt_set_string( "tc7" ), 	"shmem_int_cswap(): A simple test.",       TEST_RUN},
    { NULL, osh_atomic_tc8,  "long_cswap",     aopt_set_string( "tc8" ), 	"shmem_long_cswap(): A simple test.",      TEST_RUN},
    { NULL, osh_atomic_tc9,  "longlong_cswap", aopt_set_string( "tc9" ), 	"shmem_longlong_cswap(): A simple test.",  TEST_RUN},
    { NULL, osh_atomic_tc10, "int_fadd",       aopt_set_string( "tc10" ), 	"shmem_int_fadd(): A simple test.",        TEST_RUN},
    { NULL, osh_atomic_tc11, "long_fadd",      aopt_set_string( "tc11" ), 	"shmem_long_fadd(): A simple test.",       TEST_RUN},
    { NULL, osh_atomic_tc12, "longlong_fadd",  aopt_set_string( "tc12" ), 	"shmem_longlong_fadd(): A simple test.",   TEST_RUN},
    { NULL, osh_atomic_tc13, "int_finc",       aopt_set_string( "tc13" ), 	"shmem_int_finc(): A simple test.",        TEST_RUN},
    { NULL, osh_atomic_tc14, "long_finc",      aopt_set_string( "tc14" ), 	"shmem_long_finc(): A simple test.",       TEST_RUN},
    { NULL, osh_atomic_tc15, "longlong_finc",  aopt_set_string( "tc15" ), 	"shmem_longlong_finc(): A simple test.",   TEST_RUN},
    { NULL, osh_atomic_tc16, "int_add",        aopt_set_string( "tc16" ), 	"shmem_int_add(): A simple test.",         TEST_RUN},
    { NULL, osh_atomic_tc17, "long_add",       aopt_set_string( "tc17" ), 	"shmem_long_add(): A simple test.",        TEST_RUN},
    { NULL, osh_atomic_tc18, "longlong_add",   aopt_set_string( "tc18" ), 	"shmem_longlong_add(): A simple test.",    TEST_RUN},
    { NULL, osh_atomic_tc19, "int_inc",        aopt_set_string( "tc19" ), 	"shmem_int_inc(): A simple test.",         TEST_RUN},
    { NULL, osh_atomic_tc20, "long_inc",       aopt_set_string( "tc20" ), 	"shmem_long_inc(): A simple test.",        TEST_RUN},
    { NULL, osh_atomic_tc21, "longlong_inc",   aopt_set_string( "tc21" ), 	"shmem_longlong_inc(): A simple test.",    TEST_RUN},
    { NULL, osh_atomic_tc22, "stress",         aopt_set_string( "tc22" ), 	"Atomic stress test.",                     TEST_RUN},
    { NULL, NULL,            NULL,	            aopt_set_string( NULL ),      NULL, TEST_IGNORE}
};


/*
 * List of supported test case options.
 */
static const AOPT_DESC  self_opt_desc[] =
{
	{ 0, AOPT_NOARG, aopt_set_literal( 0 ), aopt_set_string( NULL ), NULL }
};


int proc_tst_atomic( const TE_NODE *node, int argc, const char **argv )
{
    OSH_ERROR status = OSH_ERR_NONE;
	const AOPT_OBJECT* self_opt_obj = NULL;

    UNREFERENCED_PARAMETER(argc);

    if (!node)
    {
        return OSH_ERR_FATAL;
    }

	/* Load supported option and create option objects */
	{
		int temp_argc = 0;

		temp_argc = argc;
		self_opt_obj = aopt_init(&temp_argc, (const char **)argv, self_opt_desc);
        if (!self_opt_obj)
        {
            status = OSH_ERR_FATAL;
        }
    }

	if (!status && self_opt_obj) 
    {
        /* Parse specific options */
    }

	if (status) 
    {
        /* Display help information */
	    const char* help_str = NULL;
	    char temp_buf[30];

		log_help("%s: %s\n", display_opt(node, temp_buf, sizeof(temp_buf)), node->note);
		log_help("\n");
		log_help("Valid arguments:\n");
		help_str = aopt_help(self_opt_desc);
	    if (help_str)
	    {
	        log_help("%s", help_str);
	        sys_free((void*)help_str);
		    log_help("\n");
	    }
	}

	/* Destroy option objects */
	aopt_exit((AOPT_OBJECT*)self_opt_obj);

    return status;
}
