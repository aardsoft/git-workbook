#!/bin/bash

VAR1="Vice" 
VAR2="Vice"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
