#!/bin/bash
grep -e "theo1" -e "steven1" -e "arnaud1" -e "pierre-jean" | sed -e 's/theo1/Wile E. Coyote/g ; s/steven1/Daffy Duck/g ; s/arnaud1/Porky Pig/g ; s/pierre-jean/Marvin the Martian/g'