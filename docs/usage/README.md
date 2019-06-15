### 下载

```bash
# 使用 git 下载源码
git clone https://github.com/Lvsi-China/Sherk
```

### 运行客户端

- 第一种<br>
```bash
# 直接运行 src/client/bin 目录下的 sherk 脚本
cd ./src/client/bin
sherk login
```

- 第二种<br>
自己修改源代码，然后编译代码，执行生成的sherk可执行文件。使用这种的时候，注意需要使用如下命令。
```bash
./sherk login
```

- 第三种<br>
将bin目录下的sherk添加到环境变量中，这样，启动客户端的时候，就不需要再切换目录了。
```bash
sherk login
```

#### 注意
1. 运行客户端main函数只有2种方法：①使用 ./sherk ②使用 sherk 。第②种需要把sherk命令添加到环境变量中
2. 使用第②种的时候，如果修改了源码，一定要记得及时把编译后的程序移到 bin 目录下，这样才能及时生效。（ 多么痛的领悟 ）
3. 可以执行客户端 build.sh 脚本对项目构建。
4. 添加到环境变量中的方法是修改 ~/.bash_profile 文件，如下
```bash
export PATH=${PATH}:~/github/Sherk/src/client/bin
export PATH=${PATH}:~/github/Sherk/src/server/bin
```

### 运行服务端


#### 注意
1. 也可以执行客户端 build.sh 脚本对项目构建。

