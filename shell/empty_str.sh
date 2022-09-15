#!/usr/bin/env bash

rebuild=$4

not_empty="not_empty"

if [[ -z ${rebuild} ]]; then
    echo "rebuild empty"   
fi

if [[ -n ${not_empty} ]]; then
    echo "not_empty"   
fi
