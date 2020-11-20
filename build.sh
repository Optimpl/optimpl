#!/bin/bash

clear

echo -e "\e[92mStarting the compilation... \e[0m\n"

if [[ -d './bin' ]]
then
    echo -e '\e[101m\e[30mFiles from previous compilation found! Removing...\e[0m\n'
    rm -r bin
    echo -e '\e[102m\e[30mSuccessfully removed the files\e[0m\n'
fi

if [[ ! -d './bin' ]]
then
    mkdir ./bin
fi

echo -e '\e[43m\e[30mCompiling...\e[0m\n'

echo -e '\e[32m\e[40mCompiling ./include/PYICPP/string.h to ./bin/string.o \e[0m\n'
g++ -c ./include/PYICPP/string.h -o ./bin/string.o

echo -e '\e[42m\e[30mDone compiling...\e[0m\n'
echo -e '\e[42m\e[30mCompiled objects are located in the bin folder\e[0m\n'