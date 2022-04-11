
#ifndef _vgridlock_c
#define _vgridlock_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vgridlock.xml                                            */
/* Target         : vgridlock.c                                              */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vframe.h"
#define en__Auto3562   ""
#define fr__Auto3562   ""
#define it__Auto3562   ""
#define es__Auto3562   ""
#define de__Auto3562   ""
#define nl__Auto3562   ""
#define pt__Auto3562   ""
#define xx__Auto3562   ""
#define en_Auto3563   "Widget Gridlock Parameters"
#define fr_Auto3563   "Alignement des Widgets"
#define it_Auto3563   "Widget Gridlock Parameters"
#define es_Auto3563   "Widget Gridlock Parameters"
#define de_Auto3563   "Widget Gridlock Parameters"
#define nl_Auto3563   "Widget Gridlock Parameters"
#define pt_Auto3563   "Widget Gridlock Parameters"
#define xx_Auto3563   "Widget Gridlock Parameters"
#define en__Auto3563   ""
#define fr__Auto3563   ""
#define it__Auto3563   ""
#define es__Auto3563   ""
#define de__Auto3563   ""
#define nl__Auto3563   ""
#define pt__Auto3563   ""
#define xx__Auto3563   ""
#define en_Auto3564   "Forms editor widget font/grid lock configuration"
#define fr_Auto3564   "Configuration de l'alignement automatique des widgets"
#define it_Auto3564   "Forms editor widget font/grid lock configuration"
#define es_Auto3564   "Forms editor widget font/grid lock configuration"
#define de_Auto3564   "Forms editor widget font/grid lock configuration"
#define nl_Auto3564   "Forms editor widget font/grid lock configuration"
#define pt_Auto3564   "Forms editor widget font/grid lock configuration"
#define xx_Auto3564   "Forms editor widget font/grid lock configuration"
#define en__Auto3564   ""
#define fr__Auto3564   ""
#define it__Auto3564   ""
#define es__Auto3564   ""
#define de__Auto3564   ""
#define nl__Auto3564   ""
#define pt__Auto3564   ""
#define xx__Auto3564   ""
#define en_wfill   "0|1|2|3|4|5|7|8"
#define fr_wfill   "0|1|2|3|4|5|7|8"
#define it_wfill   "0|1|2|3|4|5|7|8"
#define es_wfill   "0|1|2|3|4|5|7|8"
#define de_wfill   "0|1|2|3|4|5|7|8"
#define nl_wfill   "0|1|2|3|4|5|7|8"
#define pt_wfill   "0|1|2|3|4|5|7|8"
#define xx_wfill   "0|1|2|3|4|5|7|8"
#define en__wfill   ""
#define fr__wfill   ""
#define it__wfill   ""
#define es__wfill   ""
#define de__wfill   ""
#define nl__wfill   ""
#define pt__wfill   ""
#define xx__wfill   ""
#define en_cfill   "Fill"
#define fr_cfill   "Fill"
#define it_cfill   "Fill"
#define es_cfill   "Fill"
#define de_cfill   "Fill"
#define nl_cfill   "Fill"
#define pt_cfill   "Fill"
#define xx_cfill   "Fill"
#define en__cfill   ""
#define fr__cfill   ""
#define it__cfill   ""
#define es__cfill   ""
#define de__cfill   ""
#define nl__cfill   ""
#define pt__cfill   ""
#define xx__cfill   ""
#define en_woutset   "0|1|2|3|4|5|7|8"
#define fr_woutset   "0|1|2|3|4|5|7|8"
#define it_woutset   "0|1|2|3|4|5|7|8"
#define es_woutset   "0|1|2|3|4|5|7|8"
#define de_woutset   "0|1|2|3|4|5|7|8"
#define nl_woutset   "0|1|2|3|4|5|7|8"
#define pt_woutset   "0|1|2|3|4|5|7|8"
#define xx_woutset   "0|1|2|3|4|5|7|8"
#define en__woutset   ""
#define fr__woutset   ""
#define it__woutset   ""
#define es__woutset   ""
#define de__woutset   ""
#define nl__woutset   ""
#define pt__woutset   ""
#define xx__woutset   ""
#define en_coutset   "Outset Frame"
#define fr_coutset   "Outset Frame"
#define it_coutset   "Outset Frame"
#define es_coutset   "Outset Frame"
#define de_coutset   "Outset Frame"
#define nl_coutset   "Outset Frame"
#define pt_coutset   "Outset Frame"
#define xx_coutset   "Outset Frame"
#define en__coutset   ""
#define fr__coutset   ""
#define it__coutset   ""
#define es__coutset   ""
#define de__coutset   ""
#define nl__coutset   ""
#define pt__coutset   ""
#define xx__coutset   ""
#define en_winset   "0|1|2|3|4|5|7|8"
#define fr_winset   "0|1|2|3|4|5|7|8"
#define it_winset   "0|1|2|3|4|5|7|8"
#define es_winset   "0|1|2|3|4|5|7|8"
#define de_winset   "0|1|2|3|4|5|7|8"
#define nl_winset   "0|1|2|3|4|5|7|8"
#define pt_winset   "0|1|2|3|4|5|7|8"
#define xx_winset   "0|1|2|3|4|5|7|8"
#define en__winset   ""
#define fr__winset   ""
#define it__winset   ""
#define es__winset   ""
#define de__winset   ""
#define nl__winset   ""
#define pt__winset   ""
#define xx__winset   ""
#define en_cinset   "Inset Frame"
#define fr_cinset   "Inset Frame"
#define it_cinset   "Inset Frame"
#define es_cinset   "Inset Frame"
#define de_cinset   "Inset Frame"
#define nl_cinset   "Inset Frame"
#define pt_cinset   "Inset Frame"
#define xx_cinset   "Inset Frame"
#define en__cinset   ""
#define fr__cinset   ""
#define it__cinset   ""
#define es__cinset   ""
#define de__cinset   ""
#define nl__cinset   ""
#define pt__cinset   ""
#define xx__cinset   ""
#define en_wridge   "0|2|4|8|16"
#define fr_wridge   "0|2|4|8|16"
#define it_wridge   "0|2|4|8|16"
#define es_wridge   "0|2|4|8|16"
#define de_wridge   "0|2|4|8|16"
#define nl_wridge   "0|2|4|8|16"
#define pt_wridge   "0|2|4|8|16"
#define xx_wridge   "0|2|4|8|16"
#define en__wridge   ""
#define en_cridge   "Ridge Frame"
#define fr_cridge   "Ridge Frame"
#define it_cridge   "Ridge Frame"
#define es_cridge   "Ridge Frame"
#define de_cridge   "Ridge Frame"
#define nl_cridge   "Ridge Frame"
#define pt_cridge   "Ridge Frame"
#define xx_cridge   "Ridge Frame"
#define en__cridge   ""
#define en_wgroove   "0|1|2|3|4|5|7|8"
#define fr_wgroove   "0|1|2|3|4|5|7|8"
#define it_wgroove   "0|1|2|3|4|5|7|8"
#define es_wgroove   "0|1|2|3|4|5|7|8"
#define de_wgroove   "0|1|2|3|4|5|7|8"
#define nl_wgroove   "0|1|2|3|4|5|7|8"
#define pt_wgroove   "0|1|2|3|4|5|7|8"
#define xx_wgroove   "0|1|2|3|4|5|7|8"
#define en__wgroove   ""
#define fr__wgroove   ""
#define it__wgroove   ""
#define es__wgroove   ""
#define de__wgroove   ""
#define nl__wgroove   ""
#define pt__wgroove   ""
#define xx__wgroove   ""
#define en_cgroove   "Groove Frame"
#define fr_cgroove   "Groove Frame"
#define it_cgroove   "Groove Frame"
#define es_cgroove   "Groove Frame"
#define de_cgroove   "Groove Frame"
#define nl_cgroove   "Groove Frame"
#define pt_cgroove   "Groove Frame"
#define xx_cgroove   "Groove Frame"
#define en__cgroove   ""
#define en_wedit   "0|1|2|3|4|5|7|8"
#define fr_wedit   "0|1|2|3|4|5|7|8"
#define it_wedit   "0|1|2|3|4|5|7|8"
#define es_wedit   "0|1|2|3|4|5|7|8"
#define de_wedit   "0|1|2|3|4|5|7|8"
#define nl_wedit   "0|1|2|3|4|5|7|8"
#define pt_wedit   "0|1|2|3|4|5|7|8"
#define xx_wedit   "0|1|2|3|4|5|7|8"
#define en__wedit   ""
#define fr__wedit   ""
#define it__wedit   ""
#define es__wedit   ""
#define de__wedit   ""
#define nl__wedit   ""
#define pt__wedit   ""
#define xx__wedit   ""
#define en_cedit   "Edit"
#define fr_cedit   "Edit"
#define it_cedit   "&Edit"
#define es_cedit   "&Edit"
#define de_cedit   "&Edit"
#define nl_cedit   "&Edit"
#define pt_cedit   "&Edit"
#define xx_cedit   "&Edit"
#define en__cedit   ""
#define fr__cedit   ""
#define it__cedit   ""
#define es__cedit   ""
#define de__cedit   ""
#define nl__cedit   ""
#define pt__cedit   ""
#define xx__cedit   ""
#define en_wtext   "0|1|2|3|4|5|7|8"
#define fr_wtext   "0|1|2|3|4|5|7|8"
#define it_wtext   "0|1|2|3|4|5|7|8"
#define es_wtext   "0|1|2|3|4|5|7|8"
#define de_wtext   "0|1|2|3|4|5|7|8"
#define nl_wtext   "0|1|2|3|4|5|7|8"
#define pt_wtext   "0|1|2|3|4|5|7|8"
#define xx_wtext   "0|1|2|3|4|5|7|8"
#define en__wtext   ""
#define fr__wtext   ""
#define it__wtext   ""
#define es__wtext   ""
#define de__wtext   ""
#define nl__wtext   ""
#define pt__wtext   ""
#define xx__wtext   ""
#define en_ctext   "Text"
#define fr_ctext   "Text"
#define it_ctext   "Text"
#define es_ctext   "Text"
#define de_ctext   "Text"
#define nl_ctext   "Text"
#define pt_ctext   "Text"
#define xx_ctext   "Text"
#define en__ctext   ""
#define en_wimage   "0|1|2|3|4|5|7|8"
#define fr_wimage   "0|1|2|3|4|5|7|8"
#define it_wimage   "0|1|2|3|4|5|7|8"
#define es_wimage   "0|1|2|3|4|5|7|8"
#define de_wimage   "0|1|2|3|4|5|7|8"
#define nl_wimage   "0|1|2|3|4|5|7|8"
#define pt_wimage   "0|1|2|3|4|5|7|8"
#define xx_wimage   "0|1|2|3|4|5|7|8"
#define en__wimage   ""
#define fr__wimage   ""
#define it__wimage   ""
#define es__wimage   ""
#define de__wimage   ""
#define nl__wimage   ""
#define pt__wimage   ""
#define xx__wimage   ""
#define en_cimage   "Image"
#define fr_cimage   "Image"
#define it_cimage   "Image"
#define es_cimage   "Image"
#define de_cimage   "Image"
#define nl_cimage   "Image"
#define pt_cimage   "Image"
#define xx_cimage   "Image"
#define en__cimage   ""
#define en_wline   "0|1|2|3|4|5|7|8"
#define fr_wline   "0|1|2|3|4|5|7|8"
#define it_wline   "0|1|2|3|4|5|7|8"
#define es_wline   "0|1|2|3|4|5|7|8"
#define de_wline   "0|1|2|3|4|5|7|8"
#define nl_wline   "0|1|2|3|4|5|7|8"
#define pt_wline   "0|1|2|3|4|5|7|8"
#define xx_wline   "0|1|2|3|4|5|7|8"
#define en__wline   ""
#define fr__wline   ""
#define it__wline   ""
#define es__wline   ""
#define de__wline   ""
#define nl__wline   ""
#define pt__wline   ""
#define xx__wline   ""
#define en_cline   "Line"
#define fr_cline   "Line"
#define it_cline   "Line"
#define es_cline   "Line"
#define de_cline   "Line"
#define nl_cline   "Line"
#define pt_cline   "Line"
#define xx_cline   "Line"
#define en__cline   ""
#define en_wpush   "0|1|2|3|4|5|7|8"
#define fr_wpush   "0|1|2|3|4|5|7|8"
#define it_wpush   "0|1|2|3|4|5|7|8"
#define es_wpush   "0|1|2|3|4|5|7|8"
#define de_wpush   "0|1|2|3|4|5|7|8"
#define nl_wpush   "0|1|2|3|4|5|7|8"
#define pt_wpush   "0|1|2|3|4|5|7|8"
#define xx_wpush   "0|1|2|3|4|5|7|8"
#define en__wpush   ""
#define fr__wpush   ""
#define it__wpush   ""
#define es__wpush   ""
#define de__wpush   ""
#define nl__wpush   ""
#define pt__wpush   ""
#define xx__wpush   ""
#define en_cpush   "Push Button"
#define fr_cpush   "Push Button"
#define it_cpush   "Push Button"
#define es_cpush   "Push Button"
#define de_cpush   "Push Button"
#define nl_cpush   "Push Button"
#define pt_cpush   "Push Button"
#define xx_cpush   "Push Button"
#define en__cpush   ""
#define en_wwindow   "0|1|2|3|4|5|7|8"
#define fr_wwindow   "0|1|2|3|4|5|7|8"
#define it_wwindow   "0|1|2|3|4|5|7|8"
#define es_wwindow   "0|1|2|3|4|5|7|8"
#define de_wwindow   "0|1|2|3|4|5|7|8"
#define nl_wwindow   "0|1|2|3|4|5|7|8"
#define pt_wwindow   "0|1|2|3|4|5|7|8"
#define xx_wwindow   "0|1|2|3|4|5|7|8"
#define en__wwindow   ""
#define fr__wwindow   ""
#define it__wwindow   ""
#define es__wwindow   ""
#define de__wwindow   ""
#define nl__wwindow   ""
#define pt__wwindow   ""
#define xx__wwindow   ""
#define en_cwindow   "Window"
#define fr_cwindow   "Window"
#define it_cwindow   "Window"
#define es_cwindow   "Window"
#define de_cwindow   "Window"
#define nl_cwindow   "Window"
#define pt_cwindow   "Window"
#define xx_cwindow   "Window"
#define en__cwindow   ""
#define en_wtab   "0|1|2|3|4|5|7|8"
#define fr_wtab   "0|1|2|3|4|5|7|8"
#define it_wtab   "0|1|2|3|4|5|7|8"
#define es_wtab   "0|1|2|3|4|5|7|8"
#define de_wtab   "0|1|2|3|4|5|7|8"
#define nl_wtab   "0|1|2|3|4|5|7|8"
#define pt_wtab   "0|1|2|3|4|5|7|8"
#define xx_wtab   "0|1|2|3|4|5|7|8"
#define en__wtab   ""
#define fr__wtab   ""
#define it__wtab   ""
#define es__wtab   ""
#define de__wtab   ""
#define nl__wtab   ""
#define pt__wtab   ""
#define xx__wtab   ""
#define en_ctab   "Tabpage"
#define fr_ctab   "Tabpage"
#define it_ctab   "Tabpage"
#define es_ctab   "Tabpage"
#define de_ctab   "Tabpage"
#define nl_ctab   "Tabpage"
#define pt_ctab   "Tabpage"
#define xx_ctab   "Tabpage"
#define en__ctab   ""
#define en_wcheck   "0|1|2|3|4|5|7|8"
#define fr_wcheck   "0|1|2|3|4|5|7|8"
#define it_wcheck   "0|1|2|3|4|5|7|8"
#define es_wcheck   "0|1|2|3|4|5|7|8"
#define de_wcheck   "0|1|2|3|4|5|7|8"
#define nl_wcheck   "0|1|2|3|4|5|7|8"
#define pt_wcheck   "0|1|2|3|4|5|7|8"
#define xx_wcheck   "0|1|2|3|4|5|7|8"
#define en__wcheck   ""
#define fr__wcheck   ""
#define it__wcheck   ""
#define es__wcheck   ""
#define de__wcheck   ""
#define nl__wcheck   ""
#define pt__wcheck   ""
#define xx__wcheck   ""
#define en_ccheck   "Check Box"
#define fr_ccheck   "Check Box"
#define it_ccheck   "Check Box"
#define es_ccheck   "Check Box"
#define de_ccheck   "Check Box"
#define nl_ccheck   "Check Box"
#define pt_ccheck   "Check Box"
#define xx_ccheck   "Check Box"
#define en__ccheck   ""
#define en_wradio   "0|2|4|8|16"
#define fr_wradio   "0|2|4|8|16"
#define it_wradio   "0|2|4|8|16"
#define es_wradio   "0|2|4|8|16"
#define de_wradio   "0|2|4|8|16"
#define nl_wradio   "0|2|4|8|16"
#define pt_wradio   "0|2|4|8|16"
#define xx_wradio   "0|2|4|8|16"
#define en__wradio   ""
#define fr__wradio   ""
#define it__wradio   ""
#define es__wradio   ""
#define de__wradio   ""
#define nl__wradio   ""
#define pt__wradio   ""
#define xx__wradio   ""
#define en_cradio   "Radio Button"
#define fr_cradio   "Radio Button"
#define it_cradio   "Radio Button"
#define es_cradio   "Radio Button"
#define de_cradio   "Radio Button"
#define nl_cradio   "Radio Button"
#define pt_cradio   "Radio Button"
#define xx_cradio   "Radio Button"
#define en__cradio   ""
#define en_wselect   "0|1|2|3|4|5|7|8"
#define fr_wselect   "0|1|2|3|4|5|7|8"
#define it_wselect   "0|1|2|3|4|5|7|8"
#define es_wselect   "0|1|2|3|4|5|7|8"
#define de_wselect   "0|1|2|3|4|5|7|8"
#define nl_wselect   "0|1|2|3|4|5|7|8"
#define pt_wselect   "0|1|2|3|4|5|7|8"
#define xx_wselect   "0|1|2|3|4|5|7|8"
#define en__wselect   ""
#define fr__wselect   ""
#define it__wselect   ""
#define es__wselect   ""
#define de__wselect   ""
#define nl__wselect   ""
#define pt__wselect   ""
#define xx__wselect   ""
#define en_cselect   "Select"
#define fr_cselect   "Select"
#define it_cselect   "&Select"
#define es_cselect   "&Select"
#define de_cselect   "&Select"
#define nl_cselect   "&Select"
#define pt_cselect   "&Select"
#define xx_cselect   "&Select"
#define en__cselect   ""
#define fr__cselect   ""
#define it__cselect   ""
#define es__cselect   ""
#define de__cselect   ""
#define nl__cselect   ""
#define pt__cselect   ""
#define xx__cselect   ""
#define en_wtable   "0|1|2|3|4|5|7|8"
#define fr_wtable   "0|1|2|3|4|5|7|8"
#define it_wtable   "0|1|2|3|4|5|7|8"
#define es_wtable   "0|1|2|3|4|5|7|8"
#define de_wtable   "0|1|2|3|4|5|7|8"
#define nl_wtable   "0|1|2|3|4|5|7|8"
#define pt_wtable   "0|1|2|3|4|5|7|8"
#define xx_wtable   "0|1|2|3|4|5|7|8"
#define en__wtable   ""
#define fr__wtable   ""
#define it__wtable   ""
#define es__wtable   ""
#define de__wtable   ""
#define nl__wtable   ""
#define pt__wtable   ""
#define xx__wtable   ""
#define en_ctable   "Table"
#define fr_ctable   "Table"
#define it_ctable   "Table"
#define es_ctable   "Table"
#define de_ctable   "Table"
#define nl_ctable   "Table"
#define pt_ctable   "Table"
#define xx_ctable   "Table"
#define en__ctable   ""
#define en_wscroll   "0|1|2|3|4|5|7|8"
#define fr_wscroll   "0|1|2|3|4|5|7|8"
#define it_wscroll   "0|1|2|3|4|5|7|8"
#define es_wscroll   "0|1|2|3|4|5|7|8"
#define de_wscroll   "0|1|2|3|4|5|7|8"
#define nl_wscroll   "0|1|2|3|4|5|7|8"
#define pt_wscroll   "0|1|2|3|4|5|7|8"
#define xx_wscroll   "0|1|2|3|4|5|7|8"
#define en__wscroll   ""
#define fr__wscroll   ""
#define it__wscroll   ""
#define es__wscroll   ""
#define de__wscroll   ""
#define nl__wscroll   ""
#define pt__wscroll   ""
#define xx__wscroll   ""
#define en_cscroll   "Scroll Bar"
#define fr_cscroll   "Scroll Bar"
#define it_cscroll   "Scroll Bar"
#define es_cscroll   "Scroll Bar"
#define de_cscroll   "Scroll Bar"
#define nl_cscroll   "Scroll Bar"
#define pt_cscroll   "Scroll Bar"
#define xx_cscroll   "Scroll Bar"
#define en__cscroll   ""
#define en_wprogress   "0|1|2|3|4|5|7|8"
#define fr_wprogress   "0|1|2|3|4|5|7|8"
#define it_wprogress   "0|1|2|3|4|5|7|8"
#define es_wprogress   "0|1|2|3|4|5|7|8"
#define de_wprogress   "0|1|2|3|4|5|7|8"
#define nl_wprogress   "0|1|2|3|4|5|7|8"
#define pt_wprogress   "0|1|2|3|4|5|7|8"
#define xx_wprogress   "0|1|2|3|4|5|7|8"
#define en__wprogress   ""
#define fr__wprogress   ""
#define it__wprogress   ""
#define es__wprogress   ""
#define de__wprogress   ""
#define nl__wprogress   ""
#define pt__wprogress   ""
#define xx__wprogress   ""
#define en_cprogress   "Progress Bar"
#define fr_cprogress   "Progress Bar"
#define it_cprogress   "Progress Bar"
#define es_cprogress   "Progress Bar"
#define de_cprogress   "Progress Bar"
#define nl_cprogress   "Progress Bar"
#define pt_cprogress   "Progress Bar"
#define xx_cprogress   "Progress Bar"
#define en__cprogress   ""
#define en_wswitch   "0|1|2|3|4|5|7|8"
#define fr_wswitch   "0|1|2|3|4|5|7|8"
#define it_wswitch   "0|1|2|3|4|5|7|8"
#define es_wswitch   "0|1|2|3|4|5|7|8"
#define de_wswitch   "0|1|2|3|4|5|7|8"
#define nl_wswitch   "0|1|2|3|4|5|7|8"
#define pt_wswitch   "0|1|2|3|4|5|7|8"
#define xx_wswitch   "0|1|2|3|4|5|7|8"
#define en__wswitch   ""
#define fr__wswitch   ""
#define it__wswitch   ""
#define es__wswitch   ""
#define de__wswitch   ""
#define nl__wswitch   ""
#define pt__wswitch   ""
#define xx__wswitch   ""
#define en_cswitch   "Colour Switch"
#define fr_cswitch   "Colour Switch"
#define it_cswitch   "Colour Switch"
#define es_cswitch   "Colour Switch"
#define de_cswitch   "Colour Switch"
#define nl_cswitch   "Colour Switch"
#define pt_cswitch   "Colour Switch"
#define xx_cswitch   "Colour Switch"
#define en__cswitch   ""
#define en_wgraph   "0|1|2|3|4|5|7|8"
#define fr_wgraph   "0|1|2|3|4|5|7|8"
#define it_wgraph   "0|1|2|3|4|5|7|8"
#define es_wgraph   "0|1|2|3|4|5|7|8"
#define de_wgraph   "0|1|2|3|4|5|7|8"
#define nl_wgraph   "0|1|2|3|4|5|7|8"
#define pt_wgraph   "0|1|2|3|4|5|7|8"
#define xx_wgraph   "0|1|2|3|4|5|7|8"
#define en__wgraph   ""
#define fr__wgraph   ""
#define it__wgraph   ""
#define es__wgraph   ""
#define de__wgraph   ""
#define nl__wgraph   ""
#define pt__wgraph   ""
#define xx__wgraph   ""
#define en_cgraph   "Graph Box"
#define fr_cgraph   "Graph Box"
#define it_cgraph   "Graph Box"
#define es_cgraph   "Graph Box"
#define de_cgraph   "Graph Box"
#define nl_cgraph   "Graph Box"
#define pt_cgraph   "Graph Box"
#define xx_cgraph   "Graph Box"
#define en__cgraph   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""

