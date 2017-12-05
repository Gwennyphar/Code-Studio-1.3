/*************************** Eingaben *****************************************/

/**
 * Funktion : Datei/Programmname eingeben
 * Status   : vorgelegt
 */
 int iEingabe_Dateiname()
 {
	 /* Trennt die Ausgabe des Bedienmodi */
	 stSteuerung.cFlag[0] = '0';
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte einen Dateinamen ein.");
		 iSetze_Cursor(19, 24);
		 /* Eingabefeld nach Falscheingabe zuruecksetzen */
		 iLeere_Eingabefeld();
		 fgets(stEingaben.sDateiname, sizeof(stEingaben.sDateiname),stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stEingaben.sDateiname);
		 stEingaben.iSize = stEingaben.iSize - 61;
		 /* Dateiname auf 60 Zeichen begrenzen */
		 stEingaben.sDateiname[strlen(stEingaben.sDateiname)-stEingaben.iSize] 
		 = '\0';
		 /* Newline entfernen */
		 stEingaben.sDateiname[strlen(stEingaben.sDateiname)-1] = '\0';
		 if(strncmp(stEingaben.sDateiname, "\n", 1) == 0
		 || strncmp(stEingaben.sDateiname, "\0", 1) == 0)
		 {
			 /* Hinweis bei leerer Eingabe anzeigen */
			 iZeige_Hinweis(2);
		 }
		 /* Bedienmodi anschalten */
		 else if((strncmp(stEingaben.sDateiname, "#", 1)) == 0)
		 {
			 /* Zurueck zu Dateiname */
			 stSteuerung.cFlag[5] = '0';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit Autor */
			 stSteuerung.cFlag[5] = '1'; 
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }
  
/**
 * Funktion : Autor eingeben
 * Status   : vorgelegt
 */
 int iEingabe_Autor()
 {
	 /* Screen auf Bildschirm anzeigen */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte ihren vollst%sndigen Namen ein.", ae);
		 iLeere_Eingabefeld();
		 fgets(stEingaben.sAutor, sizeof(stEingaben.sAutor), stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stEingaben.sAutor);
		 stEingaben.iSize = stEingaben.iSize - 61;
		 /* Autor auf 60 Zeichen begrenzen */
		 stEingaben.sAutor[strlen(stEingaben.sAutor)-stEingaben.iSize] = '\0';
		 /* Newline entfernen */
		 stEingaben.sAutor[strlen(stEingaben.sAutor)-1] = '\0';
		 /* Bedienmodi anschalten */
		 if((strncmp(stEingaben.sAutor, "#", 1)) == 0)
		 {
			 /* Zurueck zu Autor */
			 stSteuerung.cFlag[5] = '1';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit Version */
			 stSteuerung.cFlag[5] = '2';
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Versionsnummer eingeben
 * Status   : vorgelegt
 */
 int iEingabe_Version()
 {
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte die aktuelle Versionsnummer ein.");
		 iLeere_Eingabefeld();
		 fgets(stEingaben.sVersion, sizeof(stEingaben.sVersion), stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stEingaben.sVersion);
		 stEingaben.iSize = stEingaben.iSize - 61;
		 /* Version auf 60 Zeichen begrenzen */
		 stEingaben.sVersion[strlen(stEingaben.sVersion)-stEingaben.iSize] =
		 '\0';
		 /* Newline entfernen */
		 stEingaben.sVersion[strlen(stEingaben.sVersion)-1] = '\0';
		 if((strncmp(stEingaben.sVersion, "#", 1)) == 0)
		 {
			 /* Zurueck zu Version */
			 stSteuerung.cFlag[5] = '2';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit Status */
			 stSteuerung.cFlag[5] = '3';
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }
  
/**
 * Funktion : Status eingeben
 * Status   : vorgelegt
 */
 int iEingabe_Status()
 {
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte den aktuellen Entwicklungstand ein.");
		 iLeere_Eingabefeld();
		 fgets(stEingaben.sStatus, sizeof(stEingaben.sStatus), stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stEingaben.sStatus);
		 stEingaben.iSize = stEingaben.iSize - 61;
		 /* Status auf 60 Zeichen begrenzen */
		 stEingaben.sStatus[strlen(stEingaben.sStatus)-stEingaben.iSize] =
		 '\0';
		 /* Newline entfernen */
		 stEingaben.sStatus[strlen(stEingaben.sStatus)-1] = '\0';
		 /* Bedienmodi anschalten */
		 if((strncmp(stEingaben.sStatus, "#", 1)) == 0)
		 {
			 /* Zurueck zu Status */
			 stSteuerung.cFlag[5] = '3';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit ToDo */
			 stSteuerung.cFlag[5] = '4';
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }
	  
/**
 * Funktion : ToDo's eingeben
 * Status   : vorgelegt
 */
 int iEingabe_ToDos()
 {
	 int iZeile = 0;
	 int iZaehler = 0;
	 stEingaben.iPos_ToDo = 0;
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Dreizeiler */
	 for(stEingaben.iPos_ToDo = 0; stEingaben.iPos_ToDo < 3;
	 stEingaben.iPos_ToDo++)
	 {
		 /* Schleife */
		 while(1)
		 {
			 iSetze_Cursor(14, 8);
			 printf("Geben Sie bitte ihre ToDo's ein."
			 "[%i von 3 Zeilen]", stEingaben.iPos_ToDo + 1);
			 /* Erste Eingabe beginnt ab Zeile 14
			  * Nach dem 1. Eintrag wird pro Zeile hochgezaehlt, um die
			  * aktuelle Position vorheriger Eingaben zu behalten. */
			  for(iZeile = 0; iZeile < stEingaben.iPos_ToDo; iZeile++)
			  {
				  if(stEingaben.iPos_ToDo == 0)
				  {
					  iSetze_Cursor(14 + iZeile, 8);
					  iZaehler++;
				  }
				  else
				  {
					  iSetze_Cursor(15 + iZeile, 8);
				  }
				  printf("%s", stEingaben.sToDo[iZeile]);
			  }
			  /* Eingabefeld ausgegraut */
			  iSetze_Textfarbe(8, 22);
			  iLeere_Eingabefeld();
			  iSetze_Cursor(15 + stEingaben.iPos_ToDo, 8);
			  fgets(stEingaben.sToDo[stEingaben.iPos_ToDo],
			  sizeof(stEingaben.sToDo[stEingaben.iPos_ToDo]), stdin);
			  /* Bedienmodi anschalten */
			  if((strncmp(stEingaben.sToDo[stEingaben.iPos_ToDo], "#", 1)) == 0)
			  {
				  /* Zurueck zu ToDo */
				  stSteuerung.cFlag[5] = '4';
				  iMenuesteuerung();
				  iLeere_Eingabefeld();
			  }
			  else
			  {
				  /* Stringlaenge berechnen */
				  stEingaben.iSize = strlen(stEingaben.sToDo
				  [stEingaben.iPos_ToDo]);
				  stEingaben.iSize = stEingaben.iSize - 61;
				  /* ToDo's auf 60 Zeichen begrenzen */
				  stEingaben.sToDo[stEingaben.iPos_ToDo]
				  [strlen(stEingaben.sToDo[stEingaben.iPos_ToDo])-
				  stEingaben.iSize] = '\0';
				  /* Newline entfernen */
				  stEingaben.sToDo[stEingaben.iPos_ToDo]
				  [strlen(stEingaben.sToDo[stEingaben.iPos_ToDo])-1] = '\0';
				  /* Weiter mit Bibliothek */
				  stSteuerung.cFlag[5] = '5';
				  break;
			  }
			  iSetze_Cursor(15 + stEingaben.iPos_ToDo, 8);
		 }
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Bibliotheken fuer C oder Python einbinden
 * Status   : vorgelegt
 */
 int iAuswahl_Bibliotheken()
 {
	 do
	 {
		 iAusgabe_Auswahlbildschirm();
		 iSetze_Cursor(19, 24);
		 /* stoppt den Programmablauf,
		  * bis eine bestimmte Taste gedrueckt wird */
		  stAuswahl.cTaste = iWarte_auf_Taste();
		  iSetze_Cursor(19, 15);
		  switch(stAuswahl.cTaste)
		  {
			  case '1':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[0] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("math.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("math hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cmath hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.math hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[0] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("math.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("math abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cmath abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.math abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[0] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '2':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[1] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("string.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("string hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cstring hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.text hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[1] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("string.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("string abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cstring abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.text abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Letzte Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[1] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '3':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[2] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("time.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("datetime hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("ctime hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.io hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[2] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("time.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("datetime abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("ctime abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.io abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[2] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '4':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[3] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("ctype.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("random hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cctype hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.lang hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[3] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("ctype.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("random abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cctype abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.lang abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[3] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '5':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[4] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("limits.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("pickle hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("climits hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.net hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[4] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("limits.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("pickle abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("climits abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.net abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[4] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '6':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[5] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("float.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("codecs hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cfloat hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.security hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[5] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("float.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("codecs abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cfloat abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.security abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[5] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '7':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[6] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("stdlib.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("os hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cstdlib hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.applet hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[6] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("stdlib.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("os abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cstdlib abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.applet abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[6] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '8':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[7] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("stdarg.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("re hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("fstream hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.beans hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[7] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("stdarg.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("re abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("fstream abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.beans abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[7] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '9':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[8] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("signal.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("gtk hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("csignal hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.awt hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[8] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("signal.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("gtk abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("csignal abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.awt abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[8] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '0':
			  {
				  /* Textfarbe gruen */
				  iSetze_Textfarbe(10, 22);
				  if(stAuswahl.iAuswahl[9] != 1)
				  {
					  /* unterscheide Bibliotheken */
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("assert.h hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("cgi hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cassert hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.swing hinzugef%sgt! "
						  "Dr%scken Sie Enter.", ue, ue);
					  }
					  /* Verhindert doppelte Auswahl */
					  stAuswahl.iAuswahl[9] = 1;
				  }
				  else
				  {
					  /* Textfarbe gelb */
					  iSetze_Textfarbe(14, 19);
					  iSetze_Cursor(19, 15);
					  if(stAuswahl.cSprache == '1')
					  {
						  printf("assert.h abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '2')
					  {
						  printf("cgi abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);				  
					  }
					  else if(stAuswahl.cSprache == '3')
					  {
						  printf("cassert abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  else if(stAuswahl.cSprache == '4')
					  {
						  printf("java.swing abgew%shlt! "
						  "Dr%scken Sie Enter.", ae, ue);
					  }
					  /* Auswahl zuruecksetzen */
					  stAuswahl.iAuswahl[9] = 0;
				  }
				  /* Textfarbe grau */
				  iSetze_Textfarbe(7, 30);
				  /* Auf Tastendruck warten */
				  stAuswahl.cTaste = iWarte_auf_Taste();
				  break;
			  }
			  case '\n':
			  case '\r':
			  {
				  /* falls 2 gesetzt, wird man direkt zum 
				   * Code generieren weitergeleitet */
				  if(stSteuerung.cFlag[1] == '2')
				  {
					  iGeneriere_Code();
				  }
				  else
				  {
					  /* Weiter mit Menue anlegen */
					  stSteuerung.cFlag[5] = '6';
					  iErstelle_Funktion();
				  }
				  break;
			  }
			  case 'm':
			  case 'M':
			  case 'h':
			  case 'H':
			  case 'z':
			  case 'Z':
			  {
				  /* Hinweis bei falscher Eingabe anzeigen */
				  iZeige_Hinweis(1);
				  break;
			  }
			  case '#':
			  {
				  /* Zurueck zu Bibliothek */
				  stSteuerung.cFlag[5] = '5';
				  iMenuesteuerung();
				  break;
			  }
			  default:
			  {
				  /* Hinweis bei falscher Eingabe anzeigen */
				  iZeige_Hinweis(3);
				  break;
			  }
		  }
	 }while(stAuswahl.cTaste != '\n' || stAuswahl.cTaste != '\r');
	 return EXIT_SUCCESS;
 } 

/**
 * Funktion : Anlegen des Hauptmenues
 * Status   : vorgelegt
 */
 int iErstelle_Menue()
 {
	 int iIndex = 0;
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 printf("Geben Sie bitte eine Bezeichnung "
		 "f%sr das Hauptmen%s ein.", ue, ue);
		 iLeere_Eingabefeld();
		 fgets(stFunktion.sBezeichnung, sizeof(stFunktion.sBezeichnung), stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stFunktion.sBezeichnung);
		 stEingaben.iSize = stEingaben.iSize - 15;
		 /* Bezeichner auf 14 Zeichen begrenzen */
		 stFunktion.sBezeichnung[strlen(stFunktion.sBezeichnung)-stEingaben.iSize] =
		 '\0';
		 /* Newline entfernen */
		 stFunktion.sBezeichnung[strlen(stFunktion.sBezeichnung)-1] = '\0';
		 /* Eingabe in Kleinbuchstaben umwandeln */
		 for(iIndex = 0; stFunktion.sBezeichnung[iIndex]; iIndex++)
		 {
			 stFunktion.sBezeichnung[iIndex]
			 = tolower(stFunktion.sBezeichnung[iIndex]);
		 }
		 /* Leere Eingaben validieren */
		 if(strncmp(stFunktion.sBezeichnung, "\n", 1) == 0
		 || strncmp(stFunktion.sBezeichnung, "\0", 1) == 0)
		 {
			 /* Hinweis bei leerer Eingabe anzeigen */
			 iZeige_Hinweis(2);
		 }
		 /* Vorbelegte Bezeichner validieren */
		 else if(strcmp(stFunktion.sBezeichnung, "controller") == 0
		 || strcmp(stFunktion.sBezeichnung, "main") == 0 )
		 {
			 /* Hinweis bei falscher Eingabe anzeigen */
			 iZeige_Hinweis(4);
		 }
		 /* Bedienmodi anschalten */
		 else if((strncmp(stFunktion.sBezeichnung, "#", 1)) == 0)
		 {
			 /* Zurueck zu Menuebezeichnung */
			 stSteuerung.cFlag[5] = '6';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit Kommentar */
			 stSteuerung.cFlag[5] = '7';
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Funktionskommentar eingeben
 * Status   : vorgelegt
 */
 int iEingabe_Beschreibung()
 {
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Schleife */
	 while(1)
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte einen Kommentar f%sr '%s' ein.",
		 ue, stFunktion.sBezeichnung);
		 iLeere_Eingabefeld();
		 fgets(stFunktion.sKommentar, sizeof(stFunktion.sKommentar), stdin);
		 /* Stringlaenge berechnen */
		 stEingaben.iSize = strlen(stFunktion.sKommentar);
		 stEingaben.iSize = stEingaben.iSize - 61;
		 /* Kommentar auf 60 Zeichen begrenzen */
		 stFunktion.sKommentar[strlen(stFunktion.sKommentar)-stEingaben.iSize] =
		 '\0';
		 /* Newline entfernen */
		 stFunktion.sKommentar[strlen(stFunktion.sKommentar)-1] = '\0';
		 /* Bedienmodi anschalten */
		 if((strncmp(stFunktion.sKommentar, "#", 1)) == 0)
		 {
			 /* Zurueck zu Kommentar */
			 stSteuerung.cFlag[5] = '7';
			 iMenuesteuerung();
			 iLeere_Eingabefeld();
		 }
		 else
		 {
			 /* Weiter mit Menuepunkt */
			 stSteuerung.cFlag[5] = '8';
			 break;
		 }
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : 5 Menuepunkte anlegen
 * Status   : vorgelegt
 */
 int iErstelle_Menuepunkte()
 {
	 /* Anzahl der Menuepunkte */
	 stMenues.iAnzahl = 0;
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 do
	 {
		 iSetze_Cursor(14, 8);
		 printf("Geben Sie bitte die Anzahl der "
		 "Men%spunkte ein. [0 bis 5]", ue);
		 iLeere_Eingabefeld();
		 /* stoppt den Programmablauf,
		  * bis eine bestimmte Taste gedrueckt wird */
		 stAuswahl.cTaste = iWarte_auf_Taste();
		 iSetze_Cursor(19, 15);
		 switch(stAuswahl.cTaste)
		 {
			 case '1':
			 case '2':
			 case '3':
			 case '4':
			 case '5':
			 {
				 /* Cast in Integer fuer Menuepunkte umwandeln */
				 stMenues.iAnzahl = stAuswahl.cTaste - 48;
				 /* Weiter mit Bezeichner */
				 if(stSteuerung.cFlag[5] == '9')
				 {
					 /* Weiter mit Bezeichner */
					 iBezeichne_Menuepunkte();
				 }
				 break;
			 }
			 case '6':
			 case '7':
			 case '8':
			 case '9':
			 {
				 /* Cast in Integer fuer Menuepunkte umwandeln */
				 stMenues.iAnzahl = stAuswahl.cTaste - 48;
				 /* Hinweis bei falscher Eingabe anzeigen */
				 iZeige_Hinweis(5);
				 break;
			 }
			 case '0':
			 {
				 iGeneriere_Code();
				 break;
			 }
			 case 'm':
			 case 'M':
			 case 'h':
			 case 'H':
			 case 'z':
			 case 'Z':
			 {
				 /* Hinweis bei falscher Eingabe anzeigen */
				 iZeige_Hinweis(1);
				 break;
			 }
			 case '#':
			 {
				 /* Zurueck zu Menuepunkt */
				 stSteuerung.cFlag[5] = '8';
				 iMenuesteuerung();
				 iLeere_Eingabefeld();
				 break;
			 }
			 default:
			 {
				 iZeige_Hinweis(0);
				 break;
			 }
		 }
	 }while(stAuswahl.cTaste != '1' && stAuswahl.cTaste != '2'
	 && stAuswahl.cTaste != '3' && stAuswahl.cTaste != '4'
	 && stAuswahl.cTaste != '5');
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Menuebezeichnung eingeben
 * Status   : vorgelegt
 */
 int iBezeichne_Menuepunkte()
 {
	 int iIndex  = 0;
	 int iAnzahl = 0;
	 /* Bezeichner eingeben */
	 for(iAnzahl = 1; iAnzahl <= stMenues.iAnzahl; iAnzahl++)
	 {
		 /* Schleife */
		 while(1)
		 {
			 /* Screen auf Bildschirm anzeigen  */
			 iAusgabe_Eingabebildschirm();
			 /* Hinweis, wenn letzter Menuepunkt erreicht */
			 if(iAnzahl == stMenues.iAnzahl)
			 {
				 iSetze_Cursor(14, 8);
				 printf("Geben Sie bitte eine Bezeichnung "
				 "f%sr den letzten Men%spunkt ein.", ue, ue);
			 }
			 /* Menuepunkte durchnummerieren */
			 else
			 {
				 iSetze_Cursor(14, 8);
				 printf("Geben Sie bitte eine Bezeichnung "
				 "f%sr den %i. Men%spunkt ein.", ue, iAnzahl, ue);
			 }
			 iLeere_Eingabefeld();
			 fgets(stMenues.sMenuepunkt[iAnzahl],
			 sizeof(stMenues.sMenuepunkt), stdin);
			 /* Stringlaenge berechnen */
			 stEingaben.iSize = strlen(stMenues.sMenuepunkt[iAnzahl]);
			 stEingaben.iSize = stEingaben.iSize - 15;
			 /* Kommentar auf 14 Zeichen begrenzen */
			 stMenues.sMenuepunkt[iAnzahl]
			 [strlen(stMenues.sMenuepunkt[iAnzahl])-stEingaben.iSize] = '\0';
			 /* Newline entfernen */
			 stMenues.sMenuepunkt[iAnzahl]
			 [strlen(stMenues.sMenuepunkt[iAnzahl])-1] = '\0';
			 /* Eingabe in Kleinbuchstaben umwandeln */
			 for(iIndex = 0; stMenues.sMenuepunkt[iAnzahl][iIndex] ; iIndex++)
			 {
				 stMenues.sMenuepunkt[iAnzahl][iIndex]
				 = tolower(stMenues.sMenuepunkt[iAnzahl][iIndex]);
			 }
			 /* Bedienmodi anschalten */
			 if((strncmp(stMenues.sMenuepunkt[iAnzahl], "#", 1)) == 0)
			 {
				 /* Zurueck zu Bezeichner */
				 stSteuerung.cFlag[5] = '9';
				 iMenuesteuerung();
				 iLeere_Eingabefeld();
			 }
			 /* Leere Eingaben validieren */
			 else if(strncmp(stMenues.sMenuepunkt[iAnzahl], "\n", 1) == 0
			 || strncmp(stMenues.sMenuepunkt[iAnzahl], "\0", 1) == 0 )
			 {
				 /* Hinweis bei leerer Eingabe anzeigen */
				 iZeige_Hinweis(2);
			 }
			 /* Vorbelegte Bezeichnungen validieren
			  * -1 letzter Datensatz
			  * -2 vorletzte Datensatz
			  * -3 2. Datensatz
			  * -4 der 1. Datensatz */
			  else if(strcmp(stMenues.sMenuepunkt[iAnzahl], "controller") == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], "main") == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], stFunktion.sBezeichnung)
			  == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], 
			  stMenues.sMenuepunkt[iAnzahl-1]) == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], 
			  stMenues.sMenuepunkt[iAnzahl-2]) == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], 
			  stMenues.sMenuepunkt[iAnzahl-3]) == 0
			  || strcmp(stMenues.sMenuepunkt[iAnzahl], 
			  stMenues.sMenuepunkt[iAnzahl-4]) == 0)
			  {
				  /* Hinweis bei falscher Eingabe anzeigen */
				  iZeige_Hinweis(4);
			  }
			  else
			  {
				  /* Weiter mit generieren */
				  stSteuerung.cFlag[5] = '\0';
				  break;
			  }
		 }
		 iEingabe_Kommentare(iAnzahl);
		 iSetze_Cursor(19, 24);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Kommentare fuer Menuepunkte hinzufuegen
 * Status   : vorgelegt
 */
 int iEingabe_Kommentare(iAnzahl)
 {
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 iSetze_Cursor(14, 8);
	 printf("Geben Sie bitte einen Kommentar f%sr '%s' ein.", ue,
	 stMenues.sMenuepunkt[iAnzahl]);
	 iLeere_Eingabefeld();
	 fgets(stMenues.sKommentare[iAnzahl], sizeof(stMenues.sKommentare), stdin);
	 /* Stringlaenge berechnen */
	 stEingaben.iSize = strlen(stMenues.sKommentare[iAnzahl]);
	 stEingaben.iSize = stEingaben.iSize - 61;
	 /* Kommentar auf 60 Zeichen begrenzen */
	 stMenues.sKommentare[iAnzahl] [strlen(stMenues.sKommentare[iAnzahl]) -
	 stEingaben.iSize] = '\0';
	 /* Newline entfernen */
	 stMenues.sKommentare[iAnzahl][strlen(stMenues.sKommentare[iAnzahl])-1] =
	 '\0';
	 /* Bedienmodi anschalten */
	 if((strncmp(stMenues.sKommentare[iAnzahl], "#", 1)) == 0)
	 {
		 /* aktuelle Position merken */
		 stMenues.iPos_Kommentar = iAnzahl;
		 /* Zurueck zu Kurzbeschreibung */
		 stSteuerung.cFlag[3] = '0';
		 iMenuesteuerung();
		 iLeere_Eingabefeld();
	 }
	 else
	 {
		 /* Weiter mit Bezeichner */
		 stSteuerung.cFlag[5] = '9';
	 }
	 iSetze_Cursor(19, 24);
	 return EXIT_SUCCESS;
 }
