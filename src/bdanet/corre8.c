/*
 *  Copyright (C) 1999 AT&T Laboratories Cambridge.  All Rights Reserved.
 *
 *  This is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this software; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 *  USA.
 */

/*
 * corre.c - handle CoRRE encoding.
 *
 */

static Bool	HandleCoRRE8 (int rx, int ry, int rw, int rh)
{
	rfbRREHeader hdr;
	int i;
	CARD8	pix;
	CARD8 *ptr;
	int x, y, w, h;

	if (!ReadFromRFBServer((char *)&hdr, sz_rfbRREHeader))
		return False;

	hdr.nSubrects = Swap32IfLE(hdr.nSubrects);

	if (!ReadFromRFBServer((char *)&pix, sizeof(pix)))
		return False;

	FillRectangle(pix, rx, ry, rw, rh);

	if (!ReadFromRFBServer(buffer, (hdr.nSubrects * 5 )) )
		return False; 

	for (	ptr = (CARD8 *)buffer, i=0;
		i < hdr.nSubrects; 
		i++) {
		pix = *ptr++;
		x = *ptr++;
		y = *ptr++;
		w = *ptr++;
		h = *ptr++;
		FillRectangle((pix & 0x00FF), rx + x, ry + y, w, h);

		}

	return True;
}

