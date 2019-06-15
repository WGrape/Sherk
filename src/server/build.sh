# 这个编译脚本仅用于个人开发使用, 如果非个人开发, 只使用 Sherk/build/build.sh 脚本编译即可 。

# --------------------------
# 在哪个目录执行这个命令, 在就会哪个目录下生成编译输出的文件
# /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" .
# --------------------------
# | 后来发现无法生成 cmake-build-debug 文件夹，故暂时还是使用 Clion 的 Reload Cmake Project ( 右击CMakeLists.txt文件 )
# --------------------------

killall sherkd # 杀掉所有sherk客户端进程

# 执行这个前，请确保此目录下存在 cmake-build-debug 文件夹
/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake --build ./cmake-build-debug --target sherkd -- -j 2

# 注意: 源文件和目标文件必须使用自己本地所在的绝对路径, 请自行修改
# 重要: 开发中的服务端命令从 sherkd 变成了 sherkd_dev
ln -sf ~/Lvsi/github/Sherk/src/server/cmake-build-debug/sherkd ~/sherk/bin/sherkd_dev

# 开发中修改 src/module/adapter/sherk.conf 配置文件, 不要修改 ~/sherk/sherk.conf
ln -sf ~/Lvsi/github/Sherk/src/server/SherkLaunch/src/module/adapter/sherk.conf ~/sherk/sherk.conf


# 注意:个人开发的时候，如果源码修改了，要及时更新到 ${SHERK_PATH}/project/Sherk 项目下，否则 build 无法生效
# 删除 ~/sherk/project/Sherk 目录, 拷贝最新 ../../../Sherk 目录到 ~/sherk/project/ 目录下
rm -r ~/sherk/project/Sherk
cp -rf ../../../Sherk ~/sherk/project/
