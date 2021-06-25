<शैली गुरु>
/*
 * $Id: rotated.c,v 1.1.1.1 1996/02/14 13:10:26 mclareni Exp $
 *
 * $Log: rotated.c,v $
 * Revision 1.1.1.1  1996/02/14 13:10:26  mclareni
 * Higz
 *
 */
/*CMZ :  1.23/06 22/11/95  10.13.12  by  O.Couet*/
/*-- Author :    O.Couet   17/11/93*/
/* Modअगरied: Mario Stipcevic Jan.1998 to allow ClipMask क्रम text */
/* ********************************************************************** *
 *
 * xvertext 5.0, Copyright (c) 1993 Alan Riअक्षरdson (mppa3@uk.ac.sussex.syma)
 *
 * Alignment definition modअगरied by O.Couet.
 * Mods IBM/VM by O.Couet.
 *
 * Permission to use, copy, modअगरy, and distribute this software and its
 * करोcumentation क्रम any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both the
 * copyright notice and this permission notice appear in supporting
 * करोcumentation.  All work developed as a consequence of the use of
 * this program should duly acknowledge such use. No representations are
 * made about the suitability of this software क्रम any purpose.  It is
 * provided "as is" without express or implied warranty.
 *
 * ********************************************************************** */

#समावेश <X11/Xlib.h>
#समावेश <X11/Xutil.h>
#समावेश <X11/Xatom.h>
#समावेश <मानकपन.स>
#समावेश <गणित.स>

/* ************************************************************************ *
 *
 * Header file क्रम the `xvertext 5.0' routines.
 *
 * Copyright (c) 1993 Alan Riअक्षरdson (mppa3@uk.ac.sussex.syma)
 *
 * ************************************************************************ */

#अगर_अघोषित _XVERTEXT_INCLUDED_
#घोषणा _XVERTEXT_INCLUDED_


#घोषणा XV_VERSION      5.0
#घोषणा XV_COPYRIGHT \
      "xvertext routines Copyright (c) 1993 Alan Richardson"

/* ---------------------------------------------------------------------- */

/* text alignment */

#घोषणा NONE             0
#घोषणा TLEFT            1
#घोषणा TCENTRE          2
#घोषणा TRIGHT           3
#घोषणा MLEFT            4
#घोषणा MCENTRE          5
#घोषणा MRIGHT           6
#घोषणा BLEFT            7
#घोषणा BCENTRE          8
#घोषणा BRIGHT           9

/* ---------------------------------------------------------------------- */

/* this should be C++ compliant, thanks to
     vlp@latina.inesc.pt (Vasco Lopes Paulo) */

#अगर defined(__cplusplus) || defined(c_plusplus)

बाह्य "C" अणु
भग्न   XRotVersion(अक्षर*, पूर्णांक);
व्योम    XRotSetMagnअगरication(भग्न);
व्योम    XRotSetBoundingBoxPad(पूर्णांक);
पूर्णांक     XRotDrawString(Display*, XFontStruct*, भग्न,
                       Drawable, GC, पूर्णांक, पूर्णांक, अक्षर*);
पूर्णांक     XRotDrawImageString(Display*, XFontStruct*, भग्न,
                            Drawable, GC, पूर्णांक, पूर्णांक, अक्षर*);
पूर्णांक     XRotDrawAlignedString(Display*, XFontStruct*, भग्न,
                              Drawable, GC, पूर्णांक, पूर्णांक, अक्षर*, पूर्णांक);
पूर्णांक     XRotDrawAlignedImageString(Display*, XFontStruct*, भग्न,
                                   Drawable, GC, पूर्णांक, पूर्णांक, अक्षर*, पूर्णांक);
XPoपूर्णांक *XRotTextExtents(Display*, XFontStruct*, भग्न,
                        पूर्णांक, पूर्णांक, अक्षर*, पूर्णांक);
पूर्ण

#अन्यथा
बाह्य भग्न   XRotVersion();
बाह्य व्योम    XRotSetMagnअगरication();
बाह्य व्योम    XRotSetBoundingBoxPad();
बाह्य पूर्णांक     XRotDrawString();
बाह्य पूर्णांक     XRotDrawImageString();
बाह्य पूर्णांक     XRotDrawAlignedString();
बाह्य पूर्णांक     XRotDrawAlignedImageString();
बाह्य XPoपूर्णांक *XRotTextExtents();

#पूर्ण_अगर /* __cplusplus */

/* ---------------------------------------------------------------------- */

#पूर्ण_अगर /* _XVERTEXT_INCLUDED_ */

/* ---------------------------------------------------------------------- */

/* Make sure cache size is set */

#अगर_अघोषित CACHE_SIZE_LIMIT
#घोषणा CACHE_SIZE_LIMIT 0
#पूर्ण_अगर /*CACHE_SIZE_LIMIT */

/* Make sure a cache method is specअगरied */

#अगर_अघोषित CACHE_XIMAGES
#अगर_अघोषित CACHE_BITMAPS
#घोषणा CACHE_BITMAPS
#पूर्ण_अगर /*CACHE_BITMAPS*/
#पूर्ण_अगर /*CACHE_XIMAGES*/

/* ---------------------------------------------------------------------- */

/* Debugging macros */

#अगर_घोषित DEBUG
अटल पूर्णांक debug=1;
#अन्यथा
अटल पूर्णांक debug=0;
#पूर्ण_अगर /*DEBUG*/

#घोषणा DEBUG_PRINT1(a) अगर (debug) म_लिखो (a)
#घोषणा DEBUG_PRINT2(a, b) अगर (debug) म_लिखो (a, b)
#घोषणा DEBUG_PRINT3(a, b, c) अगर (debug) म_लिखो (a, b, c)
#घोषणा DEBUG_PRINT4(a, b, c, d) अगर (debug) म_लिखो (a, b, c, d)
#घोषणा DEBUG_PRINT5(a, b, c, d, e) अगर (debug) म_लिखो (a, b, c, d, e)

/* ---------------------------------------------------------------------- */

#अगर_अघोषित M_PI
#घोषणा M_PI 3.14159265358979323846
#पूर्ण_अगर

/* ---------------------------------------------------------------------- */

/* A काष्ठाure holding everything needed क्रम a rotated string */

प्रकार काष्ठा rotated_text_item_ढाँचा अणु
    Pixmap biपंचांगap;
    XImage *ximage;

    अक्षर *text;
    अक्षर *font_name;
    Font fid;
    भग्न angle;
    पूर्णांक align;
    भग्न magnअगरy;

    पूर्णांक cols_in;
    पूर्णांक rows_in;
    पूर्णांक cols_out;
    पूर्णांक rows_out;

    पूर्णांक nl;
    पूर्णांक max_width;
    भग्न *corners_x;
    भग्न *corners_y;

    दीर्घ पूर्णांक size;
    पूर्णांक cached;

    काष्ठा rotated_text_item_ढाँचा *next;
पूर्ण RotatedTextItem;

RotatedTextItem *first_text_item=शून्य;

/* ---------------------------------------------------------------------- */

