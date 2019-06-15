echo "\n\n\n# -------sherk---------->" >> ~/.bash_profile

# 把环境变量写入.bash_profile中: SHERK_PATH 和 SHERK_PROJECT_PATH
echo "export SHERK_PATH=~/sherk" >> ~/.bash_profile
echo "export SHERK_PROJECT_PATH=\${SHERK_PATH}/project/Sherk" >> ~/.bash_profile

# 把 sherk 和 sherkd 命令添加到环境变量中
echo "# 导入的是 exec 执行文件, 而不是 shell 文件, 如 export PATH=\${PATH}:xxx.sh 这样写是错误的
export PATH=\${PATH}:\${SHERK_PATH}/bin" >> ~/.bash_profile

echo "# <-------sherk----------\n" >> ~/.bash_profile

# 更新环境变量
source ~/.bash_profile


# 编译客户端, 使用 ${SHERK_PROJECT_PATH}/src/client 目录下的CMakeLists.txt文件进行构建, 并把编译后的文件输出到 ${SHERK_PROJECT_PATH}/build/client 下
cd ${SHERK_PROJECT_PATH}/build/client; /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ${SHERK_PROJECT_PATH}/src/client
killall sherk # 杀掉所有sherk客户端进程
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ${SHERK_PROJECT_PATH}/build/client --target sherk -- -j 2
ln -sf ${SHERK_PROJECT_PATH}/build/client/sherk ${SHERK_PATH}/bin/sherk # 强制创建软连接到本地sherk/bin目录下


# 编译服务端, 使用 ${SHERK_PROJECT_PATH}/src/server 目录下的CMakeLists.txt文件进行构建, 并把编译后的文件输出到 ${SHERK_PROJECT_PATH}/build/server 下
cd ${SHERK_PROJECT_PATH}/build/server; /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ${SHERK_PROJECT_PATH}/src/server
killall sherkd # 杀掉所有sherkd服务端进程
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ${SHERK_PROJECT_PATH}/build/server --target sherkd -- -j 2
ln -sf ${SHERK_PROJECT_PATH}/build/server/sherkd ${SHERK_PATH}/bin/sherkd # 强制创建软连接到本地sherk/bin目录下
ln -sf ${SHERK_PROJECT_PATH}/src/server/SherkLaunch/src/module/adapter/sherk.conf ${SHERK_PATH}/sherk.conf

# 再更新一下
source ~/.bash_profile


# 以上均为编译 -----------------------------------


# 在 ~/sherk 目录下创建必要的一些文件

# 创建初始账号, 用户名:root 密码:000000
mkdir -p ~/sherk/database/information_schema/user.password/ # 递归创建
touch ~/sherk/database/information_schema/user.password/root.password
echo "20c3e97a0dbaf1bfeeb0c8f74911beef\c" > ~/sherk/database/information_schema/user.password/root.password # \c 表示不换行
