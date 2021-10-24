#!/bin/bash
# clean all out file in binary directory
find . -name "*.out"  | xargs rm -f
echo "clean all the out files"