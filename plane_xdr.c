#include "plane.h"

bool_t
xdr_hostName (XDR *xdrs, hostName *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXLEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_placeName (XDR *xdrs, placeName *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXLEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_stateName (XDR *xdrs, stateName *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, MAXLEN))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_location (XDR *xdrs, location *objp)
{
	register int32_t *buf;

	 if (!xdr_hostName (xdrs, &objp->host))
		 return FALSE;
	 if (!xdr_placeName (xdrs, &objp->place))
		 return FALSE;
	 if (!xdr_stateName (xdrs, &objp->state))
		 return FALSE;
	return TRUE;
}