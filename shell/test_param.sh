#!/bin/bash

func()
{
    echo "cal: $cal"
    echo "ttt: $ttt"
}

main()
{
    func
}
fund()
{
    if [[ ${cal} != "str" ]];
    then
        echo error
    fi
}

echo ""

cal=1
ttt=2
main

cal=`expr $cal + 1`
ttt=`expr $cal + 1`
main
