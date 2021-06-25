<शैली गुरु>
/*
 * $Id: gअगरdecode.c,v 1.1.1.1 1996/02/14 13:10:25 mclareni Exp $
 *
 * $Log: gअगरdecode.c,v $
 * Revision 1.1.1.1  1996/02/14 13:10:25  mclareni
 * Higz
 *
 */
/*CMZ :  1.23/06 30/11/95  10.45.47  by  O.Couet*/
/*-- Author :    O.Couet   30/11/95*/
#समावेश <मानकपन.स>
#समावेश <माला.स>


#घोषणा BITS    12                      /* largest code size */
#घोषणा TSIZE   4096                    /* tables size */

प्रकार अचिन्हित अक्षर byte;

अटल पूर्णांक      Prefix[TSIZE];          /* prefix table */
अटल byte     Suffix[TSIZE];          /* suffix table */
अटल byte     OutCode[TSIZE];         /* output stack */

अटल byte     *ptr1,                  /* poपूर्णांकer to GIF array */
                *ptr2;                  /* poपूर्णांकer to PIX array */

अटल पूर्णांक      CurCodeSize,            /* current number of bits per code */
                CurMaxCode;             /* maximum code, given CurCodeSize */

अटल दीर्घ     CurBit;                 /* current bit in GIF image data */

/***************************************************************
 *                                                             *
 ***************************************************************/
अटल पूर्णांक ReadCode()
अणु
  अटल दीर्घ   b3[3], CurByte;
  अटल byte   lblk;
  पूर्णांक           shअगरt, nbyte;
  दीर्घ          OldByte;

  अगर (CurBit == -1) अणु
    lblk = 0;
    CurByte = -1;
  पूर्ण

  CurBit += CurCodeSize;
  OldByte = CurByte;
  CurByte = CurBit/8;
  nbyte   = CurByte - OldByte;
  shअगरt   = 17 + (CurBit%8) - CurCodeSize;
  जबतक (nbyte-- > 0) अणु
    अगर (lblk == 0) अणु
      lblk = *ptr1++;
      अगर (lblk == 0) वापस -1;
    पूर्ण
    b3[0] = b3[1];
    b3[1] = b3[2];
    b3[2] = *ptr1++;
    lblk--;
  पूर्ण
  वापस (((b3[0]+0x100*b3[1]+0x10000*b3[2])>>shअगरt) & (CurMaxCode-1));
पूर्ण

/***************************************************************
 *                                                             *
 ***************************************************************/
अटल व्योम OutPixel(pix)
                byte pix;
अणु
  *ptr2++ = pix;
पूर्ण

/***************************************************************
 *                                                             *
 * Name: GIFinfo                                Date: 03.10.94 *
 *                                                             *
 * Function: Get inक्रमmation on GIF image                      *
 *                                                             *
 * Input: GIFarr[] - compressed image in GIF क्रमmat            *
 *                                                             *
 * Output: Width    - image width                              *
 *         Height   - image height                             *
 *         Ncols    - number of colors                         *
 *         वापस   - 0 - अगर O.K.                              *
 *                    1 - अगर error                             *
 *                                                             *
 ***************************************************************/
पूर्णांक GIFinfo(GIFarr, Width, Height, Ncols)
      byte *GIFarr;
       पूर्णांक *Width,*Height,*Ncols;
अणु
  byte          b;

  ptr1 = GIFarr;

  /*   R E A D   H E A D E R   */

  अगर (म_भेदन((अक्षर *)GIFarr,"GIF87a",6) && म_भेदन((अक्षर *)GIFarr,"GIF89a",6))
  अणु
    ख_लिखो(मानक_त्रुटि,"\nGIFinfo: not a valid GIF file !\n");
    वापस 1;
  पूर्ण

  ptr1 += 6;

  ptr1 += 2;                            /* screen width ... ignore */
  ptr1 += 2;                            /* screen height ... ignore */

  b         = *ptr1++;
  *Ncols    = 1 << ((b & 7) + 1);
  अगर ((b & 0x80) == 0) अणु                /* is there color map? */
    ख_लिखो(मानक_त्रुटि,"\nGIFinfo: warning! no color map\n");
    *Ncols = 0;
  पूर्ण

  ++ptr1;                               /* background color ... ignore */
  b      = *ptr1++;                     /* supposed to be शून्य */
  अगर (b) अणु
    ख_लिखो(मानक_त्रुटि,"\nGIFdecode: bad screen descriptor\n");
    वापस 1;
  पूर्ण

  ptr1 += (*Ncols) * 3;                 /* skip color map */

  b      = *ptr1++;                     /* image separator */
  अगर (b != ',') अणु
