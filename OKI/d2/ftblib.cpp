#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "ftblib.h"

using namespace std;

namespace
{
int state = 0;
int n;
int bad;
int qcount = 0;
vector<vector<int>> deps;

void
read_input ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (nullptr);

  int m;
  cin >> n >> m >> bad;

  deps.resize (n + 1);

  for (int i = 0; i < m; ++i)
    {
      int a, b;
      cin >> a >> b;

      deps[a].push_back (b);
    }
}

void
read_input_if ()
{
  if (state == 0)
    {
      read_input ();
      state = 1;
    }
}
}

int
liczba_modyfikacji ()
{
  read_input_if ();
  return n;
}

vector<int>
zaleznosci (int m)
{
  read_input_if ();

  if (m < 1 || m > n)
    {
      clog << "Błędny numer modyfikacji: " << m << endl;
      abort ();
    }

  return deps[m];
}

int
uruchom (int ile, int const *modyfikacje)
{
  static unordered_set<int> used;

  read_input_if ();

  if (qcount == 100)
    {
      clog << "Za dużo zapytań" << endl;
      abort ();
    }

  ++qcount;

  if (ile < 0 || ile > n)
    {
      clog << "Błędna liczba modyfikacji w podzbiorze: " << ile << endl;
      abort ();
    }

  used.clear ();
  for (int i = 0; i < ile; ++i)
    {
      int m = modyfikacje[i];
      if (m < 0 || m > n)
        {
          clog << "Błędny numer modyfikacji w podzbiorze: " << m << endl;
          abort ();
        }

      auto created = used.insert (m).second;
      if (!created)
        {
          clog << "Powtórzony numer modyfikacji w podzbiorze: " << m << endl;
          abort ();
        }
    }

  for (int i = 0; i < ile; ++i)
    {
      int m = modyfikacje[i];
      for (int dep : deps[m])
        if (!used.contains (dep))
          return -1;
    }

  return used.contains (bad) ? 1 : 0;
}

void
odpowiedz (int m)
{
  read_input_if ();

  if (m < 1 || m > n)
    {
      clog << "Błędny numer modyfikacji: " << m << endl;
      abort ();
    }

  cout << "Odpowiedź: " << m << endl;
  exit (EXIT_SUCCESS);
}
