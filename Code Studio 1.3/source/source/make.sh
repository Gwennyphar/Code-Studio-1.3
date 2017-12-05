#!/bin/bash
# Quelldatei als Bin Datei compilen
#gcc -m32 -o code_studio.c code_studio
#gcc -m64 -o code_studio.c code_studio
gcc -g code_studio.c -o code_studio
# Bin Datei in überliegendes Verzeichnis verschieben
mv code_studio ../code_studio
# Script anlegen
if test ! -s ../run.sh; # Datei existiert und ist nicht leer
      then
         # Inhalt in Datei kopieren
         echo "#!/bin/bash" >> ../run.sh
         echo "# startet die Liuxversion von Code Studio" >> ../run.sh
         echo "cd /usr/share/code-studio/" >> ../run.sh
         echo "./code_studio" >> ../run.sh
         echo "done" >> ../run.sh
         chmod u+x ../run.sh # Script ausführbar machen
      else
         exit 0
      fi
echo "Code Studio erfolgreich compiliert"
sleep 1
done
exit 0
