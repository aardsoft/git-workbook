#!/bin/bash

VAR1="Dice" 
VAR2="Dice"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
