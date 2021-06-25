<शैली गुरु>
/*
 * $Id: gअगरencode.c,v 1.1.1.1 1996/02/14 13:10:25 mclareni Exp $
 *
 * $Log: gअगरencode.c,v $
 * Revision 1.1.1.1  1996/02/14 13:10:25  mclareni
 * Higz
 *
 */
/*CMZ :  1.21/10 04/10/94  14.25.09  by  O.Couet*/
/*-- Author :    E.Chernyaev   19/01/94*/
#समावेश <मानकपन.स>
#समावेश <मानककोष.स>

#अगर_घोषित __STDC__
#घोषणा ARGS(alist) alist
#अन्यथा
#घोषणा ARGS(alist) ()
#पूर्ण_अगर

#घोषणा BITS     12                     /* largest code size */
#घोषणा THELIMIT 4096                   /* NEVER generate this */
#घोषणा HSIZE    5003                   /* hash table size */
#घोषणा SHIFT    4                      /* shअगरt क्रम hashing */

#घोषणा put_byte(A) (*put_b)((byte)(A)); Nbyte++

प्रकार अचिन्हित अक्षर byte;

अटल दीर्घ     HashTab [HSIZE];        /* hash table */
अटल पूर्णांक      CodeTab [HSIZE];        /* code table */

अटल पूर्णांक      BitsPixel,              /* number of bits per pixel */
                IniCodeSize,            /* initial number of bits per code */
                CurCodeSize,            /* current number of bits per code */
                CurMaxCode,             /* maximum code, given CurCodeSize */
                ClearCode,              /* reset code */
                खातापूर्णCode,                /* end of file code */
                FreeCode;               /* first unused entry */

अटल दीर्घ      Nbyte;
अटल व्योम     (*put_b) ARGS((byte));

अटल व्योम     output ARGS((पूर्णांक));
अटल व्योम     अक्षर_init();
अटल व्योम     अक्षर_out ARGS((पूर्णांक));
अटल व्योम     अक्षर_flush();
अटल व्योम     put_लघु ARGS((पूर्णांक));

/***********************************************************************
 *                                                                     *
 * Name: GIFencode                                   Date:    02.10.92 *
 * Author: E.Chernyaev (IHEP/Protvino)               Revised:          *
 *                                                                     *
 * Function: GIF compression of the image                              *
 *                                                                     *
 * Input: Width      - image width  (must be >= 8)                     *
 *        Height     - image height (must be >= 8)                     *
 *        Ncol       - number of colors                                *
 *        R[]        - red components                                  *
 *        G[]        - green components                                *
 *        B[]        - blue components                                 *
 *        ScLine[]   - array क्रम scan line (byte per pixel)            *
 *        get_scline - user routine to पढ़ो scan line:                 *
 *                       get_scline(y, Width, ScLine)                  *
 *        pb         - user routine क्रम "put_byte": pb(b)              *
 *                                                                     *
 * Return: size of GIF                                                 *
 *                                                                     *
 ***********************************************************************/
दीर्घ GIFencode(Width, Height, Ncol, R, G, B, ScLine, get_scline, pb)
          पूर्णांक  Width, Height, Ncol;
          byte R[], G[], B[], ScLine[];
          व्योम (*get_scline) ARGS((पूर्णांक, पूर्णांक, byte *)), (*pb) ARGS((byte));
