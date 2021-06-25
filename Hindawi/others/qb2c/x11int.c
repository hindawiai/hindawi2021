<शैली गुरु>
/*
 * $Id: x11पूर्णांक.c,v 1.6 1996/04/23 08:36:54 couet Exp $
 *
 * $Log: x11पूर्णांक.c,v $
 * Revision 2.0 1999/02/27       Mario Stipcevic, line dash styles 3.4q1
 * Revision 1.9 1999/01/01       Mario Stipcevic
 *  Added graphics rotation (ixrotate)
 * Revision 1.8 1998/10/10       Mario Stipcevic
 * Revision 1.7 1997/07/01       Mario Stipcevic
 * ixldgअगर able to load gअगरs using standard 6x6x6 color map
 * (216 color indexes, from 32-247 )
 * Revision 1.6  1996/04/23 08:36:54  couet
 * - The test on "display" in ixopnds was not correct. In the हाल of Paw++
 *   the display is set outside the ixopnds routine and in that हाल the
 *   graphics contexts was not initialized. Now the variable isdisp is tested.
 *
 * Revision 1.5  1996/04/19 16:23:52  maartenb
 * - Use XFreeFontNames() to मुक्त fontlist
 *
 * Revision 1.4  1996/04/19 13:23:00  couet
 * - मुक्त(fontlist) was misplaced
 *
 * Revision 1.3  1996/04/19 12:10:31  couet
 * - Free fontlist to aव्योम memory leak
 *
 * Revision 1.2  1996/04/18 14:36:12  couet
 * - ixopnds निकास with वापस code 0 अगर the display is alपढ़ोy खोलो.
 *
 * - Modअगरy the way the fonts are managed to aव्योम memory leak.
 *
 * Revision 1.1.1.1  1996/02/14 13:10:26  mclareni
 * Higz
 *
 */
/*CMZ :  2.07/20 12/12/95  11.17.55  by  O.Couet*/
/*-- Author : O.Couet*/
/*
 * Fortran पूर्णांकerface to X11 winकरोw routines क्रम HIGZ
 */
#समावेश <मानकपन.स>
#समावेश <माला.स>
#समावेश <मानककोष.स>
#समावेश <प्रकार.स>
#समावेश <गणित.स>
#समावेश <X11/Xlib.h>
#समावेश <X11/Xutil.h>
#समावेश <X11/Xatom.h>
#समावेश <X11/cursorfont.h>
#समावेश <X11/keysym.h>

#घोषणा max(a,b) ((a) > (b) ? (a) : (b))
#घोषणा min(a,b) ((a) < (b) ? (a) : (b))

#घोषणा क्रमever जबतक(1)
#घोषणा Lशून्य 0L

#घोषणा MAXWN 16                 /* maximum number of winकरोws                 */
अटल काष्ठा अणु
  पूर्णांक      खोलो;                 /* 1 अगर the winकरोw is खोलो, 0 अगर not         */
  पूर्णांक      motअगर;                /* 1 अगर the winकरोw is a motअगर winकरोw         */
  पूर्णांक      wid;                  /* winकरोw identअगरication number from ixopnwi */
  पूर्णांक      bgcol;                /* winकरोw's background color index (patlette)*/
  Drawable motअगर_winकरोw;         /* adress of the Motअगर winकरोw                */
  पूर्णांक      द्विगुन_buffer;        /* 1 अगर the द्विगुन buffer is on, 0 अगर not    */
  Drawable drawing;              /* drawing area, equal to winकरोw or buffer   */
  Drawable winकरोw;               /* X11 winकरोw                                */
  Drawable buffer;               /* pixmap used क्रम द्विगुन buffer             */
  पूर्णांक width;                     /* width of the winकरोw                       */
  पूर्णांक height;                    /* height of the winकरोw                      */
  पूर्णांक clip;                      /* 1 अगर the clipping is on                   */
  पूर्णांक xclip;                     /* x coordinate of the clipping rectangle    */
  पूर्णांक yclip;                     /* y coordinate of the clipping rectangle    */
  पूर्णांक wclip;                     /* width of the clipping rectangle           */
  पूर्णांक hclip;                     /* height of the clipping rectangle          */
पूर्ण winकरोws[MAXWN],                /* winकरोws : list of the खोलोed winकरोws      */
  *cws, *tws, *ttws;             /* cws : poपूर्णांकer to the current winकरोw       */
                                 /* tws : temporary poपूर्णांकer                   */
                                 /* ttws: yet another temporary poपूर्णांकer       */
अटल पूर्णांक biपंचांगask[]=अणु1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096,
      8192, 16384, 32768, 65536पूर्ण;/* घातers of 2, biपंचांगask in ixwptrq()          */

Drawable oldwin;                 /* allows to save the current खोलोed winकरोw  */
अटल पूर्णांक ispix = 0;            /* अगर ispix=1 a pixmap has been खोलोed       */

अटल XClassHपूर्णांक class_hपूर्णांकs = अणु"higz", "HIGZ"पूर्ण; /* Class name is HIGZ       */

अटल Display *display;
अटल पूर्णांक isdisp = 0;           /* अगर isdisp=1 the display has been खोलोed   */
अटल Screen *screen;
अटल पूर्णांक screen_number;
अटल अक्षर venकरोr[132];         /* output of XServerVenकरोr                   */

अटल Winकरोw (*motअगर_खोलो) ();  /* बाह्यal routine to खोलो a motअगर winकरोw   */
अटल व्योम (*motअगर_init) ();    /* बाह्यal routine to init a motअगर winकरोw   */
अटल व्योम (*motअगर_बंद) ();   /* बाह्यal routine to बंद a motअगर winकरोw  */

अटल पूर्णांक बाह्यal_पूर्णांक = 0;
अटल Drawable बाह्यal_winकरोw;

अटल Pixmap pixmp; /* temporary, Mario, delete अगर not used */

अटल पूर्णांक करो_उठाओ = 0;         /* अगर करो_उठाओ =1 cws is उठाओd in ixupdwi   */

/*
 * colors[1]           : क्रमeground also used क्रम b/w screen
 * colors[0]           : background also used क्रम b/w screen
 * colors[2..MAXCOL-1] : colors which can be set by IXSETCO
 */
अटल पूर्णांक colored;              /* Flag अगर color screen                      */
अटल Colormap colormap;        /* Maba's Colormap                           */

#घोषणा MAXCOL 256
अटल काष्ठा अणु
  पूर्णांक defined;
  अचिन्हित दीर्घ pixel;
  भग्न red;
  भग्न green;
  भग्न blue;
पूर्ण colors[MAXCOL] = अणु0, 0, 255., 255., 255.पूर्ण;

/*
 * Primitives Graphic Contexts global क्रम all winकरोws
 */
#घोषणा MAXGC 7
अटल GC gclist[MAXGC];
अटल GC *gcline = &gclist[0];  /* Polylines                                 */
अटल GC *gcmark = &gclist[1];  /* Polymarker                                */
अटल GC *gcfill = &gclist[2];  /* Fill areas                                */
अटल GC *gctext = &gclist[3];  /* Text                                      */
अटल GC *gcinvt = &gclist[4];  /* Inverse text                              */
अटल GC *gcdash = &gclist[5];  /* Dashed lines                              */
अटल GC *gcpxmp = &gclist[6];  /* Pixmap management                         */
अटल GC GCbuff[1];
अटल GC *gcbuff = &GCbuff[0];  /* GC क्रम buffer pixmap (M.S. 05.98)         */

अटल अचिन्हित दीर्घ gc_mask = GCForeground | GCBackground;
अटल XGCValues gc_वापस;

अटल draw_mode = 0;            /* Current draw mode as set by ixdrmde() M.S.*/

/*
 * Input echo Graphic Context global क्रम all winकरोws
 */
अटल GC gcecho;                           /* input echo                     */
अटल XGCValues gcechov;

अटल पूर्णांक fill_hollow;                     /* Flag अगर fill style is hollow   */
अटल पूर्णांक fill_border;                     /* Flag to fill border also       */
अटल Pixmap fill_pattern = (Pixmap)Lशून्य; /* Fill pattern                   */
अटल पूर्णांक current_fasi = 0;                /* Current fill area style index  */
अटल पूर्णांक text_align = 0;                  /* Align text left, center, right */

अटल पूर्णांक rotate_fl = 0, scale_fl = 0, trans_fl = 0;
अटल द्विगुन r_angle = 0;                  /* Rotation angle in radians      */
अटल द्विगुन Rsi = 0, Rco = 1, f10=100000; /* Rotation sine and cosine       */
अटल पूर्णांक xRO = 0, yRO = 0;                /* Central poपूर्णांक क्रम rotation     */
अटल पूर्णांक xOrig = 0, yOrig = 0;            /* Translated new origin          */
अटल द्विगुन scalex=1, scaley=1;           /* Scaling matrix                 */

/*
 * Text management
 */
#घोषणा MAXFONT 4
अटल काष्ठा अणु
  XFontStruct *id;
  अक्षर name[80];                            /* font name                      */
पूर्ण font[MAXFONT];                            /* list of fonts loaded           */
अटल XFontStruct *text_font;              /* current font                   */
अटल पूर्णांक current_font_number = 0;         /* current font number in font[]  */

/*
 * keep style values क्रम line GC
 */
अटल पूर्णांक line_width = 0;
अटल पूर्णांक line_style = LineSolid;
अटल पूर्णांक cap_style  = CapButt;
अटल पूर्णांक join_style = JoinMiter;
अटल अक्षर dash_list[16];
अटल पूर्णांक dash_length = 0;
अटल पूर्णांक dash_offset = 0;
अटल पूर्णांक dash_nseg = 1; /* Mario */

/*
 * event masks
 */
अटल अचिन्हित दीर्घ mouse_mask = ButtonPressMask   | ButtonReleaseMask |
                                  EnterWinकरोwMask   | LeaveWinकरोwMask   |
                                  Poपूर्णांकerMotionMask | KeyPressMask      |
                                  KeyReleaseMask;
अटल अचिन्हित दीर्घ keybd_mask = ButtonPressMask | KeyPressMask |
                                  EnterWinकरोwMask | LeaveWinकरोwMask;

/*
 * last cursor positions
 */
अटल पूर्णांक xloc  = 0;
अटल पूर्णांक yloc  = 0;
अटल पूर्णांक xlocp = 0;
अटल पूर्णांक ylocp = 0;

/*
 * data to create an invisible cursor
 */
अटल अक्षर null_cursor_bits[] = अणु
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00पूर्ण;
अटल Cursor null_cursor = (Cursor)Lशून्य;

/*
 * data to create fill area पूर्णांकerior style
 */
#घोषणा Hatches_type अटल अचिन्हित अक्षर

Hatches_type         p1_bits[] = अणु
   0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55,
   0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55,
   0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55पूर्ण;
Hatches_type         p2_bits[] = अणु
   0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11,
   0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11,
   0x44, 0x44, 0x11, 0x11, 0x44, 0x44, 0x11, 0x11पूर्ण;
Hatches_type         p3_bits[] = अणु
   0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x44, 0x44,
   0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x11, 0x11,
   0x00, 0x00, 0x44, 0x44, 0x00, 0x00, 0x11, 0x11पूर्ण;
Hatches_type         p4_bits[] = अणु
   0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04,
   0x02, 0x02, 0x01, 0x01, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10,
   0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01पूर्ण;
Hatches_type         p5_bits[] = अणु
   0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x01, 0x01, 0x02, 0x02, 0x04, 0x04,
   0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80, 0x80, 0x01, 0x01,
   0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10पूर्ण;
Hatches_type         p6_bits[] = अणु
   0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
   0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
   0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44पूर्ण;
Hatches_type         p7_bits[] = अणु
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xffपूर्ण;
Hatches_type         p8_bits[] = अणु
   0x11, 0x11, 0xb8, 0xb8, 0x7c, 0x7c, 0x3a, 0x3a, 0x11, 0x11, 0xa3, 0xa3,
   0xc7, 0xc7, 0x8b, 0x8b, 0x11, 0x11, 0xb8, 0xb8, 0x7c, 0x7c, 0x3a, 0x3a,
   0x11, 0x11, 0xa3, 0xa3, 0xc7, 0xc7, 0x8b, 0x8bपूर्ण;
Hatches_type         p9_bits[] = अणु
   0x10, 0x10, 0x10, 0x10, 0x28, 0x28, 0xc7, 0xc7, 0x01, 0x01, 0x01, 0x01,
   0x82, 0x82, 0x7c, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x28, 0x28, 0xc7, 0xc7,
   0x01, 0x01, 0x01, 0x01, 0x82, 0x82, 0x7c, 0x7cपूर्ण;
Hatches_type         p10_bits[] = अणु
   0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01,
   0x01, 0x01, 0xff, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0xff,
   0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xff, 0xffपूर्ण;
Hatches_type         p11_bits[] = अणु
   0x08, 0x08, 0x49, 0x49, 0x2a, 0x2a, 0x1c, 0x1c, 0x2a, 0x2a, 0x49, 0x49,
   0x08, 0x08, 0x00, 0x00, 0x80, 0x80, 0x94, 0x94, 0xa2, 0xa2, 0xc1, 0xc1,
   0xa2, 0xa2, 0x94, 0x94, 0x80, 0x80, 0x00, 0x00पूर्ण;
Hatches_type         p12_bits[] = अणु
   0x1c, 0x1c, 0x22, 0x22, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x22, 0x22,
   0x1c, 0x1c, 0x00, 0x00, 0xc1, 0xc1, 0x22, 0x22, 0x14, 0x14, 0x14, 0x14,
   0x14, 0x14, 0x22, 0x22, 0xc1, 0xc1, 0x00, 0x00पूर्ण;
Hatches_type         p13_bits[] = अणु
   0x01, 0x01, 0x82, 0x82, 0x44, 0x44, 0x28, 0x28, 0x10, 0x10, 0x28, 0x28,
   0x44, 0x44, 0x82, 0x82, 0x01, 0x01, 0x82, 0x82, 0x44, 0x44, 0x28, 0x28,
   0x10, 0x10, 0x28, 0x28, 0x44, 0x44, 0x82, 0x82पूर्ण;
Hatches_type         p14_bits[] = अणु
   0xff, 0xff, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0xf1, 0x1f, 0x11, 0x11,
   0x11, 0x11, 0x11, 0x11, 0xff, 0x11, 0x01, 0x11, 0x01, 0x11, 0x01, 0x11,
   0xff, 0xff, 0x01, 0x10, 0x01, 0x10, 0x01, 0x10पूर्ण;
Hatches_type         p15_bits[] = अणु
   0x22, 0x22, 0x55, 0x55, 0x22, 0x22, 0x00, 0x00, 0x88, 0x88, 0x55, 0x55,
   0x88, 0x88, 0x00, 0x00, 0x22, 0x22, 0x55, 0x55, 0x22, 0x22, 0x00, 0x00,
   0x88, 0x88, 0x55, 0x55, 0x88, 0x88, 0x00, 0x00पूर्ण;
Hatches_type         p16_bits[] = अणु
   0x0e, 0x0e, 0x11, 0x11, 0xe0, 0xe0, 0x00, 0x00, 0x0e, 0x0e, 0x11, 0x11,
   0xe0, 0xe0, 0x00, 0x00, 0x0e, 0x0e, 0x11, 0x11, 0xe0, 0xe0, 0x00, 0x00,
   0x0e, 0x0e, 0x11, 0x11, 0xe0, 0xe0, 0x00, 0x00पूर्ण;
Hatches_type         p17_bits[] = अणु
   0x44, 0x44, 0x22, 0x22, 0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x22, 0x22,
   0x11, 0x11, 0x00, 0x00, 0x44, 0x44, 0x22, 0x22, 0x11, 0x11, 0x00, 0x00,
   0x44, 0x44, 0x22, 0x22, 0x11, 0x11, 0x00, 0x00पूर्ण;
Hatches_type         p18_bits[] = अणु
   0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x00, 0x00, 0x11, 0x11, 0x22, 0x22,
   0x44, 0x44, 0x00, 0x00, 0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x00, 0x00,
   0x11, 0x11, 0x22, 0x22, 0x44, 0x44, 0x00, 0x00पूर्ण;
Hatches_type         p19_bits[] = अणु
   0xe0, 0x03, 0x98, 0x0c, 0x84, 0x10, 0x42, 0x21, 0x42, 0x21, 0x21, 0x42,
   0x19, 0x4c, 0x07, 0xf0, 0x19, 0x4c, 0x21, 0x42, 0x42, 0x21, 0x42, 0x21,
   0x84, 0x10, 0x98, 0x0c, 0xe0, 0x03, 0x80, 0x00पूर्ण;
Hatches_type         p20_bits[] = अणु
   0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x44, 0x44,
   0x44, 0x44, 0x44, 0x44, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
   0x22, 0x22, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44पूर्ण;
