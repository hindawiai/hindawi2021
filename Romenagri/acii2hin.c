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

#समावेश "acii2hin.h"

अक्षर *
acii2hin (अक्षर *tok)
अणु
  अक्षर t1, t2, tpush[2];
  पूर्णांक i, j, fnd;
  stack_reset ();
  क्रम (i = 0; i < म_माप (tok); i++)
    अणु
      fnd = 0;
      क्रम (j = 0; j < 75; j++)
	अणु
	  अगर (tok[i] == *(acii_hin_chrt[j][1]))
	    अणु
	      अगर (*acii_hin_chrt[j][0] == '^' && stack_len () > 0)	/*matra */
		अणु
		  pop (1);
		  अगर (*(acii_hin_chrt[j][0] + 1) == 'z')
		    अणु
		      t1 = *pop (1);
		      अगर (t1 == 'h')
			अणु
			  t2 = *pop (1);
			  अगर (t2 == 'd')
			    push ((अक्षर *) "_rdha");
			  अन्यथा
			    अणु
			      tpush[0] = t2;
			      tpush[1] = '\0';
			      push ((अक्षर *) tpush);
			      push ((अक्षर *) "hza");
			    पूर्ण
			पूर्ण
		      अन्यथा
			अणु
			  अगर (t1 == 'd')
			    push ((अक्षर *) "_rda");
			  अन्यथा
			    अणु
			      tpush[0] = t1;
			      tpush[1] = '\0';
			      push ((अक्षर *) tpush);
			      push ((अक्षर *) "za");
			    पूर्ण
			पूर्ण
		    पूर्ण
		  अन्यथा
		    अणु
		      push ((अक्षर *) (acii_hin_chrt[j][0] + 1));
		    पूर्ण
		पूर्ण
	      अन्यथा
		push (acii_hin_chrt[j][0]);
	      fnd = 1;
	      अवरोध;
	    पूर्ण
	पूर्ण
      अगर (fnd == 0 && tok[i - 1] != acii_hin_chrt[0][1][0])
	अणु
	  tpush[0] = tok[i];
	  tpush[1] = '\0';
	  push (tpush);
	पूर्ण
    पूर्ण
  म_नकल (msg, pop (stack_len ()));
  वापस msg;
पूर्ण
