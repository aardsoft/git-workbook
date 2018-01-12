#!/bin/bash

VAR1="Aard"
VAR2="Aard"

if [[ ${VAR2} == ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