/* A काष्ठाure holding current magnअगरication and bounding box padding */

अटल काष्ठा style_ढाँचा अणु
    भग्न magnअगरy;
    पूर्णांक bbx_pad;
पूर्ण style=अणु
    1.,
    0
    पूर्ण;

/* ---------------------------------------------------------------------- */

अटल अक्षर            *my_strdup();
अटल अक्षर            *my_म_मोहर();

भग्न                   XRotVersion();
व्योम                    XRotSetMagnअगरication();
व्योम                    XRotSetBoundingBoxPad();
पूर्णांक                     XRotDrawString();
पूर्णांक                     XRotDrawImageString();
पूर्णांक                     XRotDrawAlignedString();
पूर्णांक                     XRotDrawAlignedImageString();
XPoपूर्णांक                 *XRotTextExtents();

अटल XImage          *MakeXImage();
अटल पूर्णांक              XRotPaपूर्णांकAlignedString();
अटल पूर्णांक              XRotDrawHorizontalString();
अटल RotatedTextItem *XRotRetrieveFromCache();
अटल RotatedTextItem *XRotCreateTextItem();
अटल व्योम             XRotAddToLinkedList();
अटल व्योम             XRotFreeTextItem();
अटल XImage          *XRotMagnअगरyImage();

/**************************************************************************/
/* Routine to mimic `strdup()' (some machines don't have it)              */
/**************************************************************************/

अटल अक्षर *my_strdup(str)
    अक्षर *str;
अणु
    अक्षर *s;

    अगर(str==शून्य) वापस शून्य;

    s=(अक्षर *)दो_स्मृति((अचिन्हित)(म_माप(str)+1));
    अगर(s!=शून्य) म_नकल(s, str);

    वापस s;
पूर्ण

/**************************************************************************/
/* Routine to replace `म_मोहर' : this one वापसs a zero length string अगर */
/* it encounters two consecutive delimiters                               */
/**************************************************************************/

अटल अक्षर *my_म_मोहर(str1, str2)
    अक्षर *str1, *str2;
अणु
    अक्षर *ret;
    पूर्णांक i, j, stop;
    अटल पूर्णांक start, len;
    अटल अक्षर *stext;

    अगर(str2==शून्य) वापस शून्य;

    /* initialise अगर str1 not शून्य */
    अगर(str1!=शून्य) अणु
        start=0;
        stext=str1;
        len=म_माप(str1);
    पूर्ण

    /* run out of tokens ? */
    अगर(start>=len) वापस शून्य;

    /* loop through अक्षरacters */
    क्रम(i=start; i<len; i++) अणु
        /* loop through delimiters */
        stop=0;
        क्रम(j=0; j<म_माप(str2); j++)
        अगर(stext[i]==str2[j])
        stop=1;

        अगर(stop) अवरोध;
    पूर्ण

    stext[i]='\0';

    ret=stext+start;

    start=i+1;

    वापस ret;
पूर्ण

/**************************************************************************/
/* Return version/copyright inक्रमmation                                   */
/**************************************************************************/

भग्न XRotVersion(str, n)
    अक्षर *str;
    पूर्णांक n;
अणु
    अगर(str!=शून्य) म_नकलन(str, XV_COPYRIGHT, n);
    वापस XV_VERSION;
पूर्ण

/**************************************************************************/
/* Set the font magnअगरication factor क्रम all subsequent operations        */
/**************************************************************************/

व्योम XRotSetMagnअगरication(m)
    भग्न m;
अणु
    अगर(m>0.) style.magnअगरy=m;
पूर्ण

/**************************************************************************/
/* Set the padding used when calculating bounding boxes                   */
/**************************************************************************/

व्योम XRotSetBoundingBoxPad(p)
    पूर्णांक p;
अणु
    अगर(p>=0) style.bbx_pad=p;
पूर्ण

/**************************************************************************/
/*  Create an XImage काष्ठाure and allocate memory क्रम it                 */
/**************************************************************************/

अटल XImage *MakeXImage(dpy, w, h)
    Display *dpy;
    पूर्णांक w, h;
अणु
    XImage *I;
    अक्षर *data;

    /* reserve memory क्रम image */
    data=(अक्षर *)सुस्मृति((अचिन्हित)(((w-1)/8+1)*h), 1);
    अगर(data==शून्य) वापस शून्य;

    /* create the XImage */
    I=XCreateImage(dpy, DefaultVisual(dpy, DefaultScreen(dpy)), 1, XYBiपंचांगap,
                   0, data, w, h, 8, 0);
    अगर(I==शून्य) वापस शून्य;

    I->byte_order=I->biपंचांगap_bit_order=MSBFirst;
    वापस I;
पूर्ण

/**************************************************************************/
/*  A front end to XRotPaपूर्णांकAlignedString:                                */
/*      -no alignment, no background                                      */
/**************************************************************************/

पूर्णांक XRotDrawString(dpy, font, angle, drawable, gc, x, y, str)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *str;
अणु
    वापस (XRotPaपूर्णांकAlignedString(dpy, font, angle, drawable, gc,
                                   x, y, str, NONE, 0));
पूर्ण

/**************************************************************************/
/*  A front end to XRotPaपूर्णांकAlignedString:                                */
/*      -no alignment, paपूर्णांकs background                                  */
/**************************************************************************/

पूर्णांक XRotDrawImageString(dpy, font, angle, drawable, gc, x, y, str)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *str;
अणु
    वापस(XRotPaपूर्णांकAlignedString(dpy, font, angle, drawable, gc,
                                  x, y, str, NONE, 1));
पूर्ण

/**************************************************************************/
/*  A front end to XRotPaपूर्णांकAlignedString:                                */
/*      -करोes alignment, no background                                    */
/**************************************************************************/

पूर्णांक XRotDrawAlignedString(dpy, font, angle, drawable, gc, x, y, text, align)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *text;
    पूर्णांक align;
अणु
    वापस(XRotPaपूर्णांकAlignedString(dpy, font, angle, drawable, gc,
                                  x, y, text, align, 0));
पूर्ण

/**************************************************************************/
/*  A front end to XRotPaपूर्णांकAlignedString:                                */
/*      -करोes alignment, paपूर्णांकs background                                */
/**************************************************************************/

पूर्णांक XRotDrawAlignedImageString(dpy, font, angle, drawable, gc, x, y, text,
                               align)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *text;
    पूर्णांक align;
अणु
    वापस(XRotPaपूर्णांकAlignedString(dpy, font, angle, drawable, gc,
                                  x, y, text, align, 1));
पूर्ण

/**************************************************************************/
/*  Aligns and paपूर्णांकs a rotated string                                    */
/**************************************************************************/

अटल पूर्णांक XRotPaपूर्णांकAlignedString(dpy, font, angle, drawable, gc, x, y, text,
                                  align, bg)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *text;
    पूर्णांक align;
    पूर्णांक bg;
