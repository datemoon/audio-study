#!/bin/bash -x

# download opus-tools
# https://github.com/xiph/opus-tools.git
if [ ! -d opus-tools-git ]
then
	git clone https://github.com/xiph/opus-tools.git opus-tools-git
fi
cd opus-tools-git
git checkout -b v0.1.9 v0.1.9
cd -
cp -r configure.ac Makefile.am Makefile.unix opusapi opus-tools-git
cd -

# install
if [ ! -f ./configure ]
then
	./autogen.sh
	echo $?
fi

./configure --prefix=/home/hubo/tools-install --with-ogg=/home/hubo/tools-install --with-opus=/home/hubo/tools-install
make
#make install


