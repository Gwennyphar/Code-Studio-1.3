/*************************** Codegenerator ************************************/

/**
 * Makros
 */
 #define C    "./dat/main.c"
 #define CPP  "./dat/main.cpp"
 #define PY   "./dat/main.py"
 #define JAVA "./dat/main.java"
  
/**
 * Umlaute ASCII UTF8
 * \x81=ü \x84=ä \x94=ö \x8E=Ä \x99=Ö \x9A=Ü \xE1=ß");
 */
 #ifdef __linux__
 #define Ae "Ä"
 #define ae "ä"
 #define Ue "Ü"
 #define ue "ü"
 #define Oe "Ö"
 #define oe "ö"
 #define ss "ß"
 #elif __WIN32__ || _MSC_VER__
 #define Ae "\x8E"
 #define ae "\x84"
 #define Ue "\x9A"
 #define ue "\x81"
 #define Oe "\x99"
 #define oe "\x94"
 #define ss "\xE1"
 #endif

/**
 * Prototypen (speziell fuer den gcc Compiler unter Linux)
 */
 int iAusgabe_Eingabebildschirm();
 int iAusgabe_Auswahlbildschirm();
 int iHauptmenue();
 int iErstelle_Funktion();
 int iGeneriere_Code();
 int iMenuesteuerung();
  
/**
 * Funktion : Structs fuer globale Uebergabe von Benutzereingaben, Sprachauswahl
 * Status   : vorgelegt
 */
 struct Programmiersprache
 {
	 /* speichert Auswahl Programmiersprache */
	 char cSprache;
	 /* Header aus iBibliotheken speichern */
	 char sBibliothek[10][85];
	 /* Vermeidet doppelte Auswahl gegen Overflow */
	 int iAuswahl[10];
	 char cTaste;
 }stAuswahl;

/**
 * Struct fuer Programmkopf
 */ 
 struct Programmkopf
 {
	 /* Programmname speichern fuer Datei */
	 char  sDateiname[255];
	 char  sAutor[255];
	 char  sVersion[255];
	 /* generiert auch den aktuellen Stand */
	 char  sStatus[255];
	 char  sToDo[3][255];
	 int   iPos_ToDo;
	 float fDiff;
	 /* ermittelt die eingegebene Stringlaenge */
	 int iSize;
	 /* letztes Zeichen am $ aus File entfernen */
	 char  sLeer[0];
 }stEingaben;

/**
 * Struct fuer Menuefunktion
 */
 struct Hauptmenu
 {
	 char sBezeichnung[255];
	 char sBeschriftung[255];
	 char sKommentar[255];
 }stFunktion;

/**
 * Struct fuer Menuepunkte
 */
 struct Menupunkt
 {
	 int  iAnzahl;
	 int  iPos_Kommentar;
	 int  iPos_Cursor;
	 char sPos_Cursor[2];
	 /* Menuebezeichnung speichern */
	 char sMenuepunkt[5][255];
	 char sMenuetext[5][255];
	 char sKommentare[5][255];
 }stMenues;

/**
 * Struct fuer Programmkopf
 */ 
 struct Steuerung
 {
	 char cModus;
	 /* vergleicht folgende Funktionsaufrufe:
	  * 0 = Flag nicht gesetzt, 1 = Flag gesetzt
	  * Pos. 0 = 1 Trennung der Bedienanzeige
	  * Pos. 1 = 1 Aufruf zwischen iCode() und iBibl.
	  * Pos. 2 = 1 Trennung der Warnung beim Beenden
	  * Pos. 3 = 1 Trennung der Hilfeseite
	  * Pos. 4 = 1 Trennung der Eingabemasken */
	  char cFlag[5];
 }stSteuerung;

/**
 * Struct fuer Zeitberechnung
 */
 struct Benchmarking
 {
	 time_t tZeit_Start;
	 time_t tZeit_Ende;
	 float  fZeit_Diff;
 }stZeitmessung;

