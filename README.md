# Tetris w C++

Klasyczna gra Tetris napisana w C++ z wykorzystaniem biblioteki SFML 3.

---

## Funkcje

- Plansza o wymiarach 10 × 20
- 7 rodzajów klocków: I, J, L, O, S, T, Z
- Przesuwanie i obracanie klocków
- Automatyczne czyszczenie pełnych wierszy
- Podgląd następnego klocka i licznik punktów z prawej strony
- Ekran końca gry z możliwością restartu

---

## Sterowanie

| Klawisz | Akcja |
| :--- | :--- |
| Strzałka w lewo / prawo | Ruch w lewo / w prawo |
| Strzałka w dół | Przyspieszenie opadania |
| Strzałka w górę | Obrót klocka |
| R | Nowa gra (po przegranej) |
| Esc | Zamknięcie gry |

---

## Punktacja

Punkty są przyznawane na podstawie liczby jednocześnie usuniętych wierszy:

    punkty = 100 * (liczba wierszy)^2

Przykłady:
- 1 wiersz: 100 pkt
- 4 wiersze jednocześnie: 1600 pkt

---

## Wymagania i konfiguracja

- System Windows
- Visual Studio 2022 lub nowsze
- SFML 3.1.0

Projekt zakłada, że biblioteka SFML znajduje się w katalogu C:\SFML-3.1.0. W przypadku innej lokalizacji należy zmienić ścieżki do folderów include oraz lib w ustawieniach projektu.

---

## Uruchomienie

1. Otwórz plik Tetris.slnx w Visual Studio.
2. Ustaw konfigurację Debug oraz platformę x64.
3. Kompiluj i uruchom projekt (klawisz F5).

---

## Struktura projektu

```text
├── Board.*       # Logika planszy, wykrywanie kolizji i czyszczenie wierszy
├── Tetromino.*   # Definicje klocków i ich obracanie
├── Game.*        # Pętla gry, obsługa wejścia, rysowanie interfejsu
├── PieceType.h   # Enumeracja typów klocków
└── Tetris.cpp    # Funkcja main i punkt startowy
