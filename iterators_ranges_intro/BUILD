load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "iterators-ranges-test",
    srcs = ["iterators-ranges-test.cc"],
    copts = [
      "-Iexternal/gtest/googletest/include",
      "-Iexternal/gtest/googletest",
    ],
    deps = [
        "@gtest//:main",
    ],
    size = "small",
)