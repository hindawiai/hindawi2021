<शैली गुरु>
/*
Copyright (C) 2003,2004,2005,2006 Abhishek Choudhary
This file is part of the AP Code क्रम Indian Script Representation.

The AP Code क्रम Indian Script Representation is मुक्त software;
you can redistribute it and/or modअगरy it under the terms of the
GNU General Public License as published by the
Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

The AP Code क्रम Indian Script Representation is distributed in the hope
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

        20-Jan-2006, Added the modअगरications section,
                        Abhishek Choudhary <hi_pedler>,
                        choudhary@indicybers.net

End of modअगरications.
*/

#अगर_अघोषित __ACI2CISR_H__
#घोषणा __ACI2CISR_H__
#समावेश "cisr2asc.h"
#समावेश "apcisr.h"
#समावेश <मानकपन.स>
#समावेश <माला.स>

#अगर_घोषित __cplusplus
बाह्य "C"
अणु
#पूर्ण_अगर

  बाह्य cisr retval;
  बाह्य cisr acii2cisr (अचिन्हित अक्षर *aci_in, पूर्णांक cpos);
  बाह्य cisr cisr_trim (cisr dvn);
  बाह्य पूर्णांक cisr_म_लिखो_con (cisr dvn);

#अगर_घोषित __DJGPP
#समावेश <पट्टपन.स>
  बाह्य पूर्णांक cisr_म_लिखो (पूर्णांक x, पूर्णांक y, cisr dvn);
  बाह्य पूर्णांक cisr_म_लिखो_clean (पूर्णांक x, पूर्णांक y, cisr dvn);	/*clean to 78 + prपूर्णांक dvn */
  बाह्य पूर्णांक cisr_clean (पूर्णांक x, पूर्णांक y);	/*only clean to 78 */
  बाह्य पूर्णांक c3n_म_लिखो (पूर्णांक x, पूर्णांक y, अक्षर *txt);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
पूर्ण
#पूर्ण_अगर

#पूर्ण_अगर
