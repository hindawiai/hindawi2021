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

        24-Jan-2006, Removed variable grid - LM is directly looked-up now,
                        Abhishek Choudhary <hi_pedler>,
                        choudhary@indicybers.net

        23-Jan-2006, Moved the font substitution function outside
                     of the rendering loop - a major flaw earlier,
                        Abhishek Choudhary <hi_pedler>,
                        choudhary@indicybers.net

        22-Jan-2006, Annotated code,
                        Abhishek Choudhary <hi_pedler>,
                        choudhary@indicybers.net

        20-Jan-2006, Added the modअगरications section,
                        Abhishek Choudhary <hi_pedler>,
                        choudhary@indicybers.net
End of modअगरications.
*/

/*
Abbreviations:
AP - Anamika Press
APCISR - Anamika Press Code क्रम Indic Script Representation

Origin:
M/S Anamika Press, Katihar are prपूर्णांकers and publishers operating from the
eastern Indian town of Katihar, located in the state of Bihar. It is around
500 km from the cites of Kolkata (Calcutta) and Patna. The APCISR standard
was developed at Anamika Press, initially क्रम impression prपूर्णांकing purposes,
and was later aकरोpted क्रम fixed width console display. The originator of
this standard is Abhishek Choudhary, then an employee of Anamika Press. All
the rights क्रम this work, including copyright, are held by Abhishek Choudhary
and not Anamika Press, or any other inभागidual or entity. This text is
included here क्रम inक्रमmation only.
*/


/*
ISCII to APCISR conversion and support functions.
Filename: acii2csr.c
Original implementation: ANSI C
Implemented by: Abhishek Choudhary
Period of initial implementation: Oct 2003 to May 2004
Dependencies: None
Special: Seperate facility क्रम loading VGA fonts required such
as setfont or fontsel.
*/


/* Include the पूर्णांकerface */
#समावेश "acii2csr.h"


/*
ISCII to APCISR conversion routine.
Input: 0 delimited ISCII string (अचिन्हित अक्षर) and a cursor पूर्णांकo it (पूर्णांक)
Output: Rendered APCISR map. Variable retval of type cisr must be declared
Background: Based on Abhishek Choudhary's 9-grid theory क्रम Brahmi derived
scripts. The algorithm is discussed briefly in the file apcisr.txt, which
also पूर्णांकroduces APCISR.
*/