अणु
  दीर्घ          CodeK;
  पूर्णांक           ncol, i, x, y, disp, Code, K;

  /*   C H E C K   P A R A M E T E R S   */

  अगर (Width <= 0 || Width > 4096 || Height <= 0 || Height > 4096) अणु
    ख_लिखो(मानक_त्रुटि,
            "\nGIFencode: incorrect image size: %d x %d\n", Width, Height);
    वापस 0;
  पूर्ण

  अगर (Ncol <= 0 || Ncol > 256) अणु
    ख_लिखो(मानक_त्रुटि,"\nGIFencode: wrong number of colors: %d\n", Ncol);
    वापस 0;
  पूर्ण

  /*   I N I T I A L I S A T I O N   */

  put_b  = pb;
  Nbyte  = 0;
  अक्षर_init();                          /* initialise "char_..." routines */

  /*   F I N D   #   O F   B I T S   P E R    P I X E L   */

  BitsPixel = 1;
  अगर (Ncol > 2)   BitsPixel = 2;
  अगर (Ncol > 4)   BitsPixel = 3;
  अगर (Ncol > 8)   BitsPixel = 4;
  अगर (Ncol > 16)  BitsPixel = 5;
  अगर (Ncol > 32)  BitsPixel = 6;
  अगर (Ncol > 64)  BitsPixel = 7;
  अगर (Ncol > 128) BitsPixel = 8;

  ncol  = 1 << BitsPixel;
  IniCodeSize = BitsPixel;
  अगर (BitsPixel <= 1) IniCodeSize = 2;

  /*   W R I T E   H E A D E R  */

  put_byte('G');                        /* magic number: GIF87a */
  put_byte('I');
  put_byte('F');
  put_byte('8');
  put_byte('7');
  put_byte('a');

  put_लघु(Width);                     /* screen size */
  put_लघु(Height);

  K  = 0x80;                            /* yes, there is a color map */
  K |= (8-1)<<4;                        /* OR in the color resolution */
  K |= (BitsPixel - 1);                 /* OR in the # of bits per pixel */
  put_byte(K);

  put_byte(0);                          /* background color */
  put_byte(0);                          /* future expansion byte */

  क्रम (i=0; i<Ncol; i++) अणु              /* global colormap */
    put_byte(R[i]);
    put_byte(G[i]);
    put_byte(B[i]);
  पूर्ण
  क्रम (; i<ncol; i++) अणु
    put_byte(0);
    put_byte(0);
    put_byte(0);
  पूर्ण

  put_byte(',');                        /* image separator */
  put_लघु(0);                         /* left offset of image */
  put_लघु(0);                         /* top offset of image */
  put_लघु(Width);                     /* image size */
  put_लघु(Height);
  put_byte(0);                          /* no local colors, no पूर्णांकerlace */
  put_byte(IniCodeSize);                /* initial code size */

  /*   L W Z   C O M P R E S S I O N   */

  CurCodeSize = ++IniCodeSize;
  CurMaxCode  = (1 << (IniCodeSize)) - 1;
  ClearCode   = (1 << (IniCodeSize - 1));
  खातापूर्णCode     = ClearCode + 1;
  FreeCode    = ClearCode + 2;
  output(ClearCode);
  क्रम (y=0; y<Height; y++) अणु
    (*get_scline)(y, Width, ScLine);
    x     = 0;
    अगर (y == 0)
      Code  = ScLine[x++];
    जबतक(x < Width) अणु
      K     = ScLine[x++];              /* next symbol */
      CodeK = ((दीर्घ) K << BITS) + Code;  /* set full code */
      i     = (K << SHIFT) ^ Code;      /* xor hashing */

      अगर (HashTab[i] == CodeK) अणु        /* full code found */
        Code = CodeTab[i];
        जारी;
      पूर्ण
      अन्यथा अगर (HashTab[i] < 0 )         /* empty slot */
        जाओ NOMATCH;

      disp  = HSIZE - i;                /* secondary hash */
      अगर (i == 0) disp = 1;

PROBE:
      अगर ((i -= disp) < 0)
        i  += HSIZE;

      अगर (HashTab[i] == CodeK) अणु        /* full code found */
        Code = CodeTab[i];
        जारी;
      पूर्ण

      अगर (HashTab[i] > 0)               /* try again */
        जाओ PROBE;

