#include <iostream>
#include <stdio.h>

#define OTL_ORA11G_R2
#define OTL_ORA_UTF8
#include <otlv4.h>
using namespace std;
otl_connect oracledb;
void main()
{
	try
	{
		otl_connect::otl_initialize();
		oracledb.rlogon("system/infinitt@mint");
	}
	catch(otl_exception &p)
	{
		//MessageBox(0,"Error",0,0);
		cout<<p.stm_text<<endl;
	}
	oracledb.logoff();
}