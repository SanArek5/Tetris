Tetris w C++
Klasyczna gra Tetris napisana w C++ przy użyciu biblioteki SFML 3.

Co oferuje gra?
Plansza 10 × 20

7 rodzajów klocków (I, J, L, O, S, T, Z)

Przesuwanie i obracanie tetromino

Kasowanie pełnych linii i naliczanie punktów

Podgląd następnego klocka

Ekran końca gry z opcją restartu (R)

Sterowanie
Strzałki (← / →) – ruch w lewo / prawo

Strzałka w dół (↓) – przyspieszenie opadania

Strzałka w górę (↑) – obrót klocka

R – nowa gra (po przegranej)

Esc – wyjście z gry

Punktacja
Punkty liczone są ze wzoru: 100 × (usunięte wiersze)²

1 wiersz = 100 pkt

4 wiersze na raz = 1600 pkt

Wymagania
Windows

Visual Studio 2022 (lub nowsze)

SFML 3.1.0 (domyślnie w folderze C:\SFML-3.1.0)

Jak uruchomić?
Otwórz Tetris.slnx w Visual Studio.

Wybierz konfigurację Debug i x64.

Zbuduj i uruchom projekt (F5).

Pliki w projekcie
Board.* – obsługa planszy, kolizji i czyszczenia linii

Tetromino.* – definicje i obracanie klocków

Game.* – główna pętla gry, sterowanie i interfejs

PieceType.h – typy klocków

Tetris.cpp – start programu

Projekt stworzony w ramach nauki C++ i SFML.
