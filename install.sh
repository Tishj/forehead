#!/bin/bash

SHELL=$(ps -p $$ | awk '{print $4}' | grep -v "CMD")
SHELLRC_PATH=$HOME"/."$SHELL"rc"

if ! cat $SHELLRC_PATH | grep "alias forehead=" > /dev/null;
then
	echo "alias forehead=\"~/forehead/forehead\"" >> $SHELLRC_PATH
	echo "Alias 'forehead' succesfully added to your shellrc, will now source it.."
	source $SHELLRC_PATH
else
	echo "Already installed."
fi
