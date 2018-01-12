#!/bin/bash

VAR1="Veli" 
VAR2="Veli"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
