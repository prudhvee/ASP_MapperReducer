gcc mapper.c -o mapper.out
gcc reducer.c -o reducer.out
gcc combiner.c -o combiner.out

./combiner.out input1.txt > output.txt

