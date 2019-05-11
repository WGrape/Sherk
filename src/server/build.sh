/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build /Users/yimutian/Lvsi/github/Sherk/src/server/cmake-build-debug --target sherkd -- -j 2

cp -i ./cmake-build-debug/sherkd ./bin/

ln -s /Users/yimutian/Lvsi/github/Sherk/src/server/SherkLaunch/src/module/adapter/sherk.conf  /Users/yimutian/sherk/sherk.conf
