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
 * Packages
 * Bibliotheken-Einbindung fuer Ein- und Ausgaben (print, nextLine)
 */
 import java.util.Scanner;             // Verschiedene nuetzliche Klassen
$
/**
 * Klasse
 */
 public class $
 {$
     /**
      * Funktion..: $
      * Status....: $
      */$
      public void $()
      {
          Scanner scan = new Scanner(System.in); //Eingabe
          String sEingabe;
          char cAuswahl = 0;
          do
          {
              System.out.println("\n\t$\n");$
              System.out.println("\t< 0 > Beenden\n");
              System.out.print("\t----> Auswahl: ");
              sEingabe = scan.nextLine();
              if(sEingabe.length() == 1)
              {
                  cAuswahl = sEingabe.charAt(0); // Zeichen einlesen
              }
              switch(cAuswahl) 
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
          }while(cAuswahl != '0');     // beenden
      }

     /**
      * Funktion..: Steuerprogramm
      */
      public static void Controller()
      {
          // Erzeuge eine Instanz aus der Klasse $
          $ obj$ = new $();
          // Rufe die Methode der erzeugten Instanz auf
          obj$.$();
      }

     /**
      * Funktion..: Hauptprogramm
      */
      public static void main(String[] args)
      {
          Controller(); // Rufe Controller auf
      }
 }

/**
 * Programmende
 */$
