Problem komiwojażera (TSP) - heurystyka najbliższego sąsiada
=============================================================

Program wczytuje macierz odległości między miastami z pliku tekstowego,
a następnie wyznacza przybliżoną trasę komiwojażera metodą najbliższego
sąsiada (nearest neighbour). Wynikiem jest kolejność odwiedzanych miast
oraz łączna długość wyznaczonej trasy (z powrotem do miasta startowego).


Sposób kompilacji i uruchomienia:
---------------------------------
1. Kompilacja:
   g++ main.cpp -o main

2. Uruchomienie:
   ./main dane1.txt

   (w systemie Windows: main.exe dane1.txt)

3. Wymagania:
   - Kompilator C++ (g++, clang++)
   - System operacyjny: Windows / Linux / macOS


Struktura plików:
-----------------
- main.cpp   – główny i jedyny plik źródłowy programu
- dane1.txt  – przykładowy plik z danymi wejściowymi (4 miasta)
- dane2.txt  – dodatkowy plik z przykładowymi danymi
- dane3.txt  – dodatkowy plik z przykładowymi danymi
- README.txt – ten plik


Format pliku wejściowego:
-------------------------
- W pierwszym wierszu liczba całkowita n - liczba miast (n > 1).
- Następnie n wierszy po n liczb całkowitych - symetryczna macierz
  odległości między miastami. Element dist[i][j] oznacza odległość
  z miasta i do miasta j. Na przekątnej powinny znajdować się zera.


Przykładowe dane wejściowe/wyjściowe:
-------------------------------------
Wejście (dane1.txt):
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Wyjście:
Wynik (Dane wczytane z: dane1.txt)
Trasa: 0 -> 1 -> 3 -> 2 -> 0
Calkowita odleglosc: 80


Uwagi dodatkowe:
----------------
- Program zakłada poprawność danych wejściowych (kwadratowa macierz
  n x n liczb całkowitych). W razie błędu odczytu program kończy
  działanie z komunikatem na standardowym wyjściu błędów.
