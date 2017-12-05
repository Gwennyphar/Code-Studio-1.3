/**
 * Programm....: $
 * Entwickler..: $
 * Version.....: $
 * Datum.......: $
 * Status......: $
 * ToDo........: $
 *               $
 *               $
 */$

/**
 * Praeprozessor
 * Bibliotheken-Einbindung fuer Ein- und Ausgaben (cin, cout)
 */
 #include <iostream>                   // Input/Output Stream
$
 using namespace std;                  // Namensraum reservieren
$
/**
 * Klasse
 */
 class $
 {
     private:                          // privater Bereich
         char sAuswahl[5];
     public:                           // Lege eine Mehtode an und mache 
                                       // sie public, damit sie spaeter von
                                       // aussen aufgerufen werden kann
        /**
         * Funktion..: $
         * Status....: $
         */$
         int i$()
         {
             do
             {
                 cout << "\n\t$\n" << endl;$
                 cout << "\t< 0 > Beenden" << endl;
                 cout << "\n\t----> Auswahl: ";
                 cin >> sAuswahl; // Eingabe
                 switch(sAuswahl[0])
                 {$
                     case '0':
                     {
                         break;
                     }
                     default:
                     {
                         break;
                     }
                 }
             }while(sAuswahl[0] != '0'); // beenden
             return 0;
         }
 };

/**
 * Funktion..: Steuerprogramm
 */
 int iController()
 {
     // Erzeuge eine Instanz aus der Klasse $
     $ obj$;
     // Rufe die Methode der erzeugten Instanz auf
     obj$.i$();
     return 0;
 }

/**
 * Funktion..: Hauptprogramm
 */
 int main()
 {
     iController(); // Rufe Controller auf
     return 0;
 }

/** 
 * Programmende
 */$
