/**
 * Implementation of the
 * $(LINK2 http://www.digitalmars.com/download/freecompiler.html, Digital Mars C/C++ Compiler).
 *
 * Copyright:   Copyright (c) 1983-1998 by Symantec, All Rights Reserved
 *              Copyright (c) 2000-2017 by Digital Mars, All Rights Reserved
 * Authors:     $(LINK2 http://www.digitalmars.com, Walter Bright)
 * License:     Distributed under the Boost Software License, Version 1.0.
 *              http://www.boost.org/LICENSE_1_0.txt
 * Source:      https://github.com/DigitalMars/Compiler/blob/master/dm/src/dmc/msgsx.c
 */

// Generate msgs2.d, msgs2.h and msgs2.c
// This file pulls together all the various message files into one, which
// when compiled and run, generates the tables used by the compiler.
// Currently it puts all languages into one table, but it can be changed
// to generate binary files for different files loaded at runtime.

// Compile with -DSPP (preprocessor), -DSCPP (C/C++ compiler), -DHTOD (.h to .d converter)

#define TX86            1

struct Msgtable
{
        const char *name;       // handle for compiler
        const char *msg;        // default english message

        // Foreign language translations
        // NULL translations will be done in english
        const char *german;     // optional german message
        const char *french;     // optional french message
        const char *japanese;   // optional japanese message
};

struct Msgtable msgtable[] =
{
  { "usage",
#if SPP
"Use:\n\
        SPP sourcefile [-ooutput] { switches }\n\
-A  strict ANSI                         -D[macro[=text]] define macro\n\
-EC leave comments in                   -EL omit #line directives\n\
-Ipath  #include search path            -j[0|1|2] Asian language characters\n\
-J  chars default to unsigned\n\
-m  memory model\n\
-o  output file name (.i)\n\
-u  suppress predefined macros          -v  verbose compile\n\
-w[n]  suppress warning n               -x  turn off error maximum",

"Syntax:\n\
        SPP quelldatei [-oausgabe] { schalter }\n\
-A  Strikt nach ANSI                    -D[macro[=text]] Makro definieren\n\
-EC Kommentare beibehalten              -EL #line-Anweisungen ｜ergehen\n\
-Ipfad  Suchpfad f〉 #include           -j[0|1|2] Asiatische Zeichensдze\n\
-J  Zeichen standardm�疂g 'unsigned'\n\
-m  Speichermodell\n\
-o  Name der Ausgabedatei (.i)\n\
-u  Vordefinierte Makros unterdr…ken   -v  Ausf”rliche Meldungen\n\
-w[n]  Warnung n unterdr…ken           -x  Fehlermaximum abschalten",

"Usage:\n\
        fichier source SPP [-osortie] { commutateurs }\n\
-A  ANSI pur\n\
-D[macro[=texte]] dＧinition d'une macro\n\
-EC conserver les commentaires\n\
-EL omettre directives #line \n\
-Ichemin  #include chemin de recherche\n\
-j[0|1|2] alphabets asiatiques \n\
-J  caract較es non signＴ par dＧaut \n\
-m  mod獲e de mＮoire\n\
-o  nom du fichier de sortie (.i)\n\
-u  suppression macros prＥＧinies\n\
-v  compilation compl閣e\n\
-w[n]  suppression des avertissements n\n\
-x  dＴactivation erreurs",

#pragma dbcs(push,1)
"形式:\n\
        SPP 入力 [-o出力] {-D[マクロ[=値]]}\n\
            [-m(smclv)] {-(AjJuvwx)} {-Iパス}\n\
入力    ソースファイル名\n\
-A  厳密ANSI (拡張キーワードなし)       -D  マクロ定義\n\
-I  #include検索パス                    -j  2バイト文字\n\
-J  符号なしのchar\n\
-ms  コード、データ両方スモール         -mm  コード=ラージ、データ=スモール\n\
-mc  コード=スモール、データ=ラージ     -ml  コード、データ両方ラージ\n\
-mv  vcmモデル\n\
-o  出力ファイル名(.i)\n\
-u  既定義マクロを定義しない            -v  詳細情報出力\n\
-w[n]  警告nを発行しない                -x  最大エラー数を無効にする",
#pragma dbcs(pop)
#else
        "C/C++ Compiler",                                               // 0
        0,
        "Compilateur C/C++",                                    // 0
#endif
  },
  { "bad_parameter",
        "unrecognized parameter '%s'",                  /*  1 C */
        "Unbekannter Parameter '%s'",                   /*  1 C */
        "param閣re '%s' non reconnu",                   /*  1 C */
        #pragma dbcs(push,1)
        "不正パラメータ '%s'",                          /*  1 C */
        #pragma dbcs(pop)
  },
  { "eof",
        "premature end of source file",                 /*  2   */
        "Vorzeitiges Ende der Quelldatei",              /*  2   */
        "fin inattendue du fichier source",             /*  2   */
        //#pragma dbcs(push,1)
        //"ソースファイルの終りに達した",                 /*  2   */
        //#pragma dbcs(pop)
        "\x83\x5c\x81\x5b\x83\x58\x83\x74\x83\x40\x83\x43\x83\x8b\x82\xcc\x8f\x49\x82\xe8\x82\xc9\x92\x42\x82\xb5\x82\xbd",

  },
  { "num2big",
        "number %s is too large",                       /*  3   */
        "Zahl %s ist zu gro�",                          /*  3   */
        "nombre %s trop Ｍev�",                         /*  3   */
        #pragma dbcs(push,1)
        "数値 %s が大きすぎる",                         /*  3   */
        #pragma dbcs(pop)
  },
  { "string2big",
        "max of %u characters in string exceeded",              /*  4   */
        "Max. Anz. von %u Zeichen im String ｜erschritten",     /*  4   */
        "la longueur de la cha系e dＱasse %u caract較es",       /*  4   */
        "文字列の文字数が多すぎる",                             /*  4   */
  },
  { "ident2big",
        "identifier is longer than 254 chars",          /*  5   */
        "Bezeichner l�nger als 254 Zeichen",            /*  5   */
        "la longueur de l'identificateur dＱasse 254 caract較es", /*  5 */
        "識別子の文字数が 254 以上",                    /*  5   */
  },
        // Could be caused by extra U or L integer suffixes
  { "badtoken",
        "unrecognized token",                           /*  6 L */
        "Unbekanntes Token",                            /*  6 L */
        "tＮoin non reconnu",                           /*  6 L */
        "不正なトークン",                               /*  6 L */
  },
  { "hexdigit",
        "'%c' is not a hex digit",                      /*  8   */
        "Hex-Ziffer erwartet",                          /*  8   */
        "chiffre hexadＤimal requis",                   /*  8   */
        "16進の数字でなければならない",                 /*  8   */
  },
  // Disallowed universal character name per C99 6.4.3 or C++98 2.2.
  // Also, under Win32, values larger than 0xFFFF are not representable.
  { "disallowed_char_name",
        "disallowed universal character name \\\\U%08X",
  },
  { "not_universal_idchar",
        "\\\\U%08X is not a universal identifier character",
  },

        /* For integers, this means that the value exceeded ULONG_MAX.
           For real numbers, this means that the value overflowed
           or underflowed, in other words, it cannot be represented.
           For enums, this means it exceeds INT_MAX.
           For octal character constants, this means it cannot be
           represented in 8 bits.
         */
  { "badnumber",
        "number is not representable",                  /*  9   */
        "Zahl nicht darstellbar",                       /*  9   */
        "impossible de reprＴenter ce nombre",          /*  9   */
        //#pragma dbcs(push,1)
        //"数値を表現できない",                           /*  9   */
        //#pragma dbcs(pop)
        "\x90\x94\x92\x6c\x82\xf0\x95\x5c\x8c\xbb\x82\xc5\x82\xab\x82\xc8\x82\xa2",
  },
  { "exponent",
        "exponent expected",                            /* 10   */
        "Exponent erwartet",                            /* 10   */
        "exposant requis",                              /* 10   */
        "指数でなければならない",                       /* 10   */
  },
  { "nosource",
        "no input file specified",                      /* 11 C */
        "Keine Eingabedatei angegeben",                 /* 11 C */
        "fichier d'entrＦ non spＤifi�",                /* 11 C */
        "入力ファイルの指定がない",                     /* 11 C */
  },
  { "dashD",
        "bad -D switch, %s",                            /* 13 C */
        "Ung〕tiger Schalter f〉 -D, %s",               /* 13 C */
        "commutateur -D %s incorrect",                  /* 13 C */
        "不正 -D スイッチ: %s",                         /* 13 C */
  },
  { "error",
        "Error: ",                                      /* 14   */
        "Fehler: ",                                     /* 14   */
        "Erreur : ",                                    /* 14   */
        "エラー: ",                                     /* 14   */
  },
  { "unknown_pragma",
        "unrecognized pragma",                          /* 16   */
        "Unbekanntes Pragma",                           /* 16   */
        "pragma non reconnu",                           /* 16   */
        "不正プラグマ",                                 /* 16   */
  },
  { "bad_char",
        "illegal character, ascii %u decimal",          /* 17   */
        "Unzulгsiges Zeichen, ASCII %u dezimal",       /* 17   */
        "caract較e non autoris�, ascii %u en dＤimal",  /* 17   */
        "不正文字: ascii %u (10進)",                    /* 17   */
  },
  { "rpar",
        "')' expected",                                 /* 18   */
        "')' erwartet",                                 /* 18   */
        "')' requis",                                   /* 18   */
        "')' でなければならない",                       /* 18   */
  },
  { "param_rpar",
        "')' expected to close function parameter list with",
        "')' erwartet",
        "')' requis",
        "')' でなければならない",
  },
  { "arg_ellipsis",
        "macro argument list arg... form is obsolete",
  },
  { "ident_exp",
        "identifier expected",                          /* 20   */
        "Bezeichner erwartet",                          /* 20   */
        "identificateur requis",                        /* 20   */
        "識別子でなければならない",                     /* 20   */
  },
  { "preprocess",
        "unrecognized preprocessing directive",         /* 21   */
        "Unbekannte Prаrozessoranweisung '#%s'",       /* 21   */
        "instruction prＱrocesseur '#%s' non reconnue", /* 21   */
        "不正プリプロセッサ指令 '#%s'",                 /* 21   */
  },
  { "memmodels",
        "valid memory models are -m[tsmcrzlvfnpx]",     /* 22 C */
        "G〕tige Speichermodelle sind -m[tsmcrzlvfnpx]", /* 22 C */
        "les mod獲es de mＮoire autorisＴ sont -m[tsmcrzlvfnpx]",       /* 22 C */
        "メモリモデルは -ms、-mm、-mc、-ml のいずれか",  /* 22 C */
  },
  { "eol",
        "end of line expected",                         /* 23 P */
        "Zeilenende erwartet",                          /* 23 P */
        "fin de ligne requise",                         /* 23 P */
        "行末でなければならない",                       /* 23 P */
  },
  { "num",
        "integer constant expression expected",         /* 24   */
        "Konstanter Integer-Ausdruck erwartet",         /* 24   */
        "expression de constante enti較e requise",      /* 24   */
        "整数の定数式でなければならない",               /* 24   */
  },
  { "linnum",
        "line number expected",                         /* 25 P */
        "Zeilennummer erwartet",                        /* 25 P */
        "numＳo de ligne requis",                       /* 25 P */
        "行番号でなければならない",                     /* 25 P */
  },
  { "2manyerrors",
        "too many errors",                              /* 27   */
        "Zu viele Fehler",                              /* 27   */
        "trop d'erreurs",                               /* 27   */
        "エラーが多すぎる",                             /* 27   */
  },
  { "num_args",
        "%d actual arguments expected for %s, had %d",          /* 29   */
        "%d Argumente f〉 %s erwartet, %d erhalten",            /* 29   */
        "%d arguments effectifs requis pour %s, %d fournis",    /* 29   */
        "%d 個の引数でなければならない (%s)",                   /* 29   */
  },
  { "filespec",
        "filespec string expected",                     /* 30   */
        "String f〉 Dateispezifikation erwartet",       /* 30   */
        "cha系e d'identification de fichier requise",   /* 30   */
        "ファイル名でなければならない",                 /* 30   */
  },
  { "endif",
        "'#endif' found without '#if'",                 /* 31 P */
        "'#endif' ohne '#if'",                          /* 31 P */
        "'#endif' dＵect� sans '#if'",                  /* 31 P */
        "'#if' がないのに '#endif' があった",           /* 31 P */
  },
  { "eof_endif",
        "end of file found before '#endif'",                    /* 32 P */
        "Dateiende vor '#endif'",                               /* 32 P */
        "fin de fichier dＵectＦ avant '#endif'",               /* 32 P */
        "'#endif' が見つからない間にファイルの終りに達した",    /* 32 P */
  },
  { "else",
        "'#else' or '#elif' found without '#if'",       /* 33 P */
        "'#else' oder '#elif' ohne '#if'",              /* 33 P */
        "''#else' ou '#elif' dＵect� sans '#if'",       /* 33 P */
        "'#if' がないのに '#else' か '#elif' があった", /* 33 P */
  },
        // Probably missing closing quote or )
  { "macarg",
        "unterminated macro argument",                  // 34 P
        "Nicht abgeschlossenes Makroargument",          // 34 P
        "argument de macro incomplet",                  // 34 P
        "マクロ引数が終了していない",                   // 34 P
  },
  { "align",
        // Alignment for struct members must be 1,2,4,8, etc.
        "alignment must be a power of 2",                       /* 35 P,C */
        "Ausrichtung mu� eine Potenz von 2 sein",               /* 35 P,C */
        "l'alignement doit �tre une puissance de 2",            /* 35 P,C */
        "アラインメントの指定は2の冪乗でなければならない",      // 35 P,C
  },
        // ANSI C 3.8.8
  { "undef",
        "macro '%s' can't be #undef'd or #define'd",                    /* 36 P */
        "'#undef' oder '#define' nicht anwendbar auf Makro '%s'",       /* 36 P */
        "impossible d'appliquer #undef ou #define � la macro '%s'",     /* 36 P */
        "マクロ '%s' を #undef または #define できない",                /* 36 P */
  },
  { "rbra",
        "']' expected",                                 /* 38 S */
        "']' erwartet",                                 /* 38 S */
        "']' requis",                                   /* 38 S */
        "']' でなければならない",                       /* 38 S */
  },
  { "punctuation",
        "'=', ';' or ',' expected",                     /* 46 S */
        "'=', ';' oder ',' erwartet",                   /* 46 S */
        "'=', ';' ou ',' requis",                       /* 46 S */
        "'='、';'、または ',' でなければならない",      /* 46 S */
  },

  { "multiple_def",
        "'%s' is already defined",                      /* 48 S,P */
        "'%s' ist bereits definiert",                   /* 48 S,P */
        "'%s' est dＫ� dＧini",                         /* 48 S,P */
        "'%s' は既に定義されている",                    /* 48 S,P */
  },
  { "redefined",
        "'%s' previously declared as something else",   /* 81 S */
        "'%s' wurde vorher bereits anders deklariert",  /* 81 S */
        "'%s' dＫ� dＤlar� de mani較e diffＳente",      /* 81 S */
        "'%s' は既に別に宣言されている",                /* 81 S */
  },
  { "undefined",
        "undefined identifier '%s'",                    /* 49 S */
        "Undefinierter Bezeichner '%s'",                /* 49 S */
        "identificateur '%s' non dＧini",               /* 49 S */
        "未定識別子 '%s'",                              /* 49 S */
  },
  { "undefined2",
        "undefined identifier '%s', did you mean '%s'?",                        /* 49 S */
  },
  { "rcur",
        "'}' expected",                                 /* 55 S */
        "'}' erwartet",                                 /* 55 S */
        "'}' requis",                                   /* 55 S */
        "'}' でなければならない",                       /* 55 S */
  },
  { "response_file",
        "can't open response file",                     /* 57 S */
        "Antwortdatei kann nicht ge杷fnet werden",      /* 57 S */
        "ouverture du fichier de rＱonse impossible",   /* 57 S */
        "レスポンスファイルが開けない",                 /* 57 S */
  },
  { "pragma_proto",
        "pragma parameter function prototype not found",/* 57 S */
        "Prototyp f〉 Pragma-Parameterfunktion nicht gefunden",/* 57 S */
        "prototype de fonction du param閣re pragma introuvable",/* 57 S */
  },
  { "lcur_exp",
        "'{' expected",                                 /* 58 S } */
        "'{' erwartet",                                 /* 58 S } */
        "'{' requis",                                   /* 58 S } */
        "'{' でなければならない",                       /* 58 S } */
  },
  { "colon",
        "':' expected",                                 /* 62 S */
        "':' erwartet",                                 /* 62 S */
        "':' requis",                                   /* 62 S */
        "':' でなければならない",                       /* 62 S */
  },
  { "exp",
        "expression expected",                          /* 63 S */
        "Ausdruck erwartet",                                    /* 63 S */
        "expression requise",                           /* 63 S */
        "式でなければならない",                         /* 63 S */
  },
  { "lpar",
        "'(' expected",                                 /* 66 S */
        "'(' erwartet",                                 /* 66 S */
        "'(' requis",                                   /* 66 S */
        "'(' でなければならない",                       /* 66 S */
  },
  { "lpar2",
        "'(' expected following %s",
        "'(' erwartet",
        "'(' requis",
        "'(' でなければならない",
  },
  { "illegal_op_types",
        "illegal operand types",                        /* 83 S */
        "Unzulгsiger Operandentyp",                            /* 83 S */
        "types d'opＳandes non valides",                        /* 83 S */
        "不正オペランド型",                             /* 83 S */
  },
  { "open_input",
        "unable to open input file '%s'",               /* 84 S */
        "Eingabedatei '%s' kann nicht ge杷fnet werden", /* 84 S */
        "impossible d'ouvrir le fichier d'entrＦ '%s'",         /* 84 S */
        "入力ファイル '%s' が開けない",                 /* 84 S */
  },
  { "open_output",
        "unable to open output file '%s'",              /* 85 S */
        "Ausgabedatei '%s' kann nicht ge杷fnet werden", /* 85 S */
        "impossible d'ouvrir le fichier de sortie '%s'",                /* 85 S */
        "出力ファイル '%s' が開けない",                 /* 85 S */
  },

