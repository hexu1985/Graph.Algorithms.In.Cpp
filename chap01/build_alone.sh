#!/usr/bin/env bash

debug=0

this_sh_path=$(dirname $0)

test $debug -gt 0 && echo "this_sh_path: $this_sh_path"

cd $this_sh_path
this_sh_path=$PWD

rm -rf ./build
mkdir build
cd build
cmake -Dcompile_alone_flag=ON -G"Unix Makefiles" ..
#cmake -Dcompile_alone_flag=ON ..
make
#make install

cd $this_sh_path
cp *.sh build/
cp *.data build/
