/**
 * Programm : code_studio.c
 * Autor	: Nico Anders
 * Version  : 1.2.0
 * Datum    : 18.11.2011
 * Stand    : 15.02.2014
 * Status   : vorgelegt
 * _____________________________________________________________________________
 * Features : Einsatz auf Linux und Windows
 *          : Metatool welches scannen/parsen der Quellinformation
 *  		: und generieren der Zielformate Ansi-C oder Python
 *_____________________________________________________________________________
 * ToDo's   : automatische Selbstheilung bei beschaedigten Dateien
 *          : Metrikenmesser
 *          : aufhuebschende Animation
 *          : Ueberschrift aus Kommentar
 *          : Metriken LOCs, McCabe
 *_____________________________________________________________________________
 * Erledigt : Grundgeruest bauen
 *	     	: Scanner
 * 		 	: Parser
 * 		 	: Codegenerator (Algorithmus)
 * 		 	: Templates (Generat)
 *          : Hilfsfunktion anlegen
 *          : Flackerfreie Bildschirmausgabe Ansi Standard
 *          : Systemweite Einheit in der Darstellung schaffen
 *          : SetConsoleCursorPosition zum Cursor positionieren (Windows)
 *          : Portierbarer Programmablauf mit ungepufferten Tastendruck
 *          : Dynamische Ausgaben aus Platzmangel
 *          : Verbesserung der Scanneralgorithmen
 *            Coding Style zwischen C und Python anpassen da nur eine
 *            Parserfunktion verwendet werden soll
 *          : Umschalten bei Benutzereingabe mit #
 *          : ANSI Bibliotheken eingebunden
 *          : Praeprozessor Direktive fuer Windows/Linux eingebunden
 *          : Prototypen definiert
 *          : Fertigstellung des Hauptprogramm (weitere Nacharbeiten)
 *          : Screens fertig gestellt
 *          : Fertigstellung des Hauptmenue
 *          : Fertigstellung des Menue fuer Templates C und Python
 *          : Portierbare Funktion mit getch und tcsetattr fuer Programmablauf
 *          : Fertigstellung der Benutzerinteraktion
 *          : Generiert C und Python Code
 *          : Umschaltfunktion in den erweiterten Bedienmodus
 *          : Funktionen fuer gute Pflege in Module ausgelagert
 *            Parser setzt Dateinamen neu und hängt Datum und Format an
 *          : Konvertierung der Anfangsbuchstaben in Grossbuchstaben
 *          : Farbige Hinweise
 *          : Zeitmessung in Microsekunden
 *          : Bibliotheken aus/abwaehlen
 *          : ToDo's um 3 Zeilen erweitert
 *          : Anti-Cheating => leere Eingaben abfangen
 *          : Blätterfunktion
 *          : Generator um C++ Funktion erweitert
 *          : Templates ueberarbeitet
 *          : Vermeidung mehrfaches Inkludieren in Headerfiles
 *          : Validierung von vorbelegten und vergebenen Funktionnamen
 *          : Kuerzung auf zulaessige Stringlaengen
 *          : Menuepunkte per Tastendruck
 *          : Kommentare fuer Menuepunkte
 *          : Generator um Java erweitert
 *          : Objektorientierung
 */

/**
 * Praeprozessor
 * Bibliothek-Einbindung fuer Ansi Ein- und Ausgaben (scanf, printf)
 */
 #include <stdio.h>  					/* Standard-I/O */
 #include <stdlib.h> 				    /* Nuetzliche Funktionen */
 #include <string.h> 				    /* Zeichenkettenoperationen */
 #include <time.h>                      /* Datum und Uhrzeit */
 #include <ctype.h>                     /* Zeichenkonvertierung */
 #include <sys/stat.h>                  /* Unix Systemfunktionen */
 #include "./module/function.h"         /* eig. Header mit eig. Funktionen */
 #include "./module/generator.c"        /* eig. Header, Code generieren */
 #include "./module/control.c"          /* eig. Header fuer Programmsteuerung */
 #include "./module/input.c"            /* eig. Header fuer Benutzereingaben */
 #include "./module/interface.c"        /* eig. Header fuer Bildschirmausgabe */
  
/********************** Hauptprogramm Code Studio *****************************/