        // Attempt to divide by 0 when constant folding.
        // For instance:
        //      int x = 5 / 0;
  { "divby0",
        "divide by 0",                                  /* 86 S */
        "Division durch 0",                                     /* 86 S */
        "division par zＳo",                                    /* 86 S */
        "ゼロ除算",                                     /* 86 S */
  },
  { "bad_filespec",
        "can't build filespec '%s'",                    /* 88 S */
        "Dateispezifikation '%s' kann nicht erstellt werden",                   /* 88 S */
        "impossible de gＯＳer la spＤification de fichier '%S'",                       /* 88 S */
        "パス '%s' が不正",                             /* 88 S */
  },
        // Input and output files have the same name
  { "mult_files",
        "duplicate file names '%s'",                    /* 89 S */
        "Doppelter Dateiname: '%s'",                    /* 89 S */
        "nom de fichier '%s' en double",                        /* 89 S */
        "重複ファイル名 '%s'",                          /* 89 S */
  },
  { "bad_filename",
        "bad file name '%s'",                           /* 90 S */
        "Ung〕tiger Dateiname: '%s'",                           /* 90 S */
        "nom de fichier '%s' incorrect",                                /* 90 S */
        "不正ファイル名 '%s'",                          /* 90 S */
  },

        /* Comments do not nest in C. You cannot 'comment out' a block
           of code containing C comments with a C comment. The correct
           way to remove a block of code is to use a #if 0 ... #endif block.
           Also, this warning will appear if you 'forget' to terminate
           a comment (the warning appears at the start of the next comment).
         */
  { "nestcomment",
        "comments do not nest",                         /* 91 W */
        "Kommentare k馬nen nicht verschachtelt werden",                         /* 91 W */
        "imbrication des commentaires interdite",                               /* 91 W */
        "コメントはネストできない",                     /* 91 W */
  },
  { "string",
        "string expected",                                      /* 92 P */
        "String erwartet",                                      /* 92 P */
        "cha系e requise",                                       /* 92 P */
        "文字列でなければならない",                     /* 92 P */
  },
#if 0 // obsoleted by C99
  { "blank_arg",
        "blank arguments are illegal",                  /* 93 P */
        "Leere Argumente nicht zulгsig",                       /* 93 P */
        "arguments vides non autorisＴ",                        /* 93 P */
        "空きの引数は使えない",                         /* 93 P */
  },
#endif
  { "integral",
        "integral expression expected",                 /* 94 S */
        "Integraler Ausdruck erwartet",                 /* 94 S */
        "expression intＨrale requise",                 /* 94 S */
        "整数式でなければならない",                     /* 94 S */
  },
        /* Happens when a ; immediately follows an if, for, while as in:
                if (x);
           which is a common and hard-to-spot error. To suppress put
           whitespace between the ) and the ;, as in:
                if (x)
                    ;
         */
  { "extra_semi",
        "possible extraneous ';'",                      /* 98 W */
        "M波licherweise ｜erfl《siges ';'",             /* 98 W */
        "prＴence possible de ';' superflu",            /* 98 W */
        //#pragma dbcs(push,1)
        //"';' が多すぎる可能性がある",                 /* 98 W */
        //#pragma dbcs(pop)
        "\x27\x3b\x27\x20\x82\xaa\x91\xbd\x82\xb7\x82\xac\x82\xe9\x89\xc2\x94\x5c\x90\xab\x82\xaa\x82\xa0\x82\xe9",
  },
  { "lvalue",
        "lvalue expected",                              /* 101 S */
        "lvalue erwartet",                              /* 101 S */
        "lvalue requise",                               /* 101 S */
        "左辺値でなければならない",                     /* 101 S */
  },

        /* Occurs in instances like:
                a == b;
                (short)func();
           where a value is computed, but is thrown away.
           To suppress the warning, cast to void:
                (void)(a == b);
                (void)(short)func();
         */
  { "valuenotused",
        "value of expression is not used",              /* 102 W */
        "Wert des Ausdrucks wird nicht benutzt",        /* 102 W */
        "valeur de l'expression inutilisＦ",            /* 102 W */
        "式の値が使われていない",                       /* 102 W */
  },
        /* ANSI C 3.1.3.4
           Found end of file or end of line before end of string.
         */
  { "noendofstring",
        "unterminated string",                          /* 104   */
        "Nicht abgeschlossener String",                 /* 104   */
        "cha系e non terminＦ",                          /* 104   */
        "文字列が終了していない",                       /* 104   */
  },
        // Probably out of disk space
  { "write_error",
        "error writing output file '%s'",                       // 107F
        "Fehler beim Schreiben der Ausgabedatei",               /* 107F */
        "erreur d'Ｄriture dans le fichier de sortie",                  /* 107F */
        "出力ファイル書き込みエラー",                   /* 107F */
  },
  { "octal_digit",
        "octal digit expected",                         /* 108L */
        "Oktalziffer erwartet",                         /* 108L */
        "chiffre octal requis",                         /* 108L */
        "8進の数字でなければならない",                  /* 108L */
  },
  { "const_assign",
        "can't assign to const variable %s",            /* 109S */
        "Zuweisung zu Const-Variable nicht m波lich",
        "affectation � une variable constante impossible",
        "const変数への代入ができない",
  },
  { "null_nl",
        "%s",                                           /* 110E */
  },

        /* The compiler has run out of memory. Try compiling with
           the -bx, -b and -br switches (usually in that order).
         */
  { "nomem",
        "out of memory",                                /* 111  */
        "Nicht gen“end Speicher",                              /* 111  */
        "mＮoire saturＦ",                              /* 111  */
        "メモリ不足",                                   /* 111  */
  },
  { "command_line_error",
        "Command line error: ",                         /* 112  */
        "Fehler in der Befehlszeile: ",                 /* 112  */
        "erreur de ligne de commande :",                                /* 112  */
        "コマンドラインエラー: ",                       /* 112  */
  },
  { "no_comment_term",
        "end of file found before end of comment, line %d",     /* 115  */
        "Dateiende vor Kommentarende, Zeile %d",        /* 115  */
        "fin de fichier dＵect� avant la fin du commentaire � la ligne %d",     /* 115  */
        "コメント中にファイルの終りに達成した (行番号 %d)",     /* 115  */
  },
  { "warning",
        "Warning %d: ",                                 /* 116  */
        "Warnung %d: ",                                 /* 116  */
        "Avertissement %d :",                                   /* 116  */
        "警告 %d: ",                                    /* 116  */
  },
  { "lexical_error",
        "Lexical error: ",                              /* 117  */
        "Lexikalischer Fehler: ",                               /* 117  */
        "Erreur de lexique :",                          /* 117  */
        "語句エラー: ",                                 /* 117  */
  },
  { "preprocessor_error",
        "Preprocessor error: ",                         /* 118  */
        "Prаrozessorfehler: ",                         /* 118  */
        "Erreur du prＱrocesseur :",                            /* 118  */
        "プリプロセッサエラー: ",                       /* 118  */
  },

        // This line controls the format for how errors are reported
  { "line_format",
    #if linux || __APPLE__ || __FreeBSD__ || __OpenBSD__
        "%s:%d: "
    #elif TX86
        "%s(%d) : ",                                    /* 119  */
    #else
        "File \"%s\"; line %u #",                       /* 119  */
        "Datei \"%s\"; Zeile %u #",                     /* 119  */
        "Fichier \"%s\"; ligne %u #",                   /* 119  */
    #endif
  },
  { "0or1",
        "0 or 1 expected",                              /* 122L */
        "0 oder 1 erwartet",                            /* 122L */
        "0 ou 1 requis",                                /* 122L */
        "0 または 1 でなければならない",                /* 122L */
  },

        /* Last line in source file must end in a \n without an         */
        /* immediately preceding backslash.                             */
  { "no_nl",
        "last line in file had no \\\\n",                       /* 126L */
        "Letzte Zeile der Datei hat kein \\\\n",        /* 126L */
        "\\\\n manquant sur la derni較e ligne du fichier",      /* 126L */
        "ファイルの最終行に \\\\n がない",              /* 126L */
  },

  { "prep_exp",
        "casts and sizeof are illegal in preprocessor expressions", /* 131 */
        "Casts und Sizeof unzulгsig in Prаrozessorausdr…ken", /* 131 */
        "cast et sizeof interdits dans les expressions du preprocesseur", /* 131 */
        "プリプロセッサ式にはキャストおよび sizeof は使えない", /* 131 */
  },
        /* ANSI escape sequences are: \' \" \? \\
           \a \b \f \n \r \t \v \x hex-digit \octal-digit
         */
  { "bad_escape_seq",
        "undefined escape sequence",                    /* 133L */
        "Nicht definierte Escape-Sequenz",                      /* 133L */
        "sＲuence d'Ｄhappement inconnue",                      /* 133L */
        "未定義エスケープシケンス",                     /* 133L */
  },
  { "binary_exp",
        "binary exponent part required for hex floating constants", /* 134L */
        "Binвer Exponentteil erforderlich f〉 hex. Float-Konstanten", /* 134L */
        "exposant binaire obligatoire pour les constantes hexadＤimales � virgule flottante", /* 134L */
        "16進の浮動小数点数には指数部が必要",           /* 134L */
  },
  { "cseg_global",
        "pragma cseg must be at global scope",          /* 136  */
        "Pragma Cseg mu� global g〕tig sein",           /* 136  */
        "pragma cseg doit �tre de visibilit� globale",          /* 136  */
        "pragma cseg はグローバルスコープで記述しなければならない",     /* 136  */
  },

        /* ANSI 3.8.3.3 */
  { "hashhash_end",
        "## cannot appear at beginning or end",         /* 142P */
        "## darf nicht am Anfang oder Ende stehen",             /* 142P */
        "## interdit au dＣut et � la fin",             /* 142P */
        "## は文字列の間でなければならない",                    /* 142P */
  },
        /* ANSI 3.8.3.2 */
  { "hashparam",
        "# must be followed by a parameter",            /* 143P */
        "# mu� von einem Parameter gefolgt werden",             /* 143P */
        "# doit �tre suivi d'un param閣re",             /* 143P */
        "# にはパラメータが続かなければならない",               /* 143P */
  },
        /* ANSI 3.4     */
  { "comma_const",
        "comma not allowed in constant expression",             /* 147S */
        "Komma nicht zulгsig in konstantem Ausdruck",          /* 147S */
        "les virgules ne sont pas autorisＦs dans les exptessions constantes",  /* 147S */
        "定数式にはコンマを使ってはならない",           /* 147S */
  },

        // Compiler bug: report to Digital Mars
  { "internal_error",
        "internal error %s %d",                         // 168
        "Interner Fehler %s %d",                                // 168
        "erreur interne %s%d",                          // 168
        "内部エラー: %s %d",                            // 168
  },

        // Exceeded maximum length of macro replacement text.
        // (%s is replaced by "macro text")
  { "max_macro_text",
        "maximum %s length of %u exceeded",             // 169
        "Max. %s-L�nge von %u ｜erschritten",           // 169
        "la longueur de %s dＱasse la limite de %u",            // 169
        "最大の長さ %u を越えている",                   // 169
  },

        // The compiler does not support macros with more than
        // 251 parameters.
  { "max_macro_params",
        "%u exceeds maximum of %u macro parameters",    // 171
        "%u ｜ersteigt die max. Anz. von %u Makroparametern",   // 171
        "%u dＱasse le nombre maximal de %u param閣res de macro",       // 171
        "%u は最大マクロパラメータ数の %u を越えている",// 171
  },

  { "null",
        "",                                             // 174
  },
        // Probably had syntax like:
        //      int x y;
        // where x was supposed to be a macro.
  { "missing_comma",
        "missing ',' between declaration of '%s' and '%s'",     // 176S
        "',' fehlt zwischen Deklaration von '%s' und '%s'",     // 176S
        "virgule manquante entre '%s' et sa dＤlaration",       // 176S
  },

        // Parameters are separated by commas.
  { "comma",
        "',' expected",                                         // 178S
        "',' erwartet",                                         // 178S
        "',' requis",                                           // 178S
  },
  { "pop_wo_push",
        "#pragma pack(pop) does not have corresponding push",   // 179P
        "#pragma pack(pop) hat kein entsprechendes push",       // 179P
        "#pragma pack(pop) sans push correspondant",    // 179P
  },
  { "pascal_str_2long",
        "pascal string length %u is longer than 255",           // 180L
        "Pascal-Stringl�nge %u ist gr批er als 255",             // 180L
        "longueur de la cha系e pascal %u supＳieure � 255",             // 180L
  },
  { "fatal_error",
        "Fatal error: ",                                        // 184
        "Schwerer Fehler: ",                                    // 184
        "Erreur fatale :",                                      // 184
  },
        // Either the file cannot be opened for reading or
        // the virtual memory address is not available
  { "cant_map_file",
        "cannot map file '%s' at %p",                   // 187
        "Umsetzung der Datei '%s' an %p nicht m波lich",                 // 187
        "impossible d'accＥer au fichier '%s' � %p",                    // 187
  },

        // There is insufficient virtual memory at that address
  { "cant_reserve_mem",
        "cannot reserve memory at %p",                  // 188
        "Speicher an %p kann nicht reserviert werden",                  // 188
        "impossible de rＴerver de la mＮoire � %p",                    // 188
  },

        // There is a maximum on the number of #include files
        // used in precompiled headers.
  { "2manyfiles",
        "max of %d include files exceeded",                     // 190
  },

  { "nolocale",
        "locale \"%s\" not supported by operating system",      // 195
  },

        // 64 bit ints are only supported for 32 bit memory models.
        // The long long data type is not ANSI standard.
  { "no_longlong",
        "long long not supported for ANSI or 16 bit compiles",  // 167S
        "Long Long nicht unterst》zt bei ANSI- oder 16-Bit-Kompilierung",       // 167S
        "long long incompatible avec la compilation ANSI ou 16 bits",   // 167S
  },

  { "no_complex",
        "complex and imaginary types not supported for this memory model",
  },

        // C99 6.7.5.2-2
  { "no_vla",
        "variable length arrays are only for function prototypes and autos",
  },

   /* C++0x A.2 "any member of the basic source character set except:
    * space, the left parenthesis (, the right parenthesis ), the backslash \,
    * and the control characters representing horizontal tab,
    * vertical tab, form feed, and newline."
    */
   { "invalid_dchar",
        "valid d-char's are ASCII except for ( ) space \\\\ \\\\t \\\\v \\\\f \\\\n, not x%02x",
   },

   { "bad_utf",
        "bad UTF-8 sequence %s",
   },

   { "mismatched_string",
        "concatenated string literal types do not match",
   },

   { "static_assert",
        "static_assert failed %s",
   },

   { "static_assert_semi",
        "';' expected following static_assert declaration",
   },

   { "narrow_string",
        "string literal must be a narrow string literal",
   },