अणु
    पूर्णांक i;
    GC my_gc;
    पूर्णांक xp, yp;
    भग्न hot_x, hot_y;
    भग्न hot_xp, hot_yp;
    भग्न sin_angle, cos_angle;
    RotatedTextItem *item;
    Pixmap biपंचांगap_to_paपूर्णांक;

    /* वापस early क्रम शून्य/empty strings */
    अगर(text==शून्य)
        वापस 0;

    अगर(म_माप(text)==0) वापस 0;

    /* manipulate angle to 0<=angle<360 degrees */
    जबतक(angle<0)
        angle+=360;

    जबतक(angle>=360)
        angle-=360;

    angle*=M_PI/180;

    /* horizontal text made easy */
    अगर(angle==0. && style.magnअगरy==1.)
        वापस(XRotDrawHorizontalString(dpy, font, drawable, gc, x, y,
                                        text, align, bg));

    /* get a rotated biपंचांगap */
    item=XRotRetrieveFromCache(dpy, font, angle, text, align);
    अगर(item==शून्य) वापस (पूर्णांक)शून्य;

    /* this gc has similar properties to the user's gc */
    my_gc=XCreateGC(dpy, drawable, शून्य, 0);
    XCopyGC(dpy, gc,
       GCForeground|GCBackground|GCFunction|GCPlaneMask|GCClipMask, my_gc);

    /* alignment : which poपूर्णांक (hot_x, hot_y) relative to biपंचांगap centre
       coincides with user's specअगरied poपूर्णांक? */

    /* y position */
    अगर(align==TLEFT || align==TCENTRE || align==TRIGHT)
        hot_y=(भग्न)item->rows_in/2*style.magnअगरy;
    अन्यथा अगर(align==MLEFT || align==MCENTRE || align==MRIGHT)
    अणु
    /*  Modअगरy by O.Couet to have Bottom alignment without font->descent */
    /*  hot_y=0; */
        hot_y=-((भग्न)item->rows_in/4-(भग्न)font->descent)*style.magnअगरy;
    पूर्ण
    अन्यथा अगर(align==BLEFT || align==BCENTRE || align==BRIGHT)
    अणु
    /*  Modअगरy by O.Couet to have Bottom alignment without font->descent */
    /*  hot_y=-(भग्न)item->rows_in/2*style.magnअगरy; */
        hot_y=-((भग्न)item->rows_in/2-(भग्न)font->descent)*style.magnअगरy;
    पूर्ण
    अन्यथा
        hot_y=-((भग्न)item->rows_in/2-(भग्न)font->descent)*style.magnअगरy;

    /* x position */
    अगर(align==TLEFT || align==MLEFT || align==BLEFT || align==NONE)
        hot_x=-(भग्न)item->max_width/2*style.magnअगरy;
    अन्यथा अगर(align==TCENTRE || align==MCENTRE || align==BCENTRE)
        hot_x=0;
    अन्यथा
        hot_x=(भग्न)item->max_width/2*style.magnअगरy;

    /* pre-calculate sin and cos */
    sin_angle=sin(angle);
    cos_angle=cos(angle);

    /* rotate hot_x and hot_y around biपंचांगap centre */
    hot_xp= hot_x*cos_angle - hot_y*sin_angle;
    hot_yp= hot_x*sin_angle + hot_y*cos_angle;

    /* text background will be drawn using XFillPolygon */
    अगर(bg) अणु
        GC depth_one_gc;
        XPoपूर्णांक *xpoपूर्णांकs;
        Pixmap empty_stipple;

        /* reserve space क्रम XPoपूर्णांकs */
        xpoपूर्णांकs=(XPoपूर्णांक *)दो_स्मृति((अचिन्हित)(4*item->nl*माप(XPoपूर्णांक)));
        अगर(!xpoपूर्णांकs) वापस 1;

        /* rotate corner positions */
        क्रम(i=0; i<4*item->nl; i++) अणु
            xpoपूर्णांकs[i].x=(भग्न)x + ( (item->corners_x[i]-hot_x)*cos_angle +
                                      (item->corners_y[i]+hot_y)*sin_angle);
            xpoपूर्णांकs[i].y=(भग्न)y + (-(item->corners_x[i]-hot_x)*sin_angle +
                                      (item->corners_y[i]+hot_y)*cos_angle);
        पूर्ण

        /* we want to swap क्रमeground and background colors here;
           XGetGCValues() is only available in R4+ */

        empty_stipple=XCreatePixmap(dpy, drawable, 1, 1, 1);

        depth_one_gc=XCreateGC(dpy, empty_stipple, शून्य, 0);
        XSetForeground(dpy, depth_one_gc, 0);
        XFillRectangle(dpy, empty_stipple, depth_one_gc, 0, 0, 2, 2);

        XSetStipple(dpy, my_gc, empty_stipple);
        XSetFillStyle(dpy, my_gc, FillOpaqueStippled);

        XFillPolygon(dpy, drawable, my_gc, xpoपूर्णांकs, 4*item->nl, Nonconvex,
              CoordModeOrigin);

        /* मुक्त our resources */
        मुक्त((अक्षर *)xpoपूर्णांकs);
        XFreeGC(dpy, depth_one_gc);
        XFreePixmap(dpy, empty_stipple);
    पूर्ण

    /* where should top left corner of biपंचांगap go ? */
    xp=(भग्न)x-((भग्न)item->cols_out/2 +hot_xp);
    yp=(भग्न)y-((भग्न)item->rows_out/2 -hot_yp);

    /* by शेष we draw the rotated biपंचांगap, solid */
    biपंचांगap_to_paपूर्णांक=item->biपंचांगap;

    /* handle user stippling */
