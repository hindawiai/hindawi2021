<शैली गुरु>
#समावेश <मानकपन.स>
#समावेश <माला.स>
#समावेश <मानकघोष.स>
#समावेश <मानककोष.स>
#समावेश <प्रकार.स>

/* This is a Basic Text Preprocessor पूर्णांकended क्रम preparing BASIC texts  */
/* beक्रमe they are passed to QB2C (Microsoft QuickBasic to C) translator */
/* Last revision: 4.14 27.Oct 1999 */

#घोषणा LMAX 1024
#घोषणा CMAX 175 /* Max number of keywords */

/* Function declarations */
बाह्य अक्षर  *MID_S(अक्षर *, पूर्णांक, पूर्णांक);
बाह्य पूर्णांक    LEN(अक्षर *);
बाह्य पूर्णांक    eof(खाता *);
बाह्य अक्षर  *COMMAND_S(पूर्णांक, अक्षर *argv[]);
बाह्य व्योम lcmds__def(व्योम);

/* Shared variables and arrays declarations */
अटल अक्षर   w__S[16][LMAX];
अटल पूर्णांक    i__w = 0;
अटल द्विगुन x__d[16];
अटल पूर्णांक    i__x = 0;
अटल अक्षर tws__S[LMAX];
अटल अक्षर *cmds_S[] = अणु
"END SUB",  "FUNCTION", "END FUNCTION", "EXIT SUB", "SHARED", "SUB", "DATA",
"CONST", "DECLARE", "DIM", "DYNAMIC", "IF", "THEN", "ELSEIF", "ELSE", "END IF",
"ENDIF", "GOTO",  "GO TO",  "GOSUB",  "RETURN",  "CALL",  "READ",  "RESTORE",
"FOR",   "TO",       "NEXT",   "DO WHILE", "LOOP",   "WHILE",  "WEND",
"DO UNTIL", "EOF", "LOF(", "PRINT", "EPRINT", "LINE INPUT", "INPUT", "STEP",
"OPEN", "INPUT", "SSCAN", "OUTPUT", "USING", "APPEND", "RANDOM", "CLOSE", "AS",
"COMMAND$", "INKEY$", "DATE$",    "TIME$",   "TIMER",  "SHELL",  "REM",
"END",   "STATIC", "LET", "CLS", "COLOR", "LOCATE", "RANDOMIZE", "DEFINT",
"SPACE$","MID$", "LEFT$", "RIGHT$",  "STR$", "CHR$", "HEX$(", "OCT$(", "ASC",
"VAL", "LEN(", "LOG", "SIN", "COS", "TAN", "ATN", "SQR", "ABS", "EXP",
"SGN", "RND", "INT(", "CINT","AND", "OR",  "NOT", "XOR", "MIN", "MAX", "PAUSE",
"SCREEN", "LINE", "PSET", "PALETTE", "SAVEGIF", "LOADGIF", "GIFINFO", "DEFDBL",
"XTEXT", "MARKER", "PMARKER", "PLINE", "XUPDATE", "XCLS", "FAREA", "CIRCLE",
"XWINDOW", "XSELWI", "XCLOSEDS", "XCLOSE", "GCGET", "XPOINTER", "XCURSOR",
"XTITLE", "XREQST", "XCLIP", "XNOCLI", "XWARP", "GET", "PUT", "XANIM",
"XROT", "XSCAL", "XTRAN", "MRESET", "XBUF", "XRMBUF", "DEFSTR", "STRING$",
"GETCOL", "XGETGE", "EXISTS", "LCASE$", "UCASE$", "ENVIRON$", "ENVIRON",
"TXLEN", "SET LCOL", "SET PLCI", "SET LWID", "SET DMOD", "SET PMCI",
"SET PMTS", "SET FASI", "SET FACI", "SET TXCI", "SET TFON", "SET TXAL",
"SET DRMD", "SET BG", "MOD", "SAVEPS", "SAVEPSL", "SAVEEPS", "ERASE", "REDIM",
"SEEK", "INP(", "OUT", "XLEN",
"x" पूर्ण;
अटल अक्षर lcmds_S[CMAX][16];
/* Popular replacements: */
अटल अक्षर *rplc_S[] = अणु"?",         "PRINT",
                         "GO TO",     "GOTO",
                         "ENDIF",     "END IF",
                         "SQRT(",     "SQR(",