cisr
acii2cisr (अचिन्हित अक्षर *aci_in, पूर्णांक cpos)
अणु
  /*
     Variable acपंचांगp is used as a temporary copy of input string aci_in, aci
     is a right-sided winकरोw पूर्णांकo acपंचांगp, l_aci holds the length of the original
     ISCII after adjusting initial 'ref', curpos is a cursor पूर्णांकo acपंचांगp
   */
  अचिन्हित अक्षर acपंचांगp[1024], *aci;
  पूर्णांक l_aci = 0, curpos = 0;

  /*
     Variables urdha, madhya and nimna together क्रमm the working map (WM),
     varibles matrik, lipik, purak are cursors पूर्णांकo the WM
   */
  अचिन्हित अक्षर urdha[1024], madhya[1024], nimna[1024];
  पूर्णांक matrik = 0, lipik = 0, purak = 0;

  /*
     Variable flag tells whether apcisr_अक्षरt entry has been found, purna
     gives the purna status, varna_purna tells whether last symbol completed
     a varna including a sanyuktakshara, prev_hal tells whether the last symbol
     encountered was a hal, prev_ra_hal tells whether the last symbol encontered
     was a ra+hal (as a following varna will show it on top), lnfnd tells अगर the
     last symbol was not found, lasttok is the previous index पूर्णांकo apcisr_chrt,
     grid_job tells whether to render the current symbol or look-ahead
   */
  पूर्णांक flag = 0, purna = 2, varna_purna = 1, prev_hal = 0, prev_ra_hal = 0,
    lnfnd = 0, lasttok = 0, grid_job = 1;

  /* House-keeping variable used क्रम loops and indexing पूर्णांकo apcisr_chrt */
  पूर्णांक i = 0;

  /*
     Variable pos is a cursor पूर्णांकo retval, check keeps a count of the numbers
     of cisr columns eliminated during font substituion, fpos holds the value of
     the position where the original ISCII at cpos occurs. Variable fpos should
     be initialised to less than 0 as this condition is used to check whether it
     has been set beक्रमe, owing to the fact that the exact cpos ISCII may be
     consumed non-productively.
   */
  पूर्णांक pos = 0, check = 0, fpos = -1;

  /* End of declarations */

  /* Initialisation */

  /*
     Copy the input string पूर्णांकo the temporary working string and set the
     right-sided winकरोw to begin at initial location.
   */
  म_नकल (acपंचांगp, aci_in);
  aci = acपंचांगp;

  /* Initialise the strings to zeroes */
  क्रम (i = 0; i < 1024; i++)
    अणु
      urdha[i] = madhya[i] = nimna[i] = 0;
      retval.urdha[i] = retval.madhya[i] = retval.nimna[i] = 0;
    पूर्ण

  /* End of initialisation */

  /* Start processing the ISCII input */

  /* Remove first 'ref' अगर it exists -> bad ISCII */
  अगर (म_माला (aci, "्र") == (अक्षर *) aci)
    अणु
      /* Shअगरt winकरोw right and reduce cpos as we are redefing input */
      aci++;
      cpos--;
    पूर्ण

  /* Strore the length of the input string in l_aci */
  l_aci = म_माप (aci);

  /* Process the input string till the winकरोw length is not zero */
  जबतक (म_माप (aci))
    अणु
      /* Look-up next ISCII symbol in apcisr_chrt (speed bottleneck) */

      /* Locate the 9-grid pattern in the APCISR look-up table */
      flag = 0;
      क्रम (i = 0; i < APCISR_LEN; i++)
	अणु
	  /*
	     Method of lookup is to check whether the ISCII अक्षरacter is the
	     lefपंचांगost in the winकरोw
	   */
	  अगर (म_माला (aci, apcisr_chrt[i].acii) == (अक्षर *) aci)
	    अणु
	      flag = 1;
	      अवरोध;
	    पूर्ण
	पूर्ण

      /*
         Variable varna_purna gives purna status of previous ISCII अक्षर.
         A non-zero varna_purna leads to a new matrik; i.e. varna is complete
       */
      अगर (purna)
	अणु
	  varna_purna = purna;
	पूर्ण

      /* Purna value is retrived from apcisr_अक्षरt */
      purna = apcisr_chrt[i].purna;

      /*
         Repeated matra is bad ISCII and hence ignored. Matra over-करो
         prevention needs to be improved
       */
      अगर (i == lasttok && purna == 0)
	अणु
	  flag = 0;
	पूर्ण

      /* Set lasttok equal to the index in apcisr_chrt */
      lasttok = i;

      अगर (flag == 1)
	/* If ISCII symbol found... */
	अणु
	  /* Advance winकरोw to exclude identअगरied token */
	  aci += म_माप (apcisr_chrt[i].acii);

	  /* Advance cursor to correspond to the winकरोw */
	  curpos += म_माप (apcisr_chrt[i].acii);

	  /* Signal that last symbol was found (क्रम next iteration use) */
	  lnfnd = 0;
	पूर्ण
      अन्यथा
	/* If ISCII symbol not found... */
	अणु
	  /* As this is not ISCII a prev_hal is inconsequential */
	  prev_hal = 0;

	  /*
	     If last अक्षरacter was ISCII and this is not the first अक्षरacter
	     then the previous cisr needs to be completed.
	   */
	  अगर (lnfnd == 0 && म_माप (aci) < l_aci)
	    अणु
	      purak++;
	    पूर्ण

	  /* The non-ISCII input अक्षर is placed in urdha[purak] */
	  urdha[purak] = aci[0];

	  /*
	     The madhya[purak] is filled with a special marker to identअगरy
	     a non-ISCII अक्षरacter.
	   */
	  madhya[purak] = 192;

	  /*
	     Since other cisr-advancing rules will not apply here, we need to
	     manually advance the cisr positions. As we करो not know in advance
	     whether the nex अक्षरacter is ISCII or not we have to keep the next
	     cisr collapsed क्रम now. Otherwise the resulting empty matrik would
	     be rendered.
	   */
	  matrik = purak + 1;
	  lipik = purak = matrik;

	  /*
	     Set the next cisr madhya position to represent a non-lipik by
	     setting it equal to 128;i.e. set bit 7 to indicate matrik/purak
	   */
	  madhya[purak] = 128;

	  /* Advance winकरोw to consume the non-ISCII */
	  aci++;
	  curpos++;

	  /*
	     A non-ISCII by definition cannot be a purna as it करोes not
	     generate a new cisr, hence, we set purna equal to 0
	   */
	  purna = 0;

	  /*
	     Now check whether the अक्षरacter at cpos has been consumed. If
	     it has been, then set fpos to previous cisr, where we rendered the
	     non-ISCII अक्षरacter
	   */
	  अगर (curpos >= cpos && fpos < 0)
	    अणु
	      fpos = purak - 1;
	    पूर्ण

	  /*
	     Indicate that the last cisr was completed as the non-ISCII has
	     been rendered to a collapsed cisr
	   */
	  varna_purna = 1;

	  /* Flag that last अक्षरacer was not found; i.e. non-ISCII */
	  lnfnd = 1;
	पूर्ण

      /* End of look-up phase */


      /* Apply the LM - WM combination rules क्रम Devnagri and combine them */

      /*
         These rules are applicable only to ISCII अक्षरacters and not to other
         non-ISCII अक्षरacters or numerals. This is where the WM cursors are
         positioned. Dynamic behaviour is handled by the rules here.
       */
      अगर (lnfnd == 0)
	अणु
	  /* General LM - WM combination rules */

	  अगर (prev_ra_hal == 1)
	    /* If the sequence ra_hal was encountered earlier... */
	    अणु
	      अगर ((purna % 2) == 1)
		/* If the current अक्षरacter has an even purna status... */
		अणु
		  /* ...add 'ref' to urdha-lipik */
		  urdha[lipik] = urdha[lipik] | 128;
		पूर्ण
	      अन्यथा
		/* If the current अक्षरacter has an odd purna status... */
		अणु
		  /* ...add 'ref' to urdha-purak */
		  urdha[purak] = urdha[purak] | 128;
		पूर्ण
	    पूर्ण
	  अन्यथा अगर (purna && prev_hal == 0)
	    /* Under non-'hal' conditions; i.e. the trivial purna method */
	    अणु
	      /* Old purak becomes new matrik */
	      matrik = purak;

	      /* Lipik is next to matrik */
	      lipik = matrik + 1;

	      /* Purak is next to lipik */
	      purak = lipik + 1;

	      /* Set bit 7 on madhya-matrik and madhya-purak to संकेत
	         non-lipik */
	      madhya[matrik] = madhya[matrik] | 128;
	      madhya[purak] = madhya[purak] | 128;
	    पूर्ण
	  अन्यथा अगर (purna && prev_hal == 1)
	    /* If current is purna but after a hal then... */
	    अणु
	      /*
	         Perक्रमm a delayed 'hal' operation; i.e. the half-क्रमm of a
	         consonant is rendered only अगर there is a following ISCII, अन्यथा
	         the previous अक्षरacter is displayed in full क्रमm, but with a
	         'hal' below it.
	       */
	      अगर (varna_purna > 1)
		/* If the last अक्षरacter had a purna of 1 then... */
		अणु
		  अगर (nimna[lipik] >= 64)
		    /* ...अगर the nimna-lipik has bit 6 ('hal')on then... */
		    अणु
		      /* ...turn 'hal'-mark off */
		      nimna[lipik] -= 64;
		    पूर्ण
		  अन्यथा अगर (nimna[purak] >= 64)
		    /* ...अगर the nimna-purak has bit 6 ('hal')on then... */
		    अणु
		      /* ...turn 'hal'-mark off */
		      nimna[purak] -= 64;
		    पूर्ण
		पूर्ण

	      /* Matrik position reमुख्यs unchanged */
	      /* matrik = matrik; *//* nop; no operation */

	      /* Lipik is right shअगरted; i.e. cisr is expanded */
	      lipik++;

	      /* Purak is next to lipik */
	      purak = lipik + 1;

	      /* Bit 7 is turned off on the madhya-lipik to indicate
	         a lipik */
	      madhya[lipik] = 0;

	      /* Bit 7 is set on  madhya-matrik and madhya-purak to indicate
	         a non-lipik */
	      madhya[matrik] = madhya[matrik] | 128;
	      madhya[purak] = madhya[purak] | 128;
	    पूर्ण

	  /*
	     Check to see whether the अक्षरacter at cpos has been consumed. If
	     it has been, then set fpos to current cisr lipik.
	   */
	  अगर (curpos >= cpos && fpos < 0)
	    अणु
	      fpos = lipik;
	    पूर्ण

	  /* Previous hal and ra_hal ('ref' above) have been considered */
	  prev_hal = 0;
	  prev_ra_hal = 0;

	  /*
	     Ensure that LM-WM combination is activated by शेष. However,
	     dynamic rules may modअगरy this.
	   */
	  grid_job = 1;

	  /* The dynamic rules and sequence specअगरic rules appear here */

	  /* Dynamic rule #1 - ^ra */
	  /*
	     Rule: Adding a lower ref to a vyanjan without a purak requires
	     addition of the ref to the nimna-lipik instead of nimna-purak
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "्र") == 0 && varna_purna == 1)
	    अणु
	      /* Add the ref bit to the nimna-lipik */
	      nimna[lipik] = nimna[lipik] | 8;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #2 - ^u */
	  /*
	     Rule: Adding a harshva-u-kar (^u or chota-oo) to a vyanjan
	     without a purak requires addition of the matra to the nimna-lipik
	     instead of nimna-purak
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ु") == 0
	      && (varna_purna % 2) == 1)
	    अणु
	      /* Add the 'chota-oo matra'-bit to the nimna-lipik */
	      nimna[lipik] = nimna[lipik] | 2;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #3 - visargaha */
	  /*
	     Rule: When adding a visargaha to a vyanjan without a purak,
	     which alपढ़ोy has o-kar (^oa), shअगरt the a-kar part of the o-kar
	     from the urdha-purak to urdha-lipik
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ः") == 0 && varna_purna == 1
	      && (madhya[purak] && 4) && (urdha[purak] && 4))
	    अणु
	      /* Shअगरt the a-kar part from the urdha-purak to urdha-lipik */
	      urdha[lipik] = urdha[lipik] | 4;
	      urdha[purak] = urdha[purak] - 4;

	      /* Add visargaha bit to the madhya-purak */
	      madhya[purak] = madhya[purak] | 16;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #4 - chandra bindu */
	  /*
	     Rule: For vyanjans without a purak, the chandra bindu is added
	     to urdha-lipik instead of urdha-purak, unless a matra is present
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ँ") == 0 && varna_purna == 1
	      && madhya[purak] == 160)
	    अणु
	      /* Add chandra bindu to urdha-lipik */
	      urdha[lipik] = urdha[lipik] | 32;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #5 - bindu */
	  /*
	     Rule: For vyanjans without a purak, the bindu is added to
	     urdha-lipik instead of urdha-purak, unless a matra is present
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ं") == 0 && varna_purna == 1
	      && madhya[purak] == 160)
	    अणु
	      /* Add bindu to urdha-lipik */
	      urdha[lipik] = urdha[lipik] | 16;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #6 - ^oo */
	  /*
	     Rule: For vyanjans without a purak, the oo-kar (^oo) is added to
	     nimna-lipik instead of nimna-purak
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ू") == 0
	      && (varna_purna % 2) == 1)
	    अणु
	      /* Add ^oo to nimna-lipik */
	      nimna[lipik] = nimna[lipik] | 1;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #7 - ref */
	  /*
	     Rule: If ra+hal sequence is found then indicate it क्रम
	     the next iteration
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "र्") == 0 && aci[0] > 127)
	    अणु
	      /* Indicate ra + hal sequence found */
	      prev_ra_hal = 1;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #8 - _ha^ */
	  /*
	     Rule: If _ha+hal sequence is found and next अक्षरcter in the
	     winकरोw is ISCII then insert half-_ha glyph पूर्णांकo madhya-lipik
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ह्") == 0 && aci[0] > 127)
	    अणु
	      /* Replace with half - _ha glyph */
	      madhya[lipik] = madhya[lipik] | 45;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #9 - hal */
	  /*
	     Rule: On encountering a nascent hal, it is indicated by setting
	     prev_hal to 1. The hal symbol is added to nimna-lipik क्रम varnas
	     without a khardi-pai and to nimna-purak क्रम others. Conjunction
	     अगर required is perक्रमmed during the next iteration.
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "्") == 0)
	    अणु
	      /* Indicate that hal was encountered */
	      prev_hal = 1;

	      /* Add the hal symbol as per rule */
	      अगर ((varna_purna % 2) == 1)
		अणु
		  nimna[lipik] = nimna[lipik] | 64;
		पूर्ण
	      अन्यथा
		अणु
		  nimna[purak] = nimna[purak] | 64;
		पूर्ण

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* Dynamic rule #10 - ^i */
	  /*
	     Rule: If a harshva-ee-kar (^i or choti-ee) is encountered after
	     matrik and lipik have become seperated owing to conjoपूर्णांक varnas
	     then the upper करोme of the ^i has to be adjusted such that its
	     second half lies in a cell adjacent to urdha-matrik
	   */
	  अगर (म_भेद (apcisr_chrt[i].acii, "ि") == 0 && (matrik != lipik - 1))
	    अणु
	      urdha[matrik] = urdha[matrik] | 1;

	      /* Here matrik and lipik are not contiguous but the second
	         part of the करोme of ^i needs to be in the cell adjacent to
	         urdha-matrik */
	      urdha[matrik + 1] = urdha[matrik + 1] | 2;

	      /* 'Khardi-pai' goes as usual */
	      madhya[matrik] = madhya[matrik] | 8;

	      /* De-activate LM-WM combination क्रम this अक्षरacter */
	      grid_job = 0;
	    पूर्ण

	  /* End of dynamic rules */

	  /* Combine the LM and WM */
	  अगर (grid_job == 1)
	    /* If further LM-WM combination required then... */
	    अणु
	      /* ...combine matriks - logical OR */
	      urdha[matrik] = urdha[matrik] |
		apcisr_chrt[i].grid[_urdha + _matrik];
	      madhya[matrik] = madhya[matrik] |
		apcisr_chrt[i].grid[_madhya + _matrik];
	      nimna[matrik] = nimna[matrik] |
		apcisr_chrt[i].grid[_nimna + _matrik];

	      /* ...combine lipiks - logical OR */
	      urdha[lipik] = urdha[lipik] |
		apcisr_chrt[i].grid[_urdha + _lipik];
	      madhya[lipik] = madhya[lipik] |
		apcisr_chrt[i].grid[_madhya + _lipik];
	      nimna[lipik] = nimna[lipik] |
		apcisr_chrt[i].grid[_nimna + _lipik];

	      /* ...combine puraks - logical OR */
	      urdha[purak] = urdha[purak] |
		apcisr_chrt[i].grid[_urdha + _purak];
	      madhya[purak] = madhya[purak] |
		apcisr_chrt[i].grid[_madhya + _purak];
	      nimna[purak] = nimna[purak] |
		apcisr_chrt[i].grid[_nimna + _purak];
	    पूर्ण
	  /* LM - WM merger completed */
	पूर्ण
    पूर्ण
  /* End of rules application and LM - WM combination phase */

  /* Font substitution on the rendered APCISR */
  check = 0;

  /* Iterate till the final WM purak */
  क्रम (pos = 0; pos <= purak; pos++)
    अणु
      /*
         Visibly empty cisr columns are eliminated to produce more
         consolidated rendition
       */
      अगर ((madhya[pos] == 160 || madhya[pos] == 128) && urdha[pos] == 0
	  && nimna[pos] == 0)
	अणु
	  /* Increment count of eliminated lines */
	  check++;

	  /* Increment retval cursor */
	  pos++;
	पूर्ण

      /* Set curpos at (pos - check) at fpos. Add one as base is 1. */
      अगर (pos == fpos)
	अणु
	  retval.curpos = pos - check + 1;
	पूर्ण

      /*
         Now check क्रम and render non-ISCII अक्षरacters. This is indicated
         by a अक्षरacter value 192 in madhya[pos]. The required अक्षरacter-
         code is in urdha[pos]
       */
      अगर (madhya[pos] == 192)
	अणु
	  retval.urdha[pos - check] = 32;
	  retval.madhya[pos - check] = urdha[pos];
	  retval.nimna[pos - check] = 32;
	  जारी;
	पूर्ण

      /*
         Adjusपंचांगent needed क्रम upper-'raekha' क्रम matra in non-lipik as
         it is redundant when appearing by itself
       */
      अगर ((madhya[pos] > 160) && (madhya[pos] != 192))
	अणु
	  madhya[pos] -= 32;
	पूर्ण

      /*
         Move the top-'ref' to urdha-purak अगर there is a matra in purak,
         अन्यथा let it be above urdha-lipik
       */
      अगर ((pos < purak) && (urdha[pos] >= 128) && (madhya[pos] < 128)
	  && (madhya[pos + 1] != 160) && (madhya[pos + 1] != 129)
	  && (madhya[pos + 1] != 128))
	अणु
	  urdha[pos] -= 128;
	  urdha[pos + 1] += 128;
	पूर्ण

      /*
         Substitute the font-codes with अक्षरset glyph-codes, through
         direct cisr indexing. Nimna codes are repeated after value 128.
       */
      retval.madhya[pos - check] = cisr_madhya[madhya[pos]][1];
      retval.urdha[pos - check] = cisr_urdha[urdha[pos]][1];
      अगर (nimna[pos] <= 128)
	अणु
	  retval.nimna[pos - check] = cisr_nimna[nimna[pos]][1];
	पूर्ण
      अन्यथा
	अणु
	  retval.nimna[pos - check] = cisr_nimna[nimna[pos] - 128][1];
	पूर्ण
    पूर्ण
  /* End of font substitution phase */


  /* Trim the rendered cisr to valid limit */
  retval.urdha[pos - check] = 0;
  retval.madhya[pos - check] = 0;
  retval.nimna[pos - check] = 0;

  अगर (retval.curpos < 1)
    /* Cursor cannot be positioned beक्रमe the first cisr अक्षरacter */
    अणु
      retval.curpos = 1;
    पूर्ण
  अन्यथा अगर (retval.curpos > pos - check)
    /* Cursor cannot be positioned beyond the last cisr अक्षरacter */
    अणु
      retval.curpos = pos - check;
    पूर्ण

  /* End of ISCII to APCISR conversion */

  /* Return the rendered cisr */
  वापस retval;
