# Parallel
Testing parallel mode/extension of g++.

See [Parallel Mode of GCC](https://gcc.gnu.org/onlinedocs/libstdc++/manual/parallel_mode.html) for more details.

See the `task.cpp` for details - basically it generates some large vector of random numbers and sorts them few times using standrd std::sort and parallel version of it.

# Usage

Just run `make`.

Then running `./task` produces following results on my machine:

    ./task
    Generating 10000000 numbers...done (1329.56)
    Serial    Lowest: 1457, highest: 4.29497e+09, time: 795.783ms
    Serial    Lowest: 1457, highest: 4.29497e+09, time: 797.125ms
    Serial    Lowest: 1457, highest: 4.29497e+09, time: 799.151ms
    Serial    Lowest: 1457, highest: 4.29497e+09, time: 798.42ms
    Serial    Lowest: 1457, highest: 4.29497e+09, time: 799.431ms
    Parallel  Lowest: 1457, highest: 4.29497e+09, time: 168.47ms
    Parallel  Lowest: 1457, highest: 4.29497e+09, time: 168.675ms
    Parallel  Lowest: 1457, highest: 4.29497e+09, time: 167.623ms
    Parallel  Lowest: 1457, highest: 4.29497e+09, time: 161.914ms
    Parallel  Lowest: 1457, highest: 4.29497e+09, time: 167.784ms

