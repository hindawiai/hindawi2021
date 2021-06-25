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

#समावेश "rmn2acii.h"
अक्षर tst2[2];
अक्षर *tst = tst2;
अक्षर *lev1 = "|kgcjtdnpbmyrlwsxh_^";

अक्षर *
c2s (अक्षर t)
अणु
  tst[0] = t;
  tst[1] = '\0';
  वापस tst;
पूर्ण

अक्षर *
lookup (अक्षर *key)
अणु
  पूर्णांक i;
  क्रम (i = 0; i < 74; i++)
    अणु
      अगर (म_भेद (acii_chrt[i][0], key) == 0)
	वापस acii_chrt[i][1];
    पूर्ण
  वापस शून्य;
पूर्ण

पूर्णांक
matra (अक्षर *tok)
अणु
  अगर (म_माप (tok) < 1)
    अणु
      म_जोड़ो (msg, lookup ("^"));	/*terminating 'halant' */
      वापस 1;
    पूर्ण
  चयन (tok[0])
    अणु
    हाल 'i':
      म_जोड़ो (msg, lookup ("^i"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'u':
      म_जोड़ो (msg, lookup ("^u"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'e':
      म_जोड़ो (msg, lookup ("^ee"));
      tok += 2;
      level1 (tok);
      अवरोध;
    हाल 'z':
      म_जोड़ो (msg, lookup ("^za"));
      level2a (++tok);
      अवरोध;
    हाल '_':			/*redundant */
      म_जोड़ो (msg, lookup ("^_ri"));
      tok += 3;
      level1 (tok);
      अवरोध;
    हाल 'o':
      tok++;
      चयन (tok[0])
	अणु
	हाल 'o':
	  म_जोड़ो (msg, lookup ("^oo"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'a':
	  म_जोड़ो (msg, lookup ("^oa"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'u':
	  म_जोड़ो (msg, lookup ("^ou"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	शेष:
	  म_जोड़ो (msg, c2s (tok[0]));
	  level1 (++tok);
	पूर्ण;
      अवरोध;
    हाल 'a':
      tok++;
      अगर (म_माला (lev1, c2s (tok[0])) != शून्य)
	level1 (tok);
      अन्यथा
	चयन (tok[0])
	  अणु
	  हाल 'a':
	    म_जोड़ो (msg, lookup ("^aa"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'e':
	    म_जोड़ो (msg, lookup ("^ae"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'i':
	    म_जोड़ो (msg, lookup ("^ai"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'o':
	    म_जोड़ो (msg, lookup ("^ao"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'u':
	    म_जोड़ो (msg, lookup ("^au"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  शेष:
	    म_जोड़ो (msg, c2s (tok[0]));
	    level1 (++tok);
	  पूर्ण;
      अवरोध;
    शेष:
      म_जोड़ो (msg, c2s (tok[0]));
      level1 (++tok);
    पूर्ण;
  वापस 1;
पूर्ण

पूर्णांक
level2a (अक्षर *tok)
अणु
  अगर (म_माप (tok) < 1)
    अणु
      म_जोड़ो (msg, lookup ("^"));
      वापस 1;
    पूर्ण
  अगर (म_माला (lev1, c2s (tok[0])) != शून्य)
    अणु
      म_जोड़ो (msg, lookup ("^"));
      level1 (tok);
    पूर्ण
  अन्यथा
    matra (tok);
  वापस 1;
पूर्ण

पूर्णांक
level2b (अक्षर *tok, अक्षर *lk)
अणु
  अक्षर lup[7];
  म_नकल (lup, lk);
  अगर (म_माप (tok) < 1)
    अणु
      म_जोड़ो (lup, "a");
      म_जोड़ो (msg, lookup (lup));
      म_जोड़ो (msg, lookup ("^"));
      वापस 1;
    पूर्ण
  अगर (tok[0] == 'h')
    अणु
      म_जोड़ो (lup, "ha");
      म_जोड़ो (msg, lookup (lup));
      level2a (++tok);
    पूर्ण
  अन्यथा अगर (tok[0] == 'v')	/*lvra-हाल */
    अणु
      म_जोड़ो (lup, "vra");
      म_जोड़ो (msg, lookup (lup));
      level2a ((tok + 2));
    पूर्ण
  अन्यथा
    अणु
      म_जोड़ो (lup, "a");
      म_जोड़ो (msg, lookup (lup));
      level2a (tok);
    पूर्ण
  वापस 1;
पूर्ण

पूर्णांक
level2c (अक्षर *tok)
अणु
  अगर (म_माप (tok) < 1)
    अणु
      म_जोड़ो (msg, lookup ("^"));
      वापस 1;
    पूर्ण
  चयन (tok[0])
    अणु
    हाल 'u':
      म_जोड़ो (msg, lookup ("_u"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'm':
      म_जोड़ो (msg, lookup ("_m"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'i':
      म_जोड़ो (msg, lookup ("_i"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'e':
      म_जोड़ो (msg, lookup ("_ee"));
      tok += 2;
      level1 (tok);
      अवरोध;
    हाल 'y':
      म_जोड़ो (msg, lookup ("_yna"));
      tok++;
      level2a (++tok);
      अवरोध;
    हाल 't':
      level2b (++tok, "_t");
      अवरोध;
    हाल 'd':
      level2b (++tok, "_d");
      अवरोध;
    हाल 'h':
      अगर (tok[1] == 'h')
	अणु
	  म_जोड़ो (msg, lookup ("_hh"));
	  tok++;
	  level1 (++tok);
	पूर्ण
      अन्यथा
	अणु
	  म_जोड़ो (msg, lookup ("_ha"));
	  level2a (++tok);
	पूर्ण
      अवरोध;
    हाल 'o':
      tok++;
      चयन (tok[0])
	अणु
	हाल 'o':
	  म_जोड़ो (msg, lookup ("_oo"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'a':
	  म_जोड़ो (msg, lookup ("_oa"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'u':
	  म_जोड़ो (msg, lookup ("_ou"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	शेष:
	  म_जोड़ो (msg, c2s (tok[0]));
	  level1 (++tok);
	पूर्ण;
      अवरोध;
    हाल 'n':
      tok++;
      चयन (tok[0])
	अणु
	हाल 'a':
	  म_जोड़ो (msg, lookup ("_na"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'n':
	  म_जोड़ो (msg, lookup ("_nna"));
	  level2a (++tok);
	  अवरोध;
	हाल 'g':
	  म_जोड़ो (msg, lookup ("_nga"));
	  level2a (++tok);
	  अवरोध;
	शेष:
	  म_जोड़ो (msg, c2s (tok[0]));
	  level1 (++tok);
	पूर्ण;
      अवरोध;
    हाल 'r':
      tok++;
      चयन (tok[0])
	अणु
	हाल 'i':/*_ri*/
	  अगर (म_माप (msg) > 0 && msg[म_माप (msg) - 1] == *lookup ("^"))	/*push-pop */
	    अणु
	      msg[म_माप (msg) - 1] = '\0';
	      म_जोड़ो (msg, lookup ("^_ri"));
	    पूर्ण
	  अन्यथा
	    म_जोड़ो (msg, lookup ("_ri"));
	  tok++;
	  level1 (tok);
	  अवरोध;
	हाल 'd':
	  level2b (++tok, "_rd");
	  अवरोध;
	शेष:
	  म_जोड़ो (msg, c2s (tok[0]));
	  level1 (++tok);
	पूर्ण;
      अवरोध;
    हाल 'a':
      tok++;
      अगर (म_माला (lev1, c2s (tok[0])) != शून्य)
	अणु
	  म_जोड़ो (msg, lookup ("_a"));
	  level1 (tok);
	पूर्ण
      अन्यथा
	चयन (tok[0])
	  अणु
	  हाल 'a':
	    म_जोड़ो (msg, lookup ("_aa"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'e':
	    म_जोड़ो (msg, lookup ("_ae"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'i':
	    म_जोड़ो (msg, lookup ("_ai"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'o':
	    म_जोड़ो (msg, lookup ("_ao"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  हाल 'u':
	    म_जोड़ो (msg, lookup ("_au"));
	    tok++;
	    level1 (tok);
	    अवरोध;
	  शेष:
	    म_जोड़ो (msg, c2s (tok[0]));
	    level1 (++tok);
	  पूर्ण;
      अवरोध;
    शेष:
      म_जोड़ो (msg, c2s (tok[0]));
      level1 (++tok);
    पूर्ण
  वापस 1;
पूर्ण

पूर्णांक
level1 (अक्षर *tok)
अणु
  अगर (म_माप (tok) < 1)
    वापस 1;
  चयन (tok[0])
    अणु
    हाल '|':
      म_जोड़ो (msg, lookup ("|"));
      tok++;
      level1 (tok);
      अवरोध;
    हाल 'n':
      म_जोड़ो (msg, lookup ("na"));
      level2a (++tok);
      अवरोध;
    हाल 'm':
      म_जोड़ो (msg, lookup ("ma"));
      level2a (++tok);
      अवरोध;
    हाल 'y':
      म_जोड़ो (msg, lookup ("ya"));
      level2a (++tok);
      अवरोध;
    हाल 'w':
      म_जोड़ो (msg, lookup ("wa"));
      level2a (++tok);
      अवरोध;
    हाल 'x':
      म_जोड़ो (msg, lookup ("xa"));
      level2a (++tok);
      अवरोध;
      /*हाल 'h':
         म_जोड़ो(msg,lookup("ha"));
         level2a(++tok);
         अवरोध; */
    हाल 'r':
      म_जोड़ो (msg, lookup ("ra"));
      level2a (++tok);
      अवरोध;
    हाल 'g':
      level2b (++tok, "g");
      अवरोध;
    हाल 'c':
      tok++;
      level2b (++tok, "ch");
      अवरोध;
    हाल 't':
      level2b (++tok, "t");
      अवरोध;
    हाल 'd':
      level2b (++tok, "d");
      अवरोध;
    हाल 'p':
      level2b (++tok, "p");
      अवरोध;
    हाल 'b':
      level2b (++tok, "b");
      अवरोध;
    हाल 's':
      level2b (++tok, "s");
      अवरोध;
    हाल 'l':
      level2b (++tok, "l");
      अवरोध;
    हाल 'k':
      level2b (++tok, "k");
      अवरोध;
    हाल 'j':
      level2b (++tok, "j");
      अवरोध;
    हाल '_':
      level2c (++tok);
      अवरोध;
    हाल '^':			/*discrete 'matra' */
      matra (++tok);
      अवरोध;
    शेष:
      म_जोड़ो (msg, c2s (tok[0]));
      level1 (++tok);
    पूर्ण;
  वापस 1;
पूर्ण

अक्षर *
rmn2acii (अक्षर *tok)
अणु
  *msg = '\0';
  level1 (tok);
  वापस msg;
पूर्ण
