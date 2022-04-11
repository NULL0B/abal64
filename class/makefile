
# -----------------------------------
# construction of the class libraries
# -----------------------------------
HTTP =  http.as bdanet.cls httph.cls https.cls httpc.cls
INET =  http.as bdanet.cls bdamail.cls httph.cls https.cls httpc.cls

http.apl: $(HTTP)
	otr64 -l http.as 

internet.apl: $(INET)
	otr64 -l internet.as 
	

! make

