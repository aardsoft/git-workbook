#!/bin/bash

VAR1="Metus" 
VAR2="Metus"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