पूर्ण

/* End of ISCII to APCISR conversion routine */

/* APCISR support functions */

/* Function to 'rtrim' a cisr */

cisr
cisr_trim (cisr dvn)
अणु
  पूर्णांक l = म_माप (dvn.urdha) - 1;
  अगर ((dvn.madhya[l] == '\32') || (dvn.madhya[l] == '\255'))
    अणु
      dvn.urdha[l] = 0;
      dvn.madhya[l] = 0;
      dvn.nimna[l] = 0;
    पूर्ण
  वापस dvn;
पूर्ण

/* Generic function क्रम prपूर्णांकing cisr on console */

पूर्णांक
cisr_म_लिखो_con (cisr dvn)
अणु
  म_लिखो ("%s\n", dvn.urdha);
  म_लिखो ("%s\n", dvn.madhya);
  म_लिखो ("%s", dvn.nimna);
  वापस 0;
पूर्ण

/*
The following functions utilise पट्टपन.स routines जाओxy, cम_लिखो etc. As,
these are not available under standard GNU GCC, we need to check availability.
These functions can be ported to ncurses or similar library. If your प्रणाली
has पट्टपन.स then add a #घोषणा __GOT_CONIO below.
*/

#अगर_घोषित __DJGPP
#घोषणा __GOT_CONIO
#पूर्ण_अगर

