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

#समावेश "stack.h"
अक्षर stack2[10240], popper2[10240];
अक्षर *stack = stack2, *popper = popper2;
पूर्णांक ts = 0;

पूर्णांक
push (अक्षर *data)
अणु
  अगर ((ts + म_माप (data)) > 10240)
    वापस 0;
  म_जोड़ो (stack, data);
  ts += म_माप (data);
  वापस 1;
पूर्ण

अक्षर *
pop (पूर्णांक n)
अणु
  अगर ((ts - n) < 0)
    वापस शून्य;
  म_नकल (popper, (अक्षर *) (stack + ts - n));
  ts -= n;
  stack[ts] = '\0';
  वापस popper;
पूर्ण

पूर्णांक
stack_reset ()
अणु
  ts = 0;
  वापस 1;
पूर्ण

पूर्णांक
stack_len ()
अणु
  वापस ts;
पूर्ण
