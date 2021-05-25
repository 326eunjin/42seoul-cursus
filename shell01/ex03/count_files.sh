#!/bin/sh
find . | wc -l | sed 's/ //g';
exit 0
