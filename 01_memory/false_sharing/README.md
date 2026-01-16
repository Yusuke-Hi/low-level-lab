## False Sharing Experiment

- Two threads increment different variables
- When variables share a cache line, performance degrades
- Separating cache lines with alignas(64) dramatically improves performance

## Key Insight
False sharing occurs at cache-line granularity, not variable granularity.

## Result
### false sharing 
Time: 1246 ms
### avoid false sharing
Time: 118 ms
