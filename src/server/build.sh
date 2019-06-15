cd ${SHERK_PROJECT_PATH}/build/server; /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ${SHERK_PROJECT_PATH}/src/server


killall sherkd # 杀掉所有sherkd服务端进程
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ${SHERK_PROJECT_PATH}/build/server --target sherkd -- -j 2
cp -i ${SHERK_PROJECT_PATH}/build/server/sherkd ${SHERK_PROJECT_PATH}/build/bin/
ln -s ${SHERK_PROJECT_PATH}/src/server/SherkLaunch/src/module/adapter/sherk.conf ${SHERK_PATH}/sherk.conf