private struct accept_widget_gridlock_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_Auto3562[8];
	char * hint_Auto3562[8];
	int	x_Auto3562;
	int	y_Auto3562;
	int	w_Auto3562;
	int	h_Auto3562;
	char * msg_Auto3563[8];
	char * hint_Auto3563[8];
	char * msg_Auto3564[8];
	char * hint_Auto3564[8];
	char * msg_wfill[8];
	char * hint_wfill[8];
	int	value_wfill;
	char * msg_cfill[8];
	int	trigger_cfill;
	char * hint_cfill[8];
	int	value_cfill;
	char * msg_woutset[8];
	char * hint_woutset[8];
	int	value_woutset;
	char * msg_coutset[8];
	int	trigger_coutset;
	char * hint_coutset[8];
	int	value_coutset;
	char * msg_winset[8];
	char * hint_winset[8];
	int	value_winset;
	char * msg_cinset[8];
	int	trigger_cinset;
	char * hint_cinset[8];
	int	value_cinset;
	char * msg_wridge[8];
	char * hint_wridge[8];
	int	value_wridge;
	char * msg_cridge[8];
	int	trigger_cridge;
	char * hint_cridge[8];
	int	value_cridge;
	char * msg_wgroove[8];
	char * hint_wgroove[8];
	int	value_wgroove;
	char * msg_cgroove[8];
	int	trigger_cgroove;
	char * hint_cgroove[8];
	int	value_cgroove;
	char * msg_wedit[8];
	char * hint_wedit[8];
	int	value_wedit;
	char * msg_cedit[8];
	int	trigger_cedit;
	char * hint_cedit[8];
	int	value_cedit;
	char * msg_wtext[8];
	char * hint_wtext[8];
	int	value_wtext;
	char * msg_ctext[8];
	int	trigger_ctext;
	char * hint_ctext[8];
	int	value_ctext;
	char * msg_wimage[8];
	char * hint_wimage[8];
	int	value_wimage;
	char * msg_cimage[8];
	int	trigger_cimage;
	char * hint_cimage[8];
	int	value_cimage;
	char * msg_wline[8];
	char * hint_wline[8];
	int	value_wline;
	char * msg_cline[8];
	int	trigger_cline;
	char * hint_cline[8];
	int	value_cline;
	char * msg_wpush[8];
	char * hint_wpush[8];
	int	value_wpush;
	char * msg_cpush[8];
	int	trigger_cpush;
	char * hint_cpush[8];
	int	value_cpush;
	char * msg_wwindow[8];
	char * hint_wwindow[8];
	int	value_wwindow;
	char * msg_cwindow[8];
	int	trigger_cwindow;
	char * hint_cwindow[8];
	int	value_cwindow;
	char * msg_wtab[8];
	char * hint_wtab[8];
	int	value_wtab;
	char * msg_ctab[8];
	int	trigger_ctab;
	char * hint_ctab[8];
	int	value_ctab;
	char * msg_wcheck[8];
	char * hint_wcheck[8];
	int	value_wcheck;
	char * msg_ccheck[8];
	int	trigger_ccheck;
	char * hint_ccheck[8];
	int	value_ccheck;
	char * msg_wradio[8];
	char * hint_wradio[8];
	int	value_wradio;
	char * msg_cradio[8];
	int	trigger_cradio;
	char * hint_cradio[8];
	int	value_cradio;
	char * msg_wselect[8];
	char * hint_wselect[8];
	int	value_wselect;
	char * msg_cselect[8];
	int	trigger_cselect;
	char * hint_cselect[8];
	int	value_cselect;
	char * msg_wtable[8];
	char * hint_wtable[8];
	int	value_wtable;
	char * msg_ctable[8];
	int	trigger_ctable;
	char * hint_ctable[8];
	int	value_ctable;
	char * msg_wscroll[8];
	char * hint_wscroll[8];
	int	value_wscroll;
	char * msg_cscroll[8];
	int	trigger_cscroll;
	char * hint_cscroll[8];
	int	value_cscroll;
	char * msg_wprogress[8];
	char * hint_wprogress[8];
	int	value_wprogress;
	char * msg_cprogress[8];
	int	trigger_cprogress;
	char * hint_cprogress[8];
	int	value_cprogress;
	char * msg_wswitch[8];
	char * hint_wswitch[8];
	int	value_wswitch;
	char * msg_cswitch[8];
	int	trigger_cswitch;
	char * hint_cswitch[8];
	int	value_cswitch;
	char * msg_wgraph[8];
	char * hint_wgraph[8];
	int	value_wgraph;
	char * msg_cgraph[8];
	int	trigger_cgraph;
	char * hint_cgraph[8];
	int	value_cgraph;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
