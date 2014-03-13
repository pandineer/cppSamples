## C++で指定したディレクトリが空かどうかをチェックする

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
