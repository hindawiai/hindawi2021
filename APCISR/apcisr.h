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

/* ISCII to APCISR mapping table */

#अगर_अघोषित __APCISR_H__
#घोषणा __APCISR_H__
#घोषणा APCISR_LEN 82


#अगर_घोषित __cplusplus
बाह्य "C"
अणु
#पूर्ण_अगर


  अटल पूर्णांक _urdha = 0;
  अटल पूर्णांक _madhya = 3;
  अटल पूर्णांक _nimna = 6;

  अटल पूर्णांक _matrik = 0;
  अटल पूर्णांक _lipik = 1;
  अटल पूर्णांक _purak = 2;

  प्रकार काष्ठा
  अणु
    अक्षर urdha[1024];		/*originaly 1024 each of the three */
    अक्षर madhya[1024];
    अक्षर nimna[1024];
    पूर्णांक curpos;
  पूर्ण cisr;

  प्रकार काष्ठा
  अणु
    अक्षर *rmn;
    अक्षर *acii;
    पूर्णांक purna;
    पूर्णांक grid[9];
  पूर्ण grid9;

  अटल grid9 apcisr_chrt[APCISR_LEN] = अणु

    अणु"_hra", "ह्र", 1, अणु0, 0, 0,
			0, 103, 32,
			0, 0, 0पूर्णपूर्ण,

    अणु"kxa", "क्ष", 2, अणु0, 0, 0,
		       0, 40, 2,
		       0, 0, 0पूर्णपूर्ण,

    अणु"_tra", "त्र", 2, अणु0, 0, 0,
			0, 41, 2,
			0, 0, 0पूर्णपूर्ण,

    अणु"j_yna", "ज्ञ", 2, अणु0, 0, 0,
			 0, 42, 2,
			 0, 0, 0पूर्णपूर्ण,

    अणु"_dya", "द्य", 2, अणु0, 0, 0,
			0, 43, 2,
			0, 0, 0पूर्णपूर्ण,

    अणु"_t_ta", "त्त", 2, अणु0, 0, 0,
			 0, 51, 2,
			 0, 0, 0पूर्णपूर्ण,

    अणु"k_ta", "क्त", 2, अणु0, 0, 0,
			0, 48, 1,
			0, 0, 0पूर्णपूर्ण,

    अणु"shra", "श्र", 2, अणु0, 0, 0,
			0, 44, 2,
			0, 0, 0पूर्णपूर्ण,

    अणु"_ee_m", "ईं", 1, अणु0, 1, 16,
			0, 2, 32,
			0, 0, 0पूर्णपूर्ण,

    अणु"_h_ri", "हृ", 1, अणु0, 0, 0,
			0, 104, 32,
			0, 0, 0पूर्णपूर्ण,

    अणु"_rda", "ड़", 1, अणु0, 0, 0,
		       0, 19, 32,
		       0, 32, 0पूर्णपूर्ण,

    अणु"_rdha", "ढ़", 1, अणु0, 0, 0,
			0, 20, 32,
			0, 32, 0पूर्णपूर्ण,

    अणु"ru", "रु", 1, अणु0, 0, 0,
		     0, 46, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"roo", "रू", 1, अणु0, 0, 0,
		      0, 47, 32,
		      0, 0, 0पूर्णपूर्ण,

    अणु"r", "र्", 1, अणु0, 0, 0,
		    0, 33, 32,
		    0, 64, 0पूर्णपूर्ण,

    अणु"^ra", "्र", 0, अणु0, 0, 0,
		      0, 64, 0,
		      0, 0, 0पूर्णपूर्ण,

    अणु"_h", "ह्", 1, अणु0, 0, 0,
		     0, 39, 32,
		     0, 64, 0पूर्णपूर्ण,

    अणु"_a", "अ", 2, अणु0, 0, 0,
		    0, 1, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"_aa", "आ", 2, अणु0, 0, 0,
		     0, 1, 6,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^aa", "ा", 0, अणु0, 0, 0,
		     0, 0, 4,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_i", "इ", 1, अणु0, 0, 0,
		    0, 2, 32,
		    0, 0, 0पूर्णपूर्ण,

    अणु"^i", "ि", 0, अणु1, 2, 0,
		    8, 0, 0,
		    0, 0, 0पूर्णपूर्ण,

    अणु"_ee", "ई", 1, अणु0, 1, 0,
		     0, 2, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^ee", "ी", 0, अणु0, 1, 2,
		     0, 0, 4,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_u", "उ", 1, अणु0, 0, 0,
		    0, 3, 32,
		    0, 0, 0पूर्णपूर्ण,

    अणु"^u", "ु", 0, अणु0, 0, 0,
		    0, 0, 0,
		    0, 0, 2पूर्णपूर्ण,

    अणु"_oo", "ऊ", 2, अणु0, 0, 0,
		     0, 4, 1,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^oo", "ू", 0, अणु0, 0, 0,
		     0, 0, 0,
		     0, 0, 1पूर्णपूर्ण,

    अणु"_ri", "ऋ", 1, अणु0, 0, 0,
		     0, 6, 32,
		     0, 16, 0पूर्णपूर्ण,

    अणु"^_ri", "ृ", 0, अणु0, 0, 0,
		      0, 0, 0,
		      0, 16, 0पूर्णपूर्ण,

    अणु"_ae", "ए", 1, अणु0, 0, 0,
		     0, 5, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^ae", "े", 0, अणु0, 4, 0,
		     0, 0, 0,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_ai", "ऐ", 1, अणु0, 4, 0,
		     0, 5, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^ai", "ै", 0, अणु0, 8, 0,
		     0, 0, 0,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_oa", "ओ", 2, अणु0, 0, 4,
		     0, 1, 6,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^oa", "ो", 0, अणु0, 0, 4,
		     0, 0, 4,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_ou", "औ", 2, अणु0, 0, 8,
		     0, 1, 6,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^ou", "ौ", 0, अणु0, 0, 8,
		     0, 0, 4,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_au", "ऑ", 2, अणु0, 0, 64,
		     0, 1, 6,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^au", "ॉ", 0, अणु0, 0, 64,
		     0, 0, 4,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_ao", "ऍ", 1, अणु0, 64, 0,
		     0, 5, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^ao", "ॅ", 0, अणु0, 64, 0,
		     0, 0, 0,
		     0, 0, 0पूर्णपूर्ण,

    अणु"ka", "क", 3, अणु0, 0, 0,
		    0, 7, 1,
		    0, 0, 0पूर्णपूर्ण,

    अणु"kha", "ख", 2, अणु0, 0, 0,
		     0, 8, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"ga", "ग", 2, अणु0, 0, 0,
		    0, 9, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"gha", "घ", 2, अणु0, 0, 0,
		     0, 10, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_nga", "ङ", 1, अणु0, 0, 0,
		      0, 11, 32,
		      0, 0, 0पूर्णपूर्ण,

    अणु"cha", "च", 2, अणु0, 0, 0,
		     0, 12, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"chha", "छ", 1, अणु0, 0, 0,
		      0, 13, 32,
		      0, 0, 0पूर्णपूर्ण,

    अणु"ja", "ज", 2, अणु0, 0, 0,
		    0, 14, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"jha", "झ", 2, अणु0, 0, 0,
		     0, 15, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_yna", "ञ", 2, अणु0, 0, 0,
		      0, 16, 2,
		      0, 0, 0पूर्णपूर्ण,

    अणु"ta", "ट", 1, अणु0, 0, 0,
		    0, 17, 32,
		    0, 0, 0पूर्णपूर्ण,

    अणु"tha", "ठ", 1, अणु0, 0, 0,
		     0, 18, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"da", "ड", 1, अणु0, 0, 0,
		    0, 19, 32,
		    0, 0, 0पूर्णपूर्ण,

    अणु"dha", "ढ", 1, अणु0, 0, 0,
		     0, 20, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_nna", "ण", 2, अणु0, 0, 0,
		      0, 21, 2,
		      0, 0, 0पूर्णपूर्ण,

    अणु"_ta", "त", 2, अणु0, 0, 0,
		     0, 22, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_tha", "थ", 2, अणु0, 0, 0,
		      0, 23, 2,
		      0, 0, 0पूर्णपूर्ण,

    अणु"_da", "द", 1, अणु0, 0, 0,
		     0, 24, 32,
		     0, 128, 0पूर्णपूर्ण,

    अणु"_dha", "ध", 2, अणु0, 0, 0,
		      0, 25, 2,
		      0, 0, 0पूर्णपूर्ण,

    अणु"na", "न", 2, अणु0, 0, 0,
		    0, 26, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"pa", "प", 2, अणु0, 0, 0,
		    0, 27, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"pha", "फ", 3, अणु0, 0, 0,
		     0, 28, 1,
		     0, 0, 0पूर्णपूर्ण,

    अणु"ba", "ब", 2, अणु0, 0, 0,
		    0, 29, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"bha", "भ", 2, अणु0, 0, 0,
		     0, 30, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"ma", "म", 2, अणु0, 0, 0,
		    0, 31, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"ya", "य", 2, अणु0, 0, 0,
		    0, 32, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"ra", "र", 1, अणु0, 0, 0,
		    0, 33, 32,
		    0, 0, 0पूर्णपूर्ण,

    अणु"la", "ल", 2, अणु0, 0, 0,
		    0, 34, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"wa", "व", 2, अणु0, 0, 0,
		    0, 35, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"lvra", "ळ", 1, अणु0, 0, 0,
		      0, 105, 32,
		      0, 0, 0पूर्णपूर्ण,

    अणु"sha", "श", 2, अणु0, 0, 0,
		     0, 36, 2,
		     0, 0, 0पूर्णपूर्ण,

    अणु"xa", "ष", 2, अणु0, 0, 0,
		    0, 37, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"sa", "स", 2, अणु0, 0, 0,
		    0, 38, 2,
		    0, 0, 0पूर्णपूर्ण,

    अणु"_ha", "ह", 1, अणु0, 0, 0,
		     0, 39, 32,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_m", "ं", 0, अणु0, 0, 16,
		    0, 0, 0,
		    0, 0, 0पूर्णपूर्ण,

    अणु"_hh", "ः", 0, अणु0, 0, 0,
		     0, 0, 16,
		     0, 0, 0पूर्णपूर्ण,

    अणु"_na", "ँ", 0, अणु0, 0, 32,
		     0, 0, 0,
		     0, 0, 0पूर्णपूर्ण,

    अणु"^za", "़", 0, अणु0, 0, 0,
		     0, 0, 0,
		     0, 32, 0पूर्णपूर्ण,

    अणु"|", "।", 1, अणु0, 0, 0,
		   0, 50, 0,
		   0, 0, 0पूर्णपूर्ण,

    अणु"^", "्", 0, अणु0, 0, 0,
		   0, 0, 0,
		   0, 0, 64पूर्णपूर्ण
  पूर्ण;
#अगर_घोषित __cplusplus
पूर्ण
#पूर्ण_अगर

#पूर्ण_अगर
