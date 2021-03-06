/* subopt.cpp - subopt */

#include <stdio.h>
#include <winsock.h>

#include "telnet.h"
#include "tnfsm.h"

extern struct fsm_trans	substab[];
extern int		substate;
extern u_char		subfsm[][NCHRS];

/*------------------------------------------------------------------------
 * subopt - do option subnegotiation FSM transitions
 *------------------------------------------------------------------------
 */
int
subopt(SOCKET sfd, FILE *tfp, int c)
{
	struct	fsm_trans	*pt;
	int			ti;

	ti = subfsm[substate][c];
	pt = &substab[ti];
	(pt->ft_action)(sfd, tfp, c);
	substate = pt->ft_next;
	return 0;
}