/**
 * Funktion : Leert das Array fuer neue Auswahlen
 * Status   : vorgelegt
 */
 int iLoesche_Auswahl()
 {
	 int iIndex = 0;
	 for(iIndex = 0; iIndex < 10; iIndex++)
	 {
		 /* Auswahl aus Bibliothekenarray loeschen */
		 stAuswahl.sBibliothek[iIndex][0] = '\0';
		 /* Belegte Position aus Bibliothekenarray freigeben */
		 stAuswahl.iAuswahl[iIndex] = 0;
	 }
	 for(iIndex = 0; iIndex < stEingaben.iPos_ToDo; iIndex++)
	 {
		 /* ToDo's aus Eingabearray loeschen */
		 stEingaben.sToDo[iIndex][0] = '\0';
	 }
	 for(iIndex = 0; iIndex < stMenues.iAnzahl; iIndex++)
	 {
		 /* Menuepunkte aus Eingabearray loeschen */
		 stMenues.sMenuepunkt[iIndex][0] = '\0';
		 stMenues.sMenuetext[iIndex][0]  = '\0';
		 stMenues.sKommentare[iIndex][0] = '\0';
	 }
	 for(iIndex = 0; iIndex < 5; iIndex++)
	 {
		 /* Auswahl aus Eingabearray loeschen */
		 stSteuerung.cFlag[iIndex] = '\0';
	 }
	 /* Zaehler wieder zuruecksetzen und von Null beginnen */
	 stMenues.iAnzahl         = 0;
	 stMenues.iPos_Kommentar  = 0;
	 stEingaben.iPos_ToDo     = 0;
	 stEingaben.fDiff         = 0;
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Generiert ein C/C++ oder Python Codegeruest in einem Durchlauf
 * Status   : vorgelegt
 */
 int iGenerator(const char *sParsen, FILE *FPLesen, FILE *FPSchreiben)
 {
	 char cSchnipsel;
	 /* Zeitmessung starten */
	 time(&stZeitmessung.tZeit_Start);
	 /* wiederhole bis zum letzten $ */
	 while ((cSchnipsel = fgetc(FPLesen)) != '$')
	 {
		 /* benoetigt nur eine Funktion */
		 fprintf(FPSchreiben, "%c", cSchnipsel);
	 }
	 /* ersetze $ durch Benutzereingabe */
	 fprintf(FPSchreiben, "%s", sParsen);
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Benutzereingaben an Generator uebergeben
 * Status   : vorgelegt
 */
 int iParser()
 {
	 int    iZeile  = 0;
	 int    iLaenge = 0;
	 int    iIndex  = 0;
	 char   *sDatum;
	 char   sPfad[255] = {"projekt/"};
	 char   sDatei[255];
	 char   *cZeichen;
	 time_t tDatum;
	 FILE   *FPLesen;
	 FILE   *FPSchreiben;
	 /* Template fuer C oeffnen */
	 if(stAuswahl.cSprache == '1')
	 {
		 FPLesen = fopen(C, "r");
		 /* pruefe ob die Datei existiert */
		 if(FPLesen == NULL)
		 {
			 iSetze_Cursor(19, 15);
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht gelesen werden!",C);
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 stAuswahl.cTaste = iWarte_auf_Taste();
			 return EXIT_FAILURE;
		 }
	 }
	 /* Template fuer Python oeffnen */
	 else if(stAuswahl.cSprache == '2')
	 {
		 FPLesen = fopen(PY, "r");
		 /* pruefe ob die Datei existiert */
		 if(FPLesen == NULL)
		 {
			 iSetze_Cursor(19, 15);
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht gelesen werden!",PY);
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 stAuswahl.cTaste = iWarte_auf_Taste();
			 return EXIT_FAILURE;
		 }
	 }
	 /* Template fuer C++ oeffnen */
	 else if(stAuswahl.cSprache == '3')
	 {
		 FPLesen = fopen(CPP, "r");
		 /* pruefe ob die Datei existiert */
		 if(FPLesen == NULL)
		 {
			 iSetze_Cursor(19, 15);
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht gelesen werden!",CPP);
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 stAuswahl.cTaste = iWarte_auf_Taste();
			 return EXIT_FAILURE;
		 }
	 }
	 /* Template fuer Java oeffnen */
	 else if(stAuswahl.cSprache == '4')
	 {
		 FPLesen = fopen(JAVA, "r");
		 /* pruefe ob die Datei existiert */
		 if(FPLesen == NULL)
		 {
			 iSetze_Cursor(19, 15);
			 /* Textfarbe rot */
			 iSetze_Textfarbe(12, 19);
			 /* Cursor positionieren */
			 iSetze_Cursor(19, 15);
			 printf("Fehler: '%s' kann nicht gelesen werden!",JAVA);
			 /* Textfarbe grau */
			 iSetze_Textfarbe(7, 30);
			 stAuswahl.cTaste = iWarte_auf_Taste();
			 return EXIT_FAILURE;
		 }
	 }
	 /* Leerzeichen im Dateinamen entfernen */
	 while((cZeichen = strchr(stEingaben.sDateiname, ' ')) != NULL)
	 {
		 *cZeichen = '_';
	 }
	 /* Bindestriche im Dateinamen entfernen */
	 while((cZeichen = strchr(stEingaben.sDateiname, '-')) != NULL)
	 {
		 *cZeichen = '_';
	 }
	 /* Anfangsbuchstaben in Grossbuchstaben umwandeln */
	 stEingaben.sDateiname[0] = toupper(stEingaben.sDateiname[0]);
	 /* Dateiname als Programmname verwenden */
	 strncpy(sDatei,stEingaben.sDateiname, sizeof(sDatei));
	 /* Dateiformat an Datei anhaengen */
	 if(stAuswahl.cSprache == '1')
	 {
		 strncat(sDatei, ".c", sizeof(sDatei));
	 }
	 else if(stAuswahl.cSprache == '2')
	 {
		 strncat(sDatei, ".py", sizeof(sDatei));
	 }
	 else if(stAuswahl.cSprache == '3')
	 {
		 strncat(sDatei, ".cpp", sizeof(sDatei));
	 }
	 else if(stAuswahl.cSprache == '4')
	 {
		 strncat(sDatei, ".java", sizeof(sDatei));
	 }
	 /* Eine kleine Pause einlegen */
	 iSetze_Cursor(19, 15);
	 /* Textfarbe blau */
	 iSetze_Textfarbe(11, 25);
	 printf("Einen Moment bitte...       \n");
	 iSetze_Cursor(19, 40);
	 /* Textfarbe grau */
	 iSetze_Textfarbe(7, 30);
	 /* Warte 1 Sekunde */
	 iSetze_Pause(1);
	 /* Vorher pruefen, ob Verzeichnis erstellt werden muss */
	 if(stat != NULL)
	 {
		 /* Neues Verzeichnis erstellen */
		 iErstelle_Ordner(sPfad);
	 }
	 strncat(sPfad,sDatei, sizeof(sPfad));
	 /* Datei anlegen */
	 FPSchreiben = fopen(sPfad, "w");
	 /* Unterstriche im Dateinamen entfernen */
	 while((cZeichen = strchr(stEingaben.sDateiname, '_')) != NULL)
	 {
		 *cZeichen = ' ';
	 }
	 /* Dateinamen als Programmname speichern */
	 iGenerator(stEingaben.sDateiname,FPLesen,FPSchreiben);
	 /* Anfangsbuchstaben in Grossbuchstaben umwandeln */
	 stEingaben.sAutor[0] = toupper(stEingaben.sAutor[0]);
	 /* Autor abspeichern */
	 iGenerator(stEingaben.sAutor, FPLesen, FPSchreiben);
	 /* Version abspeichern */
	 iGenerator(stEingaben.sVersion, FPLesen, FPSchreiben);
	 /* Datum abspeichern */
	 /* Zeilenumbruch entfernen */
	 time(&tDatum);
	 sDatum = ctime(&tDatum);
	 /* Zeilenumbruch nach Datum entfernen */
	 sDatum[strlen(sDatum)-1] = '\0';
	 iGenerator(sDatum, FPLesen, FPSchreiben);
	 /* Anfangsbuchstaben in Grossbuchstaben umwandeln */
	 stEingaben.sStatus[0] = toupper(stEingaben.sStatus[0]);
	 /* Status im Programmkopf abspeichern */
	 iGenerator(stEingaben.sStatus, FPLesen, FPSchreiben);
	 /* ToDo's abspeichern */
	 for(iZeile = 0; iZeile < stEingaben.iPos_ToDo; iZeile++)
	 {
		 iGenerator(stEingaben.sToDo[iZeile], FPLesen, FPSchreiben);
	 }
	 /* Kommentarende abspeichern */
   	 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
   	 /* Letztes Zeichen aus Datei entfernen  */
     iGenerator(stEingaben.sLeer,FPLesen,FPSchreiben);
     /* Standard C-Bibliotheken */
     if(stAuswahl.cSprache == '1')
     {
		 /* math.h */
		 strncpy(stAuswahl.sBibliothek[0],
		 " #include <math.h>                     "
		 "/* Mathematische Funktionen */",
		 sizeof(stAuswahl.sBibliothek[0]));
		 /* string.h */
		 strncpy(stAuswahl.sBibliothek[1],
		 " #include <string.h>                   "
		 "/* Zeichenkettenoperationen */",
		 sizeof(stAuswahl.sBibliothek[1]));
		 /* time.h */
		 strncpy(stAuswahl.sBibliothek[2],
		 " #include <time.h>                     "
		 "/* Datum und Uhrzeit */",
		 sizeof(stAuswahl.sBibliothek[2]));
		 strncpy(stAuswahl.sBibliothek[3],
		 " #include <ctype.h>                    "
		 "/* Zeichenkonvertierung */",
		 sizeof(stAuswahl.sBibliothek[3]));
		 /* limits.h */
		 strncpy(stAuswahl.sBibliothek[4],
		 " #include <limits.h>                   "
		 "/* Implementierungskonstanten */",
		 sizeof(stAuswahl.sBibliothek[4]));
		 /* float.h */
		 strncpy(stAuswahl.sBibliothek[5],
		 " #include <float.h>                    "
		 "/* Eigschft. Gleitpunkttypen */",
		 sizeof(stAuswahl.sBibliothek[5]));
		 /* stdlib.h */
		 strncpy(stAuswahl.sBibliothek[6],
		 " #include <stdlib.h>                   "
		 "/* Speicherplatz allokieren */",
		 sizeof(stAuswahl.sBibliothek[6]));
		 /* stdarg.h */
		 strncpy(stAuswahl.sBibliothek[7],
		 " #include <stdarg.h>                   "
		 "/* Variable Parameteruebergabe */",
		 sizeof(stAuswahl.sBibliothek[7]));
		 /* signal.h */
		 strncpy(stAuswahl.sBibliothek[8],
		 " #include <signal.h>                   "
		 "/* Signale behandeln */",
		 sizeof(stAuswahl.sBibliothek[8]));
		 /* assert.h */
		 strncpy(stAuswahl.sBibliothek[9],
		 " #include <assert.h>                   "
		 "/* Fehlersuche und Debugging */",
		 sizeof(stAuswahl.sBibliothek[9]));
	 }
	 /* Python-Bibliotheken */
	 else if(stAuswahl.cSprache == '2')
	 {
		 /* math */
		 strncpy(stAuswahl.sBibliothek[0],
		 "import math                          "
		 "# Mathematische Funktionen",
		 sizeof(stAuswahl.sBibliothek[0]));
		 /* string */
		 strncpy(stAuswahl.sBibliothek[1],
		 "import string                        "
		 "# Zeichenkettenoperationen",
		 sizeof(stAuswahl.sBibliothek[1]));
		 /* datetime */
		 strncpy(stAuswahl.sBibliothek[2],
		 "import datetime                      "
		 "# Datum und Uhrzeit",
		 sizeof(stAuswahl.sBibliothek[2]));
		 /* random */
		 strncpy(stAuswahl.sBibliothek[3],
		 "import random                        "
		 "# Zufallsgesteuerte Operationen",
		 sizeof(stAuswahl.sBibliothek[3]));
		  /* pickle */
		 strncpy(stAuswahl.sBibliothek[4],
		 "import pickle                        "
		 "# Datenstrukturen zu Bytefolge konvertieren",
		 sizeof(stAuswahl.sBibliothek[4]));
		  /* codecs */
		 strncpy(stAuswahl.sBibliothek[5],
		 "import codecs                        "
		 "# Wandeln von Unicode-Zeichenkette",
		 sizeof(stAuswahl.sBibliothek[5]));
		 /* os */
		 strncpy(stAuswahl.sBibliothek[6],
		 "import os                            "
		 "# Betriebsystemfunktionen",
		 sizeof(stAuswahl.sBibliothek[6]));
		 /* re */
		 strncpy(stAuswahl.sBibliothek[7],
		 "import re                            "
		 "# regulaere Ausdruecke",
		 sizeof(stAuswahl.sBibliothek[7]));
		 /* gtk */
		 strncpy(stAuswahl.sBibliothek[8],
		 "import gtk                           "
		 "# Anbindung an die GUI-Bibliothek GTK",
		 sizeof(stAuswahl.sBibliothek[8]));
		 /* cgi */
		 strncpy(stAuswahl.sBibliothek[9],
		 "import cgi                           "
		 "# Einfache CGI-Schnittstelle",
		 sizeof(stAuswahl.sBibliothek[9]));
	 }
	 /* Standard C++ Bibliotheken */
	 if(stAuswahl.cSprache == '3')
	 {
		 /* cmath */
		 strncpy(stAuswahl.sBibliothek[0],
		 " #include <cmath>                      "
		 "// Mathematische Funktionen",
		 sizeof(stAuswahl.sBibliothek[0]));
		 /* cstring */
		 strncpy(stAuswahl.sBibliothek[1],
		 " #include <cstring>                    "
		 "// Zeichenkettenoperationen",
		 sizeof(stAuswahl.sBibliothek[1]));
		 /* ctime */
		 strncpy(stAuswahl.sBibliothek[2],
		 " #include <ctime>                      "
		 "// Datum und Uhrzeit",
		 sizeof(stAuswahl.sBibliothek[2]));
		 /* cmath */
		 strncpy(stAuswahl.sBibliothek[3],
		 " #include <cctype>                     "
		 "// Zeichenkonvertierung",
		 sizeof(stAuswahl.sBibliothek[3]));
		 /* climits */
		 strncpy(stAuswahl.sBibliothek[4],
		 " #include <climits>                    "
		 "// Implementierungskonstanten",
		 sizeof(stAuswahl.sBibliothek[4]));
		 /* cfloat */
		 strncpy(stAuswahl.sBibliothek[5],
		 " #include <cfloat>                     "
		 "// Eigschft. Gleitpunkttypen",
		 sizeof(stAuswahl.sBibliothek[5]));
		 /* cstdlib */
		 strncpy(stAuswahl.sBibliothek[6],
		 " #include <cstdlib>                    "
		 "// Speicherplatz allokieren",
		 sizeof(stAuswahl.sBibliothek[6]));
		 /* fstream */
		 strncpy(stAuswahl.sBibliothek[7],
		 " #include <fstream>                    "
		 "// Dateioperationen",
		 sizeof(stAuswahl.sBibliothek[7]));
		 /* csignal */
		 strncpy(stAuswahl.sBibliothek[8],
		 " #include <csignal>                    "
		 "// Signale behandeln",
		 sizeof(stAuswahl.sBibliothek[8]));
		 /* cassert */
		 strncpy(stAuswahl.sBibliothek[9],
		 " #include <cassert>                    "
		 "// Fehlersuche und Debugging",
		 sizeof(stAuswahl.sBibliothek[9]));
	 }
	 /* Java Bibliotheken */
	 if(stAuswahl.cSprache == '4')
	 {
		 /* java.math */
		 strncpy(stAuswahl.sBibliothek[0],
		 " import java.math.*;                   "
		 "// Mathematische Funktionen",
		 sizeof(stAuswahl.sBibliothek[0]));
		 /* java.text */
		 strncpy(stAuswahl.sBibliothek[1],
		 " import java,text.*;                   "
		 "// Verarbeitung von Text",
		 sizeof(stAuswahl.sBibliothek[1]));
		 /* java.io */
		 strncpy(stAuswahl.sBibliothek[2],
		 " import java.io.*;                     "
		 "// Ein/Ausgabe und Dateiverwaltung",
		 sizeof(stAuswahl.sBibliothek[2]));
		 /* java.lang */
		 strncpy(stAuswahl.sBibliothek[3],
		 " import java.lang.*;                   "
		 "// Grundklassen",
		 sizeof(stAuswahl.sBibliothek[3]));
		 /* java.net */
		 strncpy(stAuswahl.sBibliothek[4],
		 " import java.net.*;                    "
		 "// Netzwerkprogrammierung",
		 sizeof(stAuswahl.sBibliothek[4]));
		 /* java.security */
		 strncpy(stAuswahl.sBibliothek[5],
		 " import java.security.*;               "
		 "// Zugriffskontrollen",
		 sizeof(stAuswahl.sBibliothek[5]));
		 /* java.applet */
		 strncpy(stAuswahl.sBibliothek[6],
		 " import java.applet.*;                 "
		 "// Applets",
		 sizeof(stAuswahl.sBibliothek[6]));
		 /* java.beans */
		 strncpy(stAuswahl.sBibliothek[7],
		 " import java.beans.*;                  "
		 "// Beans-Komponenten",
		 sizeof(stAuswahl.sBibliothek[7]));
		 /* java.awt */
		 strncpy(stAuswahl.sBibliothek[8],
		 " import java.awt.*;                    "
		 "// AWT-Klassen",
		 sizeof(stAuswahl.sBibliothek[8]));
		 /* java.swing */
		 strncpy(stAuswahl.sBibliothek[9],
		 " import java.swing.*;                  "
		 "// Swing-Klassen",
		 sizeof(stAuswahl.sBibliothek[9]));
	 }
	 /* Anzahl der Header aus Struct holen und in Datei schreiben */
	 for(iZeile = 0; iZeile < 10; iZeile++)
	 {
		 /* schreibt nur so viel Zeilen in die Datei,
		  * wie Bibliotheken ausgewaehlt wurden */
		  if(stAuswahl.iAuswahl[iZeile] == 1)
		  {
			  fprintf(FPSchreiben, "%s\n", stAuswahl.sBibliothek[iZeile]);
		  }
	 }
	 /* Klassenbezeichner fuer Java erstellen */
	 if(stAuswahl.cSprache == '4')
	 {
		  /* Leerzeichen im Dateinamen entfernen */
		  while((cZeichen = strchr(stEingaben.sDateiname, ' ')) != NULL)
		  {
			  *cZeichen = '_';
		  }
		  /* Dateinamen als Klassenbezeichner speichern */
		  iGenerator(stEingaben.sDateiname,FPLesen,FPSchreiben);
		  /* letztes Zeichen aus Datei entfernen */
		  iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 }
	 /* Anfangsbuchstaben in Grossbuchstaben umwandeln */
	 stFunktion.sBezeichnung[0] = toupper(stFunktion.sBezeichnung[0]);
	 /* Menuepunkte generieren */
	 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
	 {
		 /* Menuepunkte als Auswahltext kopieren */
		 iLaenge = strlen(stMenues.sMenuepunkt[iZeile]);
		 for(iIndex = 0; iIndex < iLaenge; iIndex++)
		 {
			 stMenues.sMenuetext[iZeile][iIndex]
			 = stMenues.sMenuepunkt[iZeile][iIndex];
		 }
		 /* Anfangsbuchstaben in Grossbuchstaben umwandeln */
		 stMenues.sMenuepunkt[iZeile][0]
		 = toupper(stMenues.sMenuepunkt[iZeile][0]);
		 stMenues.sMenuetext[iZeile][0]
		 = toupper(stMenues.sMenuetext[iZeile][0]);
		 stMenues.sKommentare[iZeile][0]
		 = toupper(stMenues.sKommentare[iZeile][0]);
		 /* Leerzeichen im Menuepunkt entfernen */
		 while((cZeichen = strchr(stMenues.sMenuepunkt[iZeile], ' ')) != NULL)
		 {
			 *cZeichen = '_';
		 }
	 }
	 /* Unterfunktionen in C erzeugen */
	 if(stAuswahl.cSprache == '1' && stMenues.iAnzahl > 0)
	 {
		 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
		 {
			 fprintf(FPSchreiben,
			 "\n/**\n"
			 " * Funktion..: %s\n"
			 " * Status....: %s\n"
			 " */\n"
			 " int i%s()\n"
			 " {\n"
			 "     /* mache etwas... */\n"
			 "     return 0;\n"
			 " }\n",
			 stMenues.sKommentare[iZeile],
			 stEingaben.sStatus, stMenues.sMenuepunkt[iZeile]);
		 }
	 }
	 /* Unterfunktionen in Python erzeugen */
	 if(stAuswahl.cSprache == '2' && stMenues.iAnzahl > 0)
	 {
		 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
		 {
			 fprintf(FPSchreiben,
			 "\n\"\"\"\n"
			 "Funktion..: %s\n"
			 "Status....: %s\n"
			 "\"\"\"\n"
			 "def %s(self):\n"
			 "    # mache etwas...\n"
			 "    %s();",
			 stMenues.sKommentare[iZeile], stEingaben.sStatus,
			 stMenues.sMenuepunkt[iZeile], stFunktion.sBezeichnung);
		 }
	 }
	 /* Unterfunktionen in C++ erzeugen */
	 if(stAuswahl.cSprache == '3' && stMenues.iAnzahl > 0)
	 {
		 /* letztes Zeichen aus Datei entfernen */
		 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
		 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
		 {
			 fprintf(FPSchreiben,
			 "\n/**\n"
			 " * Funktion..: %s\n"
			 " * Status....: %s\n"
			 " */\n"
			 " int i%s()\n"
			 " {\n"
			 "     // mache etwas...\n"
			 "     return 0;\n"
			 " }\n",
			 stMenues.sKommentare[iZeile],
			 stEingaben.sStatus, stMenues.sMenuepunkt[iZeile]);
		 }
	 }
	 /* Klassenbezeichner fuer C++ erstellen */
	 if(stAuswahl.cSprache == '3')
	 {
		  /* Leerzeichen im Dateinamen entfernen */
		  while((cZeichen = strchr(stEingaben.sDateiname, ' ')) != NULL)
		  {
			  *cZeichen = '_';
		  }
		  /* Schreibe Leerzeile, wenn kein Menuepunkt ausgewaehlt wurde */
		  if(stMenues.iAnzahl == 0)
		  {
			  /* letztes Zeichen aus Datei entfernen */
			  iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
		  }
		  /* Dateinamen als Klassenbezeichner speichern */
		  iGenerator(stEingaben.sDateiname,FPLesen,FPSchreiben);
	 }
	 /* Unterfunktionen in Java erzeugen */
	 if(stAuswahl.cSprache == '4' && stMenues.iAnzahl > 0)
	 {
		 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
		 {
			 fprintf(FPSchreiben,
			 "\n     /**\n"
			 "      * Funktion..: %s\n"
			 "      * Status....: %s\n"
			 "      */\n"
			 "      public void %s()\n"
			 "      {\n"
			 "          // mache etwas...\n"
			 "      }\n",
			 stMenues.sKommentare[iZeile],
			 stEingaben.sStatus, stMenues.sMenuepunkt[iZeile]);
		 }
	 }
	 /* Kommentar im Funktionskopf abspeichern */
	 iGenerator(stFunktion.sKommentar, FPLesen, FPSchreiben);
	 /* Status im Funktionskopf abspeichern */
	 iGenerator(stEingaben.sStatus, FPLesen, FPSchreiben);
	 /* letztes Zeichen aus Datei entfernen */
	 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 /* Bezeichner als Ueberschrift kopieren */
	 iLaenge = strlen(stFunktion.sBezeichnung);
	 for(iIndex = 0; iIndex < iLaenge; iIndex++)
	 {
		 stFunktion.sBeschriftung[iIndex]
		 = stFunktion.sBezeichnung[iIndex];
	 }
	 /* Leerzeichen im Bezeichner entfernen */
	 while((cZeichen = strchr(stFunktion.sBezeichnung, ' ')) != NULL)
	 {
		 *cZeichen = '_';
	 }
	 /* Bezeichnung im Funktionskopf abspeichern */
	 iGenerator(stFunktion.sBezeichnung, FPLesen, FPSchreiben);
	 /* Bezeichnung als Ueberschrift abspeichern */
	 iGenerator(stFunktion.sBeschriftung, FPLesen, FPSchreiben);
	 /* letztes Zeichen aus Datei entfernen */
	 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 /* Menuepunkte in C erzeugen */
	 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
	 {
		 if(stAuswahl.cSprache == '1' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben,
			 "\n         printf(\"\\n\\t< %i > %s\");",
			 iZeile, stMenues.sMenuetext[iZeile]);
		 }
		 /* Menuepunkte in Python erzeugen */
		 else if(stAuswahl.cSprache == '2' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n    print \"\\t< %i > %s\"",
			 iZeile, stMenues.sMenuetext[iZeile]);
		 }
		 /* Menuepunkte in C++ erzeugen */
		 if(stAuswahl.cSprache == '3' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n                 "
			 "cout << \"\\t< %i > %s\" << endl;",
			 iZeile, stMenues.sMenuetext[iZeile]);
		 }
		 /* Menuepunkte in Java erzeugen */
		 if(stAuswahl.cSprache == '4' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n              "
			 "System.out.println(\"\\t< %i > %s\");",
			 iZeile, stMenues.sMenuetext[iZeile]);
		 }
	 }
	 /* letztes Zeichen aus Datei entfernen */
	 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 /* Switch-Cases in C erzeugen */
	 for(iZeile = 1; iZeile <= stMenues.iAnzahl; iZeile++)
	 {
		 if(stAuswahl.cSprache == '1' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n             case '%i':\n"
			 "             {\n"
			 "                 i%s();\n"
			 "                 break;\n"
			 "             }",
			 iZeile, stMenues.sMenuepunkt[iZeile]);
		 }
		 /* Switch-Cases in Pyhton erzeugen */
		 else if(stAuswahl.cSprache == '2' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n        if Auswahl == '%i':\n"
			 "           %s(object)", iZeile, stMenues.sMenuepunkt[iZeile]);
		 }
		 /* Switch-Cases in C++ erzeugen */
		 if(stAuswahl.cSprache == '3' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n                     case '%i':\n"
			 "                     {\n"
			 "                         i%s();\n"
			 "                         break;\n"
			 "                     }",
			 iZeile, stMenues.sMenuepunkt[iZeile]);
		 }
		 /* Switch-Cases in Java erzeugen */
		 if(stAuswahl.cSprache == '4' && stMenues.iAnzahl > 0)
		 {
			 fprintf(FPSchreiben, "\n                     case '%i':\n"
			 "                     {\n"
			 "                         %s();\n"
			 "                         break;\n"
			 "                     }",
			 iZeile, stMenues.sMenuepunkt[iZeile]);
		 }
	 }
	 /* Klammer wird extra erzeugt, zum beibehaelten der Pos. in Datei */
	 if(stAuswahl.cSprache == '2')
	 {
		 iGenerator(stFunktion.sBezeichnung, FPLesen, FPSchreiben);
		 fprintf(FPSchreiben,"()");
		 /* letztes Zeichen aus Datei entfernen */
		 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 }
	 /* Main und Controller erzeugen */
	 if(stAuswahl.cSprache == '1' || stAuswahl.cSprache == '2')
	 {
		 /* Schreibe Funktionsbezeichner in Controller */
		 iGenerator(stFunktion.sBezeichnung, FPLesen, FPSchreiben);
		 /* letztes Zeichen aus Datei entfernen */
		 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 }
	 else if(stAuswahl.cSprache == '3' || stAuswahl.cSprache == '4')
	 {
		 /* Schreibe Klassebezeichner als Kommentar */
		 iGenerator(stEingaben.sDateiname, FPLesen, FPSchreiben);
		 /* Schreibe Klassenbezeichner in Controller */
		 iGenerator(stEingaben.sDateiname, FPLesen, FPSchreiben);
		 /* Schreibe Klassenbezeichner als Instanz */
		 iGenerator(stEingaben.sDateiname, FPLesen, FPSchreiben);
		 /* Java benoetigt Initalisierung fuer Objekte */
		 if(stAuswahl.cSprache == '4')
		 {
			 /* Schreibe Klassenbezeichner als Instanz */
			 iGenerator(stEingaben.sDateiname, FPLesen, FPSchreiben);
		 }
		 /* Schreibe Instanzbezeichner vor die Funktion im Controller */
		 iGenerator(stEingaben.sDateiname, FPLesen, FPSchreiben);
		 /* Schreibe Methodenbezeichner in Controller */
		 iGenerator(stFunktion.sBezeichnung, FPLesen, FPSchreiben);
		 /* letztes Zeichen aus Datei entfernen */
		 iGenerator(stEingaben.sLeer, FPLesen, FPSchreiben);
	 }
	 /* Dateien aus Sicherhheitsgruenden schliessen */
	 fclose(FPSchreiben);
	 fclose(FPLesen);
	 /* Zeitmessung beenden */
	 time(&stZeitmessung.tZeit_Ende);
	 /* Differenz in Microsekunden berechnen */
	 stZeitmessung.fZeit_Diff = difftime(stZeitmessung.tZeit_Ende,
	 stZeitmessung.tZeit_Start/CLOCKS_PER_SEC);
	 /* prueft ob Generat angelegt werden kann */
	 if(stEingaben.sDateiname != NULL)
	 {
		 iSetze_Cursor(14, 50);
		 /* Ausgabe in Millisekunden */
		 printf("Ben%stigte Zeit: %.2lf[ms]",oe,
		 stZeitmessung.fZeit_Diff/1000000000);
		 /* Textfarbe gruen */
		 iSetze_Textfarbe(10, 22);
		 iSetze_Cursor(19, 15);
		 printf("Generierung erfolgreich. Dr%scken Sie Enter.", ue);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 /* Warte auf Tastendruck */
		 stAuswahl.cTaste = iWarte_auf_Taste();
		 if(stSteuerung.cFlag[0] == '0')
		 {
			 /* bleibe im Menue fuer weitere Schritte */
			 iGeneriere_Code();
		 }
	 }
	 else
	 {
		 iSetze_Cursor(19, 15);
		 /* Textfarbe rot */
		 iSetze_Textfarbe(12, 19);
		 printf("Generierung fehlgeschlagen. Dr%scken Sie Enter.", ue);
		 /* Textfarbe grau */
		 iSetze_Textfarbe(7, 30);
		 stAuswahl.cTaste = iWarte_auf_Taste();
		 /* sonst Abbruch, neuer Versuch */
		 iHauptmenue();
	 }
	 stAuswahl.cTaste = iWarte_auf_Taste();
	 return EXIT_SUCCESS;
 }
