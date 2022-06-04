#!/bin/bash
cut -d\; -f 3 | grep -i "$*" | wc -l 
