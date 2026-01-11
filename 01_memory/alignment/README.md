## What I did
- structのメンバ順でサイズが変わるか確認

## What I observed
- sizeof(A)=4
- sizeof(B)=4
- intは4byte境界に揃えられていた

## What I learned
- CPU都合でpaddingが入る
- メモリレイアウトは自動で最適化される