NOMATCH:
      output(Code);                     /* full code not found */
      Code = K;

      अगर (FreeCode < THELIMIT) अणु
        CodeTab[i] = FreeCode++;        /* code -> hashtable */
        HashTab[i] = CodeK;
      पूर्ण
      अन्यथा
        output(ClearCode);
    पूर्ण
  पूर्ण
   /*   O U T P U T   T H E   R E S T  */

  output(Code);
  output(खातापूर्णCode);
  put_byte(0);                          /* zero-length packet (खातापूर्ण) */
  put_byte(';');                        /* GIF file terminator */

  वापस (Nbyte);
पूर्ण

अटल अचिन्हित दीर्घ cur_accum;
अटल पूर्णांक           cur_bits;
अटल पूर्णांक           a_count;
अटल अक्षर          accum[256];
अटल अचिन्हित दीर्घ masks[] = अणु 0x0000,
                                 0x0001, 0x0003, 0x0007, 0x000F,
                                 0x001F, 0x003F, 0x007F, 0x00FF,
                                 0x01FF, 0x03FF, 0x07FF, 0x0FFF,
                                 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF पूर्ण;

/***************************************************************
 *                                                             *
 * Name: output                                 Date: 02.10.92 *
 *                                                             *
 * Function: output GIF code                                   *
 *                                                             *
 * Input: code - GIF code                                      *
 *                                                             *
 ***************************************************************/
अटल व्योम output(code)
               पूर्णांक code;
अणु
  /*   O U T P U T   C O D E   */

   cur_accum &= masks[cur_bits];
   अगर (cur_bits > 0)
     cur_accum |= ((दीर्घ)code << cur_bits);
   अन्यथा
     cur_accum = code;
   cur_bits += CurCodeSize;
   जबतक( cur_bits >= 8 ) अणु
     अक्षर_out( (अचिन्हित पूर्णांक) (cur_accum & 0xFF) );
     cur_accum >>= 8;
     cur_bits -= 8;
   पूर्ण

  /*   R E S E T   */

  अगर (code == ClearCode ) अणु
    स_रखो((अक्षर *) HashTab, -1, माप(HashTab));
    FreeCode = ClearCode + 2;
    CurCodeSize = IniCodeSize;
    CurMaxCode  = (1 << (IniCodeSize)) - 1;
  पूर्ण

  /*   I N C R E A S E   C O D E   S I Z E   */

  अगर (FreeCode > CurMaxCode ) अणु
      CurCodeSize++;
      अगर ( CurCodeSize == BITS )
        CurMaxCode = THELIMIT;
      अन्यथा
        CurMaxCode = (1 << (CurCodeSize)) - 1;
   पूर्ण

  /*   E N D   O F   F I L E :  ग_लिखो the rest of the buffer  */

  अगर( code == खातापूर्णCode ) अणु
    जबतक( cur_bits > 0 ) अणु
      अक्षर_out( (अचिन्हित पूर्णांक)(cur_accum & 0xff) );
      cur_accum >>= 8;
      cur_bits -= 8;
    पूर्ण
    अक्षर_flush();
  पूर्ण
पूर्ण

अटल व्योम अक्षर_init()
अणु
   a_count = 0;
   cur_accum = 0;
   cur_bits  = 0;
पूर्ण

अटल व्योम अक्षर_out(c)
                 पूर्णांक c;
अणु
   accum[a_count++] = c;
   अगर (a_count >= 254)
      अक्षर_flush();
पूर्ण

अटल व्योम अक्षर_flush()
अणु
  पूर्णांक i;

  अगर (a_count == 0) वापस;
  put_byte(a_count);
  क्रम (i=0; i<a_count; i++) अणु
    put_byte(accum[i]);
  पूर्ण
  a_count = 0;
पूर्ण

अटल व्योम put_लघु(word)
                  पूर्णांक word;
अणु
  put_byte(word & 0xFF);
  put_byte((word>>8) & 0xFF);
पूर्ण
