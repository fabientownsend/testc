#!/usr/bin/env bash

gcc lib/unity_fixture.c myheader.c temperature.c  lib/unity.c -o main && ./main
