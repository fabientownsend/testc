#!/usr/bin/env bash

clear && gcc main.c myheader.c unity.c unity_fixture.c -o main && ./main
