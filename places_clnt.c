#include <memory.h> /* for memset */
#include "places.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

planeListRet *
query_airports_1(position *argp, CLIENT *clnt)
{
	static planeListRet clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, QUERY_AIRPORTS,
		(xdrproc_t) xdr_position, (caddr_t) argp,
		(xdrproc_t) xdr_planeListRet, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