Hatches_type         p21_bits[] = अणु
   0xf1, 0xf1, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x1f, 0x01, 0x01,
   0x01, 0x01, 0x01, 0x01, 0xf1, 0xf1, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
   0x1f, 0x1f, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01पूर्ण;
Hatches_type         p22_bits[] = अणु
   0x8f, 0x8f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xf8, 0xf8, 0x80, 0x80,
   0x80, 0x80, 0x80, 0x80, 0x8f, 0x8f, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
   0xf8, 0xf8, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80पूर्ण;
Hatches_type         p23_bits[] = अणु
   0xAA, 0xAA, 0x55, 0x55, 0x6a, 0x6a, 0x74, 0x74, 0x78, 0x78, 0x74, 0x74,
   0x6a, 0x6a, 0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0x6a, 0x6a, 0x74, 0x74,
   0x78, 0x78, 0x74, 0x74, 0x6a, 0x6a, 0x55, 0x55पूर्ण;
Hatches_type         p24_bits[] = अणु
   0x80, 0x00, 0xc0, 0x00, 0xea, 0xa8, 0xd5, 0x54, 0xea, 0xa8, 0xd5, 0x54,
   0xeb, 0xe8, 0xd5, 0xd4, 0xe8, 0xe8, 0xd4, 0xd4, 0xa8, 0xe8, 0x54, 0xd5,
   0xa8, 0xea, 0x54, 0xd5, 0xfc, 0xff, 0xfe, 0xffपूर्ण;
Hatches_type         p25_bits[] = अणु
   0x80, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0xff, 0xf0, 0xff, 0xf0,
   0xfb, 0xf0, 0xf9, 0xf0, 0xf8, 0xf0, 0xf8, 0x70, 0xf8, 0x30, 0xff, 0xf0,
   0xff, 0xf8, 0xff, 0xfc, 0xff, 0xfe, 0xff, 0xffपूर्ण;


#घोषणा MAXMK 100
अटल काष्ठा अणु
  पूर्णांक type;
  पूर्णांक n;
  XPoपूर्णांक xy[MAXMK];
पूर्ण marker;                        /* poपूर्णांक list to draw marker          */

/*
 *    Define some marker types ala PAW
 */
अटल लघु boxm[5][2] = अणु-1,-1, -1,1, 1,1, 1,-1, -1,-1पूर्ण;
अटल भग्न tupm[4][2] = अणु0.,1., 1.1547,-1., -1.1547,-1., 0.,1.पूर्ण;
अटल भग्न tdnm[4][2] = अणु0.,-1., -1.1547,1., 1.1547,1., 0.,-1.पूर्ण;

/*
 * Define some line dash styles (1..4)
 */
अटल लघु tdash[5][4] = अणु0,0,0,0,  6,6,0,0,  6,3,1,3,  1,6,0,0,  1,3,0,0पूर्ण;

/*
 *    Own/standard Color Palette corespondance table (in ixldgअगर())
 */
अटल अचिन्हित अक्षर tpal[256];
अटल अक्षर stdset=0; /* Std. Palette flag (in ixldgअगर()) */

/*
 *    Set input on or off
 */
व्योम
  setinput(inp)
पूर्णांक inp;
अणु
  XSetWinकरोwAttributes attributes;
  अचिन्हित दीर्घ attr_mask = 0;

  अगर( inp == 1 ) अणु
    attributes.event_mask = mouse_mask | keybd_mask;
    attr_mask |= CWEventMask;
    XChangeWinकरोwAttributes ( display, cws->winकरोw, attr_mask, &attributes);
  पूर्ण
  अन्यथा अणु
     attr_mask = 0;
     attributes.event_mask = NoEventMask;
     attr_mask |= CWEventMask;
     XChangeWinकरोwAttributes ( display, cws->winकरोw, attr_mask, &attributes);
  पूर्ण
पूर्ण


/*
 * set the क्रमeground color in GC
 */
व्योम
  setcolor( gc, ci )
GC gc;
पूर्णांक ci;
अणु
  अगर( colored && ( ci < 0 || ci >= MAXCOL || !colors[ci].defined ) )
    अणु
     ci = 0;
    पूर्ण
  अन्यथा अगर (!colored && ci < 0 )
    अणु
     ci = 0;
    पूर्ण
  अन्यथा अगर (!colored && ci > 0 )
    अणु
     ci = 1;
    पूर्ण

  XSetForeground( display, gc, colors[ci].pixel );

  /* make sure that क्रमeground and background are dअगरferent */
  अगर ( XGetGCValues( display, gc, gc_mask, &gc_वापस) ) अणु
     अगर ( gc_वापस.क्रमeground == gc_वापस.background )
        XSetBackground( display, gc, colors[!ci].pixel );
  पूर्ण अन्यथा अणु
     म_लिखो("**** Error: Cannot get GC values \n");
  पूर्ण
पूर्ण



/*
 *    INTEGER FUNCTION IXOPNDS(HOST)
 *    CHARACTER*(*) HOST  : host name
 *
 *    Open the display. Return -1 अगर the खोलोing fails
 */
पूर्णांक
  ixopnds( host )
अक्षर host[128];
अणु
  पूर्णांक lenhst;
  Pixmap pixmp1,pixmp2;
  XColor क्रमe,back;
  अक्षर **fontlist;
  पूर्णांक fontcount;
  पूर्णांक i;
  बाह्य अक्षर *दो_पर्या();

  lenhst=म_माप(host);

/*
 *              Try to खोलो the DISPLAY
 */
  अगर ( !isdisp ) अणु
     अगर( display == शून्य ) अणु
        अगर( lenhst == 0 ) अणु
           display = XOpenDisplay( दो_पर्या( "DISPLAY" ) );
        पूर्ण अन्यथा अणु
           display = XOpenDisplay( host );
        पूर्ण
        अगर( display == शून्य ) अणु ख_लिखो(मानक_त्रुटि, "The DISPLAY %s cannot be opened !\n", दो_पर्या("DISPLAY") ); वापस( -1 ); पूर्ण
     पूर्ण
  पूर्ण अन्यथा अणु
     वापस( 0 );
  पूर्ण

  screen_number = DefaultScreen( display );
  screen        = ScreenOfDisplay( display, screen_number);
  colored       = DisplayPlanes( display, screen_number ) > 1;

  अगर (colored) colormap = DefaultColormap( display, screen_number);

  colors[1].defined = 1; /* शेष क्रमeground */
  colors[1].pixel = BlackPixel( display, screen_number );
  colors[0].defined = 1; /* शेष background */
  colors[0].pixel = WhitePixel( display, screen_number );

/*
 *              Inquire the the XServer Venकरोr
 */
  म_नकल (venकरोr,XServerVenकरोr(display));

/*
 *              Create primitives graphic contexts
 */
  क्रम ( i = 0; i < MAXGC; i++ )
     gclist[i] = XCreateGC( display, RootWinकरोw( display, screen_number ),
                             0, शून्य );
     GCbuff[0] = XCreateGC( display, RootWinकरोw( display, screen_number ),
                             0, शून्य );
  अगर ( XGetGCValues( display, *gctext, gc_mask, &gc_वापस) ) अणु
     XSetForeground( display, *gcinvt, gc_वापस.background );
     XSetBackground( display, *gcinvt, gc_वापस.क्रमeground );
  पूर्ण अन्यथा अणु
     म_लिखो("**** Error: Cannot get GC values \n");
  पूर्ण

/*
 *              Create input echo graphic context
 */
  gcechov.क्रमeground = BlackPixel( display, screen_number );
  gcechov.background = WhitePixel( display, screen_number );
  अगर(म_माला(venकरोr,"Hewlett")) अणु
     gcechov.function   = GXxor;
  पूर्ण अन्यथा अणु
     gcechov.function   = GXinvert;
  पूर्ण
  gcecho = XCreateGC( display, RootWinकरोw( display, screen_number ),
                      GCForeground | GCBackground | GCFunction,
                      &gcechov );
/*
 *              Load a शेष Font
 */
  क्रम ( i = 0; i < MAXFONT; i++ ) अणु
     font[i].id = शून्य;
     म_नकल( font[i].name, " " );
  पूर्ण
  fontlist = XListFonts( display, "*courier*", 1, &fontcount );
  अगर ( fontcount != 0 ) अणु
     font[current_font_number].id = XLoadQueryFont( display, fontlist[0] );
     text_font = font[current_font_number].id;
     म_नकल( font[current_font_number].name, "*courier*" );
     current_font_number++;
     XFreeFontNames(fontlist);
  पूर्ण अन्यथा अणु
     म_लिखो("No default font loaded \n");
  पूर्ण
/*
 *              Create a null cursor
 */
  pixmp1 = XCreateBiपंचांगapFromData(display,
                                 RootWinकरोw( display, screen_number ),
                                 null_cursor_bits, 16, 16);
  pixmp2 = XCreateBiपंचांगapFromData(display,
                                 RootWinकरोw( display, screen_number ),
                                 null_cursor_bits, 16, 16);
  null_cursor = XCreatePixmapCursor(display,pixmp1,pixmp2,&क्रमe,&back,0,0);

  isdisp = 1;
  वापस( 0 );
पूर्ण


/*
 *    INTEGER FUNCTION IXOPNWI(X,Y,W,H,TITLE,FLAG)
 *    INTEGER X,Y         : initial winकरोw position
 *    INTEGER W,H         : initial winकरोw width and height
 *    CHARACTER*(*) TITLE : winकरोw title
 *    INTEGER FLAG        : FLAG<>1 allows to खोलो a non MOTIF winकरोw
 *                          even अगर ixmotअगर has been called.
 *
 *    Open winकरोw and वापसs winकरोw number which can be used with IXSELWIN
 *    वापस -1 अगर winकरोw creation fails
 */
पूर्णांक
  ixopnwi( x, y, w, h, title, flag)
पूर्णांक x, y;
पूर्णांक w, h;
अक्षर title[80];
पूर्णांक flag;
अणु
  XSetWinकरोwAttributes attributes;
  अचिन्हित दीर्घ attr_mask = 0;
  अक्षर दीर्घ_title[256];
  अक्षर host_name[64];
  XWMHपूर्णांकs wm_hपूर्णांकs;
  XSizeHपूर्णांकs size_hपूर्णांकs;
  XEvent event;
  पूर्णांक wid, i;
  पूर्णांक xval, yval;
  अचिन्हित पूर्णांक wval, hval, border, depth;
  Winकरोw root;

  अगर (बाह्यal_पूर्णांक == 1) अणु
     XGetGeometry( display, बाह्यal_winकरोw, &root,
                   &xval, &yval, &wval, &hval, &border, &depth );
  पूर्ण
  अन्यथा अणु
     xval = x;
     yval = y;
     wval = w;
     hval = h;
  पूर्ण

/*
 *              Select next मुक्त winकरोw number
 */
      क्रम ( wid = 0; wid < MAXWN; wid++ )
         अगर ( !winकरोws[wid].खोलो ) अणु
            winकरोws[wid].खोलो = 1;
            cws = &winकरोws[wid];
            cws->wid = wid;
            अवरोध;
         पूर्ण
/*
 *              Create a Motअगर winकरोw
 */
      अगर (motअगर_खोलो != शून्य && flag == 0) अणु
          cws->motअगर_winकरोw = (*motअगर_खोलो) (wid+1, xval, yval, wval, hval);
          अगर ( !cws->motअगर_winकरोw ) वापस( -1 );
          XGetGeometry( display, cws->motअगर_winकरोw, &root,
                        &xval, &yval, &wval, &hval, &border, &depth );
      पूर्ण

      अगर ( wid == MAXWN ) वापस( -1 );
/*
 *              Create winकरोw
 */
      attributes.background_pixel = colors[0].pixel;
      attr_mask |= CWBackPixel;
      attributes.border_pixel = colors[1].pixel;
      attr_mask |= CWBorderPixel;
      attributes.event_mask = NoEventMask;
      attr_mask |= CWEventMask;
      attributes.backing_store = Always;
      attr_mask |= CWBackingStore;
      अगर ( colored ) अणु
         attributes.colormap = colormap;
         attr_mask |= CWColormap;
      पूर्ण
      अगर (motअगर_खोलो != शून्य && flag == 0) अणु
         cws->winकरोw = XCreateWinकरोw(display, cws->motअगर_winकरोw,
                       xval, yval, wval, hval, 0, CopyFromParent,
                       InputOutput, CopyFromParent,
                       attr_mask, &attributes );
         cws->motअगर = 1;
      पूर्ण अन्यथा अणु
         अगर (बाह्यal_पूर्णांक == 1) अणु
            cws->winकरोw = XCreateWinकरोw(display, बाह्यal_winकरोw,
                          xval, yval, wval, hval, 0, CopyFromParent,
                          InputOutput, CopyFromParent,
                          attr_mask, &attributes );
            बाह्यal_पूर्णांक = 0;
            cws->motअगर = 1;
            cws->motअगर_winकरोw = बाह्यal_winकरोw;
         पूर्ण अन्यथा अणु
            cws->motअगर = 0;
            cws->winकरोw = XCreateWinकरोw(display,
                          RootWinकरोw( display, screen_number),
                          xval, yval, wval, hval, 1, CopyFromParent,
                          InputOutput, CopyFromParent,
                          attr_mask, &attributes );
            म_नकल( दीर्घ_title, title );
            अगर (दीर्घ_title[0] != '-') अणु
               म_जोड़ो( दीर्घ_title, " @ " );
               gethostname( host_name, माप( host_name ) );
               म_जोड़ो( दीर्घ_title, host_name );
            पूर्ण अन्यथा अणु
               दीर्घ_title[0] = ' ';
            पूर्ण
            XStoreName( display, cws->winकरोw, दीर्घ_title );
            XSetIconName( display, cws->winकरोw, दीर्घ_title );
         पूर्ण
      पूर्ण
/*
 *              Set winकरोw manager hपूर्णांकs
 */
      स_रखो( &wm_hपूर्णांकs, 0, माप(wm_hपूर्णांकs));
      wm_hपूर्णांकs.flags = InputHपूर्णांक;
      wm_hपूर्णांकs.input = False;  /* करोn't grab input focus */
      XSetWMHपूर्णांकs( display, cws->winकरोw, &wm_hपूर्णांकs );
/*
 *              Set winकरोw size hपूर्णांकs
 */
      स_रखो( &size_hपूर्णांकs, 0, माप(size_hपूर्णांकs));
      size_hपूर्णांकs.flags = USPosition | USSize;
      size_hपूर्णांकs.x = xval;
      size_hपूर्णांकs.y = yval;
      size_hपूर्णांकs.width = wval;
      size_hपूर्णांकs.height = hval;
      XSetNormalHपूर्णांकs( display, cws->winकरोw, &size_hपूर्णांकs );

      XMoveWinकरोw( display, cws->winकरोw, xval, yval );
      XResizeWinकरोw( display, cws->winकरोw, wval, hval );
      XMapWinकरोw( display, cws->winकरोw );
/*
      XFlush( display );
 *              Set the Class Hपूर्णांक
 */
      XSetClassHपूर्णांक(display, cws->winकरोw, &class_hपूर्णांकs);
/*
 *              Initialise the winकरोw काष्ठाure
 */
      cws->drawing        = cws->winकरोw;
      cws->buffer         = (Drawable)शून्य;
      cws->द्विगुन_buffer  = (पूर्णांक)शून्य;
      cws->clip           = (पूर्णांक)शून्य;
      cws->width          = wval;
      cws->height         = hval;
      cws->bgcol          = 0;

/*    Raise (and unclip) the winकरोw */

      क्रम( i = 0; i < MAXGC; i++ ) XSetClipMask( display, gclist[i], None );
      XRaiseWinकरोw( display, cws->winकरोw );

  XFlush( display );
  XSync( display, 1 );

  वापस( wid );
पूर्ण

/*
 *    SUBROUTINE IXRSCWI(WID, W, H)
 *    INTEGER WID  : Winकरोw identअगरier.
 *    INTEGER W    : Width
 *    INTEGER H    : Heigth
 *
 *    Rescale the winकरोw WID
 */
व्योम
   ixrscwi(wid, w, h)
  पूर्णांक wid;
  पूर्णांक w;
  पूर्णांक h;
अणु
  पूर्णांक i;

  tws = &winकरोws[wid];
/*
  अगर (!tws->खोलो) वापस;
*/

  XResizeWinकरोw( display, tws->winकरोw, w, h );

  अगर( tws->द्विगुन_buffer ) अणु
     XFreePixmap(display,tws->buffer);
     tws->buffer = XCreatePixmap(display, RootWinकरोw( display, screen_number),
                   w, h, DefaultDepth(display,screen_number));
     क्रम( i = 0; i < MAXGC; i++ ) XSetClipMask( display, gclist[i], None );
     setcolor( *gcpxmp, 0);
     XFillRectangle( display, tws->buffer, *gcpxmp, 0, 0, w, h);
     setcolor( *gcpxmp, 1);
     tws->drawing = tws->buffer;
  पूर्ण
  tws->width  = w;
  tws->height = h;
  XFlush( display );
