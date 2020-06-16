#!/bin/sh
#!/bin/bash
if [ "$#" -ne 3 ]
then
    echo "You must input 3 numbers to do this operator!"
else
    val=`expr $1 \* $2 \* $3`
    echo "Result 1: $1*$2*$3 = $val"
    val=`expr $1 + $2 + $3`
    echo "Result 2: $1+$2+$3 = $val"
fi
exit 0