   { "no_nullptr_bool",
        "nullptr cannot give boolean result",
   },

// Error messages specific to TX86
        // Can't specify 16 bit instruction set for 32 bit memory model
  { "bad_iset",
        "invalid instruction set '%c' for memory model '%c'",   // 166
        "Ung〕tiger Instruktionssatz '%c' f〉 Speichermodell '%c'",     // 166
        "jeu d'instructions '%c' incompatible avec le mod獲e de mＮoire '%c'",  // 166
        "命令セット '%c' をメモリモデル '%c' には使えない",     // 166
  },

   { "too_many_symbols",
        "more than %d symbols in object file",
   },


//////////////////////////////////////////////////////////////////
// Preprocessor and C messages

  { "cpp_comments",
        "// comments are not ANSI C",                   /* 60   */
        "Kommentare mit // entsprechen nicht ANSI C",                   /* 60   */
        "commentaires // non valides en C ANSI",                        /* 60   */
        "// で始まるコメントは ANSI C にない",          /* 60   */
  },

//////////////////////////////////////////////////////////////////
// C messages

        /* ANSI 3.5.2.1 There must be at least one member
           of the struct
         */
  { "empty_sdl",
        "struct-declaration-list can't be empty",
        "Struct-Declaration-Liste darf nicht leer sein",
        "la liste de dＤlaration des structures ne doit pas �tre vide",
        "struct の宣言リストは空きになっていてはならない",
  },
        // Use -p to turn off autoprototyping
  { "recursive_proto",
        "recursive prototype, turn off autoprototyping",
        "Rekursiver Prototyp, autom. Prototypbildung abschalten",
        "prototype rＤursif, dＴactivez le prototypage automatique",
        "再帰的なプロトタイプ宣言、自動プロトタイプをOFFにしなければならない",
  },

//////////////////////////////////////////////////////////////////
// C and C++ messages


  { "bad_type_comb",
        "illegal type combination, possible missing ';' after struct", // 181S
        "Unzulгsige Typkombination, evtl. fehlt ';' nach Struct", // 181S
        "combinaison de types non autorisＦ, absence possible de ',' apr郭 struct", // 181S
  },

        /* Can't have both near and far, etc.
           Can't use modifiers on references, pascal on pointers, etc.
           Can't have stack pointer to function.
           Can't have things like short long, etc.
         */
  { "illegal_type_combo",
        "illegal combination of types",                 /* 125S */
        "Unzulгsige Typkombination",                   /* 125S */
        "combinaison de types incorrecte",                      /* 125S */
        "不正な型の組合せ",                             /* 125S */
  },

  { "ptr_to_ref",
        "illegal pointer to reference",
  },

  { "ref_to_ref",
        "illegal reference to reference",
  },

  { "illegal_cast",
        "illegal cast",                                 /* 82 S */
        "Unzulгsiges Cast",                                    /* 82 S */
        "cast non valide",                                      /* 82 S */
        "不正キャスト",                                 /* 82 S */
  },
  { "2manyinits",
        "too many initializers",                        /* 56 S */
        "Zu viele Initialisierer",                      /* 56 S */
        "trop de codes d'initialisation",               /* 56 S */
        "初期化子が多すぎる",                           /* 56 S */
  },
        // Probably need an explicit cast
  { "explicit_cast",
        "need explicit cast to convert",                // 26
        "Implizite Konvertierung nicht m波lich",        /* 26   */
        "conversion implicite impossible",              /* 26   */
        "暗黙な変換ができない",                         /* 26   */
  },
        /* ANSI C 3.5.4.3
                func(s) short s; { ... }
           should be prototyped as:
                func(int s);
           rather than:
                func(short s);
         */
  { "prototype",
        "prototype for '%s' should be %s",              /* 19   */
        "Prototyp f〉 '%s' sollte %s sein",             /* 19   */
        "le prototype de '%s' doit �tre %s",            /* 19   */
        "'%s' のプロトタイプは %s でなければならない",  /* 19   */
  },
  { "tag",
        "'{' or tag identifier expected",               /* 12 S */
        "'{' oder Tag-Bezeichner erwartet",             /* 12 S */
        "'{' ou identificateur de balise requis",       /* 12 S */
        "'{' またはタグ識別子でなければならない",       /* 12 S */
  },
  { "no_inline",
        "function '%s' is too complicated to inline",   /* 15 W */
        "Funktion '%s' zu komplex f〉 Inline",          /* 15 W */
        "fonction '%s' trop complexe pour inline",      /* 15 W */
        "関数 '%s' が複雑すぎてインライン化できない",   /* 15 W */
  },
  { "statement",
        "statement expected",                           /*  7 S */
        "Anweisung erwartet",                           /*  7 S */
        "instruction requise",                          /*  7 S */
        "文でなければならない",                         /*  7 S */
  },
        // Identifer is both a symbol and a member of a struct.
  { "ambig_ref",
        "ambiguous reference to '%s'",                  // 189
        "Mehrdeutige Referenz '%s'",                            // 189
        "rＧＳence � '%s' ambigu�",                             // 189
  },

        // Can't implicitly convert one of the function parameters,
        // probably need a cast.
  { "explicitcast",
        "need explicit cast for function parameter %d to get", // 191
  },

        // 1. Command line switches aren't right
  { "nodebexp",
        "can't compile debugger expression",                    // 194
  },
  { "was_declared",
        "It was declared as: %s",                               // 185
        "Wurde deklariert als: %s",                             // 185
        "ElＮent dＤlar� auparavant sous la forme %s",                          // 185
  },
  { "now_declared",
        "It is now declared: %s",                               // 186
        "Wird jetzt deklariert als: %s",                        // 186
        "ElＮent dＴormais dＤlar� sous la forme %s",                           // 186
  },

        // ANSI 3.4
        // The value for a case is larger than the type of
        // the switch expression, for example, if you are
        // switching on a short, and the case is 100000L, then
        // it won't fit.
  { "const_case",
        "constant expression does not fit in switch type",      /* 148S */
        "Konstanter Ausdruck pa疸 nicht in Schaltertyp",        /* 148S */
        "expression constante incompatible avec le type d'aiguillage",  /* 148S */
        "定数式が switch 変数のサイズより大きい",       /* 148S */
  },

        /* ANSI 3.5 A declarator shall declare at least
           a declarator, a tag, or the members of an enumeration
         */
  { "empty_decl",
        "empty declaration",                                    /* 149S */
        "Leere Deklaration",                                    /* 149S */
        "dＤlaration vide",                                     /* 149S */
        "空き宣言",                                     /* 149S */
  },

        /* This is detected when the optimizer does data flow analysis
           on the program. The analysis has determined that there
           is no path through the function that possibly sets the
           variable before it is used. This is nearly always indicative
           of a serious bug.
         */
  { "used_b4_set",
        "variable '%s' used before set",                // 150W
        "Variable '%s' wird vor dem Setzen benutzt",            // 150W
        "variable '%s' utilisＦ avant sa dＧinition",           // 150W
        "変数 '%s' が代入の前に使用されている",         // 150W
  },

        // Probably results in an invalid pointer beyond the end of the stack
  { "ret_auto",
        "returning address of automatic '%s'",          // 161W
        "R…kgabe der Adresse der Automatic-Zuweisung '%s'",            // 161W
        "renvoi de l'adresse de la fonction automatic '%s'",            // 161W
        "自動変数 '%s' のポインタを返している",                 // 161W
  },

        // Code and data for 16 bit compiles is output into 64Kb
        // segments. One of those segments
        // exceeded 64Kb. Divide your source module up into smaller
        // pieces, or switch to a 32 bit memory model.
  { "seg_gt_64k",
        "segment size is 0x%lx, exceeding 64Kb",                        // 162
        "Segmentgr批e 0x%lx ｜ersteigt 64 Kb",                  // 162
        "la taille du segment est 0x%lx, dＱassement des 64 Ko",                        // 162
        "0x%lx のセグメントサイズが 64Kb を越えている",         // 162
  },

        // __saveregs is recognized but not supported by Digital Mars C/C++.
  { "bad_kwd",
        "keyword not supported",                        // 163
        "Schl《selwort wird nicht unterst》zt",                 // 163
        "mot-cl� non valide",                   // 163
        "キーワードがサポートされていない",                     // 163
  },

        // The member appears in more than one struct, so you
        // need to specify which it is.
  { "ambig_member",
        "'%s' is a member of '%s' and '%s'",            // 164
        "'%s' ist Glied von '%s' und '%s'",             // 164
        "'%s' est membre de '%s' et de '%s'",           // 164
        "'%s' は '%s' と '%s' の両方のメンバになっている",      // 164
  },

        // Can't have a member of struct X that is of type X
  { "mem_same_type",
        "member '%s' can't be same type as struct '%s'",        // 165
        "Glied '%s' kann nicht vom gleichen Typ sein wie Struct '%s'",  // 165
        "le membre '%s' et la structure '%s' ne doivent pas �tre du m�me type", // 165
        "メンバ '%s' の型は struct '%s' と同じになってはならない",      // 165
  },

        /* ANSI 3.7.1   */
  { "explicit_param",
        "function definition must have explicit parameter list", /* 144S */
        "Funktionsdefinition ben杯igt explizite Parameterliste", /* 144S */
        "une liste de param閣res explicite doit �tre associＦ � la dＧinition de la fonction", /* 144S */
        "関数定義には具体的なパラメータリストが必要",            /* 144S */
  },

        /* ANSI 3.5.7   */
  { "ext_block_init",
        "external with block scope cannot have initializer",    /* 145S */
        "Externe mit Block-G〕tigkeit kann keinen Initialisierer haben",        /* 145S */
        "les variables externes utilisant la visibilit� de bloc doivent �tre dＱourvues de code d'initialisation",      /* 145S */
        "ブロックスコープの external には初期化子があってはならない",   /* 145S */
  },

        /* Precompiled headers can only have declarations, not
           definitions, in them.
         */
  { "data_in_pch",
        "data or code '%s' defined in precompiled header",      /* 146S */
        "Daten oder Code in vorkompiliertem Header definiert",          /* 146S */
        "l'en-t�te prＤompil� contient les donnＦs ou le code '%s'",    /* 146S */
    #if TX86
        "プリコンパイルヘッダにデータが定義されている",                 /* 146S */
    #else
        "プリコンパイルヘッダにデータかコード '%s' が定義されている",   /* 146S */
    #endif
  },

        /* ARM 6.6.3
           A non-void return type was specified for the function,
           but no return expression is given.
         */
  { "no_ret_value",
        "no return value for function '%s'",            // 127S,W
        "Kein R…kgabewert f〉 Funktion '%s'",  // 127S,W
        "pas de valeur de retour pour la fonction '%s'",                // 127S,W
        "関数 '%s' の戻り値がない",                             /* 127S */
  },
  { "sizeof_bitfield",
        "can't take sizeof bit field",                  /* 128S */
        "Kann kein Sizeof-Bitfeld aufnehmen",   /* 128S */
        "sizeof non utilisable avec un champ de bits",                  /* 128S */
        "ビットフィールドの sizeof をとることはできない",       /* 128S */
  },
  { "no_ident_decl",
        "no identifier for declarator",                 /* 120S */
        "Keine Bezeichner f〉 Deklarator",              /* 120S */
        "dＤlaration dＱourvue d'identificateur",                       /* 120S */
        "宣言子に識別子がない",                         /* 120S */
  },
  { "typesize_gt64k",
        "size of type exceeds 64k",                     /* 121S */
        "Typ gr批er als 64 KB",                 /* 121S */
        "taille du type supＳieure � 64 Ko",                    /* 121S */
        "型のサイズが 64k を越えている",                /* 121S */
  },
  { "noaddress",
        "can't take address of register, bit field, constant or string", /* 103 S */
        "Kann Adresse von Register, Bit-Feld, I-Konstante oder String nicht aufnehmen", /* 103 S */
        "impossible d'enregistrer l'adresse du registre, du champ de bits, de la constante ou de la cha系e", /* 103 S */
        "レジスタ、ビットフィールド、定数および文字列のアドレスは取れない", /* 103 S */
  },

  { "bad_struct_use",
        "undefined use of struct or union",             /* 99 S */
        "Undefinierte Verwendung von Struct oder Union",        /* 99 S */
        "utilisation non dＧinie de struct ou union",           /* 99 S */
        "struct または union の不正使用",               /* 99 S */
  },

