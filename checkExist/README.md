## C++でファイルやフォルダが存在するかどうかを確認する
ファイルやフォルダが存在したら、stat関数は0を返し、存在しなければstat関数は-1を返す

    $ g++ checkExist.cpp -o checkExist
    $ touch file
    $ mkdir directory
    $ ./checkExist
    0
    0
    -1