/*  ख_लिखो(मानक_त्रुटि,"\nGIFinfo: no image separator, it will be found...\n"); */
    जबतक ((b = *ptr1++) != ',');       /* find image separator */
    /* वापस 1; */
  पूर्ण

  ptr1   += 2;                          /* left offset ... ignore */
  ptr1   += 2;                          /* top offset ... ignore */
  b       = *ptr1++;                    /* image width */
  *Width  = b + 0x100*(*ptr1++);
  b       = *ptr1++;                    /* image height */
  *Height = b + 0x100*(*ptr1++);
  वापस 0;
पूर्ण

/***************************************************************
 *                                                             *
 * Name: GIFdecode                              Date: 06.10.92 *
 *                                                             *
 * Function: Decode image from GIF array                       *
 *                                                             *
 * Input: GIFarr[] - compressed image in GIF क्रमmat            *
 *                                                             *
 * Output: PIXarr[] - image (byte per pixel)                   *
 *         Width    - image width                              *
 *         Height   - image height                             *
 *         Ncols    - number of colors                         *
 *         R[]      - red components                           *
 *         G[]      - green components                         *
 *         B[]      - blue components                          *
 *         वापस   - 0 - अगर O.K.                              *
 *                    1 - अगर error                             *
 *                                                             *
 ***************************************************************/
पूर्णांक GIFdecode(GIFarr, PIXarr, Width, Height, Ncols, R, G, B)
        byte *GIFarr,*PIXarr,*R,*G,*B;
         पूर्णांक *Width,*Height,*Ncols;
अणु
  byte          b,                      /* working variable */
                FinChar;                /* final अक्षरacter */

  पूर्णांक           i,                      /* working variable क्रम loops */
                BitsPixel,              /* number of bits per pixel */
                IniCodeSize,            /* initial number of bits per code */
                ClearCode,              /* reset code */
                खातापूर्णCode,                /* end of file code */
                FreeCode,               /* first unused entry */
                CurCode,                /* current code */
                InCode,                 /* input code */
                OldCode,                /* previous code */
                PixMask,                /* mask क्रम pixel */
                OutCount;               /* output stack counter */

  दीर्घ          Npix;                   /* number of pixels */

  ptr1 = GIFarr;
  ptr2 = PIXarr;

  /*   R E A D   H E A D E R   */
  अगर (म_भेदन((अक्षर *)GIFarr,"GIF87a",6) && म_भेदन((अक्षर *)GIFarr,"GIF89a",6))
  अणु
    ख_लिखो(मानक_त्रुटि,"\nGIFinfo: not a GIF\n");
    वापस 1;
  पूर्ण

  ptr1 += 6;

  ptr1 += 2;                            /* screen width ... ignore */
  ptr1 += 2;                            /* screen height ... ignore */

  b         = *ptr1++;
  BitsPixel = (b & 7) + 1;              /* # of bits per pixel */
  *Ncols    = 1 << BitsPixel;
  PixMask   = (*Ncols) - 1;             /* mask क्रम pixel code */
  अगर ((b & 0x80) == 0) अणु                /* is there color map? */
    ख_लिखो(मानक_त्रुटि,"\nGIFdecode: warning! no color map\n");
    *Ncols = 0;
  पूर्ण

  ++ptr1;                               /* background color ... ignore */
  b      = *ptr1++;                     /* supposed to be शून्य */
  अगर (b) अणु
    ख_लिखो(मानक_त्रुटि,"\nGIFdecode: bad screen descriptor\n");
    वापस 1;
  पूर्ण

  क्रम (i=0; i<(*Ncols); i++) अणु          /* global color map */
    R[i] = *ptr1++;
    G[i] = *ptr1++;
    B[i] = *ptr1++;
  पूर्ण

  b      = *ptr1++;                     /* image separator */
  अगर (b != ',') अणु
