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
#समावेश "acii2rmn.h"
#समावेश "rmn2acii.h"

/*msg is used by the Romenagri routines to वापस the results*/
अक्षर msg2[10240], *msg = msg2;

पूर्णांक
मुख्य (पूर्णांक argc, अक्षर *argv[])
अणु
  अक्षर text[1024];
  म_लिखो ("Romenagri test: \n");
  म_लिखो ("Enter some text for Romenagri to ISCII conversion:");
  म_पूछो ("%s", text);
  म_जोड़ो (text, " ");		/*this is करोne क्रम safety as the parser is LA(1) */
  म_लिखो ("The text in ISCII is %s\n", rmn2acii (text));
  म_लिखो ("Verifying the reverse conversion we get %s\n",
	  acii2rmn (rmn2acii (text)));

  वापस 0;
पूर्ण