private int on_cfill_create(struct accept_widget_gridlock_context * _Context);
private int on_coutset_create(struct accept_widget_gridlock_context * _Context);
private int on_cinset_create(struct accept_widget_gridlock_context * _Context);
private int on_cridge_create(struct accept_widget_gridlock_context * _Context);
private int on_cgroove_create(struct accept_widget_gridlock_context * _Context);
private int on_cedit_create(struct accept_widget_gridlock_context * _Context);
private int on_ctext_create(struct accept_widget_gridlock_context * _Context);
private int on_cimage_create(struct accept_widget_gridlock_context * _Context);
private int on_cline_create(struct accept_widget_gridlock_context * _Context);
private int on_cpush_create(struct accept_widget_gridlock_context * _Context);
private int on_cwindow_create(struct accept_widget_gridlock_context * _Context);
private int on_ctab_create(struct accept_widget_gridlock_context * _Context);
private int on_ccheck_create(struct accept_widget_gridlock_context * _Context);
private int on_cradio_create(struct accept_widget_gridlock_context * _Context);
private int on_cselect_create(struct accept_widget_gridlock_context * _Context);
private int on_ctable_create(struct accept_widget_gridlock_context * _Context);
private int on_cscroll_create(struct accept_widget_gridlock_context * _Context);
private int on_cprogress_create(struct accept_widget_gridlock_context * _Context);
private int on_cswitch_create(struct accept_widget_gridlock_context * _Context);
private int on_cgraph_create(struct accept_widget_gridlock_context * _Context);
private int on_Accept_event(struct accept_widget_gridlock_context * _Context);
private int on_Cancel_event(struct accept_widget_gridlock_context * _Context);
private int on_cfill_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_FILL_FRAME))&1){
	_Context->value_cfill=1;
	_Context->value_wfill=(v>>1);
	}
	else{
	_Context->value_wfill=_Context->value_cfill=0;
	}
		return(-1);
}
private int on_coutset_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_OUTSET_FRAME))&1){
	_Context->value_coutset=1;
	_Context->value_woutset=(v>>1);
	}
	else{
	_Context->value_woutset=_Context->value_coutset=0;
	}
		return(-1);
}
private int on_cinset_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_INSET_FRAME))&1){
	_Context->value_cinset=1;
	_Context->value_winset=(v>>1);
	}
	else{
	_Context->value_winset=_Context->value_cinset=0;
	}
		return(-1);
}
private int on_cridge_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_RIDGE_FRAME))&1){
	_Context->value_cridge=1;
	_Context->value_wridge=(v>>1);
	}
	else{
	_Context->value_wridge=_Context->value_cridge=0;
	}
		return(-1);
}
private int on_cgroove_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_GROOVE_FRAME))&1){
	_Context->value_cgroove=1;
	_Context->value_wgroove=(v>>1);
	}
	else{
	_Context->value_wgroove=_Context->value_cgroove=0;
	}
		return(-1);
}
private int on_cedit_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_EDIT_FRAME))&1){
	_Context->value_cedit=1;
	_Context->value_wedit=(v>>1);
	}
	else{
	_Context->value_wedit=_Context->value_cedit=0;
	}
		return(-1);
}
private int on_ctext_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_TEXT_FRAME))&1){
	_Context->value_ctext=1;
	_Context->value_wtext=(v>>1);
	}
	else{
	_Context->value_wtext=_Context->value_ctext=0;
	}
		return(-1);
}
private int on_cimage_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_IMAGE_FRAME))&1){
	_Context->value_cimage=1;
	_Context->value_wimage=(v>>1);
	}
	else{
	_Context->value_wimage=_Context->value_cimage=0;
	}
	return(-1);
}
private int on_cline_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_LINE_FRAME))&1){
	_Context->value_cline=1;
	_Context->value_wline=(v>>1);
	}
	else{
	_Context->value_wline=_Context->value_cline=0;
	}
		return(-1);
}
private int on_cpush_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_BUTTON_FRAME))&1){
	_Context->value_cpush=1;
	_Context->value_wpush=(v>>1);
	}
	else{
	_Context->value_wpush=_Context->value_cpush=0;
	}
		return(-1);
}
private int on_cwindow_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_WINDOW_FRAME))&1){
	_Context->value_cwindow=1;
	_Context->value_wwindow=(v>>1);
	}
	else{
	_Context->value_wwindow=_Context->value_cwindow=0;
	}
	return(-1);
}
private int on_ctab_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_TAB_FRAME))&1){
	_Context->value_ctab=1;
	_Context->value_wtab=(v>>1);
	}
	else{
	_Context->value_wtab=_Context->value_ctab=0;
	}
	return(-1);
}
private int on_ccheck_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_CHECK_FRAME))&1){
	_Context->value_ccheck=1;
	_Context->value_wcheck=(v>>1);
	}
	else{
	_Context->value_wcheck=_Context->value_ccheck=0;
	}
	return(-1);
}
private int on_cradio_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_RADIO_FRAME))&1){
	_Context->value_cradio=1;
	_Context->value_wradio=(v>>1);
	}
	else{
	_Context->value_wradio=_Context->value_cradio=0;
	}
	return(-1);
}
private int on_cselect_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_SELECT_FRAME))&1){
	_Context->value_cselect=1;
	_Context->value_wselect=(v>>1);
	}
	else{
	_Context->value_wselect=_Context->value_cselect=0;
	}
	return(-1);
}
private int on_ctable_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_FORM_FRAME))&1){
	_Context->value_ctable=1;
	_Context->value_wtable=(v>>1);
	}
	else{
	_Context->value_wtable=_Context->value_ctable=0;
	}
	return(-1);
}
private int on_cscroll_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_SCROLL_FRAME))&1){
	_Context->value_cscroll=1;
	_Context->value_wscroll=(v>>1);
	}
	else{
	_Context->value_wscroll=_Context->value_cscroll=0;
	}
	return(-1);
}
private int on_cprogress_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_PROGRESS_FRAME))&1){
	_Context->value_cprogress=1;
	_Context->value_wprogress=(v>>1);
	}
	else{
	_Context->value_wprogress=_Context->value_cprogress=0;
	}
	return(-1);
}
private int on_cswitch_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_SWITCH_FRAME))&1){
	_Context->value_cswitch=1;
	_Context->value_wswitch=(v>>1);
	}
	else{
	_Context->value_wswitch=_Context->value_cswitch=0;
	}
	return(-1);
}
private int on_cgraph_create(struct accept_widget_gridlock_context * _Context) {
	int v;
	if((v=get_widget_gridlock(_GRAPH_FRAME))&1){
	_Context->value_cgraph=1;
	_Context->value_wgraph=(v>>1);
	}
	else{
	_Context->value_wgraph=_Context->value_cgraph=0;
	}
	return(-1);
}

