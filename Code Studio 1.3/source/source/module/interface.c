/*************************** Code Studio Bildschirmausgaben *******************/

/**
 * Makros
 */
 #define MAX FILENAME_MAX
 #define START       "./screen/start.nfo"
 #define MENUE       "./screen/menue.nfo"
 #define EINGABE     "./screen/eingabe.nfo"
 #define HEADER_C    "./screen/header_c.nfo"
 #define HEADER_PY   "./screen/header_py.nfo"
 #define HEADER_CPP  "./screen/header_cpp.nfo"
 #define HEADER_JAVA "./screen/header_java.nfo"
 #define GENERIEREN  "./screen/generieren.nfo"
 #define ENDE        "./screen/ende.nfo"
 #define INFO        "./screen/info.nfo"
 #define HILFE       "./screen/hilfe.nfo"
  
/**
 * Funktion : Gibt beim Start den Willkommensbildschirm aus
 * Status   : vorgelegt
 */
 int iAusgabe_Startbildschirm()
 {
	 /* Linuxshell auf 25x80 Zeilen anpassen */
	 #ifdef __linux__
	 system("resize -s 25 80");
	 #endif
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* start.nfo zum einlesen oeffnen */
	 FPLesen = fopen(START, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", START);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 /* setze Bildschirmausgabe zurueck fuer neue Ausgabe */
		 iLoesche_Ausgabe();
		 /* ersetzt erste doppelte Zeile */
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
			 /* bis zum Dateiende lesen */
		 }while(!feof(FPLesen));
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Gibt den Menuebildschirm fuer die Untermenues aus
 * Status   : vorgelegt
 */
 int iAusgabe_Menuebildschirm()
 {
	 /* Bildschirminhalt aus Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* menue.nfo zum einlesen oeffnen */
	 FPLesen = fopen(MENUE, "r");          
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", MENUE);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 /* setze Bildschirmausgabe zurueck */ 
		 iLoesche_Ausgabe();
		 /* ersetzt erste doppelte Zeile */
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
			 /* bis zum Dateiende lesen */
		 }while(!feof(FPLesen));
		 iSetze_Cursor(20,58);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 printf("Bedienmodus_aus_#");
		 iSetze_Cursor(22,8);
		 /* Textfarbe ausgegraut */
		 iSetze_Textfarbe(8, 22);
		 printf("< B >  Beenden");
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe");
		 /* Textfarbe gau */
		 iSetze_Textfarbe(7, 30);
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Gibt den Eingabebildschirm fuer den Programmkopf aus
 * Status   : vorgelegt
 */
 int iAusgabe_Eingabebildschirm()
 {
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* eingabe.nfo zum einlesen oeffnen */
	 FPLesen = fopen(EINGABE, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", EINGABE);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 iLoesche_Ausgabe();
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
		 }while(!feof(FPLesen));
		 iSetze_Cursor(20,58);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* sichtbar machen des Modus */
		 printf("Bedienmodus_aus_#");
		 iSetze_Cursor(22,8);
		 /* Textfarbe ausgegraut */
		 iSetze_Textfarbe(8, 22);
		 printf("< M >  Hauptmen%s", ue);
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe");
		 iSetze_Cursor(22, 50);
		 printf("< Z >  Zur%sck", ue);
		 iSetze_Cursor(19, 24);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
  }

/**
 * Funktion : Gibt den Auswahlbildschirm fuer die Bibliotheken aus
 * Status   : vorgelegt
 */
 int iAusgabe_Auswahlbildschirm()
 {
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 if(stAuswahl.cSprache == '1')
	 {
		 /* header_c.nfo zum einlesen oeffnen */
		 FPLesen = fopen(HEADER_C, "r");
	 }
	 else if(stAuswahl.cSprache == '2')
	 {
		 /* header_py.nfo zum einlesen oeffnen */
		 FPLesen = fopen(HEADER_PY, "r");
	 }
	 else if(stAuswahl.cSprache == '3')
	 {
		 /* header_cpp.nfo zum einlesen oeffnen */
		 FPLesen = fopen(HEADER_CPP, "r");
	 }
	 else if(stAuswahl.cSprache == '4')
	 {
		 /* header_java.nfo zum einlesen oeffnen */
		 FPLesen = fopen(HEADER_JAVA, "r");
	 }
	 /* Wenn Datei nicht gefunden: Fehlermeldung */
	 if(FPLesen == NULL)
	 {
		 /* pruefe, welche Datei fehlerhaft ist*/
		 if(stAuswahl.cSprache == '1')
		 {
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht angezeigt werden!", HEADER_C);
		 }
		 else if(stAuswahl.cSprache == '2')
		 {
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht angezeigt werden!", HEADER_PY);
		 }
		 else if(stAuswahl.cSprache == '3')
		 {
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht angezeigt werden!", HEADER_CPP);
		 }
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 iLoesche_Ausgabe();
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
		 }while(!feof(FPLesen));
		 iSetze_Cursor(20,58);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* sichtbar machen des Modus */
		 printf("Bedienmodus_aus_#");
		 iSetze_Cursor(22,8);
		 /* Textfarbe ausgegraut */
		 iSetze_Textfarbe(8, 22);
		 printf("< M >  Hauptmen%s", ue);
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe");
		 iSetze_Cursor(22, 50);
		 printf("< Z >  Zur%sck", ue);
		 iSetze_Cursor(19, 24);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Gibt den Abschlussbildschirm zum Code generieren aus
 * Status   : vorgelegt
 */
 int iAusgabe_Generierungsbildschirm()
 {
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* generieren.nfo zum einlesen oeffnen */
	 FPLesen = fopen(GENERIEREN, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", GENERIEREN);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 iLoesche_Ausgabe();
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
		 }while(!feof(FPLesen));
		 /* Umlaute setzen */
		 iSetze_Cursor(14, 53);
		 printf("%s",oe);
		 iSetze_Cursor(16, 28);
		 printf("%s",ue);
		 iSetze_Cursor(20, 58);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Bedienmodus aktivert  */
		 printf("Bedienmodus_an__#");
		 iSetze_Cursor(22,8);
		 /* Textfarbe ausgegraut */
		 iSetze_Textfarbe(8, 22);
		 printf("< M >  Hauptmen%s", ue);
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe ");
		 iSetze_Cursor(22, 50);
		 printf("< Z >  Zur%sck", ue);
		 iSetze_Cursor(19, 24);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
  }

/**
 * Funktion : Gibt den Hilfebildschirm aus
 * Status   : vorgelegt
 */
 int iAusgabe_Hilfebildschirm()
 {
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* info.nfo zum einlesen oeffnen */
	 FPLesen = fopen(INFO, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", INFO);
		 return EXIT_FAILURE;
	 }
	 /* hilfe.nfo zum einlesen oeffnen */
	 FPLesen = fopen(HILFE, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", HILFE);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 /* Startseite Hilfe lesen */
		 if(stSteuerung.cModus == 'z' || stSteuerung.cModus == 'Z' 
		 || stSteuerung.cFlag[4] == '0')
		 {
			 FPLesen = fopen(INFO, "r");
		 }
		 /* naechste Hilfeseite lesen */
		 else if(stSteuerung.cModus == '\n' || stSteuerung.cModus == '\r'
		 || stSteuerung.cFlag[4] == '1')
		 {
			 FPLesen = fopen(HILFE, "r");
		 }
		 iLoesche_Ausgabe();
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
		 }while(!feof(FPLesen));
		 /* Umlaute umwandeln und anzeigen */
		 iKonvertiere_Umlaute();
		 iSetze_Cursor(20,58);
		 /* Textfarbe gruen */
		 iSetze_Textfarbe(10, 22);
		 /* Bedienmodus aktivert */
		 printf("Bedienmodus_an__#");
		 iSetze_Cursor(22,8);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 printf("< M >  Men%s", ue);
		 if(stSteuerung.cFlag[4] == '0')
		 {
			 /* Text positionieren */
			 iSetze_Cursor(19, 15);
			 /* Textfarbe blau */
			 iSetze_Textfarbe(11, 25);
			 printf("Dr%scken Sie zum Weiterbl%sttern Enter.", ue, ae);
			 /* Textfarbe ausgegraut */
			 iSetze_Textfarbe(8, 22);
			 /* Bedienelement positionieren */
			 iSetze_Cursor(22, 31);
			 printf("< H >  Hilfe");
			 /* Bedienelement positionieren */
			 iSetze_Cursor(22, 50);
			 /* wechseln der Bedienelemente */
			 printf("< Z >  Zur%sck", ue);
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 52);
		 }
		 else
		 {
			 /* Text positionieren */
			 iSetze_Cursor(19, 15);
			 /* Textfarbe blau */
			 iSetze_Textfarbe(11, 25);
			 printf("Dr%scken Sie zum Zur%sckbl%sttern Taste [Z]", ue, ue, ae);
			 /* Textfarbe ausgegraut */
			 iSetze_Textfarbe(8, 22);
			 /* Bedienelement positionieren */
			 iSetze_Cursor(22, 31);
			 printf("< H >  Hilfe");
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 /* Bedienelement positionieren */
			 iSetze_Cursor(22, 50);
			 /* aktivieren des Bedienelements */
			 printf("< Z >  Zur%sck", ue);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 55);
		 }
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Gibt beim Beenden den Abschiedsbildschirm aus
 * Status   : vorgelegt
 */
 int iAusgabe_Abschlussbildschirm()
 {
	 /* Bildschirmausgabe in Datei speichern */
	 char sAusgabe[MAX];
	 FILE *FPLesen;
	 /* ende.nfo zum einlesen oeffnen */
	 FPLesen = fopen(ENDE, "r");
	 if(FPLesen == NULL)
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 /* Cursor positionieren */
		 iSetze_Cursor(19, 15);
		 printf("Fehler: '%s' kann nicht angezeigt werden!", ENDE);
		 return EXIT_FAILURE;
	 }
	 else
	 {
		 /* loesche Bildschirmausgabe */
		 iLoesche_Ausgabe();
		 /* ersetzt erste doppelte Zeile */
		 fgets(sAusgabe, MAX, FPLesen);
		 do
		 {
			 /* Farbe auf Grau setzen */
			 iSetze_Textfarbe(7, 30);
			 printf("%s", sAusgabe);
			 fgets(sAusgabe, MAX, FPLesen);
			 /* Newline unter Windows entfernen */
			 #ifndef __linux__
			 int  i = 0;
			 /* Stringlaenge ermitteln */
			 i = strlen(sAusgabe) -1;
			 if(sAusgabe[i] == '\n')
			 {
				 sAusgabe[i] = '\0';
			 }
			 #endif
			 /* bis zum Dateiende lesen */
		 }while(!feof(FPLesen));
	 }
	 /* Datei aus Sicherheitsgruenden schliesen */
	 fclose(FPLesen);
	 return EXIT_SUCCESS;
 }
