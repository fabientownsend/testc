#!/usr/bin/env bash

gcc lib/unity.c lib/unity_fixture.c tests/example.test.c -o main && ./main
