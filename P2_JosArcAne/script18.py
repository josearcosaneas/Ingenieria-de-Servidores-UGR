#!/usr/local/bin/python	

import sys

import fileinput

for i, line in enumerate (fileinput.input('etc/ssh/sshd\_config',inplace=1)):
	sys.stdout.write(line.replace('PasswordAuthetication no', 'PasswordAuthentication yes'))
	sys.stdout.write(line.replace('PermitEmptyPasswords no', 'PermitEmptyPasswords yes'))
