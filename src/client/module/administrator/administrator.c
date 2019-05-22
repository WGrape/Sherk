#include <libconfig.h>
#include <memory.h>

// 管理员, 管理整个系统的配置
config_t *administrator_property_conf;

// 初始化配置
void administrator_method_init_config() {

    // 初始化配置的代码应该怎么写 ？
    // administrator_property_conf = &(config_t) {};
    // config_init(administrator_property_conf);
    // config_read_file(administrator_property_conf, "/Users/yimutian/sherk/sherk.conf");
    administrator_property_conf = &(config_t) {};
    config_init(administrator_property_conf);
    config_read_file(administrator_property_conf, "/Users/yimutian/sherk/sherk.conf");
}

config_t *administrator_method_get_config() {

    // 获取配置后的代码应该怎么写 ？
    // config_t *config = administrator_method_get_config();
    // const char *title;
    // config_lookup_string(config, "title", &title);
    // printf("%s",title);
    administrator_method_init_config();
    return administrator_property_conf;
}

int administrator_method_read_config_int(const char *path) {

    config_t *config = administrator_method_get_config();

    int value;
    config_lookup_int(config, path, &value);

    return value;
}

char *administrator_method_read_config_string(const char *path) {

    config_t *config = administrator_method_get_config();

    const char *value;
    config_lookup_string(config, path, &value);

    return (char *)value;
}

