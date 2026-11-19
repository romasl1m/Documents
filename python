# PYTHON — ŚCIĄGA NA SZKOLNY ETAP OI
# Uruchamianie: python3 oi.py
# Większość przykładów jest zakomentowana. Odkomentuj potrzebne fragmenty.
# W Pythonie listy są dynamicznymi tablicami, a krotki (tuple) są niemodyfikowalne.

import sys
from collections import deque, defaultdict, Counter
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from math import gcd, lcm, isqrt

input = sys.stdin.readline


# ============================================================
# 1. WCZYTYWANIE DANYCH
# ============================================================

# Jedna liczba:
# n = int(input())

# Kilka liczb w jednym wierszu:
# a, b, c = map(int, input().split())

# Lista n liczb (w jednym wierszu):
# tab = list(map(int, input().split()))

# Lista n liczb (każda w osobnym wierszu):
# tab = [int(input()) for _ in range(n)]

# Macierz n x m:
# mac = [list(map(int, input().split())) for _ in range(n)]

# Wczytanie całego wejścia jako liczby — czasem wygodne przy dużym wejściu:
# dane = list(map(int, sys.stdin.buffer.read().split()))
# n = dane[0]
# tab = dane[1:n + 1]

# Łańcuch znaków:
# s = input().strip()

# Kilka testów:
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     ...


# ============================================================
# 2. WYJŚCIE
# ============================================================

# print(x)
# print(a, b, c)
# print(*tab)                  # elementy listy oddzielone spacjami
# print(*tab, sep=";")
# print("TAK" if warunek else "NIE")

# Przy dużej liczbie wyników:
# wyniki = []
# wyniki.append(str(x))
# sys.stdout.write("\n".join(wyniki))


# ============================================================
# 3. LISTY — TABLICE
# ============================================================

# tab = [0] * n                # n zer
# tab = [i for i in range(n)]  # [0, 1, ..., n-1]
# tab = [[0] * m for _ in range(n)]  # macierz; NIE używaj [[0]*m]*n

# tab[i]                       # i-ty element
# tab[-1]                      # ostatni element
# tab[l:r]                     # fragment od l do r-1
# len(tab)
# tab.append(x)                 # dodanie na koniec
# tab.pop()                     # usunięcie i zwrócenie ostatniego
# tab.pop(i)                    # usunięcie elementu o indeksie i
# tab.insert(i, x)              # wstawienie na pozycję i
# tab.extend(inna_lista)
# tab.clear()
# x in tab                      # sprawdzenie przynależności — O(n)
# tab.index(x)                  # pierwsza pozycja x — O(n)
# tab.count(x)                  # liczba wystąpień — O(n)
# tab[::-1]                     # kopia odwrócona
# tab.reverse()                 # odwrócenie w miejscu
# kopia = tab.copy()

# Iteracja:
# for x in tab:
#     ...
# for i in range(len(tab)):
#     ...
# for i, x in enumerate(tab):
#     ...
# for a, b in zip(tab1, tab2):
#     ...

# Sortowanie listy:
# tab.sort()                    # rosnąco, modyfikuje listę
# tab.sort(reverse=True)        # malejąco
# nowa = sorted(tab)            # tworzy nową listę
# nowa = sorted(tab, reverse=True)

# Sortowanie po kluczu:
# pary = [(2, 7), (1, 9), (2, 3)]
# pary.sort()                   # najpierw pierwszy, potem drugi element
# pary.sort(key=lambda p: p[1])
# pary.sort(key=lambda p: (p[0], -p[1]))
# obiekty.sort(key=lambda x: x[0])


# ============================================================
# 4. PARY, KROTKI I ROZPAKOWYWANIE
# ============================================================

# para = (a, b)                 # krotka (tuple)
# x, y = para
# lista_par = [(1, 5), (2, 8)]
# lista_par.append((3, 4))

# Pętla po parach:
# for x, y in lista_par:
#     ...

# Sortowanie par:
# lista_par.sort()              # leksykograficznie
# lista_par.sort(key=lambda p: p[0])
# lista_par.sort(key=lambda p: p[1])

# Funkcja może zwrócić kilka wartości:
# def f(x):
#     return x, x * x
# a, b = f(5)


# ============================================================
# 5. FUNKCJE
# ============================================================

# def suma(a, b):
#     return a + b
#
# def maksimum(tab):
#     wynik = tab[0]
#     for x in tab:
#         if x > wynik:
#             wynik = x
#     return wynik
#
# Argument domyślny:
# def f(x, mod=10**9 + 7):
#     return x % mod
#
# Uwaga: nie używaj mutowalnej listy jako domyślnego argumentu.
# Zmienna globalna:
# n = 10
# def f():
#     global n
#     n += 1


# ============================================================
# 6. SŁOWNIKI I ZBIORY
# ============================================================

# Słownik — średnio O(1) na operację:
# cnt = {}
# cnt[x] = cnt.get(x, 0) + 1
# if x in cnt:
#     ...
# for klucz, wartosc in cnt.items():
#     ...

# defaultdict:
# cnt = defaultdict(int)
# cnt[x] += 1
#
# Lista sąsiedztwa:
# graf = [[] for _ in range(n)]
# graf[u].append(v)
# graf[v].append(u)  # dla grafu nieskierowanego

# Zbiór — unikalne elementy, średnio O(1):
# zbior = set()
# zbior.add(x)
# zbior.discard(x)              # nie zgłasza błędu, gdy x nie ma
# if x in zbior:
#     ...
# unikalne = set(tab)


# ============================================================
# 7. KOLEJKI, STOSY I KOPIEC
# ============================================================

# Stos (LIFO) — zwykła lista:
# stos = []
# stos.append(x)
# x = stos.pop()

