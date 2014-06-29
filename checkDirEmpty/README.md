## Check specified directory is empty or not

    $ g++ checkDirEmpty.cpp -o checkDirEmpty
    $ mkdir emptyDir
    $ mkdir noEmptyDir
    $ touch noEmptyDir/test.txt
    $ ./checkDirEmpty.exe
    filename: .
    filename: ..
    emptyDir is empty!
    filename: .
    filename: ..
    filename: test.txt
    noEmptyDir is not empty.
