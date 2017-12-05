/*************************** Programmfunktionen *******************************/

/**
 * Mehrfaches Inkludieren vermeiden
 */
 #ifndef FUNCTION_H_
 #define FUNCTION_H_
 
/**
 * Praeprozessor Direktive zum uebersetzen von Windows
 * und unixbasierten Systemen fuer SetCursor Funktion
 */
 /* Direktive unter Linux/UNIX uebersetzen */ 
 #ifdef __linux__
 #include <termios.h>
 /* Direktive unter MS Windows uebersetzen */
 #elif __WIN32__ || _MSC_VER__
 #include <windows.h>
 #endif

/**
 * Funktion : Eigene Funktion fuer getch ohne Zeilenvorschub
 * Status   : vorgelegt (Quelle: http://linux.die.net/man/3/tcsetattr)
 */
 #ifdef __linux__  
 int iWarte_auf_Taste() 
 {
	 /* -1 bei Fehler und 0 wenn geschlossen */
	 static int ch = -1, fd = 0;
	 struct termios neu, alt;
	 fd = fileno(stdin);
	 /* Zustand holen*/
	 tcgetattr(fd, &alt);
	 neu = alt;
	 /* Flags zur Ausgabe uebertragen */
	 neu.c_lflag &= ~(ICANON|ECHO);
	 tcsetattr(fd, TCSANOW, &neu);
	 ch = getchar();
	 /* Signale nicht auswerten */
	 tcsetattr(fd, TCSANOW, &alt);
	 return ch;
 }
 #elif __WIN32__ || _MSC_VER__
 #define iWarte_auf_Taste() getch()
 #endif

/**
 * Funktion : vorherige Bildschirmausgabe unter Linux und Windows loeschen
 * Status   : vorgelegt 
 */
 int iLoesche_Ausgabe()
 {
	 #ifdef __linux__
	 printf("\033[1J\033[1;1H");
	 #elif __WIN32__ || _MSC_VER__
	 COORD coord;
	 DWORD written;
	 CONSOLE_SCREEN_BUFFER_INFO info;
	 coord.X = coord.Y = 0;
	 HANDLE std = GetStdHandle(STD_OUTPUT_HANDLE);
	 GetConsoleScreenBufferInfo(std, &info);
	 FillConsoleOutputCharacter(std,' ',info.dwSize.X*info.dwSize.Y,coord,&written);
	 coord.X = coord.Y = 0;
	 SetConsoleCursorPosition(std, coord);
	 #endif
	 return EXIT_SUCCESS;
 }
 
/**
 * Funktion : Setzt den Cursor auf Position x, y
 * Status   : vorgelegt
 */
 int iSetze_Cursor(unsigned int y, unsigned int x)
 {
	 #ifdef __linux__
	 printf("\033[%i;%iH", (y + 1), (x + 1));
	 #else
	 COORD Position;
	 Position.X = x;
	 Position.Y = y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	 #endif
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Aendert die Schriftfarbe von Texten
 * Status   : vorgelegt
 */
 int iSetze_Textfarbe(int iSchriftfarbe, int iPlus)
 {
	 #ifdef __linux__
	 printf("\033[%i;3m", iSchriftfarbe + iPlus);
	 #elif __WIN32__ || _MSC_VER__
	 HANDLE hConsole;
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 /* Beliebige Zahl von 1-255 z.B. 15 = Weiss */
	 SetConsoleTextAttribute(hConsole, iSchriftfarbe);
	 #endif
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Pausiert das Programm in Sekunden
 * Status   : vorgelegt
 */
 int iSetze_Pause(int iZeit)
 {
	 time_t tStart = 0;
	 time_t tStop = 0;
	 double dDiff;
	 tStart=time(NULL);
	 while((dDiff=difftime(tStop,tStart)) != iZeit)
	 {
		 tStop=time(NULL);
	 }
	 return EXIT_SUCCESS;
 }

/**
 * Funktion : Erstellt ein Verzeichnis
 * Status   : vorgelegt
 */
 int iErstelle_Ordner(const char* sPfad)
 {
	 #ifdef __linux__
	 mkdir(sPfad, 0775);
	 #elif __WIN32__ || _MSC_VER__
	 _mkdir(sPfad);
	 #endif
	 return EXIT_SUCCESS;
 }
 #endif
