#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'centerDisplay' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. INTEGER width
#  2. STRING_ARRAY content
#

def centerDisplay(width, content):
    res = []
    filler = "."
    for line in content:
        if (width - len(line)) % 2 == 0:
            res.append(f"{line :{filler}^{width}}")
        else:
            res.append(f".{line :{filler}^{width-1}}")
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    width = int(input().strip())

    content_count = int(input().strip())

    content = []

    for _ in range(content_count):
        content_item = input()
        content.append(content_item)

    result = centerDisplay(width, content)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