        /* Occurs in instances like:
                if (a = b)
                while (x = f())
           which are common errors when
                if (a == b)
                while (x == f())
           were intended. To suppress the warning, rewrite as:
                if ((a = b) != NULL)
                while ((x = f()) != NULL)
         */
  { "assignment",
        "possible unintended assignment",               /* 100 W */
        "M波licherweise unbeabsichtigte Zuweisung",     /* 100 W */
        "prＴence possible d'une affectation non voulue",               /* 100 W */
        #pragma dbcs(push,1)
        "誤った代入の可能性がある",                     /* 100 W */
        #pragma dbcs(pop)
  },
  { "type_mismatch",
        "type mismatch",                                /* 76 S */
        "Typ stimmt nicht ｜erein",                             /* 76 S */
        "conflit de types",                             /* 76 S */
        "型が矛盾している",                             /* 76 S */
  },
  { "mult_default",
        "'default:' is already used",                   /* 77 S */
        "'default:' wird bereits benutzt",                      /* 77 S */
        "'default:' dＫ� utilis�",                      /* 77 S */
        "'default:' は既に使われている",                /* 77 S */
  },
  { "not_switch",
        "not in a switch statement",                    /* 78 S */
        "Nicht in einer Verzweigungsanweisung",                 /* 78 S */
        "pas dans une instruction d'aiguillage",                        /* 78 S */
        "switch 文内でない",                            /* 78 S */
  },
        /* Probably means you forgot to declare a function that returns */
        /* a pointer, so the compiler assumed it returns int. Cast int  */
        /* to a long before the pointer cast if you really mean it.     */
  { "int2far",
        "conversion of int to far or handle pointer",   /* 79 S */
        "Konvertierung von Int in Far- oder Handle-Pointer",    /* 79 S */
        "conversion de int en pointeur far ou descripteur",     /* 79 S */
        "int が far または handle ポインタに変換されている",    /* 79 S */
  },
  { "mult_case",
        "case %ld was already used",                    /* 80 S */
        "Case %ld wurde bereits benutzt",                       /* 80 S */
        "le cas %ld a dＫ� Ｕ� utilis�",                        /* 80 S */
        "case %ld は既に使われている",                  /* 80 S */
  },
        /* A function must precede a ().
           Also occurs if a template declaration is not
           a class template or a function template.
         */
  { "function",
        "function expected",                            /* 64 S */
        "Funktion erwartet",                                    /* 64 S */
        "fonction requise",                             /* 64 S */
        "関数でなければならない",                       /* 64 S */
  },
  { "ident_abstract",
        "identifier '%s' found in abstract declarator", /* 65 S */
        "Bezeichner in abstraktem Deklarator gefunden", /* 65 S */
        "identificateur dＵect� dans une dＤlaration abstraite",        /* 65 S */
        "抽象宣言子に識別子がある",                     /* 65 S */
  },
  { "const_init",
        "constant initializer expected",                /* 59 S */
        "Konstanter Initialisierer erwartet",           /* 59 S */
        "initialisation de la constante requise",       /* 59 S */
        "定数の初期化子でなければならない",             /* 59 S */
  },
        // ARM 7
        // Only in function definitions and function declarations
        // may the decl-specifier-seq be omitted.
        // A decl-specifier-seq is the storage class followed
        // by the type of a declaration.
  { "decl_spec_seq",
        "missing decl-specifier-seq for declaration of '%s'",   /* 61 S */
        "decl-specifier-seq fehlt f〉 Deklaration von '%s'",    /* 61 S */
        "sＲuence de spＤification manquante pour la dＤlaration de '%s'",      /* 61 S */
        "'%s'の宣言に宣言子が欠けている",               /* 61 S */
  },
  { "semi_member",
        "';' expected following declaration of struct member", // 51 S
        "';' erwartet",                                 /* 51 S */
        "';' requis",                                   /* 51 S */
        "';' がなければならない",                       /* 51 S */
  },
  { "bitfield",
        "bit field '%s' must be of integral type",      /* 50 S */
        "Feld '%s' mu� vom Typ Integral sein",          /* 50 S */
        "le champ '%s' doit �tre de type intＨral",     /* 50 S */
        "フィールド '%s' は整数型でなければならない",   /* 50 S */
  },
  { "bitwidth",
        "%d exceeds maximum bit field width of %d bits",        // 52 S
        "Max. Breite von %d Bits ｜erschritten",                /* 52 S */
        "dＱassement de la largeur autorisＦ de %d bits",       /* 52 S */
        "%d ビットの最大幅を越えている",                        /* 52 S */
  },
  { "unknown_size",
        "size of %s is not known",                      /* 53 S */
        "Gr批e von %s nicht bekannt",                   /* 53 S */
        "taille de %s inconnue",                        /* 53 S */
        "%s のサイズは知られていない",                  /* 53 S */
  },
  { "bad_member_type",
        "illegal type for '%s' member",                 /* 54 S */
        "Unzulгsiger Typ f〉 Glied '%s'",              /* 54 S */
        "membre '%s' de type non autoris�",             /* 54 S */
        "'%s' メンバの型が不正",                        /* 54 S */
  },
  { "id_or_decl",
        "identifier or '( declarator )' expected",      /* 39 S */
        "Bezeichner oder '( declarator )' erwartet",    /* 39 S */
        "identificateur ou '( dＤlaration )' requis",   /* 39 S */
        "識別子または '( 宣言子 )' でなければならない", /* 39 S */
  },
  { "not_param",
        "'%s' is not in function parameter list",               /* 40 S */
        "'%s' ist nicht in der Funktionsparameterliste",        /* 40 S */
        "'%s' ne figure pas dans la liste des param閣res de la fonction", /* 40 S       */
        "'%s' は関数のパラメータリストには含まれていない",      /* 40 S */
  },
  { "param_context",
        "parameter list is out of context",                     /* 41 S */
        "Parameterliste au疇rhalb des Kontexts",                /* 41 S */
        "la liste des param閣res est hors contexte",            /* 41 S */
        "パラメータリストの位置関係がおかしい",                 /* 41 S */
  },
  { "noprototype",
        "function '%s' has no prototype",               /* 44 S */
        "Funktion '%s' hat keinen Prototyp",            /* 44 S */
        "la fonction '%s' n'a pas de prototype",        /* 44 S */
        "関数 '%s' にはプロトタイプがない",             /* 44 S */
  },
  { "datadef",
        "expected data def of '%s', not func def",      /* 45 S */
        "Datendefinition von '%s' erwartet, nicht Funktionsdefinition", /* 45 S */
        "dＧinition de donnＦs de '%s' requise et non dＧinition de fonction",  /* 45 S */
        "関数定義ではなく、'%s' のデータ定義でなければならない",/* 45 S */
  },
  { "noextern",
        "cannot define parameter as extern",                    /* 37 S */
        "Parameter kann nicht als extern definiert werden",     /* 37 S */
        "impossible de dＧinir le param閣re comme extern",      /* 37 S */
        "パラメータを extern と定義することはできない",         /* 37 S */
  },
  { "badtag",
        "'%s' is not a correct struct, union or enum tag identifier", /* 28 S */
        "'%s' ist kein korrekter Tag-Bezeichner f〉 Struct, Union oder Enum", /* 28 S */
        "'%s' n'est pas une balise struct, union ou enum valide", /* 28 S */
        "'%s' は struct、union または enum のタグ識別子ではない", /* 28 S */
  },
  { "nomatch_proto",
        "type of '%s' does not match function prototype", /* 105 S */
        "Typ von '%s' stimmt nicht mit Prototyp der Funktion ｜erein", /* 105 S */
        "le type de '%s' ne correspond pas au prototype de la fonction", /* 105 S */
        "'%s' の型が関数プロトタイプと矛盾している",    /* 105 S */
  },
  { "void_novalue",
        // Also, void& is an illegal type
        // Constructors, destructors and invariants cannot return values.
        /* Functions returning void cannot return values.       */
        "voids have no value; ctors, dtors and invariants have no return value", // 106
        "Voids haben keinen Wert, Ctors und Dtors haben keinen R…kgabewert", /* 106 */
        "les void sont dＱourvus de valeur, les ctor et dtor ne renvoient pas de valeur", /* 106 */
        #pragma dbcs(push,1)
        "void には値がなく、構築子、消滅子には戻り値がない", /* 106 */
        #pragma dbcs(pop)
  },
        /* Precompiled headers must be compiled with same
           switches as when it is used.
           The precompiled header is ignored, and the header is reparsed.
         */
  { "pch_config",
        "different configuration for precompiled header", // 139 (W22)
        "Abweichende Konfiguration f〉 vorkompilierten Header", /* 139 */
        "la configuration de l'en-t�te prＤompil� a chang�", /* 139 */
        "ちがうオプションでコンパイルしたプリコンパイルヘッダを使用している", /* 139 */
  },
        // Use -cpp to precompile a header file with C++, as the default
        // is to compile a .h file with the C compiler.
  { "wrong_lang",
        "precompiled header compiled with C instead of C++",    // 182 F
        "Vorkompilierter Header wurde mit C statt mit C++ kompiliert",  // 182 F
        "en-t�te prＤompil� sous C et non sous C++",    // 182 F
  },

        // Define the struct before referencing its members.
  { "not_a_member",
        "'%s' is not a member of undefined class '%s'", // 175
        "'%s' ist nicht Glied des vorausreferenzierten Class '%s'",     // 175
        "'%s' n'est pas membre de la structure rＧＳencＦ '%s'",        // 175
  },
  { "not_a_member_alt",
        "'%s' is not a member of undefined class '%s', did you mean '%s'?",
  },

        // ANSI 3.7
        // A static is referred to, but no definition given, i.e.:
        //      static void f();
        //      void g() { f(); }
  { "no_static_def",
        "no definition for static '%s'",                // 172
        "Keine Definition f〉 Static '%s'",             // 172
        "la fonction static '%s' n'est pas dＧinie",            // 172
        "static '%s' は定義されていない",               // 172
  },

        // ANSI 3.7
        // An ANSI requirement that there be at least one global
        // symbol defined.
  { "no_ext_def",
        "need at least one external def",               // 173
        "Mindestens eine externe Definition erforderlich",              // 173
        "au moins une dＧinition externe est obligatoire",              // 173
        "最低1つの external 定義が必要",                // 173
  },

  { "decl_0size_bitfield",
        "declarator for 0 sized bit field",             /* 129S */
        "Deklarator f〉 Bitfeld mit Gr批e 0",           /* 129S */
        "dＤlaration d'un champ de bits de taille zＳo",                /* 129S */
        "サイズ 0 のビットフィールドに識別子をつけることはできない",/* 129S     */
  },

        /* An internally generated tag name is used. You should supply a
           tag name for easy debugging and name mangling purposes.
         */
  { "notagname",
        "no tag name for struct or enum",               /* 130W */
        "Kein Tag-Name f〉 Struct oder Enum",           /* 130W */
        "struct ou enum dＱourvu de nom de balise",             /* 130W */
        "struct または enum にタグ名がない",                    /* 130W */
  },
  { "unnamed_bitfield",
        "can't have unnamed bit fields in unions",      /* 123  */
        "Unbenannte Bit-Felder in Unions nicht zulгsig",       /* 123  */
        "champs de bits sans nom interdits dans les unions",    /* 123  */
        " unionには無名ビットフィールドを含むことはできない",   /* 123  */
  },
        /* Large automatic allocations will probably cause stack overflow */
  { "large_auto",
        "very large automatic",                         /* 124W */
        "Sehr gro疇 Automatic-Zuweisung",                       /* 124W */
        "assignation automatique de taille trop importante",                    /* 124W */
        "自動変数が大きすぎる",                         /* 124W */
  },
  { "array",
        "array or pointer required before '['",         /* 96 S */
        "Array oder Pointer erforderlich vor '['",              /* 96 S */
        "tableau ou pointeur requis avant '['",         /* 96 S */
        "'[' の前は配列またはポインタでなければならない",       /* 96 S */
  },

        /* ANSI C 3.5.4.2       */
  { "array_dim",
        "array dimension %d must be > 0",                       /* 97   */
        "Array-Dimension mu� > 0 sein",                 /* 97   */
        "la dimension du tableau doit �tre supＳieure � 0",                     /* 97   */
        "配列の次元数は 0 以上でなければならない",              /* 97   */
  },

  { "pointer",
        "pointer required before '->', '->*' or after '*'",     /* 95 S */
        "Pointer erforderlich vor '->', '->*' oder nach '*'",   /* 95 S */
        "pointeur requis avant '->' ou '->*' et apr郭 '*'",     /* 95 S */
        "'->'、'->*' の前および '*' の後はポインタでなければならない",  /* 95 S */
  },
  { "not_variable",
        // The symbol is not a variable, or is not a static variable.
        "'%s' is not a %svariable",                     /* 87 S */
        "'%s' ist keine %s-Variable",                           /* 87 S */
        "'%s' n'est pas une %svariable",                        /* 87 S */
        "'%s' は %s 変数ではない",                      /* 87 S */
  },
  { "while",
        "'while (expression)' expected after 'do { statement }'", // 67 S
        "'while' erwartet",                                     /* 67 S */
        "'while' requis",                               /* 67 S */
        "'while' でなければならない",                   /* 67 S */
  },
  { "bad_break",
        "'break' is valid only in a for, do, while or switch statement",        /* 68 S */
        "'break' ist nur g〕tig in Schleife oder Verzweigung",  /* 68 S */
        "'break' autoris� uniquement dans une boucle ou un aiguillage", /* 68 S */
        "'break' はループまたは switch 内に限る",       /* 68 S */
  },
  { "bad_continue",
        "'continue' is valid only in a for, do or while statement",             /* 69 S */
        "'continue' ist nur g〕tig in einer Schleife",  /* 69 S */
        "'continue' autoris� uniquement dans une boucle",               /* 69 S */
        "'continue' はループ内に限る",                  /* 69 S */
  },
  { "unknown_tag",
        "undefined tag '%s'",                           /* 70 S */
        "Undefiniertes Tag '%s'",                       /* 70 S */
        "balise '%s' non identifiＦ",                           /* 70 S */
        "未定タグ '%s'",                                /* 70 S */
  },
  { "unknown_label",
        "undefined label '%s'",                         /* 71 S */
        "Undefiniertes Label '%s'",                             /* 71 S */
        "Ｕiquette '%s' non identifiＦ",                                /* 71 S */
        "未定ラベル '%s'",                              /* 71 S */
  },
        // Can't subtract 2 pointers if they point to 0 sized objects
        // because a divide by 0 would result.
  { "0size",
        "cannot subtract pointers to objects of 0 size", // 72 S
        "Objekt hat die Gr批e 0",                               /* 72 S */
        "objet de taille zＳo",                         /* 72 S */
        "オブジェクトのサイズがゼロ",                   /* 72 S */
  },
  { "not_struct",
        "not a struct or union type",                   /* 73 S */
        "Nicht vom Typ Struct oder Union",                      /* 73 S */
        "le type n'est pas struct ou union",                    /* 73 S */
        "struct または union ではない",                 /* 73 S */
  },
        /*
           In C++, this can also happen
           when a class member function is forward referenced:
                class Y;                        // forward declaration
                class X { friend void Y::f(); } // error, ARM 11.4
         */
  { "notamember",
        "'%s' is not a member of '%s'",                 /* 74 S */
        "'%s' ist kein Glied des '%s'",                 /* 74 S */
        "'%s' n'appartient pas � la '%s'",              /* 74 S */
        "'%s' は struct '%s' のメンバではない",         /* 74 S */
  },
  { "notamember_alt",
        "'%s' is not a member of '%s', did you mean '%s'?",
  },
  { "bad_ptr_arith",
        "illegal pointer arithmetic",                   /* 75 S */
        "Unzulгsige Pointer-Arithmetik",                       /* 75 S */
        "arithmＵique de pointeur incorrect",                   /* 75 S */
        "不正ポインタ演算",                             /* 75 S */
  },
        /* One of:
                1. Templates can only be declared at global scope. ARM 14.1
                2. Function arguments cannot be static or extern.
                3. Auto or register variables cannot be at global scope.
                4. Typedef in conditional declaration
         */
  { "storage_class",
        "%s storage class is illegal in this context",  /* 47 S */
        "Speicherklasse %s in diesem Kontext unzulгsig",       /* 47 S */
        "classe de stockage %s interdite dans ce contexte",     /* 47 S */
        "ここでは %s の記憶クラスは使えない",           /* 47 S */
  },
  { "storage_class2",
        "%s storage class is illegal for %s",
  },
  { "array_of_funcs",
        "array of functions, references or voids is illegal",   /* 42 S */
        "Array von Funktionen oder Referenzen ung〕tig",        /* 42 S */
        "tableau de fonctions ou de rＧＳences non autoris�",   /* 42 S */
        "関数または参照の配列を宣言できない",                   /* 42 S */
  },
  { "return_type",
        "can't return arrays, functions or abstract classes",   /* 43 S */
        "R…kgabe von Arrays, Funktionen oder abstrakten Klassen nicht m波lich",        /* 43 S */
        "renvoi de tableaux, de fonctions ou de classes abstraites impossible", /* 43 S */
        "配列、関数、抽象クラスを戻り値とすることはできない",   /* 43 S */
  },
  { "body",
        "__body statement expected following __in or __out",
  },
  { "return",
        "__in and __out statements cannot contain return's",
  },
  { // not in errormsgs.html yet
    "complex_operands",
        "operator is not defined for complex operands",
  },
  { // C99 6.7.5.2
    "array_qual",
        "type qualifiers and static can only appear in outermost array of function parameter",
  },

#if TX86
  { "tdb",
        "error accessing type database '%s' %d",                // 196
  },
        // Part of syntax for __try block for Structured Exception Handling.
  { "bad_leave",
        "__leave must be within a __try block",         // TX86+0
        "__leave mu� innerhalb eines '__try'-Blocks sein",              // TX86+0
        "__leave doit se trouver dans un bloc __try",           // TX86+0
  },

        // Part of syntax for __try block for Structured Exception Handling.
  { "finally_or_except",
        "__finally or __except expected",                       // TX86+1
        "__finally oder __except erwartet",                     // TX86+1
        "__finally ou __except requis",                 // TX86+1
  },

        // Structured Exception Handling is only for Win32.
  { "try_needs_win32",
        "__try only valid for -mn memory model",                // TX86+2
        "__try nur g〕tig f〉 Speichermodell -mn",              // TX86+2
        "__try est utilisable uniquement avec le mod獲e de mＮoire -mn",                // TX86+2
  },

        // This is part of Structured Exception Handling.
  { "needs_filter",
        "GetExceptionInformation() only valid in exception filter",     // TX86+3
        "GetExceptionInformation() nur g〕tig in Ausnahmefilter",       // TX86+3
        "GetExceptionInformation() utilisable uniquement dans un filtre d'exceptions",  // TX86+3
  },

        // This is part of Structured Exception Handling.
  { "needs_handler",
        "GetExceptionCode() only valid in exception filter or handler", // TX86+4
        "GetExceptionCode() nur g〕tig in Ausnahmefilter oder Handler", // TX86+4
        "GetExceptionCode() utilisable uniquement dans un filtre ou un gestionnaire d'exceptions",      // TX86+4
  },

        // Supported types are:
        //      __declspec(dllimport)
        //      __declspec(dllexport)
        //      __declspec(naked)
        //      __declspec(thread)
  { "bad_declspec",
        "unsupported __declspec type",                  // TX86+5
        "Nichtunterst》zter __declspec-Typ",                    // TX86+5
        "type __declspec incompatible",                 // TX86+5
  },

        /* Supported based types are:
                __based(__segname("_DATA"))  => __near
                __based(__segname("_STACK")) => __ss
                __based(__segname("_CODE"))  => __cs
        */
  { "bad_based_type",
        "unsupported based type",                       // TX86+6
        "Nichtunterst》zter Based-Typ",                 // TX86+6
        "type based incompatible",                      // TX86+6
        "未サポートの based 型",                        // 167
  },

        // dllimports can only be extern declarations
  { "bad_dllimport",
        "initializer or function body for dllimport not allowed", // TX86+7
        "Initialisierer oder Funktionsrumpf f〉 Dllimport nicht zulгsig", // TX86+7
        "code d'initialisation ou corps de la fonction non autoris� pour dllimport", // TX86+7
  },

        /* _far16 is used only under OS/2 2.0 flat memory model */
  { "far16_model",
        "'_far16' is only valid in -mf memory model",   /* 137  */
        "'_far16' nur g〕tig f〉 Speichermodell -mf",   /* 137  */
        "'_far16' valide uniquement dans le mod獲e de mＮoire -mf",     /* 137  */
        "'_far16' は -mf メモリモデルに限る",           /* 137  */
  },

        /* The compiler cannot generate code for a far16
           function body, only call it.
         */
  { "far16_extern",
        "'_far16' functions can only be extern",        /* 138  */
        "'_far16'-Funktionen k馬nen nur extern sein",   /* 138  */
        "les fonctions '_far16' doivent �tre de type extern",   /* 138  */
        "'_far16' 関数は extern でなければならない",    /* 138  */
  },

