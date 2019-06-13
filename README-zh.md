random generator of Bernoulli trials  with limited resolution
===

### 數位 Bernoulli 試驗

常見的 Bernoulli 試驗演算法是產生一組浮點數亂數rand_float，小於機率 p 便視作事件觸發回傳 true。

```python
def randBernoulli(probability): 
	if (rand()/RAND_MAX) < probability:
        return true
    else:
        return false
```

好處是其解析度極高，其試驗結果非常接近提供的機率。但是這種方式每進行一次 Bernoulli 試驗就要產生一次亂數，而且過程還涉及浮點數運算。

若能生成一組資料具有均勻分佈的 1 與 0 ，從頭或尾端抽出 1 位元的資料，便可視作一次機率為 0.5 的 Bernoulli  試驗。若亂數演算法（如：mt19937）能產生 64 位元的均勻亂數，則一次亂數運算就能供 64 次數位 Bernoulli 試驗使用。

### 二進制擴增數位 Bernoulli 試驗

將一組充滿 1 的數位資料與另一組數位 Bernoulli 亂數資料進行 AND 運算會使原本100%填充率的資料衰減成期望值為 50% 填充率的數位資料，若再與一組數位 Bernoulli 亂數資料進行 AND 運算，資料會再衰減成期望值 25% 填充率的數位資料，此時從頭或尾抽出 1 位元的資料便可進行 25% 成功機率的 Bernoulli 試驗。

如此一來便可生成機率為 0 .5 指數倍的 Bernoulli 試驗。

### OR 運算下的數位 Bernoulli 資料

若將兩組機率分別為 p1 和 p2 的資料進行 OR 運算，其產出物p3的期望值如下：
$$
p_3 = p_1 + (1-p_1)p_2 = p_1 +p_2 - p_1p_2
$$
其中(1-p1)的意義為，p2的效果只能體現在p1資料內邏輯為 false 的資料。

![1560402826341](https://i.imgur.com/VJN2EjW.png)

### XOR運算下的數位 Bernoulli 資料

若將兩組機率分別為 p1 和 p2 的資料進行 XOR 運算，其產出物p3的期望值如下：
$$
p_3 = p_1(1-p_2) + p_2(1-p_1) = p_1 + p_2 -2p_1p_2
$$
其意義為，兩資料互斥為 1，因此輸出為 1 的資料必須由互斥的資料產生。

![1560402798753](https://i.imgur.com/Hc1F1vD.png)