पूर्ण

/*
 *    SUBROUTINE IXMOVWI(WID, X, Y)
 *    INTEGER WID  : Winकरोw identअगरier.
 *    INTEGER X    : Width
 *    INTEGER Y    : Heigth
 *
 *    Move the winकरोw WID
 */
व्योम
   ixmovwi(wid, x, y)
  पूर्णांक wid;
  पूर्णांक x;
  पूर्णांक y;
अणु
  पूर्णांक i;

  tws = &winकरोws[wid];
  अगर (!tws->खोलो) वापस;

  XMoveWinकरोw( display, tws->winकरोw, x, y );
पूर्ण

/*
 *    INTEGER FUNCTION IXOPNPX(W, H)
 *    INTEGER W,H : Width and height of the pixmap.
 *
 *    Open a new pixmap.
 */
पूर्णांक
  ixopnpx(w, h)
पूर्णांक w, h;
अणु
  Drawable pixtemp;
  Winकरोw root;
  अचिन्हित पूर्णांक wval, hval;
  पूर्णांक xx, yy, i ;
  अचिन्हित पूर्णांक ww, hh, border, depth;
  wval = w;
  hval = h;

  XGetGeometry( display, cws->drawing, &root, &xx, &yy, &ww, &hh, &border, &depth );

/*
  oldwin = cws->drawing;
  pixtemp = XCreatePixmap(display, RootWinकरोw( display, screen_number),
            wval, hval, DefaultDepth(display,screen_number));
  ispix = 1;
  क्रम( i = 0; i < MAXGC; i++ )
    XSetClipMask( display, gclist[i], None );
  cws->drawing = pixtemp;
  setcolor( *gcpxmp, 0);
  XFillRectangle( display, pixtemp, *gcpxmp,0 ,0 ,ww ,hh);
  setcolor( *gcpxmp, 1);
*/


  pixtemp = cws->drawing;
  वापस ( pixtemp );
पूर्ण


/*
 *    SUBROUTINE IXCLRPX(PIX)
 *    INTEGER PIX : Pixmap address
 *
 *    Clear the pixmap PIX.
 */
व्योम
  ixclrpx(pix )
Drawable pix;
अणु
  Winकरोw root;
  पूर्णांक xx, yy;
  अचिन्हित पूर्णांक ww, hh, border, depth;
  XGetGeometry( display, pix, &root, &xx, &yy, &ww, &hh, &border, &depth );
  setcolor( *gcpxmp, 0);
  XFillRectangle( display, pix, *gcpxmp,0 ,0 ,ww ,hh);
  setcolor( *gcpxmp, 1);
  XFlush( display );
पूर्ण


/*
 *    SUBROUTINE IXCLPX
 *
 *    Close the current खोलोed pixmap.
 */
व्योम
  ixclpx()
अणु
  XFlush( display );
  cws->drawing = oldwin;
  ispix = 0;
पूर्ण


/*
 *    SUBROUTINE IXCPPX(PIX, XPOS, YPOS)
 *    INTEGER PIX : Pixmap address
 *    INTEGER XPOS, YPOS : Pixmap Position
 *
 *    Copy the pixmap PIX at the position XPOS YPOS.
 */
व्योम
  ixcppx(pix, xpos, ypos)
Drawable pix;
पूर्णांक xpos, ypos;
अणु
  Winकरोw root;
  पूर्णांक xx, yy;
  XEvent event;
  अचिन्हित पूर्णांक ww, hh, border, depth;
  XGetGeometry( display, pix, &root, &xx, &yy, &ww, &hh, &border, &depth );

  XCopyArea(display,pix,cws->winकरोw,*gcpxmp,0,0,ww,hh,xpos,ypos);
/*
म_लिखो("pix geometry =  %d %d %d %d %d %d %d pos = %d %d que=%d\n", pix, xx, yy, ww, hh, border, depth, xpos, ypos, XEventsQueued( display, QueuedAlपढ़ोy));
*/
  XFlush( display );
पूर्ण


/*
 *    SUBROUTINE IXWRPX(PIX,W,H,LENNAME,PXNAME)
 *    INTEGER PIX : Pixmap address
 *    INTEGER W,H : Width and height of the pixmap.
 *    INTEGER LENNAME     : pixmap name length
 *    CHARACTER*(*) PXNAME: pixmap name
 *
 *    Write the pixmap IPX in the biपंचांगap file PXNAME.
 */
व्योम
  ixwrpx(pix, w, h, pxname )
अक्षर pxname[128];
Drawable pix;
पूर्णांक w, h;
अणु
  अचिन्हित पूर्णांक wval, hval;
  wval = w;
  hval = h;
  XWriteBiपंचांगapFile(display, pxname, pix, wval, hval, -1, -1);
पूर्ण

/*
व्योम
  ixrdpx( pix, w, h, pxname )
Drawable *pix;
पूर्णांक *w, *h;
अक्षर pxname[128];
अणु
  पूर्णांक x_hot_वापस, y_hot_वापस;
  अचिन्हित पूर्णांक width, height;
  अक्षर data[10000];
  पूर्णांक i;
  Winकरोw root;
  पूर्णांक xx, yy;
  अचिन्हित पूर्णांक ww, hh, border, depth=1;
  अचिन्हित दीर्घ fg = 0, bg = 1;


  i=XReadBiपंचांगapFileData(pxname,&width,&height,data,&x_hot_वापस,&y_hot_वापस);
  *w = width;
  *h = height;
  *pix=XCreatePixmapFromBiपंचांगapData(display,RootWinकरोw( display, screen_number),data,width,height,fg,bg,depth);
  XGetGeometry( display, *pix, &root, &xx, &yy, &ww, &hh, &border, &depth );

  म_लिखो("XReadBitmapFile: %d %d %d depth = %d\n", i, BiपंचांगapSuccess, *pix, depth);
पूर्ण
*/

/*
 *    SUBROUTINE IXWIPX(PIX, XPOS, YPOS)
 *    INTEGER PIX : Pixmap address
 *    INTEGER XPOS, YPOS : Position in the current winकरोw
 *
 *    Copy the area at the position XPOS YPOS in the current
 *    winकरोw in the pixmap PIX. The area copied has the size
 *    of the pixmap PIX.
 */
व्योम
  ixwipx(pix, xpos, ypos )
Drawable pix;
पूर्णांक xpos, ypos;
अणु
  Winकरोw root;
  पूर्णांक xx, yy;
  अचिन्हित पूर्णांक ww, hh, border, depth;
  XGetGeometry( display, cws->winकरोw, &root, &xx, &yy, &ww, &hh, &border, &depth );

म_लिखो("window Depth = %d\n", depth);
  XGetGeometry( display, pix, &root, &xx, &yy, &ww, &hh, &border, &depth );
म_लिखो("pix Depth = %d\n", depth);
  XCopyArea(display,cws->winकरोw,pix,*gcpxmp,xpos,ypos,ww,hh,0,0);
पूर्ण

/* IXGETPX
 *
 */
Drawable
  ixgetpx( xpos, ypos, width, height )
पूर्णांक xpos, ypos, width, height;
अणु
  Winकरोw root;
  Drawable pix;
  पूर्णांक xx, yy;
  अचिन्हित पूर्णांक ww, hh, border, depth;

  pix = XCreatePixmap(display, RootWinकरोw( display, screen_number),
        width, height, DefaultDepth(display,screen_number));
/*
  XGetGeometry( display, cws->winकरोw, &root, &xx, &yy, &ww, &hh, &border, &depth );
म_लिखो("window Depth = %d\n", depth);
  XGetGeometry( display, pix, &root, &xx, &yy, &ww, &hh, &border, &depth );
म_लिखो("pix Depth = %d\n", depth);
*/
  XCopyArea(display, cws->winकरोw, pix, *gcpxmp, xpos,ypos, width,height, 0,0);

  वापस (pix);
पूर्ण

/*
 *    SUBROUTINE IXRMPX(PIX)
 *    INTEGER PIX : Pixmap adress
 *
 *    Remove the pixmap PIX.
 */
व्योम
  ixrmpx(pix)
Drawable pix;
अणु
  XFreePixmap(display,pix);
पूर्ण


/*
 *    SUBROUTINE IXCLSDS
 *
 *    Delete all winकरोws and बंद connection
 */
व्योम
  ixclsds()
अणु
  पूर्णांक Motअगर = (पूर्णांक)शून्य;
  पूर्णांक i;

  अगर(display == शून्य) वापस;

  क्रम( i = 0; i < MAXFONT; i++ ) अणु
    अगर ( font[i].id ) अणु
       XFreeFont ( display, font[i].id);
       font[i].id = शून्य;
    पूर्ण
  पूर्ण

  क्रम( i = 0; i < MAXWN; i++ ) अणु
    winकरोws[i].खोलो = 0;
    अगर( winकरोws[i].motअगर )
       Motअगर = 1;
  पूर्ण
  अगर(display != शून्य && Motअगर == (पूर्णांक)शून्य) XCloseDisplay( display );
  display = शून्य;
  cws     = शून्य;
  tws     = शून्य;
  isdisp  = 0;
पूर्ण


/*
 *    SUBROUTINE IXCLSWI
 *
 *    Delete current winकरोw
 *    Modअगरied by Mario Stipcevic to बंद specअगरic or current winकरोw
 *    win >= MAXWN वापस without any action
 *    win <  0     बंद the current winकरोw
 *    win          बंद the winकरोw 'wid', अगर it exists. If not, just निकास.
 *                 If बंदd winकरोw is the last, perक्रमm ixclsds()
 */
व्योम
  ixclswi(win)
पूर्णांक win;
अणु
  पूर्णांक wid, flag;
  XEvent event;

  अगर (win >= MAXWN) वापस;
  अगर (win < 0) tws = cws;
  अगर (win >= 0 &&  winकरोws[win].खोलो) अणु
   tws = &winकरोws[win];
  पूर्ण अन्यथा अणु
   अगर (win >= 0) वापस;
  पूर्ण
  अगर (tws == cws) flag = 1;

  XDestroyWinकरोw( display, tws->winकरोw );

  अगर( tws->द्विगुन_buffer ) XFreePixmap( display, tws->buffer);

  अगर (tws->motअगर && motअगर_बंद != शून्य) अणु
      क्रम( wid = 0; wid < MAXWN; wid++ ) अणु
           अगर (tws->motअगर_winकरोw == winकरोws[wid].motअगर_winकरोw) अणु
               (*motअगर_बंद) (wid+1);
               अवरोध; पूर्ण
      पूर्ण
  पूर्ण

  tws->खोलो = (पूर्णांक)शून्य;

  XFlush( display );
  जबतक (XEventsQueued(display,QueuedAlपढ़ोy) > 0) XNextEvent(display,&event);

  अगर (flag) अणु

   क्रम( wid = MAXWN - 1; wid >= 0; wid-- )
    अगर( winकरोws[wid].खोलो ) अणु
     cws = &winकरोws[wid];
     वापस;
    पूर्ण

    ixclsds(); /* no खोलो winकरोw left */
   पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXSELWI(WID)
 *    INTEGER WID : winकरोw number वापसed by IXOPNWI
 *
 *    Select and उठाओ a winकरोw to which subsequent output is directed
 */
व्योम
  ixselwi( wid )
पूर्णांक wid;
अणु
  XRectangle region;
  पूर्णांक i, bcolor;

  अगर (wid != -1) अणु
   अगर( wid < 0 || wid >= MAXWN || !winकरोws[wid].खोलो ) वापस;
   cws = &winकरोws[wid];
  पूर्ण

  अगर ( cws->clip && !ispix && !cws->द्विगुन_buffer ) अणु
    region.x      = cws->xclip;
    region.y      = cws->yclip;
    region.width  = cws->wclip;
    region.height = cws->hclip;
    क्रम( i = 0; i < MAXGC; i++ )
      XSetClipRectangles( display, gclist[i], 0, 0, &region, 1, YXBanded );
  पूर्ण अन्यथा अणु
    क्रम( i = 0; i < MAXGC; i++ )
      XSetClipMask( display, gclist[i], None );
  पूर्ण

  /* Set background color क्रम this winकरोw (Mario S.) */
  bcolor = cws->bgcol;
  अगर (bcolor == 0) अणु
   colors[0].pixel = WhitePixel( display, screen_number );
  पूर्ण अन्यथा अणु
   colors[0] = colors[bcolor];
  पूर्ण
  XSetWinकरोwBackground( display, cws->drawing, colors[0].pixel );

  XRaiseWinकरोw( display, cws->winकरोw );
  XFlush( display );
पूर्ण


/*
 *    SUBROUTINE IXGETGE(WID,X,Y,W,H)
 *    INTEGER WID : winकरोw identअगरier
 *    INTEGER X,Y : winकरोw position (output)
 *    INTEGER W,H : winकरोw size (output)
 *
 *    Return position and size of winकरोw wid
 *    अगर wid < 0 the size of the display is वापसed
 */
व्योम
   ixgetge( wid, x, y, w, h )
पूर्णांक wid;
पूर्णांक *x, *y;
अचिन्हित पूर्णांक *w, *h;
अणु
  Winकरोw temp_win;
  Display *पंचांगp_display;

  /* If workstation not खोलोed, वापस root display geometry */
  अगर (display == शून्य) अणु
    *x = 0;
    *y = 0;
    *w = 0;
    *h = 0;
    अगर( wid < 0 ) अणु
     पंचांगp_display = XOpenDisplay( दो_पर्या( "DISPLAY" ) );
     screen_number = DefaultScreen( पंचांगp_display );
     *w = DisplayWidth(पंचांगp_display,screen_number);
     *h = DisplayHeight(पंचांगp_display,screen_number);
     XCloseDisplay( पंचांगp_display );
     वापस;
    पूर्ण
  पूर्ण
  अगर( wid < 0 ) अणु
    *x = 0;
    *y = 0;
    *w = DisplayWidth(display,screen_number);
    *h = DisplayHeight(display,screen_number);
  पूर्ण अन्यथा अणु
    Winकरोw root;
    अचिन्हित पूर्णांक border, depth;
    अचिन्हित पूर्णांक width, height;

    tws = &winकरोws[wid];
    XGetGeometry(display, tws->drawing, &root, x, y,
                 &width, &height, &border, &depth);
    (व्योम) XTranslateCoordinates (display, tws->winकरोw,
                                 RootWinकरोw( display, screen_number),
                                   0, 0, x, y, &temp_win);
    अगर( width > 0 && height > 0 ) अणु
      tws->width  = width;
      tws->height = height;
    पूर्ण
    अगर( width > 1 && height > 1 ) अणु
      *w=tws->width-1;
      *h=tws->height-1;
    पूर्ण अन्यथा अणु
      *w=1;
      *h=1;
    पूर्ण
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXGETPL(NPLANES)
 *    INTEGER NPLANES     : number of bit planes
 *
 *    Get maximum number of planes
 */
व्योम
   ixgetpl(nplanes)
पूर्णांक *nplanes;
अणु
   *nplanes = DisplayPlanes( display, screen_number );
पूर्ण


/*
 *    SUBROUTINE IXRSIZ(WID)
 *    INTEGER WID     : winकरोw to be resized
 *
 *    Resize the current winकरोw अगर necessary
 */
व्योम
   ixrsiz(wid)
पूर्णांक wid;
अणु
  पूर्णांक i;
  पूर्णांक xval, yval;
  Winकरोw root;
  अचिन्हित पूर्णांक wval, hval, border, depth;

  tws = &winकरोws[wid];

  अगर( !tws->motअगर ) वापस;

  XGetGeometry( display, tws->motअगर_winकरोw, &root,
                &xval, &yval, &wval, &hval, &border, &depth );
  XResizeWinकरोw( display, tws->winकरोw, wval, hval );

  अगर( tws->द्विगुन_buffer ) अणु
     XFreePixmap(display,tws->buffer);
     tws->buffer = XCreatePixmap(display, RootWinकरोw( display, screen_number),
                   wval, hval, DefaultDepth(display,screen_number));
     क्रम( i = 0; i < MAXGC; i++ ) XSetClipMask( display, gclist[i], None );
     setcolor( *gcpxmp, 0);
     XFillRectangle( display, tws->buffer, *gcpxmp, 0, 0, wval, hval);
     setcolor( *gcpxmp, 1);
     tws->drawing        = tws->buffer;
  पूर्ण
  tws->width = wval;
  tws->height = hval;
पूर्ण


/*
 *    SUBROUTINE IXGETWI(WKID,IDG)
 *    INTEGER WKID : Workstation identअगरier (input)
 *    INTEGER IDG  : Winकरोw identअगरier (output)
 *
 *    Return the X11 winकरोw identअगरier according to the
 *    Winकरोw id वापसed by IXOPNWI.
 */
