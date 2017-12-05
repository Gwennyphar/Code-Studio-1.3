#/usr/bin/env python
# -*- coding: cp1252 -*-

"""
Programm....: $
Entwickler..: $
Version.....: $
Datum.......: $
Status......: $
ToDo........: $
              $
              $
"""
$
"""
Bibliotheken-Einbindung fuer Umleitungen (stdin, stdout und stderr)
"""
import sys                           # Systemaufrufe
$
"""
Funktion..: $
Status....: $
"""$
def $():
    print "\n\t$\n"$
    print "\t< 0 > Beenden\n";
    Auswahl = raw_input("\t----> Auswahl: ") # Eingabe
    while Auswahl != '0':$
        if Auswahl == '0':
           break
        else:
           $
    else:
        sys.exit() # beenden
$

"""
Funktion..: Steuerprogramm
"""
def Controller():
    $() # Rufe Funktion im Controller auf

"""
Das Hauptprogramm wird nur gestartet, wenn dieses Python-Modul
direkt aufgerufen wurde.
Wenn dieses Modul von einem anderen Modul importiert wurde,
dann passiert nichts. Dafuer sind die folgenden zwei Zeilen Code zustaendig.
"""
if __name__ == '__main__':
    Controller() # Rufe Controller auf

"""
Programmende
"""
$
