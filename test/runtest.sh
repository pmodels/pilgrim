#!/bin/bash

function run_one_program()  {
    if [[ ! -z $1 ]]    # check $1 is not empty
    then
        prog="./$1"
        proc=$2
        args=$3

        echo "Program: $prog, Procs: $proc, Args: $args"
        mpirun -n $proc -env LD_PRELOAD=$libpilgrim $prog $args
        #mpirun -n $proc $prog $args
    fi
}


file_content=`cat ./testlist.in`
readarray -t y <<<$file_content

for line in "${y[@]}"
do
    if [[ $line != \#* ]]
    then 
        # split the line by ' ':
        #  - arr[0] is the program name
        #  - arr[1] is the number of MPI processes
        #  - arr[2] is the potential arguments
        arr=(${line// / })        

        args=           
        if [[ ${arr[2]} == arg* ]]
        then
            tmp=(${arr[2]//arg=/ })
            args=${tmp[0]}
        fi

        run_one_program ${arr[0]} ${arr[1]} ${args}
    fi
done
