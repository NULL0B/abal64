/*
   Write an AIFF sound file
   Only do one channel, only support 16 bit.
   Supports sample frequencies of 11, 22, 44KHz (default).
   Little/big endian independent!
*/
void Write_AIFF(FILE *fptr,double *samples,long nsamples,int nfreq)
{
   unsigned short v;
   int i;
   unsigned long totalsize;
   double themin,themax,scale,themid;

   /* Write the form chunk */
   fprintf(fptr,"FORM");
   totalsize = 4 + 8 + 18 + 8 + 2 * nsamples + 8;
   fputc((totalsize & 0xff000000) >> 24,fptr);
   fputc((totalsize & 0x00ff0000) >> 16,fptr);
   fputc((totalsize & 0x0000ff00) >> 8,fptr);
   fputc((totalsize & 0x000000ff),fptr);
   fprintf(fptr,"AIFF");

   /* Write the common chunk */
   fprintf(fptr,"COMM");
   fputc(0,fptr);                               /* Size */
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(18,fptr);
   fputc(0,fptr);                               /* Channels = 1 */
   fputc(1,fptr);
   fputc((nsamples & 0xff000000) >> 24,fptr);   /* Samples */
   fputc((nsamples & 0x00ff0000) >> 16,fptr);
   fputc((nsamples & 0x0000ff00) >> 8,fptr);
   fputc((nsamples & 0x000000ff),fptr);
   fputc(0,fptr);                               /* Size = 16 */
   fputc(16,fptr);
   fputc(0x40,fptr);                            /* 10 byte sampe rate */
   if (nfreq == 11025)
      fputc(0x0e,fptr);
   else if (nfreq == 22050)
      fputc(0x0d,fptr);
   else
      fputc(0x0e,fptr);
   fputc(0xac,fptr);
   fputc(0x44,fptr);
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);

   /* Write the sound data chunk */
   fprintf(fptr,"SSND");
   fputc((2*nsamples+8 & 0xff000000) >> 24,fptr);/* Size      */
   fputc((2*nsamples+8 & 0x00ff0000) >> 16,fptr);
   fputc((2*nsamples+8 & 0x0000ff00) >> 8,fptr);
   fputc((2*nsamples+8 & 0x000000ff),fptr);
   fputc(0,fptr);                                /* Offset    */
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);                                /* Block     */
   fputc(0,fptr);
   fputc(0,fptr);
   fputc(0,fptr);

   /* Find the range */
   themin = samples[0];
   themax = themin;
   for (i=1;i<nsamples;i++) {
      if (samples[i] > themax)
         themax = samples[i];
      if (samples[i] < themin)
         themin = samples[i];
   }
   if (themin >= themax) {
      themin -= 1;
      themax += 1;
   }
   themid = (themin + themax) / 2;
   themin -= themid;
   themax -= themid;
   if (ABS(themin) > ABS(themax))
      themax = ABS(themin);
   scale = 32760 / (themax);

   /* Write the data */
   for (i=0;i<nsamples;i++) {
      v = (unsigned short)(scale * (samples[i] - themid));
      fputc((v & 0xff00) >> 8,fptr);
      fputc((v & 0x00ff),fptr);
   }
}


