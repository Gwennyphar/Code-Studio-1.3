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
 * Bibliotheken-Einbindung fuer Ein- und Ausgaben (scanf, printf)
 */
 #include <stdio.h>                    /* Standard-Input/Output */
$
/**
 * Funktion..: $
 * Status....: $
 */$
 int i$()
 {
     char sAuswahl[5];                 /* Variable deklarieren */
     do
     {
         printf("\n\t$\n");$
         printf("\n\t< 0 > Beenden\n");
         printf("\n\t----> Auswahl: ");
         scanf("%s", &sAuswahl[0]);    /* Eingabe */
         fflush(stdin);                /* Tastaturpuffer leeren */
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
     }while(sAuswahl[0] != '0');       /* beenden */
     return 0;
 }

/**
 * Funktion..: Steuerprogramm
 */
 int iController()
 {
     i$(); /* Rufe Funktion im Controller auf */
     return 0;
 }

/**
 * Funktion..: Hauptprogramm
 */
 int main()
 {
     iController(); /* Rufe Controller auf */
     return 0;
 }

/**
 * Programmende
 */$
