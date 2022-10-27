#!/bin/bash

TRUE="true"
FALSE="false"

echo

if [[ ${TRUE} == "true" ]] && [[ ${FALSE} == "false" ]]; then
    echo "1. pass." # pass
else
    echo "1. no pass."
fi

if [[ ${TRUE} == "true" && ${FALSE} == "false" ]]; then
    echo "2. pass." # pass
else
    echo "2. no pass."
fi

if [[ (${TRUE} == "true") && (${FALSE} == "false") ]]; then
    echo "3. pass." # pass
else
    echo "3. no pass."
fi

if [[ ( ${TRUE} == "true" ) && ( ${FALSE} == "false" ) ]]; then
    echo "4. pass." # pass
else
    echo "4. no pass."
fi
