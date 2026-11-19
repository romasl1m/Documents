#!/bin/bash

echo "=====  PROGRESS TRACKER ====="

total=$(find . -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) | wc -l)
cf=$(find codeforces -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) 2>/dev/null | wc -l)
sz=$(find szkopul -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) 2>/dev/null | wc -l)
oi=$(find OI -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) 2>/dev/null | wc -l)
oki=$(find OKI -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) 2>/dev/null | wc -l)
harbour=$(find harbour -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) 2>/dev/null | wc -l)

echo "Total solutions: $total"
echo ""
echo "Codeforces:   $cf"
echo "Szkopul:      $sz"
echo "OI:           $oi"
echo "OKI:          $oki"
echo "Harbour Space: $harbour"

echo ""
echo "=====  Last modified (top 5) ====="
find . -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) -printf "%TY-%Tm-%Td %TT %p\n" | sort -r | head -5

echo ""
echo "==== The longest files (top 10) ===="
find . -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) -exec wc -l {} + 2>/dev/null | grep -v ' total$' | sort -rn | head -n 10

echo ""
echo "==== The shortest files (top 10) ===="
find . -type f \( -name "*.cpp" -o -name "*.sh" -o -name "*.py" \) -exec wc -l {} + 2>/dev/null | grep -v ' total$' | sort -n | head -n 10

echo ""
echo "===== Most common songs (top 10) ====="

find . -name "*.cpp" -exec awk '
    /^Now playing:/ {
        getline
        if (length($0) > 0)
            print
    }
' {} + | sort | uniq -c | sort -rn | head -10

echo ""
