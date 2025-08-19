# Speedup

This op is memory-bandwidth bottle necked. Difficult to speed up cz ratio of loads / math is too high.
so you're always waiting around on memory, do a bit of work, then stall.
can optimise by prefetching, which cpu already does usually.
Noticed something intereresting where if i added prefetching like so:-

```cpp
    for(int y = 0; y <= 32; y++)
    {
      prefetch_l3(&X[y*8]);
      prefetch_l3(&Y[y*8]);
    }
```

that would give a relative speedup, but only because that slowed down the per task comp massively,
did nothing to improve actual perf. was effectively cache poisoning myself.
