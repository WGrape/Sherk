typedef struct Server{

    // 启动
    static int (*startup)();

    // 启动
    static int (*shutdown)();

}Server;


static int startup(){

    return 0;
}


static int shutdown(){

    return 0;
}

Server server = {startup, shutdown};