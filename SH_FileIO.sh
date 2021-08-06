#!/bin/bash

printf "\n"

echo "user name : " $USER
echo "home directory : " $HOME
echo "user  name (whoami) : " `whoami`
echo "host name : "  `hostname -i`
echo "ip address : " 

ifconfig

printf "\n"

while :
do
	echo "-------------------------------------"

	printf "\n"

	echo "interface name : " $1
	
#	read stringname

#	echo "Input Value : " $stringname

	stringIP="ifconfig $1 | grep '\<inet\>'"

	printf "\n" 

	eval $stringIP

	if [ $? -eq 0 ];
	then
		echo "success"
		ifconfig $1 | grep '\<\inet\>'  > /home/jiyoon/Desktop/Git/study1/Shell+C/ipPrint.txt
		break
	else

        	echo "fail!"
		echo "fail" > /usr/local/etc/test/input.txt
		break
	fi

done

exit 0
