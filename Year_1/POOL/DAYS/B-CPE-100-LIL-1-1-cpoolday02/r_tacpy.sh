#!/bin/bash
awk "NR%2==0" | cut -d\: -f 1 | rev | sort -r | awk "FNR>=$MY_LINE1 && FNR<=$MY_LINE2" | awk '$1=$1' ORS=', ' | sed 's/, $//' | awk '{print $0 "." }'