<शैली गुरु>
/*
Copyright (C) 2003,2004,2005,2006 Abhishek Choudhary
This file is part of the Romenagri Transliteration System.

The Romenagri Transliteration System is मुक्त software;
you can redistribute it and/or modअगरy it under the terms of the
GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

The Romenagri Transliteration System is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE. See the GNU General Public License क्रम
more details.

You should have received a copy of the GNU General Public
License aदीर्घ with this file; see the file COPYING. If
not, ग_लिखो to the Free Software Foundation,
51 Franklin Street, Fअगरth Floor, Boston, MA 02110-1301 USA
*/

/*
Modअगरications: (Please मुख्यtain reverse chronological order)

	dd-mmm-yyyy, Nature of modअगरication,
                        Name of modअगरier <alias>,
			email adress of modअगरier

	19-Jan-2006, Added the modअगरications section,
                        Abhishek Choudhary <hi_pedler>,
			choudhary@indicybers.net

End of modअगरications.
*/

#समावेश <मानकपन.स>
#समावेश <fcntl.h>

#समावेश "unicode.h"

पूर्णांक
मुख्य (पूर्णांक argc, अक्षर *argv[])
अणु
  खाता *fin, *fout;
  अचिन्हित अक्षर t1, t2, पंचांगp[4];
  पूर्णांक i = 0, flag = 0;

#अगर_घोषित __DJGPP
  _भ_शेषe = O_BINARY;
#पूर्ण_अगर

  पंचांगp[0] = 0;
  पंचांगp[1] = 0;
  पंचांगp[2] = 0;
  पंचांगp[3] = 0;

  अगर (argc < 2)
    अणु
      fin = मानक_निवेश;
      fout = मानक_निकास;
    पूर्ण
  अन्यथा
    अणु
      अगर (argc < 3)
	अणु
	  म_लिखो ("Usage: uni2acii <UNICODE_filename> <ISCII_filename>\n");
	  वापस 1;
	पूर्ण


      अगर ((fin = ख_खोलो (argv[1], "r+")) == शून्य)
	अणु
	  ख_लिखो (मानक_त्रुटि, "Cannot open input file, using stdin.\n");
	  fin = मानक_निवेश;
	पूर्ण

      अगर ((fout = ख_खोलो (argv[2], "w")) == शून्य)
	अणु
	  ख_लिखो (मानक_त्रुटि, "Cannot open output file, using stdout.\n");
	  fout = मानक_निकास;
	पूर्ण
    पूर्ण

  जबतक (!ख_पूर्ण (fin))
    अणु
      t1 = ख_अक्षर_लो (fin);
      अगर (ख_पूर्ण (fin))
	अवरोध;
      t2 = ख_अक्षर_लो (fin);
      अगर (ख_पूर्ण (fin))
	अवरोध;

      अगर (t1 == 255 && t2 == 254)
	जारी;		/*eat the control */

      अगर (t1 == 13 && t2 == 0)
	जारी;		/*eat cr */

      पंचांगp[0] = पंचांगp[2];
      पंचांगp[1] = पंचांगp[3];
      पंचांगp[2] = t1;
      पंचांगp[3] = t2;

      flag = 0;
      क्रम (i = 0; i < UNI_LEN; i++)
	अणु
	  अगर (t1 == unicode_hin[i][0] && t2 == unicode_hin[i][1])	/*match */
	    अणु
	      flag = 1;
	      अवरोध;
	    पूर्ण
	पूर्ण
      अगर (flag == 1)
	अणु
	  ख_अक्षर_दो (unicode_hin[i][2], fout);
	पूर्ण
      अन्यथा
	अणु
	  ख_अक्षर_दो (t1, fout);	/*presuming 0 to 127 */
	पूर्ण
    पूर्ण

  ख_बंद (fin);
  ख_बंद (fout);

  वापस 0;
पूर्ण