        /* alloca() requires that a special stack frame be set
           up which is in conflict with stack frames that Windows
           requires.
         */
  { "alloca_win",
        "alloca() cannot be used in Windows functions", // 151S
        "alloca() kann nicht in Windows-Funktionen benutzt werden",     // 151S
        "allocal() non autoris� dans les fonctions Windows",    // 151S
        "alloca() は Windows 関数では使えない",         // 151S
  },

        // Error messages from the inline assembler.

        // The user has given the incorrect number of operands for
        // the instruction.  Tell them the correct number
  { "nops_expected",                                            // 152
        "%d operands expected for the %s instruction, had %d",
        "%d Operanden erwartet f〉 die %s-Instruktion",
        "'%d' opＳandes l'instruction %s doit comprendre",
        "%d 個のオペランドが必要 (命令:%s)",
  },


        // The user has specified the incorrect size of operand for the
        // instruction.  For instance:
        //      char c;
        //      __asm push c;
        // This would be illegal because the PUSH instruction does
        // not allow for an 8 bit memory operand.
  { "bad_op",
        "Illegal type/size of operands for the %s instruction", // 153 W
        "Unzulгsige(r) Typ/Gr批e der Operanden f〉 die %s-Instruktion",        // 153 W
        "Type/taille des opＳandes incompatible avec l'instruction %s", // 153 W
        "%s 命令のオペランドの型およびサイズが不正",    // 153
  },

        // A non-sensical operand was entered on a floating point instruction
        // for instance:
        //      fdiv    0x50
        // A numeric constant entered into a floating point instrution
  { "bad_float_op",
        "Unknown operand type for this floating point instruction",     // 154
        "Unbekannter Oprendentyp f〉 diese Flie疚omma-Instruktion",     // 154
        "Type d'opＳande incompatible avec une instruction en virgule flottante",       // 154
        "浮動点命令のオペランドタイプが不正",           // 154
  },
        //
        // This covers illegal operands like [ah], etc.
        //
  { "bad_addr_mode",
        "Illegal addressing mode",                              // 155
        "Unzulгsiger Adressierungsmodus",                              // 155
        "Mode d'adressage non valide",                          // 155
        "不正アドレスモード",                           // 155
  },
        //
        // If the ASM keyword is used, an assembler opcode should be the
        // start of each instruction (or a label, or prefix)
        //
  { "opcode_exp",
        "Assembler opcode expected",                            // 156
        "Assembler-Opcode erwartet",                            // 156
        "code opＳation assembleur requis",                             // 156
        "アセンブラのオペコードでなければならない",     // 156
  },
        //
        // When using the LOCK, REP, REPE, REPNE, REPZ instruction
        // prefixes, the opcode must immediately follow them
        //
  { "prefix",
        "Prefix opcode must be followed by an assembler opcode", // 157
        "Assembler-Opcode mu� auf Pr�fix-Opcode folgen", // 157
        "Le code opＳation du prＧixe doit �tre suivi d'un code opＳation assembleur", // 157
        "プレフィックスオペコードにはアセンブラのオペコードが続かなければならない", // 157
  },
        //
        // This error message is used when an expression cannot be
        // evaluated by the inline assembler.  For instance adding two vars
        //      dec a+b
        //
  { "bad_operand",
        "Illegal operand",                                      // 158
        "Unzulгsiger Operand",                                 // 158
        "OpＳande non autorisＦ",                                       // 158
        "不正オペランド",                                       // 158
  },
  { "ptr_exp",
        "Expected assembler directive PTR to follow assembler cast", // 159
        "Erwarte Assembler-Anweisung PTR nach Assembler-Cast", // 159
        "Directive assembleur PTR requise apr郭 cast assembleur", // 159
        "アセンブラキャストにアセンブラ指令 PTR が続かなければならない", // 159
  },
  { "386_op",
        "Reference to '%s' caused a 386 instruction to be generated", // 160W
        "Referenz auf '%s' bewirkte eine 386-Instruktion", // 160W
        "Instruction 386 gＯＳＦ par la rＧＳence � '%'", // 160W
        "'%s' の参照により 386 の命令を生成する",               // 160W
  },

        // Happens if -Wb flag and there is a segment fixup to DGROUP
  { "ds_ne_dgroup",
        "DS is not equal to DGROUP",                    // 170
        "DS ist ungleich DGROUP",                       // 170
        "D S n'est pas Ｈal � DGROUP",                  // 170
        "DS は DGROUP と同じでない",                    // 170
  },
        // Too many debug info types in one module.
  { "2manytypes",
        "max of %d types in debug info exceeded",               // 192 F
  },
  { "nakedret",
        "__declspec(naked) functions can't have return statements",     // 193
  },

        // Cannot #define, #undef or declare global symbols prior
        // to #include'ing a precompiled header.
        // The precompiled header is not used, and the header is reparsed.
  { "before_pch",
        "symbols or macros defined before #include of precompiled header",      // TX86+8 (W20)
        "Symbole oder Makros definiert vor #include des vorkompilierten Header",        // TX86+8
        "symboles ou macros dＧinis avant #include de l'en-t�te prＤompil�",    // TX86+8
  },

        // The #include'ing of a precompiled header must be the first
        // #include, if you are using precompiled headers (-H).
        // The precompiled header is not used, and the header is reparsed.
  { "pch_first",
        "precompiled header must be first #include when -H is used",    // TX86+9 (W21)
  },
  { "thread_and_dllimport",
        "'%s' cannot be both thread and dllimport",             // TX86+10

  },
  { "no_CV3",
        "CV3 debug format is no longer supported",              // TX86+11
  },
  { "mfc",
        "#pragma DMC mfc must be before symbols",
  },

#endif
#if !TX86
  { "cseg_2big",
        "code segment too large",                       /* 151cg F*/
        "Codesegment zu gro�",                  /* 151cg F*/
        "segment de code trop grand",                   /* 151cg F*/
        "コードセグメントが多すぎる",                   /* 151cg F*/
  },
  { "ptr_handle",
        "only pointers to handle based types allowed",  /* 22 S */
        "Nur Pointer auf Handle-basierte Typen zulгsig",  /* 22 S */
        "seuls les pointeurs vers des types � base de descripteur sont permis",  /* 22 S */
  },
#endif
#if TARGET_LINUX || TARGET_OSX || TARGET_FREEBSD || TARGET_OPENBSD || TARGET_SOLARIS
  { "attribute",
        "illegal attribute specification",
        "illegal attribute specification",
        "illegal attribute specification",
  },
  { "skip_attribute",                           /* warning message */
        "skipping attribute specification %s ",
        "skipping attribute specification %s ",
        "skipping attribute specification %s ",
  },
  { "warning_message",                          /* warning message */
        "#%s ",
        "#%s ",
        "#%s ",
  },
  { "bad_vastart",                              /* warning message */
        "second parameter %s of 'va_start' not last named argument",
        "second parameter %s of 'va_start' not last named argument",
        "second parameter %s of 'va_start' not last named argument",
  },
  { "bad_vararg",
        "va_start not used correctly",
        "va_start not used correctly",
        "va_start not used correctly",
  },
  { "undefined_inline",                         /* warning message */
        "static inline %s not defined",
        "static inline %s not defined",
        "static inline %s not defined",
  },
#endif

//////////////////////////////////////////////////////////////////
// C++ messages

        // When initializing a reference, the object being used as
        // an initializer must be of the same type or it must be const.
  { "bad_ref",
        "reference must refer to same type or be const",        // 183
        "Referenz mu� sich auf denselben Typ beziehen oder konstant sein",      // 183
        "la rＧＳence doit porter sur le m�me type ou �tre constante",  // 183
  },
        // Function is declared to return a value, but it returns
        // without specifying a value.
  { "implied_ret",
        "implied return of %s at closing '}' does not return value",    // 177S,W
        "Implizierter R…ksprung bei abschlie疇nder '}' gibt keinen Wert zur…k",       // 177S,W
        "le retour impliqu� par l'accolade '}' ne renvoie pas de valeur",       // 177S,W
  },
        /* ++x is overloaded by operator++()
           x++ is overloaded by operator++(int)
         */
  { "obsolete_inc",
        "using operator++() (or --) instead of missing operator++(int)", /* 140W */
        "Verwende operator++() (oder --) anstelle des fehlenden operator++(int)", /* 140W */
        "utilisation de l'opＳateur ++() (ou --) � la place de l'opＳateur manquant ++(entier)", /* 140W */
        "operator++(int) (または --) がないのでかわりに operator++() を使用する", /* 140W */
  },

        /* The member functions must be const or volatile too.  */
  { "cv_arg",
        "can't pass const/volatile object to non-const/volatile member function",       /* 141T */
        "Kann Const/Volatile-Objekt nicht an Non-Const/Volatile-Gliedfunktion ｜ergeben",       /* 141T */
        "impossible de transmettre un objet constant/volatile � une fonction membre de type diffＳent", /* 141T */
        "const/volatile のオブジェクトを const/volatile でないメンバ関数に渡すことができない",  /* 141T */
  },
        /* The syntax delete [expr] p; is an anachronism, it
           has been superseded by delete [] p; ARM 5.3.4.
         */
  { "obsolete_del",
        "use delete[] rather than delete[expr], expr ignored",  /* 135W */
        "Verwenden Sie delete[] statt delete[expr], Ausdr. wird ignoriert",     /* 135W */
        "utilisez delete[] � la place de delete[expr], expr ignorＦ",   /* 135W */
        "delete[expr] ではなく delete[] を使うべき (expr は無視される)",        /* 135W */
  },
        /* Support for storage management via assignment
           to 'this' is an anachronism and will be removed
           in future versions of the compiler. Use the
           facility for overloading operator new and operator
           delete instead.
         */
  { "assignthis",
        "assignment to 'this' is obsolete, use X::operator new/delete", /* 132W */
        "Zuweisung zu 'this' obsolet, verwenden Sie X::operator new/delete", /* 132W */
        "affectation � 'this' obsol閣e, utilisez X::operator new/delete", /* 132W */
        "'this' への代入の代わりに X::operator new/delete を使うべき", /* 132W */
  },
  { "musthaveinit",
        "trailing parameters must have initializers",
        "Nachfolgende Parameter m《sen initialisiert werden",
        "les param閣res de fin doivent comporter des codes d'initialisation",
        "後続のパラメータには初期化子が必要",
  },

        // ARM 9.6
        // An anonymous union may not have function members.
  { "func_anon_union",
        "function member '%s' can't be in an anonymous union", /* CPP+1 */
        "Funktionsglied '%s' kann nicht in anonymer Union sein", /* CPP+1 */
        "membre de fonction '%s' interdit dans une union anonyme", /* CPP+1 */
        "関数メンバ '%s' を無名 union に含むことはできない", /* CPP+1 */
  },

        /* Static member functions don't have a this. By the same token,
           you cannot call a non-static member function without an
           instance of the class to get the this pointer from.
           Cannot define a non-static class data member
           outside of a class.
         */
  { "no_instance",
        "no instance of class '%s'",                    /* CPP+2 */
        "Keine Instanz der Klasse '%s'",                        /* CPP+2 */
        "aucune occurrence de la classe '%s'",                  /* CPP+2 */
        "クラス '%s' のインスタンスがない",                     /* CPP+2 */
  },

  { "no_template_instance",
        "template %s<> is not instantiated",
  },

        // Can only derive from structs or classes
  { "not_class",
        "'%s' is not a struct or a class",              /* CPP+3 */
        "'%s' ist weder Struct noch Klasse",            /* CPP+3 */
        "'%s' n'est pas une structure ou une classe",           /* CPP+3 */
        "'%s' は struct でもクラスでもない",                    /* CPP+3 */
  },

        /* p->class::member     */
        /* Class must be the same as class p points to or be a public base class of it */
  { "public_base",
        "'%s' must be a public base class of '%s'",     // CPP+4
        "'%s' mu� eine 杷fentliche Basisklasse von '%s' sein",  // CPP+4
        "'%s' doit �tre une classe m較e publique de '%s'",      // CPP+4
        "'%s' は public 基本クラスでなければならない",          /* CPP+4 */
  },

        /* Identifier with type info appended exceeds 127 chars, which  */
        /* is the max length of an identifier.                          */
  { "identifier_too_long",
        "decorated identifier '%s' is %d longer than maximum of %d",
  },

        /* Function %s is overloaded, and the compiler can't find       */
        /* a function which it can coerce the arguments to match        */
  { "nomatch",
        "no match for function '%s%s'",                         /* CPP+7 */
        "Keine Entsprechung f〉 Funktion '%s%s'",                               /* CPP+7 */
        "aucune correspondance pour la fonction'%s%s'",                         /* CPP+7 */
        "関数 '%s%s' に一致するものがない",                     /* CPP+7 */
  },

        /* Not all operators can be overloaded  */
  { "not_overloadable",
        "not an overloadable operator token",           /* CPP+8 */
        "Kein ｜erlagerbares Operator-Token",           /* CPP+8 */
        "il ne s'agit pas d'un tＮoin d'opＳateur chargeable",          /* CPP+8 */
        #pragma dbcs(push,1)
        "オーバーロード可能な演算子ではない",                   /* CPP+8 */
        #pragma dbcs(pop)
  },
  { "opovl_function",
        "operator overload must be a function",         /* CPP+9 */
        "Operator-喘erlagerung mu� eine Funktion sein",         /* CPP+9 */
        "l'appel par opＳateur doit porter sur une fonction",           /* CPP+9 */
        "演算子のオーバーロードは関数でなければならない",       /* CPP+9 */
  },

        /* Operator overloaded functions must be unary, binary or n-ary */
        /* depending on which operator is overloaded. () is n-ary.      */
  { "n_op_params",
        "should be %s parameter(s) for operator",       /* CPP+10 */
        "Es sollten %s Parameter f〉 Operator vorhanden sein",  /* CPP+10 */
        "l'opＳateur devrait comporter %s param閣res",  /* CPP+10 */
        "演算子のパラメータ数は %s でなければならない",         /* CPP+10 */
  },

  /* C++98 13.5-6 says:
   * An operator function shall either be a non-static member function or be a
   * non-member function and have at least one parameter whose type is a class,
   * a reference to a class, an enumeration, or a reference to an enumeration.
   */
  { "param_class",
        "at least one parameter must be a class, class&, enum or enum&",
        "Mindestens ein Parameter mu� Class oder Class& sein",  /* CPP+11 */
        "au moins un param閣re doit �tre une classe ou une class&",     /* CPP+11 */
        "少なくとも１つのパラメターがクラスもしくはクラスの参照でなければならない", /* CPP+11 */
  },
  { "class_colcol",
        "'%s' must be a class name preceding '::'",     /* CPP+12 */
        "'%s' mu� ein Klassenname, gefolgt von '::', sein",     /* CPP+12 */
        "'%s' doit �tre un nom de classe suivi de '::'",        /* CPP+12 */
        "'::' の前の '%s' はクラス名でなければならない",        /* CPP+12 */
  },

        /* When naming members of a base class in a derived class       */
        /* declaration, as in:                                          */
        /*      class abc : def { public: def::a; };                    */
        /* def must be a base class of abc.                             */
  { "base_class",
        "'%s' must be a base class",                    /* CPP+13 */
        "'%s' mu� eine Basisklasse sein",                       /* CPP+13 */
        "'%s' doit �tre une classe m較e",                       /* CPP+13 */
        "'%s' は基本クラスでなければならない",                  /* CPP+13 */
  },

        /* Can only adjust access to members of a base class in a
           derived class to public or protected. ARM 11.3
         */
  { "access_decl",
        "access declaration must be in public or protected section",    /* CPP+14 */
        "Zugriffsdeklaration mu� in 杷fentlichem oder gesch》ztem Abschnitt erfolgen",  /* CPP+14 */
        "la dＤlaration d'acc郭 doit se trouver dans une section publique ou protＨＦ", /* CPP+14 */
        "アクセス宣言は public または protected 部になければならない",  /* CPP+14 */
  },

        /* o    not declaring destructors right                         */
        /* o    declaring constructor as virtual or friend              */
        /* o    declaring destructor as friend                          */
        /* o    specifying return value for constructor or destructor   */
  { "bad_ctor_dtor",
        "illegal constructor or destructor or invariant declaration",   // CPP+15
        "Unzulгsige Constructor- oder Destructor-Deklaration", /* CPP+15 */
        "dＤlaration de constructeur ou de destructeur non valide",     /* CPP+15 */
        #pragma dbcs(push,1)
        "構築子または消滅子の宣言が不正",                       /* CPP+15 */
        #pragma dbcs(pop)
  },

