#!/bin/bash

VAR1="Aard"
VAR2="Aard"

if [[ ${VAR1} == ${VAR2} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
