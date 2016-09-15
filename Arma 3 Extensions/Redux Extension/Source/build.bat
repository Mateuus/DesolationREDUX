g++ -std=c++11 -Wall -g -c uuid.cpp
g++ -std=c++11 -IC:\mingw-w64\i686-5.4.0-posix-dwarf-rt_v5-rev0\mingw32\include -Wall -g -c redex.cpp
g++ -static -shared -std=c++11 -Wall -g -o "D:\Steam\steamapps\common\Arma 3\redex.dll" redex.o uuid.o -lrpcrt4
