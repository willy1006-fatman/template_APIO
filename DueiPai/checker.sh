#!/bin/bash
t=0 

g++ data.cpp -o data -std=c++20
g++ std.cpp -o std -std=c++20
g++ mycode.cpp -o mycode -std=c++20

while true; do
    let "t=$t + 1" echox
    printf $t                                 
    printf ": "
	./data > input              
    ./std < input > stdout         
    ./mycode < input > myout            
    
    if diff stdout myout; then
        cat stdout
        printf "Accepted\n"
    else
		printf "Standard\n"
		cat stdout
		printf "Mycode\n"
		cat myout
		printf "Testcase\n"
		cat input
        printf "Wrong Answer\n"
        break
    fi
done