व्योम
   ixgetwi (wkid, idg)
   पूर्णांक wkid;
   Winकरोw *idg;
अणु
   *idg = winकरोws[wkid].winकरोw;
पूर्ण

/*
 *    SUBROUTINE IXCLRWI
 *
 *    Clear current winकरोw
 */
व्योम
  ixclrwi()
अणु

  अगर ( !cws->buffer ) अणु
/*
  अगर ( !ispix && !cws->द्विगुन_buffer ) अणु
     XSetWinकरोwBackground( display, cws->drawing, colors[0].pixel );
*/
     XClearWinकरोw( display, cws->drawing );
  पूर्ण अन्यथा अणु
     setcolor( *gcbuff, 0);
     XFillRectangle( display, cws->buffer, *gcbuff,
                     0, 0, cws->width, cws->height );
     setcolor( *gcbuff, 1);
  पूर्ण
  करो_उठाओ = 1;
  XFlush( display );
पूर्ण


/*
 * Change the background क्रम the current winकरोw to bcolor Pallete index
*/
व्योम
  ixsetbg( bcolor )
  पूर्णांक bcolor;
अणु
  cws->bgcol = bcolor;
  अगर (bcolor == 0) अणु
   colors[0].pixel = WhitePixel( display, screen_number );
  पूर्ण अन्यथा अणु
   colors[0] = colors[bcolor];
  पूर्ण

  XSetWinकरोwBackground( display, cws->drawing, colors[0].pixel );
  करो_उठाओ = 1;
पूर्ण

/*
 *    SUBROUTINE IXUPDWI(MODE)
 *    INTEGER MODE : (1) or (11) The winकरोw is उठाओd
 *                   (0) or (10) The winकरोw is not उठाओd
 *                   (0) or (1)  no synchonisation between client and server
 *                  (10) or (11) synchonisation between client and server
 *
 *    Update display and उठाओ current winकरोw to top of stack.
 *    Synchronise client and server once (not permanent).
 *    Copy the pixmap cws->buffer on the winकरोw cws-> winकरोw
 *    अगर the द्विगुन buffer is on.
 */
व्योम
  ixupdwi(mode)
  पूर्णांक mode;
अणु
  अगर (display == शून्य) वापस;
  अगर ( mode == 1 || mode == 11 ) अणु
     अगर ( करो_उठाओ ) अणु
        XRaiseWinकरोw( display, cws->winकरोw );
        करो_उठाओ = 0;
     पूर्ण
  पूर्ण
  अगर ( cws->buffer ) अणु
     XCopyArea( display, cws->buffer, cws->winकरोw,
                *gcbuff, 0, 0, cws->width, cws->height, 0, 0 );
  पूर्ण
  अगर ( mode == 0 || mode == 1 ) अणु
    XFlush( display );
  पूर्ण अन्यथा अणु
    XSync( display ,0);
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXCLIP(WID,X,Y,W,H)
 *    INTEGER WID : Winकरोw indentअगरier
 *    INTEGER X,Y : origin of clipping rectangle
 *    INTEGER W,H : size of clipping rectangle;
 *
 *    Set clipping region क्रम the winकरोw wid
 */
व्योम
  ixclip( wid, x, y, w, h )
पूर्णांक wid;
पूर्णांक x, y;
पूर्णांक w, h;
अणु
  XRectangle region;
  पूर्णांक i;

  tws = &winकरोws[wid];
  tws->xclip = x;
  tws->yclip = y;
  tws->wclip = w;
  tws->hclip = h;
  tws->clip  = 1;
  अगर ( cws->clip && !ispix && !cws->द्विगुन_buffer ) अणु
    region.x      = cws->xclip;
    region.y      = cws->yclip;
    region.width  = cws->wclip;
    region.height = cws->hclip;
    क्रम( i = 0; i < MAXGC; i++ )
      XSetClipRectangles( display, gclist[i], 0, 0, &region, 1, YXBanded );
  पूर्ण
पूर्ण

/* BASIC implementation of clipping function: */
व्योम
  ixclip1( wid, x1, y1, x2, y2 )
पूर्णांक wid;
पूर्णांक x1, y1;
पूर्णांक x2, y2;
अणु
  पूर्णांक w, h;
  w = x2 - x1 + 1;
  h = y2 - y1 + 1;
  ixclip( wid, x1, y1, w, h);
पूर्ण

/*
 *    SUBROUTINE IXNOCLI(WID)
 *    INTEGER WID : Winकरोw indentअगरier
 *
 *    Switch off the clipping क्रम the winकरोw wid
 */
व्योम
  ixnocli(wid)
पूर्णांक wid;
अणु
  पूर्णांक i;

  tws       = &winकरोws[wid];
  tws->clip = (पूर्णांक)शून्य;

  क्रम( i = 0; i < MAXGC; i++ )
    XSetClipMask( display, gclist[i], None );
पूर्ण


/*
 *    SUBROUTINE IXSETCO(CINDEX,R,G,B)
 *    INTEGER CINDEX : color index
 *    REAL R,G,B     : red, green, blue पूर्णांकensities between 0.0 and 1.0
 *
 *    Set color पूर्णांकensities क्रम given color index
 */
#घोषणा BIGGEST_RGB_VALUE 65535

व्योम
  ixsetco( cindex, r, g, b )
पूर्णांक cindex;
पूर्णांक r, g, b;
अणु
  XColor xcol;

  अगर( colored && cindex >= 0 && cindex < MAXCOL ) अणु
   xcol.red   = (अचिन्हित लघु)( (r /255.) * BIGGEST_RGB_VALUE );
   xcol.green = (अचिन्हित लघु)( (g /255.) * BIGGEST_RGB_VALUE );
   xcol.blue  = (अचिन्हित लघु)( (b /255.) * BIGGEST_RGB_VALUE );
   xcol.flags = DoRed || DoGreen || DoBlue;
   अगर( colors[cindex].defined == 1 ) अणु
    /* म_लिखो("Warning: color = %d redefined\n", cindex); */
    colors[cindex].defined = 0;
    XFreeColors(display, colormap, &colors[cindex].pixel, 1, शून्य);
   पूर्ण
   अगर( XAllocColor( display, colormap, &xcol ) != (Status)शून्य ) अणु
    colors[cindex].defined = 1;
    colors[cindex].pixel   = xcol.pixel;
    colors[cindex].red     = r;
    colors[cindex].green   = g;
    colors[cindex].blue    = b;
   पूर्ण
  पूर्ण
पूर्ण


व्योम
  ixअ_लोol( index, r, g, b)
पूर्णांक index; /* input */
पूर्णांक *r, *g, *b; /* output */
अणु
  *r = colors[index].red;
  *g = colors[index].green;
  *b = colors[index].blue;
  वापस ;
पूर्ण

/*
 *    SUBROUTINE IXSETLN(WIDTH)
 *    INTEGER WIDTH : line width in pixels
 *
 *    Set line width
 */
व्योम
  ixsetln( width )
पूर्णांक width;
अणु
  अगर( width == 1) अणु
     line_width = 0;
  पूर्ण
  अन्यथा अणु
     line_width = width;
  पूर्ण
  XSetLineAttributes( display, *gcline, line_width,
              line_style, cap_style, join_style );
  XSetLineAttributes( display, *gcdash, line_width,
              line_style, cap_style, join_style );
पूर्ण


/*
 *    SUBROUTINE IXSETLS(N,DASH)
 *    INTEGER N       : length of dash list
 *    INTEGER DASH(N) : dash segment lengths
 *
 *    Set line style:
 *    अगर N.EQ.0 use solid lines
 *    अगर N.LT.0 use predefined tdash[][] dashed style of type -N (1..4)
 *    अगर N.GT.0 use dashed lines described by DASH(N), 2 <= N <= 10 (even)
 *    e.g. N=4,DASH=(6,3,1,3) gives a dashed-करोtted line with 6 करोts,
 *    followed by 3 blanks followed by 1 करोt followed by 3 blanks
 */
व्योम
  ixsetls( n, dash )
पूर्णांक n;
लघु *dash;
अणु
  पूर्णांक i, j;
  अगर (n > 16) n = 16;
  अगर( n == 0 ) अणु
    line_style = LineSolid;
    dash_nseg = 1;
    XSetLineAttributes( display, *gcline, line_width,
              line_style, cap_style, join_style );
    वापस;
  पूर्ण

  dash_length = 0;
  dash_offset = 0;
  line_style = LineOnOffDash;

  अगर ( n > 0 ) /* input type */
  अणु
   dash_nseg = n;
   क्रम( i = 0; i < n; i++ ) अणु
    dash_list[i] = dash[i];
    dash_length += dash_list[i];
   पूर्ण
  पूर्ण

  अगर ( n < 0 ) /* predefined types */
  अणु
   n = -n;
   चयन (n) अणु
           हाल 1: j = 2;
                   अवरोध;
           हाल 2: j = 4;
                   अवरोध;
           हाल 3: j = 2;
                   अवरोध;
           हाल 4: j = 2;
                   अवरोध;
   पूर्ण
   dash_nseg = j;
   क्रम( i = 0; i < j; i++ ) अणु
    dash_list[i] = tdash[n][i];
    dash_length += dash_list[i];
   पूर्ण
  पूर्ण
  XSetLineAttributes( display, *gcdash, line_width,
             line_style, cap_style, join_style );
पूर्ण

व्योम
  ixsetld( lt )
पूर्णांक lt;
/* Set dashing style via 16-bit पूर्णांकeger mask. Use lower 16 bits */
अणु
 पूर्णांक i=0, j, n=0, m, mask=1, flag, offset=0;
 लघु dash[16];

 flag=lt & mask;
 जबतक(i<16) अणु
  j = 0;
  m = lt & mask;
  जबतक(i<16 && (lt & mask)==m) अणु
   i++; j++; lt >>= 1;
  पूर्ण
  dash[n++]=j;
 पूर्ण
 अगर(!flag) अणु
  offset = dash[0];
  क्रम(i=1; i<n; i++) dash[i-1]=dash[i];
  dash[n-1]=offset;
  offset=-offset;
  अगर(n%2 != 0) अणुn--; dash[n-1]+=dash[n];पूर्ण
 पूर्ण अन्यथा अणु
  अगर(n%2 != 0) अणुn--; dash[0]+=dash[n]; offset = dash[n];पूर्ण
 पूर्ण
/*
 म_लिखो("n =%d offset=%d\n", n, offset);
 क्रम(i=0; i<n; i++) म_लिखो("i=%d dash=%d\n", i, dash[i]);
*/
 ixsetls( n, dash );
 dash_offset = offset;
पूर्ण


/*
 *    SUBROUTINE IXSETLC(CINDEX)
 *    INTEGER CINDEX : color index defined my IXSETCOL
 *
 *    Set color index क्रम lines
 */
व्योम
  ixsetlc( cindex )
पूर्णांक cindex;
अणु
  setcolor( *gcline, cindex );
  setcolor( *gcdash, cindex );
पूर्ण


/*
 *    SUBROUTINE IXLINE(N,XY)
 *    INTEGER N         : number of poपूर्णांकs
 *    INTEGER*2 XY(2,N) : list of poपूर्णांकs
 *
 *    Draw a line through all poपूर्णांकs
 */
व्योम
  ixline( n, Rxy )
पूर्णांक n;
XPoपूर्णांक *Rxy;
अणु
 XPoपूर्णांक *xy;
 पूर्णांक i;

 अगर (rotate_fl || scale_fl || trans_fl) अणु
  xy = (XPoपूर्णांक *)सुस्मृति(n, माप(XPoपूर्णांक));
  क्रम (i = 0; i < n; i++) अणु
   xy[i].x=xOrig+Rco*scalex*(Rxy[i].x-xRO)+Rsi*scaley*(Rxy[i].y-yRO);
   xy[i].y=yOrig-Rsi*scalex*(Rxy[i].x-xRO)+Rco*scaley*(Rxy[i].y-yRO);
  पूर्ण
 पूर्ण अन्यथा अणु
  xy = Rxy;
 पूर्ण
/*
म_लिखो("1: %d, %d, %d, %d, %d, %d, %d, %d\n",Rxy[0].x,Rxy[0].y,Rxy[1].x,Rxy[1].y, Rxy[2].x,Rxy[2].y, Rxy[3].x,Rxy[3].y);
म_लिखो("2: %d, %d, %d, %d, %d, %d, %d, %d\n",xy[0].x,xy[0].y,xy[1].x,xy[1].y, xy[2].x,xy[2].y,xy[3].x,xy[3].y);
म_लिखो("3: Rsi=%f, Rco=%f, sx=%f, sy=%f, xO=%d, yO=%d, xRO=%d, yRO=%d\n",Rsi, Rco, scalex, scaley, xOrig, yOrig, xRO, yRO);
*/

 अगर ( n > 1 )
    अणु
       अगर( line_style == LineSolid )
         अगर (cws->buffer) अणु
          XDrawLines( display, cws->buffer, *gcline, xy, n, CoordModeOrigin );
         पूर्ण अन्यथा अणु
          XDrawLines( display, cws->drawing, *gcline, xy, n, CoordModeOrigin );
         पूर्ण
       अन्यथा अणु
         पूर्णांक i;
         XSetDashes( display, *gcdash,
             dash_offset, dash_list, dash_nseg );
         XDrawLines( display, cws->drawing, *gcdash, xy, n, CoordModeOrigin );

         /* calculate length of line to update dash offset */
/* Doesn't work well anyway (Mario)
         क्रम( i = 1; i < n; i++ ) अणु
          पूर्णांक dx = xy[i].x - xy[i-1].x;
          पूर्णांक dy = xy[i].y - xy[i-1].y;
          अगर( dx < 0 ) dx = - dx;
          अगर( dy < 0 ) dy = - dy;
          dash_offset += dx > dy ? dx : dy;
         पूर्ण
         dash_offset %= dash_length;
*/
       पूर्ण
    पूर्ण
 अन्यथा
    अणु
     XDrawPoपूर्णांक(display, cws->drawing,
        line_style == LineSolid ? *gcline : *gcdash, xy[0].x, xy[0].y);
    पूर्ण
   करो_उठाओ = 1;
पूर्ण


/*
 *    SUBROUTINE IXSETMS(TYPE,N,XY)
 *    INTEGER TYPE      : marker type
 *    INTEGER N         : length of marker description
 *    INTEGER*2 XY(2,N) : list of poपूर्णांकs describing marker shape
 *
 *    Set marker style:
 *    अगर N.EQ.0 marker is a single poपूर्णांक
 *    अगर TYPE.EQ.0 marker is hollow circle of diameter N
 *    अगर TYPE.EQ.1 marker is filled circle of diameter N
 *    अगर TYPE.EQ.2 marker is a hollow polygon describe by line XY
 *    अगर TYPE.EQ.3 marker is a filled polygon describe by line XY
 *    अगर TYPE.EQ.4 marker is described by segmented line XY
 *    e.g. TYPE=4,N=4,XY=(-3,0,3,0,0,-3,0,3) sets a plus shape of 7x7 pixels
 */
व्योम
  ixseपंचांगs( type, n, xy )
पूर्णांक type;
पूर्णांक n;
XPoपूर्णांक *xy;
अणु
  पूर्णांक i;

  marker.type = type;
  marker.n = n < MAXMK ? n : MAXMK;
  अगर( marker.type >= 2 )
    क्रम( i = 0; i < marker.n; i++ )
      marker.xy[i] = xy[i];
पूर्ण


/*   SUBROUTINE IXSETMTS( TYPE, SIZE )
 *   Author: Mario Stipcevic
 * A set of predefined markers ala PAW */
/* type  0 or 20 = filled circle
 *       1 or 21 = filled box
 *       2 or 22 = filled triangle poपूर्णांकing up
 *       3 or 23 = filled triangle poपूर्णांकing करोwn
 *       4 or 24 = hollow circle
 *       5 or 25 = hollow box
 *       6 or 26 = hollow triangle poपूर्णांकing up
 *       7 or 27 = hollow triangle poपूर्णांकing करोwn
*/
व्योम
  ixseपंचांगts( type, size )
पूर्णांक type;
पूर्णांक size;
अणु
 पूर्णांक i, fill;
 भग्न siz;
 लघु पूर्णांक xy[10][2];

 fill = 3;
 siz = (1 + size) / 2.;
 अगर (type >= 20) type = type - 20;
 अगर (type >= 4) fill = 2;
 अगर (type == 0) अणु ixseपंचांगs( 1, size, xy ); वापस; पूर्ण
 अगर (type == 4) अणु ixseपंचांगs( 0, size, xy ); वापस; पूर्ण
 अगर (type == 1 || type == 5) अणु
  क्रम(i = 0; i < 5; xy[i][0]=siz*boxm[i][0], xy[i][1]=siz*boxm[i][1], i++);
  ixseपंचांगs( fill, 5, xy ); वापस; पूर्ण
 अगर (type == 2 || type == 6) अणु
  क्रम(i = 0; i < 4; xy[i][0]=siz*tupm[i][0], xy[i][1]=siz*tupm[i][1], i++);
  ixseपंचांगs( fill, 4, xy ); वापस; पूर्ण
 अगर (type == 3 || type == 7) अणु
  क्रम(i = 0; i < 4; xy[i][0]=siz*tdnm[i][0], xy[i][1]=siz*tdnm[i][1], i++);
  ixseपंचांगs( fill, 4, xy ); वापस; पूर्ण

