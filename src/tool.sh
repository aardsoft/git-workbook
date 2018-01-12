#!/bin/bash

VAR1="Aardsoft"
VAR2="Aardsoft"

if [[ ${VAR2} == ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
