#ifndef EMBOX_TEST_NET_INET_PTON_TEST_H_
#define EMBOX_TEST_NET_INET_PTON_TEST_H_

#include "netinet/in.h"

#define V4_MAX_ADDR_LEN 15
struct v4_test_info {
	char test_string[V4_MAX_ADDR_LEN];
	struct in_addr true_val;
	uint8_t pass;
	char true_ntop[V4_MAX_ADDR_LEN];
};

#define V6_MAX_ADDR_LEN 45
struct v6_test_info {
	char test_string[V6_MAX_ADDR_LEN];
	struct in6_addr true_val;
	uint8_t pass;
	char true_ntop[V6_MAX_ADDR_LEN];
};

#define V4_TESTS sizeof(v4_test_ref) / sizeof(struct v4_test_info)
#define V6_TESTS sizeof(v6_test_ref) / sizeof(struct v6_test_info)

struct v4_test_info v4_test_ref[] = {
    {.pass = 0,
        .test_string = "192.0.00a.003",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "192.0.004.003",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "192.0.04.03",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 1,
        .test_string = "192.0.40.30",
        .true_ntop = "192.0.40.30",
        .true_val.s_addr = 0x1e2800c0},
    {.pass = 1,
        .test_string = "0.0.0.0",
        .true_ntop = "0.0.0.0",
        .true_val.s_addr = 0x00000000},
    {.pass = 1,
        .test_string = "1.2.3.4",
        .true_ntop = "1.2.3.4",
        .true_val.s_addr = 0x04030201},
    {.pass = 1,
        .test_string = "192.168.4.3",
        .true_ntop = "192.168.4.3",
        .true_val.s_addr = 0x0304a8c0},
    {.pass = 0,
        .test_string = "192.0.4.3.",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 1,
        .test_string = "24.136.46.33",
        .true_ntop = "24.136.46.33",
        .true_val.s_addr = 0x212e8818},
    {.pass = 0,
        .test_string = "24.136.46.33g",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "256.20.0.1",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "100.20.0",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "100.20.0.0.1",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "f.1.2.3",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "0xf.1.2.3",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
    {.pass = 0,
        .test_string = "google.com",
        .true_ntop = "",
        .true_val.s_addr = 0x00000000},
};
struct v6_test_info v6_test_ref[] = {
    {.pass = 1,
        .test_string = "1:0:0:0:0:0:0:8",
        .true_ntop = "1::8",
        .true_val.s6_addr16 = {0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0800}},
    {.pass = 1,
        .test_string = "1:2:3:4:5:6:7:8",
        .true_ntop = "1:2:3:4:5:6:7:8",
        .true_val.s6_addr16 = {0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600,
            0x0700, 0x0800}},
    {.pass = 1,
        .test_string = "0001:0002:0003:0004:0005:0006:0007:0008",
        .true_ntop = "1:2:3:4:5:6:7:8",
        .true_val.s6_addr16 = {0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600,
            0x0700, 0x0800}},
    {.pass = 1,
        .test_string = "1111:2222:3333:4444:5555:6666:7777:8888",
        .true_ntop = "1111:2222:3333:4444:5555:6666:7777:8888",
        .true_val.s6_addr16 = {0x1111, 0x2222, 0x3333, 0x4444, 0x5555, 0x6666,
            0x7777, 0x8888}},
    {.pass = 1,
        .test_string = "ffff:eeee:dddd:cccc:bbbb:aaaa:255.255.255.255",
        .true_ntop = "ffff:eeee:dddd:cccc:bbbb:aaaa:ffff:ffff",
        .true_val.s6_addr16 = {0xffff, 0xeeee, 0xdddd, 0xcccc, 0xbbbb, 0xaaaa,
            0xffff, 0xffff}},
    {.pass = 1,
        .test_string = "ff:0:0:aa:0:0:aa:ff",
        .true_ntop = "ff::aa:0:0:aa:ff",
        .true_val.s6_addr16 = {0xff00, 0x0000, 0x0000, 0xaa00, 0x0000, 0x0000,
            0xaa00, 0xff00}},
    {.pass = 1,
        .test_string = "fF:0:0:Aa:0:0:aA:Ff",
        .true_ntop = "ff::aa:0:0:aa:ff",
        .true_val.s6_addr16 = {0xff00, 0x0000, 0x0000, 0xaa00, 0x0000, 0x0000,
            0xaa00, 0xff00}},
    {.pass = 1,
        .test_string = "::FFFF",
        .true_ntop = "::ffff",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0xffff}},
    {.pass = 1,
        .test_string = "FFFF::",
        .true_ntop = "ffff::",
        .true_val.s6_addr16 = {0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 1,
        .test_string = "FFAA::1",
        .true_ntop = "ffaa::1",
        .true_val.s6_addr16 = {0xaaff, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0100}},
    {.pass = 1,
        .test_string = "FF:AA::1",
        .true_ntop = "ff:aa::1",
        .true_val.s6_addr16 = {0xff00, 0xaa00, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0100}},
    {.pass = 1,
        .test_string = "FF::AA:1",
        .true_ntop = "ff::aa:1",
        .true_val.s6_addr16 = {0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0xaa00, 0x0100}},
    {.pass = 1,
        .test_string = "FF:BB:CC::AA:1",
        .true_ntop = "ff:bb:cc::aa:1",
        .true_val.s6_addr16 = {0xff00, 0xbb00, 0xcc00, 0x0000, 0x0000, 0x0000,
            0xaa00, 0x0100}},
    {.pass = 0,
        .test_string = "10000:BB:CC::AA:1",
        .true_ntop = "",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 0,
        .test_string = "ff:0:0:aa:0:0:aa",
        .true_ntop = "",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 0,
        .test_string = "ff::1::1",
        .true_ntop = "",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 1,
        .test_string = "ff:0:0:aa:0:0:1.2.3.4",
        .true_ntop = "ff::aa:0:0:102:304",
        .true_val.s6_addr16 = {0xff00, 0x0000, 0x0000, 0xaa00, 0x0000, 0x0000,
            0x0201, 0x0403}},
    {.pass = 0,
        .test_string = "ff:0:0:aa:0:0:1.2.3.a",
        .true_ntop = "",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 1,
        .test_string = "ff::1.2.3.4",
        .true_ntop = "ff::102:304",
        .true_val.s6_addr16 = {0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0201, 0x0403}},
    {.pass = 1,
        .test_string = "::ffff:102:304",
        .true_ntop = "::ffff:1.2.3.4",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
            0x0201, 0x0403}},
    {.pass = 1,
        .test_string = "::102:304",
        .true_ntop = "::1.2.3.4",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0201, 0x0403}},
    {.pass = 1,
        .test_string = "::FFFF:1.2.3.4",
        .true_ntop = "::ffff:1.2.3.4",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
            0x0201, 0x0403}},
    {.pass = 1,
        .test_string = "0:0:0:0:0:FFFF:1.2.3.4",
        .true_ntop = "::ffff:1.2.3.4",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff,
            0x0201, 0x0403}},
    {.pass = 0,
        .test_string = "1:0:0:0:0:0:FFFF:1.2.3.4",
        .true_ntop = "",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0000, 0x0000}},
    {.pass = 1,
        .test_string = "::1.2.3.4",
        .true_ntop = "::1.2.3.4",
        .true_val.s6_addr16 = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0201, 0x0403}},
};

#endif /*EMBOX_TEST_NET_INET_PTON_TEST_H_*/
