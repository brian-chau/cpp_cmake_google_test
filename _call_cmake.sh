#!/bin/bash

echo Cleaning directory
rm -rf build

test=-Drun_my_tests=$1
if [ $# -eq 2 ]
then
    flags=$2
else
    flags=
fi

mkdir -p build && cd build
cmake $test $flags .. 1>/dev/null 2>&1
make 1>/dev/null 2>&1

if [ $# -ge 1 ]
then
    if [ "$1" == "ON" ]
    then
        echo Preparing to test...
        rm -rf ../coverage-report 1>/dev/null
        ctest -V 1>/dev/null

        echo Generating coverage report
        lcov --capture --directory . --output-file coverage.info --gcov-tool gcov-14 --ignore-errors inconsistent,inconsistent 1>/dev/null
        lcov --remove coverage.info '14/*' '/usr/*' 'tests/' --output-file coverage.filtered.info 1>/dev/null
        genhtml coverage.filtered.info --output-directory ../coverage-report 1>/dev/null
    elif [ "$1" == "OFF" ]
    then
        echo Building application in "bin/exe"
        cp ./bin/exe ../bin/exe 1>/dev/null
    fi
fi
cd ..

rm -rf build
