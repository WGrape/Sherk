
<div align="center">

<img width="220px" src="extra/image/logo/sherk.jpeg">

<br/>

<img width="90px" src="extra/image/logo/1.jpg">

</div>

<br/>

<div align="center">
<img src="extra/image/logo/2.png">
<p><font size=2>A Relational Database System Implementation Based on C Language</font></p>
</div>

<p align="center">
<a href="https://github.com/Lvsi-China/Sherk">
    <img src="https://img.shields.io/codacy/grade/e27821fb6289410b8f58338c7e0bc686.svg">
</a>
<a href="https://github.com/Lvsi-China/Sherk">
    <img src="https://img.shields.io/travis/rust-lang/rust.svg">
</a>
<a href="https://github.com/Lvsi-China/Sherk">
    <img src="https://img.shields.io/github/license/mashape/apistatus.svg">
</a>
</p>

> ### 正在更新中 ...

## 摘要
<img src="/extra/image/synopsis/example.gif">
Sherk是基于C语言实现的关系型数据库，实现了关系型数据库的基本功能

## 使用
1. 创建 ~/sherk/project 文件夹，并在其文件夹内 ```git clone``` 下此项目

2. 执行 ```build/build.sh``` 脚本，如果没有权限可以 ```sudo chmod``` ，或者执行 ```sudo bash ./build.sh``` 。

3. 使用 ```sherkd``` 命令启动数据库服务端, 再使用 ```sherk login``` 启动客户端（初始账号:root, 初始密码:000000）。

4. 如果过程无误会出现客户端交互界面，使用 sherk test 即可完成样例测试。

> 环境要求: Mac + Clion 编译器 + .bash_profile 文件 + 整个 ~/sherk 目录的可读可写权限

[查看更详细使用说明](docs/usage)

## 文档
在使用的过程中，遇到相关问题可以查看 [Sherk文档](docs/documentation)

## 说明
- 本项目仅致力于对数据库有兴趣的爱好者共同学习和研究使用。
- 提交的 ```random_xxxx``` 消息只是因为前期开发中为方便自动提交。

## 教程
对于没有数据库基础，或者想要研究数据库基础原理的开发者，建议阅读
[数据库教程](docs/tutorial) 。

## 参考
[阅读参考资料](docs/reference)


