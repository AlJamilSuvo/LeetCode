#!/bin/bash
git add .
git commit -m $1
git push github master
git push gitlab master