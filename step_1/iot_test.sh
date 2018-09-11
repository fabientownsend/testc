#!/usr/bin/env bash

gcc lib/unity_fixture.c src/myheader.c tests/temperature.test.c lib/unity.c -o main && ./main
