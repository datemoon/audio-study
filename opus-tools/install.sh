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
cp -r configure.ac Makefile.am Makefile.unix opusapi opus-tools-git || exit 1;
cd -

export PKG_CONFIG_PATH=/home/hubo/tools-install/lib/pkgconfig/
# install
if [ ! -f ./configure ]
then
	./autogen.sh 
	if [ $? != 0 ]
	then
		echo "./autogen.sh failed!!! you need run again ./autogen.sh until success!!!"
		./autogen.sh || exit 1;
	fi
fi

./configure --prefix=/home/hubo/tools-install --with-ogg=/home/hubo/tools-install --with-opus=/home/hubo/tools-install || exit 1;
make
#make install

# the last lib in opus-tools-git/.lib

