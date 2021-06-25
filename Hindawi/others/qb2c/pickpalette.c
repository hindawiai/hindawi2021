<शैली गुरु>
/*
 * $Id: imgpickpalette.c,v 1.3 1996/03/19 16:10:28 couet Exp $
 *
 * $Log: imgpickpalette.c,v $
 * Revision 1.3  1996/03/19 16:10:28  couet
 * The variable "window" is now compared with 0 instead of शून्य.
 *
 * Revision 1.2  1996/03/19 15:27:36  couet
 * The variable "window" is now compared with (Winकरोw)शून्य instead of शून्य.
 * Some compilers need this cast.
 *
 * Revision 1.1.1.1  1996/02/14 13:10:26  mclareni
 * Higz
 *
 */
/*CMZ :  1.20/08 19/01/94  14.30.44  by  O.Couet*/
/*-- Author :    E.Chernyaev   19/01/94*/
#समावेश <X11/Xlib.h>
#समावेश <X11/Xutil.h>
#समावेश <X11/cursorfont.h>
#समावेश <मानकपन.स>
#समावेश <समय.स>

#घोषणा MAXCOL  256

/***********************************************************************
 *                                                                     *
 * Name: ImgPickPalette                              Date:    22.02.93 *
 * Author: E.Chernyaev (IHEP/Protvino)               Revised:          *
 *                                                                     *
 * Function: Pick palette क्रम image output                             *
 *                                                                     *
 * Input: theDsp - poपूर्णांकer to display काष्ठाure                        *
 *        winकरोw - winकरोw                                              *
 *                                                                     *
 * Output: Ncol  - number of colors                                    *
 *         R[]   - red components                                      *
 *         G[]   - green components                                    *
 *         B[]   - blue components                                     *
 *                                                                     *
 ***********************************************************************/
व्योम ImgPickPalette(theDsp, winकरोw, Ncol, R, G, B)
           Display *theDsp;
           Winकरोw   winकरोw;
           पूर्णांक     *Ncol, *R, *G, *B;
अणु
  पूर्णांक               i, theScr, nmaps, ncolors;
  Winकरोw            theRoot, theWin;
  Colormap          cmap, *cmaps;
  XColor            colors[MAXCOL];
  XWinकरोwAttributes theAtt;

  theScr  = DefaultScreen(theDsp);
  theRoot = RootWinकरोw(theDsp, theScr);

  अगर (winकरोw != 0 && winकरोw != theRoot)
    theWin  = winकरोw;
  अन्यथा
    theWin  = theRoot;

  XGetWinकरोwAttributes(theDsp, theWin, &theAtt);

  अगर (theAtt.colormap && theAtt.map_installed) अणु
    ncolors = theAtt.visual->map_entries;
    cmap    = theAtt.colormap;
  पूर्णअन्यथाअणु
    ncolors = DisplayCells(theDsp, theScr);
    cmap    = DefaultColormap(theDsp, theScr);
    cmaps   = XListInstalledColormaps(theDsp, theRoot, &nmaps);
    अगर (nmaps != 0) अणु
      क्रम (i=0; i<nmaps; i++) अणु
        अगर (cmap == cmaps[i]) अवरोध;
        अगर (i == nmaps-1) cmap = cmaps[0];
      पूर्ण
    पूर्ण
    XFree((व्योम *) cmaps);
  पूर्ण

  क्रम (i=0; i<ncolors; i++) अणु
    colors[i].pixel = i;
    colors[i].pad   = 0;
  पूर्ण
  XQueryColors(theDsp, cmap, colors, ncolors);

  *Ncol   = ncolors;
  म_लिखो("Read %d colors.\n", ncolors);
  क्रम (i=0; i<ncolors; i++) अणु
    R[i] = colors[i].red;
    G[i] = colors[i].green;
    B[i] = colors[i].blue;
  पूर्ण
पूर्ण