"x"पूर्ण;
/* Literal replacements (no afterspace required): */
अटल अक्षर *litr_S[] = अणु"LINE(",     "LINE (",
                         "CIRCLE(",   "CIRCLE (",
                         "PSET(",     "PSET (",
                         "PRINT#",    "PRINT #",
                         "def fn",    "DEF FN",
"x"पूर्ण;
अटल पूर्णांक    imax = 0, jmax = 0, mmax = 0;

/* Open files poपूर्णांकers */
खाता *fp_1, *fp_2;

मुख्य(पूर्णांक n__arg, अक्षर *argv[])
अणु
 अटल पूर्णांक  leng_पूर्णांक, nctok_पूर्णांक, i_पूर्णांक, k_पूर्णांक, j_पूर्णांक, पूर्णांकflg_पूर्णांक, हालflg_पूर्णांक;
 अटल पूर्णांक  lleng_पूर्णांक, i,j,k,n,m,m1, togfl_पूर्णांक, brcnt_पूर्णांक, पंचांगpfl_पूर्णांक, nl_पूर्णांक;
 अटल पूर्णांक  log1, log2, Cflg, c64flg, quietflg, rflag, flag1, flag2;
 अटल अक्षर c_S[LMAX], d_S[LMAX], b_S[LMAX], a_S[LMAX];
 अटल अक्षर inpf_S[LMAX], outf_S[LMAX], पंचांगp_S[LMAX];
 अटल अक्षर c, pc, nc, fc, ct; /* current अक्षर, previouus, next, first */
 अटल अक्षर line_S[LMAX], nline_S[LMAX], w_S[LMAX];
 अटल अक्षर key; /* क्रम specअगरic '-' and '+' handling as unary */

 अटल अक्षर ctok_S[11][LMAX];

 म_नकल(c_S,COMMAND_S(n__arg, argv));
 leng_पूर्णांक = LEN(c_S);
 lcmds__def();
 nctok_पूर्णांक = 0;
 i_पूर्णांक = 1;
 क्रम(k_पूर्णांक = 1; k_पूर्णांक <= 5; k_पूर्णांक++)
 अणु
  जबतक(म_भेद(MID_S(c_S, i_पूर्णांक, 1), " ") == 0 && i_पूर्णांक <= leng_पूर्णांक)
  अणु
   i_पूर्णांक = i_पूर्णांक + 1;
  पूर्ण
  j_पूर्णांक = i_पूर्णांक + 1;
  जबतक(म_भेद(MID_S(c_S, j_पूर्णांक, 1), " ") != 0 && j_पूर्णांक <= leng_पूर्णांक)
  अणु
   j_पूर्णांक = j_पूर्णांक + 1;
  पूर्ण
  म_नकल(ctok_S[k_पूर्णांक],MID_S(c_S, i_पूर्णांक, j_पूर्णांक - i_पूर्णांक));
  अगर(ctok_S[k_पूर्णांक][0]=='\0')
  अणु
   जाओ Lab_50005;
  पूर्ण
  i_पूर्णांक = j_पूर्णांक + 1;
 पूर्ण
