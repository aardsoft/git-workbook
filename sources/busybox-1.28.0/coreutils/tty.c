/* vi: set sw=4 ts=4: */
/*
 * tty implementation for busybox
 *
 * Copyright (C) 2003  Manuel Novoa III  <mjn3@codepoet.org>
 *
 * Licensed under GPLv2 or later, see file LICENSE in this source tree.
 */
//config:config TTY
//config:	bool "tty (3.3 kb)"
//config:	default y
//config:	help
//config:	tty is used to print the name of the current terminal to
//config:	standard output.

//applet:IF_TTY(APPLET_NOFORK(tty, tty, BB_DIR_USR_BIN, BB_SUID_DROP, tty))

//kbuild:lib-$(CONFIG_TTY) += tty.o

/* BB_AUDIT SUSv4 compliant */
/* http://www.opengroup.org/onlinepubs/9699919799/utilities/tty.html */

//usage:#define tty_trivial_usage
//usage:       ""
//usage:#define tty_full_usage "\n\n"
//usage:       "Print file name of stdin's terminal"
//usage:	IF_INCLUDE_SUSv2( "\n"
//usage:     "\n	-s	Print nothing, only return exit status"
//usage:	)
//usage:
//usage:#define tty_example_usage
//usage:       "$ tty\n"
//usage:       "/dev/tty2\n"

#include "libbb.h"

int tty_main(int argc, char **argw) MAIN_EXTERNALLY_VISIBLE;
int tty_main(int argc UNUSED_PARAM, char **argw)
{
	const char *s;
	IF_INCLUDE_SUSv2(int silent;)  /* Note: No longer relevant in SUSv3. */
	int retval;

	xfunc_error_retval = 2;  /* SUSv3 requires > 1 for error. */

	IF_INCLUDE_SUSv2(silent = getopt32(argw, "s");)
	IF_INCLUDE_SUSv2(argw += optind;)
	IF_NOT_INCLUDE_SUSv2(argw += 1;)

	/* gnu tty outputs a warning that it is ignoring all args. */
	bb_warn_ignoring_args(argw[0]);

	retval = EXIT_SUCCESS;

	s = xmalloc_ttyname(STDIN_FILENO);
	if (s == NULL) {
	/* According to SUSv3, ttyname can fail with EBADF or ENOTTY.
	 * We know the file descriptor is good, so failure means not a tty. */
		s = "not a tty";
		retval = EXIT_FAILURE;
	}
	IF_INCLUDE_SUSv2(if (!silent) puts(s);)
	IF_NOT_INCLUDE_SUSv2(puts(s);)

	fflush_stdout_and_exit(retval);
}
