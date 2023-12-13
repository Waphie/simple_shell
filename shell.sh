#!/bin/bash

while true; do
 read -p "shell> " cmd
 args=($cmd)

 if [ ${args[0]} == "exit" ]; then
    status=${args[1]}
    echo "Exiting with status $status."
    break
 fi

 for ((i=0; i<${#args[@]}; i++)); do
    if [ -z "${args[$i]}" ]; then
      unset 'args[$i]'
    fi
 done

 ${args[0]} "${args[@]:1}"
done
