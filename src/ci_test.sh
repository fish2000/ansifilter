#!/bin/bash

echo "Starting sample CI verification script"

OUTPUT=`./src/ansifilter ./src/ci_test_line.col`
RETVAL=$?

if [ $RETVAL -eq 0 ]; then
  echo "Retval is 0, OK"
else
  echo "Retval is not 0, FAIL"
  exit 1
fi

if [ "$OUTPUT" == "BEGIN Bold Underline Italic Blink Hide Black Red Green Yellow Blue Magenta Cyan White END" ]; then
  echo "Output is correct, OK"
else
  echo "Output is not right, FAIL"
  exit 1
fi
