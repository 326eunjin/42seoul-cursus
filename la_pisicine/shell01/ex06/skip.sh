#!/bin/bash
ls -l | awk "NR % 2 != 0"
exit 0
