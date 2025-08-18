# Notes on sqrt

The func is super fast around vals of 1, so if you gen rand from say 0.9-1.1 that's very fast.
Super slow around vals of 3, so 2.8 - 3.0 would be super slow.
This is due to divergence and convergence, usually the first guess is pretty accurate for convergent nums (1).
So you don't need as many iterations to get to the right ans.
And in SIMD, say you have numbers with high divergence, it would take longer for each simd lane to finish.
So you'd unnecessarily be waiting around when just 1 out of 8 nums in the lane isn't done. Therefore least speedup.
Therefore divergent cases have least speedup over seq, and convergent have most since not too much variability each lane.

