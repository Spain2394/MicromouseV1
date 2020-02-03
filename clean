FILE=Makefile

for i in ./* # iterate over all files in current dir
do
    if [ -d "$i" ] # if it's a directory
    then
        cd $i
        if [ -f "$FILE" ]; then # if file exists within current directory
            echo "$FILE in $i exist"
            make clean
        else
            if [ $i == "./MicromouseV1_Software" ]; then # if file exists within current directory
                echo "No need to add $FILE to $i"
                echo "next..."
            else
                echo "$i"
                cd ../
                echo "adding Makefile to $i"
                cp clean.txt $i
                cd $i
                mv clean.txt Makefile
                make clean
            fi
        fi
        cd ../
    fi
done
