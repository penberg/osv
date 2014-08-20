/*
 * Copyright (C) 2014 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#include "arch.hh"
#include "libc/libc.hh"

#include <assert.h>
#include <stdio.h>

enum {
    ARCH_SET_GS = 0x1001,
    ARCH_SET_FS = 0x1002,
    ARCH_GET_FS = 0x1003,
    ARCH_GET_GS = 0x1004,
};

long arch_prctl(int code, unsigned long addr)
{
    switch (code) {
    case ARCH_SET_GS:
        printf("arch_prctl(): SET_GS=%lx\n", addr);
        break;
    case ARCH_SET_FS:
        printf("arch_prctl(): SET_FS=%lx\n", addr);
        break;
    case ARCH_GET_FS:
        assert(0);
    case ARCH_GET_GS:
        assert(0);
    default:
        return libc_error(EINVAL);
    }
    return 0;
}