#अगर_अघोषित X11R3
    अणु
        GC depth_one_gc;
        XGCValues values;
        Pixmap new_biपंचांगap, inverse;

        /* try and get some GC properties */
        अगर(XGetGCValues(dpy, gc,
            GCStipple|GCFillStyle|GCForeground|GCBackground|
            GCTileStipXOrigin|GCTileStipYOrigin,
            &values)) अणु

          /* only करो this अगर stippling requested */
          अगर((values.fill_style==FillStippled ||
         values.fill_style==FillOpaqueStippled) && !bg) अणु

         /* opaque stipple: draw rotated text in background colour */
         अगर(values.fill_style==FillOpaqueStippled) अणु
             XSetForeground(dpy, my_gc, values.background);
             XSetFillStyle(dpy, my_gc, FillStippled);
             XSetStipple(dpy, my_gc, item->biपंचांगap);
             XSetTSOrigin(dpy, my_gc, xp, yp);
             XFillRectangle(dpy, drawable, my_gc, xp, yp,
                  item->cols_out, item->rows_out);
             XSetForeground(dpy, my_gc, values.क्रमeground);
         पूर्ण

         /* this will merge the rotated text and the user's stipple */
         new_biपंचांगap=XCreatePixmap(dpy, drawable,
                   item->cols_out, item->rows_out, 1);

                /* create a GC */
                depth_one_gc=XCreateGC(dpy, new_biपंचांगap, शून्य, 0);
                XSetForeground(dpy, depth_one_gc, 1);
                XSetBackground(dpy, depth_one_gc, 0);

                /* set the relative stipple origin */
                XSetTSOrigin(dpy, depth_one_gc,
                 values.ts_x_origin-xp, values.ts_y_origin-yp);

                /* fill the whole biपंचांगap with the user's stipple */
                XSetStipple(dpy, depth_one_gc, values.stipple);
                XSetFillStyle(dpy, depth_one_gc, FillOpaqueStippled);
                XFillRectangle(dpy, new_biपंचांगap, depth_one_gc,
                   0, 0, item->cols_out, item->rows_out);

                /* set stipple origin back to normal */
                XSetTSOrigin(dpy, depth_one_gc, 0, 0);

                /* this will contain an inverse copy of the rotated text */
                inverse=XCreatePixmap(dpy, drawable,
                     item->cols_out, item->rows_out, 1);

                /* invert text */
                XSetFillStyle(dpy, depth_one_gc, FillSolid);
                XSetFunction(dpy, depth_one_gc, GXcopyInverted);
                XCopyArea(dpy, item->biपंचांगap, inverse, depth_one_gc,
              0, 0, item->cols_out, item->rows_out, 0, 0);

                /* now delete user's stipple everywhere EXCEPT on text */
                XSetForeground(dpy, depth_one_gc, 0);
                XSetBackground(dpy, depth_one_gc, 1);
                XSetStipple(dpy, depth_one_gc, inverse);
                XSetFillStyle(dpy, depth_one_gc, FillStippled);
                XSetFunction(dpy, depth_one_gc, GXcopy);
                XFillRectangle(dpy, new_biपंचांगap, depth_one_gc,
                               0, 0, item->cols_out, item->rows_out);

                /* मुक्त resources */
                XFreePixmap(dpy, inverse);
                XFreeGC(dpy, depth_one_gc);

                /* this is the new biपंचांगap */
                biपंचांगap_to_paपूर्णांक=new_biपंचांगap;
          पूर्ण
      पूर्ण
    पूर्ण
#पूर्ण_अगर /*X11R3*/

    /* paपूर्णांक text using stipple technique */
    XSetFillStyle(dpy, my_gc, FillStippled);
    XSetStipple(dpy, my_gc, biपंचांगap_to_paपूर्णांक);
    XSetTSOrigin(dpy, my_gc, xp, yp);
    XFillRectangle(dpy, drawable, my_gc, xp, yp,
            item->cols_out, item->rows_out);

    /* मुक्त our resources */
    XFreeGC(dpy, my_gc);

    /* stippled biपंचांगap no दीर्घer needed */
    अगर(biपंचांगap_to_paपूर्णांक!=item->biपंचांगap)
      XFreePixmap(dpy, biपंचांगap_to_paपूर्णांक);

#अगर_घोषित CACHE_XIMAGES
    XFreePixmap(dpy, item->biपंचांगap);
#पूर्ण_अगर /*CACHE_XIMAGES*/

    /* अगर item isn't cached, destroy it completely */
    अगर(!item->cached)
      XRotFreeTextItem(dpy,item);

    /* we got to the end OK! */
    वापस 0;
पूर्ण

/**************************************************************************/
/*  Draw a horizontal string in a quick fashion                           */
/**************************************************************************/

अटल पूर्णांक XRotDrawHorizontalString(dpy, font, drawable, gc, x, y, text,
                 align, bg)
    Display *dpy;
    XFontStruct *font;
    Drawable drawable;
    GC gc;
    पूर्णांक x, y;
    अक्षर *text;
    पूर्णांक align;
    पूर्णांक bg;
अणु
    GC my_gc;
    पूर्णांक nl=1, i;
    पूर्णांक height;
    पूर्णांक xp, yp;
    अक्षर *str1, *str2, *str3;
    अक्षर *str2_a="\0", *str2_b="\n\0";
    पूर्णांक dir, asc, desc;
    XCharStruct overall;

    DEBUG_PRINT1("**\nHorizontal text.\n");

    /* this gc has similar properties to the user's gc (including stipple) */
    my_gc=XCreateGC(dpy, drawable, शून्य, 0);
    XCopyGC(dpy, gc,
          GCForeground|GCBackground|GCFunction|GCStipple|GCFillStyle|
          GCTileStipXOrigin|GCTileStipYOrigin|GCPlaneMask|GCClipMask, my_gc);
    XSetFont(dpy, my_gc, font->fid);

    /* count number of sections in string */
    अगर(align!=NONE)
      क्रम(i=0; i<म_माप(text)-1; i++)
          अगर(text[i]=='\n')
         nl++;

    /* ignore newline अक्षरacters अगर not करोing alignment */
    अगर(align==NONE)
      str2=str2_a;
    अन्यथा
      str2=str2_b;

    /* overall font height */
    height=font->ascent+font->descent;

    /* y position */
    अगर(align==TLEFT || align==TCENTRE || align==TRIGHT)
      yp=y+font->ascent;
    अन्यथा अगर(align==MLEFT || align==MCENTRE || align==MRIGHT)
    अणु
    /*  Modअगरy by O.Couet to have Middle alignment without font->descent */
    /*  yp=y-nl*height/2+font->ascent; */
        yp=y-nl*(height-font->descent)/2+font->ascent;
    पूर्ण
    अन्यथा अगर(align==BLEFT || align==BCENTRE || align==BRIGHT)
    अणु
    /*  Modअगरy by O.Couet to have Bottom alignment without font->descent */
    /*  yp=y-nl*height+font->ascent; */
        yp=y-nl*(height-font->descent)+font->ascent;
    पूर्ण
    अन्यथा
      yp=y;

    str1=my_strdup(text);
    अगर(str1==शून्य) वापस 1;

    str3=my_म_मोहर(str1, str2);

    /* loop through each section in the string */
    करो अणु
        XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
                     &overall);

      /* where to draw section in x ? */
      अगर(align==TLEFT || align==MLEFT || align==BLEFT || align==NONE)
          xp=x;
      अन्यथा अगर(align==TCENTRE || align==MCENTRE || align==BCENTRE)
          xp=x-overall.rbearing/2;
      अन्यथा
          xp=x-overall.rbearing;

      /* draw string onto biपंचांगap */
      अगर(!bg)
          XDrawString(dpy, drawable, my_gc, xp, yp, str3, म_माप(str3));
      अन्यथा
          XDrawImageString(dpy, drawable, my_gc, xp, yp, str3, म_माप(str3));

      /* move to next line */
      yp+=height;

      str3=my_म_मोहर((अक्षर *)शून्य, str2);
    पूर्ण
    जबतक(str3!=शून्य);

    मुक्त(str1);
    XFreeGC(dpy, my_gc);

    वापस 0;
पूर्ण

/**************************************************************************/
/*   Query cache क्रम a match with this font/text/angle/alignment          */
/*       request, otherwise arrange क्रम its creation                      */
/**************************************************************************/

अटल RotatedTextItem *XRotRetrieveFromCache(dpy, font, angle, text, align)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    अक्षर *text;
    पूर्णांक align;
