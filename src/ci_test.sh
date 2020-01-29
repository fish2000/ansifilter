#!/bin/bash

# file needs to be saved as UTF-8!

echo "Starting sample CI verification script"


# test case #1

OUTPUT=`./src/ansifilter ./src/ci_test_line.col`
RETVAL=$?

if [ $RETVAL -eq 0 ]; then
  echo "Retval test #1 is 0, OK"
else
  echo "Retval test #1  is not 0, FAIL"
  exit 1
fi

if [ "$OUTPUT" == "BEGIN Bold Underline Italic Blink Hide Black Red Green Yellow Blue Magenta Cyan White END" ]; then
  echo "Output test #1 is correct, OK"
else
  echo "Output  test #1 is not right, FAIL"
  exit 1
fi


# test case #2

OUTPUT=`echo "123Л123" | ./src/ansifilter --ignore-csi`

RETVAL=$?

if [ $RETVAL -eq 0 ]; then
  echo "Retval test #2 is 0, OK"
else
  echo "Retval test #2 is not 0, FAIL"
  exit 1
fi

if [ "$OUTPUT" == "123Л123" ]; then
  echo "Output test #2 is correct, OK"
else
  echo "Output  test #2 is not right, FAIL"
  exit 1
fi
