#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Blad: Nie podano nazwy pliku wejsciowego" << endl;
    cerr << "Uzycie: " << argv[0] << " <nazwa_pliku.txt>" << endl;
    return 1;
  }

  string filename = argv[1];
  ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Blad: Nie mozna otworzyc pliku: " << filename << endl;
    return 1;
  }

  int n;
  if (!(file >> n)) {
    cerr << "Blad: Brak danych w pliku" << endl;
    return 1;
  }

  if (n <= 1) {
    cout << "Liczba miast musi byc wieksza niz 1" << endl;
    return 0;
  }

  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!(file >> dist[i][j])) {
        cerr << "Blad: Niepoprawny format macierzy lub za malo danych w pliku"
             << endl;
        return 1;
      }
    }
  }

  file.close();

  vector<bool> visited(n, false);
  vector<int> path;
  int total_distance = 0;

  int current_city = 0;
  visited[current_city] = true;
  path.push_back(current_city);

  for (int step = 1; step < n; ++step) {
    int next_city = -1;
    int min_dist = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
      if (!visited[i] && dist[current_city][i] < min_dist &&
          current_city != i) {
        min_dist = dist[current_city][i];
        next_city = i;
      }
    }

    if (next_city != -1) {
      visited[next_city] = true;
      path.push_back(next_city);
      total_distance += min_dist;
      current_city = next_city;
    }
  }

  total_distance += dist[current_city][path[0]];
  path.push_back(path[0]);

  cout << "Wynik (Dane wczytane z: " << filename << ")" << endl;
  cout << "Trasa: ";
  for (size_t i = 0; i < path.size(); ++i) {
    cout << path[i];
    if (i != path.size() - 1) {
      cout << " -> ";
    }
  }
  cout << endl << "Calkowita odleglosc: " << total_distance << endl;

  return 0;
}