public	int	accept_widget_gridlock_create(struct accept_widget_gridlock_context **cptr)
{

	int i;
	struct accept_widget_gridlock_context * _Context=(struct accept_widget_gridlock_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_widget_gridlock_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=43;
		_Context->value_wfill=0;
		_Context->value_cfill=0;
		_Context->value_woutset=0;
		_Context->value_coutset=0;
		_Context->value_winset=0;
		_Context->value_cinset=0;
		_Context->value_wridge=0;
		_Context->value_cridge=0;
		_Context->value_wgroove=0;
		_Context->value_cgroove=0;
		_Context->value_wedit=0;
		_Context->value_cedit=0;
		_Context->value_wtext=0;
		_Context->value_ctext=0;
		_Context->value_wimage=0;
		_Context->value_cimage=0;
		_Context->value_wline=0;
		_Context->value_cline=0;
		_Context->value_wpush=0;
		_Context->value_cpush=0;
		_Context->value_wwindow=0;
		_Context->value_cwindow=0;
		_Context->value_wtab=0;
		_Context->value_ctab=0;
		_Context->value_wcheck=0;
		_Context->value_ccheck=0;
		_Context->value_wradio=0;
		_Context->value_cradio=0;
		_Context->value_wselect=0;
		_Context->value_cselect=0;
		_Context->value_wtable=0;
		_Context->value_ctable=0;
		_Context->value_wscroll=0;
		_Context->value_cscroll=0;
		_Context->value_wprogress=0;
		_Context->value_cprogress=0;
		_Context->value_wswitch=0;
		_Context->value_cswitch=0;
		_Context->value_wgraph=0;
		_Context->value_cgraph=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3562[i]=" ";
	_Context->hint_Auto3562[0]=en__Auto3562;
	_Context->hint_Auto3562[1]=fr__Auto3562;
	_Context->hint_Auto3562[2]=it__Auto3562;
	_Context->hint_Auto3562[3]=es__Auto3562;
	_Context->hint_Auto3562[4]=de__Auto3562;
	_Context->hint_Auto3562[5]=nl__Auto3562;
	_Context->hint_Auto3562[6]=pt__Auto3562;
	_Context->hint_Auto3562[7]=xx__Auto3562;
	_Context->x_Auto3562=125;
	_Context->y_Auto3562=65;
	_Context->w_Auto3562=550;
	_Context->h_Auto3562=470;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3563[i]=" ";
	_Context->msg_Auto3563[0]=en_Auto3563;
	_Context->msg_Auto3563[1]=fr_Auto3563;
	_Context->msg_Auto3563[2]=it_Auto3563;
	_Context->msg_Auto3563[3]=es_Auto3563;
	_Context->msg_Auto3563[4]=de_Auto3563;
	_Context->msg_Auto3563[5]=nl_Auto3563;
	_Context->msg_Auto3563[6]=pt_Auto3563;
	_Context->msg_Auto3563[7]=xx_Auto3563;
	_Context->hint_Auto3563[0]=en__Auto3563;
	_Context->hint_Auto3563[1]=fr__Auto3563;
	_Context->hint_Auto3563[2]=it__Auto3563;
	_Context->hint_Auto3563[3]=es__Auto3563;
	_Context->hint_Auto3563[4]=de__Auto3563;
	_Context->hint_Auto3563[5]=nl__Auto3563;
	_Context->hint_Auto3563[6]=pt__Auto3563;
	_Context->hint_Auto3563[7]=xx__Auto3563;
	for (i=0; i < 8; i++)_Context->msg_Auto3564[i]=" ";
	_Context->msg_Auto3564[0]=en_Auto3564;
	_Context->msg_Auto3564[1]=fr_Auto3564;
	_Context->msg_Auto3564[2]=it_Auto3564;
	_Context->msg_Auto3564[3]=es_Auto3564;
	_Context->msg_Auto3564[4]=de_Auto3564;
	_Context->msg_Auto3564[5]=nl_Auto3564;
	_Context->msg_Auto3564[6]=pt_Auto3564;
	_Context->msg_Auto3564[7]=xx_Auto3564;
	_Context->hint_Auto3564[0]=en__Auto3564;
	_Context->hint_Auto3564[1]=fr__Auto3564;
	_Context->hint_Auto3564[2]=it__Auto3564;
	_Context->hint_Auto3564[3]=es__Auto3564;
	_Context->hint_Auto3564[4]=de__Auto3564;
	_Context->hint_Auto3564[5]=nl__Auto3564;
	_Context->hint_Auto3564[6]=pt__Auto3564;
	_Context->hint_Auto3564[7]=xx__Auto3564;
	for (i=0; i < 8; i++)_Context->msg_wfill[i]=" ";
	_Context->msg_wfill[0]=en_wfill;
	_Context->msg_wfill[1]=fr_wfill;
	_Context->msg_wfill[2]=it_wfill;
	_Context->msg_wfill[3]=es_wfill;
	_Context->msg_wfill[4]=de_wfill;
	_Context->msg_wfill[5]=nl_wfill;
	_Context->msg_wfill[6]=pt_wfill;
	_Context->msg_wfill[7]=xx_wfill;
	_Context->hint_wfill[0]=en__wfill;
	_Context->hint_wfill[1]=fr__wfill;
	_Context->hint_wfill[2]=it__wfill;
	_Context->hint_wfill[3]=es__wfill;
	_Context->hint_wfill[4]=de__wfill;
	_Context->hint_wfill[5]=nl__wfill;
	_Context->hint_wfill[6]=pt__wfill;
	_Context->hint_wfill[7]=xx__wfill;
	for (i=0; i < 8; i++)_Context->msg_cfill[i]=" ";
	_Context->msg_cfill[0]=en_cfill;
	_Context->msg_cfill[1]=fr_cfill;
	_Context->msg_cfill[2]=it_cfill;
	_Context->msg_cfill[3]=es_cfill;
	_Context->msg_cfill[4]=de_cfill;
	_Context->msg_cfill[5]=nl_cfill;
	_Context->msg_cfill[6]=pt_cfill;
	_Context->msg_cfill[7]=xx_cfill;
	_Context->hint_cfill[0]=en__cfill;
	_Context->hint_cfill[1]=fr__cfill;
	_Context->hint_cfill[2]=it__cfill;
	_Context->hint_cfill[3]=es__cfill;
	_Context->hint_cfill[4]=de__cfill;
	_Context->hint_cfill[5]=nl__cfill;
	_Context->hint_cfill[6]=pt__cfill;
	_Context->hint_cfill[7]=xx__cfill;
	(void) on_cfill_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_woutset[i]=" ";
	_Context->msg_woutset[0]=en_woutset;
	_Context->msg_woutset[1]=fr_woutset;
	_Context->msg_woutset[2]=it_woutset;
	_Context->msg_woutset[3]=es_woutset;
	_Context->msg_woutset[4]=de_woutset;
	_Context->msg_woutset[5]=nl_woutset;
	_Context->msg_woutset[6]=pt_woutset;
	_Context->msg_woutset[7]=xx_woutset;
	_Context->hint_woutset[0]=en__woutset;
	_Context->hint_woutset[1]=fr__woutset;
	_Context->hint_woutset[2]=it__woutset;
	_Context->hint_woutset[3]=es__woutset;
	_Context->hint_woutset[4]=de__woutset;
	_Context->hint_woutset[5]=nl__woutset;
	_Context->hint_woutset[6]=pt__woutset;
	_Context->hint_woutset[7]=xx__woutset;
	for (i=0; i < 8; i++)_Context->msg_coutset[i]=" ";
	_Context->msg_coutset[0]=en_coutset;
	_Context->msg_coutset[1]=fr_coutset;
	_Context->msg_coutset[2]=it_coutset;
	_Context->msg_coutset[3]=es_coutset;
	_Context->msg_coutset[4]=de_coutset;
	_Context->msg_coutset[5]=nl_coutset;
	_Context->msg_coutset[6]=pt_coutset;
	_Context->msg_coutset[7]=xx_coutset;
	_Context->hint_coutset[0]=en__coutset;
	_Context->hint_coutset[1]=fr__coutset;
	_Context->hint_coutset[2]=it__coutset;
	_Context->hint_coutset[3]=es__coutset;
	_Context->hint_coutset[4]=de__coutset;
	_Context->hint_coutset[5]=nl__coutset;
	_Context->hint_coutset[6]=pt__coutset;
	_Context->hint_coutset[7]=xx__coutset;
	(void) on_coutset_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_winset[i]=" ";
	_Context->msg_winset[0]=en_winset;
	_Context->msg_winset[1]=fr_winset;
	_Context->msg_winset[2]=it_winset;
	_Context->msg_winset[3]=es_winset;
	_Context->msg_winset[4]=de_winset;
	_Context->msg_winset[5]=nl_winset;
	_Context->msg_winset[6]=pt_winset;
	_Context->msg_winset[7]=xx_winset;
	_Context->hint_winset[0]=en__winset;
	_Context->hint_winset[1]=fr__winset;
	_Context->hint_winset[2]=it__winset;
	_Context->hint_winset[3]=es__winset;
	_Context->hint_winset[4]=de__winset;
	_Context->hint_winset[5]=nl__winset;
	_Context->hint_winset[6]=pt__winset;
	_Context->hint_winset[7]=xx__winset;
	for (i=0; i < 8; i++)_Context->msg_cinset[i]=" ";
	_Context->msg_cinset[0]=en_cinset;
	_Context->msg_cinset[1]=fr_cinset;
	_Context->msg_cinset[2]=it_cinset;
	_Context->msg_cinset[3]=es_cinset;
	_Context->msg_cinset[4]=de_cinset;
	_Context->msg_cinset[5]=nl_cinset;
	_Context->msg_cinset[6]=pt_cinset;
	_Context->msg_cinset[7]=xx_cinset;
	_Context->hint_cinset[0]=en__cinset;
	_Context->hint_cinset[1]=fr__cinset;
	_Context->hint_cinset[2]=it__cinset;
	_Context->hint_cinset[3]=es__cinset;
	_Context->hint_cinset[4]=de__cinset;
	_Context->hint_cinset[5]=nl__cinset;
	_Context->hint_cinset[6]=pt__cinset;
	_Context->hint_cinset[7]=xx__cinset;
	(void) on_cinset_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wridge[i]=" ";
	_Context->msg_wridge[0]=en_wridge;
	_Context->msg_wridge[1]=fr_wridge;
	_Context->msg_wridge[2]=it_wridge;
	_Context->msg_wridge[3]=es_wridge;
	_Context->msg_wridge[4]=de_wridge;
	_Context->msg_wridge[5]=nl_wridge;
	_Context->msg_wridge[6]=pt_wridge;
	_Context->msg_wridge[7]=xx_wridge;
	_Context->hint_wridge[0]=en__wridge;
	for (i=0; i < 8; i++)_Context->msg_cridge[i]=" ";
	_Context->msg_cridge[0]=en_cridge;
	_Context->msg_cridge[1]=fr_cridge;
	_Context->msg_cridge[2]=it_cridge;
	_Context->msg_cridge[3]=es_cridge;
	_Context->msg_cridge[4]=de_cridge;
	_Context->msg_cridge[5]=nl_cridge;
	_Context->msg_cridge[6]=pt_cridge;
	_Context->msg_cridge[7]=xx_cridge;
	_Context->hint_cridge[0]=en__cridge;
	(void) on_cridge_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wgroove[i]=" ";
	_Context->msg_wgroove[0]=en_wgroove;
	_Context->msg_wgroove[1]=fr_wgroove;
	_Context->msg_wgroove[2]=it_wgroove;
	_Context->msg_wgroove[3]=es_wgroove;
	_Context->msg_wgroove[4]=de_wgroove;
	_Context->msg_wgroove[5]=nl_wgroove;
	_Context->msg_wgroove[6]=pt_wgroove;
	_Context->msg_wgroove[7]=xx_wgroove;
	_Context->hint_wgroove[0]=en__wgroove;
	_Context->hint_wgroove[1]=fr__wgroove;
	_Context->hint_wgroove[2]=it__wgroove;
	_Context->hint_wgroove[3]=es__wgroove;
	_Context->hint_wgroove[4]=de__wgroove;
	_Context->hint_wgroove[5]=nl__wgroove;
	_Context->hint_wgroove[6]=pt__wgroove;
	_Context->hint_wgroove[7]=xx__wgroove;
	for (i=0; i < 8; i++)_Context->msg_cgroove[i]=" ";
	_Context->msg_cgroove[0]=en_cgroove;
	_Context->msg_cgroove[1]=fr_cgroove;
	_Context->msg_cgroove[2]=it_cgroove;
	_Context->msg_cgroove[3]=es_cgroove;
	_Context->msg_cgroove[4]=de_cgroove;
	_Context->msg_cgroove[5]=nl_cgroove;
	_Context->msg_cgroove[6]=pt_cgroove;
	_Context->msg_cgroove[7]=xx_cgroove;
	_Context->hint_cgroove[0]=en__cgroove;
	(void) on_cgroove_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wedit[i]=" ";
	_Context->msg_wedit[0]=en_wedit;
	_Context->msg_wedit[1]=fr_wedit;
	_Context->msg_wedit[2]=it_wedit;
	_Context->msg_wedit[3]=es_wedit;
	_Context->msg_wedit[4]=de_wedit;
	_Context->msg_wedit[5]=nl_wedit;
	_Context->msg_wedit[6]=pt_wedit;
	_Context->msg_wedit[7]=xx_wedit;
	_Context->hint_wedit[0]=en__wedit;
	_Context->hint_wedit[1]=fr__wedit;
	_Context->hint_wedit[2]=it__wedit;
	_Context->hint_wedit[3]=es__wedit;
	_Context->hint_wedit[4]=de__wedit;
	_Context->hint_wedit[5]=nl__wedit;
	_Context->hint_wedit[6]=pt__wedit;
	_Context->hint_wedit[7]=xx__wedit;
	for (i=0; i < 8; i++)_Context->msg_cedit[i]=" ";
	_Context->msg_cedit[0]=en_cedit;
	_Context->msg_cedit[1]=fr_cedit;
	_Context->msg_cedit[2]=it_cedit;
	_Context->msg_cedit[3]=es_cedit;
	_Context->msg_cedit[4]=de_cedit;
	_Context->msg_cedit[5]=nl_cedit;
	_Context->msg_cedit[6]=pt_cedit;
	_Context->msg_cedit[7]=xx_cedit;
	_Context->hint_cedit[0]=en__cedit;
	_Context->hint_cedit[1]=fr__cedit;
	_Context->hint_cedit[2]=it__cedit;
	_Context->hint_cedit[3]=es__cedit;
	_Context->hint_cedit[4]=de__cedit;
	_Context->hint_cedit[5]=nl__cedit;
	_Context->hint_cedit[6]=pt__cedit;
	_Context->hint_cedit[7]=xx__cedit;
	(void) on_cedit_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wtext[i]=" ";
	_Context->msg_wtext[0]=en_wtext;
	_Context->msg_wtext[1]=fr_wtext;
	_Context->msg_wtext[2]=it_wtext;
	_Context->msg_wtext[3]=es_wtext;
	_Context->msg_wtext[4]=de_wtext;
	_Context->msg_wtext[5]=nl_wtext;
	_Context->msg_wtext[6]=pt_wtext;
	_Context->msg_wtext[7]=xx_wtext;
	_Context->hint_wtext[0]=en__wtext;
	_Context->hint_wtext[1]=fr__wtext;
	_Context->hint_wtext[2]=it__wtext;
	_Context->hint_wtext[3]=es__wtext;
	_Context->hint_wtext[4]=de__wtext;
	_Context->hint_wtext[5]=nl__wtext;
	_Context->hint_wtext[6]=pt__wtext;
	_Context->hint_wtext[7]=xx__wtext;
	for (i=0; i < 8; i++)_Context->msg_ctext[i]=" ";
	_Context->msg_ctext[0]=en_ctext;
	_Context->msg_ctext[1]=fr_ctext;
	_Context->msg_ctext[2]=it_ctext;
	_Context->msg_ctext[3]=es_ctext;
	_Context->msg_ctext[4]=de_ctext;
	_Context->msg_ctext[5]=nl_ctext;
	_Context->msg_ctext[6]=pt_ctext;
	_Context->msg_ctext[7]=xx_ctext;
	_Context->hint_ctext[0]=en__ctext;
	(void) on_ctext_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wimage[i]=" ";
	_Context->msg_wimage[0]=en_wimage;
	_Context->msg_wimage[1]=fr_wimage;
	_Context->msg_wimage[2]=it_wimage;
	_Context->msg_wimage[3]=es_wimage;
	_Context->msg_wimage[4]=de_wimage;
	_Context->msg_wimage[5]=nl_wimage;
	_Context->msg_wimage[6]=pt_wimage;
	_Context->msg_wimage[7]=xx_wimage;
	_Context->hint_wimage[0]=en__wimage;
	_Context->hint_wimage[1]=fr__wimage;
	_Context->hint_wimage[2]=it__wimage;
	_Context->hint_wimage[3]=es__wimage;
	_Context->hint_wimage[4]=de__wimage;
	_Context->hint_wimage[5]=nl__wimage;
	_Context->hint_wimage[6]=pt__wimage;
	_Context->hint_wimage[7]=xx__wimage;
	for (i=0; i < 8; i++)_Context->msg_cimage[i]=" ";
	_Context->msg_cimage[0]=en_cimage;
	_Context->msg_cimage[1]=fr_cimage;
	_Context->msg_cimage[2]=it_cimage;
	_Context->msg_cimage[3]=es_cimage;
	_Context->msg_cimage[4]=de_cimage;
	_Context->msg_cimage[5]=nl_cimage;
	_Context->msg_cimage[6]=pt_cimage;
	_Context->msg_cimage[7]=xx_cimage;
	_Context->hint_cimage[0]=en__cimage;
	(void) on_cimage_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wline[i]=" ";
	_Context->msg_wline[0]=en_wline;
	_Context->msg_wline[1]=fr_wline;
	_Context->msg_wline[2]=it_wline;
	_Context->msg_wline[3]=es_wline;
	_Context->msg_wline[4]=de_wline;
	_Context->msg_wline[5]=nl_wline;
	_Context->msg_wline[6]=pt_wline;
	_Context->msg_wline[7]=xx_wline;
	_Context->hint_wline[0]=en__wline;
	_Context->hint_wline[1]=fr__wline;
	_Context->hint_wline[2]=it__wline;
	_Context->hint_wline[3]=es__wline;
	_Context->hint_wline[4]=de__wline;
	_Context->hint_wline[5]=nl__wline;
	_Context->hint_wline[6]=pt__wline;
	_Context->hint_wline[7]=xx__wline;
	for (i=0; i < 8; i++)_Context->msg_cline[i]=" ";
	_Context->msg_cline[0]=en_cline;
	_Context->msg_cline[1]=fr_cline;
	_Context->msg_cline[2]=it_cline;
	_Context->msg_cline[3]=es_cline;
	_Context->msg_cline[4]=de_cline;
	_Context->msg_cline[5]=nl_cline;
	_Context->msg_cline[6]=pt_cline;
	_Context->msg_cline[7]=xx_cline;
	_Context->hint_cline[0]=en__cline;
	(void) on_cline_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wpush[i]=" ";
	_Context->msg_wpush[0]=en_wpush;
	_Context->msg_wpush[1]=fr_wpush;
	_Context->msg_wpush[2]=it_wpush;
	_Context->msg_wpush[3]=es_wpush;
	_Context->msg_wpush[4]=de_wpush;
	_Context->msg_wpush[5]=nl_wpush;
	_Context->msg_wpush[6]=pt_wpush;
	_Context->msg_wpush[7]=xx_wpush;
	_Context->hint_wpush[0]=en__wpush;
	_Context->hint_wpush[1]=fr__wpush;
	_Context->hint_wpush[2]=it__wpush;
	_Context->hint_wpush[3]=es__wpush;
	_Context->hint_wpush[4]=de__wpush;
	_Context->hint_wpush[5]=nl__wpush;
	_Context->hint_wpush[6]=pt__wpush;
	_Context->hint_wpush[7]=xx__wpush;
	for (i=0; i < 8; i++)_Context->msg_cpush[i]=" ";
	_Context->msg_cpush[0]=en_cpush;
	_Context->msg_cpush[1]=fr_cpush;
	_Context->msg_cpush[2]=it_cpush;
	_Context->msg_cpush[3]=es_cpush;
	_Context->msg_cpush[4]=de_cpush;
	_Context->msg_cpush[5]=nl_cpush;
	_Context->msg_cpush[6]=pt_cpush;
	_Context->msg_cpush[7]=xx_cpush;
	_Context->hint_cpush[0]=en__cpush;
	(void) on_cpush_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wwindow[i]=" ";
	_Context->msg_wwindow[0]=en_wwindow;
	_Context->msg_wwindow[1]=fr_wwindow;
	_Context->msg_wwindow[2]=it_wwindow;
	_Context->msg_wwindow[3]=es_wwindow;
	_Context->msg_wwindow[4]=de_wwindow;
	_Context->msg_wwindow[5]=nl_wwindow;
	_Context->msg_wwindow[6]=pt_wwindow;
	_Context->msg_wwindow[7]=xx_wwindow;
	_Context->hint_wwindow[0]=en__wwindow;
	_Context->hint_wwindow[1]=fr__wwindow;
	_Context->hint_wwindow[2]=it__wwindow;
	_Context->hint_wwindow[3]=es__wwindow;
	_Context->hint_wwindow[4]=de__wwindow;
	_Context->hint_wwindow[5]=nl__wwindow;
	_Context->hint_wwindow[6]=pt__wwindow;
	_Context->hint_wwindow[7]=xx__wwindow;
	for (i=0; i < 8; i++)_Context->msg_cwindow[i]=" ";
	_Context->msg_cwindow[0]=en_cwindow;
	_Context->msg_cwindow[1]=fr_cwindow;
	_Context->msg_cwindow[2]=it_cwindow;
	_Context->msg_cwindow[3]=es_cwindow;
	_Context->msg_cwindow[4]=de_cwindow;
	_Context->msg_cwindow[5]=nl_cwindow;
	_Context->msg_cwindow[6]=pt_cwindow;
	_Context->msg_cwindow[7]=xx_cwindow;
	_Context->hint_cwindow[0]=en__cwindow;
	(void) on_cwindow_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wtab[i]=" ";
	_Context->msg_wtab[0]=en_wtab;
	_Context->msg_wtab[1]=fr_wtab;
	_Context->msg_wtab[2]=it_wtab;
	_Context->msg_wtab[3]=es_wtab;
	_Context->msg_wtab[4]=de_wtab;
	_Context->msg_wtab[5]=nl_wtab;
	_Context->msg_wtab[6]=pt_wtab;
	_Context->msg_wtab[7]=xx_wtab;
	_Context->hint_wtab[0]=en__wtab;
	_Context->hint_wtab[1]=fr__wtab;
	_Context->hint_wtab[2]=it__wtab;
	_Context->hint_wtab[3]=es__wtab;
	_Context->hint_wtab[4]=de__wtab;
	_Context->hint_wtab[5]=nl__wtab;
	_Context->hint_wtab[6]=pt__wtab;
	_Context->hint_wtab[7]=xx__wtab;
	for (i=0; i < 8; i++)_Context->msg_ctab[i]=" ";
	_Context->msg_ctab[0]=en_ctab;
	_Context->msg_ctab[1]=fr_ctab;
	_Context->msg_ctab[2]=it_ctab;
	_Context->msg_ctab[3]=es_ctab;
	_Context->msg_ctab[4]=de_ctab;
	_Context->msg_ctab[5]=nl_ctab;
	_Context->msg_ctab[6]=pt_ctab;
	_Context->msg_ctab[7]=xx_ctab;
	_Context->hint_ctab[0]=en__ctab;
	(void) on_ctab_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wcheck[i]=" ";
	_Context->msg_wcheck[0]=en_wcheck;
	_Context->msg_wcheck[1]=fr_wcheck;
	_Context->msg_wcheck[2]=it_wcheck;
	_Context->msg_wcheck[3]=es_wcheck;
	_Context->msg_wcheck[4]=de_wcheck;
	_Context->msg_wcheck[5]=nl_wcheck;
	_Context->msg_wcheck[6]=pt_wcheck;
	_Context->msg_wcheck[7]=xx_wcheck;
	_Context->hint_wcheck[0]=en__wcheck;
	_Context->hint_wcheck[1]=fr__wcheck;
	_Context->hint_wcheck[2]=it__wcheck;
	_Context->hint_wcheck[3]=es__wcheck;
	_Context->hint_wcheck[4]=de__wcheck;
	_Context->hint_wcheck[5]=nl__wcheck;
	_Context->hint_wcheck[6]=pt__wcheck;
	_Context->hint_wcheck[7]=xx__wcheck;
	for (i=0; i < 8; i++)_Context->msg_ccheck[i]=" ";
	_Context->msg_ccheck[0]=en_ccheck;
	_Context->msg_ccheck[1]=fr_ccheck;
	_Context->msg_ccheck[2]=it_ccheck;
	_Context->msg_ccheck[3]=es_ccheck;
	_Context->msg_ccheck[4]=de_ccheck;
	_Context->msg_ccheck[5]=nl_ccheck;
	_Context->msg_ccheck[6]=pt_ccheck;
	_Context->msg_ccheck[7]=xx_ccheck;
	_Context->hint_ccheck[0]=en__ccheck;
	(void) on_ccheck_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wradio[i]=" ";
	_Context->msg_wradio[0]=en_wradio;
	_Context->msg_wradio[1]=fr_wradio;
	_Context->msg_wradio[2]=it_wradio;
	_Context->msg_wradio[3]=es_wradio;
	_Context->msg_wradio[4]=de_wradio;
	_Context->msg_wradio[5]=nl_wradio;
	_Context->msg_wradio[6]=pt_wradio;
	_Context->msg_wradio[7]=xx_wradio;
	_Context->hint_wradio[0]=en__wradio;
	_Context->hint_wradio[1]=fr__wradio;
	_Context->hint_wradio[2]=it__wradio;
	_Context->hint_wradio[3]=es__wradio;
	_Context->hint_wradio[4]=de__wradio;
	_Context->hint_wradio[5]=nl__wradio;
	_Context->hint_wradio[6]=pt__wradio;
	_Context->hint_wradio[7]=xx__wradio;
	for (i=0; i < 8; i++)_Context->msg_cradio[i]=" ";
	_Context->msg_cradio[0]=en_cradio;
	_Context->msg_cradio[1]=fr_cradio;
	_Context->msg_cradio[2]=it_cradio;
	_Context->msg_cradio[3]=es_cradio;
	_Context->msg_cradio[4]=de_cradio;
	_Context->msg_cradio[5]=nl_cradio;
	_Context->msg_cradio[6]=pt_cradio;
	_Context->msg_cradio[7]=xx_cradio;
	_Context->hint_cradio[0]=en__cradio;
	(void) on_cradio_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wselect[i]=" ";
	_Context->msg_wselect[0]=en_wselect;
	_Context->msg_wselect[1]=fr_wselect;
	_Context->msg_wselect[2]=it_wselect;
	_Context->msg_wselect[3]=es_wselect;
	_Context->msg_wselect[4]=de_wselect;
	_Context->msg_wselect[5]=nl_wselect;
	_Context->msg_wselect[6]=pt_wselect;
	_Context->msg_wselect[7]=xx_wselect;
	_Context->hint_wselect[0]=en__wselect;
	_Context->hint_wselect[1]=fr__wselect;
	_Context->hint_wselect[2]=it__wselect;
	_Context->hint_wselect[3]=es__wselect;
	_Context->hint_wselect[4]=de__wselect;
	_Context->hint_wselect[5]=nl__wselect;
	_Context->hint_wselect[6]=pt__wselect;
	_Context->hint_wselect[7]=xx__wselect;
	for (i=0; i < 8; i++)_Context->msg_cselect[i]=" ";
	_Context->msg_cselect[0]=en_cselect;
	_Context->msg_cselect[1]=fr_cselect;
	_Context->msg_cselect[2]=it_cselect;
	_Context->msg_cselect[3]=es_cselect;
	_Context->msg_cselect[4]=de_cselect;
	_Context->msg_cselect[5]=nl_cselect;
	_Context->msg_cselect[6]=pt_cselect;
	_Context->msg_cselect[7]=xx_cselect;
	_Context->hint_cselect[0]=en__cselect;
	_Context->hint_cselect[1]=fr__cselect;
	_Context->hint_cselect[2]=it__cselect;
	_Context->hint_cselect[3]=es__cselect;
	_Context->hint_cselect[4]=de__cselect;
	_Context->hint_cselect[5]=nl__cselect;
	_Context->hint_cselect[6]=pt__cselect;
	_Context->hint_cselect[7]=xx__cselect;
	(void) on_cselect_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wtable[i]=" ";
	_Context->msg_wtable[0]=en_wtable;
	_Context->msg_wtable[1]=fr_wtable;
	_Context->msg_wtable[2]=it_wtable;
	_Context->msg_wtable[3]=es_wtable;
	_Context->msg_wtable[4]=de_wtable;
	_Context->msg_wtable[5]=nl_wtable;
	_Context->msg_wtable[6]=pt_wtable;
	_Context->msg_wtable[7]=xx_wtable;
	_Context->hint_wtable[0]=en__wtable;
	_Context->hint_wtable[1]=fr__wtable;
	_Context->hint_wtable[2]=it__wtable;
	_Context->hint_wtable[3]=es__wtable;
	_Context->hint_wtable[4]=de__wtable;
	_Context->hint_wtable[5]=nl__wtable;
	_Context->hint_wtable[6]=pt__wtable;
	_Context->hint_wtable[7]=xx__wtable;
	for (i=0; i < 8; i++)_Context->msg_ctable[i]=" ";
	_Context->msg_ctable[0]=en_ctable;
	_Context->msg_ctable[1]=fr_ctable;
	_Context->msg_ctable[2]=it_ctable;
	_Context->msg_ctable[3]=es_ctable;
	_Context->msg_ctable[4]=de_ctable;
	_Context->msg_ctable[5]=nl_ctable;
	_Context->msg_ctable[6]=pt_ctable;
	_Context->msg_ctable[7]=xx_ctable;
	_Context->hint_ctable[0]=en__ctable;
	(void) on_ctable_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wscroll[i]=" ";
	_Context->msg_wscroll[0]=en_wscroll;
	_Context->msg_wscroll[1]=fr_wscroll;
	_Context->msg_wscroll[2]=it_wscroll;
	_Context->msg_wscroll[3]=es_wscroll;
	_Context->msg_wscroll[4]=de_wscroll;
	_Context->msg_wscroll[5]=nl_wscroll;
	_Context->msg_wscroll[6]=pt_wscroll;
	_Context->msg_wscroll[7]=xx_wscroll;
	_Context->hint_wscroll[0]=en__wscroll;
	_Context->hint_wscroll[1]=fr__wscroll;
	_Context->hint_wscroll[2]=it__wscroll;
	_Context->hint_wscroll[3]=es__wscroll;
	_Context->hint_wscroll[4]=de__wscroll;
	_Context->hint_wscroll[5]=nl__wscroll;
	_Context->hint_wscroll[6]=pt__wscroll;
	_Context->hint_wscroll[7]=xx__wscroll;
	for (i=0; i < 8; i++)_Context->msg_cscroll[i]=" ";
	_Context->msg_cscroll[0]=en_cscroll;
	_Context->msg_cscroll[1]=fr_cscroll;
	_Context->msg_cscroll[2]=it_cscroll;
	_Context->msg_cscroll[3]=es_cscroll;
	_Context->msg_cscroll[4]=de_cscroll;
	_Context->msg_cscroll[5]=nl_cscroll;
	_Context->msg_cscroll[6]=pt_cscroll;
	_Context->msg_cscroll[7]=xx_cscroll;
	_Context->hint_cscroll[0]=en__cscroll;
	(void) on_cscroll_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wprogress[i]=" ";
	_Context->msg_wprogress[0]=en_wprogress;
	_Context->msg_wprogress[1]=fr_wprogress;
	_Context->msg_wprogress[2]=it_wprogress;
	_Context->msg_wprogress[3]=es_wprogress;
	_Context->msg_wprogress[4]=de_wprogress;
	_Context->msg_wprogress[5]=nl_wprogress;
	_Context->msg_wprogress[6]=pt_wprogress;
	_Context->msg_wprogress[7]=xx_wprogress;
	_Context->hint_wprogress[0]=en__wprogress;
	_Context->hint_wprogress[1]=fr__wprogress;
	_Context->hint_wprogress[2]=it__wprogress;
	_Context->hint_wprogress[3]=es__wprogress;
	_Context->hint_wprogress[4]=de__wprogress;
	_Context->hint_wprogress[5]=nl__wprogress;
	_Context->hint_wprogress[6]=pt__wprogress;
	_Context->hint_wprogress[7]=xx__wprogress;
	for (i=0; i < 8; i++)_Context->msg_cprogress[i]=" ";
	_Context->msg_cprogress[0]=en_cprogress;
	_Context->msg_cprogress[1]=fr_cprogress;
	_Context->msg_cprogress[2]=it_cprogress;
	_Context->msg_cprogress[3]=es_cprogress;
	_Context->msg_cprogress[4]=de_cprogress;
	_Context->msg_cprogress[5]=nl_cprogress;
	_Context->msg_cprogress[6]=pt_cprogress;
	_Context->msg_cprogress[7]=xx_cprogress;
	_Context->hint_cprogress[0]=en__cprogress;
	(void) on_cprogress_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wswitch[i]=" ";
	_Context->msg_wswitch[0]=en_wswitch;
	_Context->msg_wswitch[1]=fr_wswitch;
	_Context->msg_wswitch[2]=it_wswitch;
	_Context->msg_wswitch[3]=es_wswitch;
	_Context->msg_wswitch[4]=de_wswitch;
	_Context->msg_wswitch[5]=nl_wswitch;
	_Context->msg_wswitch[6]=pt_wswitch;
	_Context->msg_wswitch[7]=xx_wswitch;
	_Context->hint_wswitch[0]=en__wswitch;
	_Context->hint_wswitch[1]=fr__wswitch;
	_Context->hint_wswitch[2]=it__wswitch;
	_Context->hint_wswitch[3]=es__wswitch;
	_Context->hint_wswitch[4]=de__wswitch;
	_Context->hint_wswitch[5]=nl__wswitch;
	_Context->hint_wswitch[6]=pt__wswitch;
	_Context->hint_wswitch[7]=xx__wswitch;
	for (i=0; i < 8; i++)_Context->msg_cswitch[i]=" ";
	_Context->msg_cswitch[0]=en_cswitch;
	_Context->msg_cswitch[1]=fr_cswitch;
	_Context->msg_cswitch[2]=it_cswitch;
	_Context->msg_cswitch[3]=es_cswitch;
	_Context->msg_cswitch[4]=de_cswitch;
	_Context->msg_cswitch[5]=nl_cswitch;
	_Context->msg_cswitch[6]=pt_cswitch;
	_Context->msg_cswitch[7]=xx_cswitch;
	_Context->hint_cswitch[0]=en__cswitch;
	(void) on_cswitch_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_wgraph[i]=" ";
	_Context->msg_wgraph[0]=en_wgraph;
	_Context->msg_wgraph[1]=fr_wgraph;
	_Context->msg_wgraph[2]=it_wgraph;
	_Context->msg_wgraph[3]=es_wgraph;
	_Context->msg_wgraph[4]=de_wgraph;
	_Context->msg_wgraph[5]=nl_wgraph;
	_Context->msg_wgraph[6]=pt_wgraph;
	_Context->msg_wgraph[7]=xx_wgraph;
	_Context->hint_wgraph[0]=en__wgraph;
	_Context->hint_wgraph[1]=fr__wgraph;
	_Context->hint_wgraph[2]=it__wgraph;
	_Context->hint_wgraph[3]=es__wgraph;
	_Context->hint_wgraph[4]=de__wgraph;
	_Context->hint_wgraph[5]=nl__wgraph;
	_Context->hint_wgraph[6]=pt__wgraph;
	_Context->hint_wgraph[7]=xx__wgraph;
	for (i=0; i < 8; i++)_Context->msg_cgraph[i]=" ";
	_Context->msg_cgraph[0]=en_cgraph;
	_Context->msg_cgraph[1]=fr_cgraph;
	_Context->msg_cgraph[2]=it_cgraph;
	_Context->msg_cgraph[3]=es_cgraph;
	_Context->msg_cgraph[4]=de_cgraph;
	_Context->msg_cgraph[5]=nl_cgraph;
	_Context->msg_cgraph[6]=pt_cgraph;
	_Context->msg_cgraph[7]=xx_cgraph;
	_Context->hint_cgraph[0]=en__cgraph;
	(void) on_cgraph_create(_Context);
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3562,_Context->y_Auto3562,550+10,470+10);
	return(0);
}

