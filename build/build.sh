echo "\n\n\n# -------sherk---------->" >> ~/.bash_profile

# 把环境变量写入.bash_profile中: SHERK_PATH 和 SHERK_PROJECT_PATH
echo "export SHERK_PATH=~/sherk" >> ~/.bash_profile
echo "export SHERK_PROJECT_PATH=\${SHERK_PATH}/project/Sherk" >> ~/.bash_profile

# 把 sherk 和 sherkd 命令添加到环境变量中
echo "# 导入的是 exec 执行文件, 而不是 shell 文件, 如 export PATH=\${PATH}:xxx.sh 这样写是错误的
export PATH=\${PATH}:\${SHERK_PROJECT_PATH}/build/client/bin
export PATH=\${PATH}:\${SHERK_PROJECT_PATH}/build/server/bin" >> ~/.bash_profile

echo "# <-------sherk----------\n" >> ~/.bash_profile


# 更新环境变量
source ~/.bash_profile

# 编译客户端
../src/client/build.sh


# 编译服务端
cd ${SHERK_PROJECT_PATH}/build/server; /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ${SHERK_PROJECT_PATH}/src/server

killall sherkd # 杀掉所有sherkd服务端进程
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ${SHERK_PROJECT_PATH}/build/server --target sherkd -- -j 2
cp -i ${SHERK_PROJECT_PATH}/build/server/sherkd ${SHERK_PROJECT_PATH}/build/bin/
ln -s ${SHERK_PROJECT_PATH}/src/server/SherkLaunch/src/module/adapter/sherk.conf ${SHERK_PATH}/sherk.conf




