cd ../../build/client; /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ${SHERK_PROJECT_PATH}/src/client


killall sherk # 杀掉所有sherk客户端进程
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ${SHERK_PROJECT_PATH}/build/client --target sherk -- -j 2
cp -i ${SHERK_PROJECT_PATH}/build/client/sherk ${SHERK_PROJECT_PATH}/build/bin/