#!/bin/bash

git init
git add $1
git commit -m "$2"
git push https://gramoscelli:Secret20130@github.com/gramoscelli/EDU-CIAA-NXP.git --all
git push -u origin master
