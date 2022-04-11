#ifndef	_singxml_h
#define	_singxml_h

#define	_FORM_XML_DTD	"sing.dtd"
#define	_FORM_XML_CSS	"sing.dtd"
#define	_FORM_XML_XSD	"sing.xsd"
#define	_FORM_XML_XSL	"sing.xsl"

#define	_THREED_XML_DTD	"threed.dtd"
#define	_THREED_XML_CSS	"threed.css"
#define	_THREED_XML_XSD	"threed.xsd"
#define	_THREED_XML_XSL	"threed.xsl"

#define	_DATABASE_DTD	"base.dtd"
#define	_DATABASE_CSS	"base.css"
#define	_DATABASE_XSD	"base.xsd"
#define	_DATABASE_XSL	"base.xsl"

#ifndef	_xmlform_c
extern	char *	xml_form_type;
extern	char *	xml_form_style;
#else
public	char *	xml_form_type=_FORM_XML_DTD;
public 	char *	xml_form_style=_FORM_XML_CSS;
#endif

#ifndef	_xmlthree_c
extern	char *	xml_threed_type;
extern	char *	xml_threed_style;
extern	char *	xml_base_type;
extern	char *	xml_base_style;
#else
public	char *	xml_threed_type=_THREED_XML_DTD;
public char *	xml_threed_style=_THREED_XML_CSS;
public	char *	xml_base_type=_DATABASE_DTD;
public char *	xml_base_style=_DATABASE_CSS;
#endif

#endif 	/* _singxml_h */
	/* ---------- */

