<शैली गुरु>
#समावेश <मानकपन.स>
#समावेश <माला.स>
#समावेश <मानकघोष.स>
#समावेश <मानककोष.स>
#समावेश <प्रकार.स>

/* This file was generated by QuasiBASIC to C translator */
/* qb2c  ver.3.41 Free Version 04 May 2000
Check out the Pay version at http://अक्रमom.com.hr/products/                            */

#घोषणा LMAX 1025 /* Max strig length */

/* Function declarations */
बाह्य अक्षर  *MID_S(अक्षर *, पूर्णांक, पूर्णांक);
बाह्य अक्षर  *LEFT_S(अक्षर *, पूर्णांक);
बाह्य अक्षर  *UCASE_S(अक्षर *);
बाह्य अक्षर  *STR_S(द्विगुन);
बाह्य पूर्णांक    LEN(अक्षर *);
बाह्य पूर्णांक    eof(खाता *);
बाह्य अक्षर  *COMMAND_S(पूर्णांक, अक्षर *argv_S[]);
बाह्य द्विगुन DBL(द्विगुन);

/* Shared variables and arrays declarations */
अटल अक्षर   w__S[16][LMAX];
अटल पूर्णांक    j__S = 0, j__Sपंचांगp;
अटल द्विगुन w__d[16];
अटल पूर्णांक    i__d = 0, i__dपंचांगp;
अटल अक्षर tws__S[LMAX];

/* Open files poपूर्णांकers */
खाता *fp_1;
अक्षर fn1__S[160];

मुख्य(पूर्णांक n_arg_पूर्णांक, अक्षर *argv_S[])
अणु
 अटल पूर्णांक  nl_पूर्णांक, leng_पूर्णांक;
 अटल अक्षर c_S[LMAX], line_S[LMAX], helpf_S[LMAX], key_S[LMAX];

 n_arg_पूर्णांक--;
 /* bhelp क्रम QB2C versions 3.2k and later - by Mario Stipcevic */
 /* This is a QB2C code. Compile it with: bcc */
 म_नकल(c_S,COMMAND_S(n_arg_पूर्णांक, argv_S));
 म_नकल(line_S,"");
 nl_पूर्णांक = 0;
 /* local_path$ = */
 /* src_path$ = */
 /* अगर exists() */
 म_नकल(helpf_S,"manual.txt");
 अगर(म_भेद(c_S, "") != 0)
 अणु
  अगर((fp_1 = ख_खोलो(म_नकल(fn1__S,helpf_S), "r")) == शून्य)
  अणु
   ख_लिखो(मानक_त्रुटि,"Can't open file %s\n",fn1__S); निकास(1);
  पूर्ण
  प्र_लिखो(key_S,"%s%s","o ",UCASE_S(c_S));
  leng_पूर्णांक = LEN(key_S);
  जबतक((म_भेद(LEFT_S(line_S, 20), "+ Reference Manual +") != 0) && ! eof(fp_1))
  अणु
   ख_माला_लो(line_S, LMAX, fp_1);
   line_S[म_माप(line_S) - 1] = '\0';
   nl_पूर्णांक = nl_पूर्णांक + 1;
  पूर्ण
  जबतक((म_भेद(LEFT_S(line_S, leng_पूर्णांक), key_S) != 0) && ! eof(fp_1))
  अणु
   ख_माला_लो(line_S, LMAX, fp_1);
   line_S[म_माप(line_S) - 1] = '\0';
   nl_पूर्णांक = nl_पूर्णांक + 1;
  पूर्ण
  ख_बंद(fp_1);
  प्र_लिखो(tws__S,"%s%s%s%s","vi +",MID_S(STR_S(nl_पूर्णांक), 2, LMAX)," ",helpf_S);
  प्रणाली(tws__S);
 पूर्ण
 अन्यथा
 अणु
  प्र_लिखो(tws__S,"%s%s","vi ",helpf_S);
  प्रणाली(tws__S);
 पूर्ण
 निकास(0);
पूर्ण /* End of MAIN */

/* Translates of used QB's पूर्णांकrinsic functions: */

बाह्य अक्षर *MID_S(अक्षर *a_S, पूर्णांक start, पूर्णांक length)
अणु

 अगर (++j__S == 16) j__S=0;
 अगर(length < 0) अणु
  म_लिखो("Error: in MID_S: length < 0\n");
  निकास(0); पूर्ण
 अगर(start  < 0) अणु
  म_लिखो("Error: in MID_S: start < 1\n");
  निकास(0); पूर्ण
 अगर(start > म_माप(a_S))
 अणु w__S[j__S][0]='\0'; पूर्ण
 अन्यथा
 अणु म_नकलन(w__S[j__S], &a_S[start-1], length);
   w__S[j__S][length]='\0'; पूर्ण

 वापस w__S[j__S];
पूर्ण

बाह्य अक्षर *LEFT_S(अक्षर *a_S, पूर्णांक length)
अणु

 अगर (++j__S == 16) j__S=0;
 अगर(length < 0) अणु
  म_लिखो("Error: in LEFT_S: length < 0\n");
  निकास(0); पूर्ण
 म_नकलन(w__S[j__S], a_S, length);
 w__S[j__S][length]='\0';

 वापस w__S[j__S];
पूर्ण

बाह्य अक्षर *STR_S(द्विगुन d)
अणु

 अगर (++j__S == 16) j__S=0;
 प्र_लिखो(w__S[j__S],"% G",d);
 वापस w__S[j__S];
पूर्ण

बाह्य पूर्णांक LEN(अक्षर *a_S)
अणु
 अगर (++i__d == 16) i__d = 0;
 w__d[i__d] = म_माप(a_S);
 वापस w__d[i__d];
पूर्ण

बाह्य पूर्णांक eof(खाता *stream)
अणु
 अटल पूर्णांक c, istat;

 istat=((c=ख_अक्षर_लो(stream))==खातापूर्ण);
 अक्षर_वापस(c,stream);
 वापस istat;
पूर्ण

बाह्य अक्षर *COMMAND_S(पूर्णांक n_arg_पूर्णांक, अक्षर *argv_S[])
अणु
 पूर्णांक i;

 अगर (++j__S == 16) j__S=0;
 क्रम(i = 1; i <= n_arg_पूर्णांक; i++)
 अणु
  म_जोड़ो(w__S[j__S],argv_S[i]);
  म_जोड़ो(w__S[j__S]," ");
 पूर्ण
 w__S[j__S][म_माप(w__S[j__S])-1]='\0';
 वापस w__S[j__S];
पूर्ण

बाह्य द्विगुन DBL(द्विगुन d)
अणु
 अगर (++i__d == 16) i__d = 0;
 w__d[i__d] = d;
 वापस w__d[i__d];
पूर्ण

बाह्य अक्षर *UCASE_S(अक्षर *text_S)
अणु
 पूर्णांक i=0; अक्षर c;
 अगर (++j__S == 16) j__S=0;
 जबतक((c=text_S[i]) != '\0') अणु
  w__S[j__S][i++] = बड़े(c);
 पूर्ण
 w__S[j__S][i] = '\0';
 वापस w__S[j__S];
पूर्ण
