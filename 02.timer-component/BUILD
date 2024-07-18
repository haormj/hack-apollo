load("//tools:cpplint.bzl", "cpplint")
load(
    "//tools:apollo_package.bzl",
    "apollo_package",
    "apollo_cc_library",
    "apollo_component",
)

package(default_visibility=["//visibility:public"])

apollo_component(
    name="libtest.so",
    srcs=["test.cc"],
    hdrs=["test.h"],
    deps=[
        "//cyber",
    ],
    visibility=["//visibility:private"],
)

filegroup(
    name="conf",
    srcs=[
        ":test.dag",
    ],
)

apollo_package()
cpplint()