अणु
    Font fid;
    अक्षर *font_name;
    अचिन्हित दीर्घ name_value;
    RotatedTextItem *item=शून्य;
    RotatedTextItem *i1=first_text_item;

    /* get font name, अगर it exists */
    अगर(XGetFontProperty(font, XA_FONT, &name_value)) अणु
      DEBUG_PRINT1("got font name OK\n");
      font_name=XGetAtomName(dpy, name_value);
      fid=0;
    पूर्ण
#अगर_घोषित CACHE_FID
    /* otherwise rely (unreliably?) on font ID */
    अन्यथा अणु
      DEBUG_PRINT1("can't get fontname, caching FID\n");
      font_name=शून्य;
      fid=font->fid;
    पूर्ण
#अन्यथा
    /* not allowed to cache font ID's */
    अन्यथा अणु
      DEBUG_PRINT1("can't get fontname, can't cache\n");
      font_name=शून्य;
      fid=0;
    पूर्ण
#पूर्ण_अगर /*CACHE_FID*/

    /* look क्रम a match in cache */

    /* matching क्रमmula:
       identical text;
       identical fontname (अगर defined, font ID's अगर not);
       angles बंद enough (<0.00001 here, could be smaller);
       HORIZONTAL alignment matches, OR it's a one line string;
       magnअगरications the same */

    जबतक(i1 && !item) अणु
      /* match everything EXCEPT fontname/ID */
      अगर(म_भेद(text, i1->text)==0 &&
         भ_असल(angle-i1->angle)<0.00001 &&
         style.magnअगरy==i1->magnअगरy &&
         (i1->nl==1 ||
          ((align==0)?9:(align-1))%3==
            ((i1->align==0)?9:(i1->align-1))%3)) अणु

          /* now match fontname/ID */
          अगर(font_name!=शून्य && i1->font_name!=शून्य) अणु
         अगर(म_भेद(font_name, i1->font_name)==0) अणु
             item=i1;
             DEBUG_PRINT1("Matched against font names\n");
         पूर्ण
         अन्यथा
             i1=i1->next;
          पूर्ण
#अगर_घोषित CACHE_FID
          अन्यथा अगर(font_name==शून्य && i1->font_name==शून्य) अणु
         अगर(fid==i1->fid) अणु
             item=i1;
             DEBUG_PRINT1("Matched against FID's\n");
                पूर्ण
         अन्यथा
                    i1=i1->next;
          पूर्ण
#पूर्ण_अगर /*CACHE_FID*/
          अन्यथा
         i1=i1->next;
      पूर्ण
      अन्यथा
          i1=i1->next;
    पूर्ण

    अगर(item)
      DEBUG_PRINT1("**\nFound target in cache.\n");
    अगर(!item)
      DEBUG_PRINT1("**\nNo match in cache.\n");

    /* no match */
    अगर(!item) अणु
      /* create new item */
      item=XRotCreateTextItem(dpy, font, angle, text, align);
      अगर(!item)
          वापस शून्य;

      /* record what it shows */
      item->text=my_strdup(text);

      /* fontname or ID */
      अगर(font_name!=शून्य) अणु
          item->font_name=my_strdup(font_name);
          item->fid=0;
      पूर्ण
      अन्यथा अणु
          item->font_name=शून्य;
          item->fid=fid;
      पूर्ण

      item->angle=angle;
      item->align=align;
      item->magnअगरy=style.magnअगरy;

      /* cache it */
      XRotAddToLinkedList(dpy, item);
    पूर्ण

    अगर(font_name)
      XFree(font_name);

    /* अगर XImage is cached, need to recreate the biपंचांगap */

#अगर_घोषित CACHE_XIMAGES
    अणु
      GC depth_one_gc;

      /* create biपंचांगap to hold rotated text */
      item->biपंचांगap=XCreatePixmap(dpy, DefaultRootWinकरोw(dpy),
                  item->cols_out, item->rows_out, 1);

      /* depth one gc */
      depth_one_gc=XCreateGC(dpy, item->biपंचांगap, शून्य, 0);
      XSetBackground(dpy, depth_one_gc, 0);
      XSetForeground(dpy, depth_one_gc, 1);

      /* make the text biपंचांगap from XImage */
      XPutImage(dpy, item->biपंचांगap, depth_one_gc, item->ximage, 0, 0, 0, 0,
           item->cols_out, item->rows_out);

      XFreeGC(dpy, depth_one_gc);
    पूर्ण
#पूर्ण_अगर /*CACHE_XIMAGES*/

    वापस item;
पूर्ण

/**************************************************************************/
/*  Create a rotated text item                                            */
/**************************************************************************/

अटल RotatedTextItem *XRotCreateTextItem(dpy, font, angle, text, align)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    अक्षर *text;
    पूर्णांक align;
