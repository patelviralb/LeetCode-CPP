#!/bin/bash

numberOfArguments=${#}

if [[ ${numberOfArguments} != 1 ]]
then
    echo "USAGE: compileAndRunCode.sh <.cpp file name>"
else
    file=${1}
    fileExtension=`echo ${file} | cut -d"." -f2`
    if [[ ${fileExtension} -ne "cpp" ]]
    then
        echo "USAGE: compileAndRunCode.sh <.cpp file name>"
    fi
fi

fileName=`echo ${file} | cut -d"." -f1`
if [[ ! -d "objectFiles" ]]
then
    `mkdir -p objectFiles`
fi

echo "Compiling ${file}...."
`g++ ${file} -o objectFiles/${fileName}.o`

if [[ ${?} == 0 ]]
then
    echo "Running ${fileName}...."
    ./objectFiles/${fileName}.o

    if [[ ${?} == 0 ]]
    then
        echo "Program execution completed. Press any key to continue...."
        read -sn1 input
    fi
fi