पूर्ण


/*
 *    SUBROUTINE IXSETMC(CINDEX)
 *    INTEGER CINDEX : color index defined my IXSETCOL
 *
 *    Set color index क्रम markers
 */
व्योम
  ixseपंचांगc( cindex )
पूर्णांक cindex;
अणु
  setcolor( *gcmark, cindex );
पूर्ण


/*
 *    SUBROUTINE IXMARKE(N,XY)
 *    INTEGER N         : number of poपूर्णांकs
 *    INTEGER*2 XY(2,N) : list of poपूर्णांकs
 *
 *    Draw a marker at each poपूर्णांक
 */
व्योम
   ixmarke( n, Rxy )
पूर्णांक n;
XPoपूर्णांक *Rxy;
अणु
  XPoपूर्णांक *xy;
  पूर्णांक i;
  Drawable d;

  अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

  अगर (rotate_fl || scale_fl || trans_fl) अणु
   xy = (XPoपूर्णांक *)सुस्मृति(n, माप(XPoपूर्णांक));
   क्रम (i = 0; i < n; i++) अणु
    xy[i].x=xOrig+Rco*scalex*(Rxy[i].x-xRO)+Rsi*scaley*(Rxy[i].y-yRO)+.5;
    xy[i].y=yOrig-Rsi*scalex*(Rxy[i].x-xRO)+Rco*scaley*(Rxy[i].y-yRO)+.5;
   पूर्ण
  पूर्ण अन्यथा अणु
   xy = Rxy;
  पूर्ण

  करो_उठाओ = 1;
  अगर( marker.n <= 0 )
    XDrawPoपूर्णांकs( display, d, *gcmark, xy, n, CoordModeOrigin );
  अन्यथा अणु
    पूर्णांक r = marker.n / 2;
    पूर्णांक m;

    क्रम( m = 0; m < n; m++ ) अणु
      पूर्णांक hollow = 0;

      चयन( marker.type ) अणु
      पूर्णांक i;

      हाल 0:        /* hollow circle */
      XDrawArc( display, d, *gcmark,
          xy[m].x - r, xy[m].y - r, marker.n, marker.n, 0, 360 * 64 );
      अवरोध;

      हाल 1:        /* filled circle */
      XFillArc( display, d, *gcmark,
          xy[m].x - r, xy[m].y - r, marker.n, marker.n, 0, 360 * 64 );
    /* For Xlibs with ugly XFillArc: */
      XDrawArc( display, d, *gcmark,
          xy[m].x - r, xy[m].y - r, marker.n, marker.n, 0, 360 * 64 );
      अवरोध;

      हाल 2:        /* hollow polygon */
      hollow = 1;
      हाल 3:        /* filled polygon */
      क्रम( i = 0; i < marker.n; i++ ) अणु
        marker.xy[i].x += xy[m].x;
        marker.xy[i].y += xy[m].y;
      पूर्ण
      अगर( hollow )
        XDrawLines( display, d, *gcmark,
              marker.xy, marker.n, CoordModeOrigin );
      अन्यथा
        XFillPolygon( display, d, *gcmark,
                marker.xy, marker.n, Nonconvex, CoordModeOrigin );
      क्रम( i = 0; i < marker.n; i++ ) अणु
        marker.xy[i].x -= xy[m].x;
        marker.xy[i].y -= xy[m].y;
      पूर्ण
      अवरोध;

      हाल 4:        /* segmented line */
      क्रम( i = 0; i < marker.n; i += 2 )
        XDrawLine( display, d, *gcmark,
             xy[m].x + marker.xy[i].x, xy[m].y + marker.xy[i].y,
             xy[m].x + marker.xy[i+1].x, xy[m].y + marker.xy[i+1].y );
      अवरोध;
      पूर्ण
    पूर्ण
  पूर्ण
पूर्ण

/*
 *    SUBROUTINE IXCIRC(x0, y0, r, angle1, angle2, aspect)
 *    Author: Mario Stipcevic
 *    Simple पूर्णांकerface to ixarc क्रम QB's CIRCLE
 */
पूर्णांक
   ixcirc( x0, y0, r, phi1, phi2, aspect )
पूर्णांक x0, y0, r;
भग्न phi1, phi2, aspect; /* start and stop angles in radians */
अणु
  अटल भग्न f = 57.295779512;
  ixarc(x0, y0, r, (पूर्णांक)(aspect*r+.5), (पूर्णांक)(f*phi1+.5), (पूर्णांक)(f*phi2+.5), 0);
पूर्ण

/*
 *    SUBROUTINE IXARC(x0, y0, rh, rv, angle1, angle2, अगरill)
 *    Author: Mario Stipcevic
 *
 *    Draw an arc
 *    center: (x0, y0)
 *    horiz. and vert. radii: rh, rv
 *    start and stop angles in degrees: angle1, angle2
 *    अगरill= 0 (hollow), 1 (filled)
 */
पूर्णांक
   ixarc( Rx0, Ry0, rx, ry, ang1, ang2, अगरill )
पूर्णांक Rx0, Ry0, rx, ry, ang1, ang2, अगरill;
अणु
  पूर्णांक x, y;
  पूर्णांक ang;
  अटल भग्न f = 57.295779512;
  Drawable d;

  अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

  अगर (rotate_fl || scale_fl || trans_fl) अणु
   x = xOrig + Rco * scalex * (Rx0 - xRO) + Rsi * scaley * (Ry0 - yRO)+.5;
   y = yOrig - Rsi * scalex * (Rx0 - xRO) + Rco * scaley * (Ry0 - yRO)+.5;
   rx = भ_असल(scalex) * rx;
   ry = भ_असल(scaley) * ry;
   अगर (scalex < 0 && scaley < 0) अणु
    ang1 = 180 + ang1; ang2 = 180 + ang2;
   पूर्ण अन्यथा अणु
    अगर (scalex < 0.) अणुang = ang2; ang2 = 180 - ang1; ang1 = 180 - ang;पूर्ण
    अगर (scaley < 0.) अणुang = ang2; ang2 = -ang1; ang1 = -ang;पूर्ण
   पूर्ण
   ang1 = ang1 + r_angle * f;
   ang2 = ang2 + r_angle * f;
  पूर्ण अन्यथा अणु
   x = Rx0;
   y = Ry0;
  पूर्ण

  करो_उठाओ = 1;
  जबतक (ang2 < ang1) ang2 += 360;
  जबतक (ang1 < -360) अणु ang1 = 360 + ang1; ang2 = 360 + ang2; पूर्ण
  जबतक (ang2 > 360) अणु ang1 = -360 + ang1; ang2 = -360 + ang2; पूर्ण
/* म_लिखो("ixarc2: ang1=%d, ang2=%d\n", ang1, ang2); */
  ang2 = ang2 - ang1; /* Length of the arc, as required by XDrawArc */

  चयन( अगरill ) अणु
  हाल 0:        /* hollow arc */
       XDrawArc( display, d, *gcline,
                  x - rx, y - ry, 2 * rx, 2 * ry, ang1 * 64, ang2 * 64 );
  अवरोध;

  हाल 1:        /* filled arc */
       XFillArc( display, d, *gcfill,
                  x - rx, y - ry, 2 * rx, 2 * ry, ang1 * 64, ang2 * 64 );
       XDrawArc( display, d, *gcfill,
                  x - rx, y - ry, 2 * rx, 2 * ry, ang1 * 64, ang2 * 64 );
  अवरोध;
  पूर्ण
पूर्ण

/*
 *    SUBROUTINE IXSETFS(STYLE,FASI)
 *    INTEGER STYLE : fill area पूर्णांकerior style hollow or solid
 *
 *    Set fill area style
 */
व्योम
  ixsetfs( style, fasi )
पूर्णांक style;
पूर्णांक fasi;
अणु
  fill_border = 0;
  अगर ( fasi == 0 ) style = 0;
  चयन( style ) अणु

  हाल 1:         /* fill पूर्णांकerior with solid color */
    fill_hollow = 0;
    XSetFillStyle( display, *gcfill, FillSolid );
    अवरोध;

  हाल 2:         /* fill पूर्णांकerior + border with solid color */
    fill_hollow = 0;
    fill_border = 1;
    XSetFillStyle( display, *gcfill, FillSolid );
    अवरोध;

  हाल 3:         /* hatch */
    fill_hollow = 0;
    XSetFillStyle( display, *gcfill, FillStippled );
    अगर( fasi != current_fasi ) अणु
      अगर( fill_pattern != (Pixmap)शून्य ) अणु
        XFreePixmap( display, fill_pattern );
        fill_pattern = (Pixmap)शून्य;
      पूर्ण
      चयन( fasi ) अणु
        हाल 1: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p3_bits, 16, 16);
                अवरोध;
        हाल 2: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p2_bits, 16, 16);
                अवरोध;
        हाल 3: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p1_bits, 16, 16);
                अवरोध;
        हाल 4: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p4_bits, 16, 16);
                अवरोध;
        हाल 5: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p5_bits, 16, 16);
                अवरोध;
        हाल 6: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p6_bits, 16, 16);
                अवरोध;
        हाल 7: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p7_bits, 16, 16);
                अवरोध;
        हाल 8: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p8_bits, 16, 16);
                अवरोध;
        हाल 9: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p9_bits, 16, 16);
                अवरोध;
        हाल 10:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p10_bits, 16, 16);
                अवरोध;
        हाल 11:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p11_bits, 16, 16);
                अवरोध;
        हाल 12:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p12_bits, 16, 16);
                अवरोध;
        हाल 13:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p13_bits, 16, 16);
                अवरोध;
        हाल 14:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p14_bits, 16, 16);
                अवरोध;
        हाल 15:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p15_bits, 16, 16);
                अवरोध;
        हाल 16:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p16_bits, 16, 16);
                अवरोध;
        हाल 17:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p17_bits, 16, 16);
                अवरोध;
        हाल 18:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p18_bits, 16, 16);
                अवरोध;
        हाल 19:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p19_bits, 16, 16);
                अवरोध;
        हाल 20:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p20_bits, 16, 16);
                अवरोध;
        हाल 21:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p21_bits, 16, 16);
                अवरोध;
        हाल 22:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p22_bits, 16, 16);
                अवरोध;
        हाल 23:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p23_bits, 16, 16);
                अवरोध;
        हाल 24:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p24_bits, 16, 16);
                अवरोध;
        हाल 25:fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p25_bits, 16, 16);
                अवरोध;
       शेष: fill_pattern = XCreateBiपंचांगapFromData(display,
                RootWinकरोw( display, screen_number), p2_bits, 16, 16);
                अवरोध;
      पूर्ण
      XSetStipple( display, *gcfill, fill_pattern );
      current_fasi = fasi;
    पूर्ण
    अवरोध;

  शेष:
    fill_hollow = 1;
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXSETFC(CINDEX)
 *    INTEGER CINDEX : color index defined my IXSETCOL
 *
 *    Set color index क्रम fill areas
 */
व्योम
  ixsetfc( cindex )
पूर्णांक cindex;
अणु
  setcolor( *gcfill, cindex );

  /* invalidate fill pattern */
  अगर( fill_pattern != (Pixmap)शून्य ) अणु
    XFreePixmap( display, fill_pattern );
    fill_pattern = (Pixmap)शून्य;
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXFLARE(N,XY)
 *    INTEGER N         : number of poपूर्णांकs
 *    INTEGER*2 XY(2,N) : list of poपूर्णांकs
 *
 *    Fill area described by polygon
 */
व्योम
  ixflare( n, Rxy )
पूर्णांक n;
XPoपूर्णांक *Rxy;
अणु
  XPoपूर्णांक *xy;
  पूर्णांक i;
  Drawable d;

  अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

  अगर (rotate_fl || scale_fl || trans_fl) अणु
   xy = (XPoपूर्णांक *)सुस्मृति(n, माप(XPoपूर्णांक));
   क्रम (i = 0; i < n; i++) अणु
    xy[i].x=xOrig+Rco*scalex*(Rxy[i].x-xRO)+Rsi*scaley*(Rxy[i].y-yRO)+.5;
    xy[i].y=yOrig-Rsi*scalex*(Rxy[i].x-xRO)+Rco*scaley*(Rxy[i].y-yRO)+.5;
   पूर्ण
  पूर्ण अन्यथा अणु
   xy = Rxy;
  पूर्ण

  अगर( fill_hollow )
    XDrawLines( display, d, *gcfill, xy, n, CoordModeOrigin );
  अन्यथा अणु
   अगर( fill_border )
    XDrawLines( display, d, *gcfill, xy, n, CoordModeOrigin );
    XFillPolygon( display, d, *gcfill,
                  xy, n, Nonconvex, CoordModeOrigin );
  पूर्ण
  करो_उठाओ = 1;
पूर्ण


/*
 *    SUBROUTINE IXSETTA(TXALH,TXALV)
 *    INTEGER TXALH : horizontal text alignment
 *    INTEGER TXALV : vertical text alignment
 */
व्योम
  ixsetta( txalh, txalv )
पूर्णांक txalh;
पूर्णांक txalv;
अणु
  चयन ( txalh ) अणु

  हाल 0 :
  हाल 1 : चयन ( txalv) अणु
           हाल 0 :
           हाल 1 : text_align = 7;
                    अवरोध;
           हाल 2 : text_align = 4;
                    अवरोध;
           हाल 3 : text_align = 1;
                    अवरोध;
           पूर्ण
           अवरोध;
  हाल 2 : चयन ( txalv) अणु
           हाल 0 :
           हाल 1 : text_align = 8;
                    अवरोध;
           हाल 2 : text_align = 5;
                    अवरोध;
           हाल 3 : text_align = 2;
                    अवरोध;
           पूर्ण
           अवरोध;
  हाल 3 : चयन ( txalv) अणु
           हाल 0 :
           हाल 1 : text_align = 9;
                    अवरोध;
           हाल 2 : text_align = 6;
                    अवरोध;
           हाल 3 : text_align = 3;
                    अवरोध;
           पूर्ण
           अवरोध;
  पूर्ण
पूर्ण


/*
 *    FUNCTION IXSETTF(MODE,LENFNT,FONTNAME)
 *    INTEGER MODE       : loading flag
 *            MODE=0     : search अगर the font exist
 *            MODE=1     : search the font and load it अगर it exist
 *    INTEGER LENFNT     : font name length
 *    CHARACTER*(*) FONT : font name
 *
 *    Set text font to specअगरied name. This function वापसs 0 अगर
 *    the specअगरied font is found, 1 अगर not.
 */
पूर्णांक
  ixsettf( mode, fontname )
पूर्णांक mode;
अक्षर fontname[128];
अणु
  अक्षर **fontlist;
  पूर्णांक fontcount;
  पूर्णांक i;

  अगर ( mode != 0 ) अणु
     क्रम ( i = 0; i < MAXFONT; i++ ) अणु
        अगर (म_भेद(fontname, font[i].name) == 0) अणु
           text_font = font[i].id;
           XSetFont( display, *gctext, text_font->fid);
           XSetFont( display, *gcinvt, text_font->fid);
           वापस(0);
        पूर्ण
     पूर्ण
  पूर्ण

  fontlist = XListFonts( display, fontname, 1, &fontcount);

  अगर ( fontcount != 0 ) अणु
     अगर ( mode != 0 ) अणु
        अगर ( font[current_font_number].id )
           XFreeFont ( display, font[current_font_number].id);
        font[current_font_number].id = XLoadQueryFont( display, fontlist[0]);
	text_font = font[current_font_number].id;
        XSetFont( display, *gctext, text_font->fid);
        XSetFont( display, *gcinvt, text_font->fid);
        म_नकल (font[current_font_number].name,fontname);
        current_font_number++;
        अगर ( current_font_number == MAXFONT ) current_font_number = 0;
     पूर्ण
     XFreeFontNames(fontlist);
     वापस(0);
  पूर्ण
  अन्यथा अणु
     वापस(1);
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXSETTC(CINDEX)
 *    INTEGER CINDEX : color index defined by IXSETCOL
 *
 *    Set color index क्रम text
 */
व्योम
  ixsettc( cindex )
