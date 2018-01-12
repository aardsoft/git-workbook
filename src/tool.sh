#!/bin/bash

VAR1="Julius" 
VAR2="Julius"

if [[ ${VAR2} != ${VAR1} ]]; then
	echo "PASS"
else
	echo "FAIL"
fi
