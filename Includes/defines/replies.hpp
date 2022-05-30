#pragma once

/*
	 RPL_USERHOST
			":[<reply>{<space><reply>}]"

	- Reply format used by USERHOST to list replies to
		the query list.  The reply string is composed as
		follows:

		<reply> ::= <nick>['*'] '=' <'+'|'-'><hostname>

		The '*' indicates whether the client has registered
		as an Operator.  The '-' or '+' characters represent
		whether the client has set an AWAY message or not
		respectively.
*/
# define RPL_USERHOST 	302

/*
	RPL_ISON
		":[<nick> {<space><nick>}]"

	- Reply format used by ISON to list replies to the
		query list.
*/
# define RPL_ISON 	303

/*
	 RPL_AWAY
		"<nick> :<away message>"
*/
# define RPL_AWAY 	301

/*

*/
# define RPL_NONE 	300

/*

*/
# define RPL_NONE 	300