पूर्णांक cindex;
अणु
  setcolor( *gctext, cindex );

  अगर ( XGetGCValues( display, *gctext, gc_mask, &gc_वापस) ) अणु
     XSetForeground( display, *gcinvt, gc_वापस.background );
     XSetBackground( display, *gcinvt, gc_वापस.क्रमeground );
  पूर्ण अन्यथा अणु
     म_लिखो("**** Error: Cannot get GC values \n");
  पूर्ण
  XSetBackground( display, *gctext, colors[0].pixel );
पूर्ण


/*
 *    SUBROUTINE IXTEXT(MODE,X,Y,ANGLE,MGN,LENTXT,TEXT)
 *    INTEGER MODE       : drawing mode
 *            MODE=0     : the background is not drawn
 *            MODE=1     : the background is drawn
 *    INTEGER X,Y        : text position
 *    REAL    ANGLE      : text angle in degrees
 *    REAL    MGN        : magnअगरication factor
 *    INTEGER LENTXT     : text length
 *    CHARACTER*(*) TEXT : text string
 *
 *    Draw a text string using current font
 */
व्योम
  ixtext( mode, Rx, Ry, Rangle, mgn, text )
अक्षर text[256];
पूर्णांक mode;
पूर्णांक Rx, Ry;
भग्न Rangle;
भग्न mgn;
अणु
  पूर्णांक x, y;
  भग्न angle;
  Drawable d;

  अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

  अगर (rotate_fl || scale_fl || trans_fl) अणु
   x = xOrig + Rco * scalex * (Rx - xRO) + Rsi * scaley * (Ry - yRO)+.5;
   y = yOrig - Rsi * scalex * (Rx - xRO) + Rco * scaley * (Ry - yRO)+.5;
   angle = Rangle + r_angle * 57.295779512;
  पूर्ण अन्यथा अणु
   x = Rx; y = Ry; angle = Rangle;
  पूर्ण

  अगर (mgn != 1.) XRotSetMagnअगरication(mgn);

  चयन ( mode ) अणु

  हाल 0 : XRotDrawAlignedString( display, text_font, angle,
           d, *gctext, x, y, text, text_align);
           अवरोध;

  हाल 1 : XRotDrawAlignedImageString( display, text_font, angle,
           d, *gctext, x, y, text, text_align);
           अवरोध;

  शेष: अवरोध;
  पूर्ण
  करो_उठाओ = 1;
पूर्ण


/*
 *    SUBROUTINE IXTXTL(IW,IH,LMESS,MESS)
 *    INTEGER IW          : text width
 *    INTEGER IH          : text height
 *    INTEGER LMES        : message length
 *    CHARACTER*(*) MESS  : message
 *
 *    Return the size of a अक्षरacter string
 */
व्योम
  ixtxtl( w, h, mess )
अक्षर mess[256];
पूर्णांक *w;
पूर्णांक *h;
अणु
   *w = XTextWidth( text_font, mess, म_माप(mess) );
   *h = text_font->ascent;
पूर्ण


/*
 *    SUBROUTINE IXBOX(X1,X2,Y1,Y2,MODE)
 *    INTEGER X1,Y1 : left करोwn corner
 *    INTEGER X2,Y2 : right up corner
 *    INTEGER MODE : drawing mode
 *
 *            MODE=0 hollow
 *            MODE=1 solid
 *
 *    Draw a box
 */
व्योम
  ixbox( x1, x2, y1, y2, mode)
पूर्णांक x1, x2, y1, y2;
पूर्णांक mode;
अणु
 लघु xy[5][2];
 Drawable d;

 अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

 अगर (rotate_fl || scale_fl || trans_fl || mode == 0) अणु

     xy[0][0]=x1; xy[0][1]=y1;
     xy[1][0]=x2; xy[1][1]=y1;
     xy[2][0]=x2; xy[2][1]=y2;
     xy[3][0]=x1; xy[3][1]=y2;
     xy[4][0]=x1; xy[4][1]=y1;

     चयन ( mode ) अणु

     हाल 0 : /* Draw holow rectangle using lines (M.S.) */
                         ixline(5, xy);
              अवरोध;

     हाल 1 : /* Draw filled rectangle using flare (M.S.) */
                         ixflare(5, xy);
              अवरोध;
     पूर्ण
 पूर्ण अन्यथा अणु
     चयन ( mode ) अणु

/*   हाल 0 : XDrawRectangle( display, d, *gcline,
                              min(x1,x2), min(y1,y2),
                              असल(x2-x1), असल(y2-y1));
              अवरोध;     Doesn't work क्रम dashes.
*/

     हाल 1 : XFillRectangle( display, d, *gcfill,
                              min(x1,x2), min(y1,y2),
                              असल(x2-x1), असल(y2-y1));
              अवरोध;
     पूर्ण
 पूर्ण
 करो_उठाओ = 1;
पूर्ण


/*
 *    SUBROUTINE IXCA(X1,X2,Y1,Y2,NX,NY,IC)
 *    INTEGER X1,Y1 : left करोwn corner
 *    INTEGER X2,Y2 : right up corner
 *    INTEGER NX,NY : array size
 *    INTEGER IC : array
 *
 *    Draw a cell array. The drawing is करोne with the pixel presicion
 *    अगर (X2-X1)/NX (or Y) is not a exact pixel number the position of
 *    the top rigth corner may be wrong.
 */
व्योम
  ixca(x1, x2, y1, y2, nx, ny, ic)
पूर्णांक *x1, *x2, *y1, *y2, *nx, *ny;
पूर्णांक ic[];
अणु
   पूर्णांक i,j,icol,ix,iy,w,h,current_icol;

   current_icol = -1;
   w            = max((*x2-*x1)/(*nx),1);
   h            = max((*y1-*y2)/(*ny),1);
   ix           = *x1;

   क्रम ( i=0; i<*nx; i++ ) अणु
      iy = *y1-h;
      क्रम ( j=0; j<*ny; j++ ) अणु
         icol = ic[i+(*nx*j)];
         अगर(icol != current_icol)अणु
            XSetForeground( display, *gcfill, colors[icol].pixel );
            current_icol = icol;
         पूर्ण
         XFillRectangle( display, cws->drawing, *gcfill, ix, iy, w, h);
         iy = iy-h;
      पूर्ण
      ix = ix+w;
   पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXDRMDE(MODE)
 *    INTEGER MODE : drawing mode
 *    Changed (enhanced) by Mario
 *            MODE=1 copy src
 *            MODE=2 src xor dest
 *            MODE=3 invert (not dest)
 *            MODE=4 src and dest
 *            MODE=5 not (src xor dest)
 *            MODE=16 set the suitable mode क्रम cursor echo according to
 *                   the venकरोr.
 *
 *    Set the drawing mode
 */
व्योम
  ixdrmde( mode )
  पूर्णांक mode;
अणु
  पूर्णांक i;
  draw_mode = mode;
  चयन ( mode ) अणु

     हाल 1 :
     क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXcopy);
     अवरोध;

     हाल 2 :
     क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXxor);
     अवरोध;

     हाल 3 :
     क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXinvert);
     अवरोध;

     हाल 4 :
     क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXand);
     अवरोध;

     हाल 5 :
     क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXequiv);
     अवरोध;

     हाल 16:
     अगर(म_माला(venकरोr,"Hewlett")) अणु
      क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXinvert);
     पूर्ण अन्यथा अणु
      क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], GXxor);
     पूर्ण
     अवरोध;

     शेष:
     mode = -mode;
     अगर ( mode >= 0 && mode <= 15 ) अणु
      क्रम ( i = 0; i < MAXGC; i++ ) XSetFunction( display, gclist[i], mode);
     पूर्ण
     अवरोध;
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXSYNC(MODE)
 *    INTEGER MODE : synchronisation on/off
 *
 *            MODE=1 on
 *            MODE<>0 off
 *
 *    Set synchronisation on or off
 */
व्योम
  ixsync( mode )
  पूर्णांक mode;
अणु
  चयन ( mode ) अणु

     हाल 1 :
     XSynchronize(display,1);
     अवरोध;

     शेष:
     XSynchronize(display,0);
     अवरोध;
  पूर्ण
पूर्ण


/*
 *    SUBROUTINE IXQPTR(IX,IY)
 *
 *    Output parameters:
 *
 *    INTEGER IX : X coordinate of poपूर्णांकer
 *    INTEGER IY : Y coordinate of poपूर्णांकer
 *    (both coordinates are relative to the origin of the root winकरोw)
 */
व्योम ixqptr( ix, iy )
पूर्णांक *ix,*iy;
अणु
   Winकरोw idg;

   Winकरोw    root_वापस,child_वापस;
   पूर्णांक       win_x_वापस,win_y_वापस;
   पूर्णांक       root_x_वापस,root_y_वापस;
   अचिन्हित पूर्णांक mask_वापस;

   XQueryPoपूर्णांकer(display,cws->winकरोw,&root_वापस,
   &child_वापस,&root_x_वापस,&root_y_वापस,&win_x_वापस,
   &win_y_वापस,&mask_वापस);

   *ix = (पूर्णांक)root_x_वापस;
   *iy = (पूर्णांक)root_y_वापस;
पूर्ण



/*
 *    SUBROUTINE IXWARP(IX,IY)
 *
 *    Input parameters:
 *
 *    INTEGER IX : New X coordinate of poपूर्णांकer
 *    INTEGER IY : New Y coordinate of poपूर्णांकer
 *    (both coordinates are relative to the origin of the current winकरोw)
 */
व्योम ixwarp( ix, iy )
पूर्णांक ix,iy;
अणु
   XWarpPoपूर्णांकer(display,0,cws->winकरोw,0,0,0,0,ix,iy);
पूर्ण


/*
 *    INTEGER FUNCTION IXREQLO(MODE,CTYP,X,Y)
 *    INTEGER X,Y : cursor position out moment of button press (output)
 *    INTEGER CTYP : cursor type (input)
 *
 *            CTYP=1 tracking cross
 *            CTYP=2 cross-hair
 *            CTYP=3 rubber circle
 *            CTYP=4 rubber band
 *            CTYP=5 rubber rectangle
 *
 *    INTEGER MODE : input mode
 *
 *            MODE=0 request
 *            MODE=1 sample
 *
 *    Request locator:
 *    वापस button number  1 = left is pressed
 *                          2 = middle is pressed
 *                          3 = right is pressed
 *         in sample mode:
 *                         11 = left is released
 *                         12 = middle is released
 *                         13 = right is released
 *                         -1 = nothing is pressed or released
 *                         -2 = leave the winकरोw
 *                       अन्यथा = keycode (keyboard is pressed)
 */
पूर्णांक
  ixreqlo( mode, ctyp, x, y )
पूर्णांक mode, ctyp, *x, *y;
अणु
  अटल Cursor cursor = (Cursor)Lशून्य;
  XEvent event;
  पूर्णांक button_press;
  पूर्णांक radius;

  setinput(1);

/*
 *   Change the cursor shape
 */
  अगर( cursor == (Cursor)शून्य && ctyp != 0) अणु
     अगर( ctyp > 1 ) अणु
      XDefineCursor( display, cws->winकरोw, null_cursor );
      XSetForeground( display, gcecho, colors[0].pixel );
     पूर्ण अन्यथा अणु
        cursor = XCreateFontCursor( display, XC_crosshair );
        XDefineCursor( display, cws->winकरोw, cursor );
     पूर्ण
  पूर्ण

/*
 *   Event loop
 */
  button_press = 0;

  जबतक ( button_press == 0 ) अणु

     चयन ( ctyp ) अणु

     हाल 1 : अवरोध;

     हाल 2 : XDrawLine( display, cws->winकरोw, gcecho,
                         xloc, 0, xloc, cws->height);
              XDrawLine( display, cws->winकरोw, gcecho,
                         0, yloc, cws->width, yloc);
              अवरोध;

     हाल 3 : radius = (पूर्णांक) वर्ग_मूल((द्विगुन)((xloc-xlocp)*(xloc-xlocp)+
                                           (yloc-ylocp)*(yloc-ylocp)));
              XDrawArc( display, cws->winकरोw, gcecho,
                        xlocp-radius, ylocp-radius,
                        2*radius, 2*radius, 0, 23040);

     हाल 4 : XDrawLine( display, cws->winकरोw, gcecho,
                         xlocp, ylocp, xloc, yloc);
              अवरोध;

     हाल 5 : XDrawRectangle( display, cws->winकरोw, gcecho,
                              min(xlocp,xloc), min(ylocp,yloc),
                              असल(xloc-xlocp), असल(yloc-ylocp));
              अवरोध;

     शेष: अवरोध;
     पूर्ण

     जबतक ( XEventsQueued( display, QueuedAlपढ़ोy) > 1) अणु
        XNextEvent( display, &event);
     पूर्ण
     XWinकरोwEvent( display, cws->winकरोw, mouse_mask, &event );

     चयन ( ctyp ) अणु

     हाल 1 : अवरोध;

     हाल 2 : XDrawLine( display, cws->winकरोw, gcecho,
                         xloc, 0, xloc, cws->height);
              XDrawLine( display, cws->winकरोw, gcecho,
                         0, yloc, cws->width, yloc);
              अवरोध;

     हाल 3 : radius = (पूर्णांक) वर्ग_मूल((द्विगुन)((xloc-xlocp)*(xloc-xlocp)+
                                           (yloc-ylocp)*(yloc-ylocp)));
              XDrawArc( display, cws->winकरोw, gcecho,
                        xlocp-radius, ylocp-radius,
                        2*radius, 2*radius, 0, 23040);

     हाल 4 : XDrawLine( display, cws->winकरोw, gcecho,
                         xlocp, ylocp, xloc, yloc);
              अवरोध;

     हाल 5 : XDrawRectangle( display, cws->winकरोw, gcecho,
                              min(xlocp,xloc), min(ylocp,yloc),
                              असल(xloc-xlocp), असल(yloc-ylocp));
              अवरोध;

     शेष: अवरोध;
     पूर्ण

     xloc = event.xbutton.x;
     yloc = event.xbutton.y;

     चयन ( event.type ) अणु

     हाल LeaveNotअगरy :
           अगर( mode == 0 ) अणु
              क्रमever अणु
                 XNextEvent( display, &event);
                 अगर( event.type == EnterNotअगरy ) अवरोध;
              पूर्ण
           पूर्ण अन्यथा अणु
              button_press = -2;
           पूर्ण
           अवरोध;

     हाल ButtonPress :
          button_press =  event.xbutton.button ;
          xlocp = event.xbutton.x;
          ylocp = event.xbutton.y;
          अगर(ctyp != 0) अणु
           XUndefineCursor( display, cws->winकरोw );
           cursor = (Cursor)शून्य;
          पूर्ण
          अवरोध;

     हाल ButtonRelease :
           अगर( mode == 1 ) अणु
              button_press =  10+event.xbutton.button ;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     हाल KeyPress :
           अगर( mode == 1 ) अणु
              button_press =  event.xkey.keycode;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     हाल KeyRelease :
           अगर( mode == 1 ) अणु
              button_press =  -event.xkey.keycode;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     शेष : अवरोध;
     पूर्ण

     अगर( mode == 1 ) अणु
         अगर( button_press == 0 )
            button_press = -1;
         अवरोध;
     पूर्ण
  पूर्ण
  *x = event.xbutton.x;
  *y = event.xbutton.y;
  setinput(0);
  XFlush( display );
  वापस( button_press );
पूर्ण


/*
 *    INTEGER FUNCTION IXREQST(X,Y,TEXT)
 *    INTEGER X,Y        : position where text is displayed
 *    CHARACTER*(*) TEXT : text displayed (input), edited text (output)
 *
 *    Request string:
 *    text is displayed and can be edited with Emacs-like keybinding
 *    वापस termination code (0 क्रम ESC, 1 क्रम RETURN)
 *    Sep 1997, Apr 1998: bugs fixed by Mario Stipcevic
 */
पूर्णांक
  ixreqst( x, y, text )
अक्षर text[256];
पूर्णांक x, y;
अणु
  अटल Cursor cursor = (Cursor)Lशून्य;
  अटल पूर्णांक percent = 0;  /* bell volume */
  Winकरोw focuswinकरोw;
  पूर्णांक focusrevert;
  XEvent event;
  KeySym keysym;
  पूर्णांक key = -1;
  पूर्णांक nt;             /* defined length of text */
  पूर्णांक pt = 0;         /* cursor position in text */
  पूर्णांक len_text = 254; /* input text length */

  setinput(1);
  nt = म_माप(text);

  /* change the cursor shape */
  अगर( cursor == (Cursor)शून्य ) अणु
    XKeyboardState kbstate;
    cursor = XCreateFontCursor( display, XC_question_arrow );
    XGetKeyboardControl( display, &kbstate );
    percent = kbstate.bell_percent;
  पूर्ण
  अगर( cursor != (Cursor)शून्य )
    XDefineCursor( display, cws->winकरोw, cursor );