अणु
    RotatedTextItem *item;
    Pixmap canvas;
    GC font_gc;
    XImage *I_in;
    रेजिस्टर पूर्णांक i, j;
    अक्षर *str1, *str2, *str3;
    अक्षर *str2_a="\0", *str2_b="\n\0";
    पूर्णांक height;
    पूर्णांक byte_w_in, byte_w_out;
    पूर्णांक xp, yp;
    भग्न sin_angle, cos_angle;
    पूर्णांक it, jt;
    भग्न di, dj;
    पूर्णांक ic=0;
    भग्न xl, xr, xinc;
    पूर्णांक byte_out;
    पूर्णांक dir, asc, desc;
    XCharStruct overall;
    पूर्णांक old_cols_in=0, old_rows_in=0;

    /* allocate memory */
    item=(RotatedTextItem *)दो_स्मृति((अचिन्हित)माप(RotatedTextItem));
    अगर(!item)
      वापस शून्य;

    /* count number of sections in string */
    item->nl=1;
    अगर(align!=NONE)
      क्रम(i=0; i<म_माप(text)-1; i++)
          अगर(text[i]=='\n')
         item->nl++;

    /* ignore newline अक्षरacters अगर not करोing alignment */
    अगर(align==NONE)
      str2=str2_a;
    अन्यथा
      str2=str2_b;

    /* find width of दीर्घest section */
    str1=my_strdup(text);
    अगर(str1==शून्य) वापस शून्य;

    str3=my_म_मोहर(str1, str2);

    XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
          &overall);

    item->max_width=overall.rbearing;

    /* loop through each section */
    करो अणु
      str3=my_म_मोहर((अक्षर *)शून्य, str2);

      अगर(str3!=शून्य) अणु
          XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
             &overall);
          अगर(overall.rbearing>item->max_width)
         item->max_width=overall.rbearing;
      पूर्ण
    पूर्ण
    जबतक(str3!=शून्य);

    मुक्त(str1);

    /* overall font height */
    height=font->ascent+font->descent;

    /* dimensions horizontal text will have */
    item->cols_in=item->max_width;
    item->rows_in=item->nl*height;

    /* biपंचांगap क्रम drawing on */
    canvas=XCreatePixmap(dpy, DefaultRootWinकरोw(dpy),
             item->cols_in, item->rows_in, 1);

    /* create a GC क्रम the biपंचांगap */
    font_gc=XCreateGC(dpy, canvas, शून्य, 0);
    XSetBackground(dpy, font_gc, 0);
    XSetFont(dpy, font_gc, font->fid);

    /* make sure the biपंचांगap is blank */
    XSetForeground(dpy, font_gc, 0);
    XFillRectangle(dpy, canvas, font_gc, 0, 0,
            item->cols_in+1, item->rows_in+1);
    XSetForeground(dpy, font_gc, 1);

    /* pre-calculate sin and cos */
    sin_angle=sin(angle);
    cos_angle=cos(angle);

    /* text background will be drawn using XFillPolygon */
    item->corners_x=
      (भग्न *)दो_स्मृति((अचिन्हित)(4*item->nl*माप(भग्न)));
    अगर(!item->corners_x)
      वापस शून्य;

    item->corners_y=
      (भग्न *)दो_स्मृति((अचिन्हित)(4*item->nl*माप(भग्न)));
    अगर(!item->corners_y)
      वापस शून्य;

    /* draw text horizontally */

    /* start at top of biपंचांगap */
    yp=font->ascent;

    str1=my_strdup(text);
    अगर(str1==शून्य) वापस शून्य;

    str3=my_म_मोहर(str1, str2);

    /* loop through each section in the string */
    करो अणु
      XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
         &overall);

      /* where to draw section in x ? */
      अगर(align==TLEFT || align==MLEFT || align==BLEFT || align==NONE)
          xp=0;
      अन्यथा अगर(align==TCENTRE || align==MCENTRE || align==BCENTRE)
          xp=(item->max_width-overall.rbearing)/2;
      अन्यथा
            xp=item->max_width-overall.rbearing;

      /* draw string onto biपंचांगap */
      XDrawString(dpy, canvas, font_gc, xp, yp, str3, म_माप(str3));

      /* keep a note of corner positions of this string */
      item->corners_x[ic]=((भग्न)xp-(भग्न)item->cols_in/2)*style.magnअगरy;
      item->corners_y[ic]=((भग्न)(yp-font->ascent)-(भग्न)item->rows_in/2)
          *style.magnअगरy;
      item->corners_x[ic+1]=item->corners_x[ic];
      item->corners_y[ic+1]=item->corners_y[ic]+(भग्न)height*style.magnअगरy;
      item->corners_x[item->nl*4-1-ic]=item->corners_x[ic]+
          (भग्न)overall.rbearing*style.magnअगरy;
      item->corners_y[item->nl*4-1-ic]=item->corners_y[ic];
      item->corners_x[item->nl*4-2-ic]=
          item->corners_x[item->nl*4-1-ic];
      item->corners_y[item->nl*4-2-ic]=item->corners_y[ic+1];

      ic+=2;

      /* move to next line */
      yp+=height;

      str3=my_म_मोहर((अक्षर *)शून्य, str2);
    पूर्ण
    जबतक(str3!=शून्य);

    मुक्त(str1);

    /* create image to hold horizontal text */
    I_in=MakeXImage(dpy, item->cols_in, item->rows_in);
    अगर(I_in==शून्य)
      वापस शून्य;

    /* extract horizontal text */
    XGetSubImage(dpy, canvas, 0, 0, item->cols_in, item->rows_in,
          1, XYPixmap, I_in, 0, 0);
    I_in->क्रमmat=XYBiपंचांगap;

    /* magnअगरy horizontal text */
    अगर(style.magnअगरy!=1.) अणु
      I_in=XRotMagnअगरyImage(dpy, I_in);

      old_cols_in=item->cols_in;
      old_rows_in=item->rows_in;
      item->cols_in=(भग्न)item->cols_in*style.magnअगरy;
      item->rows_in=(भग्न)item->rows_in*style.magnअगरy;
    पूर्ण

    /* how big will rotated text be ? */
    item->cols_out=भ_असल((भग्न)item->rows_in*sin_angle) +
      भ_असल((भग्न)item->cols_in*cos_angle) +0.99999 +2;

    item->rows_out=भ_असल((भग्न)item->rows_in*cos_angle) +
      भ_असल((भग्न)item->cols_in*sin_angle) +0.99999 +2;

    अगर(item->cols_out%2==0)
      item->cols_out++;

    अगर(item->rows_out%2==0)
      item->rows_out++;

    /* create image to hold rotated text */
    item->ximage=MakeXImage(dpy, item->cols_out, item->rows_out);
    अगर(item->ximage==शून्य)
      वापस शून्य;

    byte_w_in=(item->cols_in-1)/8+1;
    byte_w_out=(item->cols_out-1)/8+1;

    /* we try to make this bit as fast as possible - which is why it looks
       a bit over-the-top */

    /* vertical distance from centre */
    dj=0.5-(भग्न)item->rows_out/2;

    /* where abouts करोes text actually lie in rotated image? */
    अगर(angle==0 || angle==M_PI/2 ||
       angle==M_PI || angle==3*M_PI/2) अणु
      xl=0;
      xr=(भग्न)item->cols_out;
      xinc=0;
    पूर्ण
    अन्यथा अगर(angle<M_PI) अणु
      xl=(भग्न)item->cols_out/2+
          (dj-(भग्न)item->rows_in/(2*cos_angle))/
         tan(angle)-2;
      xr=(भग्न)item->cols_out/2+
          (dj+(भग्न)item->rows_in/(2*cos_angle))/
         tan(angle)+2;
      xinc=1./tan(angle);
    पूर्ण
    अन्यथा अणु
      xl=(भग्न)item->cols_out/2+
          (dj+(भग्न)item->rows_in/(2*cos_angle))/
         tan(angle)-2;
      xr=(भग्न)item->cols_out/2+
          (dj-(भग्न)item->rows_in/(2*cos_angle))/
         tan(angle)+2;

      xinc=1./tan(angle);
    पूर्ण

    /* loop through all relevent bits in rotated image */
    क्रम(j=0; j<item->rows_out; j++) अणु

      /* no poपूर्णांक re-calculating these every pass */
      di=(भग्न)((xl<0)?0:(पूर्णांक)xl)+0.5-(भग्न)item->cols_out/2;
      byte_out=(item->rows_out-j-1)*byte_w_out;

      /* loop through meaningful columns */
      क्रम(i=((xl<0)?0:(पूर्णांक)xl);
          i<((xr>=item->cols_out)?item->cols_out:(पूर्णांक)xr); i++) अणु

          /* rotate coordinates */
          it=(भग्न)item->cols_in/2 + ( di*cos_angle + dj*sin_angle);
          jt=(भग्न)item->rows_in/2 - (-di*sin_angle + dj*cos_angle);

            /* set pixel अगर required */
            अगर(it>=0 && it<item->cols_in && jt>=0 && jt<item->rows_in)
                अगर((I_in->data[jt*byte_w_in+it/8] & 128>>(it%8))>0)
                    item->ximage->data[byte_out+i/8]|=128>>i%8;

          di+=1;
      पूर्ण
      dj+=1;
      xl+=xinc;
      xr+=xinc;
    पूर्ण
    XDestroyImage(I_in);

    अगर(style.magnअगरy!=1.) अणु
      item->cols_in=old_cols_in;
      item->rows_in=old_rows_in;
    पूर्ण