        /* Attempted to reference a member of a class without
           a "this" pointer being available.
         */
  { "no_inst_member",
        "no instance of class '%s' for member '%s'",            /* CPP+16 */
        "Keine Instanz der Klasse '%s' f〉 Glied '%s'",         /* CPP+16 */
        "aucune occurrence de la classe '%s' pour le membre %s",                /* CPP+16 */
        "クラス '%s' のインスタンスをメンバ '%s'では参照できない",      /* CPP+16 */
  },

        /* When a class name appears in an expression, the only
           valid tokens that can follow it are :: and (
         */
  { "colcol_lpar",
        "'::' or '(' expected after class '%s'",        /* CPP+17 */
        "'::' oder '(' erwartet nach Klasse '%s'",      /* CPP+17 */
        "'::' ou '(' requis apr郭 le nom de classe '%s'",       /* CPP+17 */
        "クラス '%s' の次は '::' または '(' でなければならない",        /* CPP+17 */
  },

        /* A user-defined type conversion function was declared outside of a class */
  { "conv_member",
        "type conversions must be members",             /* CPP+18 */
        "Typkonvertierungen m《sen Glieder sein",               /* CPP+18 */
        "les conversions de type doivent �tre des membres",             /* CPP+18 */
        "型変換はメンバでなければならない",             /* CPP+18 */
  },

        /* Can't have constructor as a default function parameter       */
  { "ctor_context",
        "can't handle constructor in this context",     /* CPP+19 */
        "Constructor kann in diesem Kontext nicht behandelt werden",    /* CPP+19 */
        "constructeur non utilisable dans ce contexte", /* CPP+19 */
        #pragma dbcs(push,1)
        "ここで構築子を指定してはならない",             /* CPP+19 */
        #pragma dbcs(pop)
  },

        /* More than one member-initializer appears for member %s.      */
        /* Can't have multiple initializers for the base class          */
  { "seen_init",
        "already seen initializer for '%s'",            /* CPP+20 */
        "Es wurde bereits ein Initialisierer f〉 '%s' angegeben",               /* CPP+20 */
        "code d'initialisation de '%s' dＫ� dＵect�",           /* CPP+20 */
        "'%s' の初期化子が既にある",            /* CPP+20 */
  },

        /* A base class initializer appears for class %s, but there is  */
        /* no base class.                                               */
        /* The member-initializer syntax is not recognized.             */
        /* Can't have explicit initializer for virtual base class.      */
  { "bad_mem_init",
        "bad member-initializer for '%s'",              /* CPP+21 */
        "Ung〕tiger Glied-Initialisierer f〉 '%s'",             /* CPP+21 */
        "code d'initialisation de membre incorrect pour la classe '%s'",                /* CPP+21 */
        "'%s' のメンバ初期化子が不正",          /* CPP+21 */
  },
  { "vector_init",
        "vectors cannot have initializers",             /* CPP+22 */
        "Vektoren k馬nen keine Initialisierer haben",           /* CPP+22 */
        "les vecteurs doivent �tre dＱourvus de code d'initialisation",         /* CPP+22 */
        "ベクトルには初期化子があってはならない",               /* CPP+22 */
  },
  { "del_ptrs",
        "can only delete pointers",                     /* CPP+23 */
        "Nur Pointer k馬nen gel敗cht werden",                   /* CPP+23 */
        "seuls les pointeurs peuvent �tre supprimＴ",                   /* CPP+23 */
        "delete はポインタに限る",                      /* CPP+23 */
  },
  { "ext_inline",
        "storage class for '%s' can't be both extern and inline", /* CPP+24 */
        "Speicherklasse f〉 '%s' kann nicht gleichzeitig extern und inline sein", /* CPP+24 */
        "la classe de stockage de '%s' ne peut pas �tre � la fois extern et inline", /* CPP+24 */
        "'%s' の記憶クラスは同時に extern と inline になっていはならない", /* CPP+24 */
  },
  { "non_static",
        "operator functions -> () and [] must be non-static members",   /* CPP+25 */
        "Operatorfunktionen -> () und [] m《sen nicht-statische Glieder sein",  /* CPP+25 */
        "les opＳateurs ->, () et [] doivent �tre des membres non statiques",   /* CPP+25 */
        "operator ->、()、および [] は static でないメンバでなければならない",  /* CPP+25 */
  },

        /* For member initializers for which the member has no constructor, */
        /* there must be exactly 1 parameter. The member is initialized */
        /* by assignment.                                               */
  { "one_arg",
        "one argument req'd for member initializer for '%s'", /* CPP+26 */
        "Ein Argument erforderl. f〉 Glied-Initialisierer f〉 '%s'", /* CPP+26 */
        "le code d'initialisation des membres de '%s' requiert un argument", /* CPP+26 */
        "'%s' のメンバ初期化子に引数1つが必要",                 /* CPP+26 */
  },
  { "linkage_specs",
        "linkage specs are \"C\", \"C++\", and \"Pascal\", not \"%s\"", // CPP+27
        "Link-Spezifikationen sind \"C\", \"C++\" und \"Pascal\", nicht \"%s\"", // CPP+27
        "les spＤifications de liaison sont \"C\", \"C++\" et \"Pascal\" et non pas  \"%s\"", // CPP+27
        "リンケージタイプは \"%s\" ではなく、\"C\"、\"C++\"、および\"Pascal\" のいずれかでなければならない", /* CPP+27 */
  },

        /* The member name is private or protected      */
  { "not_accessible",
        "member '%s' of class '%s' is not accessible",          /* CPP+28 */
        "Kein Zugriff auf Glied '%s' der Klasse '%s'",          /* CPP+28 */
        "le membre '%s' de la classe '%s' n'est pas accessible",                /* CPP+28 */
        "メンバ '%s' (クラス '%s')はアクセスできない",          /* CPP+28 */
  },

        /* The member name can only be used by member functions and     */
        /* friend functions of the class.                               */
  { "private",
        "member '%s' of class '%s' is private",                 /* CPP+29 */
        "Glied '%s' der Klasse '%s' ist privat",                        /* CPP+29 */
        "le membre '%s' de la classe '%s' est priv�",                   /* CPP+29 */
        "メンバ '%s' (クラス '%s')は private になっている",     /* CPP+29 */
  },

        // ARM 12.1
        // Copy constructors for class X cannot take an argument of type X.
        // Should use reference to X instead
  { "ctor_X",
        "argument of type '%s' to copy constructor",            // CPP+30
        "Argument vom Typ '%s' f〉 Copy Constructor",           // CPP+30
        "utilisez un argument de type '%s' avec le constructeur de copie",              // CPP+30
        #pragma dbcs(push,1)
        "コピー構築子の引数の型 '%s' が不正",           // CPP+30
        #pragma dbcs(pop)
  },

        /* Initializers for static members must be of the form  */
        /*      int classname::member = initializer;            */
  { "static_init_inside",
        "initializer for non-const static member must be outside of class def", /* CPP+31 */
        "Initialiserer f〉 statisches Glied mu� au疇rh. der Klassendef. sein", /* CPP+31 */
        "le code d'initialisation d'un membre statique doit se trouver en dehors de la dＧinition de la classe", /* CPP+31 */
        "static メンバの初期化子はクラスの外でなければならない", /* CPP+31 */
  },

        // Initializers for const static members, when inside
        // a class definition, must be constant.
  { "in_class_init_not_const",
        "in-class initializer for const %s not constant",
  },

        /* Could not find an unambiguous type conversion        */
  { "ambig_type_conv",
        "ambiguous type conversion",                            /* CPP+32 */
        "Typkonvertierung nicht eindeutig",                             /* CPP+32 */
        "la conversion de type est ambigu�",                            /* CPP+32 */
        "型変換があいまい",                             /* CPP+32 */
  },

        /* Cannot directly call a pure virtual function */
  { "pure_virtual",
        "'%s' is a pure virtual function",                      /* CPP+33 */
        "'%s' ist eine reine virtuelle Funktion",                       /* CPP+33 */
        "'%s' est une fonction virtuelle pure",                 /* CPP+33 */
        "'%s' は純粋仮想関数",                          /* CPP+33 */
  },

        // Non-extern consts or references must be initialized.
  { "const_needs_init",
        "const or reference '%s' needs initializer",            // CPP+34
        "Konstante oder Referenz '%s' mu� initialisiert werden",                // CPP+34
        "la constante ou la rＧＳence '%s' doit �tre initialisＦ",              // CPP+34
        "const or reference '%s' は const または参照なので初期化子が必要",              // CPP+34
  },

        /* ARM 3.4      */
  { "main_type",
    #if TX86
        "main(), WinMain() or LibMain() cannot be static or inline",    // CPP+35
        "main(), WinMain() oder LibMain() k馬nen nicht 'static' oder 'inline' sein",    // CPP+35
        "main(), WinMain() et LibMain() ne doivent pas �tre de type static ou inline",  // CPP+35
        "main()、WinMain() および LibMain() は static にも inline にもすることはできない",      // CPP+35
    #else
        "main() cannot be static or inline",                    /* CPP+35 */
        "main() kann nicht 'static' oder 'inline' sein",                        /* CPP+35 */
        "main() ne doit pas �tre de type static ou inline",                     /* CPP+35 */
        "main() は inline にもすることはできない",      // CPP+35
    #endif
  },

        /* Cannot find constructor whose parameters match
           the initializers                             */
  { "no_ctor",
        "cannot find constructor for class matching %s::%s%s",  // CPP+36
        "Kein Constructor f〉 Klasse entsprechend %s::%s%s gefunden",   // CPP+36
        "impossible de trouver un constructeur correspondant � %s::%s%s",       // CPP+36
        #pragma dbcs(push,1)
        "%s::%s%s と一致するクラスの構築子が見つからない",      // CPP+36
        #pragma dbcs(pop)
  },

        /* Base classes cannot appear more than once as a direct base class */
  { "dup_direct_base",
        "duplicate direct base class '%s'",                     /* CPP+37 */
        "Doppelte direkte Basisklasse '%s'",                    /* CPP+37 */
        "classe m較e directe '%s' utilisＦ plus d'une fois",                    /* CPP+37 */
        "直接の基本クラス '%s' が重複している",                 /* CPP+37 */
  },

        /* Can't mix static and virtual storage classes for member functions */
        /* Note that operator new() and operator delete() are static    */
  { "static_virtual",
        "static function '%s' can't be virtual",                /* CPP+38 */
        "Statische Funktion '%s' kann nicht virtuell sein",             /* CPP+38 */
        "la fonction statique '%s' ne doit pas �tre de type virtuel",           /* CPP+38 */
        "static 関数 '%s' は virtual にすることができない",             /* CPP+38 */
  },
  { "opnew_type",
        "type must be void *operator new%s(size_t [,..]);",     /* CPP+39 */
        "Typ mu� void *operator new(size_t [,..]); sein",       /* CPP+39 */
        "le type doit �tre void*opＳateur new(size_t [,..]);",  /* CPP+39 */
        "型は void *operator new(size_t [,..]); でなければならない",    /* CPP+39 */
  },

        /* Type of operator delete() must be one of:    */
        /*      void operator delete(void *);           */
        /*      void operator delete(void *,size_t);    */
        /*      void operator delete(void *,void *);    */
  { "opdel_type",
        "must be void operator delete%s(void * [,size_t]);",    /* CPP+40 */
        "mu� lauten void operator delete(void * [,size_t]);",   /* CPP+40 */
        "doit �tre void*opＳateur delete(void * [,size_t]);",   /* CPP+40 */
        "void operator delete(void * [,size_t]); でなければならない",   /* CPP+40 */
  },

        /* Syntax for pure virtual function is          */
        /*      virtual func() = 0;                     */
  { "zero",
        "0 expected",                                           /* CPP+41 */
        "0 erwartet",                                           /* CPP+41 */
        "zＳo requis",                                          /* CPP+41 */
        "0 でなければならない",                                         /* CPP+41 */
  },
  { "create_abstract",
        "cannot create instance of abstract class '%s'",        /* CPP+42 */
        "Instanz der abstrakten Klasse '%s' kann nicht erzeugt werden", /* CPP+42 */
        "impossible de crＦr une occurrence de la classe abstraite '%'",        /* CPP+42 */
        "抽象クラス '%s' のインスタンスを作成することはできない",       /* CPP+42 */
  },

        /* Can't generate X& operator=(X&) if           */
        /*      1. class has a member of a class with   */
        /*         a private operator=()                */
        /*      2. class is derived from a class with   */
        /*         a private operator=()                */
  { "cant_generate",
        "cannot generate %s for class '%s'",            /* CPP+43 */
        "%s kann f〉 Klasse '%s' nicht erzeugt werden",         /* CPP+43 */
        "impossible de gＯＳer %s pour la classe '%s'",         /* CPP+43 */
        "%s を生成できない (クラス '%s')",              /* CPP+43 */
  },

        /* Can't generate X& operator=(X&) if           */
        /*      1. class has a const member or base     */
        /*      2. class has a reference member         */
  { "cant_generate_const",
        "cannot generate operator=() for class '%s', member '%s' is %s",
  },

        /* Base and member initializers only allowed    */
        /* for functions that are constructors.         */
  { "not_ctor",
        "'%s' is not a constructor",                    /* CPP+44 */
        "'%s' ist kein Constructor",                    /* CPP+44 */
        "'%s' n'est pas un constructeur",                       /* CPP+44 */
        #pragma dbcs(push,1)
        "'%s' は構築子ではない",                        /* CPP+44 */
        #pragma dbcs(pop)
  },
  { "base_memmodel",
        "base class '%s' has different ambient memory model",   /* CPP+45 */
        "Basisklasse '%s' hat andere Speichermodellumgebung",   /* CPP+45 */
        "la classe m較e '%s' n'utilise pas le m�me mod獲e de mＮoire",  /* CPP+45 */
        "基本クラス '%s' のメモリモデルと矛盾している", /* CPP+45 */
  },

        /* Can't have a near reference to far data      */
  { "near2far",
        "'%s' is far",                                  /* CPP+46 */
        "'%s' ist Far",                                 /* CPP+46 */
        "'%s' est de type far",                                 /* CPP+46 */
        "'%s' は far になっている",                                     /* CPP+46 */
  },

        /* operator->() must return:
            1. a pointer to a class object
            2. an object of a class with operator->() defined
            3. a reference to an object of a class with operator->() defined
           If 2 or 3, then the class cannot be the same as
           the class for which operator->() is a member.
           ARM 13.4.6
         */
  { "bad_oparrow",
        "illegal return type %s for operator->()",              /* CPP+47 */
        "Unzulгsiger R…kgabetyp f〉 Operator->()",            /* CPP+47 */
        "ＭＮent renvoy� incompatible avec l'opＳateur ->[]",           /* CPP+47 */
        "operator->() の戻り型が不正",          /* CPP+47 */
  },

        /* Can't redefine default argument for parameter */
        /* even if it's to the same value. Sometimes the */
        /* line number indicated for the error is past   */
        /* the closing brace of the body of the function */
  { "default_redef",
        "redefinition of default value for parameter '%s'",     // CPP+48
        "Redefinition von Standardparametern",          /* CPP+48 */
        "modification de la dＧinition du param閣re par dＧaut",        // CPP+48
        "デフォルトパラメータを再定義できない",         /* CPP+48 */
  },

        /* If you define a variable with the same name
         * as a class, that class cannot have any
         * constructors
         * Why?
         * Also, see different usage in symbol.c.
         */
  { "ctor_disallowed",
        "no constructor allowed for class '%s'",        /* CPP+49 */
        "Kein Constructor zulгsig f〉 Klasse '%s'",    /* CPP+49 */
        "constructeur non utilisable avec la classe '%s'",      /* CPP+49 */
        #pragma dbcs(push,1)
        "クラス '%s' には構築子を定義できない", /* CPP+49 */
        #pragma dbcs(pop)
  },

        /* If multiple classes exist as base classes, and it is         */
        /* ambiguous which is referred to.                              */
  { "ambig_ref_base",
        "ambiguous reference to base class '%s'",       /* CPP+50 */
        "Mehrdeutige Referenz auf Basisklasse '%s'",    /* CPP+50 */
        "rＧＳence � la classe m較e ambigu� '%s'",      /* CPP+50 */
        "基本クラス '%s' の参照があいまい",     /* CPP+50 */
  },

        /* Pure member functions must be virtual, as in: */
        /*      virtual void func() = 0;                 */
  { "pure_func_virtual",
        "pure function must be virtual",                /* CPP+51 */
        "Reine Funktion mu� virtuell sein",             /* CPP+51 */
        "la fonction pure doit �tre virtuelle",         /* CPP+51 */
        "純粋関数は仮想にもしなければならない",         /* CPP+51 */
  },