/*
  क्रम( nt = len_text; nt > 0 && text[nt-1] == ' '; nt-- );
*/
  pt = nt;
  XGetInputFocus( display, &focuswinकरोw, &focusrevert );
  XSetInputFocus( display, Poपूर्णांकerRoot, focusrevert, CurrentTime );
/*
  XSetInputFocus( display, cws->winकरोw, focusrevert, CurrentTime );
  This causes server to crash अगर executed beक्रमe winकरोw appears (slow network)
*/
  जबतक( key < 0 ) अणु
    अक्षर keybuf[8];
    अक्षर nbytes;
    पूर्णांक dx;
    पूर्णांक i;
    XDrawImageString( display, cws->winकरोw, *gctext,
              x, y, text, nt );
    dx = XTextWidth( text_font, text, nt );
    XDrawImageString( display, cws->winकरोw, *gctext,
              x + dx, y, " ", 1 );
    dx = pt == 0 ? 0 : XTextWidth( text_font, text, pt );
    XDrawImageString( display, cws->winकरोw, *gcinvt,
              x + dx, y, pt < len_text ? &text[pt] : " ", 1 );
    XWinकरोwEvent( display, cws->winकरोw, keybd_mask, &event );
    चयन( event.type ) अणु
    हाल ButtonPress:
    हाल EnterNotअगरy:
      XSetInputFocus( display, cws->winकरोw, focusrevert, CurrentTime );
      अवरोध;
    हाल LeaveNotअगरy:
      XSetInputFocus( display, focuswinकरोw, focusrevert, CurrentTime );
      अवरोध;
    हाल KeyPress:
      nbytes = XLookupString( &event.xkey, keybuf, माप( keybuf ),
                 &keysym, शून्य );
      चयन( keysym ) अणु      /* map cursor keys */
      हाल XK_Left:
      keybuf[0] = '\002';  /* Control-B */
      nbytes = 1;
      अवरोध;
      हाल XK_Right:
      keybuf[0] = '\006';  /* Control-F */
      nbytes = 1;
      अवरोध;
      पूर्ण
      अगर( nbytes == 1 ) अणु
      अगर( isascii( keybuf[0] ) && है_छाप( keybuf[0] ) ) अणु
        /* insert अक्षरacter */
        अगर( nt < len_text )
          nt++;
        क्रम( i = nt - 0; i > pt; i-- )
          text[i] = text[i-1];
        अगर( pt < len_text ) अणु
          text[pt] = keybuf[0];
          pt++;
        पूर्ण
      पूर्ण
      अन्यथा
        चयन( keybuf[0] ) अणु
          /* Emacs-like editing keys */

        हाल '\010':    /* backspace */
          /* delete backward */
          अगर( pt > 0 ) अणु
            dx = XTextWidth( text_font, text, nt );
            XDrawImageString( display, cws->winकरोw, *gctext, x+dx, y, " ", 1 );
            क्रम( i = pt; i <= nt; i++ )
             text[i-1] = text[i];
            nt--;
            pt--;
          पूर्ण
          अवरोध;
        हाल '\001':    /* ^A */
          /* beginning of line */
          pt = 0;
          अवरोध;
        हाल '\002':    /* ^B */
          /* move backward */
          अगर( pt > 0 )
            pt--;
          अवरोध;
        हाल '\004':    /* ^D */
        हाल '\177':    /* delete */
          /* delete क्रमward */
          अगर( pt < nt ) अणु
            क्रम( i = pt; i < nt; i++ )
            text[i] = text[i+1];
            text[nt-1] = ' ';
            nt--;
          पूर्ण
          अवरोध;
        हाल '\005':    /* ^E */
          /* end of line */
          pt = nt;
          अवरोध;

        हाल '\006':    /* ^F */
          /* move क्रमward */
          अगर( pt < nt )
            pt++;
          अवरोध;
        हाल '\013':    /* ^K */
          /* delete to end of line */
          क्रम( i = pt; i < nt; i++ )
            text[i] = ' ';
          XDrawImageString( display, cws->winकरोw, *gctext, x, y, text, nt);
          nt = pt;
          अवरोध;
        हाल '\024':    /* ^T */
          /* transpose */
          अगर( pt > 0 ) अणु
            अक्षर c = text[pt];
            text[pt] = text[pt-1];
            text[pt-1] = c;
          पूर्ण
          अवरोध;
        हाल '\012':    /* newline */
        हाल '\015':    /* वापस */
          key = 1;
          अवरोध;
        हाल '\033':    /* escape */
          key = 0;
          अवरोध;

        शेष:
          XBell( display, percent );
        पूर्ण
      पूर्ण
    पूर्ण
  पूर्ण
  XSetInputFocus( display, focuswinकरोw, focusrevert, CurrentTime );

  अगर( cursor != (Cursor)शून्य ) अणु
    XUndefineCursor( display, cws->winकरोw );
    cursor = (Cursor)Lशून्य;
  पूर्ण

  setinput(0);

  /* Make sure there are no trailing spaces */
  nt = म_माप(text);
  जबतक(text[nt-1] == ' ') nt--;
  text[nt] = '\0';

  XSync( display, 1 );
  वापस( key );
पूर्ण

#घोषणा MAX_SEGMENT 20
व्योम ixput_image(offset,itran,x0,y0,nx,ny,xmin,ymin,xmax,ymax,image,ipal)
  पूर्णांक offset,itran,x0,y0,nx,ny,xmin,ymin,xmax,ymax,ipal;
  अचिन्हित अक्षर *image;
अणु
  पूर्णांक           i, n, x, y, xcur, x1, x2, y1, y2;
  अचिन्हित अक्षर *jimg, *jbase, icol;
  पूर्णांक           nlines[256];
  XSegment      lines[256][MAX_SEGMENT];
  Drawable d;

  अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

  क्रम (i=0; i<256; i++) nlines[i] = 0;

  x1 = x0 + xmin; y1 = y0 + ny - ymax - 1;
  x2 = x0 + xmax; y2 = y0 + ny - ymin - 1;
  jbase = image + (ymin-1)*nx + xmin;

  क्रम (y=y2; y>=y1; y--) अणु
    xcur   = x1; jbase += nx;
    क्रम (jimg = jbase, icol = *jimg++, x=x1+1; x<=x2; jimg++, x++) अणु
      अगर (icol != *jimg) अणु
        अगर (icol != itran) अणु
          n = nlines[icol]++;
          lines[icol][n].x1 = xcur; lines[icol][n].y1 = y;
          lines[icol][n].x2 = x-1;  lines[icol][n].y2 = y;
          अगर (nlines[icol] == MAX_SEGMENT) अणु
            अगर(!ipal) अणु setcolor(*gcline,(पूर्णांक) (icol+offset)); पूर्ण
            अन्यथा
                      अणु setcolor(*gcline,(पूर्णांक) tpal[icol]);    पूर्ण
            XDrawSegments(display,d,*gcline,&lines[icol][0],
              MAX_SEGMENT);
            nlines[icol] = 0;
          पूर्ण
        पूर्ण
        icol = *jimg; xcur = x;
      पूर्ण
    पूर्ण
    अगर (icol != itran) अणु
      n = nlines[icol]++;
      lines[icol][n].x1 = xcur; lines[icol][n].y1 = y;
      lines[icol][n].x2 = x-1;  lines[icol][n].y2 = y;
      अगर (nlines[icol] == MAX_SEGMENT) अणु
        अगर(!ipal) अणु setcolor(*gcline,(पूर्णांक) (icol+offset)); पूर्ण
        अन्यथा
                  अणु setcolor(*gcline,(पूर्णांक) tpal[icol]);    पूर्ण
        XDrawSegments(display,d,*gcline,&lines[icol][0],
          MAX_SEGMENT);
        nlines[icol] = 0;
      पूर्ण
    पूर्ण
  पूर्ण

  क्रम (i=0; i<256; i++) अणु
    अगर (nlines[i] != 0) अणु
    अगर(!ipal) अणु setcolor(*gcline,(पूर्णांक) (i+offset)); पूर्ण
    अन्यथा
              अणु setcolor(*gcline,(पूर्णांक) tpal[i]);    पूर्ण
     XDrawSegments(display,d,*gcline,&lines[i][0],nlines[i]);
    पूर्ण
  पूर्ण
पूर्ण

/*
 *    SUBROUTINE STDPAL()
 *    Created by: Mario Stipcevic 07.01.1997
 *    Install Standard 6x6x6 Palette
 */
पूर्णांक stdpal()
अणु
 पूर्णांक j, pofset, r, g, b;

 pofset = 32;
 j = pofset;
 क्रम(r=0; r<=5; r++) अणु
  क्रम(g=0; g<=5; g++) अणु
   क्रम(b=0; b<=5; b++) अणु
    ixsetco(j,r*51,g*51,b*51);
    j++;
   पूर्णपूर्णपूर्ण
 वापस 0;
पूर्ण

/*
 *    SUBROUTINE GIFINFO(खाता, GInf)
 *    Created by: Mario Stipcevic 07.01.1997
 C    CHAR    खाता: filename
 *    INTEGER GInf: output inक्रमmation: width, height, ncolors
 *
 */
व्योम gअगरinfo (file, GInf__)
अक्षर file[128];
लघु *GInf__;
अणु
  खाता  *fd;
  दीर्घ  filesize;
  अचिन्हित अक्षर *GIFarr;
  पूर्णांक   width, height, ncolor;

  GInf__[0] = 0; GInf__[1] = 0; GInf__[2] = 0;
  fd = ख_खोलो(file, "r");
  अगर (!fd) अणु
    ख_लिखो(मानक_त्रुटि,"gifinfo: Unable to open GIF file '%s'\n", file);
    वापस;
  पूर्ण

  ख_जाओ(fd, 0L, 2);
  filesize = ख_बताओ(fd);
  ख_जाओ(fd, 0L, 0);

  अगर (!(GIFarr = (अचिन्हित अक्षर *) सुस्मृति(filesize+256,1))) अणु
    ख_लिखो(मानक_त्रुटि,"gifinfo: unable to allocate array for gif\n");
    वापस;
  पूर्ण

  अगर (ख_पढ़ो(GIFarr, filesize, 1, fd) != 1) अणु
    ख_लिखो(मानक_त्रुटि,"gifinfo: GIF file read failed\n");
    वापस;
  पूर्ण

  GIFinfo(GIFarr, &width, &height, &ncolor);
  *GInf__++ = width; *GInf__++ = height; *GInf__ = ncolor; /* Save GIF Info */

  ख_बंद(fd);
  वापस;
पूर्ण

/*
 *    SUBROUTINE IXLDGIF(X0, Y0, खाता, IPAL, BG)
 *    Modअगरied by: Mario Stipcevic 07.01.1997
 *    CHARACTER*(*) खाता : file name
 *    INTEGER X0 Y0      : position
 *    INTEGER ipal: 0 = use Own palette, 1 = use Std 6x6x6 palette
 *    INTEGER bg   specअगरies background: bg<0 GIF's own, bg>=0 =colorindex
 *
 *    Load the gअगर a file in the current active winकरोw.
 */
व्योम ixldgअगर (x0, y0, file, ipal, bg)
अक्षर file[128];
पूर्णांक x0,y0, ipal, bg;
अणु
  खाता  *fd;
  दीर्घ  filesize;
  अचिन्हित अक्षर *GIFarr, *PIXarr, R[256], G[256], B[256], *j1, *j2, icol;
  पूर्णांक   i, j, k, width, height, ncolor, irep, offset, pofset;
  पूर्णांक rr, gg, bb;

  fd = ख_खोलो(file, "r");
  अगर (!fd) अणु
    ख_लिखो(मानक_त्रुटि,"ixldgif: Unable to open GIF file '%s'\n", file);
    वापस;
  पूर्ण

  /* Set Std. Color Palette अगर not alपढ़ोy set and अगर needed */
  अगर (ipal && !stdset) अणु stdpal(); पूर्ण
  stdset = ipal;

  ख_जाओ(fd, 0L, 2);
  filesize = ख_बताओ(fd);
  ख_जाओ(fd, 0L, 0);

  अगर (!(GIFarr = (अचिन्हित अक्षर *) सुस्मृति(filesize+256,1))) अणु
    ख_लिखो(मानक_त्रुटि,"ixldgif: unable to allocate array for gif\n");
    वापस;
  पूर्ण

  अगर (ख_पढ़ो(GIFarr, filesize, 1, fd) != 1) अणु
    ख_लिखो(मानक_त्रुटि,"ixldgif: GIF file read failed\n");
    ख_बंद(fd);
    वापस;
  पूर्ण
  ख_बंद(fd);

  irep = GIFinfo(GIFarr, &width, &height, &ncolor);
  अगर (irep != 0) वापस;

  अगर (!(PIXarr = (अचिन्हित अक्षर *) सुस्मृति((दीर्घ)(width*height),1))) अणु
    ख_लिखो(मानक_त्रुटि,"ixldgif: unable to allocate array for image\n");
    वापस;
  पूर्ण

  irep = GIFdecode(GIFarr, PIXarr, &width, &height, &ncolor, R, G, B);
  अगर (irep != 0) वापस;

/* Debug code:
  क्रम (j=0; j<10; j++) अणु
   क्रम (i=0; i<10; i++) अणु
    म_लिखो("%5d", PIXarr[i+j*width]);
   पूर्ण
   म_लिखो("\n");
  पूर्ण
*/

  /*   S E T   P A L E T T E   */

  offset = 16;
  pofset = 32; /* std. palette offset */

  अगर (ipal == 0)
  अणु
   /* use Own colormap */
   अगर (ncolor > 256 - offset) अणु
   म_लिखो("ixldgif: number of colors in GIF file too large, truncating to %d\n",
      (ncolor=(256-offset)) ); पूर्ण
   क्रम (i=0; i<ncolor; i++) अणु
     rr = R[i];
     gg = G[i];
     bb = B[i];
     j = i+offset;
     ixsetco(j,rr,gg,bb);
   पूर्ण
   अगर (bg >= 0) ixsetco(offset,colors[bg].red,colors[bg].green,colors[bg].blue);
  पूर्ण
  अन्यथा
  अणु
   /* use Std. 6x6x6 colormap */
   क्रम (i=0; i<ncolor; i++) अणु
     rr = (R[i] + 26) / 51;
     gg = (G[i] + 26) / 51;
     bb = (B[i] + 26) / 51;
     j = pofset + bb + 6 * (gg + 6 * rr);
     tpal[i] = j;
   पूर्ण
  पूर्ण

  /*  O U T P U T   I M A G E  */

  क्रम (i=1; i<=height/2; i++) अणु
    j1 = PIXarr + (i-1)*width;
    j2 = PIXarr + (height-i)*width;
    क्रम (k=0; k<width; k++) अणु
      icol = *j1; *j1++ = *j2; *j2++ = icol;
    पूर्ण
  पूर्ण
  ixput_image(offset,-1,x0,y0,width,height,0,0,width-1,height-1,PIXarr,ipal);
पूर्ण

प्रकार अचिन्हित अक्षर byte;     /* type used by subroutines to code&decode GIF*/
XImage *image;                  /* temporary unit क्रम GIFencode()             */
खाता *out;                      /* output/input file क्रम animation            */
अटल पूर्णांक first = 0;           /* MS: ask क्रम image poपूर्णांकer only once (why??)*/

/*
 * subroutines क्रम GIFencode()
 */

व्योम
  get_scline( y, width, scline )
  पूर्णांक y, width;
  byte scline[];
अणु
पूर्णांक i;
क्रम(i=0;i< width;i++)
        scline[i] = XGetPixel( image, i, y);
पूर्ण


व्योम
  put_byte( b)
  byte b;
अणु
 अगर( ख_त्रुटि(out) == 0) ख_अक्षर_दो( b, out);
पूर्ण

/*
 *    SUBROUTINE IXDOGIF( LEN , खाता)
 *    CHARACTER  NAME
 *    INTEGER LEN
 *
 *    Writes the current winकरोw पूर्णांकo a GIF file
 *
 */
व्योम
  ixकरोgअगर( file )
अक्षर file[128];
अणु

byte  scline[5000], r[256], g[256], b[256];
पूर्णांक R[256], G[256], B[256];
पूर्णांक ncol, maxcol, i;
पूर्णांक ln;
अक्षर file_name[100];
अचिन्हित दीर्घ z;

ImgPickPalette( display ,cws->winकरोw, &ncol, R, G, B);

 maxcol = 0;
 क्रम(i=0; i<ncol; i++)
 अणु
  अगर(maxcol < R[i] ) maxcol = R[i];
  अगर(maxcol < G[i] ) maxcol = G[i];
  अगर(maxcol < B[i] ) maxcol = B[i];
  r[i] = 0;
  g[i] = 0;
  b[i] = 0;
 पूर्ण
 अगर( maxcol != 0)
  अणु
  क्रम(i=0; i<ncol; i++)
  अणु
   r[i] = (R[i] * 255) / maxcol;
   g[i] = (G[i] * 255) / maxcol;
   b[i] = (B[i] * 255) / maxcol;
  पूर्ण
 पूर्ण

 अगर (first == 0 ) अणु
  image = XGetImage( display, cws->drawing, 0, 0,
                     cws->width, cws->height,
                     AllPlanes, ZPixmap);