#अगर_घोषित CACHE_BITMAPS

    /* create a biपंचांगap to hold rotated text */
    item->biपंचांगap=XCreatePixmap(dpy, DefaultRootWinकरोw(dpy),
                   item->cols_out, item->rows_out, 1);

    /* make the text biपंचांगap from XImage */
    XPutImage(dpy, item->biपंचांगap, font_gc, item->ximage, 0, 0, 0, 0,
            item->cols_out, item->rows_out);

    XDestroyImage(item->ximage);

#पूर्ण_अगर /*CACHE_BITMAPS*/

    XFreeGC(dpy, font_gc);
    XFreePixmap(dpy, canvas);

    वापस item;
पूर्ण

/**************************************************************************/
/*  Adds a text item to the end of the cache, removing as many items      */
/*      from the front as required to keep cache size below limit         */
/**************************************************************************/

अटल व्योम XRotAddToLinkedList(dpy, item)
    Display *dpy;
    RotatedTextItem *item;
अणु

    अटल दीर्घ पूर्णांक current_size=0;
    अटल RotatedTextItem *last=शून्य;
    RotatedTextItem *i1=first_text_item, *i2;

#अगर_घोषित CACHE_BITMAPS

    /* I करोn't know how much memory a pixmap takes in the server -
           probably this + a bit more we can't account क्रम */

    item->size=((item->cols_out-1)/8+1)*item->rows_out;

#अन्यथा

    /* this is pretty much the size of a RotatedTextItem */

    item->size=((item->cols_out-1)/8+1)*item->rows_out +
      माप(XImage) + म_माप(item->text) +
          item->nl*8*माप(भग्न) + माप(RotatedTextItem);

    अगर(item->font_name!=शून्य)
      item->size+=म_माप(item->font_name);
    अन्यथा
      item->size+=माप(Font);

#पूर्ण_अगर /*CACHE_BITMAPS */

#अगर_घोषित DEBUG
    /* count number of items in cache, क्रम debugging */
    अणु
      पूर्णांक i=0;

      जबतक(i1) अणु
          i++;
          i1=i1->next;
      पूर्ण
      DEBUG_PRINT2("Cache has %d items.\n", i);
      i1=first_text_item;
    पूर्ण
#पूर्ण_अगर

    DEBUG_PRINT4("current cache size=%ld, new item=%ld, limit=%ld\n",
          current_size, item->size, CACHE_SIZE_LIMIT*1024);

    /* अगर this item is bigger than whole cache, क्रमget it */
    अगर(item->size>CACHE_SIZE_LIMIT*1024) अणु
      DEBUG_PRINT1("Too big to cache\n\n");
      item->cached=0;
      वापस;
    पूर्ण

    /* हटाओ elements from cache as needed */
    जबतक(i1 && current_size+item->size>CACHE_SIZE_LIMIT*1024) अणु

      DEBUG_PRINT2("Removed %d bytes\n", i1->size);

      अगर(i1->font_name!=शून्य)
          DEBUG_PRINT5("  (`%s'\n   %s\n   angle=%f align=%d)\n",
             i1->text, i1->font_name, i1->angle, i1->align);

#अगर_घोषित CACHE_FID
      अगर(i1->font_name==शून्य)
          DEBUG_PRINT5("  (`%s'\n  FID=%ld\n   angle=%f align=%d)\n",
                         i1->text, i1->fid, i1->angle, i1->align);
#पूर्ण_अगर /*CACHE_FID*/

      current_size-=i1->size;

      i2=i1->next;

      /* मुक्त resources used by the unlucky item */
      XRotFreeTextItem(dpy, i1);

      /* हटाओ it from linked list */
      first_text_item=i2;
      i1=i2;
    पूर्ण

    /* add new item to end of linked list */
    अगर(first_text_item==शून्य) अणु
      item->next=शून्य;
      first_text_item=item;
      last=item;
    पूर्ण
    अन्यथा अणु
      item->next=शून्य;
      last->next=item;
      last=item;
    पूर्ण

    /* new cache size */
    current_size+=item->size;

    item->cached=1;

    DEBUG_PRINT1("Added item to cache.\n");
पूर्ण

/**************************************************************************/
/*  Free the resources used by a text item                                */
/**************************************************************************/

अटल व्योम XRotFreeTextItem(dpy, item)
    Display *dpy;
    RotatedTextItem *item;
अणु
    मुक्त(item->text);

    अगर(item->font_name!=शून्य)
      मुक्त(item->font_name);

    मुक्त((अक्षर *)item->corners_x);
    मुक्त((अक्षर *)item->corners_y);

#अगर_घोषित CACHE_BITMAPS
    XFreePixmap(dpy, item->biपंचांगap);
#अन्यथा
    XDestroyImage(item->ximage);
#पूर्ण_अगर /* CACHE_BITMAPS */

    मुक्त((अक्षर *)item);
पूर्ण

/**************************************************************************/
/* Magnअगरy an XImage using bilinear पूर्णांकerpolation                         */
/**************************************************************************/

अटल XImage *XRotMagnअगरyImage(dpy, ximage)
    Display *dpy;
    XImage *ximage;
अणु
    पूर्णांक i, j;
    भग्न x, y;
    भग्न u,t;
    XImage *I_out;
    पूर्णांक cols_in, rows_in;
    पूर्णांक cols_out, rows_out;
    रेजिस्टर पूर्णांक i2, j2;
    भग्न z1, z2, z3, z4;
    पूर्णांक byte_width_in, byte_width_out;
    भग्न mag_inv;

    /* size of input image */
    cols_in=ximage->width;
    rows_in=ximage->height;

    /* size of final image */
    cols_out=(भग्न)cols_in*style.magnअगरy;
    rows_out=(भग्न)rows_in*style.magnअगरy;

    /* this will hold final image */
    I_out=MakeXImage(dpy, cols_out, rows_out);
    अगर(I_out==शून्य)
      वापस शून्य;

    /* width in bytes of input, output images */
    byte_width_in=(cols_in-1)/8+1;
    byte_width_out=(cols_out-1)/8+1;

    /* क्रम speed */
    mag_inv=1./style.magnअगरy;

    y=0.;

    /* loop over magnअगरied image */
    क्रम(j2=0; j2<rows_out; j2++) अणु
      x=0;
      j=y;

      क्रम(i2=0; i2<cols_out; i2++) अणु
          i=x;

          /* bilinear पूर्णांकerpolation - where are we on biपंचांगap ? */
          /* right edge */
          अगर(i==cols_in-1 && j!=rows_in-1) अणु
         t=0;
         u=y-(भग्न)j;

         z1=(ximage->data[j*byte_width_in+i/8] & 128>>(i%8))>0;
         z2=z1;
         z3=(ximage->data[(j+1)*byte_width_in+i/8] & 128>>(i%8))>0;
         z4=z3;
          पूर्ण
          /* top edge */
          अन्यथा अगर(i!=cols_in-1 && j==rows_in-1) अणु
         t=x-(भग्न)i;
         u=0;

         z1=(ximage->data[j*byte_width_in+i/8] & 128>>(i%8))>0;
         z2=(ximage->data[j*byte_width_in+(i+1)/8] & 128>>((i+1)%8))>0;
         z3=z2;
         z4=z1;
          पूर्ण
          /* top right corner */
          अन्यथा अगर(i==cols_in-1 && j==rows_in-1) अणु
         u=0;
         t=0;

         z1=(ximage->data[j*byte_width_in+i/8] & 128>>(i%8))>0;
         z2=z1;
         z3=z1;
         z4=z1;
          पूर्ण
          /* somewhere `safe' */
          अन्यथा अणु
         t=x-(भग्न)i;
         u=y-(भग्न)j;

         z1=(ximage->data[j*byte_width_in+i/8] & 128>>(i%8))>0;
         z2=(ximage->data[j*byte_width_in+(i+1)/8] & 128>>((i+1)%8))>0;
         z3=(ximage->data[(j+1)*byte_width_in+(i+1)/8] &
             128>>((i+1)%8))>0;
         z4=(ximage->data[(j+1)*byte_width_in+i/8] & 128>>(i%8))>0;
          पूर्ण

          /* अगर पूर्णांकerpolated value is greater than 0.5, set bit */
          अगर(((1-t)*(1-u)*z1 + t*(1-u)*z2 + t*u*z3 + (1-t)*u*z4)>0.5)
         I_out->data[j2*byte_width_out+i2/8]|=128>>i2%8;

          x+=mag_inv;
      पूर्ण
      y+=mag_inv;
    पूर्ण

    /* destroy original */
    XDestroyImage(ximage);

    /* वापस big image */
    वापस I_out;
