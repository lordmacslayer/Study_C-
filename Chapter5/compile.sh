g++ $1 -o bin/$1.out 2>log_errors.txt
[ $? -eq 0 ] && echo "$1: Compiled and Linked Successfully!" && exit 1
echo "Build failed for $1. Check log_errors.txt."
