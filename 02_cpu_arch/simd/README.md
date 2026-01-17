## SIMD experiment

- Same loop, different optimization flags
- `-O3` enables auto-vectorization
- Verified by `paddd` / `movdqa` in assembly
- One loop iteration processes 4 integers