/**
 * Funktion : Startbildschirm anzeigen
 * Status   : vorgelegt
 */
 int iStarte_Generator()
 {
	 iAusgabe_Startbildschirm();
	 iSetze_Pause(3);
	 iAuswahl_Hauptmenue();
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Benutzerdaten fuer Programmkopf in C/C++ oder Python eingeben
 * Status   : vorgelegt
 */
 int iErstelle_Programmkopf()
 {
	 /* Arrays fuer neue Auswahl leeren */
	 iLoesche_Auswahl();
	 iEingabe_Dateiname();           
	 iEingabe_Autor(); 
	 iEingabe_Version();
	 iEingabe_Status();
	 iEingabe_ToDos();
	 iAuswahl_Bibliotheken();              
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Menues fuer C/C++ oder Python erzeugen
 * Status   : vorgelegt
 */
 int iErstelle_Funktion()
 {
	 iErstelle_Menue();
	 iEingabe_Beschreibung();
	 iErstelle_Menuepunkte();
	 iBezeichne_Menuepunkte();
	 iGeneriere_Code();
	 return EXIT_SUCCESS;     
 }

/**
 * Funktion : Hauptmenue zum auswaehlen fuer Untermenues
 * Status   : vorgelegt
 */
 int iAuswahl_Hauptmenue()
 {
	 do
	 {
		 /* Funktion fuer die Bildschirmausgabe */
		 iAusgabe_Menuebildschirm();
		 /* Uebergebe die Cursor Position aus dem Modul function.h */
		 iSetze_Cursor(19, 24);
		 /* Uebergabe der Sprache an
		  * struct fuer gemeinsame
		  * Nutzung von iParser */
		  stAuswahl.cSprache = iWarte_auf_Taste();
		  switch(stAuswahl.cSprache)
		  {
			  /* User gelangt in das Ansi-C Menue */
			  case '1':
			  {
				  /* Weiter mit Dateiname eing. */
				  stSteuerung.cFlag[5] = '0';
				  iErstelle_Programmkopf();
				  break;
			  }
			  /* User gelangt in das Python Menue */
			  case '2':
			  {
				  /* Weiter mit Dateiname eing. */
				  stSteuerung.cFlag[5] = '0';
				  iErstelle_Programmkopf();
				  break;
			  }
			  /* User gelangt in das C++ Menue */
			  case '3':
			  {
				  /* Weiter mit Dateiname eing. */
				  stSteuerung.cFlag[5] = '0';
				  iErstelle_Programmkopf();
				  break;
			  }
			  /* User gelangt in das Java Menue */
			  case '4':
			  {
				  /* Weiter mit Dateiname eing. */
				  stSteuerung.cFlag[5] = '0';
				  iErstelle_Programmkopf();
				  break;
			  }
			  /* Nur im Bedienmodus verfuegbar */
			  case 'h':
			  case 'H':
			  case 'b':
			  case 'B':
			  {
				  /* Hinweis bei falscher Eingabe anzeigen */
				  iZeige_Hinweis(1);
				  break;
			  }
			  /* wird der Modus im Hauptmenue
			   * gedrueckt, wird das Flag auf Eins
			   * gesetzt und es erfolgt eine Trennung
			   * der Modusanzeige/-auswahl */
			   case '#':
			   {
				   /* Zurueck wird hier deaktivert */
				   stSteuerung.cFlag[0] = '1';
				   iMenuesteuerung();
				   break;
			   }
			   default:
			   {
				   iZeige_Hinweis(0);
				   break;
			   }
		  }
	 }while(stAuswahl.cSprache != 'b' || stAuswahl.cSprache != 'B');
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Code in C/C++ oder Python generieren lassen oder hinzufuegen
 * Status   : vorgelegt
 */
 int iGeneriere_Code()
 {
	 stSteuerung.cFlag[0] = '0';
	 do
	 {
		 iAusgabe_Generierungsbildschirm();
		 iSetze_Cursor(20, 58);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 printf("Bedienmodus_aus_#");
		 iSetze_Cursor(22, 50);
		 /* Eingabefeld ausgegraut */
		 iSetze_Textfarbe(8, 22);  
		 printf("< Z >  Zur%sck ", ue);
		 iSetze_Cursor(19, 24);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 stSteuerung.cFlag[1] = iWarte_auf_Taste();
		 switch(stSteuerung.cFlag[1])
		 {
			 case '1':
			 {
				 iJaNein();
				 break;
			 }
			 /* Ruecksprung, falls Bibliotheken vergessen wurden */
			 case '2':
			 {
				 /* cFlag speichert Wert 2, ueberspringt Menueabfrage */
				 iAuswahl_Bibliotheken();
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
				 /* Zurueck zu Bezeichner */
				 iMenuesteuerung();
				 break;
			 }
			 default:
			 {
				 iZeige_Hinweis(0);
				 break;
			 }
		 }
	 }while(stSteuerung.cFlag[1] != 'm' || stSteuerung.cFlag[1] != 'M');
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Hilfe anzeigen
 * Status   : vorgelegt
 */
 int iZeige_Hilfe()
 {
	 do
	 {
		 /* Die 1. Seite der Hilfe aufrufen */
		 iAusgabe_Hilfebildschirm();
		 /* benoetigt kein zusaetzliches Enter */
		 stSteuerung.cModus = iWarte_auf_Taste();
		 switch(stSteuerung.cModus)
		 {
			 case 'm':
			 case 'M':
			 {
				 /* zum aktuellen Menue wenn Hilfe beendet */
				 iAusgabe_Eingabebildschirm();
				 continue;
			 }
			 case '\n':
			 case '\r':
			 {
				 /* Flag auf naechst. Seite setzen */
				 stSteuerung.cFlag[4] = '1';
				 /* naechstes Hilfekapitel aufrufen */
				 iAusgabe_Hilfebildschirm();
				 break;
			 }
			 case 'z':
			 case 'Z':
			 {
				 /* vorheriges Kapitel aufrufen */
				 stSteuerung.cFlag[4] = '0';
				 iAusgabe_Hilfebildschirm();
				 break;
			 }
			 case '#':
			 {
				 iSetze_Cursor(20,58);
				 /* Textfarbe gruen */
				 iSetze_Textfarbe(10, 22);
				 printf("Bedienmodus_an__#");
				 iSetze_Cursor(19, 15);
				 /* Textfarbe gelb */
				 iSetze_Textfarbe(14, 19);
				 printf("Modus ist bereits aktiv. Dr%scken Sie Enter.", ue);
				 stAuswahl.cTaste = iWarte_auf_Taste();
				 break;
			 }
			 default:
			 {
				 iZeige_Hinweis(0);
			 }
		 }
	 }while(stSteuerung.cModus != 'm' && 'M');
	 return EXIT_SUCCESS;
 }

/**
 * Steuerprogramm                                                          
 */
 int iController()
 {
     iStarte_Generator();
	 return EXIT_SUCCESS;
 }

/**
 * Hauptprogramm
 */
 int main()
 {
	 iController();
	 return EXIT_SUCCESS;
 }

/**
 * Programmende
 */
