#!/bin/sh

CUR_PATH=$(cd `dirname $0`; pwd)

BUILD_PATH=${CUR_PATH}/../build

if [ $# != 1 ]; then
	echo "deploy.sh [install path]"
	exit
fi


for dir in `ls ${BUILD_PATH}`; do
	cd ${BUILD_PATH}/$dir && make INSTALL_ROOT=$1 install
done
