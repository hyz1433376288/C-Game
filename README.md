# C-Game


2021/5/13
**翻到了大一用纯c写的俄罗斯方块，哈哈哈满满的回忆。整个游戏都是纯模拟操作字符，当时做的真是不容易啊哈哈，刚玩了两把，体验还蛮好的heihei**




需求分析：：


布局：
int map[H][W]

宽10个单位，那么数组的列:W就需要是20
高20个单位，数组的行：H就需要 是20
考虑到上下左右边界，所以所以设置map[20+1+1][20+2+2]  
方块的画布居中，画布下显示下一个方块 和    当 前积分
首位行设成-1
左右列设成-2
其他为0

方块：□■
分为：L , N, I, 田 ，T，其中L，N有镜像，共七种
需要注意的是，每个方块占据两个单位 宽度，但只占一个单位高度，-----（旋转难点）
case 1:I 
case 2:田
case 3:L
case 4:T
case 5:N



操作：
按下空格键，方块直接到底
‘w’键需要旋转方块
‘a’‘d’键需要左右移动方块
上述操作同时方块需要下落

重力模型：
下层方块消失后，上面的方块需要下落，下落时每个积木必须保持原来形状




2020/2/7 21：47
1.方块的旋转模拟暂时不考虑
2.rigidbody函数算法：考虑积木的每个方块的x[i]与其所在列的下一个方块（不为零的）的距离的最小值，即为积木的着陆距离！由于玩家可能左右移动积木，所以最小值必须实时刷新
rigidbody算法需要把下底边界的值全部设为2，下落中的积木的值是1，计算1与2 的最近距离，即为可下落的距离，到底后，积木1也需要归2

3.其余5个方块补全