        /* Cannot convert a pointer to a virtual base   */
        /* into a pointer to a class derived from it.   */
        /* Cannot create a pointer to a member of a     */
        /* virtual base class.                          */
  { "vbase",
        "'%s' is a virtual base class of '%s'",         /* CPP+52 */
        "'%s' ist eine virtuelle Basisklasse von '%s'",         /* CPP+52 */
        "'%s' est une classe m較e virtuelle de '%s'",           /* CPP+52 */
        "'%s' は '%s' の仮想基本クラスになっている",            /* CPP+52 */
  },

        /* An object of a class with a constructor or   */
        /* a destructor may not be a member of a union. */
  { "union_tors",
        "union members cannot have ctors or dtors",     /* CPP+53 */
        "Union-Glieder k馬nen keine Ctors oder Dtors haben",    /* CPP+53 */
        "les membres d'une union ne doivent pas comporter de ctor ou de dtor",  /* CPP+53 */
        #pragma dbcs(push,1)
        "union には構築子または消滅子のあるものを含むことはできない",   /* CPP+53 */
        #pragma dbcs(pop)
  },

        /* The second operand of the binary operators   */
        /* .* and ->* must be a pointer to member       */
  { "ptr_member",
        "pointer to member expected to right of .* or ->*",     /* CPP+54 */
        "Pointer auf Glied rechts von .* oder ->* erwartet",    /* CPP+54 */
        "pointeur vers un membre requis � droite de . * ou ->*",        /* CPP+54 */
        ".*、->* の次はメンバへのポインタでなければならない",   /* CPP+54 */
  },

        /* Access declarations in a derived class cannot
           be used to grant access to an
           otherwise inaccessible member of a base class,
           and cannot restrict access to an otherwise
           accessible member of a base class. ARM 11.3  */
  { "change_access",
        "cannot raise or lower access to base member '%s'",     /* CPP+55 */
        "Zugriff auf Basisglied '%s' kann nicht angehoben oder gesenkt werden", /* CPP+55 */
        "impossible d'augmenter ou de baisser le niveau d'acc郭 au membre parent '%s'", /* CPP+55 */
        "ベースメンバ '%s' のアクセスを変更できない",   /* CPP+55 */
  },

        /*  Cannot convert a pointer to a class X to a pointer
            to a private base class Y unless function is a member or
            a friend of X.
         */
  { "cvt_private_base",
        "cannot convert %s* to a private base class %s*",       /* CPP+56 */
        "%s* kann nicht in eine private Basisklasse %s* konvertiert werden",    /* CPP+56 */
        "impossible de convertir %s* en classe m較e privＦ %s*",        /* CPP+56 */
        "%s* を private 基本クラス %s* に変換できない", /* CPP+56 */
  },

        // ARM 9.5
  { "glbl_ambig_unions",
        "global anonymous unions must be static",               // CPP+57
        "Globale anonyme Unions m《sen statisch sein",          // CPP+57
        "les unions anonymes globales doivent �tre statiques",          // CPP+57
        "グローバルの無名 union は static でなければならない",          // CPP+57
  },

        /* The member cannot be initialized without a constructor */
  { "const_mem_ctor",
        "member '%s' is const but there is no constructor",     /* CPP+58 */
        "Glied '%s' ist eine Konstante, aber es gibt keinen Constructor",       /* CPP+58 */
        "le membre '%s' est une constante mais aucun constructeur n'est prＴent",       /* CPP+58 */
        #pragma dbcs(push,1)
        "メンバ '%s' が const なのに構築子がない",      /* CPP+58 */
        #pragma dbcs(pop)
  },
  { "static_mem_func",
        "member functions cannot be static",                    /* CPP+59 */
        "Gliedfunktionen k馬nen nicht statisch sein",                   /* CPP+59 */
        "les fonctions membres ne doivent pas �tre statiques",                  /* CPP+59 */
        "メンバ関数は static になってはならない",                       /* CPP+59 */
  },

        /* More than one match is found for overloaded function */
  { "overload_ambig",
        "ambiguous reference to symbol",                        /* CPP+60 */
        "Mehrdeutige Referenz auf Funktion",                    /* CPP+60 */
        "rＧＳence ambigu� � la fonction",                      /* CPP+60 */
        "関数への参照があいまい",                       /* CPP+60 */
  },

        /* ARM 13.4.7 only allows declarations of the form:
           operator ++()
           operator ++(int)
           operator --()
           operator --(int)
         */
  { "postfix_arg",
        "argument to postfix ++ or -- must be int",             /* CPP+61 */
        "Argument des Postfix ++ oder -- mu� Int sein",         /* CPP+61 */
        "l'argument de l'opＳateur ++ ou -- doit �tre un entier",               /* CPP+61 */
        "後置き ++ または -- の引数は int に限る",              /* CPP+61 */
  },
  { "cv_func",
        "static or non-member functions can't be const or volatile", /* CPP+62 */
        "Statische oder Nicht-Glied-Funktionen k馬nen nicht 'const' oder 'volatile' sein", /* CPP+62 */
        "les fonctions statiques ou non membres ne doivent pas �tre de type constant ou volatile", /* CPP+62 */
        "static および非メンバ関数は const または volatile になっていてはならない", /* CPP+62 */
  },

        /* Cannot specify a storage class or a type when
           adjusting the access to a member of a base class.
           ARM 11.3.
         */
  { "access_class",
        "access declaration of base member '%s::%s' has storage class or type", /* CPP+63 */
        "Kennzeichner oder Typ in Zugriffsdeklaration",         /* CPP+63 */
        "qualificateur ou type prＴent dans la dＤlaration d'acc郭",            /* CPP+63 */
        "アクセス宣言には修飾子および型を指定してはならない",           /* CPP+63 */
  },

        /* Can't adjust access for overloaded function
           that has different access levels. ARM 11.3.
         */
  { "access_diff",
        "overloaded function '%s' has different access levels", /* CPP+64 */
        "喘erlagerte Funktion '%s' hat unterschiedl. Zugriffsebenen",   /* CPP+64 */
        "le niveau d'acc郭 de la fonction '%s' appelＦ est diffＳent",  /* CPP+64 */
        "オーバーロード関数 '%s' のアクセスレベルがまちまち",   /* CPP+64 */
  },

        /* Can't adjust access for base member when a derived
           class defines a member with the same name. ARM 11.3
         */
  { "derived_class_name",
        "a derived class member has the same name '%s'",        /* CPP+65 */
        "Ein abgeleitetes Klassenglied hat denselben Namen: '%s'",      /* CPP+65 */
        "un membre dＳiv� de la classe s'appelle Ｈalement '%s'",       /* CPP+65 */
        "同じ名称 '%s' を持つ派生クラスメンバが存在する",       /* CPP+65 */
  },

        /* Had a class name preceding the member function
           name
         */
  { "decl_other_class",
        "can't declare member of another class '%s'",           /* CPP+66 */
        "Glied einer weiteren Klasse '%s' kann nicht deklariert werden",                /* CPP+66 */
        "impossible de dＤlarer le membre d'une autre classe '%s'",             /* CPP+66 */
        " 別のクラス '%s' のメンバを宣言できない",              /* CPP+66 */
  },
  { "friend_sclass",
        "invalid storage class for friend",                     /* CPP+67 */
        "Ung〕tige Speicherklassse f〉 Friend",                 /* CPP+67 */
        "classe de stockage amie non valide",                   /* CPP+67 */
        "friend にはこの保存クラスを使えない",                  /* CPP+67 */
  },
  { "friend_type",
        "only classes and functions can be friends",            /* CPP+68 */
        "Nur Klassen und Funktionen k馬nen Friends sein",               /* CPP+68 */
        "seules les classes et les fonctions peuvent �tre des amies",           /* CPP+68 */
        "friend はクラスおよび関数に限る",                      /* CPP+68 */
  },

        /* Destructors are of the form X::~X()  */
  { "tilde_class",
        "class name '%s' expected after ~",                     /* CPP+69 */
        "Klassenname '%s' erwartet nach ~",                     /* CPP+69 */
        "nom de classe '%s' requis apr郭 ~",                    /* CPP+69 */
        "「~」にクラス名 '%s' が続かなければならない",                  /* CPP+69 */
  },
  { "not_enum_member",
        "'%s' is not a member of enum '%s'",                    // CPP+70
        "'%s' ist kein Glied von Enum '%s'",                    // CPP+70
        "'%s' n'est pas membre de l'ensemble enum '%s'",                        // CPP+70
        "'%s' は enum '%s' のメンバでない",                     // CPP+87
  },

        // ARM 6.7
        // A goto or case statement has allowed an explicit or implicit
        // initialization of a variable to be skipped.
  { "skip_init",
        "initialization of '%s' is skipped",                    // CPP+71
        "Initialisierung von '%s' wird ｜ergangen",                     // CPP+71
        "'%s' n'a pas Ｕ� initialis�",                  // CPP+71
        "'%s'の初期化を無視",                                   // CPP+71
  },
  { "fwd_ref_base",
        "forward referenced class '%s' cannot be a base class", /* CPP+72 */
        "Vorausreferenzierte Klasse '%s' kann keine Basisklasse sein",  /* CPP+72 */
        "la classe '%s' rＧＳencＦ en avant ne doit pas �tre une classe m較e",  /* CPP+72 */
        "クラス '%s' は前方参照されているので基本クラスとすることはできない",   /* CPP+72 */
  },

        // ARM 5.2
        // A type-id in < > is expected following static_cast,
        // const_cast, reinterpret_cast, or dynamic_cast.
  { "lt_cast",
        "'<' expected following cast",                  // CPP+73
        "'<' erwartet nach Cast",                       // CPP+73
        "'<' requis apr郭 cast",                        // CPP+73
        "'<' でなければならない",                                       /* CPP+73       */
  },
  { "gt",
        "'>' expected",                                 // CPP+74
        "'>' erwartet",                                 // CPP+74
        "'>' requis",                                   // CPP+74
        "'>' でなければならない",                                       /* CPP+74       */
  },
  { "templ_param_lists",
        "parameter lists do not match for template '%s'", /* CPP+75     */
        "Parameterlisten entsprechen nicht der Schablone '%s'", /* CPP+75       */
        "les listes de param閣res du squelette '%s' ne correspondent pas", /* CPP+75    */
        "テンプレート '%s' のパラメータリストが一致しない", /* CPP+75   */
  },
        /* A template member function must have a class name
           that is a template.
           A class tag name followed by < must actually be
           a template name.
         */
  { "not_class_templ",
        "'%s' is not a class template",                 /* CPP+76 */
        "'%s' ist keine Klassenschablone",                      /* CPP+76 */
        "'%s' n'est pas le nom d'un squelette de classe",                       /* CPP+76 */
        "'%s' はクラステンプレートではない",                    /* CPP+76 */
  },
  { "bad_templ_decl",
        "malformed template declaration",               /* CPP+77 */
        "Fasche Form der Schablonendeklaration",                /* CPP+77 */
        "dＤlaration de squelette incorrecte",          /* CPP+77 */
        "テンプレート宣言がおかしい",           /* CPP+77 */
  },

        /* All template-arguments for a function must be type-arguments. ARM 14.4 */
  { "templ_arg_type",
        "template-argument '%s' for function must be a type-argument", // CPP+78
        "Schablonenargument '%s' mu� ein Typargument sein",     /* CPP+78 */
        "l'argument de squelette '%s' doit �tre un argument de type",   /* CPP+78 */
        "テンプレート引数 '%s' は型引数でなければならない",     /* CPP+78 */
  },

        /* ARM 5.3.4    */
  { "adel_array",
        "must use delete[] for arrays",                 /* CPP+79 */
        "F〉 Arrays mu� delete[] verwendet werden",                     /* CPP+79 */
        "delete[] obligatoire avec les tableaux",                       /* CPP+79 */
        "配列には delete[] を使わなければならない",                     /* CPP+79 */
  },

        /* ARM 9.4      */
  { "local_static",
    #if TX86
        "local class cannot have static data member '%s'",      /* CPP+80 */
        "Lokale Klasse kann kein statisches Datenglied '%s' haben",     /* CPP+80 */
        "une classe locale ne doit pas comporter de membre de type donnＦ statique",    /* CPP+80 */
        "ローカルクラスには static データメンバ '%s' を含むことはできない",     /* CPP+80 */
    #else
        "local class cannot have static data or non-inline function member '%s'",       /* CPP+80 */
        "Lok. Klasse kann kein stat. oder nicht-inline Funktionsglied '%s' haben",      /* CPP+80 */
        "une classe locale ne doit pas comporter de membre de type donnＦ statique ou fonction non inline",     /* CPP+80 */
    #endif
  },

        /* ARM 12.3.2
           char *operator char *();     // error
           operator char *();           // ok
         */
  { "conv_ret",
        "return type cannot be specified for conversion function", /* CPP+81 */
        "F〉 Konvertierungsfunktion kann kein R…kgabetyp angegeben werden", /* CPP+81 */
        "le type renvoy� ne peut pas �tre associ� � la fonction de conversion", /* CPP+81 */
        "変換関数の戻り型を指定してはならない", /* CPP+81 */
  },

        /* CPP98 14.8.2
           When instantiated, all template-arguments must have values.
         */
  { "templ_arg_unused",
        "template-argument '%s' has no value in template function specialization", /* CPP+82 */
        "Schablonenargument '%s' nicht benutzt bei Funktionsparametertypen", /* CPP+82 */
        "argument de squelette '%' non utilis� avec les types de param閣res de fonction", /* CPP+82 */
        "テンプレート引数 '%s' は関数パラメータ型に使われていない", /* CPP+82 */
  },
  { "cant_gen_templ_inst",
        "cannot generate template instance from -XI%s", /* CPP+83 */
        "Schabloneninstanz von -XI%s kann nicht erstellt werden",       /* CPP+83 */
        "impossible de gＯＳer une instance de squelette � partir de -XI%s",    /* CPP+83 */
        "-XI%s からテンプレートのインスタンスを生成できない",   /* CPP+83 */
  },

        /* ARM 8.4.3
           Caused by trying to initialize:
           o    a volatile reference to a const
           o    a const reference to a volatile
           o    a plain reference to a const or volatile
         */
  { "bad_ref_init",
        "invalid reference initialization",             /* CPP+84 */
        "Ung〕tige Referenzinitialisierung",            /* CPP+84 */
        "initialisation incorrecte de la rＧＳence",            /* CPP+84 */
        "参照の初期化が不正",           /* CPP+84 */
  },

        /* ARM 12.6.2 Can only initialize non-static members
           in the constructor initializer.
         */
  { "no_mem_init",
        "cannot have member initializer for '%s'",      /* CPP+85 */
        "Gliedinitialisierer f〉 '%s' nicht m波lich",   /* CPP+85 */
        "'%s' ne doit pas comporter de membre d'initialisation",        /* CPP+85 */
        "'%s' にメンバ初期化子を指定できない",  /* CPP+85 */
  },
#if 0 // allowed by CPP98
        // ARM 5.3.4
  { "del_ptr_const",
        "cannot delete pointer to const",               /* CPP+86 */
        "Pointer auf Konstante kann nicht gel敗cht werden",             /* CPP+86 */
        "impossible de supprimer le pointeur vers la constante",                /* CPP+86 */
        "const へのポインタを delete できない",         /* CPP+86 */
  },
#endif
#if TX86
  { "colcol_exp",
        "'::' expected",                                // CPP+89
        "'::' erwartet",                                // CPP+89
        "'::' requis",                                  // CPP+89
        "'::' がありません",                            // CPP+89
  },
#else
  { "ptr_ref",
        "pointers and references to references are illegal", /* CPP+97 */
        "Pointer und Referenzen auf Referenzen unzulгsig", /* CPP+97 */
        "un pointeur ou une rＧＳence ne doit pas indiquer une autre rＧＳence", /* CPP+97 */
  },
  { "mult_decl",
        "Only one identifier is allowed to appear in a declaration appearing in a conditional expression", /* CPP+98 */
        "Nur ein Bezeichner erlaubt in Deklaration in konditionalem Ausdruck", /* CPP+98 */
        "Un seul identificateur autoris� dans une dＤlaration figurant dans une expression conditionnelle", /* CPP+98 */
  },
#endif
        // ARM 15.4
        // void func() throw(int);
        // void func() throw(unsigned); <- error, different specification
  { "exception_specs",
        "Exception specifications must match exactly for each declaration of a function", // CPP+99
        "Ausnahmespezifikationen m《sen f〉 jede Deklaration einer Funktion genau ｜ereinstimmen", // CPP+99
        "Les spＤifications d'exception doivent �tre identiques pour toutes les dＤlarations d'une fonction", // CPP+99
  },

