typedef struct Client {

    // 启动
    static int (*startup)();

    // 启动
    static int (*shutdown)();

} Client;

static int startup() {

    return 0;
}


static int shutdown() {

    return 0;
}

Client client = {startup, shutdown};



