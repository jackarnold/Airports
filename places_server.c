#include "places.h"

planeListRet *
query_airports_1_svc(position *argp, struct svc_req *rqstp)
{
	static planeListRet result;
  //Free memory from last call
  xdr_free((xdrproc_t)xdr_planeListRet, (char*)&result); 
  //Init to nullptr so rpc has stopping point
  result.planeListRet_u.airportList = nullptr;

  //Sever code///////////
 
  //SERVER CODE HERE
	//SERVER CODE HERE
  
  result.err = 12;
  
  //SERVER CODE HERE
	//SERVER CODE HERE
	return &result;
}