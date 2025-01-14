add_requires("matplotplusplus")

target("avl_bench")
    set_kind("binary")
    add_files("avl_bench.cpp")
    add_packages("matplotplusplus")

target("avl")
    set_kind("binary")
    add_files("avl.cpp")