public 	int	accept_widget_gridlock_hide(struct accept_widget_gridlock_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3562,_Context->y_Auto3562);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_widget_gridlock_remove(struct accept_widget_gridlock_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if(_Context->value_cgraph)
	set_widget_gridlock(_GRAPH_FRAME,((_Context->value_wgraph<<1)|1));
	else set_widget_gridlock(_GRAPH_FRAME,0);
	if(_Context->value_cswitch)
	set_widget_gridlock(_SWITCH_FRAME,((_Context->value_wswitch<<1)|1));
	else set_widget_gridlock(_SWITCH_FRAME,0);
	if(_Context->value_cprogress)
	set_widget_gridlock(_PROGRESS_FRAME,((_Context->value_wprogress<<1)|1));
	else set_widget_gridlock(_PROGRESS_FRAME,0);
	if(_Context->value_cscroll)
	set_widget_gridlock(_SCROLL_FRAME,((_Context->value_wscroll<<1)|1));
	else set_widget_gridlock(_SCROLL_FRAME,0);
	if(_Context->value_ctable)
	set_widget_gridlock(_FORM_FRAME,((_Context->value_wtable<<1)|1));
	else set_widget_gridlock(_FORM_FRAME,0);
	if(_Context->value_cselect)
	set_widget_gridlock(_SELECT_FRAME,((_Context->value_wselect<<1)|1));
	else set_widget_gridlock(_SELECT_FRAME,0);
	if(_Context->value_cradio)
	set_widget_gridlock(_RADIO_FRAME,((_Context->value_wradio<<1)|1));
	else set_widget_gridlock(_RADIO_FRAME,0);
	if(_Context->value_ccheck)
	set_widget_gridlock(_CHECK_FRAME,((_Context->value_wcheck<<1)|1));
	else set_widget_gridlock(_CHECK_FRAME,0);
	if(_Context->value_ctab)
	set_widget_gridlock(_TAB_FRAME,((_Context->value_wtab<<1)|1));
	else set_widget_gridlock(_TAB_FRAME,0);
	if(_Context->value_cwindow)
	set_widget_gridlock(_WINDOW_FRAME,((_Context->value_wwindow<<1)|1));
	else set_widget_gridlock(_WINDOW_FRAME,0);
	if(_Context->value_cpush)
	set_widget_gridlock(_BUTTON_FRAME,((_Context->value_wpush<<1)|1));
	else set_widget_gridlock(_BUTTON_FRAME,0);
	if(_Context->value_cline)
	set_widget_gridlock(_LINE_FRAME,((_Context->value_wline<<1)|1));
	else set_widget_gridlock(_LINE_FRAME,0);
	if(_Context->value_cimage)
	set_widget_gridlock(_IMAGE_FRAME,((_Context->value_wimage<<1)|1));
	else set_widget_gridlock(_IMAGE_FRAME,0);
	if(_Context->value_ctext)
	set_widget_gridlock(_TEXT_FRAME,((_Context->value_wtext<<1)|1));
	else set_widget_gridlock(_TEXT_FRAME,0);
	if(_Context->value_cedit)
	set_widget_gridlock(_EDIT_FRAME,((_Context->value_wedit<<1)|1));
	else set_widget_gridlock(_EDIT_FRAME,0);
	if(_Context->value_cgroove)
	set_widget_gridlock(_GROOVE_FRAME,((_Context->value_wgroove<<1)|1));
	else set_widget_gridlock(_GROOVE_FRAME,0);
	if(_Context->value_cridge)
	set_widget_gridlock(_RIDGE_FRAME,((_Context->value_wridge<<1)|1));
	else set_widget_gridlock(_RIDGE_FRAME,0);
	if(_Context->value_cinset)
	set_widget_gridlock(_INSET_FRAME,((_Context->value_winset<<1)|1));
	else set_widget_gridlock(_INSET_FRAME,0);
	if(_Context->value_coutset)
	set_widget_gridlock(_OUTSET_FRAME,((_Context->value_woutset<<1)|1));
	else set_widget_gridlock(_OUTSET_FRAME,0);
	if(_Context->value_cfill)
	set_widget_gridlock(_FILL_FRAME,((_Context->value_wfill<<1)|1));
	else set_widget_gridlock(_FILL_FRAME,0);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_widget_gridlock_show(struct accept_widget_gridlock_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3562,_Context->y_Auto3562);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3562,_Context->y_Auto3562,550,470,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3562,_Context->y_Auto3562,550,470,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	visual_text(_Context->x_Auto3562+20,_Context->y_Auto3562+20,506,40,vfh[3],16,0,_Context->msg_Auto3563[_Context->language],strlen(_Context->msg_Auto3563[_Context->language]),1283);
	visual_text(_Context->x_Auto3562+20,_Context->y_Auto3562+60,510,16,vfh[2],16,0,_Context->msg_Auto3564[_Context->language],strlen(_Context->msg_Auto3564[_Context->language]),259);
	visual_frame(_Context->x_Auto3562+20,_Context->y_Auto3562+76,510,324,4);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+90,40,128,vfh[1],27,28,parse_selection(_Context->msg_wfill[_Context->language],&_Context->value_wfill),0);
	_Context->trigger_cfill=visual_trigger_code(_Context->msg_cfill[_Context->language],strlen(_Context->msg_cfill[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+90,182,16,vfh[2],27,28,_Context->msg_cfill[_Context->language],strlen(_Context->msg_cfill[_Context->language]),_Context->value_cfill|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+120,40,128,vfh[1],27,28,parse_selection(_Context->msg_woutset[_Context->language],&_Context->value_woutset),0);
	_Context->trigger_coutset=visual_trigger_code(_Context->msg_coutset[_Context->language],strlen(_Context->msg_coutset[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+120,182,16,vfh[2],27,28,_Context->msg_coutset[_Context->language],strlen(_Context->msg_coutset[_Context->language]),_Context->value_coutset|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+150,40,128,vfh[1],27,28,parse_selection(_Context->msg_winset[_Context->language],&_Context->value_winset),0);
	_Context->trigger_cinset=visual_trigger_code(_Context->msg_cinset[_Context->language],strlen(_Context->msg_cinset[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+150,182,16,vfh[2],27,28,_Context->msg_cinset[_Context->language],strlen(_Context->msg_cinset[_Context->language]),_Context->value_cinset|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+180,40,128,vfh[1],27,28,parse_selection(_Context->msg_wridge[_Context->language],&_Context->value_wridge),0);
	_Context->trigger_cridge=visual_trigger_code(_Context->msg_cridge[_Context->language],strlen(_Context->msg_cridge[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+180,182,16,vfh[2],27,28,_Context->msg_cridge[_Context->language],strlen(_Context->msg_cridge[_Context->language]),_Context->value_cridge|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+210,40,128,vfh[1],27,28,parse_selection(_Context->msg_wgroove[_Context->language],&_Context->value_wgroove),0);
	_Context->trigger_cgroove=visual_trigger_code(_Context->msg_cgroove[_Context->language],strlen(_Context->msg_cgroove[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+210,182,16,vfh[2],27,28,_Context->msg_cgroove[_Context->language],strlen(_Context->msg_cgroove[_Context->language]),_Context->value_cgroove|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+240,40,128,vfh[1],27,28,parse_selection(_Context->msg_wedit[_Context->language],&_Context->value_wedit),0);
	_Context->trigger_cedit=visual_trigger_code(_Context->msg_cedit[_Context->language],strlen(_Context->msg_cedit[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+240,182,16,vfh[2],27,28,_Context->msg_cedit[_Context->language],strlen(_Context->msg_cedit[_Context->language]),_Context->value_cedit|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+270,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtext[_Context->language],&_Context->value_wtext),0);
	_Context->trigger_ctext=visual_trigger_code(_Context->msg_ctext[_Context->language],strlen(_Context->msg_ctext[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+270,182,16,vfh[2],27,28,_Context->msg_ctext[_Context->language],strlen(_Context->msg_ctext[_Context->language]),_Context->value_ctext|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+300,40,128,vfh[1],27,28,parse_selection(_Context->msg_wimage[_Context->language],&_Context->value_wimage),0);
	_Context->trigger_cimage=visual_trigger_code(_Context->msg_cimage[_Context->language],strlen(_Context->msg_cimage[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+300,182,16,vfh[2],27,28,_Context->msg_cimage[_Context->language],strlen(_Context->msg_cimage[_Context->language]),_Context->value_cimage|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+330,40,128,vfh[1],27,28,parse_selection(_Context->msg_wline[_Context->language],&_Context->value_wline),0);
	_Context->trigger_cline=visual_trigger_code(_Context->msg_cline[_Context->language],strlen(_Context->msg_cline[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+330,182,16,vfh[2],27,28,_Context->msg_cline[_Context->language],strlen(_Context->msg_cline[_Context->language]),_Context->value_cline|0);
	visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+360,40,128,vfh[1],27,28,parse_selection(_Context->msg_wpush[_Context->language],&_Context->value_wpush),0);
	_Context->trigger_cpush=visual_trigger_code(_Context->msg_cpush[_Context->language],strlen(_Context->msg_cpush[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+360,168,16,vfh[2],27,28,_Context->msg_cpush[_Context->language],strlen(_Context->msg_cpush[_Context->language]),_Context->value_cpush|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+90,40,128,vfh[1],27,28,parse_selection(_Context->msg_wwindow[_Context->language],&_Context->value_wwindow),0);
	_Context->trigger_cwindow=visual_trigger_code(_Context->msg_cwindow[_Context->language],strlen(_Context->msg_cwindow[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+90,154,16,vfh[2],27,28,_Context->msg_cwindow[_Context->language],strlen(_Context->msg_cwindow[_Context->language]),_Context->value_cwindow|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+120,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtab[_Context->language],&_Context->value_wtab),0);
	_Context->trigger_ctab=visual_trigger_code(_Context->msg_ctab[_Context->language],strlen(_Context->msg_ctab[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+120,168,16,vfh[2],27,28,_Context->msg_ctab[_Context->language],strlen(_Context->msg_ctab[_Context->language]),_Context->value_ctab|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+150,40,128,vfh[1],27,28,parse_selection(_Context->msg_wcheck[_Context->language],&_Context->value_wcheck),0);
	_Context->trigger_ccheck=visual_trigger_code(_Context->msg_ccheck[_Context->language],strlen(_Context->msg_ccheck[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+150,168,16,vfh[2],27,28,_Context->msg_ccheck[_Context->language],strlen(_Context->msg_ccheck[_Context->language]),_Context->value_ccheck|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+180,40,128,vfh[1],27,28,parse_selection(_Context->msg_wradio[_Context->language],&_Context->value_wradio),0);
	_Context->trigger_cradio=visual_trigger_code(_Context->msg_cradio[_Context->language],strlen(_Context->msg_cradio[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+180,168,16,vfh[2],27,28,_Context->msg_cradio[_Context->language],strlen(_Context->msg_cradio[_Context->language]),_Context->value_cradio|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+210,40,128,vfh[1],27,28,parse_selection(_Context->msg_wselect[_Context->language],&_Context->value_wselect),0);
	_Context->trigger_cselect=visual_trigger_code(_Context->msg_cselect[_Context->language],strlen(_Context->msg_cselect[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+210,168,16,vfh[2],27,28,_Context->msg_cselect[_Context->language],strlen(_Context->msg_cselect[_Context->language]),_Context->value_cselect|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+240,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtable[_Context->language],&_Context->value_wtable),0);
	_Context->trigger_ctable=visual_trigger_code(_Context->msg_ctable[_Context->language],strlen(_Context->msg_ctable[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+240,168,16,vfh[2],27,28,_Context->msg_ctable[_Context->language],strlen(_Context->msg_ctable[_Context->language]),_Context->value_ctable|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+270,40,128,vfh[1],27,28,parse_selection(_Context->msg_wscroll[_Context->language],&_Context->value_wscroll),0);
	_Context->trigger_cscroll=visual_trigger_code(_Context->msg_cscroll[_Context->language],strlen(_Context->msg_cscroll[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+270,168,16,vfh[2],27,28,_Context->msg_cscroll[_Context->language],strlen(_Context->msg_cscroll[_Context->language]),_Context->value_cscroll|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+300,40,128,vfh[1],27,28,parse_selection(_Context->msg_wprogress[_Context->language],&_Context->value_wprogress),0);
	_Context->trigger_cprogress=visual_trigger_code(_Context->msg_cprogress[_Context->language],strlen(_Context->msg_cprogress[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+300,168,16,vfh[2],27,28,_Context->msg_cprogress[_Context->language],strlen(_Context->msg_cprogress[_Context->language]),_Context->value_cprogress|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+330,40,128,vfh[1],27,28,parse_selection(_Context->msg_wswitch[_Context->language],&_Context->value_wswitch),0);
	_Context->trigger_cswitch=visual_trigger_code(_Context->msg_cswitch[_Context->language],strlen(_Context->msg_cswitch[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+330,168,16,vfh[2],27,28,_Context->msg_cswitch[_Context->language],strlen(_Context->msg_cswitch[_Context->language]),_Context->value_cswitch|0);
	visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+360,40,128,vfh[1],27,28,parse_selection(_Context->msg_wgraph[_Context->language],&_Context->value_wgraph),0);
	_Context->trigger_cgraph=visual_trigger_code(_Context->msg_cgraph[_Context->language],strlen(_Context->msg_cgraph[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+360,154,16,vfh[2],27,28,_Context->msg_cgraph[_Context->language],strlen(_Context->msg_cgraph[_Context->language]),_Context->value_cgraph|0);
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3562+20,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3562+470,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	visual_thaw(_Context->x_Auto3562,_Context->y_Auto3562,550,470);

	return(0);
}

private int Auto3562action(struct accept_widget_gridlock_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_widget_gridlock_hide(_Context);

		_Context->x_Auto3562 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3562 < 0) { _Context->x_Auto3562=0; }
		_Context->y_Auto3562 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3562 < 0) { _Context->y_Auto3562=0; }
			accept_widget_gridlock_show(_Context);

		visual_thaw(_Context->x_Auto3562,_Context->y_Auto3562,550,470);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Accept_event(struct accept_widget_gridlock_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_widget_gridlock_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_widget_gridlock_event(
struct accept_widget_gridlock_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_cfill == mb ) return(3);
		if (_Context->trigger_coutset == mb ) return(5);
		if (_Context->trigger_cinset == mb ) return(7);
		if (_Context->trigger_cridge == mb ) return(9);
		if (_Context->trigger_cgroove == mb ) return(11);
		if (_Context->trigger_cedit == mb ) return(13);
		if (_Context->trigger_ctext == mb ) return(15);
		if (_Context->trigger_cimage == mb ) return(17);
		if (_Context->trigger_cline == mb ) return(19);
		if (_Context->trigger_cpush == mb ) return(21);
		if (_Context->trigger_cwindow == mb ) return(23);
		if (_Context->trigger_ctab == mb ) return(25);
		if (_Context->trigger_ccheck == mb ) return(27);
		if (_Context->trigger_cradio == mb ) return(29);
		if (_Context->trigger_cselect == mb ) return(31);
		if (_Context->trigger_ctable == mb ) return(33);
		if (_Context->trigger_cscroll == mb ) return(35);
		if (_Context->trigger_cprogress == mb ) return(37);
		if (_Context->trigger_cswitch == mb ) return(39);
		if (_Context->trigger_cgraph == mb ) return(41);
		if (_Context->trigger_Accept == mb ) return(42);
		if (_Context->trigger_Cancel == mb ) return(43);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3562+529) )  
	&&  (my >= (_Context->y_Auto3562+4) )  
	&&  (mx <= (_Context->x_Auto3562+546) )  
	&&  (my <= (_Context->y_Auto3562+20) )) {
		return(1);	/* Auto3562 */

		}
	if ((mx >= (_Context->x_Auto3562+513) )  
	&&  (my >= (_Context->y_Auto3562+4) )  
	&&  (mx <= (_Context->x_Auto3562+530) )  
	&&  (my <= (_Context->y_Auto3562+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vgridlock.htm");
			};
		return(-1);	/* Auto3562 */

		}
	if ((mx >= (_Context->x_Auto3562+497) )  
	&&  (my >= (_Context->y_Auto3562+4) )  
	&&  (mx <= (_Context->x_Auto3562+514) )  
	&&  (my <= (_Context->y_Auto3562+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_widget_gridlock_show(_Context);
		return(-1);	/* Auto3562 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3562+4) )  
		&&  (my >= (_Context->y_Auto3562+4) )  
		&&  (mx <= (_Context->x_Auto3562+482) )  
		&&  (my <= (_Context->y_Auto3562+20) )) {
			return( Auto3562action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+90) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+90+16))) {
		return(2); /* wfill */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+90) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+90+16))) {
		return(3); /* cfill */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+120) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+120+16))) {
		return(4); /* woutset */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+120) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+120+16))) {
		return(5); /* coutset */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+150) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+150+16))) {
		return(6); /* winset */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+150) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+150+16))) {
		return(7); /* cinset */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+180) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+180+16))) {
		return(8); /* wridge */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+180) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+180+16))) {
		return(9); /* cridge */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+210) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+210+16))) {
		return(10); /* wgroove */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+210) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+210+16))) {
		return(11); /* cgroove */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+240) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+240+16))) {
		return(12); /* wedit */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+240) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+240+16))) {
		return(13); /* cedit */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+270) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+270+16))) {
		return(14); /* wtext */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+270) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+270+16))) {
		return(15); /* ctext */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+300) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+300+16))) {
		return(16); /* wimage */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+300) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+300+16))) {
		return(17); /* cimage */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+330) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+330+16))) {
		return(18); /* wline */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+330) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+182) ) 
	&&  ( my <= (_Context->y_Auto3562+330+16))) {
		return(19); /* cline */
		}
	if (( mx >= (_Context->x_Auto3562+50+0) ) 
	&&  ( my >= (_Context->y_Auto3562+360) ) 
	&&  ( mx <= (_Context->x_Auto3562+50+40) ) 
	&&  ( my <= (_Context->y_Auto3562+360+16))) {
		return(20); /* wpush */
		}
	if (( mx >= (_Context->x_Auto3562+100) ) 
	&&  ( my >= (_Context->y_Auto3562+360) ) 
	&&  ( mx <= (_Context->x_Auto3562+100+168) ) 
	&&  ( my <= (_Context->y_Auto3562+360+16))) {
		return(21); /* cpush */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+90) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+90+16))) {
		return(22); /* wwindow */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+90) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+154) ) 
	&&  ( my <= (_Context->y_Auto3562+90+16))) {
		return(23); /* cwindow */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+120) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+120+16))) {
		return(24); /* wtab */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+120) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+120+16))) {
		return(25); /* ctab */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+150) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+150+16))) {
		return(26); /* wcheck */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+150) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+150+16))) {
		return(27); /* ccheck */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+180) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+180+16))) {
		return(28); /* wradio */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+180) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+180+16))) {
		return(29); /* cradio */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+210) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+210+16))) {
		return(30); /* wselect */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+210) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+210+16))) {
		return(31); /* cselect */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+240) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+240+16))) {
		return(32); /* wtable */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+240) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+240+16))) {
		return(33); /* ctable */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+270) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+270+16))) {
		return(34); /* wscroll */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+270) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+270+16))) {
		return(35); /* cscroll */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+300) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+300+16))) {
		return(36); /* wprogress */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+300) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+300+16))) {
		return(37); /* cprogress */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+330) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+330+16))) {
		return(38); /* wswitch */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+330) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+168) ) 
	&&  ( my <= (_Context->y_Auto3562+330+16))) {
		return(39); /* cswitch */
		}
	if (( mx >= (_Context->x_Auto3562+310+0) ) 
	&&  ( my >= (_Context->y_Auto3562+360) ) 
	&&  ( mx <= (_Context->x_Auto3562+310+40) ) 
	&&  ( my <= (_Context->y_Auto3562+360+16))) {
		return(40); /* wgraph */
		}
	if (( mx >= (_Context->x_Auto3562+360) ) 
	&&  ( my >= (_Context->y_Auto3562+360) ) 
	&&  ( mx <= (_Context->x_Auto3562+360+154) ) 
	&&  ( my <= (_Context->y_Auto3562+360+16))) {
		return(41); /* cgraph */
		}
	if (( mx >= (_Context->x_Auto3562+20) ) 
	&&  ( my >= (_Context->y_Auto3562+410) ) 
	&&  ( mx <= (_Context->x_Auto3562+20+56) ) 
	&&  ( my <= (_Context->y_Auto3562+410+48))) {
		return(42); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3562+470) ) 
	&&  ( my >= (_Context->y_Auto3562+410) ) 
	&&  ( mx <= (_Context->x_Auto3562+470+56) ) 
	&&  ( my <= (_Context->y_Auto3562+410+48))) {
		return(43); /* Cancel */
		}

	return(-1);
}


