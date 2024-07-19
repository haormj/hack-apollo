load("//tools:cpplint.bzl", "cpplint")
load("//tools:apollo_package.bzl", "apollo_package", "apollo_cc_binary")

package(default_visibility = ["//visibility:public"])

apollo_cc_binary(
    name = "state",
    srcs = [
        "state.cc",
    ],
    deps = [
        "//cyber",
    ],
)

apollo_package()
cpplint()
