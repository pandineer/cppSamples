## Check file or directory exists or not
If file or directory exists, stat() returns 0
If not, stat() returns -1

    $ g++ checkExist.cpp -o checkExist
    $ touch file
    $ mkdir directory
    $ ./checkExist
    0
    0
    -1