/*  ख_लिखो(मानक_त्रुटि,"\nGIFdecode: no image separator, it will be found...\n");*/
    जबतक ((b = *ptr1++) != ',');       /* find image separator */
    /* वापस 1; */
  पूर्ण

  ptr1   += 2;                          /* left offset ... ignore */
  ptr1   += 2;                          /* top offset ... ignore */
  b       = *ptr1++;                    /* image width */
  *Width  = b + 0x100*(*ptr1++);
  b       = *ptr1++;                    /* image height */
  *Height = b + 0x100*(*ptr1++);

  b       = *ptr1++;                    /* local colors, पूर्णांकerlace */
  अगर ((b & 0xc0) != 0) अणु
    ख_लिखो(मानक_त्रुटि,
            "\nGIFdecode: unexpected item (local colors or interlace)\n");
    /* वापस 1; */
  पूर्ण

  IniCodeSize = *ptr1++;
  CurCodeSize = ++IniCodeSize;
  CurMaxCode  = (1 << IniCodeSize);
  ClearCode   = (1 << (IniCodeSize - 1));
  खातापूर्णCode     = ClearCode + 1;
  FreeCode    = ClearCode + 2;

  /*   D E C O D E    I M A G E   */

  Npix     =(दीर्घ) (*Width) * (*Height);
  OutCount = 0;
  CurBit   = -1;
  CurCode  = ReadCode();
  जबतक (Npix > 0) अणु

    अगर (CurCode < 0) अणु
      ख_लिखो(मानक_त्रुटि,"\nGIFdecode: corrupted GIF (zero block length)\n");
      वापस 1;
    पूर्ण

    अगर (CurCode == खातापूर्णCode) अणु
      ख_लिखो(मानक_त्रुटि,"\nGIFdecode: corrupted GIF (unexpected EOF)\n");
      वापस 1;
    पूर्ण

    अगर (CurCode == ClearCode) अणु         /* clear code ... reset */

      CurCodeSize = IniCodeSize;
      CurMaxCode  = (1 << IniCodeSize);
      FreeCode    = ClearCode + 2;
      OldCode     = CurCode = ReadCode();
      FinChar     = CurCode;
      OutPixel(FinChar);
      Npix--;

    पूर्ण अन्यथा अणु                            /* image code */

      InCode = CurCode;
      अगर (CurCode >= FreeCode) अणु
        CurCode = OldCode;
        OutCode[OutCount++] = FinChar;
      पूर्ण
      जबतक (CurCode > PixMask) अणु       /* build output pixel chain */
        अगर (OutCount >= TSIZE) अणु
          ख_लिखो(मानक_त्रुटि,"\nGIFdecode: corrupted GIF (big output count)\n");
          वापस 1;
        पूर्ण
      OutCode[OutCount++] = Suffix[CurCode];
      CurCode = Prefix[CurCode];
      पूर्ण
      FinChar = CurCode;
      OutCode[OutCount++] = FinChar;

      क्रम (i=OutCount-1; i>=0; i--) अणु   /* put out pixel chain */
        OutPixel(OutCode[i]);
        Npix--;
      पूर्ण
      OutCount = 0;

      Prefix[FreeCode] = OldCode;       /* build the tables */
      Suffix[FreeCode] = FinChar;
      OldCode = InCode;

      FreeCode++;                       /* move poपूर्णांकer */
      अगर (FreeCode >= CurMaxCode) अणु
        अगर (CurCodeSize < BITS) अणु
          CurCodeSize++;
          CurMaxCode *= 2;
        पूर्ण
      पूर्ण
    पूर्ण
    CurCode = ReadCode();
  पूर्ण
  वापस 0;
पूर्ण
