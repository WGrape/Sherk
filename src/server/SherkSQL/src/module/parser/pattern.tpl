"SherkSystemCommand:command=login, name=", // Sherk系统命令


"^\\s+CREATE\\s+DATABASE\\s+.+$", // 建库语句
"^\\s+DROP\\s+DATABASE\\s+.+$", // 删库语句

"", // 建表语句
"^\\s+DROP\\s+TABLE\\s+.+$", // 删表语句

"^\\s+DELETE\\s+FROM\\s+.+$", // 清空表数据

"^\\s+TRUNCATE\\s+FROM\\s+.+$", // 截断表的全部数据