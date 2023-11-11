//
// Created by Perfare on 2020/7/4.
//

#include "hack.h"
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>
#include "il2cpp_dump.h"
#include "log.h"
#include "xdl.h"

static int GetAndroidApiLevel() {
    char prop_value[PROP_VALUE_MAX];
    __system_property_get("ro.build.version.sdk", prop_value);
    return atoi(prop_value);
}

void hack_start(const char *game_data_dir) {
    bool load = false;
    for (int i = 0; i < 1000; i++) {
        void *handle = xdl_open("/data/user/0/com.yingxiong.hero.f399/files/libil2cpp.so", 0);
        if (handle) {
            load = true;
            il2cpp_api_init(handle);
            il2cpp_dump(game_data_dir);
            break;
        } else {
            sleep(1);
        }
    }
    if (!load) {
    }
}

void hack_prepare(const char *game_data_dir) {
    int api_level = GetAndroidApiLevel();
    hack_start(game_data_dir);
}
