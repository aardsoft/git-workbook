#!/bin/bash

VAR1="Ami" 
VAR2="Ami"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
