### Generic Build Instructions

#### Setup

    git clone --recursive https://github.com/sparrowli/algorithm_library.git

#### Build

compile

    mkdir release;cd release;cmake -DCMAKE_BUILD_TYPE=Release ..;make

compile unittest

    cd spec;mkdir release;cd release;cmake -DCMAKE_BUILD_TYPE=Release ..;make

