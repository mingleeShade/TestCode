#!/bin/bash

TRUE="true"
FALSE="false"

echo

if [[ ${TRUE} == "true" ]] && [[ ${FALSE} == "false" ]]; then
    echo "1. pass.[right]" # pass
else
    echo "1. no pass."
fi

if [[ ${TRUE} == "true" ]] && [[ ${TRUE} == "false" ]]; then
    echo "1. pass."
else
    echo "1. no pass.[right]" # shall not pass
fi

if [[ ${TRUE} == "true" && ${FALSE} == "false" ]]; then
    echo "2. pass.[right]" # pass
else
    echo "2. no pass."
fi

if [[ ${FALSE} == "true" && ${FALSE} == "false" ]]; then
    echo "2. pass."
else
    echo "2. no pass.[right]"
fi

if [[ (${TRUE} == "true") && (${FALSE} == "false") ]]; then
    echo "3. pass.[right]" # pass
else
    echo "3. no pass."
fi

if [[ (${TRUE} == "true") && (${FALSE} == "faildd") ]]; then
    echo "3. pass."
else
    echo "3. no pass.[right]"
fi

if [[ ( ${TRUE} == "true" ) && ( ${FALSE} == "false" ) ]]; then
    echo "4. pass.[right]" # pass
else
    echo "4. no pass."
fi

if [[ ( ${TRUE} == "tree" ) && ( ${FALSE} == "false" ) ]]; then
    echo "4. pass."
else
    echo "4. no pass.[right]"
fi