Lab_50005:
 nctok_पूर्णांक = k_पूर्णांक - 1;
 j_पूर्णांक = 0;
 Cflg=0;
 c64flg=0;
 quietflg=0;
 rflag=0; /* flag क्रम PP6 */
 क्रम(i_पूर्णांक = 1; i_पूर्णांक <= nctok_पूर्णांक; i_पूर्णांक++)
 अणु
  म_नकल(d_S,ctok_S[i_पूर्णांक]);
  अगर(म_भेद(d_S, "-q") == 0 || म_भेद(d_S, "-Q") == 0)
  अणु
   quietflg = 1;
  पूर्ण
  अन्यथा
  अणु
   अगर(म_भेद(d_S, "-C64") == 0 || म_भेद(d_S, "-c64") == 0)
   अणु
    c64flg = 1;
   पूर्ण
   अन्यथा
   अणु
    अगर(म_भेद(d_S, "-c") == 0 || म_भेद(d_S, "-C") == 0)
    अणु
     Cflg = 1;
    पूर्ण
    अन्यथा
    अणु
     अगर(म_भेद(d_S, "-r") == 0)
     अणु
      rflag = 1;
     पूर्ण
     अन्यथा
     अणु
      अगर(म_भेद(MID_S(d_S, 1, 1), "-") == 0)
      अणु
       म_लिखो("%s%s\n","Unrecognized option  ",d_S);
       निकास(0);
      पूर्ण
      अन्यथा
      अणु
       j_पूर्णांक = j_पूर्णांक + 1;
       म_नकल(ctok_S[j_पूर्णांक],d_S);
      पूर्ण
     पूर्ण
    पूर्ण
   पूर्ण
  पूर्ण
 पूर्ण
 nctok_पूर्णांक = j_पूर्णांक;
 अगर(nctok_पूर्णांक == 0 || nctok_पूर्णांक > 2)
 अणु
  म_लिखो("%s\n","Usage: bcpp [-option [...]] input_file[.bas] [output_file]");
  निकास(0);
 पूर्ण
 अन्यथा
 अणु
  म_नकल(inpf_S,ctok_S[1]);
  अगर(nctok_पूर्णांक >= 1)
  अणु
   i_पूर्णांक = 1;
   म_नकल(b_S,inpf_S);
   जबतक(i_पूर्णांक < LEN(inpf_S))
   अणु
    अगर(म_भेद(MID_S(inpf_S, i_पूर्णांक, 1), ".") == 0)
    अणु
     म_नकल(b_S,MID_S(inpf_S, 1, i_पूर्णांक - 1));
    पूर्ण
    i_पूर्णांक = i_पूर्णांक + 1;
   पूर्ण
   प्र_लिखो(inpf_S,"%s%s",b_S,".bas");
   प्र_लिखो(outf_S,"%s%s",b_S,".bcp");
  पूर्ण
  अगर(nctok_पूर्णांक == 2)
  अणु
   म_नकल(outf_S,ctok_S[2]);
  पूर्ण
 पूर्ण
 प्र_लिखो(पंचांगp_S,"%s%s",b_S,".bcp");
 अगर(quietflg==0) म_लिखो("%s%s%s%s\n","bcpp: preprocessing ",inpf_S,"  -->  ",outf_S);
 /* SHELL "mv " + outf$ + " " + inpf$ */

 अगर((fp_1 = ख_खोलो(inpf_S, "r")) == शून्य)
 अणु
  ख_लिखो(मानक_त्रुटि,"qb2c: cant open file %s\n",inpf_S); निकास(0);
 पूर्ण
 अगर((fp_2 = ख_खोलो(पंचांगp_S, "w")) == शून्य)
 अणु
  ख_लिखो(मानक_त्रुटि,"qb2c: cant open file %s\n",पंचांगp_S); निकास(0);
 पूर्ण
 nl_पूर्णांक=0;
 जबतक(! eof(fp_1))
 अणु
  ख_माला_लो(line_S, LMAX, fp_1);
  line_S[म_माप(line_S) - 1] = 0;
  nl_पूर्णांक++;

  /* PP0: linije komentirane sa 'rem' ili 'REM' ili 'C' */
  c=' '; j=0; म_नकल(nline_S,line_S);
  जबतक(line_S[j] == c) j++;
  अगर(स_भेद(&line_S[j],"rem",3) == 0) अणुस_नकल(&nline_S[j],"REM",3); जाओ Lab_99;पूर्ण
  अगर(स_भेद(&line_S[j],"REM",3) == 0) जाओ Lab_99;
  अगर(Cflg==1 && line_S[0]=='C')
  अणु
   अगर (line_S[1]==' ' || line_S[1]=='\0' || line_S[1]=='\t' || (memcmp(line_S,"CG",2)==0 || memcmp(line_S,"CH",2)==0 || memcmp(line_S,"CM",2)==0) && (line_S[2]==' ' || line_S[2]=='\0' || line_S[2]=='\t')) जाओ Lab_99;
  पूर्ण
  /* PP1: पूर्णांकersticije u binarnim operacijama: + - * / ~ & | @ <> <= >= << >> */
  /* Ne rastavlja -,+ ako je ispred njih slovo e ili E */
  /* Ne rastavlja & ako ispred njega nije space */
  lleng_पूर्णांक = म_माप(line_S);
  togfl_पूर्णांक=0;
  brcnt_पूर्णांक=0;
  key=1;
  j=0;
  pc='\0';
  nc=line_S[0];
  fc='\0'; /* first अक्षरacter in a word */
  क्रम (i=0; i< lleng_पूर्णांक; i++)
  अणु
   c=nc;
   nc=line_S[i+1];
   अगर(c != ' ')
   अणु
    अगर(c == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
    अगर(togfl_पूर्णांक==0)
    अणु
     अगर(c=='=' && pc!='>' && pc!='<' || c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='>' && pc!='<' && nc!='=' && nc!='>' || c=='<' && nc!= '>' && nc!='=' && nc!='<' || c=='~' || c=='&' && pc==' ' || c=='|' || c=='@')
     अणु
      अगर(c=='-' || c=='+')
      अणु
       fc='\0'; k=i;
       अगर (i >= 2) fc=line_S[i-2];
       अगर((pc=='e' || pc=='E') && fc>='0' && fc<='9')
       अणु
        nline_S[j]= c ; j++;
       पूर्ण
       अन्यथा
       अणु
        अगर (key)
        अणु
         nline_S[j]=' '; j++;
         nline_S[j]= c ; j++;
        पूर्ण
        अन्यथा
        अणु
         nline_S[j]=' '; j++;
         nline_S[j]= c ; j++;
         nline_S[j]=' '; j++;
        पूर्ण
       पूर्ण
      पूर्ण
      अन्यथा
      अणु
       nline_S[j]=' '; j++;
       nline_S[j]= c ; j++;
       nline_S[j]=' '; j++;
      पूर्ण
      key=1;
     पूर्ण
     अन्यथा
     अणु
      अगर(c==',' || c==';' || c==':')
      अणु
       nline_S[j]= c ; j++;
       nline_S[j]=' '; j++;
       अगर(c==',') key=1;
      पूर्ण
      अन्यथा
      अणु
       अगर(c=='<' && (nc=='>' || nc=='<' || nc=='='))
       अणु
        nline_S[j]=' '; j++;
        nline_S[j]='<'; j++;
        nline_S[j]= nc; j++;
        nline_S[j]=' '; j++;
        i++; c=nc; nc=line_S[i+1];
        key=1;
       पूर्ण
       अन्यथा
       अणु
        अगर(c=='>' && (nc=='>' || nc=='='))
        अणु
         nline_S[j]=' '; j++;
         nline_S[j]='>'; j++;
         nline_S[j]= nc; j++;
         nline_S[j]=' '; j++;
         i++; c=nc; nc=line_S[i+1];
         key=1;
        पूर्ण
        अन्यथा अणु nline_S[j]= c ; j++; key=0;पूर्ण
       पूर्ण
      पूर्ण
     पूर्ण
     अगर(i>=3)अणु अगर(स_भेद(&line_S[i-3],"STEP",4)==0 || स_भेद(&line_S[i-3],"step",4)==0) key=1; पूर्ण
    पूर्ण
    अन्यथा अणु nline_S[j]= c ; j++; पूर्ण
   पूर्ण
   अन्यथा अणु nline_S[j]= c ; j++; पूर्ण
   pc=line_S[i];
  पूर्ण
  /* PP2: Ukidanje visestrukih spaceova ... (osim lijevih) */
  nline_S[j]='\0';
  lleng_पूर्णांक=j;
  j=0;
  c=' ';
  जबतक(nline_S[j] == c) j++;
  पंचांगpfl_पूर्णांक=0;
  togfl_पूर्णांक=0;
  क्रम(i=j; i<lleng_पूर्णांक; i++)
  अणु
   c=nline_S[i];
   अगर(c == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
   अगर(c == ' ' && togfl_पूर्णांक == 0)
   अणु
    अगर (पंचांगpfl_पूर्णांक==0) अणु nline_S[j]= c ; j++; पंचांगpfl_पूर्णांक=1; पूर्ण
   पूर्ण
   अन्यथा अणु nline_S[j]= c ; j++; पंचांगpfl_पूर्णांक=0; पूर्ण
  पूर्ण
  nline_S[j]='\0';
  /* Ako je bilo vise lijevih spaceova ostao je jedan, obrisi i njega: */
  अगर(nline_S[j-1]==' ') nline_S[--j]='\0';
  म_नकल(w_S,nline_S);

  /* ... i ukidanje nezeljenih spc kod (_ _) _, _: */
  lleng_पूर्णांक=j;
  j=0;
  pc='\0';
  पंचांगpfl_पूर्णांक=0;
  togfl_पूर्णांक=0;
  क्रम(i=0; i<lleng_पूर्णांक; i++)
  अणु
   c=w_S[i];
   ct=c;
   अगर(c == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
   अगर(togfl_पूर्णांक == 0)
   अणु
    अगर((c==')' || c==',' || c==':') && pc==' ') j--;
    अगर(c==' ' && pc=='(') { j--; c='('; पूर्ण
   पूर्ण
   nline_S[j]=c; j++;
   pc=ct;
  पूर्ण
  nline_S[j]='\0';
  lleng_पूर्णांक = j;

  /* PP3: Pretvorba lower हाल kljucnih rijeci u upper हाल */
  अगर (c64flg == 0) अणु /* no C64 */
  क्रम(i=0; i<imax; i++)
  अणु
   n = म_माप(म_नकल(b_S, lcmds_S[i]));
   togfl_पूर्णांक = 0;
   क्रम(j=0; j <= lleng_पूर्णांक - n; j++)
   अणु
    अगर (nline_S[j] == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
    अगर (स_भेद(b_S,&nline_S[j],n) == 0 && togfl_पूर्णांक == 0)
    अणु
     c=0; अगर(j > 0) c=nline_S[j-1];
     log1=(c==' ' || c==0 || c=='(');
     c=0; अगर(j+n < lleng_पूर्णांक) c=nline_S[j+n];
     log2=(c==' ' || c==0 || c=='(' || c==')' || c==':' || c==',' || nline_S[j+n-1]=='(');
     अगर(log1 && log2)
     अणु
      म_नकलन(&nline_S[j],cmds_S[i],n);
      j=j+n-1;
     पूर्ण
    पूर्ण
   पूर्ण
  पूर्ण  पूर्ण
  अन्यथा /* C64 specअगरic */
  अणु
   क्रम(i=0; i<imax; i++)
   अणु
    n = म_माप(म_नकल(b_S, lcmds_S[i]));
    क्रम(j=0; j <= lleng_पूर्णांक - n; j++)
    अणु
     अगर (nline_S[j] == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
     अगर (स_भेद(b_S,&nline_S[j],n) == 0 && togfl_पूर्णांक == 0)
     अणु
      म_नकलन(&nline_S[j],cmds_S[i],n);
      j=j+n-1;
     पूर्ण
    पूर्ण
   पूर्ण
  पूर्ण
  /* PP4: Brojanje zagrada (brackets ballance checking) */
  lleng_पूर्णांक = म_माप(nline_S);
  togfl_पूर्णांक=0;
  brcnt_पूर्णांक=0;
  क्रम(i=0; i<lleng_पूर्णांक; i++)
  अणु
   अगर (स_भेद(&nline_S[i],"REM",3) == 0) जाओ PP5;
   c=nline_S[i];
   अगर(c == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
   अगर(togfl_पूर्णांक==0)
   अणु
    अगर(c == '(') brcnt_पूर्णांक=brcnt_पूर्णांक + 1;
    अगर(c == ')') brcnt_पूर्णांक=brcnt_पूर्णांक - 1;
   पूर्ण
  पूर्ण
  अगर(brcnt_पूर्णांक != 0) अणुख_लिखो(मानक_त्रुटि,"bcpp: Error: brackets not ballanced in line No %d: %s\n",nl_पूर्णांक,w_S); निकास(1);पूर्ण
PP5:
  /* PP5: Popular syntax extensions and literal replacements, caution "?" */
  lleng_पूर्णांक = म_माप(nline_S);
  क्रम(i=0; i<jmax || i<mmax; i=i+2)
  अणु
   flag1=0; अगर(i < jmax) अणुflag1=1; n = म_माप(म_नकल(b_S, rplc_S[i]));पूर्ण
   flag2=0; अगर(i < mmax) अणुflag2=1; m = म_माप(म_नकल(a_S, litr_S[i]));पूर्ण
   togfl_पूर्णांक = 0;
   क्रम(j=0; j <= lleng_पूर्णांक - n; j++)
   अणु
    अगर (nline_S[j] == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;

    अगर (flag2 && स_भेद(&nline_S[j],a_S,m) == 0 && !togfl_पूर्णांक)
    अणु
     m1=म_माप(litr_S[i+1]);
     स_हटाओ(&nline_S[j+m1],&nline_S[j+m],lleng_पूर्णांक-(j+m)+1);
     स_हटाओ(&nline_S[j],litr_S[i+1],m1);
     j=j+m1-1;
     lleng_पूर्णांक=म_माप(nline_S);
     जाओ pp59;
    पूर्ण

    अगर (flag1 && स_भेद(&nline_S[j],b_S,n) == 0 && !togfl_पूर्णांक)
    अणु
     c=0; अगर(j > 0) c=nline_S[j-1];
     log1=!(c>='a' && c<='z' || c>='A' && c<='Z' || c=='_' || c>='0' && c<='9');
     c=0; अगर(j+n < lleng_पूर्णांक-1) c=nline_S[j+n];
     log2=!(c>='a' && c<='z' || c>='A' && c<='Z' || c=='_');
     अगर(log1 && log2)
     अणु
      म_नकल(d_S,nline_S);
      nline_S[j]='\0';
      म_जोड़ो(nline_S,rplc_S[i+1]);
      म_जोड़ो(nline_S,&d_S[j+n]);
      j=j+म_माप(rplc_S[i+1])-1;
      lleng_पूर्णांक=म_माप(nline_S);
     पूर्ण
    पूर्ण

pp59:;
   पूर्ण
  पूर्ण
  /* PP6: Integer fractals -> real fractals ie. 2 / 3 -> 2 / (द्विगुन)3 */
  अगर(rflag) अणु
   i=0; togfl_पूर्णांक=0;
   जबतक((c=nline_S[i]) != '\0') अणु
    अगर(c == 34) togfl_पूर्णांक = 1 - togfl_पूर्णांक;
    अगर(!togfl_पूर्णांक && c=='/') अणु
     स_हटाओ(&nline_S[i+10],&nline_S[i+2],म_माप(nline_S)-i);
     स_नकल(&nline_S[i+2],"(double)",8); i+=8;
    पूर्ण
    i++;
   पूर्ण
  पूर्ण
  Lab_99:
  /* म_लिखो("%s\n",nline_S); */
  ख_लिखो(fp_2,"%s\n",nline_S);
 पूर्ण
 ख_बंद(fp_2);
 ख_बंद(fp_1);

 अगर(nctok_पूर्णांक == 2)
 अणु
  प्र_लिखो(c_S,"mv -f %s %s",पंचांगp_S,outf_S);
  प्रणाली(c_S);
 पूर्ण
पूर्ण /* End of MAIN */


/* Translates of used QB's पूर्णांकrinsic functions: */

बाह्य अक्षर *MID_S(अक्षर *a_S, पूर्णांक start, पूर्णांक length)
अणु

 अगर (i__w++ == 16) i__w=0;
 अगर(length < 0) अणु
  म_लिखो("bcpp: Error: in MID_S: length < 0\n");
  निकास(1); पूर्ण
 अगर(start  < 0) अणु
  म_लिखो("bcpp: Error: in MID_S: start < 1\n");
  निकास(1); पूर्ण
 म_नकलन(w__S[i__w], &a_S[start-1], length);
 w__S[i__w][length]=0;

 वापस w__S[i__w];
पूर्ण

बाह्य पूर्णांक LEN(अक्षर *a_S)
अणु
 अगर (i__x++ == 16) i__x = 0;
 x__d[i__x] = म_माप(a_S);
 वापस x__d[i__x];
पूर्ण

बाह्य पूर्णांक eof(खाता *stream)
अणु
 अटल पूर्णांक c, istat;

 istat=((c=ख_अक्षर_लो(stream))==खातापूर्ण);
 अक्षर_वापस(c,stream);
 वापस istat;
पूर्ण

बाह्य अक्षर *COMMAND_S(पूर्णांक n__arg, अक्षर *argv[])
अणु
 पूर्णांक i;

 अगर (i__w++ == 16) i__w=0;
 क्रम(i = 1; i < n__arg; i++)
 अणु
  म_जोड़ो(w__S[i__w],argv[i]);
  म_जोड़ो(w__S[i__w]," ");
 पूर्ण
 w__S[i__w][म_माप(w__S[i__w])-1]=0;
 वापस w__S[i__w];
पूर्ण

बाह्य व्योम lcmds__def(व्योम)
अणु
 अटल पूर्णांक i=0, j;
 अटल अक्षर w_S[16];

 जबतक(म_भेद(म_नकल(w_S,cmds_S[i]),"x") != 0)
 अणु
  अगर (i >= CMAX)
  अणु ख_लिखो(मानक_त्रुटि, "bcpp: Too many commands. Enlarge CMAX.\n"); निकास(-1); पूर्ण
  क्रम(j = 0; j < म_माप(w_S); j++)
  अणु
   lcmds_S[i][j]=छोटे(w_S[j]);
  पूर्ण
  i++;
 पूर्ण
 imax=i;
 जबतक(म_भेद(rplc_S[jmax],"x") != 0)
 jmax++;
 i=0; जबतक(म_भेद(litr_S[i++],"x") != 0) mmax++;
पूर्ण