public	int	accept_widget_gridlock_focus(struct accept_widget_gridlock_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x1 :
				/* Auto3562 */
				_Context->keycode=visual_getch();
				break;
			case	0x2 :
				/* wfill */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+90,40,128,vfh[1],27,28,parse_selection(_Context->msg_wfill[_Context->language],&_Context->value_wfill),2);
				break;
			case	0x3 :
				/* cfill */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+90,182,16,vfh[2],27,28,_Context->msg_cfill[_Context->language],strlen(_Context->msg_cfill[_Context->language]),(_Context->value_cfill |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cfill=visual_trigger_code(_Context->msg_cfill[_Context->language],strlen(_Context->msg_cfill[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+90,182,16,vfh[2],27,28,_Context->msg_cfill[_Context->language],strlen(_Context->msg_cfill[_Context->language]),_Context->value_cfill|0);
				break;
			case	0x4 :
				/* woutset */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+120,40,128,vfh[1],27,28,parse_selection(_Context->msg_woutset[_Context->language],&_Context->value_woutset),2);
				break;
			case	0x5 :
				/* coutset */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+120,182,16,vfh[2],27,28,_Context->msg_coutset[_Context->language],strlen(_Context->msg_coutset[_Context->language]),(_Context->value_coutset |2));
				_Context->keycode = visual_getch();
				_Context->trigger_coutset=visual_trigger_code(_Context->msg_coutset[_Context->language],strlen(_Context->msg_coutset[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+120,182,16,vfh[2],27,28,_Context->msg_coutset[_Context->language],strlen(_Context->msg_coutset[_Context->language]),_Context->value_coutset|0);
				break;
			case	0x6 :
				/* winset */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+150,40,128,vfh[1],27,28,parse_selection(_Context->msg_winset[_Context->language],&_Context->value_winset),2);
				break;
			case	0x7 :
				/* cinset */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+150,182,16,vfh[2],27,28,_Context->msg_cinset[_Context->language],strlen(_Context->msg_cinset[_Context->language]),(_Context->value_cinset |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cinset=visual_trigger_code(_Context->msg_cinset[_Context->language],strlen(_Context->msg_cinset[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+150,182,16,vfh[2],27,28,_Context->msg_cinset[_Context->language],strlen(_Context->msg_cinset[_Context->language]),_Context->value_cinset|0);
				break;
			case	0x8 :
				/* wridge */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+180,40,128,vfh[1],27,28,parse_selection(_Context->msg_wridge[_Context->language],&_Context->value_wridge),2);
				break;
			case	0x9 :
				/* cridge */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+180,182,16,vfh[2],27,28,_Context->msg_cridge[_Context->language],strlen(_Context->msg_cridge[_Context->language]),(_Context->value_cridge |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cridge=visual_trigger_code(_Context->msg_cridge[_Context->language],strlen(_Context->msg_cridge[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+180,182,16,vfh[2],27,28,_Context->msg_cridge[_Context->language],strlen(_Context->msg_cridge[_Context->language]),_Context->value_cridge|0);
				break;
			case	0xa :
				/* wgroove */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+210,40,128,vfh[1],27,28,parse_selection(_Context->msg_wgroove[_Context->language],&_Context->value_wgroove),2);
				break;
			case	0xb :
				/* cgroove */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+210,182,16,vfh[2],27,28,_Context->msg_cgroove[_Context->language],strlen(_Context->msg_cgroove[_Context->language]),(_Context->value_cgroove |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cgroove=visual_trigger_code(_Context->msg_cgroove[_Context->language],strlen(_Context->msg_cgroove[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+210,182,16,vfh[2],27,28,_Context->msg_cgroove[_Context->language],strlen(_Context->msg_cgroove[_Context->language]),_Context->value_cgroove|0);
				break;
			case	0xc :
				/* wedit */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+240,40,128,vfh[1],27,28,parse_selection(_Context->msg_wedit[_Context->language],&_Context->value_wedit),2);
				break;
			case	0xd :
				/* cedit */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+240,182,16,vfh[2],27,28,_Context->msg_cedit[_Context->language],strlen(_Context->msg_cedit[_Context->language]),(_Context->value_cedit |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cedit=visual_trigger_code(_Context->msg_cedit[_Context->language],strlen(_Context->msg_cedit[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+240,182,16,vfh[2],27,28,_Context->msg_cedit[_Context->language],strlen(_Context->msg_cedit[_Context->language]),_Context->value_cedit|0);
				break;
			case	0xe :
				/* wtext */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+270,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtext[_Context->language],&_Context->value_wtext),2);
				break;
			case	0xf :
				/* ctext */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+270,182,16,vfh[2],27,28,_Context->msg_ctext[_Context->language],strlen(_Context->msg_ctext[_Context->language]),(_Context->value_ctext |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ctext=visual_trigger_code(_Context->msg_ctext[_Context->language],strlen(_Context->msg_ctext[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+270,182,16,vfh[2],27,28,_Context->msg_ctext[_Context->language],strlen(_Context->msg_ctext[_Context->language]),_Context->value_ctext|0);
				break;
			case	0x10 :
				/* wimage */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+300,40,128,vfh[1],27,28,parse_selection(_Context->msg_wimage[_Context->language],&_Context->value_wimage),2);
				break;
			case	0x11 :
				/* cimage */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+300,182,16,vfh[2],27,28,_Context->msg_cimage[_Context->language],strlen(_Context->msg_cimage[_Context->language]),(_Context->value_cimage |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cimage=visual_trigger_code(_Context->msg_cimage[_Context->language],strlen(_Context->msg_cimage[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+300,182,16,vfh[2],27,28,_Context->msg_cimage[_Context->language],strlen(_Context->msg_cimage[_Context->language]),_Context->value_cimage|0);
				break;
			case	0x12 :
				/* wline */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+330,40,128,vfh[1],27,28,parse_selection(_Context->msg_wline[_Context->language],&_Context->value_wline),2);
				break;
			case	0x13 :
				/* cline */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+330,182,16,vfh[2],27,28,_Context->msg_cline[_Context->language],strlen(_Context->msg_cline[_Context->language]),(_Context->value_cline |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cline=visual_trigger_code(_Context->msg_cline[_Context->language],strlen(_Context->msg_cline[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+330,182,16,vfh[2],27,28,_Context->msg_cline[_Context->language],strlen(_Context->msg_cline[_Context->language]),_Context->value_cline|0);
				break;
			case	0x14 :
				/* wpush */
				_Context->keycode = visual_select(_Context->x_Auto3562+50,_Context->y_Auto3562+360,40,128,vfh[1],27,28,parse_selection(_Context->msg_wpush[_Context->language],&_Context->value_wpush),2);
				break;
			case	0x15 :
				/* cpush */
				visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+360,168,16,vfh[2],27,28,_Context->msg_cpush[_Context->language],strlen(_Context->msg_cpush[_Context->language]),(_Context->value_cpush |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cpush=visual_trigger_code(_Context->msg_cpush[_Context->language],strlen(_Context->msg_cpush[_Context->language]));
	visual_check(_Context->x_Auto3562+100,_Context->y_Auto3562+360,168,16,vfh[2],27,28,_Context->msg_cpush[_Context->language],strlen(_Context->msg_cpush[_Context->language]),_Context->value_cpush|0);
				break;
			case	0x16 :
				/* wwindow */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+90,40,128,vfh[1],27,28,parse_selection(_Context->msg_wwindow[_Context->language],&_Context->value_wwindow),2);
				break;
			case	0x17 :
				/* cwindow */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+90,154,16,vfh[2],27,28,_Context->msg_cwindow[_Context->language],strlen(_Context->msg_cwindow[_Context->language]),(_Context->value_cwindow |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cwindow=visual_trigger_code(_Context->msg_cwindow[_Context->language],strlen(_Context->msg_cwindow[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+90,154,16,vfh[2],27,28,_Context->msg_cwindow[_Context->language],strlen(_Context->msg_cwindow[_Context->language]),_Context->value_cwindow|0);
				break;
			case	0x18 :
				/* wtab */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+120,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtab[_Context->language],&_Context->value_wtab),2);
				break;
			case	0x19 :
				/* ctab */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+120,168,16,vfh[2],27,28,_Context->msg_ctab[_Context->language],strlen(_Context->msg_ctab[_Context->language]),(_Context->value_ctab |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ctab=visual_trigger_code(_Context->msg_ctab[_Context->language],strlen(_Context->msg_ctab[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+120,168,16,vfh[2],27,28,_Context->msg_ctab[_Context->language],strlen(_Context->msg_ctab[_Context->language]),_Context->value_ctab|0);
				break;
			case	0x1a :
				/* wcheck */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+150,40,128,vfh[1],27,28,parse_selection(_Context->msg_wcheck[_Context->language],&_Context->value_wcheck),2);
				break;
			case	0x1b :
				/* ccheck */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+150,168,16,vfh[2],27,28,_Context->msg_ccheck[_Context->language],strlen(_Context->msg_ccheck[_Context->language]),(_Context->value_ccheck |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ccheck=visual_trigger_code(_Context->msg_ccheck[_Context->language],strlen(_Context->msg_ccheck[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+150,168,16,vfh[2],27,28,_Context->msg_ccheck[_Context->language],strlen(_Context->msg_ccheck[_Context->language]),_Context->value_ccheck|0);
				break;
			case	0x1c :
				/* wradio */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+180,40,128,vfh[1],27,28,parse_selection(_Context->msg_wradio[_Context->language],&_Context->value_wradio),2);
				break;
			case	0x1d :
				/* cradio */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+180,168,16,vfh[2],27,28,_Context->msg_cradio[_Context->language],strlen(_Context->msg_cradio[_Context->language]),(_Context->value_cradio |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cradio=visual_trigger_code(_Context->msg_cradio[_Context->language],strlen(_Context->msg_cradio[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+180,168,16,vfh[2],27,28,_Context->msg_cradio[_Context->language],strlen(_Context->msg_cradio[_Context->language]),_Context->value_cradio|0);
				break;
			case	0x1e :
				/* wselect */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+210,40,128,vfh[1],27,28,parse_selection(_Context->msg_wselect[_Context->language],&_Context->value_wselect),2);
				break;
			case	0x1f :
				/* cselect */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+210,168,16,vfh[2],27,28,_Context->msg_cselect[_Context->language],strlen(_Context->msg_cselect[_Context->language]),(_Context->value_cselect |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cselect=visual_trigger_code(_Context->msg_cselect[_Context->language],strlen(_Context->msg_cselect[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+210,168,16,vfh[2],27,28,_Context->msg_cselect[_Context->language],strlen(_Context->msg_cselect[_Context->language]),_Context->value_cselect|0);
				break;
			case	0x20 :
				/* wtable */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+240,40,128,vfh[1],27,28,parse_selection(_Context->msg_wtable[_Context->language],&_Context->value_wtable),2);
				break;
			case	0x21 :
				/* ctable */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+240,168,16,vfh[2],27,28,_Context->msg_ctable[_Context->language],strlen(_Context->msg_ctable[_Context->language]),(_Context->value_ctable |2));
				_Context->keycode = visual_getch();
				_Context->trigger_ctable=visual_trigger_code(_Context->msg_ctable[_Context->language],strlen(_Context->msg_ctable[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+240,168,16,vfh[2],27,28,_Context->msg_ctable[_Context->language],strlen(_Context->msg_ctable[_Context->language]),_Context->value_ctable|0);
				break;
			case	0x22 :
				/* wscroll */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+270,40,128,vfh[1],27,28,parse_selection(_Context->msg_wscroll[_Context->language],&_Context->value_wscroll),2);
				break;
			case	0x23 :
				/* cscroll */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+270,168,16,vfh[2],27,28,_Context->msg_cscroll[_Context->language],strlen(_Context->msg_cscroll[_Context->language]),(_Context->value_cscroll |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cscroll=visual_trigger_code(_Context->msg_cscroll[_Context->language],strlen(_Context->msg_cscroll[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+270,168,16,vfh[2],27,28,_Context->msg_cscroll[_Context->language],strlen(_Context->msg_cscroll[_Context->language]),_Context->value_cscroll|0);
				break;
			case	0x24 :
				/* wprogress */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+300,40,128,vfh[1],27,28,parse_selection(_Context->msg_wprogress[_Context->language],&_Context->value_wprogress),2);
				break;
			case	0x25 :
				/* cprogress */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+300,168,16,vfh[2],27,28,_Context->msg_cprogress[_Context->language],strlen(_Context->msg_cprogress[_Context->language]),(_Context->value_cprogress |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cprogress=visual_trigger_code(_Context->msg_cprogress[_Context->language],strlen(_Context->msg_cprogress[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+300,168,16,vfh[2],27,28,_Context->msg_cprogress[_Context->language],strlen(_Context->msg_cprogress[_Context->language]),_Context->value_cprogress|0);
				break;
			case	0x26 :
				/* wswitch */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+330,40,128,vfh[1],27,28,parse_selection(_Context->msg_wswitch[_Context->language],&_Context->value_wswitch),2);
				break;
			case	0x27 :
				/* cswitch */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+330,168,16,vfh[2],27,28,_Context->msg_cswitch[_Context->language],strlen(_Context->msg_cswitch[_Context->language]),(_Context->value_cswitch |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cswitch=visual_trigger_code(_Context->msg_cswitch[_Context->language],strlen(_Context->msg_cswitch[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+330,168,16,vfh[2],27,28,_Context->msg_cswitch[_Context->language],strlen(_Context->msg_cswitch[_Context->language]),_Context->value_cswitch|0);
				break;
			case	0x28 :
				/* wgraph */
				_Context->keycode = visual_select(_Context->x_Auto3562+310,_Context->y_Auto3562+360,40,128,vfh[1],27,28,parse_selection(_Context->msg_wgraph[_Context->language],&_Context->value_wgraph),2);
				break;
			case	0x29 :
				/* cgraph */
				visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+360,154,16,vfh[2],27,28,_Context->msg_cgraph[_Context->language],strlen(_Context->msg_cgraph[_Context->language]),(_Context->value_cgraph |2));
				_Context->keycode = visual_getch();
				_Context->trigger_cgraph=visual_trigger_code(_Context->msg_cgraph[_Context->language],strlen(_Context->msg_cgraph[_Context->language]));
	visual_check(_Context->x_Auto3562+360,_Context->y_Auto3562+360,154,16,vfh[2],27,28,_Context->msg_cgraph[_Context->language],strlen(_Context->msg_cgraph[_Context->language]),_Context->value_cgraph|0);
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			_Context->focus_item=1;
			accept_widget_gridlock_show(_Context);
			continue;
		case	0x2 :
			_Context->focus_item=43;
			accept_widget_gridlock_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_widget_gridlock_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3562 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* wfill */
					continue;
				case	0x3 :
					/* cfill */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cfill += 1;
						_Context->value_cfill &= 1;
						}
					continue;
				case	0x4 :
					/* woutset */
					continue;
				case	0x5 :
					/* coutset */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_coutset += 1;
						_Context->value_coutset &= 1;
						}
					continue;
				case	0x6 :
					/* winset */
					continue;
				case	0x7 :
					/* cinset */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cinset += 1;
						_Context->value_cinset &= 1;
						}
					continue;
				case	0x8 :
					/* wridge */
					continue;
				case	0x9 :
					/* cridge */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cridge += 1;
						_Context->value_cridge &= 1;
						}
					continue;
				case	0xa :
					/* wgroove */
					continue;
				case	0xb :
					/* cgroove */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cgroove += 1;
						_Context->value_cgroove &= 1;
						}
					continue;
				case	0xc :
					/* wedit */
					continue;
				case	0xd :
					/* cedit */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cedit += 1;
						_Context->value_cedit &= 1;
						}
					continue;
				case	0xe :
					/* wtext */
					continue;
				case	0xf :
					/* ctext */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ctext += 1;
						_Context->value_ctext &= 1;
						}
					continue;
				case	0x10 :
					/* wimage */
					continue;
				case	0x11 :
					/* cimage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cimage += 1;
						_Context->value_cimage &= 1;
						}
					continue;
				case	0x12 :
					/* wline */
					continue;
				case	0x13 :
					/* cline */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cline += 1;
						_Context->value_cline &= 1;
						}
					continue;
				case	0x14 :
					/* wpush */
					continue;
				case	0x15 :
					/* cpush */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cpush += 1;
						_Context->value_cpush &= 1;
						}
					continue;
				case	0x16 :
					/* wwindow */
					continue;
				case	0x17 :
					/* cwindow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cwindow += 1;
						_Context->value_cwindow &= 1;
						}
					continue;
				case	0x18 :
					/* wtab */
					continue;
				case	0x19 :
					/* ctab */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ctab += 1;
						_Context->value_ctab &= 1;
						}
					continue;
				case	0x1a :
					/* wcheck */
					continue;
				case	0x1b :
					/* ccheck */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ccheck += 1;
						_Context->value_ccheck &= 1;
						}
					continue;
				case	0x1c :
					/* wradio */
					continue;
				case	0x1d :
					/* cradio */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cradio += 1;
						_Context->value_cradio &= 1;
						}
					continue;
				case	0x1e :
					/* wselect */
					continue;
				case	0x1f :
					/* cselect */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cselect += 1;
						_Context->value_cselect &= 1;
						}
					continue;
				case	0x20 :
					/* wtable */
					continue;
				case	0x21 :
					/* ctable */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ctable += 1;
						_Context->value_ctable &= 1;
						}
					continue;
				case	0x22 :
					/* wscroll */
					continue;
				case	0x23 :
					/* cscroll */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cscroll += 1;
						_Context->value_cscroll &= 1;
						}
					continue;
				case	0x24 :
					/* wprogress */
					continue;
				case	0x25 :
					/* cprogress */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cprogress += 1;
						_Context->value_cprogress &= 1;
						}
					continue;
				case	0x26 :
					/* wswitch */
					continue;
				case	0x27 :
					/* cswitch */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cswitch += 1;
						_Context->value_cswitch &= 1;
						}
					continue;
				case	0x28 :
					/* wgraph */
					continue;
				case	0x29 :
					/* cgraph */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_cgraph += 1;
						_Context->value_cgraph &= 1;
						}
					continue;
				case	0x2a :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3562+20,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3562+20,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x2b :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3562+470,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3562+470,_Context->y_Auto3562+410,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
		case	0xd :
			break;
		case	0x9 :
		case	0x5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
		case	0xb :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=43;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	accept_widget_gridlock()
{
	int	status=0;
	struct accept_widget_gridlock_context * _Context=(struct accept_widget_gridlock_context*) 0;
	status = accept_widget_gridlock_create(&_Context);
	if ( status != 0) return(status);
	status = accept_widget_gridlock_show(_Context);
		enter_modal();
	status = accept_widget_gridlock_focus(_Context);
		leave_modal();
	status = accept_widget_gridlock_hide(_Context);
	status = accept_widget_gridlock_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vgridlock_c */
