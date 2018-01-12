#!/bin/bash

VAR1="Aardsoft"
VAR2="Aardsoft"

if [[ ${VAR1} == ${VAR2} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
