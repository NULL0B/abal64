
#class bdanet_interface

Library	"bdanet"

public	const raw%=0
public	const tcp%=1
public	const udp%=2
public	const tls%=5

public	strict integer user function HttpInitialise:(p$,l%)
public  strict integer user function HttpLiberate:
public  strict integer user function HttpOpenServer:(port%,mode%)
public  strict integer user function HttpOpenClient:(url$,length%,mode%)
public  strict integer user function HttpClose:(handle%,mode%)
public  strict integer user function HttpAccept:(handle%,timeout%)
public  strict integer user function HttpCommand:(handle%,m$,length%)
public  strict integer user function HttpGet:(handle%,buffer$?,length%)
public  strict integer user function HttpPut:(handle%,buffer$,length%)
public  strict integer user function HttpGetLine:(handle%,buffer$?,length%)
public  strict integer user function HttpPutLine:(handle%,buffer$,length%)
public  strict integer user function HttpAddress:(handle%,buffer$?,length%)
public  strict integer user function HttpSetConversion:(handle%)
public  strict integer user function HttpTranscode:(handle%)
public  strict integer user function HttpSetHost:(handle%,buffer$,length%)
public  strict integer user function HttpSetType:(buffer$,length%)
public  strict integer user function HttpPost:(handle%,buffer$,length%)
public  strict integer user function Reserved:
public  strict integer user function HttpAuthorise:(buffer$,length%)
public  strict integer user function HttpProxyAuthorise:(buffer$,length%)
public  strict integer user function HttpCryptage:(handle%,buffer$,length%,x%)
public  strict integer user function HttpGetError:
public  strict integer user function HttpGetVersion:
public  strict integer user function HttpEncodeBase64:(buffer$?,other$,length%)
public  strict integer user function HttpDecodeBase64:(buffer$?,other$,length%)
public  strict integer user function HttpResponse:(handle%,retcode%,message$,length%)
public  strict integer user function HttpFile:(handle%,buffer$,length%,type%)
public  strict integer user function HttpSelect:(handle%,timeout%)
public  strict integer user function HttpConfigure:(buffer$,length%)
public  strict integer user function HttpLoadTable:(buffer$,length%)
public  strict integer user function HttpReadTable:(buffer$,length%)
public  strict integer user function HttpGetFile:(handle%,filename$,length%,hi%,lo%)
public  strict integer user function HttpSize:(filename$,a%,b%,buffer$?)
public  strict integer user function HttpLength:(handle%,buffer$,length%)
public  strict integer user function HttpHeader:(handle%,buffer$,length%)
public  strict integer user function HttpDuplicate:(handle%)
public  strict integer user function HttpSecurity:(mode%,key$,cert$,auth$,pass$)

#endclass bdanet_interface

#class bdanet_client( public bdanet_interface )

private	common 	dcl	users%
public		dcl	evalue%	

public	routine	constructor initialise:
	if ( users = 0 )
		evalue = HttpInitialise(" ",0)
	endif
	users = users + 1
end

public	routine	destructor  terminate:
	if ( users <> 0 )
		users = users - 1
		if ( users = 0 )
			evalue = HttpLiberate
		endif
	endif
end

#endclass bdanet_client


