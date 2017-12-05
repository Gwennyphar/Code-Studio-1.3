/*************************** Funktionen ***************************************/

/**
 * Prototypen (speziell fuer den gcc Compiler unter Linux)
 */
 int iAuswahl_Hauptmenue();
 int iProgrammkopf_anlegen();
 int iEingabe_Dateiname();
 int iEingabe_Autor();
 int iEingabe_Version();
 int iEingabe_Status();
 int iEingabe_ToDos();
 int iAuswahl_Bibliotheken();
 int iErstelle_Menue();	
 int iEingabe_Beschreibung();
 int iErstelle_Menuepunkte();
 int iBezeichne_Menuepunkte();
 int iEingabe_Kommentare();
 int iAusgabe_Abschlussbildschirm();
 int iZeige_Hilfe();
 int iController();

/**
 * Funktion : switch-case Beenden Funktion     
 * Status   : vorgelegt                                               
 */
 int iBeenden()
 {
	 stAuswahl.cTaste = iWarte_auf_Taste();
	 switch(stAuswahl.cTaste)
	 {
		 case 'j':
		 case 'J':
		 {
			 iAusgabe_Abschlussbildschirm();
			 iSetze_Pause(3);
			 /* Code Studio sauber beenden */
			 exit(0);
		 }
		 case 'n':
		 case 'N':
		 {
			 /* Vorgang abbrechen */
			 return EXIT_SUCCESS;
			 break;
		 }
		 default:
		 {
			 iBeenden();
			 break;
		 }
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : switch-case Ja Nein Funktion  
 * Status   : vorgelegt                                               
 */
 int iJaNein()
 {
	 /* Textfarbe blau */
	 iSetze_Textfarbe(11, 25);
	 iSetze_Cursor(19, 15);
	 printf("M%schten Sie generieren? j/n: ", oe);
	 /* Textfarbe grau */
	 iSetze_Textfarbe(7, 30);
	 stAuswahl.cTaste = iWarte_auf_Taste();
	 switch(stAuswahl.cTaste)
	 {
		 case 'j':
		 case 'J':
		 {
			 /* weiterleiten zu iParser, um Code zu generieren */
			 iParser();
			 break;
		 }
		 case 'n':
		 case 'N':
		 {
			 /* bleibe im aktuellen Menue, um spaeter zu generieren */
			 iGeneriere_Code();
			 break;
		 }
		 default:
		 {
			 /* akzepiert nur j oder n, um Falscheingaben abzufangen */
			 iJaNein();
			 break;
		 }
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Eingabefeld auf Bildschirm leeren
 * Status   : vorgelegt
 */
 int iLeere_Eingabefeld()
 {
	 iSetze_Cursor(19, 8);
	 printf("---->  Eingabe: ");
	 iSetze_Cursor(19, 24);
	 printf("                                      ");
	 /* bei 0 ist Anzeige aktiv */
	 if(stSteuerung.cFlag[0] == '0')
	 {
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 iSetze_Cursor(20, 58);
		 /* sichtbar machen des Modus */
		 printf("Bedienmodus_aus_#");
		 iSetze_Cursor(22, 8);
		 /* Textfarbe ausgegraut */
		 iSetze_Textfarbe(8, 22);
		 printf("< M >  Hauptmen%s", ue);
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe");
		 iSetze_Cursor(22, 50);
		 printf("< Z >  Zur%sck", ue);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
	 }
	 iSetze_Cursor(19, 24);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Bedienmodus aktiv halten
 * Status   : vorgelegt
 */
 int iHalte_Bedienmodi()
 {
	 /* Flag zum Anzeigen nicht gesetzt */
	 if(stSteuerung.cFlag[2] == '0')
	 {
		 /* Textfarbe gelb */
		 iSetze_Textfarbe(14, 19);
		 iSetze_Cursor(19, 15);
		 printf("Upp's, Falsche Taste! Dr%scken Sie Enter.", ue);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7,30);
		 stAuswahl.cTaste = iWarte_auf_Taste();
	 }
	 iLeere_Eingabefeld();
	 iMenuesteuerung();
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Meist verwendete Warnhinweise bei Falscheingabe anzeigen
 * Status   : vorgelegt
 */
 int iZeige_Hinweis(int iHinweis)
 {
	 /* Textfarbe gelb */
	 iSetze_Textfarbe(14, 19);
	 iSetze_Cursor(19, 15);
	 if(iHinweis == 1)
	 {
		 printf("Bitte Modus anschalten. Dr%scken Sie Enter.", ue);
	 }
	 else if(iHinweis == 2)
	 {
		 printf("Keine g%sltige Eingabe. Dr%scken Sie Enter.", ue, ue);
	 }
	 else if(iHinweis == 3)
	 {
		 printf("'%s' ist nicht verf%sgbar. "
		  "Dr%scken Sie Enter.", &stAuswahl.cTaste, ue, ue);
	 }
	 else if(iHinweis == 4)
	 {
		 printf("Name ist bereits vergeben. Dr%scken Sie Enter.", ue);
	 }
	 else if(iHinweis == 5)
	 {
		 printf("%i Men%ss sind nicht m%sglich. Dr%scken Sie Enter.",
		 stMenues.iAnzahl, ue, oe, ue);
	 }
	 else if(iHinweis == 0)
	 {
		 printf("Upp's, Falsche Taste! Dr%scken Sie Enter.", ue);
	 }
	 /* Textfarbe grau */
	 iSetze_Textfarbe(7, 30);
	 stAuswahl.cTaste = iWarte_auf_Taste();
	 iLeere_Eingabefeld();
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Umlaute im Hilfetext ersetzen
 * Status   : vorgelegt
 */
 int iKonvertiere_Umlaute()
 {
	 /* Infoseite */
	 if(stSteuerung.cFlag[4] == '0')
	 {
		 iSetze_Cursor(5,53);
		 printf("%s",ue);
		 iSetze_Cursor(6,15);
		 printf("%s",oe); 
		 iSetze_Cursor(6,25);
		 printf("%s",ue);
		 iSetze_Cursor(7,26);
		 printf("%s",ue);
		 iSetze_Cursor(8,12);
		 printf("%s",ue);
		 iSetze_Cursor(8,46);
		 printf("%s",ae); 
		 iSetze_Cursor(8,47);
		 printf("%s",ss);
		 iSetze_Cursor(9,11);
		 printf("%s",oe);
		 iSetze_Cursor(11,51);
		 printf("%s",oe);
		 iSetze_Cursor(12,62);
		 printf("%s",ae);
		 iSetze_Cursor(14,28);
		 printf("%s",ae);
		 iSetze_Cursor(14,52);
		 printf("%s",ae);
		 iSetze_Cursor(16,18);
		 printf("%s",ue);
	 }
	 /* Hilfeseite */
	 if(stSteuerung.cFlag[4] == '1')
	 {
		 /* hier ist der Bedienteil */
		 iSetze_Cursor(5,23);
		 printf("%s",ue);
		 iSetze_Cursor(5,43);
		 printf("%s",ae);
		 iSetze_Cursor(6,38);
		 printf("%s",ue);
		 iSetze_Cursor(6,43);
		 printf("%s",ae);
		 /* hier beginnt der Funktionsteil */
		 iSetze_Cursor(13,28);
		 printf("%s",ae);
		 iSetze_Cursor(13,36);
		 printf("%s",ue);
		 iSetze_Cursor(13,44);
		 printf("%s",oe);
		 iSetze_Cursor(13,52);
		 printf("%s",ss);
		 iSetze_Cursor(14,11);
		 printf("%s",ue);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : In vorherige Eingabemaske zurueck gehen
 * Status   : vorgelegt
 */
 int iGehe_zurueck()
 {
	 /* Dateiname */
	 if(stSteuerung.cFlag[5] == '0')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Hauptmenue */
		 iAuswahl_Hauptmenue();
	 }
	 /* Autor */
	 else if(stSteuerung.cFlag[5] == '1')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Dateiname */
		 iEingabe_Dateiname();
	 }
	 /* Version */
	 else if(stSteuerung.cFlag[5] == '2')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Autor */
		 iEingabe_Autor();
	 }
	 /* Status */
	 else if(stSteuerung.cFlag[5] == '3')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Version */
		 iEingabe_Version();
	 }
	 /* ToDo's */
	 else if(stSteuerung.cFlag[5] == '4')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Position an den Anfang setzen */
		 stEingaben.iPos_ToDo = 0;
		 /* Zurueck zu Status */
		 iEingabe_Status();
	 }
	 /* Bibliotheken */
	 else if(stSteuerung.cFlag[5] == '5')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 iAusgabe_Eingabebildschirm();
		 /* Zurueck zu ToDo's */
		 iEingabe_ToDos();
	 }
	 /* Hauptmenue anlegen */
	 else if(stSteuerung.cFlag[5] == '6')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Bibliotheken */
		 iAuswahl_Bibliotheken();
	 }
	 /* Kommentar */
	 else if(stSteuerung.cFlag[5] == '7')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Menue */
		 iErstelle_Menue();
	 }
	 /* Menuepunkt */
	 else if(stSteuerung.cFlag[5] == '8')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Kommentar */
		 iEingabe_Beschreibung();
	 }
	 /* Bezeichner */
	 else if(stSteuerung.cFlag[5] == '9')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Menuepunkt */
		 iErstelle_Menuepunkte();
	 }
	 /* Kommentare */
	 else if(stSteuerung.cFlag[3] == '0')
	 {
		 stSteuerung.cFlag[3] = '\0';
		 /* Zurueck zu Bezeichner */
		 iBezeichne_Menuepunkte();
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Eingabemasken zulassen oder sperren
 * Status   : vorgelegt
 */
 int iBleibe_hier()
 {
	 /* Screen auf Bildschirm anzeigen  */
	 iAusgabe_Eingabebildschirm();
	 /* Dateiname */
	 if(stSteuerung.cFlag[5] == '0')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Programm */
		 return '#';
	 }
	 /* Autor */
	 else if(stSteuerung.cFlag[5] == '1')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Autor */
		 return '#';
	 }
	 /* Version */
	 else if(stSteuerung.cFlag[5] == '2')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Version */
		 return '#';
	 }
	 /* Status */
	 else if(stSteuerung.cFlag[5] == '3')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Status */
		 return '#';
	 }
	 /* ToDo's */
	 else if(stSteuerung.cFlag[5] == '4')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu ToDo */
		 return '#';
	 }
	 /* Bibliotheken */
	 else if(stSteuerung.cFlag[5] == '5')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Bibliothek */
		 return '#';
	 }
	 /* Hauptmenue anlegen */
	 else if(stSteuerung.cFlag[5] == '6')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Menue */
		 return '#';
	 }
	 /* Kommentar */
	 else if(stSteuerung.cFlag[5] == '7')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Kommentar */
		 return '#';
	 }
	 /* Menuepunkt */
	 else if(stSteuerung.cFlag[5] == '8')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Menuepunkt */
		 return '#';
	 }
	 /* Bezeichner */
	 else if(stSteuerung.cFlag[5] == '9')
	 {
		 stSteuerung.cFlag[5] = '\0';
		 /* Zurueck zu Bezeichner */
		 return '#';
	 }
	 /* Kommentare */
	 else if(stSteuerung.cFlag[3] == '0')
	 {
		 stSteuerung.cFlag[3] = '\0';
		 /* Zurueck zu Kommentare in aktueller Position */
		 iEingabe_Kommentare(stMenues.iPos_Kommentar);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Umschalten zwischen der Benutzereingabe und der Menuesteuerung
 * Status   : vorgelegt
 */
 int iMenuesteuerung()
 {
	 /* Flag fuer Hinweis auf 0 setzen */
	 stSteuerung.cFlag[2] = '0';
	 do
	 {
		 /* Textfarbe gruen */
		 iSetze_Textfarbe(10, 22);
		 iSetze_Cursor(20,58);
		 /* sichtbar machen des Modus */
		 printf("Bedienmodus_an__#");
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 iSetze_Cursor(22, 31);
		 printf("< H >  Hilfe");
		 /* Bei 0 ist Anzeige aktiv */
		 if(stSteuerung.cFlag[0] == '0')
		 {
			 iSetze_Cursor(22,8);
			 printf("< M >  Hauptmen%s", ue);
			 iSetze_Cursor(22, 50);
			 printf("< Z >  Zur%sck", ue);
			 iSetze_Cursor(22, 51);
		 }
		 else
		 {
			 iSetze_Cursor(22,8);
			 printf("< B >  Beenden");
		 }
		 iSetze_Cursor(19, 24);
		 /* benoetigt kein Enter */
		 stSteuerung.cModus = iWarte_auf_Taste();
		 switch(stSteuerung.cModus)
		 {
			 /* Bedingung einsetzen, von wo gedrueckt werden darf 
			  * In iAuswahl_Hauptmenue() wird das Flag vom System auf 0 gesetzt.
			  * Bei druecken von m oder z wird zur Fehlerausgabe umgeleitet.
			  * Hat das Flag den Wert 1 wird die eigent. Funktion aufgerufen */
			  case 'm':
			  case 'M':
			  {
				  /* wenn Flag nicht gesetzt */
				  if(stSteuerung.cFlag[0] == '0')
				  {
					  iAuswahl_Hauptmenue();
				  }
				  /* wenn Flag gesetzt */
				  else if(stSteuerung.cFlag[0] == '1')
				  {
					  iHalte_Bedienmodi();
				  }
				  break;
			  }
			  case 'h':
			  case 'H':
			  {
				  stSteuerung.cFlag[4] = '0';
				  iZeige_Hilfe();
				  break;
			  }
			  /* Bedingung einsetzen, von wo gedrueckt werden darf. 
			   * Hier das Gleiche Prinzip, wie im ersten Case */
			   case 'z':
			   case 'Z':
			   {
				   /* Wenn # aus iGeneriere_Code()
				    * gedrueckt, wird Pos. 1 mit #
				    * ersetzt = Aufruf der Funktion
				    * iBezeichne_Menuepunkte() */
				    if(stSteuerung.cFlag[1] == '#')
				    {
						/* Leeren fuer Ruecksprunge aus iGeneriere_Code() */
						stSteuerung.cFlag[1] = '\0';
						iAusgabe_Eingabebildschirm();
						if(stMenues.iAnzahl == 0)
						{
							/* Setzen fuer die Fortsetzung aus
							 * iErstelle_Menuepunkte() */
							 stSteuerung.cFlag[5] = '9';
							 /* Zurueck zu Menuepunkt */
							 iErstelle_Menuepunkte();
						}
						else
						{
							/* Zurueck zu Bezeichner */
							iBezeichne_Menuepunkte();
						}
						return EXIT_SUCCESS;
					}
					else if(stSteuerung.cFlag[0] == '1')
					{
						/* bleibe im aktuellen Menue */
						iHalte_Bedienmodi();
				  }
				  /* Im Eingabescreen hat das
				   * Flag immer den Wert 0
				   * Hier Pos. 0, da keine
				   * aktive Zuweisung, als in
				   * iCode_generieren */
				   else if(stSteuerung.cFlag[0] == '0')
				   {
					   /* erlaube Rueckspruenge */
					   iGehe_zurueck();
				   }
				   break;
			   }
			   case 'b':
			   case 'B':
			   {
				   /* Flag im Hauptmenue gesetzt */
				   if(stSteuerung.cFlag[0] == '1')
				   {
					   /* Flag auf Pos.2 setzen */
					   stSteuerung.cFlag[2] = '1';
					   /* Textfarbe blau */
					   iSetze_Textfarbe(11, 25);
					   iSetze_Cursor(19, 15);
					   printf("M%schten Sie Beenden? j/n: ", oe);
					   /* Textfarbe grau */
					   iSetze_Textfarbe(7, 30);
					   iSetze_Cursor(19, 42);
					   /* User fragen, bevor Code Studio beendet wird */
					   if(iBeenden())
					   {
						   return EXIT_SUCCESS;
					   }
					   else
					   {
						   iHalte_Bedienmodi();
					   }
					   break;
				   }
			   }
			   default:
			   {
				   if(stSteuerung.cModus != '#')
				   {
					   iHalte_Bedienmodi();
					   break;
				   }
			   }
		 }
		 /* Schleife nicht verlassen */
	 }while(stSteuerung.cModus != '#' && stSteuerung.cModus == '#');
	 /* vorherige Eingabemaske aufrufen,
	  * solange keine # in iGeneriere_Code() gedrueckt wurde */
	  if(stSteuerung.cFlag[1] != '#')
	  {
		  iBleibe_hier();
	  }
	  return EXIT_SUCCESS;
 }
