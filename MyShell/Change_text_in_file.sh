#!/bin/bash

User='user1'
OldPwd='abc'
NewPwd='def'
FilePath='./a.txt'

echo ${User}
echo ${OldPwd}
echo ${NewPwd}
echo "sed -i '' 's:'${User}'\:'${OldPwd}':'${NewPwd}':g' ${FilePath}"

sed -i '' 's:'${User}'\:'${OldPwd}':'${User}'\:'${NewPwd}':g' ${FilePath}
