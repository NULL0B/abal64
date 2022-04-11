#ifndef	_bdamail_cls
#define _bdamail_cls

;** ------------------------------
;** C L A S S    bdamail_interface
;** ------------------------------
 
#class bdamail_interface

Library "bdamail"

;** content type Parameter First Byte

public const ct_text$="0"
public const ct_byte$="2"
public const ct_jpeg$="3"
public const ct_gif$="4"
public const ct_audio$="5"
public const ct_mpeg$="6"
public const ct_avi$="7"
public const ct_pdf$="8"
public const ct_edi$="E"
public const ct_png$="P"

;** transport encoding second byte

public const tc_7bit$="0"
public const tc_quoted$="1"
public const tc_base64$="2"

;** character set encoding third byte

public const cs_ascii$="0"
public const cs_iso88591$="1"
public const cs_iso88592$="2"
public const cs_iso88593$="3"
public const cs_iso88594$="4"
public const cs_iso88595$="5"
public const cs_iso88596$="6"
public const cs_iso88597$="7"
public const cs_iso88598$="8"
public const cs_iso88599$="9"

public const ft_text#=0
public const ft_binary#=1

public strict user function mail_debug:(a#)

public strict integer user function smtp_connect:(server$, servlen%, sender$, sendlen%)
public strict integer user function smtp_send:(type#, mimefile$, mflen%, dest$, destlen%, cc$, cclen%, notif$, notlen%, notype$, ntlen%)
public strict integer user function smtp_disconnect:
public strict integer user function smtp_reset:

public strict integer user function dns_request:(a$, b%, c$)

public strict integer user function mime_code:(sender$, slen%, receiver$, rlen%, cc$, clen%, subject$, slen%, param$, plen%, content$, ctlen%, body$, blen%, type#, result$, reslen%)
public strict integer user function mime_add:(result$, reslen%, attachment$, alen%, type#, param$, plen%)
public strict integer user function mime_remove:(a$, b%, c$, d%)

public strict integer user function pop3_connect:(a$, b%, c$, d%, e$, f%)
public strict integer user function pop3_box_status:(a%, b%?, c%?)
public strict integer user function pop3_get_msg_buf:(a%, b$, c%?, d%)
public strict integer user function pop3_get_msg:(a%, b$, c%, d%)
public strict integer user function pop3_top_msg:(a%, b$, c%, d%)
public strict integer user function pop3_delete_msg:(a%)
public strict integer user function pop3_reset:
public strict integer user function pop3_disconnect:

public strict integer user function mime_decode:(a$, b%, c$, d%, e$, f%?, g$, h%?, i$, j%?, k$, l%?, m$, n%?, o$, p%?, q%?, r%?)
public strict integer user function mime_attachment_info:(a$, b%, c%, d%?, e%?, f%?, g%?, h$, i%?, j$, k%?)
public strict integer user function mime_extract:(a$, b%, c%, d$, e%, f%?)
public strict integer user function mime_field:(a$, b%, c$, d%, e%, f$, g%?)

public strict user function mail_conf:(a%)

public strict integer user function smtp_connect_with_auth:(server$, servlen%, sender$, sendlen%, username$, userlen%, password$, passlen%, type%)

#endclass bdamail_interface

;** ------------------------------
;** C L A S S    bdamail_client
;** ------------------------------

#class bdamail_client( public bdamail_interface )

private common  dcl     users%
public          dcl     evalue%

public  routine constructor initialise:
        if ( users = 0 )
        endif
        users = users + 1
end

public  routine destructor  terminate:
        if ( users <> 0 )
                users = users - 1
                if ( users = 0 )
                endif
        endif
end

#endclass bdamail_client

#class	bdamail_send( public bdamail_client )

Private	Dcl	sender$=1024
Private	Dcl	target$=1024
Private	Common	filecount%

public	inline constructor initialise:(s$,t$)
	mail_debug(2)
	sender = s
	target = t
end

public	strict function send:( subject$=256, body$=2048, what$=1024 )
	Local dcl err%
	Local dcl fn$=256
	filecount = filecount + 1
	fn = Print(($,$,".txt"),"/tmp/mail",Conv$(filecount))
	err = mime_code(sender,len$(sender),target,len$(target), " ", 0, subject, len$(subject), "011", 3, " ",0, body, len$(body),1, fn, len$(fn))
	err = mime_add(fn, len$(fn), what, len$(what), 0, "011", 3)
	err = smtp_send(1, fn ,len$(fn), target, len$(target) , " ",0, " ",0, " ",0)
end

public	strict function send:( subject$=256, body$=2048 )
	Local dcl err%
	Local dcl fn$=256
	fn = "/tmp/mail.txt"
	err = mime_code(sender,len$(sender),target,len$(target), " ", 0, subject, len$(subject), "011", 3, " ",0, body, len$(body),1, fn, len$(fn))

	err = smtp_send(1, fn ,len$(fn), target, len$(target) , " ",0, " ",0, " ",0)

end

#endclass bdamail_send


#endif  _bdamail_cls

