## Cache line experiment

- sizeof(X)=8 → 8 elements per cache line
- Xarr[0]〜Xarr[7] share the same cache line
- alignas(64) forces each element into its own cache line

## Insight
CPU loads memory in cache-line units.
This explains both fast array access and false sharing.
