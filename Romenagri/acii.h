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
	
/* ACII to romenagri conversion table */

/** IMPORTANT change on ^a (matra '^a') --  17-mar-2004*/
/** change unकरोne */
/* however the pathology is that rmn='^a' is matched on empty string*/

#अगर_अघोषित __ACII_H__
#घोषणा __ACII_H__
#घोषणा ACII_LEN 76

#अगर_घोषित __cplusplus
   बाह्य "C" अणु
#पूर्ण_अगर



अटल अक्षर *acii_chrt[ACII_LEN][2]=
अणु
अणु"",    "oB"पूर्ण,           /*control should be at index 0*/
अणु"__",   "_"पूर्ण,            /*expand control underscore*/
अणु"_a",   "अ"पूर्ण,
अणु"^a",    ""पूर्ण,             /*maatra 'a' is invisible in acii*/
अणु"_aa",  "आ"पूर्ण,
अणु"^aa",  "ा"पूर्ण,
अणु"_i",   "इ"पूर्ण,
अणु"^i" ,  "ि"पूर्ण,
अणु"_ee",  "ई"पूर्ण,
अणु"^ee",  "ी"पूर्ण,
अणु"_u",   "उ"पूर्ण,
अणु"^u",   "ु"पूर्ण,
अणु"_oo",  "ऊ"पूर्ण,
अणु"^oo",  "ू"पूर्ण,
अणु"_ri",  "ऋ"पूर्ण,
अणु"^_ri", "ृ"पूर्ण,
अणु"_ae",  "ए"पूर्ण,
अणु"^ae",  "े"पूर्ण,
अणु"_ai",  "ऐ"पूर्ण,
अणु"^ai",  "ै"पूर्ण,
अणु"_oa",  "ओ"पूर्ण,
अणु"^oa",  "ो"पूर्ण,
अणु"_ou",  "औ"पूर्ण,
अणु"^ou",  "ौ"पूर्ण,
अणु"_au",  "ऑ"पूर्ण,
अणु"^au",  "ॉ"पूर्ण,
अणु"_ao",  "ऍ"पूर्ण,
अणु"^ao",  "ॅ"पूर्ण,
अणु"ka",   "क"पूर्ण,
अणु"kha",  "ख"पूर्ण,
अणु"ga",   "ग"पूर्ण,
अणु"gha",  "घ"पूर्ण,
अणु"_nga", "ङ"पूर्ण,
अणु"cha",  "च"पूर्ण,
अणु"chha", "छ"पूर्ण,
अणु"ja",   "ज"पूर्ण,
अणु"jha",  "झ"पूर्ण,
अणु"_yna", "ञ"पूर्ण,
अणु"ta",   "ट"पूर्ण,
अणु"tha",  "ठ"पूर्ण,
अणु"da",   "ड"पूर्ण,
अणु"dha",  "ढ"पूर्ण,
अणु"_nna", "ण"पूर्ण,
अणु"_ta",  "त"पूर्ण,
अणु"_tha", "थ"पूर्ण,
अणु"_da",  "द"पूर्ण,
अणु"_dha", "ध"पूर्ण,
अणु"na",   "न"पूर्ण,
अणु"pa",   "प"पूर्ण,
अणु"pha",  "फ"पूर्ण,
अणु"ba",   "ब"पूर्ण,
अणु"bha",  "भ"पूर्ण,
अणु"ma",   "म"पूर्ण,
अणु"ya",   "य"पूर्ण,
अणु"ra",   "र"पूर्ण,
अणु"la",   "ल"पूर्ण,
अणु"wa",   "व"पूर्ण,
अणु"lvra", "ळ"पूर्ण,
अणु"sha",  "श"पूर्ण,
अणु"xa",   "ष"पूर्ण,
अणु"sa",   "स"पूर्ण,
अणु"_ha",  "ह"पूर्ण,
अणु"_m",   "ं"पूर्ण,    /*only क्रम trailing bindu अन्यथा find warg*/
अणु"_hh",  "ः"पूर्ण,
अणु"_na",  "ँ"पूर्ण,
अणु"^za",  "़"पूर्ण,
अणु"|",    "।"पूर्ण,
अणु"^",    "्"पूर्ण,
अणु"_rda",  "ड़"पूर्ण,
अणु"_rdha", "ढ़"पूर्ण,
अणु"^ra",   "्र"पूर्ण,
अणु"r",     "र्"पूर्ण,
अणु"kxa",  "क्ष"पूर्ण,
अणु"_tra", "त्र"पूर्ण,
अणु"j_yna","ज्ञ"पूर्ण,  /*correct to g_yna*/
अणु"shra", "श्र"पूर्ण
पूर्ण;

#अगर_घोषित __cplusplus
   पूर्ण
#पूर्ण_अगर

#पूर्ण_अगर

