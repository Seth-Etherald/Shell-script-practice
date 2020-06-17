#!/bin/sh
choice="y"
while [ $choice = "y" ]
do
    echo "Please enter file name: "
    read name
    if [ -f $name ]
    then
        echo "$name is an ordinary file."
        echo "content of $name:"
        cat $name
    elif [ -d $name ]
    then
        echo "$name is a directory."
        echo "- List subdir and files in $name:"
        ls -a $name
        echo "- Empty folders are:"
        find $name -empty -printf '%f\n'
    else
        echo "$name does not exist, or it is neither an ordinary file nor a directory."
    fi
    echo "Do you want to continue?(y/n)"
    read choice
done

exit 0
