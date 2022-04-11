static int GetBPPForDepth(int depth)
{
  XPixmapFormatValues *format;
  int nformats;
  int i;
  int bpp;

  format = XListPixmapFormats(XGC.displayptr, &nformats);

  for (i = 0; i < nformats; i++) {
    if (format[i].depth == depth)
      break;
  }

  if (i == nformats) {
    fprintf(stderr,"no pixmap format for depth %d???\n", depth);
    exit(1);
  }

  bpp = format[i].bits_per_pixel;

  XFree(format);

  if (bpp != 1 && bpp != 8 && bpp != 16 && bpp != 32) {
    fprintf(stderr,"Can't cope with %d bits-per-pixel.  Sorry.\n", bpp);
    exit(1);
  }

  return bpp;
}