/* first = 1;  Commented by Mario: strange effect (subimages ?) */
 पूर्ण अन्यथा अणु
  image = XGetSubImage(display, cws->drawing, 0, 0,
                       cws->width, cws->height,
                       AllPlanes, ZPixmap, image, 0, 0);
 पूर्ण

 प्र_लिखो( file_name, "%s", file);

 out = ख_खोलो ( file_name, "w+");

 GIFencode( cws->width, cws->height,
            ncol, r, g, b, scline, get_scline, put_byte);

 ख_बंद( out );
पूर्ण

/*   answ = IXWPTRQ (x, y, rootx, rooty, win, mode, ctyp)
     Generalized ixreqlo() function
     *win    winकरोw the poपूर्णांकer is logically on
     *x      x location of the poपूर्णांकer relative to the winकरोw origin
     *y      y location of the poपूर्णांकer relative to the winकरोw origin
     mode, ctyp, answ - see ixreqlo(...)
     Author: Mario Stipcevic Jul, 1997
*/
पूर्णांक ixwptrq( x, y, win, mode, ctyp, mask )
पूर्णांक *x, *y, *win, mode, ctyp, mask;
अणु

   अटल Cursor cursor = (Cursor)Lशून्य;
   XEvent event;
   XSetWinकरोwAttributes attributes;
   अचिन्हित दीर्घ attr_mask = 0;
   पूर्णांक button_press, radius, wid;
   पूर्णांक i, n, u;

   /* Set all inमाला_दो on */
   attributes.event_mask = mouse_mask | keybd_mask;
   attr_mask |= CWEventMask;
   क्रम ( i = 0; i < MAXWN; i++ ) अणु
    ttws = &winकरोws[i];
    अगर ( ttws->खोलो ) अणु
     attributes.event_mask = mouse_mask | keybd_mask;
     attr_mask |= CWEventMask;
     XChangeWinकरोwAttributes ( display, ttws->winकरोw, attr_mask, &attributes);
    पूर्ण
   पूर्ण


  /*
   *   Event loop a'la ixreqlo()
   */
   button_press = 0;
   n = 0;
/*
   जबतक ( button_press == 0 ) अणु
*/
   जबतक ( n == 0 ) अणु
   n = 1;

/*
   u=XEventsQueued(display,QueuedAlपढ़ोy);
   म_लिखो("ixwptrq ulaz: u = %d\n",u);
   XNextEvent( display, &event);
*/

   XMaskEvent( display, mouse_mask, &event);
   क्रम (wid = 0; wid < MAXWN; wid++) अणु
    ttws = &winकरोws[wid];
    अगर ( ttws->खोलो && ttws->winकरोw == event.xbutton.winकरोw ) अणु
      *win = wid;
      जाओ Lab_001;
    पूर्ण
   पूर्ण
   *win = -1;
   वापस( button_press );
Lab_001:;

/*
म_लिखो("Here 1\n");
    XWinकरोwEvent( display, event.xbutton.winकरोw, mouse_mask, &event );
    XWinकरोwEvent( display, ttws->winकरोw, mouse_mask, &event );
म_लिखो("Here 2\n");
*/

    xloc = event.xbutton.x;
    yloc = event.xbutton.y;

    चयन ( event.type ) अणु

     हाल LeaveNotअगरy :
           अगर( mode == 0 ) अणु
              क्रमever अणु
                 XNextEvent( display, &event);
                 अगर( event.type == EnterNotअगरy ) अवरोध;
              पूर्ण
           पूर्ण अन्यथा अणु
              button_press = -2;
           पूर्ण
           अवरोध;

     हाल ButtonPress :
          button_press =  event.xbutton.button ;
          xlocp = event.xbutton.x;
          ylocp = event.xbutton.y;
/*
          XUndefineCursor( display, ttws->winकरोw );
          cursor = (Cursor)शून्य;
*/
          अवरोध;

     हाल ButtonRelease :
           अगर( mode == 1 ) अणु
              button_press =  10+event.xbutton.button ;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     हाल KeyPress :
           अगर( mode == 1 ) अणु
              button_press =  event.xkey.keycode;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     हाल KeyRelease :
           अगर( mode == 1 ) अणु
              button_press =  -event.xkey.keycode;
              xlocp = event.xbutton.x;
              ylocp = event.xbutton.y;
           पूर्ण
          अवरोध;

     शेष : अवरोध;
    पूर्ण

    अगर( mode == 1 ) अणु
        अगर( button_press == 0 )
           button_press = -1;
        अवरोध;
    पूर्ण
  पूर्ण
Lab_99e:
  *x = event.xbutton.x;
  *y = event.xbutton.y;
  setinput(0);
  XFlush( display );
/*
 म_लिखो("ixwptrq: x=%d y=%d win=%d answ=%d\n", *x, *y, *win, button_press);
*/
  वापस( button_press );
पूर्ण

/*
 *    SUBROUTINE IXCURSOR( ctyp )
 *    पूर्णांक ctyp = Cursor type as defined in <X11/cursorfont.h>
 *    Created by: Mario Stipcevic 07.01.1997
 */
 व्योम ixcursor( ctyp )
पूर्णांक ctyp;
अणु
  Cursor cursor;

  XUndefineCursor( display, cws->winकरोw );
  cursor = XCreateFontCursor( display, ctyp );
  XDefineCursor( display, cws->winकरोw, cursor);
पूर्ण

 व्योम ixclrque()
/* Author: M.S. */
/* Flush and delete the X queue, leaving no events */
अणु
 XFlush( display );
 XSync( display , 1);
पूर्ण

 व्योम ixtitle( title, wid )
/* Set title of an existing winकरोw wid, अगर wid=-1 then current winकरोw */
पूर्णांक wid;
अक्षर title[200];
अणु
  अक्षर दीर्घ_title[256];
  अक्षर host_name[64];

  tws = &winकरोws[wid];
  अगर (wid < 0) tws = cws;
  अगर (tws->खोलो) अणु
   म_नकल(दीर्घ_title, title);
   अगर (दीर्घ_title[0] != '-') अणु
      म_जोड़ो( दीर्घ_title, " @ " );
      gethostname( host_name, माप( host_name ) );
      म_जोड़ो( दीर्घ_title, host_name );
   पूर्ण अन्यथा अणु
      दीर्घ_title[0] = ' ';
   पूर्ण
   XStoreName( display, tws->winकरोw, दीर्घ_title );
   XSetIconName( display, tws->winकरोw, दीर्घ_title );
  पूर्ण
पूर्ण

/* PIXEL and IMAGE manipulation routines, Auth. Mario Stipcevic, Apr. 1998 */

दीर्घ
   ixpget (पूर्णांक x, पूर्णांक y)
/* Get one pixel */
अणु
 XImage *image;
 दीर्घ pixel, icol = 0;
/*
 image = XGetImage( display, cws->drawing, 0, 0,
                   cws->width, cws->height,
                   AllPlanes, ZPixmap);

 pixel = ((दीर्घ) XGetPixel( image, x, y ));
 क्रम (icol=0; icol<255; icol++) अणु
  अगर (colors[icol].defined && colors[icol].pixel==pixel) अवरोध;
 पूर्ण
 XDestroyImage(image);
*/
 वापस ( icol );
पूर्ण


व्योम
   ixpset (पूर्णांक Rx, पूर्णांक Ry, पूर्णांक cindex )
/* Draw one pixel of a given color (faster than through ixline !) */
/* अगर cindex = -1 then keep old क्रमeground */
अणु
 पूर्णांक x, y;
 Drawable d;

 अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

 अगर (rotate_fl || scale_fl || trans_fl) अणु
  x = xOrig + Rco * scalex * (Rx - xRO) + Rsi * scaley * (Ry - yRO)+.5;
  y = yOrig - Rsi * scalex * (Rx - xRO) + Rco * scaley * (Ry - yRO)+.5;
 पूर्ण अन्यथा अणु
  x = Rx;
  y = Ry;
 पूर्ण

 अगर (cindex != -1)
  XSetForeground( display, *gcline, colors[cindex].pixel );
 XDrawPoपूर्णांक(display, d, *gcline, x, y);
पूर्ण

व्योम
   ixpicget (x, y, w, h, array)
पूर्णांक x, y;   /* Position of Picture in the winकरोw */
पूर्णांक w, h;   /* width and height */
अचिन्हित अक्षर *array; /* output array */
/* Get portion of the X-winwow in an (अचिन्हित लघु पूर्णांक (2b)) array */
अणु
 XImage *image;
 पूर्णांक i, j;
 अचिन्हित लघु पूर्णांक *table;
 अचिन्हित दीर्घ u, k;

 image = XGetImage( display, cws->drawing, 0, 0,
                   cws->width, cws->height,
                   AllPlanes , ZPixmap);

 table = (अचिन्हित लघु पूर्णांक *)सुस्मृति(65536, माप(अचिन्हित लघु पूर्णांक));
 /* Create pixel/color table */
 क्रम (i = 0; i < 256; i++) अणु
  अगर (colors[i].defined) अणु
   अगर ((u = colors[i].pixel) < 65536) अणु
    table[u] = i;
   पूर्ण अन्यथा अणु
    म_लिखो("ixgetpal: Colordepth > 16 bits unsupported !!\n");
   पूर्ण
  पूर्ण अन्यथा अणु table[u] = 0; पूर्ण
 पूर्ण

 /* Output array of colors */
 k = 0;
 क्रम (j = 0; j < h; j++) अणु
  क्रम (i = 0; i < w; i++) अणु
   array[k++] = table[ XGetPixel( image, i + x, j + y )];
  पूर्ण
 पूर्ण

 XDestroyImage(image);
पूर्ण

व्योम
 ixpicput(x, y, data, w, h, xoff, yoff, ws, hs)
/* Put picture stored in an (अचिन्हित लघु पूर्णांक (2b)) array पूर्णांकo a portion
 * of the X-winwow (inverse of ixpicget) */
पूर्णांक x, y;       /* Position where to put the image */
पूर्णांक xoff, yoff; /* Offset in the source image */
पूर्णांक ws, hs;     /* Dimensions of the rectangle of the source to be copied */
अचिन्हित पूर्णांक w, h; /* Picture dimension in data */
अचिन्हित अक्षर *data; /* input color array */
अणु
 XImage *image;
 Visual *visual=(Visual *)शून्य;
 पूर्णांक i, j, k, depth;
 अचिन्हित अक्षर *pxls8;
 अचिन्हित लघु पूर्णांक *pxls16;
 व्योम *pxls;
 Drawable d;

 अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

 /* Convert (input) color array पूर्णांकo pixel array */
 depth = 1; अगर (DefaultDepth(display,screen_number) > 8) depth = 2;
 अगर (depth==1) pxls = pxls8  = दो_स्मृति(w * h);
 अगर (depth==2) pxls = pxls16 = दो_स्मृति((w * h) * 2);
 अगर (pxls)
 अणु
  k = 0;
  क्रम (j = 0; j < h; j++) अणु
   क्रम (i = 0; i < w; i++) अणु
    अगर (depth==1) *(pxls8 + k) = (अचिन्हित अक्षर *) colors[data[k]].pixel;
    अगर (depth==2) *(pxls16 + k) = (अचिन्हित लघु पूर्णांक *) colors[data[k]].pixel;
    k++;
   पूर्ण
  पूर्ण

  image = XCreateImage(display, visual, DefaultDepth(display,screen_number), ZPixmap, 0, pxls, w, h, 16, 0);
  /* XInitImage(image); ??? */
  XPutImage(display, d, *gcpxmp, image, xoff, yoff, x, y, ws, hs);

  XDestroyImage( image );
  /* Empty the event queue: */
  XSync( display, 1 );
 पूर्ण
पूर्ण

अटल पूर्णांक first_img = 1;  /* Animation flags */
अटल पूर्णांक  last_img = 0;

व्योम
 ixpicanim(x, y, data, w, h, xoff, yoff, ws, hs)
/* Put picture stored in an (अचिन्हित लघु पूर्णांक (2b)) array पूर्णांकo a portion
 * of the X-winwow (inverse of ixpicget) */
पूर्णांक x, y;       /* Position where to put the image */
पूर्णांक xoff, yoff; /* Offset in the source image */
पूर्णांक ws, hs;     /* Dimensions of the rectangle of the source to be copied */
अचिन्हित पूर्णांक w, h; /* Picture dimension in data */
अचिन्हित अक्षर *data; /* input color array */
अणु
 अटल XImage *image;
 अटल XImage *image_old;
 Visual *visual=(Visual *)शून्य;
 पूर्णांक i, j, k;
 अटल अचिन्हित लघु पूर्णांक *pxls16 = शून्य;
 अटल अचिन्हित अक्षर *pxls8 = शून्य;
 अटल व्योम *pxls = शून्य;
 अटल पूर्णांक xt, yt, xofft, yofft, wst, hst, wt, ht, depth;
 Drawable d;

 अगर(!(d=cws->buffer)) d = cws->drawing; /* Handle buffer ixcrbuff() */

 अगर (!data) अणु
  /* Check what to करो with the last clip */
  अगर (draw_mode > 0)
   XPutImage(display, d, *gcpxmp, image_old, xofft, yofft, xt, yt, wst, hst);
  /* Free memory and reset flags */
  XDestroyImage( image_old );
  first_img = 1; last_img = 0; wt=0; ht=0;
  वापस ;
 पूर्ण

 अगर(w * h != wt * ht || !pxls) अणु
  अगर (pxls) XDestroyImage(image); /* Memory still leaks a bit ?? */
  depth = 1; अगर (DefaultDepth(display,screen_number) > 8) depth = 2;
  अगर (depth==1) pxls = pxls8  = दो_स्मृति(w * h);
  अगर (depth==2) pxls = pxls16 = दो_स्मृति((w * h) * 2);
 पूर्ण

 /* Convert (input) color array पूर्णांकo pixel array */
 k = 0;
 क्रम (j = 0; j < h; j++) अणु
  क्रम (i = 0; i < w; i++) अणु
   अगर (depth==1) *(pxls8 + k) = (अचिन्हित अक्षर *) colors[data[k]].pixel;
   अगर (depth==2) *(pxls16 + k) = (अचिन्हित लघु पूर्णांक *) colors[data[k]].pixel;
   k++;
  पूर्ण
 पूर्ण
 image = XCreateImage(display, visual, DefaultDepth(display,screen_number), ZPixmap, 0, pxls, w, h, 16, 0);
  /* XInitImage( image ); */

 अगर (!first_img) अणु
  XPutImage(display, d, *gcpxmp, image_old, xofft, yofft, xt, yt, wst, hst);
 पूर्ण
 अगर (!last_img) अणु
  XPutImage(display, d, *gcpxmp, image, xoff, yoff, x, y, ws, hs);
 पूर्ण

 xofft = xoff; yofft = yoff; xt = x; yt = y; wst = ws; hst = hs; wt = w; ht = h;
 image_old = image;
 अगर (first_img) first_img = 0;
 /* Empty the event queue: */
 XSync( display, 1 );
पूर्ण


व्योम
 xtest(w, h)
अचिन्हित पूर्णांक w, h;
अणु
  पूर्णांक i;

/*
     pixmp = XCreatePixmap(display, RootWinकरोw( display, screen_number),
                100, 100, DefaultDepth(display, screen_number));
     XCopyArea( display, cws->drawing, pixmp,
                *gcbuff, 0, 0, 100, 100, 0, 0 );
     XCopyArea( display, pixmp, cws->drawing,
                *gcbuff, 0, 0, 100, 100, 120, 80  );
*/
     pixmp = XCreatePixmap(display, RootWinकरोw( display, screen_number),
                100, 100, 1);
     XFillRectangle(display, pixmp, *gcline, 0, 0, 100, 100);
     क्रम( i = 0; i < 6; i++ ) अणु XSetClipMask( display, gclist[i], pixmp );
     XSetClipOrigin(display, gclist[i], 0, 0); पूर्ण

म_लिखो("depth=%d\n", DefaultDepth(display, screen_number));
/*
     क्रम( i = 0; i < MAXGC; i++ ) अणु XSetClipMask( display, gclist[i], pixmp );
     XSetClipOrigin(display, gclist[i], 0, 0); पूर्ण
     XSetClipOrigin(display, *gcline, 0, 0);
     क्रम( i = 0; i < MAXGC; i++ ) XSetClipMask( display, gclist[i], pixmp );
     cws->clip  = 1;
     XFreePixmap(display, pixmp);
     क्रम( i = 0; i < MAXGC; i++ ) XSetClipMask( display, gclist[i], pixmp );
*/
     XFlush( display );
पूर्ण