        // ARM 15.4
        // Can't have void func() throw(int,int);
  { "eh_types",
        "Types may not appear more than once in an exception specification", // CPP+100
        "Typen k馬nen in Ausnahmespezifikation nur einmal auftreten", // CPP+100
        "Les types ne doivent figurer qu'une seule fois dans une spＤification d'exception", // CPP+100
  },

        // ARM 15.3
        //  o   catch type appears more than once
        //  o   base class appears before derived class
        //  o   ptr/ref to base class appears before ptr/ref derived
  { "catch_masked",
        "Catch type masked by previous catch",          // CPP+101
        "Catch-Typ maskiert durch fr”eren Catch",              // CPP+101
        "Type catch masqu� par catch prＤＥent",                // CPP+101
  },

        // ARM 15.3
        // catch(...) must appear as the last catch in a list
        // of catch handlers for a try-block.
  { "catch_ellipsis",
        "A '...' handler must be the last one for a try-block", // CPP+102
        "Ein '...'-Handler mu� der letzte in einem Try-Block sein", // CPP+102
        "Le gestionnaire '...' doit �tre le dernier du bloc try", // CPP+102
  },

        // ARM 15.1
        // The normal syntax for a catch is:
        // try { statements } catch (exception-declaration) { statements }
  { "catch_follows",
        "A catch must follow a try-block",                      // CPP+103
        "Ein Catch mu� auf einen Try-Block folgen",                     // CPP+103
        "Un catch ne doit pas suivre un bloc try",                      // CPP+103
  },

        // Cannot throw near classes in large data models, and
        // cannot throw far classes in small data models.
  { "not_of_ambient_model",
        "Cannot throw object of '%s' not of ambient memory model", // CPP+104
        "Kann Objekt von '%s' nicht ｜ertragen, da nicht vom umgebenden Speichermodell", // CPP+104
        "Throw d'un objet de '%s' impossible, mod獲e de mＮoire incompatible", // CPP+104
  },
  { "compileEH",
        "Compile all files with -Ae to support exception handling",     // CPP+105
        "Alle Dateien mit -EH kompilieren zur Unterst》zung der Ausnahmebehandlung",    // CPP+105
        "Compilez tous les fichiers avec -EH pour assurer la gestion des exceptions",   // CPP+105
  },
  { "typeinfo_h",
        "#include <typeinfo.h> in order to use RTTI",           // CPP+106
        "#include <typeinfo.h> f〉 Verwendung von RTTI",                // CPP+106
        "#include <typeinfo.h> pour utiliser RTTI",             // CPP+106
  },
  { "compileRTTI",
        "compile all files with -Ar to support RTTI",           // CPP+107
        "Alle Dateien mit -ER kompilieren zur Unterst》zung von RTTI",          // CPP+107
        "Compilez tous les fichiers avec -ER pour gＳer RTTI",          // CPP+107
  },

        // ARM 5.2.6
        // This is refering to the type specified in a dynamic_cast.
  { "ptr_to_class",
        "type must be a pointer or a reference to a defined class or void*",    // CPP+108
        "Typ mu� Pointer oder Referenz auf definierte Klasse oder void* sein",  // CPP+108
        "le type doit �tre un pointeur ou une rＧＳence indiquant une classe dＧinie ou void*", // CPP+108
  },

        // ARM 5.2.6
        // The expression of:
        //      dynamic_cast < type-name > ( expression )
        // must be a pointer.
  { "not_pointer",
        "expression must be a pointer",                 // CPP+109
        "Ausdruck mu� ein Pointer sein",                        // CPP+109
        "l'expression doit �tre un pointeur",                   // CPP+109
  },

        // ARM 5.2.6
        // Invalid use of dynamic_cast.
        // A polymorphic type is a class with at least one virtual function.
  { "ptr_to_polymorph",
        "expression must be a pointer or reference to a polymorphic type",      // CPP+110
        "Ausdruck mu� Pointer oder Referenz auf polymorphen Typ sein",  // CPP+110
        "l'expression doit �tre un pointeur ou une rＧＳence indiquant un type polymorphe",     // CPP+110
  },

        // Template argument list required and is surrounded by <>. ARM 14.1
  { "lt_following",
        "'<' expected following %s",                    // CPP+111
        "'<' erwartet nach %s",                         // CPP+111
        "'<' requis apr郭'%'",                          // CPP+111
  },

        // When expanding a template, a template argument needs
        // a value.
  { "no_type",
        "no type for argument '%s'",                            // CPP+113
  },
  { "templ_default_args",
        "template default args not supported",          // CPP+114
  },

        /* Can't generate X::X(X&) if
         *      1. class has a member of a class with
         *         a private copy constructor
         *      2. class is derived from a class with
         *         a private copy constructor
         */
  { "nogen_cpct",
        "cannot generate copy constructor for class '%s' because of private '%s'",      // CPP+115
  },

        // ARM 8.3
  { "mem_init_following",
        "function body or member initializer expected following declaration of '%s'",   // CPP+116
  },

        // ARM 14.2
  { "semi_template",
        "';' expected following declaration of class template '%s'",    // CPP+117
  },

        // A common error is to forget to close a class definition
        // with a ;
  { "semi_rbra",
        "';' expected following '}' of definition of class '%s'", // CPP+118
  },
        // The macro _ENABLE_ARRAYNEW is predefined to 1 if -Aa is thrown
        // to be used for #if workarounds for various compilers.
  { "enable_anew",
        "use -Aa to enable overloading operator new[] and operator delete[]",   // CPP+120
  },
  { "type_argument",
        "type-argument expected for parameter '%s' of template '%s'", // CPP+121
  },

        // ANSI C++98 14.1
        // For example:
        // template <double d> class A;
  { "param_no_float",
        "non-type template-parameter '%s' may not be a floating point, class, or void type",    // CPP+122
  },

        // C++98 10.3-5
        // "The return type of an overriding function shall be either
        // identical to the return type of the overridden function or
        // covariant with the classes of the functions"
  { "diff_ret_type",
        "return type of overriding function '%s' differs from that of '%s'", // CPP+123
  },

        // ANSI C++ 7.3.2
  { "nspace_alias_semi",
        "';' expected following namespace alias definition",    // CPP+124
  },

        // ANSI C++ 7.3.2
  { "nspace_name",
        "'%s' is not a namespace name",                 // CPP+125
  },
  { "nspace_undef_id",
        "'%s' is not a member of namespace '%s'",               // CPP+126
  },

  { "using_semi",
        "';' expected to close using-%s",                       // CPP+128
  },

        // ANSI C++ 7.3.3
  { "using_member",
        "'%s' is a member, and this is not a member declaration",       // CPP+129
  },
        /* ARM 4.7 and 8.5.3
           A temporary was generated and the reference was
           initialized to that temporary. Since the reference
           was not const, the referenced temporary may change
           its value. This can lead to unexpected behavior. This
           is an error per the ARM, and will be an error in future
           versions of the compiler. ARM 8.4.3
           This is an error, not a warning, if the -A (ANSI C++)
           compiler switch is used.
         */
  { "init2tmp",
        "non-const reference initialized to temporary", /* 60 W */
        "Nicht konstante Referenz als temporв initialisiert",  /* 60 W */
        "rＧＳence non constante initialisＦ � une valeur temporaire",  /* 60 W */
        "非 const の参照を一時変数に初期化する",        /* 60 W */
  },
  // CPP98 14.6.3
  // typename should be followed by :: or nested-name-specifier
  { "nested_name_specifier",
        "nested-name-specifier expected following typename",
  },
  // CPP98 14.6.5
  { "no_typename",
        "typename can only be used in templates",
  },
  // CPP98 7.1.2.6
  { "explicit",
        "explicit is only for constructor declarations",
  },
  // CPP98 12.3.1.2
  { "explicit_ctor",
        "no implicit conversion with explicit constructor",
  },
  // CPP98 7.1.1.8
  { "mutable",
        "mutable is only for non-static, non-const, non-reference data members",
  },
  { "typename_expected",
        "%s is expected to be a typename member of %s",
  },
  // Use one scheme or the other
  { "mix_EH",
        "cannot mix C++ EH with NT structured EH",              // CPP+112
        "C++ EH kann nicht mit NT-Strukturiertem EH vermischt werden",          // CPP+112
        "impossible d'utiliser EH de C++ et EH structur� de NT ensemble",               // CPP+112
  },
  // CPP98 14.5.4-1
  { "primary_template_first",
        "Primary template '%s' must be declared before any specializations",
  },
  // CPP98 14.5.4-10 "The template parameter list of a specialization
  // shall not contain default template argument values."
  { "no_default_template_arguments",
        "class template partial specialization parameter lists cannot have defaults",
  },
  // CPP98 14.5.4-9 "The argument list of the specialization shall
  // not be identical to the implicit argument list of the primary
  // template."
  { "identical_args",
        "specialization arguments for template '%s' match primary",
  },
  // CPP98 14.5.4-9: "A partially specialized non-type argument expression shall not
  // involve a template parameter of the partial specialization except when
  // the argument expression is a simple identifier."
  { "not_simple_id",
        "non-type argument expression with template parameter '%s' is not a simple identifier",
  },
  // CPP98 14.5.4.1-1 More than one matching specialization is found,
  // and one is not more specialized than the other.
  { "ambiguous_partial",
        "ambiguous match of class template partial specialization '%s'",
  },
  // CPP98 5.2.10-2 "the reinterpret_cast operator shall not
  // cast away constness."
  { "no_castaway",
        "reinterpret_cast cannot cast away constness",
  },
  // Warn about C style casts.
  { "ccast",
        "C style cast",
  },
  // Need to implement this
  { "covariant",
        "covariant return type of '%s' with multiple inheritance not implemented",
  },
  // CPP98 7.3.1-4 "Every namespace-definition shall appear in the global
  // scope or in a namespace scope."
  { "namespace_scope",
        "namespace definition not in global or namespace scope",
  },
  // CPP98 7.3.1.2-2 "...the definition appears after the point of declaration
  // in a namespace that encloses the declaration's namespace."
  { "namespace_enclose",
        "namespace '%s' does not enclose member '%s' of namespace '%s'",
  },
  // CPP98 7.3.3-5 "A using-declaration shall not name a template-id."
  { "using_declaration_template_id",
        "using-declaration cannot name template-id '%s'",
  },
  // Warning about using obsolete features
  {
    "obsolete",
        "%s is obsolete, us %s instead",
  },
  // CPP98 14.7.2 Explicit instantiation
   { "malformed_explicit_instantiation",
        "unrecognized explicit instantiation",
   },
   { "should_be_static",
        "dynamically initialized global variable '%s' should be static",
   },
   { "member_auto",
        "class member %s cannot have auto storage class",
   },
   { "template_expected",
        "template id expected following template keyword",
   },
   { "no_vla_dtor",
        "variable length arrays cannot have destructors",
   },
   // CPP98 14.1-1
   { "class_expected",
        "'class' expected following 'template <template-parameter-list>'",
   },
   // CPP98 14.3.3-1
   { "class_template_expected",
        "template-template-argument '%s' must be the name of a class template",
   },
   { "declarator_paren_expected",
        "closing ')' of '( declarator )' expected",
   },
   { "simple_dtor",
        "invalid simple type name destructor",
   },
   /* CPP98 15-2 "A goto, break, return, or continue statement can be used to
    * transfer control out of a try block or handler, but not into one."
    */
   { "gotoforward",
        "cannot goto into try block or catch handler at label '%s'",
   },
   /* CPP98 13.4
    */
   { "ptmsyntax",
        "cannot parenthesize pointer to non-static member &(%s)",
   },
   /*
    */
   { "nonlocal_auto",
        "variable '%s' is not accessible from this function",
   },
   /* CPP98 8.3.6-7
    */
   { "nolocal_defargexp",
        "local '%s' cannot be used in default argument expression",
   },
   /* CPP98 7.1.3-4
    */
   { "notypedef",
        "typedef name '%s' cannot be used following class-key",
   },
   /* CPP98 7.1.3-4
    */
   { "noreturntype",
        "return type for function '%s' not specified",
   },
   /* CPP98 11.?
    */
   { "change_access2",
        "cannot change access of member %s::%s",
   },
   /* CPP98 14.3.1-3 "If a declaration acquires a function type through a type
    * dependent on a template-parameter and this causes a declaration that does
    * not use the syntactic form of a function declarator to have function type,
    * the program is ill formed."
    */
   { "acquire_function",
        "member %s cannot acquire function type through dependent template-parameter",
   },
   /* C++98 14.3.2-3 "Addresses of array elements and names or
    * addresses of nonstatic class members are not acceptable
    * template-arguments."
    */
   { "bad_template_arg",
        "'%s' cannot have address of array element or nonstatic class member as template-argument",
   },
   /* C++98 14.5.1-3
    */
   { "template_arg_order",
        "order of arguments must match template parameter list",
   },
    /* CPP98 14.5.4-9 "The type of a template parameter corresponding to a
     * specialized non-type argument shall not be dependent on a parameter
     * of the specialization."
     */
   { "dependent_specialization",
        "template %s has specialized non-type argument dependent on specialization parameter",
   },
   /* C++98 14.5.3-9
    */
   { "friend_partial",
        "friend declaration '%s' cannot declare partial specialization",
   },
   /* C++98 14.6.1-4
    */
   { "template_parameter_redeclaration",
        "redeclaration of template parameter '%s'",
   },
   /* C++98 14.7.3-6
    */
   { "explicit_following",
        "specialization for '%s' must appear before use",
   },
   /* C++98 14.8.2-2
    */
   { "must_be_class_type",
        "type '%s' must be class type in qualified name",
   },
   /* C++98 15.4-1 "An exception-specification shall not appear in a
    * typedef declaration."
    */
   { "typedef_exception",
        "exception specification not allowed for typedef declaration '%s'",
   },


///////////////////////////////////////////////////
// HTML messages

  { "character_entity",
        "unrecognized character entity"
  }

};

///////////////////////////////////////////////////////////////////////////
// Program to generate the tables.

#include <stdio.h>
#include <stdlib.h>

#ifdef ENGLISH_ONLY
#define LANG_CNT 1
#else
#define LANG_CNT 4
#endif

int main()
{
    FILE *fp;
    int i;

    fp = fopen("msgs2.h","w");
    if (!fp)
    {   printf("can't open msgs2.h\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp,"enum EM\n{");
    for (i = 0; i < sizeof(msgtable) / sizeof(msgtable[0]); i++)
    {
        fprintf(fp,"\tEM_%s=%d,\n",msgtable[i].name,i);
    }
    fprintf(fp,"};\n");

    fclose(fp);

    /////////////////////////////////////

    fp = fopen("msgs2.d","w");
    if (!fp)
    {   printf("can't open msgs2.d\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp,"enum\n{");
    for (i = 0; i < sizeof(msgtable) / sizeof(msgtable[0]); i++)
    {
        fprintf(fp,"\tEM_%s=%d,\n",msgtable[i].name,i);
    }
    fprintf(fp,"}\n");

    fclose(fp);

    //////////////////////////////////////
    fp = fopen("msgs2.c","w");
    if (!fp)
    {   printf("can't open msgs2.c\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp,"const char *msgtbl[][%d] =\n{",LANG_CNT);
    for (i = 0; i < sizeof(msgtable) / sizeof(msgtable[0]); i++)
    {   unsigned char *p;
        int j;

        fprintf(fp,"/* %3d */\n",i);
        for (j = 0; j < LANG_CNT; j++)
        {
            switch (j)
            {   case 0: p = (unsigned char *)msgtable[i].msg; break;
                case 1: p = (unsigned char *)msgtable[i].german; break;
                case 2: p = (unsigned char *)msgtable[i].french; break;
                case 3: p = (unsigned char *)msgtable[i].japanese; break;
            }
            if (!p)
            {   fprintf(fp,"\t0,\n");
                continue;
            }
            //if (j == 3)
                //fprintf(fp,"\t#pragma dbcs(push,1)\n");
            fprintf(fp,"\t\"");
            for (; *p; p++)
            {
                switch (*p)
                {
                    case '"':
                        fputc('\\',fp);
                        fputc('"',fp);
                        break;
                    case '\n':
                        fputc('\\',fp);
                        fputc('n',fp);
                        break;
                    default:
                        if (*p < 0x20 || *p >= 0x7F)
                            //fprintf(fp, "\\x%02x", *p);
                            fprintf(fp, "\\%3o", *p);
                        else
                            fputc(*p,fp);
                        break;
                }
            }
            fprintf(fp,"\",\n");
            //if (j == 3)
                //fprintf(fp,"\t#pragma dbcs(pop)\n");
        }
    }
    fprintf(fp,"};\n");

    fclose(fp);

    return EXIT_SUCCESS;
}