पूर्ण

/**************************************************************************/
/* Calculate the bounding box some text will have when paपूर्णांकed            */
/**************************************************************************/

XPoपूर्णांक *XRotTextExtents(dpy, font, angle, x, y, text, align)
    Display *dpy;
    XFontStruct *font;
    भग्न angle;
    पूर्णांक x, y;
    अक्षर *text;
    पूर्णांक align;
अणु
    रेजिस्टर पूर्णांक i;
    अक्षर *str1, *str2, *str3;
    अक्षर *str2_a="\0", *str2_b="\n\0";
    पूर्णांक height;
    भग्न sin_angle, cos_angle;
    पूर्णांक nl, max_width;
    पूर्णांक cols_in, rows_in;
    भग्न hot_x, hot_y;
    XPoपूर्णांक *xp_in, *xp_out;
    पूर्णांक dir, asc, desc;
    XCharStruct overall;

    /* manipulate angle to 0<=angle<360 degrees */
    जबतक(angle<0)
        angle+=360;

    जबतक(angle>360)
        angle-=360;

    angle*=M_PI/180;

    /* count number of sections in string */
    nl=1;
    अगर(align!=NONE)
      क्रम(i=0; i<म_माप(text)-1; i++)
          अगर(text[i]=='\n')
         nl++;

    /* ignore newline अक्षरacters अगर not करोing alignment */
    अगर(align==NONE)
      str2=str2_a;
    अन्यथा
      str2=str2_b;

    /* find width of दीर्घest section */
    str1=my_strdup(text);
    अगर(str1==शून्य) वापस शून्य;

    str3=my_म_मोहर(str1, str2);

    XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
          &overall);

    max_width=overall.rbearing;

    /* loop through each section */
    करो अणु
      str3=my_म_मोहर((अक्षर *)शून्य, str2);

      अगर(str3!=शून्य) अणु
          XTextExtents(font, str3, म_माप(str3), &dir, &asc, &desc,
             &overall);

          अगर(overall.rbearing>max_width)
         max_width=overall.rbearing;
      पूर्ण
    पूर्ण
    जबतक(str3!=शून्य);

    मुक्त(str1);

    /* overall font height */
    height=font->ascent+font->descent;

    /* dimensions horizontal text will have */
    cols_in=max_width;
    rows_in=nl*height;

    /* pre-calculate sin and cos */
    sin_angle=sin(angle);
    cos_angle=cos(angle);

    /* y position */
    अगर(align==TLEFT || align==TCENTRE || align==TRIGHT)
        hot_y=(भग्न)rows_in/2*style.magnअगरy;
    अन्यथा अगर(align==MLEFT || align==MCENTRE || align==MRIGHT)
      hot_y=0;
    अन्यथा अगर(align==BLEFT || align==BCENTRE || align==BRIGHT)
      hot_y=-(भग्न)rows_in/2*style.magnअगरy;
    अन्यथा
      hot_y=-((भग्न)rows_in/2-(भग्न)font->descent)*style.magnअगरy;

    /* x position */
    अगर(align==TLEFT || align==MLEFT || align==BLEFT || align==NONE)
      hot_x=-(भग्न)max_width/2*style.magnअगरy;
    अन्यथा अगर(align==TCENTRE || align==MCENTRE || align==BCENTRE)
      hot_x=0;
    अन्यथा
        hot_x=(भग्न)max_width/2*style.magnअगरy;

    /* reserve space क्रम XPoपूर्णांकs */
    xp_in=(XPoपूर्णांक *)दो_स्मृति((अचिन्हित)(5*माप(XPoपूर्णांक)));
    अगर(!xp_in)
      वापस शून्य;

    xp_out=(XPoपूर्णांक *)दो_स्मृति((अचिन्हित)(5*माप(XPoपूर्णांक)));
    अगर(!xp_out)
      वापस शून्य;

    /* bounding box when horizontal, relative to biपंचांगap centre */
    xp_in[0].x=-(भग्न)cols_in*style.magnअगरy/2-style.bbx_pad;
    xp_in[0].y= (भग्न)rows_in*style.magnअगरy/2+style.bbx_pad;
    xp_in[1].x= (भग्न)cols_in*style.magnअगरy/2+style.bbx_pad;
    xp_in[1].y= (भग्न)rows_in*style.magnअगरy/2+style.bbx_pad;
    xp_in[2].x= (भग्न)cols_in*style.magnअगरy/2+style.bbx_pad;
    xp_in[2].y=-(भग्न)rows_in*style.magnअगरy/2-style.bbx_pad;
    xp_in[3].x=-(भग्न)cols_in*style.magnअगरy/2-style.bbx_pad;
    xp_in[3].y=-(भग्न)rows_in*style.magnअगरy/2-style.bbx_pad;
    xp_in[4].x=xp_in[0].x;
    xp_in[4].y=xp_in[0].y;

    /* rotate and translate bounding box */
    क्रम(i=0; i<5; i++) अणु
      xp_out[i].x=(भग्न)x + ( ((भग्न)xp_in[i].x-hot_x)*cos_angle +
                ((भग्न)xp_in[i].y+hot_y)*sin_angle);
      xp_out[i].y=(भग्न)y + (-((भग्न)xp_in[i].x-hot_x)*sin_angle +
                ((भग्न)xp_in[i].y+hot_y)*cos_angle);
    पूर्ण

    मुक्त((अक्षर *)xp_in);

    वापस xp_out;
पूर्ण
