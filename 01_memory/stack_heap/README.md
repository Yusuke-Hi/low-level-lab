# stack vs heap

## 実験
- stack, heap, globalのアドレスを表示
- /proc/[pid]/maps と printfのアドレスを比較
- gdb で一行ずつ実行

## Observations
- stack: 高い位置に配置される
- heap: 低い位置から高い位置に伸びる
- global: 実行ファイル近辺

## Learning
- メモリは連続的ではない

### 疑問メモ
- malloc 行直後に heap_var が更新されていないように見えることがある
- gdb の表示はソースコードと完全一致しない
- 値は確定していても、変数に書き戻されていない瞬間がある