#अगर_घोषित __GOT_CONIO

/*
Function to render an apcisr at a location identअगरied by top-left corodinates
specअगरied in screen co-ordinates and not cisr co-ordinates.
*/

पूर्णांक
cisr_म_लिखो (पूर्णांक x, पूर्णांक y, cisr dvn)
अणु
  जाओxy (x, y);
  cम_लिखो ("%s", dvn.urdha);
  जाओxy (x, y + 1);
  cम_लिखो ("%s", dvn.madhya);
  जाओxy (x, y + 2);
  cम_लिखो ("%s", dvn.nimna);
  वापस 0;
पूर्ण

/*
Function as cisr_म_लिखो, but clean apcisr-line क्रम 78 positions. We clean
only till 78 positions since when used क्रम display in box the two extremes
may have a border अक्षरacter which we would not like to wipe out.
*/

पूर्णांक
cisr_म_लिखो_clean (पूर्णांक x, पूर्णांक y, cisr dvn)
अणु
  पूर्णांक i, l;
  l = म_माप (dvn.madhya);
  जाओxy (x, y);
  cम_लिखो ("%s", dvn.urdha);
  क्रम (i = l; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  जाओxy (x, y + 1);
  cम_लिखो ("%s", dvn.madhya);
  क्रम (i = l; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  जाओxy (x, y + 2);
  cम_लिखो ("%s", dvn.nimna);
  क्रम (i = l; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  वापस 0;
पूर्ण

/* Function to clear out a line till 78 positions. */

पूर्णांक
cisr_clean (पूर्णांक x, पूर्णांक y)	/*only clean to 78 */
अणु
  पूर्णांक i;
  जाओxy (x, y);
  क्रम (i = 0; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  जाओxy (x, y + 1);
  क्रम (i = 0; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  जाओxy (x, y + 2);
  क्रम (i = 0; i < 78; i++)
    अणु
      cम_लिखो (" ");
    पूर्ण
  वापस 0;
पूर्ण

/* Function to prपूर्णांक a given string on a cisr-line, repeated 3 बार */

पूर्णांक
c3n_म_लिखो (पूर्णांक x, पूर्णांक y, अक्षर *txt)
अणु
  जाओxy (x, y);
  cम_लिखो ("%s", txt);
  जाओxy (x, y + 1);
  cम_लिखो ("%s", txt);
  जाओxy (x, y + 2);
  cम_लिखो ("%s", txt);
  वापस 0;
पूर्ण

#पूर्ण_अगर
