#! /bin/bash

cat /etc/passwd |  grep -v '#' | sed '1~2d' | cut -d : -f 1 | rev | sort -d -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | sed ':a;N;$!ba;s/\n/, /g' | sed 's/$/./' | tr -d ''\n'