# Kolejka (FIFO):
# q = deque()
# q.append(x)
# x = q.popleft()

# BFS:
# q = deque([start])
# odl = [-1] * n
# odl[start] = 0
# while q:
#     v = q.popleft()
#     for u in graf[v]:
#         if odl[u] == -1:
#             odl[u] = odl[v] + 1
#             q.append(u)

# Kopiec minimum:
# kopiec = []
# heappush(kopiec, x)
# najmniejszy = heappop(kopiec)
# heapify(tab)                  # zamienia listę w kopiec
#
# Kopiec maksimum — odwróć znak:
# heappush(kopiec, -x)
# najwiekszy = -heappop(kopiec)
#
# Dijkstra:
# def dijkstra(start, graf):
#     INF = 10**30
#     odl = [INF] * len(graf)
#     odl[start] = 0
#     pq = [(0, start)]
#     while pq:
#         d, v = heappop(pq)
#         if d != odl[v]:
#             continue
#         for u, w in graf[v]:
#             nd = d + w
#             if nd < odl[u]:
#                 odl[u] = nd
#                 heappush(pq, (nd, u))
#     return odl


# ============================================================
# 8. WYSZUKIWANIE BINARNE — bisect
# ============================================================

# tab musi być posortowana rosnąco.
# bisect_left(tab, x)  — pierwsza pozycja >= x
# bisect_right(tab, x) — pierwsza pozycja > x
#
# liczba elementów równych x:
# ile = bisect_right(tab, x) - bisect_left(tab, x)
#
# czy x występuje:
# i = bisect_left(tab, x)
# jest = i < len(tab) and tab[i] == x
#
# pozycja do wstawienia:
# i = bisect_left(tab, x)
# tab.insert(i, x)  # samo wyszukanie O(log n), wstawienie O(n)


# ============================================================
# 9. PRZYDATNE FUNKCJE I MATEMATYKA
# ============================================================

# min(tab), max(tab), sum(tab), len(tab)
# abs(x)
# pow(a, b)                     # a^b
# pow(a, b, mod)                # a^b mod mod — szybkie potęgowanie
# gcd(a, b)
# lcm(a, b)
# isqrt(x)                      # floor(sqrt(x)) dokładnie dla int
# divmod(a, b)                  # (a // b, a % b)
# a // b                        # dzielenie całkowite w dół
# a % b                         # reszta z dzielenia
#
# Sortowanie bez duplikatów:
# posortowane = sorted(set(tab))
#
# Liczności:
# licznik = Counter(tab)
# najczestsze = licznik.most_common(3)


# ============================================================
# 10. PREFIKSY I SUMY PRZEDZIAŁÓW
# ============================================================

# pref[i] = suma tab[0:i]
# pref = [0] * (n + 1)
# for i in range(n):
#     pref[i + 1] = pref[i] + tab[i]
#
# Suma na przedziale domkniętym [l, r]:
# suma = pref[r + 1] - pref[l]
#
# 2D prefix sums (macierz n x m):
# pref = [[0] * (m + 1) for _ in range(n + 1)]
# for i in range(n):
#     for j in range(m):
#         pref[i+1][j+1] = (mac[i][j] + pref[i][j+1]
#                            + pref[i+1][j] - pref[i][j])
#
# Suma prostokąta [x1..x2] x [y1..y2]:
# s = (pref[x2+1][y2+1] - pref[x1][y2+1]
#      - pref[x2+1][y1] + pref[x1][y1])


# ============================================================
# 11. SORTOWANIE WŁASNYM KLUCZEM — PRZYKŁADY
# ============================================================

# Po długości:
# slowa.sort(key=len)
#
# Po wartości bezwzględnej:
# tab.sort(key=abs)
#
# Najpierw rosnąco po a, potem malejąco po b:
# pary.sort(key=lambda p: (p[0], -p[1]))
#
# Sortowanie indeksów według wartości:
# idx = sorted(range(n), key=lambda i: tab[i])


# ============================================================
# 12. REKURENCJA I DFS
# ============================================================

# Python ma limit głębokości rekurencji. Zwiększaj go tylko wtedy,
# gdy rozumiesz ryzyko przepełnienia stosu / ograniczeń środowiska.
# sys.setrecursionlimit(1_000_000)
#
# DFS rekurencyjny:
# def dfs(v, p=-1):
#     odw[v] = True
#     for u in graf[v]:
#         if u != p and not odw[u]:
#             dfs(u, v)
#
# DFS iteracyjny (bez ryzyka limitu rekurencji):
# stos = [start]
# odw[start] = True
# while stos:
#     v = stos.pop()
#     for u in graf[v]:
#         if not odw[u]:
#             odw[u] = True
#             stos.append(u)


# ============================================================
# 13. ZŁOŻONOŚCI — SZYBKA ŚCIĄGA
# ============================================================

# len(tab), tab[i], append, pop() na końcu: O(1)
# tab.append(x): amortyzowane O(1)
# x in lista, index, count: O(n)
# x in set/dict, set.add, dict.get: średnio O(1)
# sort / sorted: O(n log n)
# bisect_left/right: O(log n)
# tab.insert(i, x), pop(i): O(n)
# sum(tab), min(tab), max(tab): O(n)
# heap push/pop: O(log n)
# BFS / DFS: O(V + E)
# Dijkstra z kopcem: O((V + E) log V)


# ============================================================
# 14. MINIMALNY SZABLON ZADANIA
# ============================================================

def main():
    # Przykład:
    # n = int(input())
    # tab = list(map(int, input().split()))
    # tab.sort()
    # print(*tab)
    pass


if __name__ == "__main__":
    main()
